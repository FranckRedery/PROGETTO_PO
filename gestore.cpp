#include "gestore.h"
#include <algorithm>
#include <iostream>

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

    double max = INT_MIN ,  min = INT_MAX;

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
            if(find(nuove_key.begin(),nuove_key.end(),*it) != nuove_key.end()){         // se la keyword corrispondente alla posizione del vector dei prezzi è presente nell'articolo, aggiungo il prezzo dell'articolo al totale
                valore_key[i] += j->get_prezzo();
            }
        }

     if(valore_key[i] == max){                                              // SE TROVO UN VALORE UGUALE DI PREZZO INSERISCO ANCHE QUESTA KEY
            lista.push_back(*it);
        }
    else if(valore_key[i] > max){                                                    // SE TROVO UN VALORE PIù GRANDE DI PREZZO PULISCO LA LISTA E INSERISCO LA NUOVA KEYWORD
        max = valore_key[i];
        lista.clear();
        lista.push_back(*it);
    }
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


void Gestore::articoli_autore_sorted(int id, list<Articolo *> &lista) const {       // SEZIONE D METODO 6

    get_articoli_autore(id,lista);                                          // per prima cosa prendo tutti gli articoli dell'autore
    lista.sort(sort_autore);                                                // dopo li ordino
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

void Gestore::articoli_keyword_sorted(QString key, list<Articolo*> &lista) const{      // SEZIONE D METODO 5

    get_articoli_keyword(key,lista);
    lista.sort(sort_key);
}

void Gestore::get_articoli_keyword(QString key, list<Articolo*> &lista) const{

    list<QString> key_da_controllare;
    for(auto& i : articoli){
        key_da_controllare = i->get_keywords();
        key_da_controllare.sort();
        key_da_controllare.unique();         // nel caso ci fossero keywords duplicate nell'articolo le rendo uniche
        for(auto& j : key_da_controllare){
            if(j == key){                        // se tra le keywords da controllare trovo quella che cerco , pusho nella lista l'articolo.
                lista.push_back(i);
            }
        }
    }
}

void Gestore::get_5_most_common_key(list<QString> &chiavi) const{       // SEZIONE E METODO 3

    list<QString> contenitore_chiavi;
    list<QString> nuove_chiavi;

    for(auto& i : articoli){
        nuove_chiavi = i->get_keywords();               // prendo le key di ogni articolo
        nuove_chiavi.sort();
        nuove_chiavi.unique();                          // nel caso ci fossero keywords duplicate nell'articolo le rendo uniche (presumo che un articolo non debba avere keyword duplicate)
        for(auto& j : nuove_chiavi){
            contenitore_chiavi.push_back(j);            // le conservo tutte nel contenitore
        }
        nuove_chiavi.clear();
    }

    vector<int> quant;                               // qui vedo quante volte la chiave è presente
    quant.resize(contenitore_chiavi.size());
    int ind = 0, max = INT_MIN;

    for(auto& i : contenitore_chiavi){
        for(auto& j : contenitore_chiavi){
            if(i == j){
                quant[ind]++;                       // se le key sono uguali aumenta la quantità contenuta
            }
        }
    if(quant[ind] > max){                           // trovo il max tra le occorrenze di una chiave
        max = quant[ind];
    }
    ind++;
    }

    auto it = contenitore_chiavi.begin();

    while(chiavi.size()!=5 && max != 0 && max!=INT_MIN){          // esco dal while se trovo 5 chiavi oppure se il max scende a 0 dunque non ci sono più chiavi da controllare
                                                                   // aggiunto come condizione max!=INT_MIN perché se non erano presenti chiavi si genereva un loop infinito
        for(int i = 0 ; i<quant.size();i++){
            if(quant[i] == max && find(chiavi.begin(),chiavi.end(),*it) == chiavi.end()){       // se la chiave corrispondente alla pos è uguale al max e non è presente la aggiungo
                chiavi.push_back(*it);

                if(chiavi.size() == 5){
                    break;
                }
            }
            it++;
        }
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

void Gestore::get_conferenze_simili(QString nome, list<Pubblicazione*> &lista) const{       // SEZIONE F METODO 5

    list<QString> key;
    list<QString> nuove_key;
    // in questo for prendo tutte le chiavi relative alla conferenza scelta da input
    for(auto& i : articoli){
        if(i->get_pubblicazione()->get_nome() == nome && i->get_pubblicazione()->is_conferenza()){
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
            QString nome_conf = i->get_pubblicazione()->get_nome();
            for(auto & j : articoli){
                if(j->get_pubblicazione()->get_nome() == nome_conf){
                    nuove_key = j->get_keywords();
                    for(auto& k: nuove_key){
                        key_seconda_conf.push_back(k);
                    }
                }
            }
            key_seconda_conf.sort();
            key_seconda_conf.unique();

            // faccio l'unione delle key delle due conferenze e anche l'intersezione
            //dopodiché faccio size di intersezione / size di unione , se è >=0,8 aggiungo alla lista la pubblicazione

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
