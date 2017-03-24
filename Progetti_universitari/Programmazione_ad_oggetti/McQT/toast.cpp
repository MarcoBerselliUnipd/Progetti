#include "toast.h"

Toast::Toast(int q):Panino("Toast",q){
    Prodotto p("Pane Tostato",0.5,1);
    Prodotto pr("Prosciutto Cotto",0.3,1);
    Prodotto f("Sottiletta",0.2,1);
    Panino::aggiungiProdotto(p);
    Panino::aggiungiProdotto(pr);
    Panino::aggiungiProdotto(f);
}

void Toast::aggiungiProdotto(const Prodotto & prod){
    Prodotto pr("Prosciutto Cotto",0.3,1);
    Prodotto f("Sottiletta",0.2,1);
    Prodotto sf("Salsa ai Funghi",0.1,1);
    bool trovato=false;
    if(prod==pr || prod==f || prod==sf){
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

void Toast::rimuoviProdotto(const Prodotto & prod){
    Prodotto p("Pane Tostato",0.5,1);
    Prodotto pr("Prosciutto Cotto",0.3,1);
    Prodotto f("Sottiletta",0.2,1);
    Prodotto sf("Salsa ai Funghi",0.1,1);
    if(prod==p) std::cout<<"Non puoi rimuovere "<<prod.getNome()<<std::endl;
    else{
        if(prod==pr || prod==f){
           for(iteratore it=begin();it!=end();it++){
               if((*this)[it]==prod){
                   if((*this)[it].getQuantita()==1){
                       if(prod.getQuantita()>0) std::cout<<"Non puoi rimuovere ulteriore prodotto"<<std::endl;
                   }
                   if((*this)[it].getQuantita()==2){
                       if(prod.getQuantita()==1) Panino::rimuoviProdotto(prod);
                       if(prod.getQuantita()>1){
                           Prodotto z(prod.getNome(),prod.getPrezzoBase(),1);
                           Panino::rimuoviProdotto(z);
                       }
                   }
               }
           }
        }
        else Panino::rimuoviProdotto(prod);
    }
}

double Toast::prezzoAlPezzo() const{
    return Panino::prezzoAlPezzo()-0.1*Panino::prezzoAlPezzo();
}

std::ostream& operator<<(std::ostream& os, const Toast& p){
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

