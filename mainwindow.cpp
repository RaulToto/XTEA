#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <xtea.cpp>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_label_linkActivated(const QString &link)
{

}

void MainWindow::on_pushButton_clicked()
{
    QString input;
    input=ui->textEdit->toPlainText();

    string str;
    str=input.toStdString();
    char * writable = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), writable);

    int len=sizeof(writable);

    StringCrypt(writable,len,true);

    cout << "Encrypt string" ;
    cout << writable << endl;

    string out(writable);
    QString output=QString::fromStdString(out);
    ui->textEdit_2->setText(output);



}

