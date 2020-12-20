/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *pagina_principale;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QPushButton *SEZIONE_B;
    QPushButton *pulsante_visualizza_conferenze;
    QPushButton *pulsante_pag_aggiungiArticolo;
    QPushButton *pulsante_visualizza_Riviste;
    QPushButton *go_pag_conferenze;
    QPushButton *pushButton_3;
    QPushButton *SEZIONE_C;
    QPushButton *pulsante_visualizza_Autori;
    QPushButton *pulsante_sezione_D;
    QPushButton *go_pag_riviste;
    QPushButton *go_pag_autori;
    QPushButton *pushButton_2;
    QPushButton *pulsante_visualizza_Articoli;
    QPushButton *pulsante_aggiungi_autori_file;
    QPushButton *pulsante_aggiungi_riviste_file;
    QPushButton *pulsante_aggiungi_conferenze_file;
    QPushButton *pulsante_aggiungi_articolo_file;
    QWidget *pagina_autori;
    QPushButton *aggiungi_autore;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_cognome;
    QLineEdit *linea_cognome;
    QLabel *label_id_autore;
    QLineEdit *linea_nome;
    QLabel *label_nome;
    QSpinBox *id_autore;
    QLabel *label_afferenze;
    QPlainTextEdit *afferenze_plaintext;
    QPushButton *pulsante_torna_menu;
    QWidget *pagina_riviste;
    QPushButton *pulsante_aggiungi_rivista;
    QPushButton *pulsante_tornaalmenu;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_18;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QLabel *editore_rivista;
    QLabel *label_16;
    QLabel *acronimo_rivista;
    QLabel *volume_rivista;
    QLabel *nome_rivista;
    QGridLayout *gridLayout_4;
    QLineEdit *inserisci_acronimo;
    QLineEdit *inserisci_nome;
    QSpinBox *inserisci_volume;
    QLineEdit *inserisci_editore;
    QSpinBox *id_rivista;
    QCalendarWidget *calendario_rivista;
    QWidget *pagina_conferenze;
    QPushButton *vai_al_menu_principale;
    QPushButton *pulsante_aggiungi_conferenza;
    QWidget *layoutWidget3;
    QGridLayout *gridLayout_19;
    QCalendarWidget *calendario_conferenze;
    QGridLayout *gridLayout_6;
    QSpinBox *id_conferenza;
    QLineEdit *linea_luogo_conferenza;
    QLabel *label_luogo_conf;
    QPlainTextEdit *organizzatori_plaintext;
    QLineEdit *linea_nome_conferenza;
    QSpinBox *num_partecipanti_conferenza;
    QLineEdit *linea_acronimo_conferenza;
    QLabel *label_organizzatori;
    QLabel *label_part_conf;
    QLabel *label_acronimo_conf;
    QLabel *label_nome_conf;
    QLabel *label_17;
    QWidget *pagina_articoli;
    QPushButton *pulsante_torna_al_menu;
    QPushButton *pushButton;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_7;
    QListWidget *articolo_lista_add_autori;
    QSpinBox *numpagine_articolo_linedit;
    QPlainTextEdit *plaintext_keyword_di_articolo;
    QLabel *label_8;
    QListWidget *articolo_lista_id_pubb;
    QLabel *label_2;
    QLabel *label_7;
    QDoubleSpinBox *prezzoarticolo_linedit;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_6;
    QLineEdit *titolo_articolo_linedit;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *identificativo_articolo_linedit;
    QListWidget *articoli_lista_correlati;
    QPushButton *articolo_add_autore;
    QPushButton *articoli_aggiungi_correlato;
    QWidget *PAG_SEZIONE_B;
    QPushButton *sezioneB_to_menu;
    QPushButton *SEZIONEB_PULSANTE_VISUALIZZA;
    QListWidget *SEZIONE_B_visualizzazione_articoli;
    QWidget *layoutWidget5;
    QGridLayout *gridLayout_11;
    QRadioButton *SezioneB_scelta_visualizza_articoli_per_autore;
    QRadioButton *SEZIONE_B_pulsante_visualizz_articoli_di_conferenza;
    QRadioButton *SEZIONE_B_pulsante_visualizz_articoli_di_rivista;
    QGridLayout *gridLayout_9;
    QLabel *label_9;
    QSpinBox *sezioneB_id_autore;
    QGridLayout *gridLayout_8;
    QLabel *label_10;
    QSpinBox *SEZIONE_B_ID_CONFERENZA;
    QGridLayout *gridLayout_10;
    QLabel *label_11;
    QSpinBox *SEZIONE_B_ID_RIVISTA;
    QWidget *PAG_SEZIONE_C;
    QPushButton *SEZIONE_C_TORNAMENU;
    QListWidget *SEZIONE_C_LISTWIDGET;
    QPushButton *SEZIONE_C_PULSANTE_CONFERMA;
    QWidget *layoutWidget6;
    QGridLayout *gridLayout_13;
    QRadioButton *SEZIONE_C_ARTICOLI_MAX;
    QGridLayout *gridLayout_12;
    QLabel *label_12;
    QSpinBox *SEZIONE_C_ID_AUTORE;
    QRadioButton *SEZIONE_C_ARTICOLI_MIN;
    QRadioButton *SEZIONE_C_KEYWORD_MAX;
    QWidget *PAG_SEZIONE_D;
    QPushButton *PAG_D_MENU;
    QListWidget *PAG_D_LISTA;
    QPushButton *PAG_D_PULSANTE_CONFERMA;
    QWidget *layoutWidget7;
    QGridLayout *gridLayout_16;
    QRadioButton *PAG_D_RADIO_VISUALIZZA_KEYWORD;
    QRadioButton *PAG_D_RADIO_VISUALIZZA_AUTORE;
    QGridLayout *gridLayout_15;
    QLabel *label_13;
    QSpinBox *PAG_D_ID_AUTORE;
    QGridLayout *gridLayout_14;
    QLabel *label_14;
    QLineEdit *PAG_D_KEYWORD;
    QWidget *PAG_SEZIONE_E;
    QPushButton *PAG_E_BOTTONE_MENU;
    QPushButton *PAG_E_pulsante_key;
    QListWidget *PAG_E_LISTA;
    QWidget *PAG_SEZIONE_F;
    QPushButton *PAG_F_TORNA_MENU;
    QPushButton *PAG_F_CERCA_CONFERENZE_COMUN;
    QListWidget *PAG_F_LISTA;
    QWidget *layoutWidget8;
    QGridLayout *gridLayout_17;
    QLabel *label_15;
    QSpinBox *PAGINA_F_ID_CONFERENZA;
    QWidget *PAG_VISUALIZZA_AUTORI;
    QPushButton *PAG_VISUALIZZA_AUTORI_PULSANTE_MENU;
    QListWidget *PAG_VISUALIZZA_AUTORI_LISTA;
    QWidget *PAG_VISUALIZZA_RIVISTE;
    QListWidget *PAG_VISUALIZZA_RIVISTE_LISTA;
    QPushButton *PAG_VISUALIZZA_RIVISTE_PULSANTE_MENU_;
    QWidget *PAG_VISUALIZZA_CONFERENZE;
    QPushButton *PAG_VISUALIZZA_CONFERENZE_PULSANTE_MENU;
    QListWidget *PAG_VISUALIZZA_CONFERENZE_LISTA;
    QWidget *PAG_VISUALIZZA_ARTICOLI;
    QListWidget *PAG_VISUALIZZA_ARTICOLI_LISTA;
    QPushButton *PAG_VISUALIZZA_ARTICOLI_PULSANTE_MENU;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 791, 571));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        pagina_principale = new QWidget();
        pagina_principale->setObjectName(QString::fromUtf8("pagina_principale"));
        layoutWidget = new QWidget(pagina_principale);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 10, 711, 551));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        SEZIONE_B = new QPushButton(layoutWidget);
        SEZIONE_B->setObjectName(QString::fromUtf8("SEZIONE_B"));
        SEZIONE_B->setStyleSheet(QString::fromUtf8("background-color: rgb(217,188,0);"));

        gridLayout_2->addWidget(SEZIONE_B, 2, 0, 1, 1);

        pulsante_visualizza_conferenze = new QPushButton(layoutWidget);
        pulsante_visualizza_conferenze->setObjectName(QString::fromUtf8("pulsante_visualizza_conferenze"));
        pulsante_visualizza_conferenze->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));

        gridLayout_2->addWidget(pulsante_visualizza_conferenze, 1, 2, 1, 1);

        pulsante_pag_aggiungiArticolo = new QPushButton(layoutWidget);
        pulsante_pag_aggiungiArticolo->setObjectName(QString::fromUtf8("pulsante_pag_aggiungiArticolo"));
        pulsante_pag_aggiungiArticolo->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));

        gridLayout_2->addWidget(pulsante_pag_aggiungiArticolo, 0, 3, 1, 1);

        pulsante_visualizza_Riviste = new QPushButton(layoutWidget);
        pulsante_visualizza_Riviste->setObjectName(QString::fromUtf8("pulsante_visualizza_Riviste"));
        pulsante_visualizza_Riviste->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));

        gridLayout_2->addWidget(pulsante_visualizza_Riviste, 1, 1, 1, 1);

        go_pag_conferenze = new QPushButton(layoutWidget);
        go_pag_conferenze->setObjectName(QString::fromUtf8("go_pag_conferenze"));
        go_pag_conferenze->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));

        gridLayout_2->addWidget(go_pag_conferenze, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(217,188,0);"));

        gridLayout_2->addWidget(pushButton_3, 3, 0, 1, 1);

        SEZIONE_C = new QPushButton(layoutWidget);
        SEZIONE_C->setObjectName(QString::fromUtf8("SEZIONE_C"));
        SEZIONE_C->setStyleSheet(QString::fromUtf8("background-color: rgb(217,188,0);"));

        gridLayout_2->addWidget(SEZIONE_C, 2, 1, 1, 1);

        pulsante_visualizza_Autori = new QPushButton(layoutWidget);
        pulsante_visualizza_Autori->setObjectName(QString::fromUtf8("pulsante_visualizza_Autori"));
        pulsante_visualizza_Autori->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));

        gridLayout_2->addWidget(pulsante_visualizza_Autori, 1, 0, 1, 1);

        pulsante_sezione_D = new QPushButton(layoutWidget);
        pulsante_sezione_D->setObjectName(QString::fromUtf8("pulsante_sezione_D"));
        pulsante_sezione_D->setStyleSheet(QString::fromUtf8("background-color: rgb(217,188,0);"));

        gridLayout_2->addWidget(pulsante_sezione_D, 2, 2, 1, 1);

        go_pag_riviste = new QPushButton(layoutWidget);
        go_pag_riviste->setObjectName(QString::fromUtf8("go_pag_riviste"));
        go_pag_riviste->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));

        gridLayout_2->addWidget(go_pag_riviste, 0, 1, 1, 1);

        go_pag_autori = new QPushButton(layoutWidget);
        go_pag_autori->setObjectName(QString::fromUtf8("go_pag_autori"));
        go_pag_autori->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));

        gridLayout_2->addWidget(go_pag_autori, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(217,188,0);"));

        gridLayout_2->addWidget(pushButton_2, 2, 3, 1, 1);

        pulsante_visualizza_Articoli = new QPushButton(layoutWidget);
        pulsante_visualizza_Articoli->setObjectName(QString::fromUtf8("pulsante_visualizza_Articoli"));
        pulsante_visualizza_Articoli->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));

        gridLayout_2->addWidget(pulsante_visualizza_Articoli, 1, 3, 1, 1);

        pulsante_aggiungi_autori_file = new QPushButton(layoutWidget);
        pulsante_aggiungi_autori_file->setObjectName(QString::fromUtf8("pulsante_aggiungi_autori_file"));
        pulsante_aggiungi_autori_file->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 15, 15);"));

        gridLayout_2->addWidget(pulsante_aggiungi_autori_file, 4, 0, 1, 1);

        pulsante_aggiungi_riviste_file = new QPushButton(layoutWidget);
        pulsante_aggiungi_riviste_file->setObjectName(QString::fromUtf8("pulsante_aggiungi_riviste_file"));
        pulsante_aggiungi_riviste_file->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 15, 15);"));

        gridLayout_2->addWidget(pulsante_aggiungi_riviste_file, 4, 1, 1, 1);

        pulsante_aggiungi_conferenze_file = new QPushButton(layoutWidget);
        pulsante_aggiungi_conferenze_file->setObjectName(QString::fromUtf8("pulsante_aggiungi_conferenze_file"));
        pulsante_aggiungi_conferenze_file->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 15, 15);"));

        gridLayout_2->addWidget(pulsante_aggiungi_conferenze_file, 4, 2, 1, 1);

        pulsante_aggiungi_articolo_file = new QPushButton(layoutWidget);
        pulsante_aggiungi_articolo_file->setObjectName(QString::fromUtf8("pulsante_aggiungi_articolo_file"));
        pulsante_aggiungi_articolo_file->setStyleSheet(QString::fromUtf8("background-color: rgb(145, 15, 15);"));

        gridLayout_2->addWidget(pulsante_aggiungi_articolo_file, 4, 3, 1, 1);

        stackedWidget->addWidget(pagina_principale);
        pagina_autori = new QWidget();
        pagina_autori->setObjectName(QString::fromUtf8("pagina_autori"));
        aggiungi_autore = new QPushButton(pagina_autori);
        aggiungi_autore->setObjectName(QString::fromUtf8("aggiungi_autore"));
        aggiungi_autore->setGeometry(QRect(300, 420, 151, 51));
        aggiungi_autore->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        layoutWidget1 = new QWidget(pagina_autori);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(180, 110, 401, 241));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_cognome = new QLabel(layoutWidget1);
        label_cognome->setObjectName(QString::fromUtf8("label_cognome"));
        label_cognome->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_cognome, 1, 0, 1, 1);

        linea_cognome = new QLineEdit(layoutWidget1);
        linea_cognome->setObjectName(QString::fromUtf8("linea_cognome"));
        linea_cognome->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(linea_cognome, 1, 1, 1, 1);

        label_id_autore = new QLabel(layoutWidget1);
        label_id_autore->setObjectName(QString::fromUtf8("label_id_autore"));

        gridLayout->addWidget(label_id_autore, 2, 0, 1, 1);

        linea_nome = new QLineEdit(layoutWidget1);
        linea_nome->setObjectName(QString::fromUtf8("linea_nome"));
        linea_nome->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(linea_nome, 0, 1, 1, 1);

        label_nome = new QLabel(layoutWidget1);
        label_nome->setObjectName(QString::fromUtf8("label_nome"));
        label_nome->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(label_nome, 0, 0, 1, 1);

        id_autore = new QSpinBox(layoutWidget1);
        id_autore->setObjectName(QString::fromUtf8("id_autore"));
        id_autore->setMinimum(1);
        id_autore->setMaximum(999999999);

        gridLayout->addWidget(id_autore, 2, 1, 1, 1);

        label_afferenze = new QLabel(layoutWidget1);
        label_afferenze->setObjectName(QString::fromUtf8("label_afferenze"));

        gridLayout->addWidget(label_afferenze, 3, 0, 1, 1);

        afferenze_plaintext = new QPlainTextEdit(layoutWidget1);
        afferenze_plaintext->setObjectName(QString::fromUtf8("afferenze_plaintext"));

        gridLayout->addWidget(afferenze_plaintext, 3, 1, 1, 1);

        pulsante_torna_menu = new QPushButton(pagina_autori);
        pulsante_torna_menu->setObjectName(QString::fromUtf8("pulsante_torna_menu"));
        pulsante_torna_menu->setGeometry(QRect(300, 10, 151, 51));
        pulsante_torna_menu->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        stackedWidget->addWidget(pagina_autori);
        pagina_riviste = new QWidget();
        pagina_riviste->setObjectName(QString::fromUtf8("pagina_riviste"));
        pulsante_aggiungi_rivista = new QPushButton(pagina_riviste);
        pulsante_aggiungi_rivista->setObjectName(QString::fromUtf8("pulsante_aggiungi_rivista"));
        pulsante_aggiungi_rivista->setGeometry(QRect(300, 360, 151, 61));
        pulsante_aggiungi_rivista->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        pulsante_tornaalmenu = new QPushButton(pagina_riviste);
        pulsante_tornaalmenu->setObjectName(QString::fromUtf8("pulsante_tornaalmenu"));
        pulsante_tornaalmenu->setGeometry(QRect(300, 10, 151, 51));
        pulsante_tornaalmenu->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        layoutWidget2 = new QWidget(pagina_riviste);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(140, 140, 470, 181));
        gridLayout_18 = new QGridLayout(layoutWidget2);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        editore_rivista = new QLabel(layoutWidget2);
        editore_rivista->setObjectName(QString::fromUtf8("editore_rivista"));
        editore_rivista->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(editore_rivista, 4, 0, 1, 1);

        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_3->addWidget(label_16, 1, 0, 1, 1);

        acronimo_rivista = new QLabel(layoutWidget2);
        acronimo_rivista->setObjectName(QString::fromUtf8("acronimo_rivista"));
        acronimo_rivista->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(acronimo_rivista, 3, 0, 1, 1);

        volume_rivista = new QLabel(layoutWidget2);
        volume_rivista->setObjectName(QString::fromUtf8("volume_rivista"));
        volume_rivista->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(volume_rivista, 5, 0, 1, 1);

        nome_rivista = new QLabel(layoutWidget2);
        nome_rivista->setObjectName(QString::fromUtf8("nome_rivista"));
        nome_rivista->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(nome_rivista, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        inserisci_acronimo = new QLineEdit(layoutWidget2);
        inserisci_acronimo->setObjectName(QString::fromUtf8("inserisci_acronimo"));

        gridLayout_4->addWidget(inserisci_acronimo, 4, 0, 1, 1);

        inserisci_nome = new QLineEdit(layoutWidget2);
        inserisci_nome->setObjectName(QString::fromUtf8("inserisci_nome"));

        gridLayout_4->addWidget(inserisci_nome, 2, 0, 1, 1);

        inserisci_volume = new QSpinBox(layoutWidget2);
        inserisci_volume->setObjectName(QString::fromUtf8("inserisci_volume"));
        inserisci_volume->setMinimum(1);
        inserisci_volume->setMaximum(999999999);

        gridLayout_4->addWidget(inserisci_volume, 6, 0, 1, 1);

        inserisci_editore = new QLineEdit(layoutWidget2);
        inserisci_editore->setObjectName(QString::fromUtf8("inserisci_editore"));

        gridLayout_4->addWidget(inserisci_editore, 5, 0, 1, 1);

        id_rivista = new QSpinBox(layoutWidget2);
        id_rivista->setObjectName(QString::fromUtf8("id_rivista"));
        id_rivista->setMinimum(1);
        id_rivista->setMaximum(9999);

        gridLayout_4->addWidget(id_rivista, 3, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 1, 1, 1);


        gridLayout_18->addLayout(gridLayout_5, 0, 0, 1, 1);

        calendario_rivista = new QCalendarWidget(layoutWidget2);
        calendario_rivista->setObjectName(QString::fromUtf8("calendario_rivista"));
        calendario_rivista->setHorizontalHeaderFormat(QCalendarWidget::NoHorizontalHeader);
        calendario_rivista->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        gridLayout_18->addWidget(calendario_rivista, 0, 1, 1, 1);

        stackedWidget->addWidget(pagina_riviste);
        pagina_conferenze = new QWidget();
        pagina_conferenze->setObjectName(QString::fromUtf8("pagina_conferenze"));
        vai_al_menu_principale = new QPushButton(pagina_conferenze);
        vai_al_menu_principale->setObjectName(QString::fromUtf8("vai_al_menu_principale"));
        vai_al_menu_principale->setGeometry(QRect(300, 10, 151, 51));
        vai_al_menu_principale->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        pulsante_aggiungi_conferenza = new QPushButton(pagina_conferenze);
        pulsante_aggiungi_conferenza->setObjectName(QString::fromUtf8("pulsante_aggiungi_conferenza"));
        pulsante_aggiungi_conferenza->setGeometry(QRect(300, 480, 151, 61));
        pulsante_aggiungi_conferenza->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        layoutWidget3 = new QWidget(pagina_conferenze);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(170, 70, 401, 409));
        gridLayout_19 = new QGridLayout(layoutWidget3);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        calendario_conferenze = new QCalendarWidget(layoutWidget3);
        calendario_conferenze->setObjectName(QString::fromUtf8("calendario_conferenze"));
        calendario_conferenze->setHorizontalHeaderFormat(QCalendarWidget::NoHorizontalHeader);
        calendario_conferenze->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        gridLayout_19->addWidget(calendario_conferenze, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        id_conferenza = new QSpinBox(layoutWidget3);
        id_conferenza->setObjectName(QString::fromUtf8("id_conferenza"));
        id_conferenza->setMinimum(1);
        id_conferenza->setMaximum(9999);

        gridLayout_6->addWidget(id_conferenza, 2, 1, 1, 1);

        linea_luogo_conferenza = new QLineEdit(layoutWidget3);
        linea_luogo_conferenza->setObjectName(QString::fromUtf8("linea_luogo_conferenza"));

        gridLayout_6->addWidget(linea_luogo_conferenza, 4, 1, 1, 1);

        label_luogo_conf = new QLabel(layoutWidget3);
        label_luogo_conf->setObjectName(QString::fromUtf8("label_luogo_conf"));

        gridLayout_6->addWidget(label_luogo_conf, 4, 0, 1, 1);

        organizzatori_plaintext = new QPlainTextEdit(layoutWidget3);
        organizzatori_plaintext->setObjectName(QString::fromUtf8("organizzatori_plaintext"));

        gridLayout_6->addWidget(organizzatori_plaintext, 6, 1, 1, 1);

        linea_nome_conferenza = new QLineEdit(layoutWidget3);
        linea_nome_conferenza->setObjectName(QString::fromUtf8("linea_nome_conferenza"));

        gridLayout_6->addWidget(linea_nome_conferenza, 1, 1, 1, 1);

        num_partecipanti_conferenza = new QSpinBox(layoutWidget3);
        num_partecipanti_conferenza->setObjectName(QString::fromUtf8("num_partecipanti_conferenza"));
        num_partecipanti_conferenza->setMaximum(999999999);

        gridLayout_6->addWidget(num_partecipanti_conferenza, 5, 1, 1, 1);

        linea_acronimo_conferenza = new QLineEdit(layoutWidget3);
        linea_acronimo_conferenza->setObjectName(QString::fromUtf8("linea_acronimo_conferenza"));

        gridLayout_6->addWidget(linea_acronimo_conferenza, 3, 1, 1, 1);

        label_organizzatori = new QLabel(layoutWidget3);
        label_organizzatori->setObjectName(QString::fromUtf8("label_organizzatori"));

        gridLayout_6->addWidget(label_organizzatori, 6, 0, 1, 1);

        label_part_conf = new QLabel(layoutWidget3);
        label_part_conf->setObjectName(QString::fromUtf8("label_part_conf"));

        gridLayout_6->addWidget(label_part_conf, 5, 0, 1, 1);

        label_acronimo_conf = new QLabel(layoutWidget3);
        label_acronimo_conf->setObjectName(QString::fromUtf8("label_acronimo_conf"));

        gridLayout_6->addWidget(label_acronimo_conf, 3, 0, 1, 1);

        label_nome_conf = new QLabel(layoutWidget3);
        label_nome_conf->setObjectName(QString::fromUtf8("label_nome_conf"));

        gridLayout_6->addWidget(label_nome_conf, 1, 0, 1, 1);

        label_17 = new QLabel(layoutWidget3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_6->addWidget(label_17, 2, 0, 1, 1);


        gridLayout_19->addLayout(gridLayout_6, 1, 0, 1, 1);

        stackedWidget->addWidget(pagina_conferenze);
        pagina_articoli = new QWidget();
        pagina_articoli->setObjectName(QString::fromUtf8("pagina_articoli"));
        pulsante_torna_al_menu = new QPushButton(pagina_articoli);
        pulsante_torna_al_menu->setObjectName(QString::fromUtf8("pulsante_torna_al_menu"));
        pulsante_torna_al_menu->setGeometry(QRect(300, 10, 151, 51));
        pulsante_torna_al_menu->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        pushButton = new QPushButton(pagina_articoli);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 500, 151, 51));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        layoutWidget4 = new QWidget(pagina_articoli);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(130, 80, 461, 414));
        gridLayout_7 = new QGridLayout(layoutWidget4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        articolo_lista_add_autori = new QListWidget(layoutWidget4);
        articolo_lista_add_autori->setObjectName(QString::fromUtf8("articolo_lista_add_autori"));

        gridLayout_7->addWidget(articolo_lista_add_autori, 6, 1, 1, 1);

        numpagine_articolo_linedit = new QSpinBox(layoutWidget4);
        numpagine_articolo_linedit->setObjectName(QString::fromUtf8("numpagine_articolo_linedit"));
        numpagine_articolo_linedit->setMaximum(99999);

        gridLayout_7->addWidget(numpagine_articolo_linedit, 4, 1, 1, 1);

        plaintext_keyword_di_articolo = new QPlainTextEdit(layoutWidget4);
        plaintext_keyword_di_articolo->setObjectName(QString::fromUtf8("plaintext_keyword_di_articolo"));

        gridLayout_7->addWidget(plaintext_keyword_di_articolo, 7, 1, 1, 1);

        label_8 = new QLabel(layoutWidget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_7->addWidget(label_8, 8, 0, 1, 1);

        articolo_lista_id_pubb = new QListWidget(layoutWidget4);
        articolo_lista_id_pubb->setObjectName(QString::fromUtf8("articolo_lista_id_pubb"));

        gridLayout_7->addWidget(articolo_lista_id_pubb, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_7->addWidget(label_2, 2, 0, 1, 1);

        label_7 = new QLabel(layoutWidget4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_7->addWidget(label_7, 7, 0, 1, 1);

        prezzoarticolo_linedit = new QDoubleSpinBox(layoutWidget4);
        prezzoarticolo_linedit->setObjectName(QString::fromUtf8("prezzoarticolo_linedit"));
        prezzoarticolo_linedit->setMaximum(99999999.989999994635582);

        gridLayout_7->addWidget(prezzoarticolo_linedit, 5, 1, 1, 1);

        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_7->addWidget(label_5, 5, 0, 1, 1);

        label = new QLabel(layoutWidget4);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_7->addWidget(label, 0, 0, 1, 1);

        label_6 = new QLabel(layoutWidget4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_7->addWidget(label_6, 6, 0, 1, 1);

        titolo_articolo_linedit = new QLineEdit(layoutWidget4);
        titolo_articolo_linedit->setObjectName(QString::fromUtf8("titolo_articolo_linedit"));

        gridLayout_7->addWidget(titolo_articolo_linedit, 0, 1, 1, 1);

        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_7->addWidget(label_4, 4, 0, 1, 1);

        label_3 = new QLabel(layoutWidget4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_7->addWidget(label_3, 1, 0, 1, 1);

        identificativo_articolo_linedit = new QSpinBox(layoutWidget4);
        identificativo_articolo_linedit->setObjectName(QString::fromUtf8("identificativo_articolo_linedit"));
        identificativo_articolo_linedit->setMinimum(1);
        identificativo_articolo_linedit->setMaximum(999999999);

        gridLayout_7->addWidget(identificativo_articolo_linedit, 1, 1, 1, 1);

        articoli_lista_correlati = new QListWidget(layoutWidget4);
        articoli_lista_correlati->setObjectName(QString::fromUtf8("articoli_lista_correlati"));

        gridLayout_7->addWidget(articoli_lista_correlati, 8, 1, 1, 1);

        articolo_add_autore = new QPushButton(pagina_articoli);
        articolo_add_autore->setObjectName(QString::fromUtf8("articolo_add_autore"));
        articolo_add_autore->setGeometry(QRect(600, 280, 121, 41));
        articolo_add_autore->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        articoli_aggiungi_correlato = new QPushButton(pagina_articoli);
        articoli_aggiungi_correlato->setObjectName(QString::fromUtf8("articoli_aggiungi_correlato"));
        articoli_aggiungi_correlato->setGeometry(QRect(600, 430, 121, 41));
        articoli_aggiungi_correlato->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        stackedWidget->addWidget(pagina_articoli);
        PAG_SEZIONE_B = new QWidget();
        PAG_SEZIONE_B->setObjectName(QString::fromUtf8("PAG_SEZIONE_B"));
        sezioneB_to_menu = new QPushButton(PAG_SEZIONE_B);
        sezioneB_to_menu->setObjectName(QString::fromUtf8("sezioneB_to_menu"));
        sezioneB_to_menu->setGeometry(QRect(300, 10, 151, 51));
        sezioneB_to_menu->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        SEZIONEB_PULSANTE_VISUALIZZA = new QPushButton(PAG_SEZIONE_B);
        SEZIONEB_PULSANTE_VISUALIZZA->setObjectName(QString::fromUtf8("SEZIONEB_PULSANTE_VISUALIZZA"));
        SEZIONEB_PULSANTE_VISUALIZZA->setGeometry(QRect(300, 140, 151, 51));
        SEZIONEB_PULSANTE_VISUALIZZA->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        SEZIONE_B_visualizzazione_articoli = new QListWidget(PAG_SEZIONE_B);
        SEZIONE_B_visualizzazione_articoli->setObjectName(QString::fromUtf8("SEZIONE_B_visualizzazione_articoli"));
        SEZIONE_B_visualizzazione_articoli->setGeometry(QRect(10, 200, 771, 371));
        layoutWidget5 = new QWidget(PAG_SEZIONE_B);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 70, 771, 61));
        gridLayout_11 = new QGridLayout(layoutWidget5);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        SezioneB_scelta_visualizza_articoli_per_autore = new QRadioButton(layoutWidget5);
        SezioneB_scelta_visualizza_articoli_per_autore->setObjectName(QString::fromUtf8("SezioneB_scelta_visualizza_articoli_per_autore"));

        gridLayout_11->addWidget(SezioneB_scelta_visualizza_articoli_per_autore, 1, 0, 1, 1);

        SEZIONE_B_pulsante_visualizz_articoli_di_conferenza = new QRadioButton(layoutWidget5);
        SEZIONE_B_pulsante_visualizz_articoli_di_conferenza->setObjectName(QString::fromUtf8("SEZIONE_B_pulsante_visualizz_articoli_di_conferenza"));

        gridLayout_11->addWidget(SEZIONE_B_pulsante_visualizz_articoli_di_conferenza, 1, 1, 1, 1);

        SEZIONE_B_pulsante_visualizz_articoli_di_rivista = new QRadioButton(layoutWidget5);
        SEZIONE_B_pulsante_visualizz_articoli_di_rivista->setObjectName(QString::fromUtf8("SEZIONE_B_pulsante_visualizz_articoli_di_rivista"));

        gridLayout_11->addWidget(SEZIONE_B_pulsante_visualizz_articoli_di_rivista, 1, 2, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_9 = new QLabel(layoutWidget5);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_9->addWidget(label_9, 0, 0, 1, 1);

        sezioneB_id_autore = new QSpinBox(layoutWidget5);
        sezioneB_id_autore->setObjectName(QString::fromUtf8("sezioneB_id_autore"));
        sezioneB_id_autore->setMinimum(1);
        sezioneB_id_autore->setMaximum(999999999);

        gridLayout_9->addWidget(sezioneB_id_autore, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_9, 0, 0, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_10 = new QLabel(layoutWidget5);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_8->addWidget(label_10, 0, 0, 1, 1);

        SEZIONE_B_ID_CONFERENZA = new QSpinBox(layoutWidget5);
        SEZIONE_B_ID_CONFERENZA->setObjectName(QString::fromUtf8("SEZIONE_B_ID_CONFERENZA"));

        gridLayout_8->addWidget(SEZIONE_B_ID_CONFERENZA, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_8, 0, 1, 1, 1);

        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_11 = new QLabel(layoutWidget5);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_10->addWidget(label_11, 0, 0, 1, 1);

        SEZIONE_B_ID_RIVISTA = new QSpinBox(layoutWidget5);
        SEZIONE_B_ID_RIVISTA->setObjectName(QString::fromUtf8("SEZIONE_B_ID_RIVISTA"));

        gridLayout_10->addWidget(SEZIONE_B_ID_RIVISTA, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_10, 0, 2, 1, 1);

        stackedWidget->addWidget(PAG_SEZIONE_B);
        PAG_SEZIONE_C = new QWidget();
        PAG_SEZIONE_C->setObjectName(QString::fromUtf8("PAG_SEZIONE_C"));
        SEZIONE_C_TORNAMENU = new QPushButton(PAG_SEZIONE_C);
        SEZIONE_C_TORNAMENU->setObjectName(QString::fromUtf8("SEZIONE_C_TORNAMENU"));
        SEZIONE_C_TORNAMENU->setGeometry(QRect(300, 10, 151, 51));
        SEZIONE_C_TORNAMENU->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        SEZIONE_C_LISTWIDGET = new QListWidget(PAG_SEZIONE_C);
        SEZIONE_C_LISTWIDGET->setObjectName(QString::fromUtf8("SEZIONE_C_LISTWIDGET"));
        SEZIONE_C_LISTWIDGET->setGeometry(QRect(10, 190, 771, 371));
        SEZIONE_C_PULSANTE_CONFERMA = new QPushButton(PAG_SEZIONE_C);
        SEZIONE_C_PULSANTE_CONFERMA->setObjectName(QString::fromUtf8("SEZIONE_C_PULSANTE_CONFERMA"));
        SEZIONE_C_PULSANTE_CONFERMA->setGeometry(QRect(300, 130, 151, 51));
        SEZIONE_C_PULSANTE_CONFERMA->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        layoutWidget6 = new QWidget(PAG_SEZIONE_C);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 70, 771, 51));
        gridLayout_13 = new QGridLayout(layoutWidget6);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        SEZIONE_C_ARTICOLI_MAX = new QRadioButton(layoutWidget6);
        SEZIONE_C_ARTICOLI_MAX->setObjectName(QString::fromUtf8("SEZIONE_C_ARTICOLI_MAX"));

        gridLayout_13->addWidget(SEZIONE_C_ARTICOLI_MAX, 0, 2, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_12 = new QLabel(layoutWidget6);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_12->addWidget(label_12, 0, 0, 1, 1);

        SEZIONE_C_ID_AUTORE = new QSpinBox(layoutWidget6);
        SEZIONE_C_ID_AUTORE->setObjectName(QString::fromUtf8("SEZIONE_C_ID_AUTORE"));
        SEZIONE_C_ID_AUTORE->setMinimum(1);
        SEZIONE_C_ID_AUTORE->setMaximum(99999);

        gridLayout_12->addWidget(SEZIONE_C_ID_AUTORE, 0, 1, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 0, 0, 1, 1);

        SEZIONE_C_ARTICOLI_MIN = new QRadioButton(layoutWidget6);
        SEZIONE_C_ARTICOLI_MIN->setObjectName(QString::fromUtf8("SEZIONE_C_ARTICOLI_MIN"));

        gridLayout_13->addWidget(SEZIONE_C_ARTICOLI_MIN, 0, 1, 1, 1);

        SEZIONE_C_KEYWORD_MAX = new QRadioButton(layoutWidget6);
        SEZIONE_C_KEYWORD_MAX->setObjectName(QString::fromUtf8("SEZIONE_C_KEYWORD_MAX"));

        gridLayout_13->addWidget(SEZIONE_C_KEYWORD_MAX, 1, 1, 1, 2);

        stackedWidget->addWidget(PAG_SEZIONE_C);
        PAG_SEZIONE_D = new QWidget();
        PAG_SEZIONE_D->setObjectName(QString::fromUtf8("PAG_SEZIONE_D"));
        PAG_D_MENU = new QPushButton(PAG_SEZIONE_D);
        PAG_D_MENU->setObjectName(QString::fromUtf8("PAG_D_MENU"));
        PAG_D_MENU->setGeometry(QRect(300, 10, 151, 51));
        PAG_D_MENU->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        PAG_D_LISTA = new QListWidget(PAG_SEZIONE_D);
        PAG_D_LISTA->setObjectName(QString::fromUtf8("PAG_D_LISTA"));
        PAG_D_LISTA->setGeometry(QRect(10, 160, 771, 401));
        PAG_D_PULSANTE_CONFERMA = new QPushButton(PAG_SEZIONE_D);
        PAG_D_PULSANTE_CONFERMA->setObjectName(QString::fromUtf8("PAG_D_PULSANTE_CONFERMA"));
        PAG_D_PULSANTE_CONFERMA->setGeometry(QRect(300, 100, 151, 51));
        PAG_D_PULSANTE_CONFERMA->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        layoutWidget7 = new QWidget(PAG_SEZIONE_D);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(10, 70, 771, 24));
        gridLayout_16 = new QGridLayout(layoutWidget7);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        PAG_D_RADIO_VISUALIZZA_KEYWORD = new QRadioButton(layoutWidget7);
        PAG_D_RADIO_VISUALIZZA_KEYWORD->setObjectName(QString::fromUtf8("PAG_D_RADIO_VISUALIZZA_KEYWORD"));

        gridLayout_16->addWidget(PAG_D_RADIO_VISUALIZZA_KEYWORD, 0, 3, 1, 1);

        PAG_D_RADIO_VISUALIZZA_AUTORE = new QRadioButton(layoutWidget7);
        PAG_D_RADIO_VISUALIZZA_AUTORE->setObjectName(QString::fromUtf8("PAG_D_RADIO_VISUALIZZA_AUTORE"));

        gridLayout_16->addWidget(PAG_D_RADIO_VISUALIZZA_AUTORE, 0, 1, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_13 = new QLabel(layoutWidget7);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_15->addWidget(label_13, 0, 0, 1, 1);

        PAG_D_ID_AUTORE = new QSpinBox(layoutWidget7);
        PAG_D_ID_AUTORE->setObjectName(QString::fromUtf8("PAG_D_ID_AUTORE"));
        PAG_D_ID_AUTORE->setMinimum(1);
        PAG_D_ID_AUTORE->setMaximum(99999);

        gridLayout_15->addWidget(PAG_D_ID_AUTORE, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_15, 0, 0, 1, 1);

        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        label_14 = new QLabel(layoutWidget7);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_14->addWidget(label_14, 0, 0, 1, 1);

        PAG_D_KEYWORD = new QLineEdit(layoutWidget7);
        PAG_D_KEYWORD->setObjectName(QString::fromUtf8("PAG_D_KEYWORD"));

        gridLayout_14->addWidget(PAG_D_KEYWORD, 0, 1, 1, 1);


        gridLayout_16->addLayout(gridLayout_14, 0, 2, 1, 1);

        stackedWidget->addWidget(PAG_SEZIONE_D);
        PAG_SEZIONE_E = new QWidget();
        PAG_SEZIONE_E->setObjectName(QString::fromUtf8("PAG_SEZIONE_E"));
        PAG_E_BOTTONE_MENU = new QPushButton(PAG_SEZIONE_E);
        PAG_E_BOTTONE_MENU->setObjectName(QString::fromUtf8("PAG_E_BOTTONE_MENU"));
        PAG_E_BOTTONE_MENU->setGeometry(QRect(300, 10, 151, 51));
        PAG_E_BOTTONE_MENU->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        PAG_E_pulsante_key = new QPushButton(PAG_SEZIONE_E);
        PAG_E_pulsante_key->setObjectName(QString::fromUtf8("PAG_E_pulsante_key"));
        PAG_E_pulsante_key->setGeometry(QRect(300, 90, 151, 51));
        PAG_E_pulsante_key->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        PAG_E_LISTA = new QListWidget(PAG_SEZIONE_E);
        PAG_E_LISTA->setObjectName(QString::fromUtf8("PAG_E_LISTA"));
        PAG_E_LISTA->setGeometry(QRect(10, 150, 771, 192));
        stackedWidget->addWidget(PAG_SEZIONE_E);
        PAG_SEZIONE_F = new QWidget();
        PAG_SEZIONE_F->setObjectName(QString::fromUtf8("PAG_SEZIONE_F"));
        PAG_F_TORNA_MENU = new QPushButton(PAG_SEZIONE_F);
        PAG_F_TORNA_MENU->setObjectName(QString::fromUtf8("PAG_F_TORNA_MENU"));
        PAG_F_TORNA_MENU->setGeometry(QRect(300, 10, 151, 51));
        PAG_F_TORNA_MENU->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        PAG_F_CERCA_CONFERENZE_COMUN = new QPushButton(PAG_SEZIONE_F);
        PAG_F_CERCA_CONFERENZE_COMUN->setObjectName(QString::fromUtf8("PAG_F_CERCA_CONFERENZE_COMUN"));
        PAG_F_CERCA_CONFERENZE_COMUN->setGeometry(QRect(300, 120, 151, 51));
        PAG_F_CERCA_CONFERENZE_COMUN->setStyleSheet(QString::fromUtf8("background-color: rgb(15,138,8); "));
        PAG_F_LISTA = new QListWidget(PAG_SEZIONE_F);
        PAG_F_LISTA->setObjectName(QString::fromUtf8("PAG_F_LISTA"));
        PAG_F_LISTA->setGeometry(QRect(10, 190, 771, 371));
        layoutWidget8 = new QWidget(PAG_SEZIONE_F);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(270, 80, 225, 22));
        gridLayout_17 = new QGridLayout(layoutWidget8);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget8);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_17->addWidget(label_15, 0, 0, 1, 1);

        PAGINA_F_ID_CONFERENZA = new QSpinBox(layoutWidget8);
        PAGINA_F_ID_CONFERENZA->setObjectName(QString::fromUtf8("PAGINA_F_ID_CONFERENZA"));

        gridLayout_17->addWidget(PAGINA_F_ID_CONFERENZA, 0, 1, 1, 1);

        stackedWidget->addWidget(PAG_SEZIONE_F);
        PAG_VISUALIZZA_AUTORI = new QWidget();
        PAG_VISUALIZZA_AUTORI->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_AUTORI"));
        PAG_VISUALIZZA_AUTORI_PULSANTE_MENU = new QPushButton(PAG_VISUALIZZA_AUTORI);
        PAG_VISUALIZZA_AUTORI_PULSANTE_MENU->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_AUTORI_PULSANTE_MENU"));
        PAG_VISUALIZZA_AUTORI_PULSANTE_MENU->setGeometry(QRect(300, 10, 151, 51));
        PAG_VISUALIZZA_AUTORI_PULSANTE_MENU->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        PAG_VISUALIZZA_AUTORI_LISTA = new QListWidget(PAG_VISUALIZZA_AUTORI);
        PAG_VISUALIZZA_AUTORI_LISTA->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_AUTORI_LISTA"));
        PAG_VISUALIZZA_AUTORI_LISTA->setGeometry(QRect(10, 70, 771, 491));
        stackedWidget->addWidget(PAG_VISUALIZZA_AUTORI);
        PAG_VISUALIZZA_RIVISTE = new QWidget();
        PAG_VISUALIZZA_RIVISTE->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_RIVISTE"));
        PAG_VISUALIZZA_RIVISTE_LISTA = new QListWidget(PAG_VISUALIZZA_RIVISTE);
        PAG_VISUALIZZA_RIVISTE_LISTA->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_RIVISTE_LISTA"));
        PAG_VISUALIZZA_RIVISTE_LISTA->setGeometry(QRect(10, 70, 771, 491));
        PAG_VISUALIZZA_RIVISTE_PULSANTE_MENU_ = new QPushButton(PAG_VISUALIZZA_RIVISTE);
        PAG_VISUALIZZA_RIVISTE_PULSANTE_MENU_->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_RIVISTE_PULSANTE_MENU_"));
        PAG_VISUALIZZA_RIVISTE_PULSANTE_MENU_->setGeometry(QRect(300, 10, 151, 51));
        PAG_VISUALIZZA_RIVISTE_PULSANTE_MENU_->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        stackedWidget->addWidget(PAG_VISUALIZZA_RIVISTE);
        PAG_VISUALIZZA_CONFERENZE = new QWidget();
        PAG_VISUALIZZA_CONFERENZE->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_CONFERENZE"));
        PAG_VISUALIZZA_CONFERENZE_PULSANTE_MENU = new QPushButton(PAG_VISUALIZZA_CONFERENZE);
        PAG_VISUALIZZA_CONFERENZE_PULSANTE_MENU->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_CONFERENZE_PULSANTE_MENU"));
        PAG_VISUALIZZA_CONFERENZE_PULSANTE_MENU->setGeometry(QRect(300, 10, 151, 51));
        PAG_VISUALIZZA_CONFERENZE_PULSANTE_MENU->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        PAG_VISUALIZZA_CONFERENZE_LISTA = new QListWidget(PAG_VISUALIZZA_CONFERENZE);
        PAG_VISUALIZZA_CONFERENZE_LISTA->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_CONFERENZE_LISTA"));
        PAG_VISUALIZZA_CONFERENZE_LISTA->setGeometry(QRect(10, 70, 771, 491));
        stackedWidget->addWidget(PAG_VISUALIZZA_CONFERENZE);
        PAG_VISUALIZZA_ARTICOLI = new QWidget();
        PAG_VISUALIZZA_ARTICOLI->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_ARTICOLI"));
        PAG_VISUALIZZA_ARTICOLI_LISTA = new QListWidget(PAG_VISUALIZZA_ARTICOLI);
        PAG_VISUALIZZA_ARTICOLI_LISTA->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_ARTICOLI_LISTA"));
        PAG_VISUALIZZA_ARTICOLI_LISTA->setGeometry(QRect(10, 70, 771, 491));
        PAG_VISUALIZZA_ARTICOLI_PULSANTE_MENU = new QPushButton(PAG_VISUALIZZA_ARTICOLI);
        PAG_VISUALIZZA_ARTICOLI_PULSANTE_MENU->setObjectName(QString::fromUtf8("PAG_VISUALIZZA_ARTICOLI_PULSANTE_MENU"));
        PAG_VISUALIZZA_ARTICOLI_PULSANTE_MENU->setGeometry(QRect(300, 10, 151, 51));
        PAG_VISUALIZZA_ARTICOLI_PULSANTE_MENU->setStyleSheet(QString::fromUtf8("background-color: rgb(24,119,242);"));
        stackedWidget->addWidget(PAG_VISUALIZZA_ARTICOLI);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Progetto di Francesco", nullptr));
        SEZIONE_B->setText(QCoreApplication::translate("MainWindow", "Sezione B", nullptr));
        pulsante_visualizza_conferenze->setText(QCoreApplication::translate("MainWindow", "Visualizza conferenze", nullptr));
        pulsante_pag_aggiungiArticolo->setText(QCoreApplication::translate("MainWindow", "Aggiungi articolo", nullptr));
        pulsante_visualizza_Riviste->setText(QCoreApplication::translate("MainWindow", "Visualizza riviste", nullptr));
        go_pag_conferenze->setText(QCoreApplication::translate("MainWindow", "Aggiungi conferenze", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Sezione F", nullptr));
        SEZIONE_C->setText(QCoreApplication::translate("MainWindow", "Sezione C", nullptr));
        pulsante_visualizza_Autori->setText(QCoreApplication::translate("MainWindow", "Visualizza autori", nullptr));
        pulsante_sezione_D->setText(QCoreApplication::translate("MainWindow", "Sezione D", nullptr));
        go_pag_riviste->setText(QCoreApplication::translate("MainWindow", "Aggiungi riviste", nullptr));
        go_pag_autori->setText(QCoreApplication::translate("MainWindow", "Aggiungi autori", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Sezione E", nullptr));
        pulsante_visualizza_Articoli->setText(QCoreApplication::translate("MainWindow", "Visualizza articoli", nullptr));
        pulsante_aggiungi_autori_file->setText(QCoreApplication::translate("MainWindow", "Aggiungi autori da file", nullptr));
        pulsante_aggiungi_riviste_file->setText(QCoreApplication::translate("MainWindow", "Aggiungi riviste da file", nullptr));
        pulsante_aggiungi_conferenze_file->setText(QCoreApplication::translate("MainWindow", "Aggiungi conferenze da file", nullptr));
        pulsante_aggiungi_articolo_file->setText(QCoreApplication::translate("MainWindow", "Aggiungi articolo da file", nullptr));
        aggiungi_autore->setText(QCoreApplication::translate("MainWindow", "Aggiungi Autore", nullptr));
        label_cognome->setText(QCoreApplication::translate("MainWindow", "Cognome", nullptr));
        label_id_autore->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_nome->setText(QCoreApplication::translate("MainWindow", "Nome", nullptr));
        label_afferenze->setText(QCoreApplication::translate("MainWindow", "Afferenze", nullptr));
        afferenze_plaintext->setPlainText(QCoreApplication::translate("MainWindow", "Inserire qui le afferenze di ogni autore separate da una virgola\n"
"\n"
"Esempio : \"ciao, sono una, afferenza\"", nullptr));
        pulsante_torna_menu->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        pulsante_aggiungi_rivista->setText(QCoreApplication::translate("MainWindow", "Aggiungi Rivista", nullptr));
        pulsante_tornaalmenu->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        editore_rivista->setText(QCoreApplication::translate("MainWindow", "Editore", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        acronimo_rivista->setText(QCoreApplication::translate("MainWindow", "Acronimo", nullptr));
        volume_rivista->setText(QCoreApplication::translate("MainWindow", "Volume", nullptr));
        nome_rivista->setText(QCoreApplication::translate("MainWindow", "Nome", nullptr));
        vai_al_menu_principale->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        pulsante_aggiungi_conferenza->setText(QCoreApplication::translate("MainWindow", "Aggiungi conferenza", nullptr));
        label_luogo_conf->setText(QCoreApplication::translate("MainWindow", "Luogo", nullptr));
        organizzatori_plaintext->setPlainText(QCoreApplication::translate("MainWindow", "Inserire qui i nomi degli organizzatori separati da una virgola\n"
"\n"
"Esempio : \"giovanni, martino, vanessa, luana\"\n"
"", nullptr));
        label_organizzatori->setText(QCoreApplication::translate("MainWindow", "Organizzatori", nullptr));
        label_part_conf->setText(QCoreApplication::translate("MainWindow", "Partecipanti", nullptr));
        label_acronimo_conf->setText(QCoreApplication::translate("MainWindow", "Acronimo", nullptr));
        label_nome_conf->setText(QCoreApplication::translate("MainWindow", "Nome", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        pulsante_torna_al_menu->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Aggiungi articolo", nullptr));
        plaintext_keyword_di_articolo->setPlainText(QCoreApplication::translate("MainWindow", "Inserire qui le keywords separate da una virgola \",\" \n"
"\n"
"Esempio : \"ciao, ho moltissime, keyword \"", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "ID art. correlati (seleziona l'ID e clicca aggiungi)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID Conferenza/Rivista in cui pubblicarlo", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Keyword", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Prezzo", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Titolo", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "ID Autori (seleziona l'ID e clicca aggiungi)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Num. Pagine", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ID Articolo", nullptr));
        articolo_add_autore->setText(QCoreApplication::translate("MainWindow", "Aggiungi", nullptr));
        articoli_aggiungi_correlato->setText(QCoreApplication::translate("MainWindow", "Aggiungi", nullptr));
        sezioneB_to_menu->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        SEZIONEB_PULSANTE_VISUALIZZA->setText(QCoreApplication::translate("MainWindow", "Clicca per confermare", nullptr));
        SezioneB_scelta_visualizza_articoli_per_autore->setText(QCoreApplication::translate("MainWindow", "Visualizza articoli di quell'autore", nullptr));
        SEZIONE_B_pulsante_visualizz_articoli_di_conferenza->setText(QCoreApplication::translate("MainWindow", "Visualizza articoli di quella conferenza", nullptr));
        SEZIONE_B_pulsante_visualizz_articoli_di_rivista->setText(QCoreApplication::translate("MainWindow", "Visualizza articoli di quella rivista", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "ID autore", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ID conferenza", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "ID rivista", nullptr));
        SEZIONE_C_TORNAMENU->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        SEZIONE_C_PULSANTE_CONFERMA->setText(QCoreApplication::translate("MainWindow", "Clicca per confermare", nullptr));
        SEZIONE_C_ARTICOLI_MAX->setText(QCoreApplication::translate("MainWindow", "Visualizza articoli con prezzo max dell'autore", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "ID autore", nullptr));
        SEZIONE_C_ARTICOLI_MIN->setText(QCoreApplication::translate("MainWindow", "Visualizza articoli con prezzo min dell'autore", nullptr));
        SEZIONE_C_KEYWORD_MAX->setText(QCoreApplication::translate("MainWindow", "Visualizza keyword che hanno il guadagno max (NON RIFERITE ALL'AUTORE)", nullptr));
        PAG_D_MENU->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        PAG_D_PULSANTE_CONFERMA->setText(QCoreApplication::translate("MainWindow", "Clicca per confermare", nullptr));
        PAG_D_RADIO_VISUALIZZA_KEYWORD->setText(QCoreApplication::translate("MainWindow", "Visualizza articoli ordinati della keyword", nullptr));
        PAG_D_RADIO_VISUALIZZA_AUTORE->setText(QCoreApplication::translate("MainWindow", "Visualizza articoli ordinati dell'autore", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ID autore", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Keyword", nullptr));
        PAG_E_BOTTONE_MENU->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        PAG_E_pulsante_key->setText(QCoreApplication::translate("MainWindow", "5 keyword pi\303\271 diffuse", nullptr));
        PAG_F_TORNA_MENU->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        PAG_F_CERCA_CONFERENZE_COMUN->setText(QCoreApplication::translate("MainWindow", "Conferenze comuni", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "ID conferenza", nullptr));
        PAG_VISUALIZZA_AUTORI_PULSANTE_MENU->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        PAG_VISUALIZZA_RIVISTE_PULSANTE_MENU_->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        PAG_VISUALIZZA_CONFERENZE_PULSANTE_MENU->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
        PAG_VISUALIZZA_ARTICOLI_PULSANTE_MENU->setText(QCoreApplication::translate("MainWindow", "Menu principale", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
