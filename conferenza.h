#ifndef CONFERENZA_H
#define CONFERENZA_H

#include "pubblicazione.h"
#include <list>
#include <QString>


class Conferenza : public Pubblicazione
{

public:

    Conferenza() : Pubblicazione(), luogo("Non definito"), num_partecipanti(0) {}

    Conferenza(int id, QString n, QString a, QString d, QString l, int num, std::list<QString> o): Pubblicazione(id,n,a,d,true) , luogo(l), num_partecipanti(num), organizzatori(o) {}

    // metodo che viene usato per fare il costruttore di copia e operator =
    // nel gestore perché usiamo l'ereditarietà
    Conferenza* clone() const{ return new Conferenza(*this); }

    QString get_luogo() const { return luogo; }

    int get_num_partecipanti() const { return num_partecipanti; }

    void set_luogo(QString l) { luogo =  l; }

    void set_num_partecipanti(int n) { num_partecipanti = n; }

    void aggiungi_organizzatore(QString org){ organizzatori.push_back(org); }

    bool is_conferenza() const { return true; }


private:

    QString luogo;
    std::list<QString> organizzatori;
    int num_partecipanti;

};

#endif // CONFERENZA_H
