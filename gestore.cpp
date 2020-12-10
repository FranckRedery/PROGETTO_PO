#include "gestore.h"

void Gestore::aggiungi_autore(QString n, QString c, int id, QList<QString> a){

    Autore* nuovo = new Autore(n,c,id,a);
    autori.push_back(nuovo);

}

void Gestore::aggiungi_conferenza(QString n, QString a, QString d, QString l, int num, QList<QString> o){

    Pubblicazione* conf = new Conferenza(n,a,d,l,num,o);
    pubblicazioni.push_back(conf);

}

void Gestore::aggiungi_rivista(QString n, QString a, QString d, QString e, int v){

    Pubblicazione* riv = new Rivista(n,a,d,e,v);
    pubblicazioni.push_back(riv);

}

void Gestore::aggiungi_articolo(int id, int n, double p, QString t, Pubblicazione* pub, QList<int> corr, QList<Autore*> aut, QList<QString> key){

    Articolo* art = new Articolo(id,n,p,t,pub,corr,aut,key);
    articoli.push_back(art);

}

void Gestore::cancella_tutti_autori(){
    for(auto& it : autori){
        delete it;
    }
    autori.clear();
}

void Gestore::cancella_tutti_articoli(){
    for(auto& it : articoli){
        delete it;
    }
    articoli.clear();
}

void Gestore::cancella_tutte_pubblicazioni(){
    for(auto& it : pubblicazioni){
        delete it;
    }
    pubblicazioni.clear();
}

Gestore::~Gestore(){
    cancella_tutti_autori();
    cancella_tutte_pubblicazioni();
    cancella_tutti_articoli();
}

Gestore::Gestore(const Gestore& g){

    for(auto& i : g.pubblicazioni){
        pubblicazioni.push_back(i->clone());
    }
    for(auto& i : g.articoli){
         articoli.push_back(i);
    }
    for(auto& i : g.autori){
        autori.push_back(i);
    }

}

Gestore& Gestore::operator=(const Gestore &g){
    if(this != &g){
       cancella_tutte_pubblicazioni();
       cancella_tutti_articoli();
       cancella_tutti_autori();
       for(auto& i : g.articoli){
            articoli.push_back(i);
       }
       for(auto& i : g.autori){
           autori.push_back(i);
       }
       for(auto& i : g.pubblicazioni){
           pubblicazioni.push_back(i->clone());
       }
    }
    return * this;
}

bool Gestore::Is_ID_autore_alreadytaken(int id) const {
    for(auto& i : autori){
        if(i->get_id() == id){
            return true;
        }
    }
    return false;
}

Pubblicazione* Gestore::get_pubblicazione(QString nome) const {
    for(auto& i : pubblicazioni){
        if(i->get_nome() == nome){
            return i;
        }
    }
    return nullptr;
}

bool Gestore::Is_Nome_pubblicazione_alreadytaken(QString nome) const {
    for(auto& i : pubblicazioni){
        if(i->get_nome() == nome){
            return true;
        }
    }
    return false;
}

Autore* Gestore::get_autore(int id) const{
    for(auto& i : autori){
        if(i->get_id() == id){
            return i;
        }
    }
    return nullptr;
}

bool Gestore::Is_ID_articolo_alreadytaken(int id) const{
    for(auto& i : articoli){
        if(i->get_identificativo() == id){
            return true;
        }
    }
    return false;
}
