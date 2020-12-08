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

    void aggiungi_autore(QString n, QString c);

    void aggiungi_conferenza(QString n, QString a, QString d, QString l, int num);

    void aggiungi_rivista(QString n, QString a, QString d, QString e, int v);

    void aggiungi_articolo(int id, int n, int p, QString t, Pubblicazione* pub);

    void cancella_tutti_autori();

    void cancella_tutti_articoli();

    void cancella_tutte_pubblicazioni();

    bool pubblicazioni_isEmpty() const { return pubblicazioni.empty(); }

    Gestore& operator=(const Gestore& g);

private:

    int current_id = 0;
    QList<Autore*> autori;
    QList<Articolo*> articoli;
    QList<Pubblicazione*> pubblicazioni;

};

#endif // GESTORE_H
