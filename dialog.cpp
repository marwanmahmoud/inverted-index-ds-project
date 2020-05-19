#include "dialog.h"
#include "ui_dialog.h"
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
using namespace std;

InvertedIndex tree;

void Dialog::Read(QString q)
{
    QFile file(q);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {

       QMessageBox::warning(this,"ERROR","coudlnt open file");

    }
    else
    {
        QTextStream in(&file);
        QString text=in.readAll();
        tree.addFile(text.toStdString());
        file.close();
    }
}

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QString spath="C:/";
   dirmodel=new QFileSystemModel(this);
   dirmodel->setFilter(QDir::NoDotDot|QDir::AllDirs);
   dirmodel->setRootPath(spath);
   ui->treeView->setModel(dirmodel);
   filemodel=new QFileSystemModel(this);
   filemodel->setFilter(QDir::NoDotDot|QDir::Files);
   filemodel->setRootPath(spath);
   ui->listView->setModel(filemodel);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    QString spath =dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(spath));
}

void Dialog::on_treeView_doubleClicked(const QModelIndex &index)
{
    int count=0;
    QString spath =dirmodel->fileInfo(index).absoluteFilePath();
    for(int i=0;i<6;i++)
    {
        hide();
        QString s=QString::number(count);
        QString e="/";
        QString h=".txt";
        QString tpath=spath+e+s+h;
        Read(tpath);
        count++;
    }
}




