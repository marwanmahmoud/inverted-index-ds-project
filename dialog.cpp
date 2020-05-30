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
QVector<QString> filesContent;

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

void Dialog::Read(QString q)
{
    QFile file(q);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
       QMessageBox::warning(this,"ERROR","could not open the file file " + q);
    }
    else
    {
        QTextStream in(&file);
        QString text=in.readAll();
        filesContent.push_back(text);
        tree.addFile(text.toStdString());
        file.close();
    }
}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    QString spath =dirmodel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filemodel->setRootPath(spath));
}

void Dialog::on_treeView_doubleClicked(const QModelIndex &index)
{
    QString spath = dirmodel->fileInfo(index).absoluteFilePath();
    QDir directory(spath);
    QStringList files = directory.entryList(QStringList() << "*.txt" << "*.TXT",QDir::Files);
    foreach(QString filename, files) {
        hide();
        QString tpath = spath + "/" + filename;
        Read(tpath);
    }
}




