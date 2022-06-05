#ifndef NEWBOOKWINDOW_H
#define NEWBOOKWINDOW_H

#include <QDialog>

namespace Ui {
class newBookWindow;
}

class newBookWindow : public QDialog
{
    Q_OBJECT

public:
    explicit newBookWindow(QWidget *parent = nullptr);
    ~newBookWindow();

private slots:
    void on_RegisterBtn_clicked();

private:
    Ui::newBookWindow *ui;
};

#endif // NEWBOOKWINDOW_H
