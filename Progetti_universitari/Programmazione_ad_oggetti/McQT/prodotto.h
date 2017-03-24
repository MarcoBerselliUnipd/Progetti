#ifndef PRODOTTO_H
#define PRODOTTO_H
#include<iostream>
class Prodotto
{
    friend std::ostream& operator<<(std::ostream&,const Prodotto&);
private:
    std::string nome;
    double prezzoBase;
    int quantita;
public:
    Prodotto(std::string ="NULL",double =0.01,int =1);
    virtual ~Prodotto();
    std::string getNome() const;
    void setNome(std::string);
    double getPrezzoBase() const;
    int getQuantita() const;
    void setQuantita(int);
    void sommaQuantita(const Prodotto&);
    void togliQuantita(const Prodotto&);
    virtual double calcolaPrezzo() const;
    virtual bool operator==(const Prodotto&) const;
    virtual bool operator!=(const Prodotto&) const;


};
std::ostream& operator<< (std::ostream& , const Prodotto&);
#endif //PRODOTTO_H

