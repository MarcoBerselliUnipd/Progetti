#include "patatina.h"

Patatina::Patatina(std::string n, double p,int q,std::string s):Prodotto(n,p,q),size(s){
    if(size!="S" && size!="M" && size!="L" && size !="XL") size="S";
}

std::string Patatina::getSize() const{return size;}

void Patatina::setSize(std::string s){size=s;}

double Patatina::prezzoSize() const{
    double prezzoAggiuntivo=1;
    if(size=="S") prezzoAggiuntivo=1;
    if(size=="M") prezzoAggiuntivo=2;
    if(size=="L") prezzoAggiuntivo=3;
    if(size=="XL") prezzoAggiuntivo=4;
    return (0.5*prezzoAggiuntivo+getPrezzoBase());
}

double Patatina::calcolaPrezzo() const{
    return prezzoSize()*getQuantita();
}

bool Patatina::operator ==(const Prodotto& patat) const{
    const Prodotto* h=&patat;
    const Patatina* p=dynamic_cast<const Patatina*>(h);
    if(p && (getNome()==p->getNome() && getPrezzoBase()==p->getPrezzoBase()) && size==p->size)return true;
    else return false;
}

bool Patatina::operator !=(const Prodotto& patat) const{
    const Prodotto* h=&patat;
    const Patatina* p=dynamic_cast<const Patatina*>(h);
    if(p&& getNome()==p->getNome() && getPrezzoBase()==p->getPrezzoBase() && size==p->size) return false;
    else return true;
}

std::ostream& operator<<(std::ostream& os,const Patatina& p){
    std::string taglia;
    if(p.getSize()=="S") taglia="Piccola";
    if(p.getSize()=="M") taglia="Media";
    if(p.getSize()=="L") taglia="Grande";
    if(p.getSize()=="XL") taglia="Extra Grande";
    os<<"Patatine "<<p.getNome()<<" "<<taglia;
    int spazimancanti=31-11-p.getNome().size()-taglia.size();
    for(int i=0;i<spazimancanti;i++) os<<" ";
    if(p.getQuantita()<10) os<<"|0";
    else os<<"|";
    os<<p.getQuantita()<<"|";
    if(p.prezzoSize()<100){
        if(p.prezzoSize()<10) os<<"  ";
        else os<<" ";
    }
    os<<p.prezzoSize();
    double resto=p.prezzoSize();
    while(resto>=1) resto=resto-1;
    if(resto==0) os<<".00";
    else{
        while(resto>=0.09) resto=resto-0.1;
        if(resto<0.01) os<<0;
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
    return os;
}




