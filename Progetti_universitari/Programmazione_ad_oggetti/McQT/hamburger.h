#ifndef HAMBURGER_H
#define HAMBURGER_H
#include"panino.h"

class Hamburger:public Panino
{
    friend std::ostream& operator<<(std::ostream&, const Hamburger&);
public:
    Hamburger(int =1);
    void aggiungiProdotto(const Prodotto&);
    void rimuoviProdotto(const Prodotto&);
    double prezzoAlPezzo()const;
};
std::ostream& operator<<(std::ostream&, const Hamburger&);

#endif // HAMBURGER_H
