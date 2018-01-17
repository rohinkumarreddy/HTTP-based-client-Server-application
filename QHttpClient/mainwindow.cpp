/*NOTES:
 *1.Main Window Slots are implemented here
 *2.Signal: Clicked() is emitted on Start button click
 *which activates the slot on_pushButton_2_clicked()
 *calling method doDownload() from Downloader d object
 *which opens a OpenGL widget to draw
 *3.Button Stop closes the window and stops the Download/Http
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "downloader.h"
#include "myglwindow.h"
#include "widgetform.h"
Downloader d;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    d.doDownload();
    WidgetForm win;
    win.setModal(true);
    win.exec();
}
