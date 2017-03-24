#ifndef VEGETARIANO_H
#define VEGETARIANO_H
#include"panino.h"

class Vegetariano:public Panino
{
    friend std::ostream& operator<<(std::ostream&, const Vegetariano&);
public:
    Vegetariano(int =1);
    void aggiungiProdotto(const Prodotto&);
    void rimuoviProdotto(const Prodotto&);
    double prezzoAlPezzo() const;
};

std::ostream& operator<<(std::ostream&, const Vegetariano&);
#endif // VEGETARIANO_H
