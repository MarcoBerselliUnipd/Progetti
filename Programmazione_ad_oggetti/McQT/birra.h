#ifndef BIRRA_H
#define BIRRA_H
#include"bibita.h"

class Birra:public Bibita
{
    friend std::ostream& operator<<(std::ostream&, const Birra&);
public:
    Birra(std::string ="null",double =0.01,int =1,std::string ="0.33L");
    double prezzoSize() const;
};
std::ostream& operator<<(std::ostream&, const Birra&);

#endif // BIRRA_H
