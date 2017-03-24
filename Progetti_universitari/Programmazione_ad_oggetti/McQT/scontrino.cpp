#include "scontrino.h"

Scontrino::smartp::smartp(nodo *p):punto(p){if(punto) punto->riferimenti++;}

Scontrino::smartp::smartp(const smartp& s):punto(s.punto){if(punto) punto->riferimenti++;}

Scontrino::smartp::~smartp(){
    if(punto){
        punto->riferimenti--;
        if(punto->riferimenti==0){
            delete punto;
        }
    }
}

Scontrino::smartp& Scontrino::smartp::operator=(const smartp& s){
    if(this!=&s){
        nodo* t=punto;
        if(t) t->riferimenti++;
        if(punto) punto->riferimenti--;
        punto=s.punto;
        if(punto) punto->riferimenti++;
        if(t){
            t->riferimenti--;
            if(t->riferimenti==0) delete t;
        }
    }
    return *this;
}

Scontrino::nodo* Scontrino::smartp::operator ->()const{
    return punto;
}

Scontrino::nodo& Scontrino::smartp::operator*() const{
    return *punto;
}

bool Scontrino::smartp::operator ==(const smartp& p) const{
    return punto==p.punto;
}

bool Scontrino::smartp::operator !=(const smartp& p) const{
    return punto!=p.punto;
}

Scontrino::nodo::nodo():riferimenti(0){}

Scontrino::nodo::nodo(const smartp& n):next(n),riferimenti(0){}

Scontrino::nodo::~nodo(){}

Scontrino::nodoMenu::nodoMenu(const Menu& me, const smartp& n):nodo(n){
    const Menu* m=&me;
    const MacCarne* c=dynamic_cast<const MacCarne*>(m);
    const MacVegetariano* v=dynamic_cast<const MacVegetariano*>(m);
    if(c){
        men=new MacCarne(*c);
    }
    if(v){
        men=new MacVegetariano(*v);
    }
}

Scontrino::nodoMenu::nodoMenu(const nodoMenu &m):nodo(m.next){
    const MacCarne* c=dynamic_cast<const MacCarne*>(m.men);
    const MacVegetariano* v=dynamic_cast<const MacVegetariano*>(m.men);
    if(c) men=new MacCarne(*c);
    if(v) men=new MacVegetariano(*v);
}

Scontrino::nodoMenu& Scontrino::nodoMenu::operator =(const nodoMenu& t){
    next=t.next;
    delete men;
    const MacCarne* c=dynamic_cast<const MacCarne*>(t.men);
    const MacVegetariano* v=dynamic_cast<const MacVegetariano*>(t.men);
    if(c) men=new MacCarne(*c);
    if(v) men=new MacVegetariano(*v);
    return *this;
}

Scontrino::nodoMenu::~nodoMenu(){delete men;}

Scontrino::nodoPanino::nodoPanino(const Panino& pa, const smartp& n):nodo(n){
    const Panino* p=&pa;
    const Hamburger* h=dynamic_cast<const Hamburger*>(p);
    const Toast* t=dynamic_cast<const Toast*>(p);
    const Vegetariano* v=dynamic_cast<const Vegetariano*>(p);
    if(h || t || v){
        if(h) pan=new Hamburger(*h);
        if(t) pan=new Toast(*t);
        if(v) pan=new Vegetariano(*v);
    }
    else{
        pan=new Panino(*p);
    }
}

Scontrino::nodoPanino::nodoPanino(const nodoPanino& p):nodo(p.next){
    const Hamburger* h=dynamic_cast<const Hamburger*>(p.pan);
    const Toast* t=dynamic_cast<const Toast*>(p.pan);
    const Vegetariano* v=dynamic_cast<const Vegetariano*>(p.pan);
    if(h || t || v){
        if(h) pan=new Hamburger(*h);
        if(t) pan=new Toast(*t);
        if(v) pan=new Vegetariano(*v);
    }
    else{
        pan=new Panino(*p.pan);
    }
}

Scontrino::nodoPanino& Scontrino::nodoPanino::operator =(const nodoPanino& p){
    next=p.next;
    const Hamburger* h=dynamic_cast<const Hamburger*>(p.pan);
    const Toast* t=dynamic_cast<const Toast*>(p.pan);
    const Vegetariano* v=dynamic_cast<const Vegetariano*>(p.pan);
    delete pan;
    if(h || t || v){
        if(h) pan=new Hamburger(*h);
        if(t) pan=new Toast(*t);
        if(v) pan=new Vegetariano(*v);
    }
    else{
        pan=new Panino(*p.pan);
    }
    return *this;
}

Scontrino::nodoPanino::~nodoPanino(){delete pan;}

Scontrino::nodoBibita::nodoBibita(const Bibita& bi, const smartp& n):nodo(n){
    const Bibita* b=&bi;
    const Acqua* a=dynamic_cast<const Acqua*>(b);
    const Birra* bir=dynamic_cast<const Birra*>(b);
    if(a || bir){
        if(a) bib=new Acqua(*a);
        if(bir) bib=new Birra(*bir);
    }
    else bib=new Bibita(*b);
}

Scontrino::nodoBibita::nodoBibita(const nodoBibita& b):nodo(b.next){
    const Acqua* a=dynamic_cast<const Acqua*>(b.bib);
    const Birra* bi=dynamic_cast<const Birra*>(b.bib);
    if(a || bi){
        if(a) bib=new Acqua(*a);
        if(bi) bib=new Birra(*bi);
    }
    else bib=new Bibita(*b.bib);
}

Scontrino::nodoBibita& Scontrino::nodoBibita::operator=(const nodoBibita& b){
    next=b.next;
    delete bib;
    const Acqua* a=dynamic_cast<const Acqua*>(b.bib);
    const Birra* bi=dynamic_cast<const Birra*>(b.bib);
    if(a || bi){
        if(a) bib=new Acqua(*a);
        if(bi) bib=new Birra(*bi);
    }
    else bib=new Bibita(*b.bib);
    return *this;
}

Scontrino::nodoBibita::~nodoBibita(){delete bib;}

Scontrino::nodoPatatina::nodoPatatina(const Patatina& p, const smartp& n):nodo(n),pat(new Patatina(p)){}

Scontrino::nodoPatatina::nodoPatatina(const nodoPatatina& p):nodo(p.next),pat(new Patatina(*p.pat)){}

Scontrino::nodoPatatina& Scontrino::nodoPatatina::operator =(const nodoPatatina& p){
    next=p.next;
    delete pat;
    pat=new Patatina(*p.pat);
    return *this;
}

Scontrino::nodoPatatina::~nodoPatatina(){delete pat;}

bool Scontrino::iteratore::operator ==(const iteratore& i)const{
    return punt==i.punt;
}

bool Scontrino::iteratore::operator !=(const iteratore& i)const{
    return punt!=i.punt;
}
Scontrino::iteratore& Scontrino::iteratore::operator++(){
    if(punt!=0)punt=punt->next;
    return *this;
}

Scontrino::iteratore Scontrino::iteratore::operator++(int){
    iteratore aux =*this;
    if(punt!=0) punt=punt->next;
    return aux;
}

Scontrino::Scontrino(int n):numero(n){}

Scontrino::~Scontrino(){}

int Scontrino::getNumero()const{ return numero;}

void Scontrino::inserisciMenu(const Menu& m){
    bool trovato=false;
    if(first==0) first=new nodoMenu(m,first);
    else{
        for(iteratore it=begin(); it!=end();it++){
            nodoMenu *nm=dynamic_cast<nodoMenu*>((*this)[it]);
            if(nm && *nm->men==m){
                trovato=true;
                Menu* i=const_cast<Menu*>(nm->men);      
                i->sommaQuantita(m);
            }
        }
        if(trovato==false) first=new nodoMenu(m,first);

    }
}

void Scontrino::inserisciPanino(const Panino& p){
    bool trovato=false;
    if(first==0) first=new nodoPanino(p,first);
    else{
        for(iteratore it=begin(); it!=end();it++){
            nodoPanino *np=dynamic_cast<nodoPanino*>((*this)[it]);
            if(np && *np->pan==p){
                trovato=true;
                Panino* i=const_cast<Panino*>(np->pan);
                i->sommaQuantita(p);
            }
        }
        if(trovato==false) first=new nodoPanino(p,first);

    }
}

void Scontrino::inserisciBibita(const Bibita& b){
    bool trovato=false;
    if(first==0) first=new nodoBibita(b,first);
    else{
        for(iteratore it=begin(); it!=end();it++){
            nodoBibita *nb=dynamic_cast<nodoBibita*>((*this)[it]);
            if(nb && *nb->bib==b){
                trovato=true;
                Bibita* i=const_cast<Bibita*>(nb->bib);
                i->sommaQuantita(b);
            }
        }
        if(trovato==false) first=new nodoBibita(b,first);

    }
}

void Scontrino::inserisciPatatina(const Patatina& p){
    bool trovato=false;
    if(first==0) first=new nodoPatatina(p,first);
    else{
        for(iteratore it=begin(); it!=end();it++){
            nodoPatatina *np=dynamic_cast<nodoPatatina*>((*this)[it]);
            if(np && *np->pat==p){
                trovato=true;
                Patatina* i=const_cast<Patatina*>(np->pat);
                i->sommaQuantita(p);
            }
        }
        if(trovato==false) first=new nodoPatatina(p,first);

    }
}

void Scontrino::rimuoviMenu(const Menu& m){
    smartp primo=first;
    smartp secondo=primo;
    if(first==0) std::cout<<"Lista Vuota!"<<std::endl;
    else{
        iteratore it=begin();
        Scontrino::nodoMenu* nm=dynamic_cast<Scontrino::nodoMenu*>((*this)[it]);
        if(nm && *nm->men==m){
            Menu* i=const_cast<Menu*>(nm->men);
            i->togliQuantita(m);
            if(nm->men->getQuantita()==0) first=first->next;
        }
        else{
            for(;it!=end();it++){
                nm=dynamic_cast<Scontrino::nodoMenu*>((*this)[it]);
                if(nm && *nm->men==m){
                   Menu* i=const_cast<Menu*>(nm->men);
                   i->togliQuantita(m);
                   if(nm->men->getQuantita()==0) secondo->next=primo->next;
                }
                secondo=primo;
                primo=primo->next;
            }
        }
    }
}

void Scontrino::rimuoviPanino(const Panino& p){
    smartp primo=first;
    smartp secondo=primo;
    if(first==0) std::cout<<"Lista Vuota!"<<std::endl;
    else{
        iteratore it=begin();
        Scontrino::nodoPanino* np=dynamic_cast<Scontrino::nodoPanino*>((*this)[it]);
        if(np && *np->pan==p) {
            Panino* i=const_cast<Panino*>(np->pan);
            i->togliQuantita(p);
            if(np->pan->getQuantita()==0) first=first->next;
        }
        else{
            for(;it!=end();it++){
                np=dynamic_cast<Scontrino::nodoPanino*>((*this)[it]);
                if(np && *np->pan==p){
                    Panino* i=const_cast<Panino*>(np->pan);
                    i->togliQuantita(p);
                    if(np->pan->getQuantita()==0) secondo->next=primo->next;
                }
                secondo=primo;
                primo=primo->next;
            }
        }
    }
}

void Scontrino::rimuoviBibita(const Bibita& b){
    smartp primo=first;
    smartp secondo=primo;
    if(first==0) std::cout<<"Lista Vuota!"<<std::endl;
    else{
        iteratore it=begin();
        Scontrino::nodoBibita* nb=dynamic_cast<Scontrino::nodoBibita*>((*this)[it]);
        if(nb && *nb->bib==b){
            Bibita* i=const_cast<Bibita*>(nb->bib);
            i->togliQuantita(b);
            if(nb->bib->getQuantita()==0) first=first->next;
        }
        else{
            for(;it!=end();it++){
                nb=dynamic_cast<Scontrino::nodoBibita*>((*this)[it]);
                if(nb && *nb->bib==b){
                    Bibita* i=const_cast<Bibita*>(nb->bib);
                    i->togliQuantita(b);
                    if(nb->bib->getQuantita()==0) secondo->next=primo->next;
                }
                secondo=primo;
                primo=primo->next;
            }
        }
    }
}

void Scontrino::rimuoviPatatina(const Patatina& p){
    smartp primo=first;
    smartp secondo=primo;
    if(first==0) std::cout<<"Lista Vuota!"<<std::endl;
    else{
        iteratore it=begin();
        Scontrino::nodoPatatina* np=dynamic_cast<Scontrino::nodoPatatina*>((*this)[it]);
        if(np && *np->pat==p){
            Patatina* i=const_cast<Patatina*>(np->pat);
            i->togliQuantita(p);
            if(np->pat->getQuantita()==0) first=first->next;
        }
        else{
            for(;it!=end();it++){
                np=dynamic_cast<Scontrino::nodoPatatina*>((*this)[it]);
                if(np && *np->pat==p){
                    Patatina* i=const_cast<Patatina*>(np->pat);
                    i->togliQuantita(p);
                    if(np->pat->getQuantita()==0) secondo->next=primo->next;
                }
                secondo=primo;
                primo=primo->next;
            }
        }
    }
}

int Scontrino::pezziTotaliInseriti() const{
    int tot=0;
    for(iteratore it=begin();it!=end();it++){
        Scontrino::nodoMenu* m=dynamic_cast<Scontrino::nodoMenu*>((*this)[it]);
        Scontrino::nodoPanino* p=dynamic_cast<Scontrino::nodoPanino*>((*this)[it]);
        Scontrino::nodoBibita* b=dynamic_cast<Scontrino::nodoBibita*>((*this)[it]);
        Scontrino::nodoPatatina* pt=dynamic_cast<Scontrino::nodoPatatina*>((*this)[it]);
        if(m) tot=tot+ m->men->getQuantita();
        if(p) tot=tot+p->pan->getQuantita();
        if(b) tot=tot+b->bib->getQuantita();
        if(pt) tot=tot+pt->pat->getQuantita();
    }
    return tot;
}

double Scontrino::calcolaPrezzo() const{
    double tot=0;
    for(iteratore it=begin();it!=end();it++){
        Scontrino::nodoMenu* m=dynamic_cast<Scontrino::nodoMenu*>((*this)[it]);
        Scontrino::nodoPanino* p=dynamic_cast<Scontrino::nodoPanino*>((*this)[it]);
        Scontrino::nodoBibita* b=dynamic_cast<Scontrino::nodoBibita*>((*this)[it]);
        Scontrino::nodoPatatina* pt=dynamic_cast<Scontrino::nodoPatatina*>((*this)[it]);
        if(m) tot= tot + m->men->calcolaPrezzo();
        if(p) tot = tot + p->pan->calcolaPrezzo();
        if(b) tot = tot + b->bib->calcolaPrezzo();
        if(pt) tot = tot + pt->pat->calcolaPrezzo();
    }
    return tot;
}

Scontrino::iteratore Scontrino::begin() const{
    iteratore aux;
    aux.punt=first;
    return aux;
}

Scontrino::iteratore Scontrino::end() const{
    iteratore aux;
    aux.punt=0;
    return aux;
}

Scontrino::nodo* Scontrino::operator[](const Scontrino::iteratore& it)const{
    return (it.punt).punto;
}

int Scontrino::size() const{
    int count=0;
    for(iteratore it=begin();it!=end();it++){
        count ++;
    }
    return count;
}

QVector<Menu*> Scontrino::listaMenu() const{
    QVector<Menu*> menu;
    for(iteratore it=begin(); it!=end(); it++){
        Scontrino::nodoMenu* m=dynamic_cast<Scontrino::nodoMenu*>((*this)[it]);
        if(m){
            menu.append(m->men);
        }
    }
    return menu;
}
QVector<Panino*> Scontrino::listaPanino() const{
    QVector<Panino*> panino;
    for(iteratore it=begin(); it!=end(); it++){
        Scontrino::nodoPanino* p=dynamic_cast<Scontrino::nodoPanino*>((*this)[it]);
        if(p){
            panino.append(p->pan);
        }
    }
    return panino;
}
QVector<Bibita*> Scontrino::listaBibita() const{
    QVector<Bibita*> bibita;
    for(iteratore it=begin(); it!=end(); it++){
        Scontrino::nodoBibita* b=dynamic_cast<Scontrino::nodoBibita*>((*this)[it]);
        if(b){
            bibita.append(b->bib);
        }
    }
    return bibita;
}
QVector<Patatina*> Scontrino::listaPatatina() const{
    QVector<Patatina*> patatina;
    for(iteratore it=begin(); it!=end(); it++){
        Scontrino::nodoPatatina* pt=dynamic_cast<Scontrino::nodoPatatina*>((*this)[it]);
        if(pt){
            patatina.append(pt->pat);
        }
    }
    return patatina;
}

std::ostream& operator<<(std::ostream& os,const Scontrino&s){
    os<<"Scontrino       |n:";
    if(s.numero<100){
        if(s.numero<10) os<<"00";
        else os<<"0";
    }
    os<<s.numero<<"|       |pz|Al pz.| TOT. |\n"<<std::endl;
    for(int i=0;i<52;i++) os<<"-";
    os<<std::endl;
    for(int i=0;i<52;i++) os<<"-";
    os<<std::endl;
    double pezziTotali=0;
    for(Scontrino::iteratore it=s.begin();it!=s.end();it++){
        Scontrino::nodoMenu* m=dynamic_cast<Scontrino::nodoMenu*>(s[it]);
        Scontrino::nodoPanino* p=dynamic_cast<Scontrino::nodoPanino*>(s[it]);
        Scontrino::nodoBibita* b=dynamic_cast<Scontrino::nodoBibita*>(s[it]);
        Scontrino::nodoPatatina* pt=dynamic_cast<Scontrino::nodoPatatina*>(s[it]);
        if(m) {

            os<<*m->men;
            pezziTotali +=m->men->getQuantita();
        }
        if(p){
            const Hamburger* h=dynamic_cast<const Hamburger*>(p->pan);
            const Toast* t=dynamic_cast<const Toast*>(p->pan);
            const Vegetariano* v=dynamic_cast<const Vegetariano*>(p->pan);
            if(h) os<<*h;
            if(t) os<<*t;
            if(v) os<<*v;
            if(!h && !t  && !v) os<<*p->pan;
            pezziTotali +=p->pan->getQuantita();
        }
        if(b){
            const Acqua* a=dynamic_cast<const Acqua*>(b->bib);
            const Birra* bi=dynamic_cast<const Birra*>(b->bib);
            if(a) os<<*a;
            if(bi) os<<*bi;
            if(!a && !bi) os<<*b->bib;
            pezziTotali +=b->bib->getQuantita();
        }
        if(pt){
            os<<*pt->pat;
            pezziTotali +=pt->pat->getQuantita();
        }
    }
    for(int i=0;i<52;i++) os<<"-";
    os<<std::endl;
    for(int i=0;i<52;i++) os<<"-";
    os<<std::endl;
    os<<"|Pezzi totali:"<<pezziTotali<<"| Totale:"<<s.calcolaPrezzo()<<" Euro|"<<std::endl;
    return os;

}


