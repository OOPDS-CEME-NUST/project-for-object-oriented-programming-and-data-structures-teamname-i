#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QTextStream>
#include<iomanip>
#include<QMessageBox>
#include<QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    QFile file("‪data.txt");
          if(file.open(QFile::WriteOnly  | QIODevice::Append | QIODevice::Text))
          {
              QTextStream stream(&file);
              stream << "-----------------------------------------------------" << endl;
              file.close();
          }

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    static int count = 0;
   QString ID = ui -> ID_feild ->text();
   QString Bill = ui -> Bill_feild ->text();
    ui ->lcdnum -> setDigitCount(++count);
    ui-> lcdnum -> display(count);

    QFile file("‪data.txt");
          if(file.open(QFile::WriteOnly  | QIODevice::Append | QIODevice::Text))
          {
              //qDebug() << " WRITE TO THE FILE";
              // We're going to streaming text to the file
              QTextStream stream(&file);

              stream <<"ENTRY#" <<"    "<< ID  << endl;
              stream << "Bill-" << "     "<< Bill << endl << count << endl;

              file.close();

          }
else{
          qDebug() << "Could not open file to write";
          return;


}
ui -> ID_feild ->clear();
ui -> Bill_feild ->clear();
}



