#include "menu.h"

Menu::Menu(std::string n,const Bibita& b,const Panino& p,const Patatina& pt, int q):nome(n),pat(new Patatina(pt)),quantita(q){
    const Bibita* bi=&b;
    const Panino* pa=&p;
    const Acqua* a=dynamic_cast<const Acqua*>(bi);
    const Birra* bir=dynamic_cast<const Birra*>(bi);
    const Hamburger* h=dynamic_cast<const Hamburger*>(pa);
    const Toast * t=dynamic_cast<const Toast*>(pa);
    const Vegetariano* v=dynamic_cast<const Vegetariano*>(pa);
    if(a || bir){
        if(a) bib=new Acqua(*a);
        if(bir) bib= new Birra(*bir);
    }
    else bib= new Bibita(b);
    if(h || t || v){
        if(h) pan=new Hamburger(*h);
        if(t) pan=new Toast(*t);
        if(v) pan=new Vegetariano(*v);
    }
    else pan=new Panino(p);
    if(quantita<1) quantita=1;
}

Menu::Menu(const Menu & m):nome(m.nome),pat(new Patatina(*m.pat)),quantita(m.quantita){
    const Bibita* bi=&(*m.bib);
    const Panino* pa=&(*m.pan);
    const Acqua* a=dynamic_cast<const Acqua*>(bi);
    const Birra* bir=dynamic_cast<const Birra*>(bi);
    const Hamburger* h=dynamic_cast<const Hamburger*>(pa);
    const Toast * t=dynamic_cast<const Toast*>(pa);
    const Vegetariano* v=dynamic_cast<const Vegetariano*>(pa);
    if(a || bir){
        if(a) bib=new Acqua(*a);
        if(bir) bib= new Birra(*bir);
    }
    else bib= new Bibita(*m.bib);
    if(h || t || v){
        if(h) pan=new Hamburger(*h);
        if(t) pan=new Toast(*t);
        if(v) pan=new Vegetariano(*v);
    }
    else pan=new Panino(*m.pan);
}

Menu& Menu::operator =(const Menu& t){
    nome=t.nome;
    delete bib;
    delete pan;
    delete pat;
    const Bibita* bi=&(*t.bib);
    const Panino* pa=&(*t.pan);
    const Acqua* a=dynamic_cast<const Acqua*>(bi);
    const Birra* bir=dynamic_cast<const Birra*>(bi);
    const Hamburger* h=dynamic_cast<const Hamburger*>(pa);
    const Toast * to=dynamic_cast<const Toast*>(pa);
    const Vegetariano* v=dynamic_cast<const Vegetariano*>(pa);
    if(a || bir){
        if(a) bib=new Acqua(*a);
        if(bir) bib= new Birra(*bir);
    }
    else bib= new Bibita(*t.bib);
    if(h || to || v){
        if(h) pan=new Hamburger(*h);
        if(to) pan=new Toast(*to);
        if(v) pan=new Vegetariano(*v);
    }
    else pan=new Panino(*t.pan);
    pat=new Patatina(*t.pat);
    quantita=t.quantita;
    return *this;
}

Menu::~Menu(){
    delete bib;
    delete pan;
    delete pat;
}

std::string Menu::getNome() const{
    return nome;
}


const Bibita& Menu::getBibita() const{
    return *bib;
}

const Panino& Menu::getPanino()const{
    return *pan;
}

const Patatina& Menu::getPatatina() const{
    return *pat;
}

int Menu::getQuantita() const{
    return quantita;
}

void Menu::setQuantita(int i){
    quantita=i;
}

void Menu::sommaQuantita(const Menu& m){
    if(*this==m){

        quantita += m.quantita;
    }
}

void Menu::togliQuantita(const Menu& m){
    if(*this==m){
        quantita -= m.quantita;
        if(quantita<0) quantita=0;
    }
}


double Menu::calcolaPrezzo() const{
    return prezzoAlPezzo()*getQuantita();
}

bool Menu::operator ==(const Menu& m) const{
    if(nome==m.nome && *bib==*(m.bib) && *pan==*(m.pan) && *pat==*(m.pat))return true;
    else return false;
}

bool Menu::operator !=(const Menu& m) const{
    if(nome==m.nome && *bib==*(m.bib) && *pan==*(m.pan) && *pat==*(m.pat))return false;
    else return true;
}

std::ostream& operator<<(std::ostream& os,const Menu& m){
    os<<"Menu: "<<m.getNome();
    int spazimancanti=30-6-m.getNome().size();
    for(int i=0;i<spazimancanti;i++) os<<" ";
    if(m.getQuantita()<10) os<<"|0";
    else os<<"|";
    os<<m.getQuantita()<<"|";
    if(m.prezzoAlPezzo()<100){
        if(m.prezzoAlPezzo()<10) os<<"  ";
        else os<<" ";
    }
    os<<m.prezzoAlPezzo();
    double resto=m.prezzoAlPezzo();
    while(resto>=1) resto=resto-1;
    if(resto==0) os<<".00";
    else{
        while(resto>=0.09) resto=resto-0.1;
        if(resto<0.01) os<<"0";
    }
    os<<"|";
    if(m.calcolaPrezzo()<100){
        if(m.calcolaPrezzo()<10) os<<"  ";
        else os<<" ";
    }
    os<<m.calcolaPrezzo();
    double resto1=m.calcolaPrezzo();
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

