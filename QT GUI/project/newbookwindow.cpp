#include "newbookwindow.h"
#include "ui_newbookwindow.h"
#include <QMessageBox>
#include <QDoubleValidator>
#include "book.h"
extern std::map<QString,int> booksTitle;
extern std::map<int,std::map<QString,book>> stocks;
newBookWindow::newBookWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newBookWindow)
{
    ui->setupUi(this);
    ui->bookPriceArea->setValidator( new QDoubleValidator(0, 100, 2, this) );
    ui->bookAmountArea->setValidator( new QIntValidator(0, 100, this) );
    ui->stockPositionArea->setValidator( new QIntValidator(0, 100, this) );
}

newBookWindow::~newBookWindow()
{
    delete ui;
}

void newBookWindow::on_RegisterBtn_clicked()
{
    if(ui->stockPositionArea->text().isEmpty() || ui->bookTitleArea->text().isEmpty() || ui->authorNameArea->text().isEmpty() || ui->bookPriceArea->text().isEmpty() || ui->bookAmountArea->text().isEmpty()){
        QMessageBox::warning(this,"Error","Please, fill all details");
        return;
    }
    if(booksTitle.count(ui->bookTitleArea->text())){
        QMessageBox::warning(this,"Error","This book title exist before");
        return;
    }
    int stockPosition = ui->stockPositionArea->text().toInt();
    book newBook;
    newBook.title = ui->bookTitleArea->text();
    newBook.authorName = ui->authorNameArea->text();
    newBook.price = ui->bookPriceArea->text().toInt();
    newBook.amount = ui->bookAmountArea->text().toInt();
    stocks[stockPosition][newBook.title] = newBook;
    QMessageBox::information(this,"Book searching","Stock position: " + QString::number(stockPosition) + "\nBook name: " + newBook.title + "\nAuthor name: " + stocks[stockPosition][newBook.title].authorName + "\nBook's price: " + QString::number(stocks[stockPosition][newBook.title].price) + "\nBook's amount: " + QString::number(stocks[stockPosition][newBook.title].amount));
    hide();
}

