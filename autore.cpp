#include "autore.h"

void Autore::set_nome(QString n){
    nome = n;
}

void Autore::set_cognome(QString c){
    cognome = c;
}

void Autore::aggiungi_afferenza(QString aff){
    afferenze.push_back(aff);
}

QString Autore::get_cognome() const{
    return cognome;
}

QString Autore::get_nome() const{
    return nome;
}
