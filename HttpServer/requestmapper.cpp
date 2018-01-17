/*NOTES:
 *1.Implements Various errors and status codes to show
 *2.Implements the request service based on QtWebApp
*/

#include "requestmapper.h"
StaticFileController* RequestMapper::staticFileController=0;
RequestMapper::RequestMapper(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response) {
    QByteArray path=request.getPath();
    qDebug("RequestMapper: path=%s",path.data());

    if (path.startsWith("/files")) {
        staticFileController->service(request,response);
    }
    else {
        response.setStatus(404,"Not found");
        response.write("The URL is wrong, no such document.",true);
    }

    qDebug("RequestMapper: finished request");
}
