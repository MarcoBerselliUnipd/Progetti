#ifndef MACMENU_H
#define MACMENU_H
#include"menu.h"
#include"hamburger.h"
class MacCarne:public Menu
{
    friend std::ostream& operator<<(std::ostream&,const MacCarne&);
public:
    MacCarne(std::string ="Cocacola", int =1);
    double prezzoAlPezzo() const;
};
std::ostream& operator<<(std::ostream&,const MacCarne&);
#endif // MACMENU_H
