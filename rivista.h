/*This file is part of ProgettoPO-2020-2021-Reda-209394.

ProgettoPO-2020-2021-Reda-209394 is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ProgettoPO-2020-2021-Reda-209394 is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ProgettoPO-2020-2021-Reda-209394.  If not, see <http://www.gnu.org/licenses/>.*/


#ifndef RIVISTA_H
#define RIVISTA_H
#include "pubblicazione.h"
#include <QString>

class Rivista : public Pubblicazione
{

public:

    Rivista() : Pubblicazione(), editore("Non definito"), volume(0) {}

    Rivista(int id, QString n, QString a, QString d, QString e, int v) : Pubblicazione(id,n,a,d,false) , editore(e) , volume(v) {}

    // metodo che viene usato per fare il costruttore di copia e operator =
    // nel gestore perché usiamo l'ereditarietà
    Rivista* clone() const { return new Rivista(*this); }

    int get_volume() const { return volume; }

    QString get_editore() const { return editore; }

    void set_volume(int v) { volume = v; }

    void set_editore(QString e) { editore = e; }

    bool is_conferenza() const { return false; }

private:

    QString editore;
    int volume;

};

#endif // RIVISTA_H
