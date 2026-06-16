/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *widget_2;
    QWidget *widget_3;
    QToolButton *ButtonCiudadOrigen;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_5;
    QToolButton *ButtonCiudadDestino;
    QTextEdit *textEdit;
    QGraphicsView *graphicsViewMapa;
    QTextEdit *textEditResultado;
    QTextBrowser *textBrowserAlertas;
    QPushButton *pushButton_rehabilitar;
    QMenuBar *menubar;
    QMenu *menuSistema_de_Gestion_Logistica;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, -10, 861, 601));
        widget->setAutoFillBackground(false);
        widget->setStyleSheet(QString::fromUtf8("background-color: #111E2A;\n"
"border-radius: 15px;"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 120, 121, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: #1D5657;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: white;\n"
"border-radius: 10px;"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 170, 121, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #1D5657;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: white;\n"
"border-radius: 10px;"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 220, 121, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #1D5657;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: white;\n"
"border-radius: 10px;"));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 320, 121, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: #1D5657;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: white;\n"
"border-radius: 10px;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(140, 30, 711, 551));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: #F6F7F9;\n"
"border: rounded;"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 30, 461, 71));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: #FEFEFE;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: black;\n"
"border-radius: 15px;"));
        ButtonCiudadOrigen = new QToolButton(widget_3);
        ButtonCiudadOrigen->setObjectName("ButtonCiudadOrigen");
        ButtonCiudadOrigen->setGeometry(QRect(20, 30, 131, 31));
        ButtonCiudadOrigen->setStyleSheet(QString::fromUtf8("background-color: #FEFEFE;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: black;\n"
"\n"
"border: 1px solid gray;\n"
"border-radius: 4px;\n"
"padding: 5px;"));
        ButtonCiudadOrigen->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
        label = new QLabel(widget_3);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 71, 21));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: black;\n"
"\n"
""));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 10, 81, 21));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: black;\n"
"\n"
""));
        pushButton_5 = new QPushButton(widget_3);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(310, 20, 121, 41));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: #29958D;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: white;\n"
"\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"padding: 5px;"));
        ButtonCiudadDestino = new QToolButton(widget_3);
        ButtonCiudadDestino->setObjectName("ButtonCiudadDestino");
        ButtonCiudadDestino->setGeometry(QRect(160, 30, 131, 31));
        ButtonCiudadDestino->setStyleSheet(QString::fromUtf8("background-color: #FEFEFE;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: black;\n"
"\n"
"border: 1px solid gray;\n"
"border-radius: 4px;\n"
"padding: 5px;"));
        ButtonCiudadDestino->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
        textEdit = new QTextEdit(widget_2);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(10, 0, 321, 31));
        graphicsViewMapa = new QGraphicsView(widget_2);
        graphicsViewMapa->setObjectName("graphicsViewMapa");
        graphicsViewMapa->setGeometry(QRect(20, 100, 451, 371));
        textEditResultado = new QTextEdit(widget_2);
        textEditResultado->setObjectName("textEditResultado");
        textEditResultado->setGeometry(QRect(500, 30, 151, 401));
        textEditResultado->setStyleSheet(QString::fromUtf8("background-color: #FEFEFE;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: black;\n"
"border-radius: 15px;"));
        textEditResultado->setReadOnly(true);
        textBrowserAlertas = new QTextBrowser(widget_2);
        textBrowserAlertas->setObjectName("textBrowserAlertas");
        textBrowserAlertas->setGeometry(QRect(10, 441, 641, 81));
        textBrowserAlertas->setStyleSheet(QString::fromUtf8("QTextBrowser {\n"
"    background-color: #1A1D24; /* El gris oscuro que combina con tu fondo */\n"
"    color: #EAEAEA;            /* Letras claras y legibles */\n"
"    border: 1px solid #3B4252; /* Un borde sutil para que encuadre bien */\n"
"    border-radius: 8px;        /* Bordes redondeados est\303\251ticos */\n"
"    padding: 8px;              /* Espaciado interno para que el texto respire */\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 10px;\n"
"}"));
        pushButton_rehabilitar = new QPushButton(widget);
        pushButton_rehabilitar->setObjectName("pushButton_rehabilitar");
        pushButton_rehabilitar->setGeometry(QRect(10, 270, 121, 41));
        pushButton_rehabilitar->setStyleSheet(QString::fromUtf8("background-color: #1D5657;\n"
"font: 900 9pt \"Segoe UI Black\";\n"
"color: white;\n"
"border-radius: 10px;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuSistema_de_Gestion_Logistica = new QMenu(menubar);
        menuSistema_de_Gestion_Logistica->setObjectName("menuSistema_de_Gestion_Logistica");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSistema_de_Gestion_Logistica->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Agregar ciudad", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Agregar ruta", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Cortar ruta", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Mostrar historial", nullptr));
        ButtonCiudadOrigen->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Or\303\255gen", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Destino", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Calcular Ruta", nullptr));
        ButtonCiudadDestino->setText(QString());
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:11.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700; color:#000000;\">Planificaci\303\263n de Ruta \303\223ptima</span></p></body></html>", nullptr));
        pushButton_rehabilitar->setText(QCoreApplication::translate("MainWindow", "Rehabilitar ruta", nullptr));
        menuSistema_de_Gestion_Logistica->setTitle(QCoreApplication::translate("MainWindow", "Sistema de Gestion Logistica", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
