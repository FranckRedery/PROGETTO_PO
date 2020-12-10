#ifndef GESTORE_H
#define GESTORE_H

#include "autore.h"
#include <QList>
#include "pubblicazione.h"
#include "rivista.h"
#include "conferenza.h"
#include "articolo.h"

class Gestore
{

public:

    Gestore(){};

    ~Gestore();

    Gestore(const Gestore& g);

    void aggiungi_autore(QString n, QString c, int id, QList<QString> a);

    void aggiungi_conferenza(QString n, QString a, QString d, QString l, int num, QList<QString> o);

    void aggiungi_rivista(QString n, QString a, QString d, QString e, int v);

    void aggiungi_articolo(int id, int n, double p, QString t, Pubblicazione* pub, QList<int> corr, QList<Autore*> aut, QList<QString> key);

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

private:

    QList<Autore*> autori;
    QList<Articolo*> articoli;
    QList<Pubblicazione*> pubblicazioni;

};

#endif // GESTORE_H
