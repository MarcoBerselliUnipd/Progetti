#include "acqua.h"

Acqua::Acqua(std::string n,int q,std::string s):Bibita(n,0.01,q,s){
    setSize(s);
    if(getSize()!="0.5L" && getSize()!="1L") setSize("0.5L");
}

double Acqua::prezzoSize() const{
    double x=1;
    if(getSize()=="0.5L") x=1;
    if(getSize()=="1L") x=2;
    return x;
}


std::ostream& operator<<(std::ostream& os,const Acqua& a){
    os<<"Acqua "<<a.getNome()<<" "<<a.getSize();
    int spazimancanti=30-7-a.getNome().size()-a.getSize().size();
    for(int i=0;i<spazimancanti;i++) os<<" ";
    if(a.getQuantita()<10) os<<"|0";
    else os<<"|";
    os<<a.getQuantita()<<"|";
    if(a.prezzoSize()<100){
        if(a.prezzoSize()<10) os<<"  ";
        else os<<" ";
    }
    os<<a.prezzoSize();
    double resto=a.prezzoSize();
    while(resto>=1) resto=resto-1;
    if(resto==0) os<<".00";
    os<<"|";
    if(a.calcolaPrezzo()<100){
        if(a.calcolaPrezzo()<10) os<<"  ";
        else os<<" ";
    }
    os<<a.calcolaPrezzo();
    double resto1=a.calcolaPrezzo();
    while(resto1>=1) resto1=resto1-1;
    if(resto1==0) os<<".00";
    os<<"|"<<std::endl;
    for(int i=0;i<48;i++)os<<"-";
    os<<std::endl;
    return os;
}


