#include <QApplication>
#include "window.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    MyWindow window;
    window.show();
    
    return app.exec();
}