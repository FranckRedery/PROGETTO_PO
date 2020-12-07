#ifndef GESTORE_H
#define GESTORE_H

#include "autore.h"
#include <QList>

class Gestore
{

public:

    Gestore(){};

    void aggiungi_autore(QString n, QString c);

private:

    int current_id = 0;
    QList<Autore*> autori;

};

#endif // GESTORE_H
