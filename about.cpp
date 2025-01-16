#include "about.h"
#include "ui_about.h"
#include<QPixmap>
About::About(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::About)
{
    ui->setupUi(this);
    this->setWindowTitle("Pad4Note");
    this->setWindowIcon(QIcon(":/rsrc/rsrc/icons/note.png"));
    // QPixmap pix(":/rsrc/rsrc/icons/icons8-notepad-48.png");
    // int w = ui->img->width(), h = ui->img->height();
    // ui->img->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

About::~About()
{
    delete ui;
}

void About::on_pushButton_clicked()
{
    close();
}

