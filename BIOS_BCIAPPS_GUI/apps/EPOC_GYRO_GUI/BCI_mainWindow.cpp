#include "BCI_mainWindow.h"
#include "ui_BCI_mainWindow.h"

#include <QtGui>

// On load of the window
BCI_mainWindow::BCI_mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BCI_mainWindow)
{
    ui->setupUi(this);
	ConnectSlots();

	// Variables initialization
	
}

BCI_mainWindow::~BCI_mainWindow()
{
    delete ui;
}

// Slot connection
void BCI_mainWindow::ConnectSlots()
{
	QObject::connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(menuAbout_Click()));
	QObject::connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(menuClose_Click()));
}


// SLOT DEFINITION


void BCI_mainWindow::menuAbout_Click()
{
	// Show error message
	QMessageBox msgBox;
	msgBox.setWindowTitle("Credits (Spanish)");
	msgBox.setText("BIOS - BCI");
	msgBox.setInformativeText("Proyecto de Regalías:\n"
		"Convenio Especial de Cooperación 08112013-0621\n"
		"Celebrado entre el departamento de Caldas y el\n"
		"Centro de Bioinformática y Biología Computacional.\n\n"
		"Agradecimientos al  Ministerio de Tecnologías de\n"
		"la Información  y las Comunicaciones ( MINTIC ).\n\n"
		"Este proyecto está soportado en la biblioteca Qt 4.8.\n\n\n"
		"ÁREA DE INNOVACIÓN TECNOLÓGICA - CBBC\n");
	msgBox.exec();
}

void BCI_mainWindow::menuClose_Click()
{
	this->close();
}
