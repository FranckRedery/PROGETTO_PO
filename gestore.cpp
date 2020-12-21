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


#include "gestore.h"
#include <algorithm>
#include <iostream>

void Gestore::aggiungi_autore(QString n, QString c, int id, std::list<QString> a){

    Autore* nuovo = new Autore(n,c,id,a);
    autori.push_back(nuovo);

}

void Gestore::aggiungi_conferenza(int id, QString n, QString a, QString d, QString l, int num, std::list<QString> o){

    Pubblicazione* conf = new Conferenza(id,n,a,d,l,num,o);
    pubblicazioni.push_back(conf);

}

void Gestore::aggiungi_rivista(int id,QString n, QString a, QString d, QString e, int v){

    Pubblicazione* riv = new Rivista(id,n,a,d,e,v);
    pubblicazioni.push_back(riv);

}

void Gestore::aggiungi_articolo(int id, int n, double p, QString t, Pubblicazione* pub, std::list<int> corr, std::list<Autore*> aut, std::list<QString> key){

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

//triade delete, costruttore copia, operator =

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

// se l'id è stato preso ritorna true, altrimenti false
bool Gestore::Is_ID_autore_alreadytaken(int id) const {
    for(auto& i : autori){
        if(i->get_id() == id){
            return true;
        }
    }
    return false;
}

Pubblicazione* Gestore::get_pubblicazione(int id) const {
    for(auto& i : pubblicazioni){
        if(i->get_id() == id){
            return i;
        }
    }
    return nullptr;
}

bool Gestore::Is_ID_pubblicazione_alreadytaken(int id) const {
    for(auto& i : pubblicazioni){
        if(i->get_id() == id){
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

// se l'id è stato preso ritorna true altrimenti false
bool Gestore::Is_ID_articolo_alreadytaken(int id) const{
    for(auto& i : articoli){
        if(i->get_identificativo() == id){
            return true;
        }
    }
    return false;
}

// SEZIONE B METODO 1
void Gestore::get_articoli_autore(int id, std::list<Articolo*>& lista) const {

    std::list<int> id_da_controllare;

    for(auto& i : articoli){
        id_da_controllare = i->get_id_autori();

        // nel caso ci fossero ID duplicati di autori nell'articolo li rendo unici
        id_da_controllare.sort();
        id_da_controllare.unique();
        for(auto& j : id_da_controllare){
            // SE TRA GLI ID DA CONTROLLARE TROVO QUELLO CHE CERCO , PUSHO NELLA LISTA L'ARTICOLO
            if(j == id){
                lista.push_back(i);
            }
        }
    }
}

// SEZIONE B METODO 4 E 5 (FUNZIONA PER ENTRAMBI)
void Gestore::get_articoli_conferenza_or_rivista(int id, std::list<Articolo *> &lista) const{

    for(auto& i : articoli){
        if(i->get_pubblicazione()->get_id() == id){
            lista.push_back(i);
        }
    }
}

// SEZIONE C METODO 1 E 2 (FUNZIONA PER ENTRAMBI INSERENDO IL TIPO DI SCELTA)
// Scegliendo 1 si prendono gli articoli con prezzo min , scegliendo 2 quelli con prezzo max
void Gestore::get_articoli_autore_prezzo_max_or_min(int id, std::list<Articolo *> &lista, int scelta) const{

    std::list<Articolo*> articoli_autore;

     // trovo tutti gli articoli di quell'autore
    get_articoli_autore(id,articoli_autore);

    double max = INT_MIN ,  min = INT_MAX;

    // trovo il prezzo max e min degli articoli dell'autore
    for(auto& i : articoli_autore){
        if(i->get_prezzo() > max){
            max = i->get_prezzo();
        }
        if(i->get_prezzo()< min){
            min = i->get_prezzo();
        }
    }
    if(scelta == 1){
        for(auto& i : articoli_autore){
            if(i->get_prezzo() == min){
                lista.push_back(i);
            }
        }
    }
    else if(scelta == 2){
        for(auto& i : articoli_autore){
            if(i->get_prezzo() == max){
                lista.push_back(i);
            }
        }
    }
}

// SEZIONE C METODO 6
void Gestore::get_keywords_guadagno_max(std::list<QString> &lista) const{

    std::list<QString> keywords;
    std::list<QString> nuove_key;

      // prendo le keyword di tutti gli articoli
    for(auto& i : articoli){
        nuove_key = i->get_keywords();
        for(auto& j : nuove_key){
            keywords.push_back(j);
        }
    }
    // se ci sono duplicati li elimino
    keywords.sort();
    keywords.unique();

    // utilizzo un vector di double per conservare i prezzi totali degli articoli contenenti quella keyword
    // il suo size deve essere uguale a quelle delle keyword
    std::vector<double> valore_key;
    valore_key.resize(keywords.size());

    double max = INT_MIN;
    auto it = keywords.begin();

    // se la keyword corrispondente alla posizione del vector dei prezzi è presente nell'articolo, aggiungo il prezzo dell'articolo al totale
    for(unsigned int i = 0 ; i!=valore_key.size();i++){
        for(auto& j : articoli){
            nuove_key = j->get_keywords();
            if(find(nuove_key.begin(),nuove_key.end(),*it) != nuove_key.end()){
                valore_key[i] += j->get_prezzo();
            }
        }
    // SE TROVO UN VALORE UGUALE DI PREZZO INSERISCO ANCHE QUESTA KEY
     if(valore_key[i] == max){
            lista.push_back(*it);
        }
     // SE TROVO UN VALORE PIù GRANDE DI PREZZO PULISCO LA LISTA E INSERISCO LA NUOVA KEYWORD
    else if(valore_key[i] > max){
        max = valore_key[i];
        lista.clear();
        lista.push_back(*it);
    }
    // come si incrementa l'indice dei guadagni nel vector bisogna incrementare anche l'iteratore che corrisponde alla parola relativa a quell'indice
    it++;
    }
}

bool sort_prezzo(const Articolo* a , const Articolo* b){
    if(a->get_prezzo() > b->get_prezzo()){
        return false;
    }
    return true;
}

// SEZIONE D METODO 2 , prendo gli articoli dell'autore e li ordino per prezzo
void Gestore::articoli_autore_sorted_anno(int id, std::list<Articolo *> &lista) const{
    get_articoli_autore(id,lista);
    lista.sort(sort_prezzo);
}

bool sort_autore(const Articolo* a , const Articolo* b){
    if(a->get_pubblicazione()->get_data() > b->get_pubblicazione()->get_data()){
        return false;
    }
    else if(a->get_prezzo() < b->get_prezzo() && a->get_pubblicazione()->get_data() == b->get_pubblicazione()->get_data()){
        return false;
    }
    else if(a->get_prima_key() > b->get_prima_key() && a->get_pubblicazione()->get_data() == b->get_pubblicazione()->get_data() && a->get_prezzo() == b->get_prezzo()){
        return false;
    }
    return true;
}

// SEZIONE D METODO 6, prendo gli articoli dell'autore e li ordino secondo i criteri
void Gestore::articoli_autore_sorted(int id, std::list<Articolo *> &lista) const {

    get_articoli_autore(id,lista);
    lista.sort(sort_autore);
}

void Gestore::get_articoli_keyword(QString key, std::list<Articolo*> &lista) const{

    std::list<QString> key_da_controllare;
    for(auto& i : articoli){
        key_da_controllare = i->get_keywords();
         // nel caso ci fossero keywords duplicate nell'articolo le rendo uniche
        key_da_controllare.sort();
        key_da_controllare.unique();
        for(auto& j : key_da_controllare){
            // se tra le keywords da controllare trovo quella che cerco , pusho nella lista l'articolo.
            if(j == key){
                lista.push_back(i);
            }
        }
    }
}

void Gestore::get_all_keyword_by_ID(int id, std::list<QString> &lista) const{

    std::list<QString> nuove_key;
    for(auto& i : articoli){
        if(i->get_pubblicazione()->get_id() == id){
            nuove_key = i->get_keywords();
            for(auto& j : nuove_key){
                lista.push_back(j);
            }
        }
    }
    lista.sort();
    lista.unique();
}

bool Gestore::sottoinsieme(std::list<QString> &first, std::list<QString> &second) const{

    int cont = 0 ;
    for(auto& i : first){
        for(auto& j : second){
            if(i == j){
                cont++;
            }
        }
        if(cont == 0){
            return false;
        }
        cont = 0;
    }
    return true;
}

//SEZIONE E METODO 6
void Gestore::get_riviste_specialistiche(std::list<Pubblicazione *> &lista) const{

    std::list<QString> key;
    std::list<QString> key_seconda;

    //prendo tutte le keyword per l'id di quell'articolo
    for(auto& i : articoli){
        if(i->get_pubblicazione()->is_conferenza() == false){
            get_all_keyword_by_ID(i->get_pubblicazione()->get_id(),key);
        }
        // prendo tutte le keyword per l'id di un  altro articolo che sia diverso da quello di prima
        for(auto& j : articoli){
            if(j->get_pubblicazione()->is_conferenza() == false && j->get_pubblicazione()->get_id() != i->get_pubblicazione()->get_id()){

                get_all_keyword_by_ID(j->get_pubblicazione()->get_id(),key_seconda);

                //verifico se le key del primo sono un sottoinsieme del secondo e non ho già pushato nella lista l'articolo
                if(sottoinsieme(key,key_seconda) && find(lista.begin(),lista.end(),i->get_pubblicazione()) == lista.end()){
                    lista.push_back(i->get_pubblicazione());
                }
            }
            key_seconda.clear();
        }
    key.clear();
    }


}


std::list<QString> get_key_comuni(std::list<QString>& a, std::list<QString>& b){

    std::list<QString> comuni;
    // se trovo chiavi comuni che non sono presente nella list comuni le aggiungo
    for(auto& i : a){
        for(auto& j : b){
            if(i == j && find(comuni.begin(),comuni.end(),i) == comuni.end()){
                comuni.push_back(i);
            }
        }
    }
    comuni.sort();
    comuni.unique();
    return  comuni;
}

std::list<QString> get_key_unione(std::list<QString>& a, std::list<QString>& b){

    std::list<QString> unione = a;
    for(auto& i : b){
        unione.push_back(i);
    }
    unione.sort();
    unione.unique();
    return unione;

}

// SEZIONE F METODO 5
void Gestore::get_conferenze_simili(int id, std::list<Pubblicazione*> &lista) const{

    std::list<QString> key;
    std::list<QString> nuove_key;

    // in questo for prendo tutte le chiavi relative alla conferenza scelta da input
    for(auto& i : articoli){
        if(i->get_pubblicazione()->get_id() == id && i->get_pubblicazione()->is_conferenza() == true){
            get_all_keyword_by_ID(i->get_pubblicazione()->get_id(),key);
        }
    }

    std::list<QString> key_comuni;
    std::list<QString> key_seconda_conf;
    std::list<QString> key_unione;

    // assumo che una conferenza uguale a se stessa sia anche simile quindi voglio visualizzare anche quella scelta
    for(auto& i : articoli){

        key_seconda_conf.clear();
        key_comuni = key;

        // se trovo un altra pubblicazione che è una conferenza prendo tutte le keywords di quella conferenza

        if(i->get_pubblicazione()->is_conferenza()){
            get_all_keyword_by_ID(i->get_pubblicazione()->get_id(),key_seconda_conf);

            // faccio l'unione delle key delle due conferenze e anche l'intersezione
            //dopodiché faccio size di intersezione / size di unione , se è >=0,8 aggiungo alla lista di quelle comuni la pubblicazione attuale

            key_unione = get_key_unione(key_comuni,key_seconda_conf);
            key_comuni = get_key_comuni(key_comuni,key_seconda_conf);
            if(static_cast<double>(key_comuni.size())/key_unione.size() >= 0.8){
                lista.push_back(i->get_pubblicazione());
            }
        }
    }
}


// metodo per avere l'id automatico quando si va ad inserire un autore da file
// restituisce il primo id libero per un autore
int Gestore::get_first_free_id_autore() const{
    int id = 1;
    while(Is_ID_autore_alreadytaken(id)){
        id++;
    }
    return id;
}

// metodo per avere l'id automatico quando si insersice un articolo
// restituisce il primo id libero per un articolo
int Gestore::get_first_free_id_articolo() const{
    int id = 1;
    while(Is_ID_articolo_alreadytaken(id)){
        id++;
    }
    return id;
}

int Gestore::get_first_free_id_pubblicazione() const {
    int id = 1;
    while(Is_ID_pubblicazione_alreadytaken(id)){
        id++;
    }
    return id;
}

bool Gestore::is_pubblicazione_unique(QString data, QString nome, bool is_conf) const{
    for(auto& i : pubblicazioni){
        if(i->get_data() == data && i->get_nome() == nome && i->is_conferenza() == is_conf){
            return false;
        }
    }
    return true;
}
