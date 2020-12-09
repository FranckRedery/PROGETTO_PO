#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "autore.h"
#include "gestore.h"
#include <QMessageBox>
#include <iostream>

using namespace std;

Gestore gestore;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pulsante_torna_menu, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->pulsante_tornaalmenu, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->vai_al_menu_principale, &QPushButton::clicked, this, &MainWindow::on_backtohome);
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
    QString afferenze = ui->afferenze_plaintext->toPlainText();

    QList<QString> aff;
    QString parola;

    for(int i = 0; i!=afferenze.size();i++){        // prendo ogni afferenza dalla stringa e le inserisco nella lista
        if(afferenze[i] != ' '){
            parola.push_back(afferenze[i]);
            if(i+1 == afferenze.size()){
                aff.push_back(parola);
                parola.clear();
            }
        }

        if(afferenze[i] == ' ' && !parola.isEmpty()){
            aff.push_back(parola);
            parola.clear();
        }
    }

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

    gestore.aggiungi_autore(nome,cognome,id,aff);
    ui->lista_autori->addItem(nome + "  " + cognome + "  ID : " + QString::number(id));

}

void MainWindow::on_go_pag_riviste_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_riviste);
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

    QString stringa_di_organizzatori = ui->organizzatori_plaintext->toPlainText();

    QList<QString> org;
    QString organizzatore;

    for(int i = 0; i!=stringa_di_organizzatori.size();i++){        // prendo ogni afferenza dalla stringa e le inserisco nella lista
        if(stringa_di_organizzatori[i] != ' '){
            organizzatore.push_back(stringa_di_organizzatori[i]);
            if(i+1 == stringa_di_organizzatori.size()){
                org.push_back(organizzatore);
                organizzatore.clear();
            }
        }

        if(stringa_di_organizzatori[i] == ' ' && !organizzatore.isEmpty()){
            org.push_back(organizzatore);
            organizzatore.clear();
        }
    }

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



    gestore.aggiungi_conferenza(nome,acronimo,data.toString(Qt::DateFormat::ISODate),luogo,part,org);
    ui->lista_conferenze->addItem("Nome : " + nome + "  Acronimo : " + acronimo + "  Luogo : " + luogo + "  Data : " + data.toString(Qt::DateFormat::ISODate) + "  Partecipanti : " + QString::number(part));
}

void MainWindow::on_go_pag_conferenze_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_conferenze);
}

void MainWindow::on_backtohome(){
    ui->stackedWidget->setCurrentWidget(ui->pagina_principale);
}
