#ifndef GESTORE_H
#define GESTORE_H

#include "autore.h"
#include <QList>

class Gestore
{

public:

    Gestore(){};

    ~Gestore();

    void aggiungi_autore(QString n, QString c);

    void cancella_tutti_autori();



private:

    int current_id = 0;
    QList<Autore*> autori;

};

#endif // GESTORE_H
