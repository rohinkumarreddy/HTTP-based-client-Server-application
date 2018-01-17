/*NOTES:
 *1.Class File for the OpenGL Widget
 *2.Provides the draw space for OpenGL
 *3.Draws Lines as per Data
*/

#ifndef MYGLWINDOW_H
#define MYGLWINDOW_H

#include <QtOpenGL/QGLWidget>
#include <QFile>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class MyGlWindow : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGlWindow(QWidget *parent = 0);
    float VCords[1000];
protected:
    void initializeGL();
    void paintGL();
public slots:
    void parse();
};

#endif // MYGLWINDOW_H
