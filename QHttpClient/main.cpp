/*NOTES:
 *1.Main() File for the Http Downloader
 *2.Creates the main window object and
 * projects it on screen
*/

#include "mainwindow.h"
#include <QApplication>
#include <downloader.h>
#include "myglwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
