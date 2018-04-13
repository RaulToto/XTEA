#include "mainwindow.h"
#include <QApplication>
//#include "xtea.cpp"
#include <iostream>
using namespace std;

/*void testXtea()
{

      //FileCrypt("file.txt",true); // encrypt
      //FileCrypt("file.txt",false); // decrypt
      char str[16]={"Hello,"}; // 16 mod 8 =0
      int len=sizeof(str);

      StringCrypt(str,len,true);
      cout <<"Encrypted string: ";
      for(int i=0;i<len;i++)
          cout <<str[i];
      cout <<endl;

      StringCrypt(str,len,false);

      cout <<"Decrypted string: ";
      cout <<str;


}*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //testXtea();
    w.show();
    return a.exec();
}
