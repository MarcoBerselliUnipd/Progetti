#ifndef TOAST_H
#define TOAST_H
#include"panino.h"

class Toast:public Panino
{
    friend std::ostream& operator<<(std::ostream&, const Toast&);
public:
    Toast(int =1);
    void aggiungiProdotto(const Prodotto&);
    void rimuoviProdotto(const Prodotto&);
    double prezzoAlPezzo() const;
};

std::ostream& operator<<(std::ostream&, const Toast&);
#endif // TOAST_H
