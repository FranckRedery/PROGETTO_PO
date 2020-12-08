#ifndef RIVISTA_H
#define RIVISTA_H
#include "pubblicazione.h"
#include <QString>

class Rivista : public Pubblicazione
{

public:

    Rivista() : Pubblicazione(), editore("Non definito"), volume(0) {}
    Rivista(QString n, QString a, QString d, QString e, int v) : Pubblicazione(n,a,d) , editore(e) , volume(v) {}

    Rivista* clone() const { return new Rivista(*this); }

    int get_volume() const { return volume; }
    QString get_editore() const { return editore; }

    void set_volume(int v) { volume = v; }
    void set_editore(QString e) { editore = e; }

private:

    QString editore;
    int volume;

};

#endif // RIVISTA_H
