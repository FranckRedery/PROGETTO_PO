#ifndef CONFERENZA_H
#define CONFERENZA_H
#include "pubblicazione.h"
#include <QList>
#include <QString>

class Conferenza : public Pubblicazione
{

public:

    Conferenza() : Pubblicazione(), luogo("Non definito"), num_partecipanti(0) {}

    Conferenza(QString n, QString a, QString d, QString l, int num, QList<QString> o): Pubblicazione(n,a,d) , luogo(l), num_partecipanti(num), organizzatori(o) {}

    Conferenza* clone() const{ return new Conferenza(*this); }

    QString get_luogo() const { return luogo; }
    int get_num_partecipanti() const { return num_partecipanti; }

    void set_luogo(QString l) { luogo =  l; }
    void set_num_partecipanti(int n) { num_partecipanti = n; }

    void aggiungi_organizzatore(QString org);


private:

    QString luogo;
    QList<QString> organizzatori;
    int num_partecipanti;

};

#endif // CONFERENZA_H
