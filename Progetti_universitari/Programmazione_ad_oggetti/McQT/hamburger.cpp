#include "hamburger.h"

Hamburger::Hamburger(int q):Panino("Hamburger",q){
    Prodotto p("Pane",0.5,1);
    Prodotto h("Hamburger",1,1);
    Prodotto i("Insalata",0.2,1);
    Prodotto po("Pomodoro",0.2,1);
    Prodotto s("Sotto Aceti",0.1,1);
    Panino::aggiungiProdotto(s);
    Panino::aggiungiProdotto(po);
    Panino::aggiungiProdotto(i);
    Panino::aggiungiProdotto(h);
    Panino::aggiungiProdotto(p);
}

void Hamburger::aggiungiProdotto(const Prodotto & prod){
    Prodotto i("Insalata",0.2,1);
    Prodotto po("Pomodoro",0.2,1);
    Prodotto s("Sotto Aceti",0.1,1);
    bool trovato=false;
    if(prod==i || prod== po || prod==s){
        for(iteratore i=begin();i!=end();i++){
            if(prod==(*this)[i]){
                trovato=true;
                if(prod.getQuantita()>1){
                    if((*this)[i].getQuantita()>1) std::cout<<"Non puoi aggiungere ulteriore prodotto"<<std::endl;
                        if((*this)[i].getQuantita()==1) {
                            Prodotto y(prod.getNome(),prod.getPrezzoBase(),1);
                            Panino::aggiungiProdotto(y);
                        }
                    }
                    if(prod.getQuantita()==1){
                        if((*this)[i].getQuantita()>1) std::cout<<"Non puoi aggiungere ulteriore prodotto"<<std::endl;
                        if((*this)[i].getQuantita()==1) Panino::aggiungiProdotto(prod);
                    }
            }
        }
        if(trovato==false) {
            if(prod.getQuantita()>2){
                Prodotto k(prod.getNome(),prod.getPrezzoBase(),2);
                Panino::aggiungiProdotto(k);
            }
            else Panino::aggiungiProdotto(prod);
            }
        }
        else std::cout<<"Non puoi aggiungere "<<prod.getNome()<<std::endl;
}

void Hamburger::rimuoviProdotto(const Prodotto & prod){
    Prodotto x("Pane",0.3,1);
    Prodotto y("Hamburger",1,1);
    if(prod==x || prod==y) std::cout<<"Non puoi rimuovere "<<prod.getNome()<<std::endl;
    else Panino::rimuoviProdotto(prod);
}

double Hamburger::prezzoAlPezzo() const{
    return Panino::prezzoAlPezzo()-0.1*Panino::prezzoAlPezzo();
}

std::ostream& operator<<(std::ostream& os, const Hamburger& p){
    os<<p.getNome()<<" Sconto:10%";
    int spazimancanti=30-11-p.getNome().size();
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

