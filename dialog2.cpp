#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
//   QPixmap pic("C:/games/tenor.gif");
//   int w=ui->label->width();
//   int h=ui->label->height();
//   ui->label->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));


}

Dialog2::~Dialog2()
{
    delete ui;
}
