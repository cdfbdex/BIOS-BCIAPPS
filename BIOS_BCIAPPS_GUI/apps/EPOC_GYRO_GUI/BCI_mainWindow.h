#ifndef BCI_MAINWINDOW_H
#define BCI_MAINWINDOW_H



#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <glut.h>


namespace Ui {
    class BCI_mainWindow;
}

class BCI_mainWindow : public QMainWindow {
    Q_OBJECT

public:
    BCI_mainWindow(QWidget *parent = 0);
    ~BCI_mainWindow();

private slots:
	void menuAbout_Click();
	void menuClose_Click();

private:
	void ConnectSlots();

private:
    Ui::BCI_mainWindow *ui;
	QStandardItemModel *model;
    
};

#endif // BCI_mainWindow_H
