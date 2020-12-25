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


#include "articolo.h"

void Articolo::aggiungi_autore(Autore *a){
    autori.push_back(a);
}

void Articolo::aggiungi_keyword(QString k){
    keyword.push_back(k);
}

// ritorna una lista di interi che contiene
// gli id di tutti gli autori dell'articolo
std::list<int> Articolo::get_id_autori() const{
    std::list<int> id_autori;
    for(auto& i : autori){
        id_autori.push_back(i->get_id());
    }
    return id_autori;
}

bool Articolo::is_correlato(int id) const {
    for(auto& it : articoli_correlati){
        if(id == it){
            return true;
        }
    }
    return false;
}
