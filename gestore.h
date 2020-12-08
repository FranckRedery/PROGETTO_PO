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

    ~Gestore();  // RICORDA CHE SERVE LA TRIADE DELETE , COSTRUTTORE COPIA E OPERATOR = !!!

    void aggiungi_autore(QString n, QString c);

    //void aggiungi_articolo();

    //void aggiungi_conferenza();

    //void aggiungi_rivista();

    void cancella_tutti_autori();

    //void cancella_tutti_articoli();

    //void cancella_tutte_pubblicazioni();

    // costruttore copia

    //operator =

private:

    int current_id = 0;
    QList<Autore*> autori;
    QList<Articolo*> articoli;
    QList<Pubblicazione*> pubblicazioni;

};

#endif // GESTORE_H
