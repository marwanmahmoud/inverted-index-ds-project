#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include<QtCore>
#include<QtGui>
#include<QMessageBox>
#include<QTextStream>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include <set>
#include<invertedindex.h>
using namespace std;

extern InvertedIndex tree;


MainWindow1::MainWindow1(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
}

MainWindow1::~MainWindow1()
{
    delete ui;
}
void MainWindow1::Read(QString q)
{
    QFile file(q);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
       QMessageBox::warning(this,"ERROR","could not open " + q);
    }
    else
    {
        QTextStream in(&file);
        QString text=in.readAll();
        tree.addFile(text.toStdString());
        file.close();
    }
}

void MainWindow1::on_actionAdd_triggered()
{
    d=new Dialog();
    d->show();
}

void MainWindow1::on_pushButton_clicked()
{

    QString qstr=ui->lineEdit->text();
    string str = qstr.toStdString();

    string occurence = tree.search(str);
    QMessageBox::information(this, "Result", QString::fromStdString(occurence));
}
