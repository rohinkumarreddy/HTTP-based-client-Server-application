/*NOTES:
 *1.Here the Downloader Class Methods are Implemented
 *2.Method: doDownload() sends a Get request to the Http Server
 *3.Slot: replyFinished() saves the Downloaded File
*/

#include "downloader.h"

Downloader::Downloader(QObject *parent) :
    QObject(parent)
{

}

void Downloader::doDownload()
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl("http://localhost:8080/files/HTTPDATAFEED.json")));
}

void Downloader::replyFinished (QNetworkReply *reply)
{
    if(reply->error())
    {
        //qDebug() << "ERROR!";
        //qDebug() << reply->errorString();
    }
    else
    {
       /*qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
       */
        QFile *file = new QFile("../QHttpClient/Downloads/DownloadedData.json");
        if(file->open(QFile::WriteOnly))
        {
            file->write(reply->readAll());
            file->flush();
            file->close();
            //qDebug()<<"Downloaded";
        }
        delete file;
    }

    reply->deleteLater();
}

