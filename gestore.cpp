#include "gestore.h"

void Gestore::aggiungi_autore(QString n, QString c){

    Autore* nuovo = new Autore(n,c);
    nuovo->set_id(current_id);
    current_id++;
    autori.push_back(nuovo);

}

void Gestore::cancella_tutti_autori(){
    for(auto& it : autori){
        delete it;
    }
    autori.clear();
}

Gestore::~Gestore(){            // RICORDA CHE SERVE LA TRIADE DELETE , COSTRUTTORE COPIA E OPERATOR = !!!
    cancella_tutti_autori();
}
