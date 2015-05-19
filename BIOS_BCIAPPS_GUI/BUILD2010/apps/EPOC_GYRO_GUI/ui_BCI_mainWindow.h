/********************************************************************************
** Form generated from reading UI file 'BCI_mainWindow.ui'
**
** Created: Fri 15. May 16:18:20 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BCI_MAINWINDOW_H
#define UI_BCI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_BCI_mainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    GLWidget *VideoWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_XValue;
    QLabel *label_Yvalue;
    QLabel *label_6;
    QSpacerItem *verticalSpacer;
    QSlider *slider_1;
    QLabel *label;
    QSlider *slider_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *BCI_mainWindow)
    {
        if (BCI_mainWindow->objectName().isEmpty())
            BCI_mainWindow->setObjectName(QString::fromUtf8("BCI_mainWindow"));
        BCI_mainWindow->resize(527, 380);
        actionAbout = new QAction(BCI_mainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Images/fileinfo-32.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon);
        actionExit = new QAction(BCI_mainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        centralWidget = new QWidget(BCI_mainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        VideoWidget = new GLWidget(centralWidget);
        VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoWidget->sizePolicy().hasHeightForWidth());
        VideoWidget->setSizePolicy(sizePolicy);
        VideoWidget->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(VideoWidget);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        label_XValue = new QLabel(centralWidget);
        label_XValue->setObjectName(QString::fromUtf8("label_XValue"));
        label_XValue->setMinimumSize(QSize(30, 0));

        gridLayout->addWidget(label_XValue, 4, 2, 1, 1);

        label_Yvalue = new QLabel(centralWidget);
        label_Yvalue->setObjectName(QString::fromUtf8("label_Yvalue"));
        label_Yvalue->setMinimumSize(QSize(30, 0));

        gridLayout->addWidget(label_Yvalue, 4, 4, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 4);

        slider_1 = new QSlider(centralWidget);
        slider_1->setObjectName(QString::fromUtf8("slider_1"));
        slider_1->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_1, 1, 3, 1, 2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 2);

        slider_2 = new QSlider(centralWidget);
        slider_2->setObjectName(QString::fromUtf8("slider_2"));
        slider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(slider_2, 2, 3, 1, 2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 4);


        horizontalLayout->addLayout(gridLayout);

        BCI_mainWindow->setCentralWidget(centralWidget);
        statusbar = new QStatusBar(BCI_mainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        BCI_mainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(BCI_mainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        BCI_mainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionAbout);
        toolBar->addAction(actionExit);

        retranslateUi(BCI_mainWindow);

        QMetaObject::connectSlotsByName(BCI_mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BCI_mainWindow)
    {
        BCI_mainWindow->setWindowTitle(QApplication::translate("BCI_mainWindow", "BIOS - Brain Computer Interface", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("BCI_mainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("BCI_mainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("BCI_mainWindow", "Close application", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("BCI_mainWindow", "X Value:", 0, QApplication::UnicodeUTF8));
        label_XValue->setText(QString());
        label_Yvalue->setText(QString());
        label_6->setText(QApplication::translate("BCI_mainWindow", "Y Value:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BCI_mainWindow", "Angle:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BCI_mainWindow", "Magnitude:", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("BCI_mainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BCI_mainWindow: public Ui_BCI_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BCI_MAINWINDOW_H
