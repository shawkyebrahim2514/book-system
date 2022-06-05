#include "editbookwindow.h"
#include "ui_editbookwindow.h"
#include <QMessageBox>
#include <QDoubleValidator>
#include "book.h"
extern std::map<QString,int> booksTitle;
extern std::map<int,std::map<QString,book>> stocks;
editBookWindow::editBookWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editBookWindow)
{
    ui->setupUi(this);
    ui->bookPriceArea->setValidator( new QDoubleValidator(0, 100, 2, this) );
    ui->bookAmountArea->setValidator( new QIntValidator(0, 100, this) );
    ui->authorNameArea->setEnabled(false);
    ui->bookPriceArea->setEnabled(false);
    ui->bookAmountArea->setEnabled(false);
    ui->changeBtn->setEnabled(false);
    ui->authorNameLabel->setEnabled(false);
    ui->bookPriceLabel->setEnabled(false);
    ui->bookAmountLabel->setEnabled(false);
}

editBookWindow::~editBookWindow()
{
    delete ui;
}

void editBookWindow::on_checkBookBtn_clicked()
{
    QString tarBook = ui->bookTitleArea->text();
    if(!booksTitle.count(tarBook)){
        QMessageBox::information(this,"Book searching","Book was not found");
    }else{
        /*int stockPosition = booksTitle[tarBook];
        QMessageBox::information(this,"Book searching","Stock position: " + QString::number(stockPosition) + "\nBook name: " + tarBook + "\nAuthor name: " + stocks[stockPosition][tarBook].authorName + "\nBook's price: " + QString::number(stocks[stockPosition][tarBook].price) + "\nBook's amount: " + QString::number(stocks[stockPosition][tarBook].amount));*/
        ui->authorNameArea->setEnabled(true);
        ui->bookPriceArea->setEnabled(true);
        ui->bookAmountArea->setEnabled(true);
        ui->changeBtn->setEnabled(true);
        ui->authorNameLabel->setEnabled(true);
        ui->bookPriceLabel->setEnabled(true);
        ui->bookAmountLabel->setEnabled(true);
    }
}


void editBookWindow::on_changeBtn_clicked()
{
    QString tarBook = ui->bookTitleArea->text();
    int stockPosition = booksTitle[tarBook];
    book *curBook = &stocks[stockPosition][tarBook];
    if(!ui->authorNameArea->text().isEmpty()){
        curBook->authorName = ui->authorNameArea->text();
    }
    if(!ui->bookPriceArea->text().isEmpty()){
        curBook->price = ui->bookPriceArea->text().toInt();
    }
    if(!ui->bookAmountArea->text().isEmpty()){
        curBook->price = ui->bookAmountArea->text().toInt();
    }
    QMessageBox::information(this,"Book changing details","Stock position: " + QString::number(stockPosition) + "\nBook name: " + tarBook + "\nAuthor name: " + curBook->authorName + "\nBook's price: " + QString::number(curBook->price) + "\nBook's amount: " + QString::number(curBook->amount));
    hide();
}

