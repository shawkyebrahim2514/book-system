#ifndef SEARCHSTOCKWINDOW_H
#define SEARCHSTOCKWINDOW_H

#include <QDialog>
#include <QListWidgetItem>
namespace Ui {
class searchStockWindow;
}

class searchStockWindow : public QDialog
{
    Q_OBJECT

public:
    explicit searchStockWindow(QWidget *parent = nullptr);
    ~searchStockWindow();

private slots:
    void on_showBooksBtn_clicked();

    void on_booksList_itemClicked(QListWidgetItem *item);

private:
    Ui::searchStockWindow *ui;
};

#endif // SEARCHSTOCKWINDOW_H
