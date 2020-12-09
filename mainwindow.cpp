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
    int id = ui->id_autore->value();

    if(nome.isEmpty() || cognome.isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "I campi nome e cognome non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(gestore.Is_ID_autore_alreadytaken(id)){
        QMessageBox mess_due(QMessageBox::Critical, "Errore", "L'ID richiesto è già occupato da un autore.", QMessageBox::Ok,this);
        mess_due.exec();
        return;
    }

    gestore.aggiungi_autore(nome,cognome,id);
    ui->lista_autori->addItem(nome + "  " + cognome + "  ID : " + QString::number(id));
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

    if(nome.isEmpty() || acronimo.isEmpty() || editore.isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "I campi nome, acronimo ed editore non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(gestore.Is_Nome_pubblicazione_alreadytaken(nome)){
        QMessageBox mess_due(QMessageBox::Critical, "Errore", "Nome inserito già occupato da un altra rivista/confereza (i nomi devono essere unici).", QMessageBox::Ok,this);
        mess_due.exec();
        return;
    }

    gestore.aggiungi_rivista(nome,acronimo,data.toString(Qt::DateFormat::ISODate),editore,volume);
    ui->lista_riviste->addItem("Nome : " + nome + "    Acronimo : " + acronimo + "    Editore : " + editore + "    Data : " + data.toString(Qt::DateFormat::ISODate) + "    Volume : " + QString::number(volume) );

}

void MainWindow::on_pulsante_aggiungi_conferenza_clicked()
{
    QString nome = ui->linea_nome_conferenza->text();
    QString acronimo = ui->linea_acronimo_conferenza->text();
    QString luogo = ui->linea_luogo_conferenza->text();
    int part = ui->num_partecipanti_conferenza->value();
    QDate data = ui->calendario_conferenze->selectedDate();

    if(nome.isEmpty() || acronimo.isEmpty() || luogo.isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "I campi nome, acronimo e luogo non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(gestore.Is_Nome_pubblicazione_alreadytaken(nome)){
        QMessageBox mess_due(QMessageBox::Critical, "Errore", "Nome inserito già occupato da un altra rivista/confereza (i nomi devono essere unici).", QMessageBox::Ok,this);
        mess_due.exec();
        return;
    }

    gestore.aggiungi_conferenza(nome,acronimo,data.toString(Qt::DateFormat::ISODate),luogo,part);
    ui->lista_conferenze->addItem("Nome : " + nome + "  Acronimo : " + acronimo + "  Luogo : " + luogo + "  Data : " + data.toString(Qt::DateFormat::ISODate) + "  Partecipanti : " + QString::number(part));
}

void MainWindow::on_vai_al_menu_principale_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_principale);
}

void MainWindow::on_go_pag_conferenze_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_conferenze);
}
