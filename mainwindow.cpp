#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include<QIcon>
#include<QStandardPaths>
#include <QClipboard>
#include<QRegularExpression>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Pad4Note");
    this->setWindowIcon(QIcon(":/rsrc/rsrc/icons/note.png"));
    this->setCentralWidget(ui->textEdit);
    this->statusBar()->showMessage("Characters: 0");

    currentNode = new Node(ui->textEdit->toPlainText());
    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::saveState);


}

MainWindow::~MainWindow()
{
    while (currentNode && currentNode->prev) {
        currentNode = currentNode->prev;
        delete currentNode->next;
    }
    delete currentNode;
    delete ui;
}



void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString file_name = QFileDialog::getOpenFileName(this,"Open  ",defaultPath,"Text files (*.txt) ;; All files (*)");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"Not Opened","File Not Opened");
        return;
    }
    QTextStream in(&file);
    in.setEncoding(QStringConverter::Utf8);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    if (!file_path.isEmpty()) {
        QFile file(file_path);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::critical(this, "Error", "Could not save the file.");
            return;
        }
        QTextStream out(&file);
        out.setEncoding(QStringConverter::Utf8);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.flush();
        file.close();
    }
    else {
        QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
        QString file_name = QFileDialog::getSaveFileName(this, "Save As", defaultPath,"Text files (*.txt) ;; All files (*)");
        if (file_name.isEmpty()) {
            return;
        }

        QFile file(file_name);
        file_path = file_name;
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::critical(this, "Error", "Could not save the file.");
            return;
        }
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text;
        file.flush();
        file.close();
    }
}


void MainWindow::on_actionSave_As_triggered()
{
    QString defaultPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString file_name = QFileDialog::getSaveFileName(this,"Save As  ",defaultPath,"Text files (*.txt) ;; All files (*)");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"Not Saved","File Not Saved");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    QString selectedText = ui->textEdit->textCursor().selectedText();
    if (!selectedText.isEmpty()) {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(selectedText);
        ui->textEdit->textCursor().removeSelectedText();
    }
}


void MainWindow::on_actionCopy_triggered()
{
    QString selectedText = ui->textEdit->textCursor().selectedText();
    if (!selectedText.isEmpty()) {
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(selectedText);
    }
}


void MainWindow::on_actionPaste_triggered()
{
    QClipboard *clipboard = QApplication::clipboard();
    QString clipboardText = clipboard->text();
    if (!clipboardText.isEmpty()) {
        ui->textEdit->textCursor().insertText(clipboardText);
    }
}



void MainWindow::saveState(){
    QString currText = ui->textEdit->toPlainText();

    if (currentNode && currentNode->text == currText) {
        return;
    }

    while (currentNode && currentNode->next) {
        Node* temp = currentNode->next;
        currentNode->next = nullptr;
        delete temp;
    }

    Node* newNode = new Node(currText);
    newNode->prev = currentNode;

    if (currentNode) {
        currentNode->next = newNode;
    }
    currentNode = newNode;
}


void MainWindow::on_actionUndo_triggered()
{
    if (currentNode && currentNode->prev) {
        currentNode = currentNode->prev;
        ui->textEdit->blockSignals(true);
        ui->textEdit->setPlainText(currentNode->text);
        ui->textEdit->blockSignals(false);
    } else {
        statusBar()->showMessage("Nothing to undo!");
    }


}


void MainWindow::on_actionRedo_triggered()
{
    if (currentNode && currentNode->next) {
        currentNode = currentNode->next;
        ui->textEdit->blockSignals(true);
        ui->textEdit->setPlainText(currentNode->text);
        ui->textEdit->blockSignals(false);
    } else {
        statusBar()->showMessage("Nothing to redo!");
    }
}


void MainWindow::on_actionPad4Note_triggered()
{
    about = new About(this);
    about->show();
}



void MainWindow::on_textEdit_textChanged()
{
    int charCount = ui->textEdit->toPlainText().length();
    QString text = ui->textEdit->toPlainText();
    QStringList words = text.split(QRegularExpression("\\s+"));
    words.removeAll("");
    int wordCount = words.count();
    statusBar()->showMessage("Chars: " + QString::number(charCount) + " Words: " + QString::number(wordCount));
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
