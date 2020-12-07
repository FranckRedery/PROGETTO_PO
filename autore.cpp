#include "autore.h"

void Autore::set_nome(QString n){
    nome = n;
}

void Autore::set_cognome(QString c){
    cognome = c;
}

void Autore::set_id(int id){
    identificativo = id;
}

void Autore::aggiungi_afferenza(QString aff){
    afferenze.push_back(aff);
}

int Autore::get_id() const{
    return identificativo;
}

QString Autore::get_cognome() const{
    return cognome;
}

QString Autore::get_nome() const{
    return nome;
}
