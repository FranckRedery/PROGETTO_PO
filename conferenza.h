#ifndef CONFERENZA_H
#define CONFERENZA_H
#include "pubblicazione.h"
#include <list>
#include <QString>
using namespace std;

class Conferenza : public Pubblicazione
{

public:

    Conferenza() : Pubblicazione(), luogo("Non definito"), num_partecipanti(0) {}

    Conferenza(QString n, QString a, QString d, QString l, int num, list<QString> o): Pubblicazione(n,a,d,true) , luogo(l), num_partecipanti(num), organizzatori(o) {}

    Conferenza* clone() const{ return new Conferenza(*this); }

    QString get_luogo() const { return luogo; }
    int get_num_partecipanti() const { return num_partecipanti; }

    void set_luogo(QString l) { luogo =  l; }
    void set_num_partecipanti(int n) { num_partecipanti = n; }

    void aggiungi_organizzatore(QString org);

    bool is_conferenza() const { return true; }


private:

    QString luogo;
    list<QString> organizzatori;
    int num_partecipanti;

};

#endif // CONFERENZA_H
