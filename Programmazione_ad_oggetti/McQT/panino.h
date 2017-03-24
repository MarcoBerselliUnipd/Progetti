 #ifndef PANINO_H
#define PANINO_H
#include"prodotto.h"

class Panino
{
    friend std::ostream& operator<<(std::ostream&,const Panino&);
    friend class iteratore;
private:
    class NodoProdotto;
    class smartp{
    public:
        NodoProdotto* punto;
        smartp(NodoProdotto*p=0);
        smartp(const smartp&);
        ~smartp();
        smartp& operator=(const smartp&);
        NodoProdotto& operator*() const;
        NodoProdotto* operator->() const;
        bool operator==(const smartp&) const;
        bool operator!=(const smartp&) const;
    };
    class NodoProdotto{
    public:
        NodoProdotto();
        NodoProdotto(const Prodotto&, const smartp&);
        Prodotto info;
        smartp next;
        int riferimenti;
    };
    smartp PrimoNodo;
    std::string nome;
    static bool lunghezzaUguale(const Panino&, const Panino&);
    int quantita;
public:
    class iteratore{
        friend class Panino;
    private:
        Panino::smartp punt;
    public:
        bool operator==(const iteratore&)const;
        bool operator!=(const iteratore&)const;
        iteratore& operator++();
        iteratore operator++(int);
    };

    Panino(std::string ="null", int=1);
    std::string getNome() const;
    void setNome(std::string);
    int getQuantita() const;
    void setQuantita(int);
    void stampaDettaglio() const;
    void sommaQuantita(const Panino&);
    void togliQuantita(const Panino&);
    virtual ~Panino();
    Prodotto& getProdotto(const Prodotto&) const;
    virtual void aggiungiProdotto(const Prodotto&);
    virtual void rimuoviProdotto(const Prodotto&);
    virtual double prezzoAlPezzo() const;
    double calcolaPrezzo()const;
    bool operator==(const Panino&) const;
    bool operator!=(const Panino&) const;
    iteratore begin() const;
    iteratore end() const;
    Prodotto& operator[](const iteratore&)const;
};
std::ostream& operator<<(std::ostream&,const Panino&);
#endif // PANINO_H
