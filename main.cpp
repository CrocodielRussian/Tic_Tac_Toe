#include "tictac.h"
#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow w1;
    w1.show();

    return a.exec();
}
