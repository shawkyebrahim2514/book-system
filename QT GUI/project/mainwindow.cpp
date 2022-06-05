#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newbookwindow.h"
#include "searchstockwindow.h"
#include "editbookwindow.h"
#include "book.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>
#include <QDir>
std::map<QString,int> booksTitle;
std::map<int,std::map<QString,book>> stocks;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir databaseDir;
    databaseDir.mkpath("database");

    QFile styleSheet(":/resources/mainWindowStylesheet.qss");
    styleSheet.open(QFile::ReadOnly);
    QString style = styleSheet.readAll();
    qApp->setStyleSheet(style);
    styleSheet.close();


    QFile file("database/database.txt");
    file.open(QFile::ReadOnly);
    QTextStream in(&file);
    while(!in.atEnd()){
        QStringList data = in.readLine().split(',');
        booksTitle[data.at(1)] = data.at(0).toInt();
        stocks[data.at(0).toInt()][data.at(1)] = {data.at(1),data.at(2),data.at(3).toInt(),data.at(4).toInt()};
    }
}

MainWindow::~MainWindow()
{
    QFile file("database/database.txt");
    file.open(QFile::WriteOnly);
    QTextStream out(&file);
    for(auto& stock : stocks){
        for(auto& item : stock.second){
            QString tmp = QString::number(stock.first) + ',' + item.second.title + ',' + item.second.authorName + ',' + QString::number(item.second.price) + ',' + QString::number(item.second.amount);
            out << tmp << '\n';
        }
    }
    file.flush();
    file.close();
    delete ui;
}


void MainWindow::on_newBookBtn_clicked()
{
    newBookWindow screen;
    screen.exec();
    screen.show();
}


void MainWindow::on_searchInStockBtn_clicked()
{
    searchStockWindow screen;
    screen.exec();
    screen.show();
}


void MainWindow::on_editBookBtn_clicked()
{
    editBookWindow screen;
    screen.exec();
    screen.show();
}


void MainWindow::on_searchForBookBtn_clicked()
{
    QString tarBook = QInputDialog::getText(this,"Book searching","Enter book title");
    if(!booksTitle.count(tarBook)){
        QMessageBox::information(this,"Book searching","Book was not found");
    }else{
        int stockPosition = booksTitle[tarBook];
        book *curBook = &stocks[stockPosition][tarBook];
        QMessageBox::information(this,"Book searching","Stock position: " + QString::number(stockPosition) + "\nBook name: " + tarBook + "\nAuthor name: " + curBook->authorName + "\nBook's price: " + QString::number(curBook->price) + "\nBook's amount: " + QString::number(curBook->amount));
    }
}


void MainWindow::on_buyBookBtn_clicked()
{
    QString tarBook = QInputDialog::getText(this,"Book buying","Enter book title");
    if(!booksTitle.count(tarBook)){
        QMessageBox::information(this,"Error","Book was not found");
        return;
    }
    int stockPosition = booksTitle[tarBook];
    int tarAmount = QInputDialog::getInt(this,"Book buying","Enter Amount");
    book *curBook = &stocks[stockPosition][tarBook];
    if(tarAmount > curBook->amount){
        QMessageBox::information(this,"Error","Current book's amount is smaller than the required amount");
        return;
    }
    curBook->amount -= tarAmount;
    QMessageBox::information(this,"Book buying","Successfully, ( " + QString::number(tarAmount) + " ) book's amount has been sold\nToatal price: " + QString::number(tarAmount * curBook->price) + "\nThe current book amount: ( " + QString::number(curBook->amount) + " )");
}

