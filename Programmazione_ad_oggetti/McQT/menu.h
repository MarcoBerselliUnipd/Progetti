#ifndef MENU_H
#define MENU_H
#include"bibita.h"
#include"acqua.h"
#include"birra.h"
#include"panino.h"
#include"hamburger.h"
#include"toast.h"
#include"vegetariano.h"
#include"patatina.h"

class Menu
{
    friend std::ostream& operator<<(std::ostream&,const Menu&);
private:
    std::string nome;
    const Bibita* bib;
    const Panino* pan;
    const Patatina* pat;
    int quantita;
public:
    Menu(std::string,const Bibita&,const Panino&,const Patatina&,int =1);
    Menu(const Menu&);
    Menu& operator=(const Menu& t);
    virtual ~Menu();
    std::string getNome() const;
    const Bibita& getBibita() const;
    const Panino& getPanino() const;
    const Patatina& getPatatina() const;
    int getQuantita() const;
    void setQuantita(int i);
    void sommaQuantita(const Menu&);
    void togliQuantita(const Menu&);
    virtual double prezzoAlPezzo() const = 0;
    double calcolaPrezzo() const;
    bool operator ==(const Menu&) const;
    bool operator !=(const Menu&) const ;
};

std::ostream& operator<<(std::ostream&,const Menu&);

#endif // MENU_H
