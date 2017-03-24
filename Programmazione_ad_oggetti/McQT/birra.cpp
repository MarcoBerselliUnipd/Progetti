#include "birra.h"
Birra::Birra(std::string n,double p,int q,std::string s):Bibita(n,p,q,s){
    setSize(s);
    if(getSize()!="0.33L" && getSize()!="0.66L") setSize("0.33L");
}

double Birra::prezzoSize() const{
    double prezzoAggiuntivo=0;
    if(getSize()=="0.33L") prezzoAggiuntivo=1;
    if(getSize()=="0.66L") prezzoAggiuntivo=1.5;
    return getPrezzoBase()*prezzoAggiuntivo;
}

std::ostream& operator<<(std::ostream& os, const Birra& b){
    os<<"Birra "<<b.getNome()<<" "<<b.getSize();
    int spazimancanti=30-7-b.getNome().size()-b.getSize().size();
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
        if(resto<0.01) os<<0;
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



