#ifndef MENUVEGETARIANO_H
#define MENUVEGETARIANO_H
#include"menu.h"

class MacVegetariano:public Menu
{
    friend std::ostream& operator<<(std::ostream&,const MacVegetariano&);
public:
    MacVegetariano(int =1);
    double prezzoAlPezzo() const;
};
std::ostream& operator<<(std::ostream&,const MacVegetariano&);
#endif // MENUVEGETARIANO_H

