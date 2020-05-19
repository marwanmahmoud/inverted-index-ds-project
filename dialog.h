#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include<QFileSystemModel>
#include<QFile>
#include "invertedindex.h"


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_listView_clicked(const QModelIndex &index);

    void on_treeView_doubleClicked(const QModelIndex &index);
    void Read(QString q);
private:
    Ui::Dialog *ui;
    QFileSystemModel *dirmodel;
    QFileSystemModel *filemodel;

};

#endif // DIALOG_H
