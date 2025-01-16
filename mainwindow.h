#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"about.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_actionOpen_triggered();

    void on_actionCut_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();    

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionPad4Note_triggered();

    void on_actionExit_triggered();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;
    QString file_path;
    About *about;

    struct Node
    {
        QString text;
        Node* next;
        Node* prev;

        Node(const QString &textState): text(textState),next(nullptr),prev(nullptr){};
    };

    Node* currentNode;

    void saveState();

};
#endif // MAINWINDOW_H
