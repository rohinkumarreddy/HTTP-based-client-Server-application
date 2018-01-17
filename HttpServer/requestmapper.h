/*NOTES:
 *1.Class File for the Request Mapper
 *2.Facilitates Various Requests using
 *Controllers
 *3.StaticFileController facilitates Serving
 *Local files on disk
*/
#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"
#include "staticfilecontroller.h"

using namespace stefanfrings;

class RequestMapper : public HttpRequestHandler {
    Q_OBJECT
public:
    RequestMapper(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
    static StaticFileController* staticFileController;

};

#endif // REQUESTMAPPER_H
