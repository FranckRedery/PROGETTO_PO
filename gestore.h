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

    Pubblicazione* get_pubblicazione(QString nome) const ; // ritorna un puntatore alla pubblicazione se è presente, altrimenti ritorna nullptr

    bool Is_ID_autore_alreadytaken(int id) const ;

    bool Is_Nome_pubblicazione_alreadytaken(QString nome) const ;

    bool Is_ID_articolo_alreadytaken(int id) const;

    Autore* get_autore(int id) const;          // ritorna un puntatore ad autore se l'id di quell'autore è presente nella lista , altrimenti ritorna nullptr

    void get_articoli_autore(int id, list<Articolo*>& lista) const; // SEZIONE B METODO 1 TROVA GLI ARTICOLI DI UN DETERMINATO AUTORE PRESO PER ID

    void get_articoli_conferenza_or_rivista(QString nome, list<Articolo*>& lista) const; // SEZIONE B METODO 4 E 5 TROVA GLI ARTICOLI DI UNA CONFERENZA/RIVSTA PRESA PER NOME

private:

    list<Autore*> autori;
    list<Articolo*> articoli;
    list<Pubblicazione*> pubblicazioni;

};

#endif // GESTORE_H
