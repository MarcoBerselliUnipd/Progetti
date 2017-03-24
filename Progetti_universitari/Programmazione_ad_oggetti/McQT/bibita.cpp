#include "bibita.h"

Bibita::Bibita(std::string n,double p,int q,std::string g):Prodotto(n,p,q),size(g){
    if(size!="S" && size!="M" && size!="L") size="S";
}

std::string Bibita::getSize() const{return size;}

void Bibita::setSize(std::string s){size=s;}

double Bibita::prezzoSize() const{
    double prezzoAggiuntivo=1;
    if(size=="S") prezzoAggiuntivo=1;
    if(size=="M") prezzoAggiuntivo=2;
    if(size=="L") prezzoAggiuntivo=3;
    return (0.5*prezzoAggiuntivo+getPrezzoBase());
}

double Bibita::calcolaPrezzo() const{
    return prezzoSize()*getQuantita();
}

bool Bibita::operator ==(const Prodotto& bib) const{
    const Prodotto* bi=&bib;
    const Bibita* b=dynamic_cast<const Bibita*>(bi);
    if(b && getNome()==b->getNome() && getPrezzoBase()==b->getPrezzoBase() && size==b->size) return true;
    else return false;
}

bool Bibita::operator !=(const Prodotto& bib) const{
    const Prodotto* bi=&bib;
    const Bibita* b=dynamic_cast<const Bibita*>(bi);
    if(getNome()==b->getNome() && getPrezzoBase()==b->getPrezzoBase() && size==b->size) return false;
    else return true;
}

std::ostream& operator<<(std::ostream& os,const Bibita& b){
    std::string taglia;
    if(b.getSize()=="S") taglia="Piccola";
    if(b.getSize()=="M") taglia="Media";
    if(b.getSize()=="L") taglia="Grande";
    os<<"Bibita: "<<b.getNome()<<" "<<taglia;
    int spazimancanti=30-9-b.getNome().size()-taglia.size();
    for(int i=0;i<spazimancanti;i++) os<<" ";
    if(b.getQuantita()<10) os<<"|0";
    else os<<"|";
    os<<b.getQuantita()<<"|";
    if(b.prezzoSize()<100){
        if(b.prezzoSize()<10) os<<"  ";
        else os<<" ";
    }
    os<<b.prezzoSize();
    double resto=b.prezzoSize();
    while(resto>=1) resto=resto-1;
    if(resto==0) os<<".00";
    else{
        while(resto>=0.09) resto=resto-0.1;
        if(resto<0.01) os<<"0";
    }
    os<<"|";
    if(b.calcolaPrezzo()<100){
        if(b.calcolaPrezzo()<10) os<<"  ";
        else os<<" ";
    }
    os<<b.calcolaPrezzo();
    double resto1=b.calcolaPrezzo();
    while(resto1>=1) resto1=resto1-1;
    if(resto1==0) os<<".00";
    else{
        while(resto1>=0.09) resto1=resto1-0.1;
        if(resto1<0.01) os<<0;
    }
    os<<"|"<<std::endl;
    for(int i=0;i<48;i++)os<<"-";
    os<<std::endl;
    return os;
}



