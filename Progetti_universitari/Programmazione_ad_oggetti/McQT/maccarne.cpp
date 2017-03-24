#include "maccarne.h"

MacCarne::MacCarne(std::string b, int q):Menu("MacCarne", Bibita (b,1.0,1,"M"), Hamburger(), Patatina("Fritte",1,1,"S"),q){}


double MacCarne::prezzoAlPezzo()const{
    return (getBibita()).calcolaPrezzo()+(getPanino()).calcolaPrezzo()+(getPatatina()).calcolaPrezzo() - 1;
}


std::ostream& operator<<(std::ostream& os,const MacCarne& m){
    const Menu& menu=dynamic_cast<const Menu&>(m);
    os<<menu;
    return os;
}
