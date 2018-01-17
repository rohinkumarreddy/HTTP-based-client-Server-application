/*NOTES:
 *1.Main Window Class File
 *2.Consists of two Buttons - Start & Stop
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
