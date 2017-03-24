#include "panino.h"

Panino::smartp::smartp(NodoProdotto* p):punto(p){
    if(punto) punto->riferimenti++;
}

Panino::smartp::smartp(const smartp& s):punto(s.punto){
    if(punto) punto->riferimenti++;
}

Panino::smartp::~smartp(){
    if(punto){
        punto->riferimenti--;
        if(punto->riferimenti==0){
            delete punto;
        }
    }
}

Panino::smartp& Panino::smartp::operator =(const smartp& s){
    if(this!=&s){
        NodoProdotto* t=punto;
        if(t) t->riferimenti++;
        if(punto) punto->riferimenti--;
        punto=s.punto;
        if(punto) punto->riferimenti++;
        if(t){
            t->riferimenti--;
            if(t->riferimenti==0)delete t;
        }
    }
    return *this;
}

Panino::NodoProdotto& Panino::smartp::operator *()const{
    return *punto;
}

Panino::NodoProdotto* Panino::smartp::operator ->()const{
    return punto;
}

bool Panino::smartp::operator==(const smartp& p)const{
    return punto==p.punto;
}

bool Panino::smartp::operator !=(const smartp& p)const{
    return punto!=p.punto;
}

Panino::NodoProdotto::NodoProdotto():riferimenti(0){}

Panino::NodoProdotto::NodoProdotto(const Prodotto& prod, const smartp& p):info(prod),next(p),riferimenti(0){}


bool Panino::iteratore::operator ==(const iteratore& i)const{
    return punt==i.punt;
}

bool Panino::iteratore::operator !=(const iteratore& i)const{
    return punt!=i.punt;
}
Panino::iteratore& Panino::iteratore::operator++(){
    if(punt!=0)punt=punt->next;
    return *this;
}

Panino::iteratore Panino::iteratore::operator++(int){
    iteratore aux =*this;
    if(punt!=0) punt=punt->next;
    return aux;
}


Panino::Panino(std::string n, int q):nome(n),quantita(q){
    if (quantita<1) quantita=1;
}

Panino::~Panino(){}

std::string Panino::getNome() const{
    return nome;
}

void Panino::setNome(std::string n){
    nome=n;
}

int Panino::getQuantita() const{
    return quantita;
}

void Panino::setQuantita(int i){
    quantita=i;
    if(quantita<0) quantita=0;
}

void Panino::sommaQuantita(const Panino& p){
    if(*this==p){
        quantita += p.quantita;
    }
}

void Panino::togliQuantita(const Panino& p){
    if(*this==p){
        quantita -= p.quantita;
        if(quantita<0) quantita=0;
    }
}

Prodotto& Panino::getProdotto(const Prodotto& p) const{
    for(iteratore it=begin();it!=end();it++){
        if((*this)[it]==p){
            return (*this)[it];
        }
    }
    throw 1;
}

void Panino::aggiungiProdotto(const Prodotto & prod){
    bool trovato=false;
    iteratore it=begin();
    if(it.punt==0) PrimoNodo=new NodoProdotto(prod,0);
    else{
        for(;it!=end();it++){
            if((*this)[it]==prod){
                (*this)[it].sommaQuantita(prod);
                trovato=true;
            }
        }
        if(trovato==false) PrimoNodo=new NodoProdotto(prod,PrimoNodo);
    }
}

void Panino::rimuoviProdotto(const Prodotto & prod){
    bool trovato=false;
    smartp first=PrimoNodo;
    smartp second=first;
    if(PrimoNodo==0)std::cout<<"La lista é vuota"<<std::endl;
    else{
        iteratore it=begin();
        if((*this)[it]==prod) {
            (*this)[it].togliQuantita(prod);
            if((*this)[it].getQuantita()==0) PrimoNodo=PrimoNodo->next;
        }
        else{
        for(;it!=end();it++){
            if((*this)[it]==prod) {
                trovato=true;
                (*this)[it].togliQuantita(prod);
            }
            if((*this)[it].getQuantita()==0){
                second->next=first->next;
            }
            second=first;
            first=first->next;
        }
        if(trovato==false) std::cout<<"Il Prodotto che vuoi rimuovere non è in lista"<<std::endl;
        }
    }
}

double Panino::prezzoAlPezzo() const{
    double x=0;
    for(Panino::iteratore it=begin(); it!= end(); it++){
        x = x + (*this)[it].calcolaPrezzo();
    }
    return x;
}

double Panino::calcolaPrezzo() const{
    return prezzoAlPezzo()*quantita;
}

void Panino::stampaDettaglio() const{
    for(iteratore it=begin();it!=end();it++){
        std::cout<<(*this)[it]<<std::endl;
    }
}




bool Panino::lunghezzaUguale(const Panino & pan, const Panino& panino){
    int count=0,count1=0;
    for(iteratore i=pan.begin();i!=pan.end();i++){
        count++;
    }
    for(iteratore e=panino.begin();e!=panino.end();e++){
        count1++;
    }
    return count==count1;
}

bool Panino::operator ==(const Panino& pan) const{
    if(getNome()==pan.getNome()){
        if(!(Panino::lunghezzaUguale(*this,pan))) return false;
        else{
            bool uguale=false;
            for(Panino::iteratore it=begin();it!=end();it++){
                for(Panino::iteratore it1=pan.begin();it1!=pan.end();it1++){
                   if((*this)[it]==pan[it1] && (*this)[it].getQuantita()==pan[it1].getQuantita()) {
                       uguale=true;
                   }
                }
                if(uguale==false) return false;
                uguale=false;
            }
            return true;
        }
    }
    else return false;

}

bool Panino::operator !=(const Panino& pan) const{
    if(getNome()==pan.getNome()){
        if(!(Panino::lunghezzaUguale(*this,pan))) return true;
        else{
            bool uguale=false;
            for(Panino::iteratore it=begin();it!=end();it++){
                for(Panino::iteratore it1=pan.begin();it1!=pan.end();it1++){
                   if((*this)[it]==pan[it1] && (*this)[it].getQuantita()==pan[it1].getQuantita()) {
                       uguale=true;
                   }
                }
                if(uguale==false) return true;
                uguale=false;
            }
            return false;
        }
    }
    else return true;
}


Panino::iteratore Panino::begin()const{
    iteratore aux;
    aux.punt=PrimoNodo;
    return aux;
}

Panino::iteratore Panino::end()const{
    iteratore aux;
    aux.punt=0;
    return aux;
}

Prodotto& Panino::operator [](const iteratore& it)const{
    return it.punt->info;
}

std::ostream& operator<<(std::ostream& os, const Panino& p){
    os<<"Panino a scelta:"<<p.getNome();
    int spazimancanti=30-16-p.getNome().size();
    for(int i=0;i<spazimancanti;i++) os<<" ";
    if(p.getQuantita()<10) os<<"|0";
    else os<<"|";
    os<<p.getQuantita()<<"|";
    if(p.prezzoAlPezzo()<100){
        if(p.prezzoAlPezzo()<10) os<<"  ";
        else os<<" ";
    }
    os<<p.prezzoAlPezzo();
    double resto=p.prezzoAlPezzo();
    while(resto>=1) resto=resto-1;
    if(resto==0) os<<".00";
    else{
        while(resto>=0.09) resto=resto-0.1;
        if(resto<0.01) os<<"0";
    }
    os<<"|";
    if(p.calcolaPrezzo()<100){
        if(p.calcolaPrezzo()<10) os<<"  ";
        else os<<" ";
    }
    os<<p.calcolaPrezzo();
    double resto1=p.calcolaPrezzo();
    while(resto1>=1) resto1=resto1-1;
    if(resto1==0) os<<".00";
    else{
        while(resto1>=0.09) resto1=resto1-0.1;
        if(resto1<0.01) os<<0;
    }
    os<<"|"<<std::endl;
    for(int i=0;i<48;i++)os<<"-";
    os<<std::endl;
    os<<"Dettaglio:            |Pz|Al pz.| TOT. |"<<std::endl;
    for(int i=0;i<40;i++)os<<"-";
    os<<std::endl;
    for(Panino::iteratore it=p.begin();it!=p.end();it++){
        os<<" -"<<p[it];
    }
    for(int i=0;i<48;i++)os<<"-";
    os<<std::endl;
    return os;
}
