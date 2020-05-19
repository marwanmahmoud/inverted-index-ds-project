#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H
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
#include"invertedindex.h"
#include <QMainWindow>
#include <dialog.h>
#include <dialog2.h>
#include<QFileDialog>
namespace Ui {
class MainWindow1;
}

class MainWindow1 : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private slots:
    void on_actionAdd_triggered();
   void  Read(QString q);
    void on_pushButton_clicked();

private:
    Ui::MainWindow1 *ui;
    Dialog *d;
    Dialog2 *d1;


};

#endif // MAINWINDOW1_H
