#ifndef PUBBLICAZIONE_H
#define PUBBLICAZIONE_H
#include <QString>


class Pubblicazione
{

public:

    Pubblicazione(): nome("Non definito"), acronimo("Non definito"), data("Non definita"){}

    Pubblicazione(QString n, QString a, QString d): nome(n), acronimo(a), data(d){}

    QString get_nome() const { return nome; }
    QString get_acronimo() const { return acronimo; }
    QString get_data() const { return data; }

    void set_nome(QString n) { nome = n; }
    void set_acronimo(QString a) { acronimo = a; }
    void set_data(QString d) { data = d; }

    virtual Pubblicazione* clone() const { return new Pubblicazione(*this); }

    virtual ~Pubblicazione(){}


private:

    QString nome;
    QString acronimo;       // nome abbreviato
    QString data;

};

#endif // PUBBLICAZIONE_H
