#ifndef ARTICOLO_H
#define ARTICOLO_H
#include <list>
#include <QString>
#include "pubblicazione.h"
#include "autore.h"
#include "conferenza.h"
#include "rivista.h"
using namespace std;

class Articolo
{

public:

    Articolo(){}

    Articolo(int id, int n, double p, QString t, Pubblicazione* pub, list<int> corr, list<Autore*> aut, list<QString> key) : identificativo(id), num_pagine(n), prezzo(p), titolo(t) , destinata(pub), articoli_correlati(corr), autori(aut), keyword(key) {}

    int get_identificativo() const { return identificativo; }
    int get_num_pagine() const { return num_pagine; }
    double get_prezzo() const { return prezzo; }
    QString get_titolo() const { return titolo; }
    Pubblicazione* get_pubblicazione() const { return destinata; }
    list<QString> get_keywords() const; // DA IMPLEMENTARE per metodo 6 sezione C
    list<int> get_id_autori() const; // DA IMPLEMENTARE per metodo 1 - 2 sezione C

    void set_identificativo(int id) { identificativo = id; }
    void set_num_pagine(int n) { num_pagine = n; }
    void set_prezzo(double p) { prezzo = p; }
    void set_titolo(QString t) { titolo = t; }
    void set_pubblicazione(Pubblicazione* p) { destinata = p; }

    void aggiungi_autore(Autore* a);
    void aggiungi_keyword(QString k);


private:

    int identificativo;
    int num_pagine;
    double prezzo;
    QString titolo;
    list<int> articoli_correlati; // racchiude gli ID degli articoli correlati
    list<Autore*> autori;
    list<QString> keyword;
    Pubblicazione* destinata; // la pubblicazioni a cui è destinato l'articolo (può essere  per una rivista o per una conferenza)

};

#endif // ARTICOLO_H
