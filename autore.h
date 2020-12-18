#ifndef AUTORE_H
#define AUTORE_H
#include <QString>
#include <list>
using namespace std;

class Autore
{

public:

    Autore(): nome("Non definito"), cognome("Non definito"), identificativo(0){}

    Autore(QString n, QString c, int id, list<QString> a): nome(n) , cognome(c), identificativo(id), afferenze(a){}

    void set_nome(QString n){ nome = n; }

    void set_cognome(QString c){ cognome = c; }

    void set_id(int id){ identificativo = id; }

    void aggiungi_afferenza(QString aff){ afferenze.push_back(aff); }

    int get_id() const { return identificativo; }

    QString get_nome() const { return nome; }

    QString get_cognome() const { return cognome; }

private:

    int identificativo;
    QString nome;
    QString cognome;
    list<QString> afferenze;       // struttura pubblica o privata in cui ha lavorato
};

#endif // AUTORE_H
