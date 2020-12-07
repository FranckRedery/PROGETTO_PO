#ifndef AUTORE_H
#define AUTORE_H
#include <QString>
#include <QList>

class Autore
{

public:

    Autore(): nome("Non definito"), cognome("Non definito"){}

    Autore(QString n, QString c): nome(n) , cognome(c){}

    void set_nome(QString n);

    void set_cognome(QString c);

    void aggiungi_afferenza(QString aff);

    QString get_nome() const;

    QString get_cognome() const;

private:

    int identificativo;
    QString nome;
    QString cognome;
    QList<QString> afferenze;       // struttura pubblica o privata in cui ha lavorato
};

#endif // AUTORE_H
