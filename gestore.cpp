#include "gestore.h"

void Gestore::aggiungi_autore(QString n, QString c){

    Autore* nuovo = new Autore(n,c);
    nuovo->set_id(current_id);
    current_id++;
    autori.push_back(nuovo);

}
