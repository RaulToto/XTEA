#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <xtea.cpp>
#include <sstream>
#include <iomanip>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

string MainWindow::string_to_hex(const string &input)
{
    static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();

    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        output.push_back(lut[c & 15]);
    }
    return output;
}

void MainWindow::keyGenerator(uint32_t *arr, string ss)
{
    for (int i = 0; i < ss.size(); ++i) {
        //cout << string_to_hex(ss[i]) << endl;
    }
}

string MainWindow::intToString(uint32_t t)
{
    std::stringstream oss;
    oss <<"" << std::setfill('0') << std::setw(sizeof(uint32_t)*2)
       << std::hex << t;
    return oss.str();
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
    uint32_t wKey[] = {0x6c696265,0x6c756c61,0x6c696265,0x6c756c61}; //secret key

//    uint32_t wKey[] = {0xdeadbabe,0xdeadface,0xdeadbeef,0x45112150}; //secret key
    //uint32_t wKey[]={2,4,5,6};
    QString input;
    input=ui->textEdit->toPlainText();

    string str;
    str=input.toStdString();
    char * writable = new char[str.size() + 1];
    std::copy(str.begin(), str.end(), writable);

    int len=sizeof(writable);
    unsigned int blockSize = sizeof(uint32_t)*2;
    unsigned int nLength = strlen(writable);

    for(unsigned int i=0; i<nLength;i+=blockSize)
        xtea_encipher(32, (uint32_t*)&writable[i], (uint32_t*) wKey);


    //mostrar hexadecimal
    string mostrar;
    for (int i = 0; i < strlen(writable); ++i) {
        mostrar+=intToString(writable[i]);
    }

    string out(writable);//convertir a string de char
    QString output=QString::fromStdString(mostrar);
    ui->textEdit_2->setText(output);

    //cout << (uint32_t*)&szMessage << endl;
    for(unsigned int i=0; i<nLength;i+=blockSize)
        xtea_decipher(32, (uint32_t*) &writable[i], (uint32_t*) wKey);
    //cout << szMessage<< endl;


    string out1(writable);
    QString output1=QString::fromStdString(out1);
    ui->textEdit_3->setText(output1);

    //string name="hello";

}


void MainWindow::on_pushButton_2_clicked()
{

}
