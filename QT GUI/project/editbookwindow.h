#ifndef EDITBOOKWINDOW_H
#define EDITBOOKWINDOW_H

#include <QDialog>

namespace Ui {
class editBookWindow;
}

class editBookWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editBookWindow(QWidget *parent = nullptr);
    ~editBookWindow();

private slots:
    void on_checkBookBtn_clicked();

    void on_changeBtn_clicked();

private:
    Ui::editBookWindow *ui;
};

struct book;
#endif // EDITBOOKWINDOW_H
