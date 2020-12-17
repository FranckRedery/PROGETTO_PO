#ifndef GESTORE_H
#define GESTORE_H

#include "autore.h"
#include <QList>
#include "pubblicazione.h"
#include "rivista.h"
#include "conferenza.h"
#include "articolo.h"
#include <list>
using namespace std;

class Gestore
{

public:

    Gestore(){};

    ~Gestore();

    Gestore(const Gestore& g);

    void aggiungi_autore(QString n, QString c, int id, list<QString> a);

    void aggiungi_conferenza(QString n, QString a, QString d, QString l, int num, list<QString> o);

    void aggiungi_rivista(QString n, QString a, QString d, QString e, int v);

    void aggiungi_articolo(int id, int n, double p, QString t, Pubblicazione* pub, list<int> corr, list<Autore*> aut, list<QString> key);

    void cancella_tutti_autori();

    void cancella_tutti_articoli();

    void cancella_tutte_pubblicazioni();

    bool pubblicazioni_isEmpty() const { return pubblicazioni.empty(); }

    Gestore& operator=(const Gestore& g);

    // ritorna un puntatore alla pubblicazione se è presente, altrimenti ritorna nullptr
    Pubblicazione* get_pubblicazione(QString nome) const ;

    bool Is_ID_autore_alreadytaken(int id) const ;

    bool Is_Nome_pubblicazione_alreadytaken(QString nome) const ;

    bool Is_ID_articolo_alreadytaken(int id) const;

    // ritorna un puntatore ad autore se l'id di quell'autore è presente nella lista , altrimenti ritorna nullptr
    Autore* get_autore(int id) const;

    // SEZIONE B METODO 1 TROVA GLI ARTICOLI DI UN DETERMINATO AUTORE PRESO PER ID
    void get_articoli_autore(int id, list<Articolo*>& lista) const;

    // SEZIONE B METODO 4 E 5 TROVA GLI ARTICOLI DI UNA CONFERENZA/RIVSTA PRESA PER NOME
    void get_articoli_conferenza_or_rivista(QString nome, list<Articolo*>& lista) const;

    // SEZIONE C METODO 1 E 2 , TROVA GLI ARTICOLI DI UN AUTORE CON PREZZO MAX O MIN
    void get_articoli_autore_prezzo_max_or_min(int id, list<Articolo*>& lista, int scelta) const;

    // SEZIONE C METODO 6
    void get_keywords_guadagno_max(list<QString>& lista) const;

    // SEZIONE D METODO 6
    void articoli_autore_sorted(int id, list<Articolo*>& lista) const;

    // SEZIONE D METODO 5
    void articoli_keyword_sorted(QString key, list<Articolo*>& lista) const;

     // trova gli articoli in cui è presente quella keyword
    void get_articoli_keyword(QString key, list<Articolo*>& lista) const;

    // SEZIONE E METODO 3
    void get_5_most_common_key(list<QString>& chiavi) const;

    // SEZIONE F METODO 5
    void get_conferenze_simili(QString nome, list<Pubblicazione*>& lista) const;

    int get_first_free_id_autore() const;

private:

    list<Autore*> autori;
    list<Articolo*> articoli;
    list<Pubblicazione*> pubblicazioni;

};

#endif // GESTORE_H
