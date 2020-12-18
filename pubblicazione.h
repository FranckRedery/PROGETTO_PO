#ifndef PUBBLICAZIONE_H
#define PUBBLICAZIONE_H
#include <QString>


class Pubblicazione
{

public:

    Pubblicazione(): identificativo(1), nome("Non definito"), acronimo("Non definito"), data("Non definita") {}

    Pubblicazione(int id, QString n, QString a, QString d, bool conf): identificativo(id), nome(n), acronimo(a), data(d), conferenza(conf){}

    QString get_nome() const { return nome; }

    QString get_acronimo() const { return acronimo; }

    QString get_data() const { return data; }

    int get_id() const { return identificativo; }

    virtual bool is_conferenza() const { return conferenza; }

    void set_nome(QString n) { nome = n; }

    void set_acronimo(QString a) { acronimo = a; }

    void set_data(QString d) { data = d; }

    void set_id(int id) { identificativo = id; }

    // metodo che viene usato per fare il costruttore di copia e operator =
    // nel gestore perché usiamo l'ereditarietà
    virtual Pubblicazione* clone() const { return new Pubblicazione(*this); }

    virtual ~Pubblicazione(){}


private:

    int identificativo;
    QString nome;
    QString acronimo;       // nome abbreviato
    QString data;
    bool conferenza;                // inizializzato automaticamente a true se è una conferenza , false altrimenti

};

#endif // PUBBLICAZIONE_H
