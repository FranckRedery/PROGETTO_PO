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


#ifndef CONFERENZA_H
#define CONFERENZA_H

#include "pubblicazione.h"
#include <list>
#include <QString>


class Conferenza : public Pubblicazione
{

public:

    Conferenza() : Pubblicazione(), luogo("Non definito"), num_partecipanti(0) {}

    Conferenza(int id, QString n, QString a, QString d, QString l, int num, std::list<QString> o): Pubblicazione(id,n,a,d,true) , luogo(l), num_partecipanti(num), organizzatori(o) {}

    // metodo che viene usato per fare il costruttore di copia e operator =
    // nel gestore perché usiamo l'ereditarietà
    Conferenza* clone() const{ return new Conferenza(*this); }

    QString get_luogo() const { return luogo; }

    int get_num_partecipanti() const { return num_partecipanti; }

    void set_luogo(QString l) { luogo =  l; }

    void set_num_partecipanti(int n) { num_partecipanti = n; }

    void aggiungi_organizzatore(QString org){ organizzatori.push_back(org); }

    bool is_conferenza() const { return true; }


private:

    QString luogo;
    std::list<QString> organizzatori;
    int num_partecipanti;

};

#endif // CONFERENZA_H
