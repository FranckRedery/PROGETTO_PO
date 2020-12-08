#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "autore.h"
#include "gestore.h"
#include <QMessageBox>

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

void MainWindow::on_aggiungi_autore_clicked()
{

    QString nome = ui->linea_nome->text();
    QString cognome = ui->linea_cognome->text();

    if(nome.isEmpty() || cognome.isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "I campi nome e cognome non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    gestore.aggiungi_autore(nome,cognome);

    ui->lista_autori->addItem(nome + "  " + cognome);
}
