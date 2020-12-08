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

void MainWindow::on_go_pag_riviste_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_riviste);
}

void MainWindow::on_pulsante_torna_menu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_principale);
}

void MainWindow::on_pulsante_tornaalmenu_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_principale);
}

void MainWindow::on_pulsante_aggiungi_rivista_clicked()
{
    QString nome = ui->inserisci_nome->text();
    QString acronimo = ui->inserisci_acronimo->text();
    QString editore = ui->inserisci_editore->text();
    int volume = ui->inserisci_volume->value();
    QDate data = ui->calendario_rivista->selectedDate();

    if(nome.isEmpty() || acronimo.isEmpty() || editore.isEmpty() || data.isNull()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "I campi nome, acronimo, editore e data non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    gestore.aggiungi_rivista(nome,acronimo,data.toString(Qt::DateFormat::ISODate),editore,volume);
    ui->lista_riviste->addItem("Nome : " + nome + "  Acronimo : " + acronimo + "  Editore : " + editore + "  Data : " + data.toString(Qt::DateFormat::ISODate) + "  Volume : " + QString::number(volume) );

}
