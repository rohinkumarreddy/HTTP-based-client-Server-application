# HTTP-based-client-Server-application
Client renders OpenGL 3D plots based on Data served by server over a HTTP connection.
Uses QtWebApp Library for the server and the data is served in json format.

**please make sure the build files and the source files are in the same level to ensure proper download of data

**Files location

HttpServer files are in the HttpServer/ directory, the files to be served are in HttpServer/docroot/files/ directory.
HttpServer also has the QtWebapp libraries in the HttpServer/Qtwebapp directory along with configuration settings in etc/

HttpClient files are in the QHttpClient/ directory, the files are downloaded to QHttpClient/Downloads directory.
For the OpenGL 3D plots we use glew library in the QHttpClient/glew/ directory.
