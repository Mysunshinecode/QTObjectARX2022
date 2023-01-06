#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <Windows.h>
#include <arxHeaders.h>
#include <acedCmdNF.h>
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
    void on_pushButton_clicked();
    void CreateLine();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
