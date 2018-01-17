/*NOTES:
 *1.Creates Draw space for OpenGL
 *2.initializeGL() sets up the GLBuffers
 *and calls forth Parse() method to parse Json
 *3.paintGL() draws the lines as per the vertex
 *and Buffer Data
 *4.Parse() retrieves the data from Json File
*/

#include <glew/include/GL/glew.h>
#include "myglwindow.h"
static qint32 globalSize =0,globalVertSize=0;
MyGlWindow::MyGlWindow(QWidget *parent):QGLWidget(parent)
{
}
void MyGlWindow::initializeGL()
{
    glewInit();
    parse();
    GLfloat verts2[1000];
    qint32 index,kl;
    for(index = 0,kl=0;index < globalSize*3;index++,kl++)
    {
        verts2[kl] = VCords[index];
        if(index == 0){/*qDebug() << verts2[kl]*/;continue;}
        else{verts2[kl+1]=VCords[index];/*qDebug() << verts2[kl+1];*/kl+=1;}

    }
    globalVertSize = kl-1;
//this is test data->creates a box if given instead of verts2
   /* GLfloat verts[] =
    {
        +0.0f, +0.0f, +0.0f,
        +1.0f, +0.0f, +0.0f,

        +1.0f, +0.0f, +0.0f,
        +1.0f, +1.0f, +0.0f,

        +1.0f, +1.0f, +0.0f,
        +0.0f, +1.0f, +0.0f,

        +0.0f, +1.0f, +0.0f,
        +0.0f, +0.0f, +0.0f,
    };*/
    GLuint myBufferID;
    glGenBuffers(1, &myBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts2),verts2,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void MyGlWindow::paintGL()
{
    //glViewport(0,0,width(),height());
    glDrawArrays(GL_LINES,0,globalVertSize);
    /*glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, -1.0);
    glVertex3f(15, 0, 1);
    glEnd();*/
}
void MyGlWindow::parse()
{
    QFile *file = new QFile("../QHttpClient/Downloads/DownloadedData.json");
    if(file->open(QFile::ReadOnly))
    {
        QJsonDocument jsdoc1 = QJsonDocument::fromJson(file->readAll());
        QJsonObject jsObj = jsdoc1.object(),jset;
        QJsonArray jsData, jcords;
        qint32 rows = 0, cols = 0, JSize = 0;
        if(jsObj.contains("settings"))
        {
            jset = jsObj["settings"].toObject();
            //qDebug() << "Settings Received!";
            if(jset.contains("rows"))
            {
                rows = jset["rows"].toInt();
                //qDebug() << "Num of rows is " << rows;
            }
            else
            {
                //qDebug() << "Failed to extract num of rows!";
            }
            if(jset.contains("columns"))
            {
                cols = jset["columns"].toInt();
                //qDebug() << "Num of cols is " << cols;
            }
            else
            {
                //qDebug() << "Failed to extract num of columns!";
            }
        }
        else
        {
            //qDebug() << "Failed to extract Settings!";
        }
        if(jsObj.contains("data"))
        {
            jsData = jsObj["data"].toArray();
            //qDebug() << "Data Received!";
            globalSize = JSize = jsData.size();
            for(int index = 0,ij=0; index < JSize; index++,ij+=3)
            {
                jcords = jsData[index].toArray();
                VCords[ij] = (float)jcords[0].toInt();
                VCords[ij+1] = (float)jcords[1].toInt();
                VCords[ij+2] = (float)jcords[2].toInt();
                /*qDebug() << index << "Coordinates are " << "["
                <<VCords[index].xCor << ", " << VCords[index].yCor
                << ", " << VCords[index].zCor << "]";*/
            }
        }
        else
        {
            //qDebug() << "Failed to extract Data!";
        }
        file->close();
    }
    delete file;
    //qDebug() << "in Parse";

}

