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
	msgBox.setInformativeText("Proyecto de Regal�as:\n"
		"Convenio Especial de Cooperaci�n 08112013-0621\n"
		"Celebrado entre el departamento de Caldas y el\n"
		"Centro de Bioinform�tica y Biolog�a Computacional.\n\n"
		"Agradecimientos al  Ministerio de Tecnolog�as de\n"
		"la Informaci�n  y las Comunicaciones ( MINTIC ).\n\n"
		"Este proyecto est� soportado en la biblioteca Qt 4.8.\n\n\n"
		"�REA DE INNOVACI�N TECNOL�GICA - CBBC\n");
	msgBox.exec();
}

void BCI_mainWindow::menuClose_Click()
{
	this->close();
}
