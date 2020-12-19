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
