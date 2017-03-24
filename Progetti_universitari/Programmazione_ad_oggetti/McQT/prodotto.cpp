#include "prodotto.h"

Prodotto::Prodotto(std::string n, double p,int q):nome(n),prezzoBase(p),quantita(q){
    if(prezzoBase<0.01) prezzoBase=0.01;
    if(quantita<1) quantita=1;
}

Prodotto::~Prodotto(){}

std::string Prodotto::getNome() const{return nome;}

void Prodotto::setNome(std::string n){
    nome=n;
}

double Prodotto::getPrezzoBase() const{return prezzoBase;}

int Prodotto::getQuantita() const{return quantita;}

void Prodotto::setQuantita(int p){
    quantita=p;
}

void Prodotto::sommaQuantita(const Prodotto & prod){
    if(*this==prod){
        quantita += prod.quantita;
    }
}

void Prodotto::togliQuantita(const Prodotto & prod){
    if(*this==prod){
        quantita -= prod.quantita;
        if(quantita<0) quantita=0;
    }
}

double Prodotto::calcolaPrezzo() const{
    return prezzoBase*quantita;
}

bool Prodotto::operator ==(const Prodotto& prod) const{
    if(nome==prod.nome && prezzoBase==prod.prezzoBase) return true;
    else return false;
}

bool Prodotto::operator !=(const Prodotto& prod) const{
    if(nome==prod.nome && prezzoBase==prod.prezzoBase) return false;
    else return true;
}

std::ostream& operator<<(std::ostream& os, const Prodotto& p){
    os<<p.getNome();
    int spaziMancanti=20-p.getNome().size();
    for(int i=0; i<spaziMancanti;i++) os<<" ";
    if(p.getQuantita()<10) os<<"|0";
    else os<<"|";
    os<<p.getQuantita()<<"|";
    if(p.getPrezzoBase()<100){
        if(p.getPrezzoBase()<10) os<<"  ";
        else os<<" ";
    }
    os<<p.getPrezzoBase();
    double resto=p.getPrezzoBase();
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
    for(int i=0;i<40;i++)os<<"-";
    os<<std::endl;

    return os;
}


