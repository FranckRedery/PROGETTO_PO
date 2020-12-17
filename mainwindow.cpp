#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "autore.h"
#include "gestore.h"
#include <QMessageBox>
#include <iostream>
#include <QFile>
#include <QTextStream>

using namespace std;


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

    list<QString> aff;
    QString parola;
    QString visualizza_afferenze;

    // prendo ogni afferenza dalla stringa e le inserisco nella lista
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
    ui->PAG_VISUALIZZA_RIVISTE_LISTA->addItem("NOME : " + nome + "    ACRONIMO : " + acronimo + "    EDITORE : " + editore + "    DATA : " + data.toString(Qt::DateFormat::ISODate) + "    VOLUME : " + QString::number(volume));
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
    QString visualizza_organizzatori;

    // prendo ogni afferenza dalla stringa e le inserisco nella lista
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

    if(visualizza_organizzatori.size()>=2){
        int last_char = visualizza_organizzatori.size()-2;
        visualizza_organizzatori[last_char] = '.';
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
    ui->PAG_VISUALIZZA_CONFERENZE_LISTA->addItem("NOME : " + nome + "    ACRONIMO : " + acronimo + "    LUOGO : " + luogo + "    DATA : " + data.toString(Qt::DateFormat::ISODate) + "    PARTECIPANTI : " + QString::number(part) + "    ORGANIZZATORI : " + visualizza_organizzatori );
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
    QString visualizza_autori;

    list<Autore*> autori;
    QString id_autore;

    for(int i = 0 ; i!=stringa_di_autori.size();i++){
        if(stringa_di_autori[i] != ' '){
            id_autore.push_back(stringa_di_autori[i]);
            if(i+1 == stringa_di_autori.size() && gestore.get_autore(id_autore.toInt())!=nullptr){
                autori.push_back(gestore.get_autore(id_autore.toInt()));
                visualizza_autori += id_autore;
                visualizza_autori += ", ";
                id_autore.clear();
            }
        }

        if(stringa_di_autori[i] == ' ' && !id_autore.isEmpty()){
            if(gestore.get_autore(id_autore.toInt())!=nullptr){
                autori.push_back(gestore.get_autore(id_autore.toInt()));
                visualizza_autori += id_autore;
                visualizza_autori += ", ";
            }
            id_autore.clear();
        }
    }

    int last_char;
    if(visualizza_autori.size()>= 2){
        last_char = visualizza_autori.size() -2;
        visualizza_autori[last_char] = '.';
    }

    QString stringa_articoli = ui->plaintext_articoli_correlati_di_articolo->toPlainText();
    QString visualizza_correlati;
    list<int> articoli_correlati;
    QString art;

    for(int i = 0 ; i!=stringa_articoli.size();i++){
        if(stringa_articoli[i] != ' '){
            art.push_back(stringa_articoli[i]);
            if(i+1 == stringa_articoli.size()){
                articoli_correlati.push_back(art.toInt());
                visualizza_correlati += art;
                visualizza_correlati += ", ";
                art.clear();
            }
        }

        if(stringa_articoli[i] == ' ' && !art.isEmpty()){
            articoli_correlati.push_back(art.toInt());
            visualizza_correlati += art;
            visualizza_correlati += ", ";
            art.clear();
        }
    }

    if(visualizza_correlati.size()>=2){
        last_char = visualizza_correlati.size()-2;
        visualizza_correlati[last_char] = '.';
    }

    QString stringa_keyword = ui->plaintext_keyword_di_articolo->toPlainText();
    QString visualizza_keyword;
    list<QString> keyword;
    QString chiave;

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

    if(visualizza_keyword.size()>=2){
        last_char = visualizza_keyword.size()-2;
        visualizza_keyword[last_char] = '.';
    }

    if(titolo.isEmpty() || autori.empty() || keyword.empty() || articoli_correlati.empty()){
        QMessageBox mess(QMessageBox::Critical, "Errore", "Nome Articolo/Keyword/Autori/Articoli correlati non possono essere vuoti. (NB gli autori vengono presi solo se precedentemente creati!)", QMessageBox::Ok,this);
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
    ui->PAG_VISUALIZZA_ARTICOLI_LISTA->addItem("ID : " + QString::number(id) + "    TITOLO : " + titolo + "    PAGINE : " + QString::number(pagine) + "    PREZZO : " + QString::number(prezzo) + "    CONFERENZA/RIVISTA ASSOCIATA : " + nome_pubblicazione + "    ID AUTORI :" +visualizza_autori +"    ID ARTICOLI CORRELATI : " + visualizza_correlati + "    KEYWORDS : " +visualizza_keyword);
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

    if(ui->SEZIONE_B_pulsante_visualizz_articoli_di_conferenza->isChecked()){
        gestore.get_articoli_conferenza_or_rivista(ui->SEZIONE_B_nome_conferenza->text(),lista_articoli);
        for(auto& i : lista_articoli){
            if(i->get_pubblicazione()->is_conferenza() == false){
                QMessageBox mess(QMessageBox::Critical, "Errore", "Il nome che hai inserito corrisponde ad una RIVISTA.", QMessageBox::Ok,this);
                mess.exec();
                return;
            }
            ui->SEZIONE_B_visualizzazione_articoli->addItem("ID :  " + QString::number(i->get_identificativo()) + "  Titolo :  " + i->get_titolo() + "  Pagine : " + QString::number(i->get_num_pagine()) + "  Prezzo : " + QString::number(i->get_prezzo()) + "  Conferenza/Rivista associata :  " + i->get_pubblicazione()->get_nome());
        }
    }

    if(ui->SEZIONE_B_pulsante_visualizz_articoli_di_rivista->isChecked()){
        gestore.get_articoli_conferenza_or_rivista(ui->SEZIONE_B_nome_rivista->text(),lista_articoli);
        for(auto& i : lista_articoli){
            if(i->get_pubblicazione()->is_conferenza() == true){
                QMessageBox mess(QMessageBox::Critical, "Errore", "Il nome che hai inserito corrisponde ad una CONFERENZA.", QMessageBox::Ok,this);
                mess.exec();
                return;
            }
            ui->SEZIONE_B_visualizzazione_articoli->addItem("ID :  " + QString::number(i->get_identificativo()) + "  Titolo :  " + i->get_titolo() + "  Pagine : " + QString::number(i->get_num_pagine()) + "  Prezzo : " + QString::number(i->get_prezzo()) + "  Conferenza/Rivista associata :  " + i->get_pubblicazione()->get_nome());
        }
    }

    lista_articoli.clear();
}






void MainWindow::on_SEZIONE_C_PULSANTE_CONFERMA_clicked()
{
    ui->SEZIONE_C_LISTWIDGET->clear();
    list<Articolo*> lista_articoli;
    list<QString> keyword_max;

    if(ui->SEZIONE_C_ARTICOLI_MIN->isChecked()){

        gestore.get_articoli_autore_prezzo_max_or_min(ui->SEZIONE_C_ID_AUTORE->value(),lista_articoli,1);
        for(auto& i : lista_articoli){
            ui->SEZIONE_C_LISTWIDGET->addItem("ID :  " + QString::number(i->get_identificativo()) + "  Titolo :  " + i->get_titolo() + "  Pagine : " + QString::number(i->get_num_pagine()) + "  Prezzo : " + QString::number(i->get_prezzo()) + "  Conferenza/Rivista associata :  " + i->get_pubblicazione()->get_nome());
        }
    }
    if(ui->SEZIONE_C_ARTICOLI_MAX->isChecked()){

        gestore.get_articoli_autore_prezzo_max_or_min(ui->SEZIONE_C_ID_AUTORE->value(),lista_articoli,2);
        for(auto& i : lista_articoli){
            ui->SEZIONE_C_LISTWIDGET->addItem("ID :  " + QString::number(i->get_identificativo()) + "  Titolo :  " + i->get_titolo() + "  Pagine : " + QString::number(i->get_num_pagine()) + "  Prezzo : " + QString::number(i->get_prezzo()) + "  Conferenza/Rivista associata :  " + i->get_pubblicazione()->get_nome());
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
    list<Articolo*> lista_articoli;

    if(ui->PAG_D_RADIO_VISUALIZZA_AUTORE->isChecked()){
        gestore.articoli_autore_sorted(ui->PAG_D_ID_AUTORE->value(),lista_articoli);
        for(auto& i : lista_articoli){
            ui->PAG_D_LISTA->addItem("ID :  " + QString::number(i->get_identificativo()) + "  Titolo :  " + i->get_titolo() + "  Pagine : " + QString::number(i->get_num_pagine()) + "  Prezzo : " + QString::number(i->get_prezzo()) + "  Conferenza/Rivista associata :  " + i->get_pubblicazione()->get_nome());
        }
    }

    if(ui->PAG_D_RADIO_VISUALIZZA_KEYWORD->isChecked()){
        gestore.articoli_keyword_sorted(ui->PAG_D_KEYWORD->text(),lista_articoli);
        for(auto& i : lista_articoli){
            ui->PAG_D_LISTA->addItem("ID :  " + QString::number(i->get_identificativo()) + "  Titolo :  " + i->get_titolo() + "  Pagine : " + QString::number(i->get_num_pagine()) + "  Prezzo : " + QString::number(i->get_prezzo()) + "  Conferenza/Rivista associata :  " + i->get_pubblicazione()->get_nome());
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

void MainWindow::on_PAG_E_pulsante_key_clicked()
{
    ui->PAG_E_LISTA->clear();
    list<QString> chiavi_diffuse;

    gestore.get_5_most_common_key(chiavi_diffuse);

    for(auto& i : chiavi_diffuse){
        ui->PAG_E_LISTA->addItem(i);
    }
    chiavi_diffuse.clear();
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PAG_SEZIONE_F);
}

void MainWindow::on_PAG_F_CERCA_CONFERENZE_COMUN_clicked()
{
    list<Pubblicazione*> comuni;
    ui->PAG_F_LISTA->clear();
    gestore.get_conferenze_simili(ui->PAGINA_F_NOME_CONFERENZA->text(),comuni);
    for(auto& i : comuni){
        ui->PAG_F_LISTA->addItem("Nome : " +i->get_nome() + "  Acronimo : " + i->get_acronimo() + "  Data : " + i->get_data());
    }
    comuni.clear();
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
L'ID DA FILE DI TESTO LO SETTO IN AUTOMATICO PER SEMPLIFICARE,
DOVE è RICHIESTO. PER QUANTO RIGUARDA LA MODALITà DI INSERIMENTO,
IN GENERALE BISOGNA INSERIRE OGNI CAMPO E POI QUANDO SI FINISCE DI
INSERIRLO SCRIVERE '.' SE CI SONO CAMPI COME LE KEYWORD CHE POSSONO
ESSERE DIVERSE BISOGNA SEPARARLE UNA DALL'ALTRA CON ','
IN PARTICOLARE LE MODALITà DI INSERIMENTO SONO SPIEGATE DENTRO I FILE
DI TESTO SPECIFICI PER ESSERE PIù CHIARI

NB: NEL CASO SI VOLESSERO INSERIRE CONTEMPORANEAMENTE FILE DALL'INTERFACCIA E DA TESTO,
SE VENGONO INSERITI PRECEDENTEMENTE (DA INTERFACCIA) ID DI AUTORI/ARTICOLI IN MODO NON UNIFORME ES: 1 , 5 , 4 , 3
I SETTAGGI AUTOMATICI PER AUGGIUNGERE GLI ID (DA FILE DI TESTO) HA QUALCHE PROBLEMA QUINDI BISOGNA INSERIRLI
IN MODO ORDINATO O IN MODO SEMPRE CRESCENTE GRAZIE
                                                                */
void MainWindow::on_pulsante_aggiungi_autori_file_clicked()
{
    QString testo_file = readFile("autori.txt");

        int i = 0, cont = 0, id;
        QString nome, cognome, visualizza_afferenze, parola;
        list<QString> aff;

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
                aff.push_back(parola.simplified());
                visualizza_afferenze += parola.simplified();
                id = gestore.get_first_free_id_autore();
                gestore.aggiungi_autore(nome.simplified(),cognome.simplified(),id,aff);
                ui->PAG_VISUALIZZA_AUTORI_LISTA->addItem("ID : " + QString::number(id) + "    NOME : "+ nome.simplified() + "    COGNOME : " + cognome.simplified() + "    AFFERENZE : " + visualizza_afferenze.simplified());

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

       int i = 0, cont = 0;
       QString nome, acronimo, visualizza_orgnizzatori, org, luogo, partecipanti,data;
       list<QString> organizzatori;

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



               if(gestore.Is_Nome_pubblicazione_alreadytaken(nome)){
                   QMessageBox mess_due(QMessageBox::Critical, "Errore", "Nome inserito già occupato da un altra rivista/confereza (i nomi devono essere unici).", QMessageBox::Ok,this);
                   mess_due.exec();
                   return;
                   }

               gestore.aggiungi_conferenza(nome.simplified(),acronimo.simplified(),data.simplified(),luogo.simplified(),partecipanti.toInt(),organizzatori);
               ui->PAG_VISUALIZZA_CONFERENZE_LISTA->addItem("NOME : " + nome.simplified() + "    ACRONIMO : " + acronimo.simplified() + "    LUOGO : " + luogo.simplified() + "    DATA : " + data + "    PARTECIPANTI : " + QString::number(partecipanti.toInt())  + "    ORGANIZZATORI : " + visualizza_orgnizzatori);

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

    int i = 0, cont = 0;
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


            if(gestore.Is_Nome_pubblicazione_alreadytaken(nome)){
                QMessageBox mess_due(QMessageBox::Critical, "Errore", "Nome inserito già occupato da un altra rivista/confereza (i nomi devono essere unici).", QMessageBox::Ok,this);
                mess_due.exec();
                return;
                }

            gestore.aggiungi_rivista(nome.simplified(),acronimo.simplified(),data.simplified(),editore.simplified(),volume.toInt());
            ui->PAG_VISUALIZZA_RIVISTE_LISTA->addItem("NOME : " + nome.simplified() + "    ACRONIMO : " + acronimo.simplified() + "    EDITORE : " + editore.simplified() + "    DATA : " + data + "    VOLUME : " + QString::number(volume.toInt()));

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

    QString titolo, nome_pubblicazione, num_pagine, prezzo, id_autore, keyword, id_correlato;
    int cont = 0, i = 0, id;

    QString visualizza_autori, visualizza_keyword,visualizza_correlati;
    list<int> articoli_correlati;
    list<Autore*> autori;
    list<QString> keys;

    while(i!=testo_file.size()){
        if(testo_file[i] == '|'){
            cont++;
        }
        if(testo_file[i]!='|' && cont == 0){
            titolo.push_back(testo_file[i]);
        }
        if(testo_file[i]!='|' && cont == 1){
            nome_pubblicazione.push_back(testo_file[i]);
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
            autori.push_back(gestore.get_autore(id_autore.toInt()));
            visualizza_autori += id_autore.simplified();
            visualizza_autori += ", ";
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

            autori.push_back(gestore.get_autore(id_autore.toInt()));
            visualizza_autori += id_autore.simplified();

            keys.push_back(keyword.simplified());
            visualizza_keyword += keyword.simplified();

            articoli_correlati.push_back(id_correlato.toInt());
            visualizza_correlati += id_correlato.simplified();

            id = gestore.get_first_free_id_articolo();

            if(titolo.isEmpty() || autori.empty() || keys.empty() || articoli_correlati.empty()){
                QMessageBox mess(QMessageBox::Critical, "Errore", "Nome Articolo/Keyword/Autori/Articoli correlati non possono essere vuoti. (NB gli autori vengono presi solo se precedentemente creati!)", QMessageBox::Ok,this);
                mess.exec();
                return;
            }
            if(gestore.get_pubblicazione(nome_pubblicazione.simplified()) == nullptr){
                QMessageBox mess_tre(QMessageBox::Critical, "Errore", "La conferenza/rivista in cui pubblicare l'articolo non esiste.", QMessageBox::Ok,this);
                mess_tre.exec();
                return;
            }

            gestore.aggiungi_articolo(id,num_pagine.toInt(),prezzo.toDouble(),titolo.simplified(),gestore.get_pubblicazione(nome_pubblicazione.simplified()),articoli_correlati,autori,keys);
            ui->PAG_VISUALIZZA_ARTICOLI_LISTA->addItem("ID : " + QString::number(id) + "    TITOLO : " + titolo.simplified() + "    PAGINE : " + QString::number(num_pagine.toInt()) + "    PREZZO : " + QString::number(prezzo.toDouble()) + "    CONFERENZA/RIVISTA ASSOCIATA : " + nome_pubblicazione.simplified() + "    ID AUTORI :" + visualizza_autori +"    ID ARTICOLI CORRELATI : " + visualizza_correlati + "    KEYWORDS : " + visualizza_keyword);

            cont = 0;
            titolo.clear();
            nome_pubblicazione.clear();
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




QString MainWindow::readFile(QString filename)
{
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        cout<<"File open failed";
    }

    QTextStream in(&file);
    QString testo_file = in.readAll();
    return testo_file;
}
