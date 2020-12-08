#include "articolo.h"

void Articolo::aggiungi_autore(Autore *a){
    autori.push_back(a);
}

void Articolo::aggiungi_keyword(QString k){
    keyword.push_back(k);
}
