#ifndef PUBBLICAZIONE_H
#define PUBBLICAZIONE_H
#include <QString>


class Pubblicazione
{

public:

    Pubblicazione(): nome("Non definito"), acronimo("Non definito"), data("Non definita") {}

    Pubblicazione(QString n, QString a, QString d, bool conf): nome(n), acronimo(a), data(d), conferenza(conf){}

    QString get_nome() const { return nome; }
    QString get_acronimo() const { return acronimo; }
    QString get_data() const { return data; }
    bool is_conferenza() const { return conferenza; }

    void set_nome(QString n) { nome = n; }
    void set_acronimo(QString a) { acronimo = a; }
    void set_data(QString d) { data = d; }

    virtual Pubblicazione* clone() const { return new Pubblicazione(*this); }

    virtual ~Pubblicazione(){}


private:

    QString nome;
    QString acronimo;       // nome abbreviato
    QString data;
    bool conferenza;                // inizializzato automaticamente a true se è una conferenza , false altrimenti

};

#endif // PUBBLICAZIONE_H
