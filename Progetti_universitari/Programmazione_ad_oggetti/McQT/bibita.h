#ifndef BIBITA_H
#define BIBITA_H
#include"prodotto.h"

class Bibita:public Prodotto
{
    friend std::ostream& operator<<(std::ostream&, const Bibita&);
private:
    std::string size;
public:
    Bibita(std::string ="null",double =0.01,int =1,std::string ="S");
    std::string getSize() const;
    void setSize(std::string);
    virtual double prezzoSize() const;
    double calcolaPrezzo() const;
    bool operator==(const Prodotto&) const;
    bool operator!=(const Prodotto&) const;
};

std::ostream& operator<<(std::ostream& os, const Bibita& b);
#endif // BIBITA_H
