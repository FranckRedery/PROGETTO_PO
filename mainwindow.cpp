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
    connect(ui->pulsante_torna_al_menu, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->sezioneB_to_menu, &QPushButton::clicked, this, &MainWindow::on_backtohome);
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

    list<QString> aff;
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

    list<QString> org;
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

void MainWindow::on_pulsante_pag_aggiungiArticolo_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagina_articoli);
}

void MainWindow::on_pushButton_clicked()
{
    QString titolo = ui->titolo_articolo_linedit->text();
    QString nome_pubblicazione = ui->nome_pubblicazione_articolo_linedit->text();
    int id = ui->identificativo_articolo_linedit->value();
    int pagine = ui->numpagine_articolo_linedit->value();
    double prezzo = ui->prezzoarticolo_linedit->value();

    QString stringa_di_autori = ui->plaintext_autori_di_articolo->toPlainText();

    list<Autore*> autori;
    QString id_autore;

    for(int i = 0 ; i!=stringa_di_autori.size();i++){
        if(stringa_di_autori[i] != ' '){
            id_autore.push_back(stringa_di_autori[i]);
            if(i+1 == stringa_di_autori.size() && gestore.get_autore(id_autore.toInt())!=nullptr){
                autori.push_back(gestore.get_autore(id_autore.toInt()));
                id_autore.clear();
            }
        }

        if(stringa_di_autori[i] == ' ' && !id_autore.isEmpty()){
            if(gestore.get_autore(id_autore.toInt())!=nullptr){
                autori.push_back(gestore.get_autore(id_autore.toInt()));
            }
            id_autore.clear();
        }
    }

    QString stringa_articoli = ui->plaintext_articoli_correlati_di_articolo->toPlainText();
    list<int> articoli_correlati;
    QString art;

    for(int i = 0 ; i!=stringa_articoli.size();i++){
        if(stringa_articoli[i] != ' '){
            art.push_back(stringa_articoli[i]);
            if(i+1 == stringa_articoli.size()){
                articoli_correlati.push_back(art.toInt());
                art.clear();
            }
        }

        if(stringa_articoli[i] == ' ' && !art.isEmpty()){
            articoli_correlati.push_back(art.toInt());
            art.clear();
        }
    }


    QString stringa_keyword = ui->plaintext_keyword_di_articolo->toPlainText();
    list<QString> keyword;
    QString chiave;

    for(int i = 0 ; i!=stringa_keyword.size();i++){
        if(stringa_keyword[i] != ' '){
            chiave.push_back(stringa_keyword[i]);
            if(i+1 == stringa_keyword.size()){
                keyword.push_back(chiave);
                chiave.clear();
            }
        }

        if(stringa_keyword[i] == ' ' && !chiave.isEmpty()){
            keyword.push_back(chiave);
            chiave.clear();
        }

    }

    if(titolo.isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "Il nome dell'articolo non può essere vuoto.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(gestore.Is_ID_articolo_alreadytaken(id)){
        QMessageBox mess_due(QMessageBox::Critical, "Errore", "L'ID richiesto è già occupato da un articolo.", QMessageBox::Ok,this);
        mess_due.exec();
        return;
    }


    if(gestore.get_pubblicazione(nome_pubblicazione) == nullptr){
        QMessageBox mess_tre(QMessageBox::Critical, "Errore", "La conferenza/rivista in cui pubblicare l'articolo non esiste.", QMessageBox::Ok,this);
        mess_tre.exec();
        return;
    }

    gestore.aggiungi_articolo(id,pagine,prezzo,titolo,gestore.get_pubblicazione(nome_pubblicazione),articoli_correlati,autori,keyword);
    ui->lista_di_articoli->addItem("ID :  " + QString::number(id) + "  Titolo :  " + titolo + "  Pagine :  " + QString::number(pagine) + "  Prezzo :  " + QString::number(prezzo) + "  Conferenza/Rivista associata :  " + nome_pubblicazione);
}

void MainWindow::on_SEZIONE_B_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_SEZIONE_B);
}

void MainWindow::on_SEZIONEB_PULSANTE_VISUALIZZA_clicked()
{
    ui->SEZIONE_B_visualizzazione_articoli->clear();
    list<Articolo*> lista_articoli;
    if(ui->SezioneB_scelta_visualizza_articoli_per_autore->isChecked()){
        int id = ui->sezioneB_id_autore->value();
        gestore.get_articoli_autore(id,lista_articoli);

        for(auto& i : lista_articoli){
            ui->SEZIONE_B_visualizzazione_articoli->addItem("ID :  " + QString::number(i->get_identificativo()) + "  Titolo :  " + i->get_titolo() + "  Pagine : " + QString::number(i->get_num_pagine()) + "  Prezzo : " + QString::number(i->get_prezzo()) + "  Conferenza/Rivista associata :  " + i->get_pubblicazione()->get_nome());
        }

    }
    lista_articoli.clear();
}





