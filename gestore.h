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


#ifndef GESTORE_H
#define GESTORE_H

#include "autore.h"
#include <QList>
#include "pubblicazione.h"
#include "rivista.h"
#include "conferenza.h"
#include "articolo.h"

class Gestore
{

public:

    Gestore(){};

    ~Gestore();

    Gestore(const Gestore& g);

    void aggiungi_autore(QString n, QString c, int id, std::list<QString> a);

    void aggiungi_conferenza(int id, QString n, QString a, QString d, QString l, int num, std::list<QString> o);

    void aggiungi_rivista(int id, QString n, QString a, QString d, QString e, int v);

    void aggiungi_articolo(int id, int n, double p, QString t, Pubblicazione* pub, std::list<int> corr, std::list<Autore*> aut, std::list<QString> key);

    void cancella_tutti_autori();

    void cancella_tutti_articoli();

    void cancella_tutte_pubblicazioni();

    bool pubblicazioni_isEmpty() const { return pubblicazioni.empty(); }

    Gestore& operator=(const Gestore& g);

    // ritorna un puntatore alla pubblicazione se è presente, altrimenti ritorna nullptr
    Pubblicazione* get_pubblicazione(int id) const ;

    // se l'id è stato preso torna true
    bool Is_ID_autore_alreadytaken(int id) const ;

    bool Is_ID_pubblicazione_alreadytaken(int id) const ;

    //se l'id è stato preso torna true
    bool Is_ID_articolo_alreadytaken(int id) const;

    // ritorna un puntatore ad autore se l'id di quell'autore è presente nella lista , altrimenti ritorna nullptr
    Autore* get_autore(int id) const;

    // SEZIONE B METODO 1 TROVA GLI ARTICOLI DI UN DETERMINATO AUTORE PRESO PER ID
    void get_articoli_autore(int id, std::list<Articolo*>& lista) const;

    // SEZIONE B METODO 4 E 5 TROVA GLI ARTICOLI DI UNA CONFERENZA/RIVSTA PRESA PER NOME
    void get_articoli_conferenza_or_rivista(int id, std::list<Articolo*>& lista) const;

    // SEZIONE C METODO 1 E 2 , TROVA GLI ARTICOLI DI UN AUTORE CON PREZZO MAX O MIN
    void get_articoli_autore_prezzo_max_or_min(int id, std::list<Articolo*>& lista, int scelta) const;

    // SEZIONE C METODO 6
    void get_keywords_guadagno_max(std::list<QString>& lista) const;

    //SEZIONE D METODO 2
    void articoli_autore_sorted_anno(int id, std::list<Articolo*>& lista) const;

    // SEZIONE D METODO 6
    void articoli_autore_sorted(int id, std::list<Articolo*>& lista) const;

     // trova gli articoli in cui è presente quella keyword
    void get_articoli_keyword(QString key, std::list<Articolo*>& lista) const;

    //SEZIONE E METODO 6
    void get_riviste_specialistiche(std::list<Pubblicazione*>& lista) const;

    // SEZIONE F METODO 5
    void get_conferenze_simili(int id, std::list<Pubblicazione*>& lista) const;

    int get_first_free_id_autore() const;

    int get_first_free_id_articolo() const;

    int get_first_free_id_pubblicazione() const;

    bool is_pubblicazione_unique(QString data, QString nome, bool is_conf) const;

    void get_all_keyword_by_ID(int id, std::list<QString>& lista) const;

    bool sottoinsieme(std::list<QString>& first , std::list<QString>& second) const;

private:

    std::list<Autore*> autori;
    std::list<Articolo*> articoli;
    std::list<Pubblicazione*> pubblicazioni;

};

#endif // GESTORE_H
