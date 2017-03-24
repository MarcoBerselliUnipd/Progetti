#include "macvegetariano.h"
#include"acqua.h"
#include"vegetariano.h"
MacVegetariano::MacVegetariano(int q):Menu("Macvegetariano", Acqua("Naturale",1,"0.5L"), Vegetariano(), Patatina("Lesse",1,1,"S"),q){}



double MacVegetariano::prezzoAlPezzo() const{
    double tot=(getBibita()).calcolaPrezzo()+(getPanino()).calcolaPrezzo()+(getPatatina()).calcolaPrezzo();
    return tot-0.5;
}

std::ostream& operator<<(std::ostream& os,const MacVegetariano&v){
    const Menu& menu=dynamic_cast<const Menu&>(v);
    os<<menu;
    return os;
}
