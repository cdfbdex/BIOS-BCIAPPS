#include <QtGui/QApplication>
#include "BCI_mainWindow.h"

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
    QApplication a(argc, argv);
    BCI_mainWindow w;
	w.show();
    
    return a.exec();
}
