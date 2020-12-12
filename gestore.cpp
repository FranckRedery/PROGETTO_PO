#include "gestore.h"
#include <algorithm>

void Gestore::aggiungi_autore(QString n, QString c, int id, list<QString> a){

    Autore* nuovo = new Autore(n,c,id,a);
    autori.push_back(nuovo);

}

void Gestore::aggiungi_conferenza(QString n, QString a, QString d, QString l, int num, list<QString> o){

    Pubblicazione* conf = new Conferenza(n,a,d,l,num,o);
    pubblicazioni.push_back(conf);

}

void Gestore::aggiungi_rivista(QString n, QString a, QString d, QString e, int v){

    Pubblicazione* riv = new Rivista(n,a,d,e,v);
    pubblicazioni.push_back(riv);

}

void Gestore::aggiungi_articolo(int id, int n, double p, QString t, Pubblicazione* pub, list<int> corr, list<Autore*> aut, list<QString> key){

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

void Gestore::get_articoli_autore(int id, list<Articolo*>& lista) const {           // SEZIONE B METODO 1

    list<int> id_da_controllare;

    for(auto& i : articoli){
        id_da_controllare = i->get_id_autori();
        id_da_controllare.sort();
        id_da_controllare.unique();         // nel caso ci fossero ID duplicati di autori nell'articolo li rendo unici
        for(auto& j : id_da_controllare){
            if(j == id){                        // SE TRA GLI ID DA CONTROLLARE TROVO QUELLO CHE CERCO , PUSHO NELLA LISTA L'ARTICOLO
                lista.push_back(i);
            }
        }
    }
}

void Gestore::get_articoli_conferenza_or_rivista(QString nome, list<Articolo *> &lista) const{      // SEZIONE B METODO 4 E 5 (FUNZIONA PER ENTRAMBI)

    for(auto& i : articoli){
        if(i->get_pubblicazione()->get_nome() == nome){
            lista.push_back(i);
        }
    }
}

void Gestore::get_articoli_autore_prezzo_max_or_min(int id, list<Articolo *> &lista, int scelta) const{ // SEZIONE C METODO 1 E 2 (FUNZIONA PER ENTRAMBI INSERENDO IL TIPO DI SCELTA)

    list<Articolo*> articoli_autore;
    get_articoli_autore(id,articoli_autore); // trovo tutti gli articoli di quell'autore

    int max = INT_MIN ,  min = INT_MAX;

    for(auto& i : articoli_autore){             // trovo il prezzo max e min degli articoli dell'autore
        if(i->get_prezzo() > max){
            max = i->get_prezzo();
        }
        if(i->get_prezzo()< min){
            min = i->get_prezzo();
        }
    }
    if(scelta == 1){                        // se la scelta è la numero 1 , restituisco gli articoli con il prezzo più basso
        for(auto& i : articoli_autore){
            if(i->get_prezzo() == min){
                lista.push_back(i);
            }
        }
    }
    else if(scelta == 2){                    // se la scelta è la 2, restituisco gli articoli con il prezzo più alto
        for(auto& i : articoli_autore){
            if(i->get_prezzo() == max){
                lista.push_back(i);
            }
        }
    }
}

void Gestore::get_keywords_guadagno_max(list<QString> &lista) const{            // SEZIONE C METODO 6

    list<QString> keywords;
    list<QString> nuove_key;
    for(auto& i : articoli){
        nuove_key = i->get_keywords();
        for(auto& j : nuove_key){
            keywords.push_back(j);                      // prendo le keyword di tutti gli articoli
        }
    }
    keywords.sort();
    keywords.unique();                                  // se ci sono duplicati li elimino

    vector<double> valore_key;                          // utilizzo un vector di double per conservare i prezzi totali degli articoli contenenti quella keyword
    valore_key.resize(keywords.size());

    double max = INT_MIN;
    auto it = keywords.begin();

    for(int i = 0 ; i!=valore_key.size();i++){
        for(auto& j : articoli){
            nuove_key = j->get_keywords();
            if(find(nuove_key.begin(),nuove_key.end(),*it) != nuove_key.end()){
                valore_key[i] += j->get_prezzo();
            }
        }
    if(valore_key[i] > max){                                                    // SE TROVO UN VALORE PIù GRANDE DI PREZZO PULISCO LA LISTA E INSERISCO LA NUOVA KEYWORD
        max = valore_key[i];
        lista.clear();
        lista.push_back(*it);
    }
    else if(valore_key[i] == max){                                              // SE TROVO UN VALORE UGUALE DI PREZZO INSERISCO ANCHE QUESTA KEY
        lista.push_back(*it);
    }
    it++;
    }
}
