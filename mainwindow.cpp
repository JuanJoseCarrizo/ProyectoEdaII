#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sistema.cargarMapaInicial();

    // =====================================
    // MENU CIUDAD ORIGEN
    // =====================================

    QMenu *ciudadOrigen = new QMenu(this);

    ciudadOrigen->addAction("Cordoba Capital");
    ciudadOrigen->addAction("Villa Carlos Paz");
    ciudadOrigen->addAction("Villa Maria");
    ciudadOrigen->addAction("Rio Cuarto");
    ciudadOrigen->addAction("Bell Ville");
    ciudadOrigen->addAction("San Francisco");

    ui->ButtonCiudadOrigen->setMenu(ciudadOrigen);
    ui->ButtonCiudadOrigen->setPopupMode(QToolButton::InstantPopup);

    connect(ciudadOrigen, &QMenu::triggered,
            this,
            [=](QAction *accion)
            {
                ui->ButtonCiudadOrigen->setText(accion->text());
            });


    // =====================================
    // MENU CIUDAD DESTINO
    // =====================================

    QMenu *ciudadDestino = new QMenu(this);

    ciudadDestino->addAction("Cordoba Capital");
    ciudadDestino->addAction("Villa Carlos Paz");
    ciudadDestino->addAction("Villa Maria");
    ciudadDestino->addAction("Rio Cuarto");
    ciudadDestino->addAction("Bell Ville");
    ciudadDestino->addAction("San Francisco");

    ui->ButtonCiudadDestino->setMenu(ciudadDestino);
    ui->ButtonCiudadDestino->setPopupMode(QToolButton::InstantPopup);

    connect(ciudadDestino, &QMenu::triggered,
            this,
            [=](QAction *accion)
            {
                ui->ButtonCiudadDestino->setText(accion->text());
            });

    // =====================================
    // MAPA
    // =====================================

    escena = new QGraphicsScene(this);

    ui->graphicsViewMapa->setScene(escena);

    // =====================================
    // COORDENADAS
    // =====================================

    const int CP_X = 40;
    const int CP_Y = 50;

    const int CC_X = 120;
    const int CC_Y = 50;

    const int VM_X = 250;
    const int VM_Y = 140;

    const int RC_X = 150;
    const int RC_Y = 320;

    const int BV_X = 380;
    const int BV_Y = 140;

    const int SF_X = 520;
    const int SF_Y = 80;

    // =====================================
    // ESTILO
    // =====================================

    QPen borde(Qt::black);
    borde.setWidth(2);

    QBrush relleno(Qt::cyan);

    // =====================================
    // RUTAS
    // =====================================

    escena->addLine(CP_X, CP_Y,
                    CC_X, CC_Y);

    escena->addLine(CC_X, CC_Y,
                    VM_X, VM_Y);

    escena->addLine(CC_X, CC_Y,
                    BV_X, BV_Y);

    escena->addLine(VM_X, VM_Y,
                    BV_X, BV_Y);

    escena->addLine(VM_X, VM_Y,
                    RC_X, RC_Y);

    escena->addLine(RC_X, RC_Y,
                    BV_X, BV_Y);

    escena->addLine(RC_X, RC_Y,
                    CP_X, CP_Y);

    escena->addLine(BV_X, BV_Y,
                    SF_X, SF_Y);

    // =====================================
    // CIUDADES
    // =====================================

    escena->addEllipse(CP_X - 8, CP_Y - 8,
                       16, 16,
                       borde, relleno);

    escena->addText("Villa Carlos Paz")
        ->setPos(CP_X + 10, CP_Y - 20);

    escena->addEllipse(CC_X - 8, CC_Y - 8,
                       16, 16,
                       borde, relleno);

    escena->addText("Cordoba Capital")
        ->setPos(CC_X + 10, CC_Y - 20);

    escena->addEllipse(VM_X - 8, VM_Y - 8,
                       16, 16,
                       borde, relleno);

    escena->addText("Villa Maria")
        ->setPos(VM_X + 10, VM_Y - 20);

    escena->addEllipse(RC_X - 8, RC_Y - 8,
                       16, 16,
                       borde, relleno);

    escena->addText("Rio Cuarto")
        ->setPos(RC_X + 10, RC_Y - 20);

    escena->addEllipse(BV_X - 8, BV_Y - 8,
                       16, 16,
                       borde, relleno);

    escena->addText("Bell Ville")
        ->setPos(BV_X + 10, BV_Y - 20);

    escena->addEllipse(SF_X - 8, SF_Y - 8,
                       16, 16,
                       borde, relleno);

    escena->addText("San Francisco")
        ->setPos(SF_X + 10, SF_Y - 20);
}

MainWindow::~MainWindow()
{
    delete ui;
}