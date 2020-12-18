#include "gestore.h"
#include <algorithm>
#include <iostream>

void Gestore::aggiungi_autore(QString n, QString c, int id, list<QString> a){

    Autore* nuovo = new Autore(n,c,id,a);
    autori.push_back(nuovo);

}

void Gestore::aggiungi_conferenza(int id, QString n, QString a, QString d, QString l, int num, list<QString> o){

    Pubblicazione* conf = new Conferenza(id,n,a,d,l,num,o);
    pubblicazioni.push_back(conf);

}

void Gestore::aggiungi_rivista(int id,QString n, QString a, QString d, QString e, int v){

    Pubblicazione* riv = new Rivista(id,n,a,d,e,v);
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
void Gestore::get_articoli_autore(int id, list<Articolo*>& lista) const {

    list<int> id_da_controllare;

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
void Gestore::get_articoli_conferenza_or_rivista(int id, list<Articolo *> &lista) const{

    for(auto& i : articoli){
        if(i->get_pubblicazione()->get_id() == id){
            lista.push_back(i);
        }
    }
}

// SEZIONE C METODO 1 E 2 (FUNZIONA PER ENTRAMBI INSERENDO IL TIPO DI SCELTA)
// Scegliendo 1 si prendono gli articoli con prezzo min , scegliendo 2 quelli con prezzo max
void Gestore::get_articoli_autore_prezzo_max_or_min(int id, list<Articolo *> &lista, int scelta) const{

    list<Articolo*> articoli_autore;

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
void Gestore::get_keywords_guadagno_max(list<QString> &lista) const{

    list<QString> keywords;
    list<QString> nuove_key;

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
    vector<double> valore_key;
    valore_key.resize(keywords.size());

    double max = INT_MIN;
    auto it = keywords.begin();

    // se la keyword corrispondente alla posizione del vector dei prezzi è presente nell'articolo, aggiungo il prezzo dell'articolo al totale
    for(int i = 0 ; i!=valore_key.size();i++){
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
void Gestore::articoli_autore_sorted(int id, list<Articolo *> &lista) const {

    get_articoli_autore(id,lista);
    lista.sort(sort_autore);
}

bool sort_key(const Articolo* a, const Articolo* b){
    if(a->get_pubblicazione()->get_data() < b->get_pubblicazione()->get_data()){
        return false;
    }
    else if(a->get_prezzo() > b->get_prezzo() && a->get_pubblicazione()->get_data() == b->get_pubblicazione()->get_data()){
        return false;
    }
    else if(a->get_primo_cognome_autore() > b->get_primo_cognome_autore() && a->get_prezzo() == b->get_prezzo() && a->get_pubblicazione()->get_data() == b->get_pubblicazione()->get_data()){
        return false;
    }
    return true;
}

// SEZIONE D METODO 5 prendo gli articoli con quella keyword e li ordino secondo i criteri
void Gestore::articoli_keyword_sorted(QString key, list<Articolo*> &lista) const{

    get_articoli_keyword(key,lista);
    lista.sort(sort_key);
}

void Gestore::get_articoli_keyword(QString key, list<Articolo*> &lista) const{

    list<QString> key_da_controllare;
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

// SEZIONE E METODO 3
void Gestore::get_5_most_common_key(list<QString> &chiavi) const{

    list<QString> contenitore_chiavi;
    list<QString> nuove_chiavi;

     // prendo le key di ogni articolo
    for(auto& i : articoli){
        nuove_chiavi = i->get_keywords();

        // nel caso ci fossero keywords duplicate nell'articolo le rendo uniche  e le conservo nel contenitore
        nuove_chiavi.sort();
        nuove_chiavi.unique();
        for(auto& j : nuove_chiavi){
            contenitore_chiavi.push_back(j);
        }
        nuove_chiavi.clear();
    }

    // uso questo vector per contare quante volte la chiave è presente
    vector<int> quant;
    quant.resize(contenitore_chiavi.size());
    int ind = 0, max = INT_MIN;

    // se le key sono uguali aumenta la quantità contenuta nel vector
    for(auto& i : contenitore_chiavi){
        for(auto& j : contenitore_chiavi){
            if(i == j){
                quant[ind]++;
            }
        }
    // allo stesso tempo trovo il max tra le occorrenze di una chiave
    if(quant[ind] > max){
        max = quant[ind];
    }
    ind++;
    }

    auto it = contenitore_chiavi.begin();

    // esco dal while se trovo 5 chiavi oppure se il max scende a 0 dunque non ci sono più chiavi da controllare
    // aggiunto come condizione max!=INT_MIN perché se non erano presenti chiavi si genereva un loop infinito
    while(chiavi.size()!=5 && max != 0 && max!=INT_MIN){
        for(int i = 0 ; i<quant.size();i++){

            // se la chiave corrispondente alla pos è uguale al max e non è presente la aggiungo
            // perché chiaramente nel contenitore che ho creato ci sono più chiavi uguali!
            if(quant[i] == max && find(chiavi.begin(),chiavi.end(),*it) == chiavi.end()){
                chiavi.push_back(*it);

                // se ne ho già trovato 5 esco dal for loop e di conseguenza dopo anche dal while
                if(chiavi.size() == 5){
                    break;
                }
            }
            it++;
        }
    //resetto l'iteratore all'inizio della lista per ogni iterazione che faccio nel while!
    it = contenitore_chiavi.begin();
    max--;
    }
}


list<QString> get_key_comuni(list<QString>& a, list<QString>& b){

    list<QString> comuni;
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

list<QString> get_key_unione(list<QString>& a, list<QString>& b){

    list<QString> unione = a;
    for(auto& i : b){
        unione.push_back(i);
    }
    unione.sort();
    unione.unique();
    return unione;

}

// SEZIONE F METODO 5
void Gestore::get_conferenze_simili(int id, list<Pubblicazione*> &lista) const{

    list<QString> key;
    list<QString> nuove_key;

    // in questo for prendo tutte le chiavi relative alla conferenza scelta da input
    for(auto& i : articoli){
        if(i->get_pubblicazione()->get_id() == id && i->get_pubblicazione()->is_conferenza()){
            nuove_key = i->get_keywords();
            for(auto& j: nuove_key){
                key.push_back(j);
            }
        }
    }
    key.sort();
    key.unique();

    list<QString> key_comuni;
    list<QString> key_seconda_conf;
    list<QString> key_unione;

    // assumo che una conferenza uguale a se stessa sia anche simile quindi voglio visualizzare anche quella scelta
    for(auto& i : articoli){

        key_seconda_conf.clear();
        key_comuni = key;

        // se trovo un altra pubblicazione che è una conferenza prendo tutte le keywords di quella conferenza

        if(i->get_pubblicazione()->is_conferenza()){
            int id_conf = i->get_pubblicazione()->get_id();
            for(auto & j : articoli){
                if(j->get_pubblicazione()->get_id() == id_conf){
                    nuove_key = j->get_keywords();
                    for(auto& k: nuove_key){
                        key_seconda_conf.push_back(k);
                    }
                }
            }
            key_seconda_conf.sort();
            key_seconda_conf.unique();

            // faccio l'unione delle key delle due conferenze e anche l'intersezione
            //dopodiché faccio size di intersezione / size di unione , se è >=0,8 aggiungo alla lista di quelle comuni la pubblicazione attuale

            key_unione = get_key_unione(key_comuni,key_seconda_conf);
            key_comuni = get_key_comuni(key_comuni,key_seconda_conf);
            if(static_cast<double>(key_comuni.size())/key_unione.size() >= 0.8){
                lista.push_back(i->get_pubblicazione());
            }
        }
    }
    lista.sort();
    lista.unique();
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
