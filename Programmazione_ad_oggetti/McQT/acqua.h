#ifndef ACQUA_H
#define ACQUA_H
#include"bibita.h"

class Acqua: public Bibita
{
    friend std::ostream& operator<<(std::ostream&, const Acqua&);
public:
    Acqua(std::string ="null",int =1,std::string ="0.5L");
    double prezzoSize() const;
};
std::ostream& operator<<(std::ostream&, const Acqua&);

#endif // ACQUA_H
