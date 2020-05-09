#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "version.h"
#include "../about/ui_about.h"

#include <QDoubleValidator>
#include <cmath>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::setWindowIcon(QIcon(":/app/img/logo.png"));

    QString titleBar = QString("%1 [Build: %2]").arg(MainWindow::windowTitle()).arg(VERSION_REVISION);

    MainWindow::setWindowTitle(titleBar);
    ui->numA->setValidator( new QDoubleValidator() );
    ui->numB->setValidator( new QDoubleValidator() );
    ui->numC->setValidator( new QDoubleValidator() );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnCalcular_clicked()
{
    float a = ui->numA->text().toFloat();
    float b = ui->numB->text().toFloat();
    float c = ui->numC->text().toFloat();

    float delta = pow(b, 2) - (4 * a * c);

    float x1 = (-b + sqrt(delta)) / (2 * a);
    float x2 = (-b - sqrt(delta)) / (2 * a);
    float xv = -(b/(2*a));
    float yv = a * pow(xv, 2) + b * xv + c;

    QString resultado = "-- Resultados --\n";
    resultado += QString("Δ: %1\n\n").arg(delta);
    resultado += QString("X1: %1\nX2: %2\n\n").arg(x1).arg(x2);
    resultado += QString("Xv: %1\nYv: %2").arg(xv).arg(yv);

    ui->lblResultado->setText(resultado);
}

void MainWindow::on_actionAbout_triggered()
{
    short vMajor = VERSION_MAJOR;
    short vMinor = VERSION_MINOR;
    short vRevision = VERSION_REVISION;

    QString message = QString("SD Bhaskara\nMade by SavanDev\nVersion %1.%2\nBuild: %3").arg(vMajor).arg(vMinor).arg(vRevision);

    QDialog *about = new QDialog(0, 0);

    Ui::About aboutUi;
    aboutUi.setupUi(about);
    aboutUi.labelInfo->setText(message);

    about->setWindowIcon(QIcon(":/app/img/logo.png"));
    about->show();
}
