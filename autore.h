#ifndef AUTORE_H
#define AUTORE_H
#include <QString>
#include <QList>

class Autore
{

public:

    Autore(): nome("Non definito"), cognome("Non definito"), identificativo(0){}

    Autore(QString n, QString c, int id): nome(n) , cognome(c), identificativo(id){}

    void set_nome(QString n);

    void set_cognome(QString c);

    void set_id(int id);

    void aggiungi_afferenza(QString aff);

    int get_id() const;

    QString get_nome() const;

    QString get_cognome() const;

private:

    int identificativo;
    QString nome;
    QString cognome;
    QList<QString> afferenze;       // struttura pubblica o privata in cui ha lavorato
};

#endif // AUTORE_H
