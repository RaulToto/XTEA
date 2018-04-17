#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <string>
#include <algorithm>
#include <QMainWindow>
#include <iostream>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    std::string string_to_hex(const std::string& input);
    void keyGenerator(uint32_t *,string);
    string intToString(uint32_t);
    ~MainWindow();

private slots:
    void on_label_linkActivated(const QString &link);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
