#include "searchstockwindow.h"
#include "ui_searchstockwindow.h"
#include <QMessageBox>
#include <QDoubleValidator>
#include "book.h"
extern std::map<QString,int> booksTitle;
extern std::map<int,std::map<QString,book>> stocks;
searchStockWindow::searchStockWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchStockWindow)
{
    ui->setupUi(this);
    ui->stockPositionArea->setValidator( new QIntValidator(0, 100, this) );
}

searchStockWindow::~searchStockWindow()
{
    delete ui;
}

void searchStockWindow::on_showBooksBtn_clicked()
{
    ui->booksList->clear();
    int stockPosition = ui->stockPositionArea->text().toInt();
    for(auto& item : stocks[stockPosition]){
        ui->booksList->addItem(item.first);
    }
}


void searchStockWindow::on_booksList_itemClicked(QListWidgetItem *item)
{
    int stockPosition = ui->stockPositionArea->text().toInt();
    QString tarBook = item->text();
    book *curBook = &stocks[stockPosition][tarBook];
    QMessageBox::information(this,"Book details","Stock position: " + QString::number(stockPosition) + "\nBook name: " + tarBook + "\nAuthor name: " + curBook->authorName + "\nBook's price: " + QString::number(curBook->price) + "\nBook's amount: " + QString::number(curBook->amount));
}

