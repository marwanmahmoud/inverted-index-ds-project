#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("Exit");
    ui->pushButton_2->setText("Next");

//    QPixmap pic ("C:/Users/marwan mahmoud/Downloads/n.jpg");
//   int  w=ui->label->width();
//   int h= ui->label->height();
//   ui->label->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    hide();
    m = new MainWindow1();
    m->show();
}
