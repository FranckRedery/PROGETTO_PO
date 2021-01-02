/*This file is part of ProgettoPO-2020-2021-Reda-209394.

ProgettoPO-2020-2021-Reda-209394 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProgettoPO-2020-2021-Reda-209394 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProgettoPO-2020-2021-Reda-209394.  If not, see <http://www.gnu.org/licenses/>.*/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "autore.h"
#include "gestore.h"
#include "pubblicazione.h"
#include "rivista.h"
#include "conferenza.h"
#include <QMessageBox>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <sstream>
#include <string>

std::list<int> id_autori;
std::list<int> id_correlati;

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
    connect(ui->SEZIONE_C_TORNAMENU, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->PAG_D_MENU, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->PAG_E_BOTTONE_MENU, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->PAG_F_TORNA_MENU, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->PAG_VISUALIZZA_ARTICOLI_PULSANTE_MENU, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->PAG_VISUALIZZA_AUTORI_PULSANTE_MENU, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->PAG_VISUALIZZA_CONFERENZE_PULSANTE_MENU, &QPushButton::clicked, this, &MainWindow::on_backtohome);
    connect(ui->PAG_VISUALIZZA_RIVISTE_PULSANTE_MENU_, &QPushButton::clicked, this, &MainWindow::on_backtohome);
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

    std::list<QString> aff;
    QString parola;
    QString visualizza_afferenze;

    // prendo ogni afferenza dalla stringa e le inserisco nella lista
    // analizzo char per char e quando trovo una virgola salvo un afferenza
    for(int i = 0; i!=afferenze.size();i++){
        if(afferenze[i] != ',' && !parola.isEmpty()){
            parola.push_back(afferenze[i]);
            if(i+1 == afferenze.size()){
                aff.push_back(parola.simplified());
                visualizza_afferenze += parola.simplified();
                visualizza_afferenze += ", ";
                parola.clear();
            }
        }
        if(parola.isEmpty() && afferenze[i]!=' ' && afferenze[i]!=','){
            parola.push_back(afferenze[i]);
        }
        if(afferenze[i] == ',' && !parola.isEmpty()){
            aff.push_back(parola.simplified());
            visualizza_afferenze += parola.simplified();
            visualizza_afferenze += ", ";
            parola.clear();
        }
    }

    //QUESTO SERVE SOLAMENTE PER CAMBIARE L'ULTIMO CHAR NELLA QWIDGET LIST DI VISUALIZZAZIONE
    // DA , IN . PER AVERE UNA VISUALIZZAZIONE LEGGERMENTE PIU' CARINA
    if(visualizza_afferenze.size()>=2){
        int last_char = visualizza_afferenze.size()-2;
        visualizza_afferenze[last_char] = '.';
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
    ui->PAG_VISUALIZZA_AUTORI_LISTA->addItem("ID : " + QString::number(id) + "    NOME : "+ nome + "    COGNOME : " + cognome + "    AFFERENZE : " + visualizza_afferenze);
    ui->articolo_lista_add_autori->addItem(QString::number(id));

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
    int id = ui->id_rivista->value();
    QDate data = ui->calendario_rivista->selectedDate();

    if(nome.isEmpty() || acronimo.isEmpty() || editore.isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "I campi nome, acronimo ed editore non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(gestore.Is_ID_pubblicazione_alreadytaken(id)){
        QMessageBox mess_due(QMessageBox::Critical, "Errore", "ID inserito già occupato da un altra rivista/conferenza (gli ID devono essere unici).", QMessageBox::Ok,this);
        mess_due.exec();
        return;
    }

    if(!gestore.is_pubblicazione_unique(data.toString(Qt::DateFormat::ISODate).simplified(),nome.simplified(),false)){
        QMessageBox mess_err(QMessageBox::Critical, "Errore", "Nome e data già occupate da un altra rivista (Non possono esistere riviste con stesso nome e data).", QMessageBox::Ok,this);
        mess_err.exec();
        return;
    }

    gestore.aggiungi_rivista(id,nome,acronimo,data.toString(Qt::DateFormat::ISODate),editore,volume);
    ui->PAG_VISUALIZZA_RIVISTE_LISTA->addItem("ID : " + QString::number(id) + "    NOME : " + nome + "    ACRONIMO : " + acronimo + "    EDITORE : " + editore + "    DATA : " + data.toString(Qt::DateFormat::ISODate) + "    VOLUME : " + QString::number(volume));
    ui->articolo_lista_id_pubb->addItem(QString::number(id));
}

void MainWindow::on_pulsante_aggiungi_conferenza_clicked()
{
    QString nome = ui->linea_nome_conferenza->text();
    QString acronimo = ui->linea_acronimo_conferenza->text();
    QString luogo = ui->linea_luogo_conferenza->text();
    int id = ui->id_conferenza->value();
    int part = ui->num_partecipanti_conferenza->value();
    QDate data = ui->calendario_conferenze->selectedDate();

    QString stringa_di_organizzatori = ui->organizzatori_plaintext->toPlainText();

    std::list<QString> org;
    QString organizzatore;
    QString visualizza_organizzatori;

    // prendo ogni afferenza dalla stringa e le inserisco nella lista
    // analizzo char per char e ogni volta che trovo una virgola aggiungo l'organizzatore
    for(int i = 0; i!=stringa_di_organizzatori.size();i++){
        if(stringa_di_organizzatori[i] != ',' && !organizzatore.isEmpty()){
            organizzatore.push_back(stringa_di_organizzatori[i]);
            if(i+1 == stringa_di_organizzatori.size()){
                org.push_back(organizzatore.simplified());
                visualizza_organizzatori += organizzatore.simplified();
                visualizza_organizzatori += ", ";
                organizzatore.clear();
            }
        }
        if(organizzatore.isEmpty() && stringa_di_organizzatori[i]!=' ' && stringa_di_organizzatori[i]!=','){
            organizzatore.push_back(stringa_di_organizzatori[i]);
        }
        if(stringa_di_organizzatori[i] == ',' && !organizzatore.isEmpty()){
            org.push_back(organizzatore.simplified());
            visualizza_organizzatori += organizzatore.simplified();
            visualizza_organizzatori += ", ";
            organizzatore.clear();
        }
    }

    //QUESTO SERVE SOLAMENTE PER CAMBIARE L'ULTIMO CHAR NELLA QWIDGET LIST DI VISUALIZZAZIONE
    // DA , IN . PER AVERE UNA VISUALIZZAZIONE LEGGERMENTE PIU' CARINA
    if(visualizza_organizzatori.size()>=2){
        int last_char = visualizza_organizzatori.size()-2;
        visualizza_organizzatori[last_char] = '.';
    }

    if(nome.isEmpty() || acronimo.isEmpty() || luogo.isEmpty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "I campi nome, acronimo e luogo non possono essere vuoti.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(gestore.Is_ID_pubblicazione_alreadytaken(id)){
        QMessageBox mess_due(QMessageBox::Critical, "Errore", "ID inserito già occupato da un altra rivista/conferenza (gli ID devono essere unici).", QMessageBox::Ok,this);
        mess_due.exec();
        return;
    }

    if(!gestore.is_pubblicazione_unique(data.toString(Qt::DateFormat::ISODate).simplified(),nome.simplified(),true)){
        QMessageBox mess_err(QMessageBox::Critical, "Errore", "Nome e data già occupate da un altra confereza (Non possono esistere conferenze con stesso nome e data).", QMessageBox::Ok,this);
        mess_err.exec();
        return;
    }

    gestore.aggiungi_conferenza(id,nome,acronimo,data.toString(Qt::DateFormat::ISODate),luogo,part,org);
    ui->PAG_VISUALIZZA_CONFERENZE_LISTA->addItem( "ID : " + QString::number(id) +"    NOME : " + nome + "    ACRONIMO : " + acronimo + "    LUOGO : " + luogo + "    DATA : " + data.toString(Qt::DateFormat::ISODate) + "    PARTECIPANTI : " + QString::number(part) + "    ORGANIZZATORI : " + visualizza_organizzatori );
    ui->articolo_lista_id_pubb->addItem(QString::number(id));
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
    int id_pubblicazione;
    int id = ui->identificativo_articolo_linedit->value();
    int pagine = ui->numpagine_articolo_linedit->value();
    double prezzo = ui->prezzoarticolo_linedit->value();

    if(ui->articolo_lista_id_pubb->selectedItems().size() != 0){
            id_pubblicazione = ui->articolo_lista_id_pubb->currentItem()->text().toInt();
    }

    else{

        QMessageBox mess_quattro(QMessageBox::Critical, "Errore", "Devi obbligatoriamente selezionare una rivista/conferenza in cui pubblicare l'articolo", QMessageBox::Ok,this);
        mess_quattro.exec();
        return;
    }

    std::string visualizza_autori;
    std::list<Autore*> autori;
    std::ostringstream str1;

    id_autori.sort();
    id_autori.unique();
    for(auto& i : id_autori){
        if(gestore.get_autore(i)!=nullptr){
            autori.push_back(gestore.get_autore(i));
            str1<< i;
            visualizza_autori += str1.str();
            visualizza_autori += "  ";
            str1.str("");
            str1.clear();
        }
    }

    std::string visualizza_correlati;
    std::list<int> articoli_correlati;
    QString art;
    id_correlati.sort();
    id_correlati.unique();
    for(auto& i : id_correlati){
        articoli_correlati.push_back(i);
        str1<< i;
        visualizza_correlati += str1.str();
        visualizza_correlati += " ";
        str1.str("");
        str1.clear();
    }

    QString stringa_keyword = ui->plaintext_keyword_di_articolo->toPlainText();
    QString visualizza_keyword;
    std::list<QString> keyword;
    QString chiave;

    //analizzo char per char la sezione delle keyword
    // quando trovo una virgola ',' aggiungo una keyword
    for(int i = 0 ; i!=stringa_keyword.size();i++){
        if(stringa_keyword[i] != ',' && !chiave.isEmpty()){
            chiave.push_back(stringa_keyword[i]);
            if(i+1 == stringa_keyword.size()){
                keyword.push_back(chiave.simplified());
                visualizza_keyword += chiave.simplified();
                visualizza_keyword += ", ";
                chiave.clear();
            }
        }
        if(chiave.isEmpty() && stringa_keyword[i]!=' ' && stringa_keyword[i]!=','){
            chiave.push_back(stringa_keyword[i]);
        }
        if(stringa_keyword[i] == ',' && !chiave.isEmpty()){
            keyword.push_back(chiave.simplified());
            visualizza_keyword += chiave.simplified();
            visualizza_keyword += ", ";
            chiave.clear();
        }

    }

    //QUESTO SERVE SOLAMENTE PER CAMBIARE L'ULTIMO CHAR NELLA QWIDGET LIST DI VISUALIZZAZIONE
    // DA , IN . PER AVERE UNA VISUALIZZAZIONE LEGGERMENTE PIU' CARINA
    int last_char;
    if(visualizza_keyword.size()>=2){
        last_char = visualizza_keyword.size()-2;
        visualizza_keyword[last_char] = '.';
    }

    if(titolo.isEmpty() || autori.empty() || keyword.empty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "Hai lasciato uno o più di questi campio vuoto Nome articolo/Keyword/Autori.", QMessageBox::Ok,this);
        mess.exec();
        return;
    }

    if(gestore.Is_ID_articolo_alreadytaken(id)){
        QMessageBox mess_due(QMessageBox::Critical, "Errore", "L'ID richiesto è già occupato da un articolo.", QMessageBox::Ok,this);
        mess_due.exec();
        return;
   }

    gestore.aggiungi_articolo(id,pagine,prezzo,titolo,gestore.get_pubblicazione(id_pubblicazione),articoli_correlati,autori,keyword);
    ui->PAG_VISUALIZZA_ARTICOLI_LISTA->addItem("ID ARTICOLO : " + QString::number(id) + "    TITOLO : " + titolo + "    PAGINE : " + QString::number(pagine) + "    PREZZO : " + QString::number(prezzo) + "    ID CONFERENZA/RIVISTA ASSOCIATA : " + QString::number(id_pubblicazione)  + "    ID AUTORI : " + QString::fromStdString(visualizza_autori) +"    ID ARTICOLI CORRELATI : " + QString::fromStdString(visualizza_correlati) + "    KEYWORDS : " + visualizza_keyword);
    id_autori.clear();
    id_correlati.clear();
    ui->articoli_lista_correlati->addItem(QString::number(id));
}

void MainWindow::on_SEZIONE_B_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_SEZIONE_B);
}

void MainWindow::on_SEZIONEB_PULSANTE_VISUALIZZA_clicked()
{
    ui->SEZIONE_B_visualizzazione_articoli->clear();

    // questa è la lista di articoli che riempirò chiamando i metodi di questa sezione
    std::list<Articolo*> lista_articoli;

    if(ui->SezioneB_scelta_visualizza_articoli_per_autore->isChecked()){
        int id = ui->sezioneB_id_autore->value();
        gestore.get_articoli_autore(id,lista_articoli);

        for(auto& i : lista_articoli){
            ui->SEZIONE_B_visualizzazione_articoli->addItem("ID ARTICOLO :  " + QString::number(i->get_identificativo()) + "  TITOLO :  " + i->get_titolo() + "  PAGINE : " + QString::number(i->get_num_pagine()) + "  PREZZO : " + QString::number(i->get_prezzo()) + "  ID CONFERENZA/RIVISTA ASSOCIATA :  " + QString::number(i->get_pubblicazione()->get_id()));
        }

    }

    if(ui->SEZIONE_B_pulsante_visualizz_articoli_di_conferenza->isChecked()){
        gestore.get_articoli_conferenza_or_rivista(ui->SEZIONE_B_ID_CONFERENZA->value(),lista_articoli);
        for(auto& i : lista_articoli){
            if(i->get_pubblicazione()->is_conferenza() == false){
                QMessageBox mess(QMessageBox::Critical, "Errore", "L'ID che hai inserito corrisponde ad una RIVISTA.", QMessageBox::Ok,this);
                mess.exec();
                return;
            }
            ui->SEZIONE_B_visualizzazione_articoli->addItem("ID ARTICOLO :  " + QString::number(i->get_identificativo()) + "  TITOLO :  " + i->get_titolo() + "  PAGINE : " + QString::number(i->get_num_pagine()) + "  PREZZO : " + QString::number(i->get_prezzo()) + "  ID CONFERENZA/RIVISTA ASSOCIATA :  " + QString::number(i->get_pubblicazione()->get_id()));
        }
    }

    if(ui->SEZIONE_B_pulsante_visualizz_articoli_di_rivista->isChecked()){
        gestore.get_articoli_conferenza_or_rivista(ui->SEZIONE_B_ID_RIVISTA->value(),lista_articoli);
        for(auto& i : lista_articoli){
            if(i->get_pubblicazione()->is_conferenza() == true){
                QMessageBox mess(QMessageBox::Critical, "Errore", "L'ID che hai inserito corrisponde ad una CONFERENZA.", QMessageBox::Ok,this);
                mess.exec();
                return;
            }
            ui->SEZIONE_B_visualizzazione_articoli->addItem("ID ARTICOLO :  " + QString::number(i->get_identificativo()) + "  TITOLO :  " + i->get_titolo() + "  PAGINE : " + QString::number(i->get_num_pagine()) + "  PREZZO : " + QString::number(i->get_prezzo()) + "  ID CONFERENZA/RIVISTA ASSOCIATA :  " + QString::number(i->get_pubblicazione()->get_id()));
        }
    }

    lista_articoli.clear();
}






void MainWindow::on_SEZIONE_C_PULSANTE_CONFERMA_clicked()
{
    ui->SEZIONE_C_LISTWIDGET->clear();

    // questa è la lista di articoli e di keyword che riempirò chiamando i metodi
    // che richiede la sezione

    std::list<Articolo*> lista_articoli;
    std::list<QString> keyword_max;

    if(ui->SEZIONE_C_ARTICOLI_MIN->isChecked()){
                                                        // con 1 come ultimo parametro del metodo trovo gli articoli con prezzo min
        gestore.get_articoli_autore_prezzo_max_or_min(ui->SEZIONE_C_ID_AUTORE->value(),lista_articoli,1);
        for(auto& i : lista_articoli){
            ui->SEZIONE_C_LISTWIDGET->addItem("ID ARTICOLO :  " + QString::number(i->get_identificativo()) + "  TITOLO :  " + i->get_titolo() + "  PAGINE : " + QString::number(i->get_num_pagine()) + "  PREZZO : " + QString::number(i->get_prezzo()) + "  ID CONFERENZA/RIVISTA ASSOCIATA :  " + QString::number(i->get_pubblicazione()->get_id()));
        }
    }
    if(ui->SEZIONE_C_ARTICOLI_MAX->isChecked()){
                                                     // con 2 come ultimo parametro del metodo trovo gli articoli con prezzo max
        gestore.get_articoli_autore_prezzo_max_or_min(ui->SEZIONE_C_ID_AUTORE->value(),lista_articoli,2);
        for(auto& i : lista_articoli){
            ui->SEZIONE_C_LISTWIDGET->addItem("ID ARTICOLO :  " + QString::number(i->get_identificativo()) + "  TITOLO :  " + i->get_titolo() + "  PAGINE : " + QString::number(i->get_num_pagine()) + "  PREZZO : " + QString::number(i->get_prezzo()) + "  ID CONFERENZA/RIVISTA ASSOCIATA :  " + QString::number(i->get_pubblicazione()->get_id()));
        }
    }
    if(ui->SEZIONE_C_KEYWORD_MAX->isChecked()){
        gestore.get_keywords_guadagno_max(keyword_max);
        for(auto& i : keyword_max){
            ui->SEZIONE_C_LISTWIDGET->addItem(i);
        }
    }


    lista_articoli.clear();
    keyword_max.clear();
}

void MainWindow::on_SEZIONE_C_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_SEZIONE_C);
}

void MainWindow::on_PAG_D_PULSANTE_CONFERMA_clicked()
{
    ui->PAG_D_LISTA->clear();

    // lista che riempio con gli articoli presi dai metodi della sezione
    std::list<Articolo*> lista_articoli;

    if(ui->PAG_D_RADIO_VISUALIZZA_AUTORE->isChecked()){
        gestore.articoli_autore_sorted(ui->PAG_D_ID_AUTORE->value(),lista_articoli);
        for(auto& i : lista_articoli){
            ui->PAG_D_LISTA->addItem("ID ARTICOLO :  " + QString::number(i->get_identificativo()) + "  TITOLO :  " + i->get_titolo() + "  PAGINE : " + QString::number(i->get_num_pagine()) + "  PREZZO : " + QString::number(i->get_prezzo()) + "  ID CONFERENZA/RIVISTA ASSOCIATA :  " + QString::number(i->get_pubblicazione()->get_id()));
        }
    }

    if(ui->PAG_D_RADIO_metodo_d2->isChecked()){
        gestore.articoli_autore_sorted_prezzo(ui->PAG_D_ID_AUTORE->value(),lista_articoli);
        for(auto& i : lista_articoli){
            ui->PAG_D_LISTA->addItem("ID ARTICOLO :  " + QString::number(i->get_identificativo()) + "  TITOLO :  " + i->get_titolo() + "  PAGINE : " + QString::number(i->get_num_pagine()) + "  PREZZO : " + QString::number(i->get_prezzo()) + "  ID CONFERENZA/RIVISTA ASSOCIATA :  " + QString::number(i->get_pubblicazione()->get_id()));
        }
    }

    lista_articoli.clear();
}

void MainWindow::on_pulsante_sezione_D_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_SEZIONE_D);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_SEZIONE_E);
}



void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_SEZIONE_F);
}

void MainWindow::on_PAG_E_pulsante_riviste_spec_clicked()
{
    ui->PAG_E_LISTA->clear();

    // lista che riempirò attraverso il metodo della sezione
    std::list<Pubblicazione*> riviste;

    gestore.get_riviste_specialistiche(riviste);

    for(auto& i : riviste){
        ui->PAG_E_LISTA->addItem("ID : " + QString::number(i->get_id()) + "    NOME : " + i->get_nome() + "    ACRONIMO : " + i->get_acronimo() + "    DATA : " + i->get_data());
    }
    riviste.clear();
}



void MainWindow::on_PAG_F_CERCA_CONFERENZE_COMUN_clicked()
{
    // lista che riempirò con le conferenze comuni prese dal metodo
    std::list<Pubblicazione*> comuni;

    ui->PAG_F_LISTA->clear();
    gestore.get_conferenze_simili(ui->PAGINA_F_ID_CONFERENZA->value(),comuni);
    for(auto& i : comuni){
        ui->PAG_F_LISTA->addItem("ID : "+ QString::number(i->get_id()) + "    Nome : " +i->get_nome() + "  Acronimo : " + i->get_acronimo() + "  Data : " + i->get_data());
    }
    comuni.clear();
}

void MainWindow::on_sezione_f_articoli_influenzati_clicked()
{
    std::list<Articolo*> influenzati;
    ui->PAG_F_LISTA->clear();
    gestore.get_influenzati_articolo(ui->Sezione_F_ID_articolo->value(),influenzati);

    for(auto& i : influenzati){
         ui->PAG_F_LISTA->addItem("ID ARTICOLO :  " + QString::number(i->get_identificativo()) + "  TITOLO :  " + i->get_titolo() + "  PAGINE : " + QString::number(i->get_num_pagine()) + "  PREZZO : " + QString::number(i->get_prezzo()) + "  ID CONFERENZA/RIVISTA ASSOCIATA :  " + QString::number(i->get_pubblicazione()->get_id()));
    }
}


void MainWindow::on_pulsante_visualizza_Autori_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_VISUALIZZA_AUTORI);
}

void MainWindow::on_pulsante_visualizza_Riviste_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_VISUALIZZA_RIVISTE);
}

void MainWindow::on_pulsante_visualizza_conferenze_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_VISUALIZZA_CONFERENZE);
}

void MainWindow::on_pulsante_visualizza_Articoli_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_VISUALIZZA_ARTICOLI);
}


/*SEZIONE F METODO 4 : AGGIUNGERE GLI INPUT DA FILE DI TESTO

L'ID RELATIVO AD AUTORI,CONFERENZE,RIVISTE ED ARTICOLI VERRA' SETTATO IN AUTOMATICO
PER SEMPLIFICARE L'INSERIMENTO ALL'UTENTE

PER QUANTO RIGUARDA LA MODALITA' DI INSERIMENTO,
IN GENERALE BISOGNA INSERIRE OGNI CAMPO RICHIESTO E QUANDO SI FINISCE DI INSERIRLO DIGITARE '|'.

SE CI SONO CAMPI COME LE KEYWORD CHE POSSONO ESSERE PIU' DI UNA (LISTE)
BISOGNA SEPARARE I DIVERSI OGGETTI (KEYWORD/AFFERENZE ... ECC) UNO DALL'ALTRO CON ','

NEL DETTAGLIO LE MODALITA' DI INSERIMENTO SONO SPIEGATE
DENTRO I FILE DI TESTO SPECIFICI PER OGNI SEZIONE (PRESENTI NELLA CARTELLA) CON DEI RELATIVI ESEMPI

L'INPUT DA FILE DI TESTO E' GESTITO IN MODO CHE SE SI RISPETTANO  I CRITERI DI INSERIMENTO
SI POSSONO INSERIRE VOLENDO ANCHE IN MODO "ALTERNATO" INPUT DA INTERFACCIA E DA FILE DI TESTO
SENZA ALCUN PROBLEMA

*/


/* IN GENERALE L'INPUT DA CODICE VIENE PRESO IN UN LOOP WHILE IN CUI SI ANALIZZA IL TESTO CHAR
   PER CHAR , OGNI VOLTA CHE SI INCONTRA UNA '|' SI INCREMENTA UN CONTATORE PER FAR CAPIRE CHE
   SI E' PASSATI AD INSERIRE IL PROSSIMO CAMPO.

   NEL CASO DI LISTE DI PIU' ELEMENTI OGNI VOLTA CHE SI TROVA UNA ',' SI SALVA
   QUELL'ELEMENTO E SI PROCEDE CON PRENDERE IL PROSSIMO FINCHE' NON VIENE TERMINATO L'INSERIMENTO
   CON IL CARATTERE '|'
*/
void MainWindow::on_pulsante_aggiungi_autori_file_clicked()
{
    QString testo_file = readFile("autori.txt");

        int i = 0, cont = 0, id;
        QString nome, cognome, visualizza_afferenze, parola;
        std::list<QString> aff;

        while(i != testo_file.size()){

            if(testo_file[i] == '|'){
                cont++;
            }
            if(testo_file[i]!='|' && cont == 0){
                nome.push_back(testo_file[i]);
            }

            if(testo_file[i]!='|' && cont == 1){
                cognome.push_back(testo_file[i]);
            }

            if(testo_file[i]!=',' && cont == 2 && !parola.isEmpty()){
                parola.push_back(testo_file[i]);
            }
            if(parola.isEmpty() && testo_file[i]!=' ' && testo_file[i]!='|' && cont == 2){
                parola.push_back(testo_file[i]);
            }
            if(testo_file[i] == ',' && !parola.isEmpty() && cont == 2){
                aff.push_back(parola.simplified());
                visualizza_afferenze += parola.simplified();
                visualizza_afferenze += ", ";
                parola.clear();
            }


            if(cont == 3){
                if(nome.simplified().isEmpty() || cognome.simplified().isEmpty()){
                    QMessageBox mess(QMessageBox::Critical, "Errore", "I campi nome e cognome non possono essere vuoti.", QMessageBox::Ok,this);
                    mess.exec();
                    return;
                }
                aff.push_back(parola.simplified());
                visualizza_afferenze += parola.simplified();
                id = gestore.get_first_free_id_autore();
                gestore.aggiungi_autore(nome.simplified(),cognome.simplified(),id,aff);
                ui->PAG_VISUALIZZA_AUTORI_LISTA->addItem("ID : " + QString::number(id) + "    NOME : "+ nome.simplified() + "    COGNOME : " + cognome.simplified() + "    AFFERENZE : " + visualizza_afferenze.simplified());
                ui->articolo_lista_add_autori->addItem(QString::number(id));
                id++;
                cont = 0;
                nome.clear();
                cognome.clear();
                aff.clear();
                parola.clear();
                visualizza_afferenze.clear();
            }
            i++;
        }

}

void MainWindow::on_pulsante_aggiungi_conferenze_file_clicked()
{
   QString testo_file = readFile("conferenze.txt");

       int i = 0, cont = 0, id;
       QString nome, acronimo, visualizza_orgnizzatori, org, luogo, partecipanti,data;
       std::list<QString> organizzatori;

       while(i!=testo_file.size()){
           if(testo_file[i] == '|'){
               cont++;
           }
           if(testo_file[i]!='|' && cont == 0){
               nome.push_back(testo_file[i]);
           }
           if(testo_file[i]!='|' && cont == 1){
               acronimo.push_back(testo_file[i]);
           }
           if(testo_file[i]!='|' && cont == 2){
               data.push_back(testo_file[i]);
           }
           if(testo_file[i]!='|' && cont == 3){
               luogo.push_back(testo_file[i]);
           }
           if(testo_file[i].isNumber() && cont == 4){
               partecipanti.push_back(testo_file[i]);
           }

           if(testo_file[i] != ',' && testo_file[i]!='|' && cont == 5){
               org.push_back(testo_file[i]);
           }
           if(testo_file[i] == ',' && !org.isEmpty() && cont == 5){
               organizzatori.push_back(org.simplified());
               visualizza_orgnizzatori += org.simplified();
               visualizza_orgnizzatori += ", ";
               org.clear();
           }

           if(cont == 6){
               organizzatori.push_back(org.simplified());
               visualizza_orgnizzatori += org.simplified();
               id = gestore.get_first_free_id_pubblicazione();

               if(nome.simplified().isEmpty() || data.simplified().isEmpty()){
                   QMessageBox errore(QMessageBox::Critical, "Errore", "I campi nome e data non possono essere vuoti.", QMessageBox::Ok,this);
                   errore.exec();
                   return;
               }

               if(!gestore.is_pubblicazione_unique(data.simplified(),nome.simplified(),true)){
                   QMessageBox mess_err(QMessageBox::Critical, "Errore", "Nome e data già occupate da un altra confereza (Non possono esistere conferenze con stesso nome e data).", QMessageBox::Ok,this);
                   mess_err.exec();
                   return;
               }

               gestore.aggiungi_conferenza(id,nome.simplified(),acronimo.simplified(),data.simplified(),luogo.simplified(),partecipanti.toInt(),organizzatori);
               ui->PAG_VISUALIZZA_CONFERENZE_LISTA->addItem("ID : " +  QString::number(id)    + "    NOME : " + nome.simplified() + "    ACRONIMO : " + acronimo.simplified() + "    LUOGO : " + luogo.simplified() + "    DATA : " + data + "    PARTECIPANTI : " + QString::number(partecipanti.toInt())  + "    ORGANIZZATORI : " + visualizza_orgnizzatori);
               ui->articolo_lista_id_pubb->addItem(QString::number(id));
               cont = 0;
               nome.clear();
               acronimo.clear();
               visualizza_orgnizzatori.clear();
               org.clear();
               luogo.clear();
               partecipanti.clear();
               data.clear();
               organizzatori.clear();
               }
           i++;
           }
}

void MainWindow::on_pulsante_aggiungi_riviste_file_clicked()
{
    QString testo_file =readFile("riviste.txt");

    int i = 0, cont = 0, id;
    QString nome, acronimo, data, editore, volume;

    while(i!=testo_file.size()){
        if(testo_file[i] == '|'){
            cont++;
        }
        if(testo_file[i]!='|' && cont == 0){
            nome.push_back(testo_file[i]);
        }
        if(testo_file[i]!='|' && cont == 1){
            acronimo.push_back(testo_file[i]);
        }
        if(testo_file[i]!='|' && cont == 2){
            data.push_back(testo_file[i]);
        }
        if(testo_file[i]!='|' && cont == 3){
            editore.push_back(testo_file[i]);
        }
        if(testo_file[i].isNumber() && cont == 4){
            volume.push_back(testo_file[i]);
        }

        if(cont == 5){

            id = gestore.get_first_free_id_pubblicazione();

            if(nome.simplified().isEmpty() || data.simplified().isEmpty()){
                QMessageBox errore(QMessageBox::Critical, "Errore", "I campi nome e data non possono essere vuoti.", QMessageBox::Ok,this);
                errore.exec();
                return;
            }

            if(!gestore.is_pubblicazione_unique(data.simplified(),nome.simplified(),false)){
                QMessageBox mess_err(QMessageBox::Critical, "Errore", "Nome e data già occupate da un altra rivista (Non possono esistere riviste con stesso nome e data).", QMessageBox::Ok,this);
                mess_err.exec();
                return;
            }
            gestore.aggiungi_rivista(id,nome.simplified(),acronimo.simplified(),data.simplified(),editore.simplified(),volume.toInt());
            ui->PAG_VISUALIZZA_RIVISTE_LISTA->addItem("ID : " + QString::number(id)   + "    NOME : " + nome.simplified() + "    ACRONIMO : " + acronimo.simplified() + "    EDITORE : " + editore.simplified() + "    DATA : " + data + "    VOLUME : " + QString::number(volume.toInt()));
            ui->articolo_lista_id_pubb->addItem(QString::number(id));
            cont = 0;
            nome.clear();
            acronimo.clear();
            data.clear();
            editore.clear();
            volume.clear();
            }
        i++;
        }
}

void MainWindow::on_pulsante_aggiungi_articolo_file_clicked()
{
    QString testo_file =readFile("articoli.txt");

    QString titolo, num_pagine, id_pubblicazione,  prezzo, id_autore, keyword, id_correlato;
    int cont = 0, i = 0, id;

    QString visualizza_autori, visualizza_keyword,visualizza_correlati;
    std::list<int> articoli_correlati;
    std::list<Autore*> autori;
    std::list<QString> keys;

    while(i!=testo_file.size()){
        if(testo_file[i] == '|'){
            cont++;
        }
        if(testo_file[i]!='|' && cont == 0){
            titolo.push_back(testo_file[i]);
        }
        if(testo_file[i]!='|' && cont == 1){
            id_pubblicazione.push_back(testo_file[i]);
        }
        if(testo_file[i]!='|' && cont == 2){
            num_pagine.push_back(testo_file[i]);
        }
        if(testo_file[i]!='|' && cont == 3){
            prezzo.push_back(testo_file[i]);
        }
        if(testo_file[i] != '|' && testo_file[i]!=',' && cont == 4){
            id_autore.push_back(testo_file[i]);
        }
        if(testo_file[i] == ',' && !id_autore.isEmpty() && cont == 4){
            if(gestore.get_autore(id_autore.toInt())!=nullptr){
                autori.push_back(gestore.get_autore(id_autore.toInt()));
                visualizza_autori += id_autore.simplified();
                visualizza_autori += ", ";
            }
            id_autore.clear();
        }
        if(testo_file[i]!= ',' && testo_file[i]!='|' && cont == 5){
            keyword.push_back(testo_file[i]);
        }
        if(testo_file[i] == ',' && !keyword.isEmpty() && cont == 5){
            keys.push_back(keyword.simplified());
            visualizza_keyword += keyword.simplified();
            visualizza_keyword += ", ";
            keyword.clear();
        }

        if(testo_file[i] != ',' && testo_file[i]!='|' && cont == 6){
            id_correlato.push_back(testo_file[i]);
        }
        if(testo_file[i] == ',' && !id_correlato.isEmpty() && cont == 6){
            articoli_correlati.push_back(id_correlato.toInt());
            visualizza_correlati += id_correlato.simplified();
            visualizza_correlati += ", ";
            id_correlato.clear();
        }
        if(cont == 7){
            if(gestore.get_autore(id_autore.toInt())!=nullptr){
                    autori.push_back(gestore.get_autore(id_autore.toInt()));
                    visualizza_autori += id_autore.simplified();
            }

            keys.push_back(keyword.simplified());
            visualizza_keyword += keyword.simplified();

            articoli_correlati.push_back(id_correlato.toInt());
            visualizza_correlati += id_correlato.simplified();

            id = gestore.get_first_free_id_articolo();

            if(titolo.isEmpty() || autori.empty() || keys.empty()){
                QMessageBox mess(QMessageBox::Critical, "Errore", "Nome Articolo/Keyword/Autori non possono essere vuoti. (NB gli autori vengono presi solo se precedentemente creati!)", QMessageBox::Ok,this);
                mess.exec();
                return;
            }
            if(gestore.get_pubblicazione(id_pubblicazione.toInt()) == nullptr){
                QMessageBox mess_tre(QMessageBox::Critical, "Errore", "La conferenza/rivista in cui pubblicare l'articolo non esiste.", QMessageBox::Ok,this);
                mess_tre.exec();
                return;
            }

            gestore.aggiungi_articolo(id,num_pagine.toInt(),prezzo.toDouble(),titolo.simplified(),gestore.get_pubblicazione(id_pubblicazione.toInt()),articoli_correlati,autori,keys);
            ui->PAG_VISUALIZZA_ARTICOLI_LISTA->addItem("ID ARTICOLO : " + QString::number(id) + "    TITOLO : " + titolo.simplified() + "    PAGINE : " + QString::number(num_pagine.toInt()) + "    PREZZO : " + QString::number(prezzo.toDouble()) + "    ID CONFERENZA/RIVISTA ASSOCIATA : " + QString::number(id_pubblicazione.toInt()) + "    ID AUTORI :" + visualizza_autori +"    ID ARTICOLI CORRELATI : " + visualizza_correlati + "    KEYWORDS : " + visualizza_keyword);
            ui->articoli_lista_correlati->addItem(QString::number(id));
            cont = 0;
            id_pubblicazione.clear();
            titolo.clear();
            num_pagine.clear();
            prezzo.clear();
            id_autore.clear();
            keyword.clear();
            id_correlato.clear();
            visualizza_autori.clear();
            visualizza_keyword.clear();
            visualizza_correlati.clear();
            articoli_correlati.clear();
            autori.clear();
            keys.clear();
        }
        i++;
    }

}


//FUNZIONE CHE PERMETTE DI LEGGERE UN FILE DI TESTO PASSANDOGLI IL NOME
// E RITORNA UNA QSTRING CONTENENTE TUTTO CIO' CHE E' SCRITTO NEL FILE

QString MainWindow::readFile(QString filename)
{
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout<<"File open failed";
    }

    QTextStream in(&file);
    QString testo_file = in.readAll();
    return testo_file;
}

void MainWindow::on_articolo_add_autore_clicked()
{
    if(ui->articolo_lista_add_autori->selectedItems().size()!=0){
        id_autori.push_back(ui->articolo_lista_add_autori->currentItem()->text().toInt());
    }
}

void MainWindow::on_articoli_aggiungi_correlato_clicked()
{
    if(ui->articoli_lista_correlati->selectedItems().size()!=0){
        id_correlati.push_back(ui->articoli_lista_correlati->currentItem()->text().toInt());
    }
}

