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


#ifndef AUTORE_H
#define AUTORE_H
#include <QString>
#include <list>


class Autore
{

public:

    Autore(): nome("Non definito"), cognome("Non definito"), identificativo(0){}

    Autore(QString n, QString c, int id, std::list<QString> a): nome(n) , cognome(c), identificativo(id), afferenze(a){}

    void set_nome(QString n){ nome = n; }

    void set_cognome(QString c){ cognome = c; }

    void set_id(int id){ identificativo = id; }

    void aggiungi_afferenza(QString aff){ afferenze.push_back(aff); }

    int get_id() const { return identificativo; }

    QString get_nome() const { return nome; }

    QString get_cognome() const { return cognome; }

private:

    QString nome;
    QString cognome;
    int identificativo;
    std::list<QString> afferenze;       // struttura pubblica o privata in cui ha lavorato
};

#endif // AUTORE_H
