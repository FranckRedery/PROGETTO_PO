/*This file is part of Nome-Programma.

Nome-Programma is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Nome-Programma is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Nome-Programma.  If not, see <http://www.gnu.org/licenses/>.*/


#ifndef ARTICOLO_H
#define ARTICOLO_H
#include <list>
#include <QString>
#include "pubblicazione.h"
#include "autore.h"
#include "conferenza.h"
#include "rivista.h"


class Articolo
{

public:

    Articolo(){}

    Articolo(int id, int n, double p, QString t, Pubblicazione* pub, std::list<int> corr, std::list<Autore*> aut, std::list<QString> key) : identificativo(id), num_pagine(n), prezzo(p), titolo(t) , destinata(pub), articoli_correlati(corr), autori(aut), keyword(key) {}

    int get_identificativo() const { return identificativo; }

    int get_num_pagine() const { return num_pagine; }

    double get_prezzo() const { return prezzo; }

    QString get_titolo() const { return titolo; }

    Pubblicazione* get_pubblicazione() const { return destinata; }

    std::list<QString> get_keywords() const { return keyword; }

    std::list<int> get_id_autori() const;

    // due metodi get che servono per il sort dei metodi della sezione D
    QString get_prima_key() const { return keyword.front(); }

    QString get_primo_cognome_autore() const { return autori.front()->get_cognome(); }

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
    std::list<int> articoli_correlati; // racchiude gli ID degli articoli correlati
    std::list<Autore*> autori;
    std::list<QString> keyword;
    Pubblicazione* destinata; // la pubblicazioni a cui è destinato l'articolo (può essere  per una rivista o per una conferenza)

};

#endif // ARTICOLO_H
