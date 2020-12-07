#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "autore.h"
#include "gestore.h"

Gestore gestore;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_go_pag_autori_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_autori);
}
