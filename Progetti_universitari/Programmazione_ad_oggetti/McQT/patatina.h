#ifndef PATATINA_H
#define PATATINA_H
#include"prodotto.h"

class Patatina:public Prodotto
{
    friend std::ostream& operator<<(std::ostream& ,const Patatina&);
private:
    std::string size;

public:
    Patatina(std::string ="null",double =0.01,int =1,std::string ="S" );
    std::string getSize() const;
    void setSize(std::string);
    virtual double prezzoSize() const;
    double calcolaPrezzo() const;
    bool operator==(const Prodotto&) const;
    bool operator!=(const Prodotto&) const;
};

std::ostream& operator<<(std::ostream&,const Patatina&);
#endif // PATATINA_H
