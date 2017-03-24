#ifndef SCONTRINO_H
#define SCONTRINO_H
#include"menu.h"
#include"maccarne.h"
#include"macvegetariano.h"
#include"panino.h"
#include"hamburger.h"
#include"toast.h"
#include"vegetariano.h"
#include"bibita.h"
#include"acqua.h"
#include"birra.h"
#include"patatina.h"
#include <QVector>

class Scontrino
{
    friend class iteratore;
    friend std::ostream& operator<<(std::ostream& ,const Scontrino&);
private:
    class nodo;

    class smartp{
    public:
        nodo* punto;
        smartp(nodo* p=0);
        smartp(const smartp&);
        ~smartp();
        smartp& operator=(const smartp&);
        nodo& operator*() const;
        nodo* operator->() const;
        bool operator==(const smartp&) const;
        bool operator!=(const smartp&) const;

    };

    class nodo{

    public:
        nodo();
        nodo(const smartp&);
        smartp next;
        int riferimenti;
        virtual ~nodo();
    };

    class nodoMenu:public nodo{
    public:
        nodoMenu(const Menu&,const smartp&);
        nodoMenu(const nodoMenu&);
        nodoMenu& operator=(const nodoMenu&);
        ~nodoMenu();
        Menu* men;
    };

    class nodoPanino:public nodo{
    public:
        nodoPanino(const Panino&,const smartp&);
        nodoPanino(const nodoPanino&);
        nodoPanino& operator=(const nodoPanino&);
        ~nodoPanino();
        Panino* pan;
    };

    class nodoBibita:public nodo{
    public:
        nodoBibita(const Bibita&,const smartp&);
        nodoBibita(const nodoBibita&);
        nodoBibita& operator=(const nodoBibita&);
        ~nodoBibita();
        Bibita* bib;
    };

    class nodoPatatina:public nodo{
    public:
        nodoPatatina(const Patatina&,const smartp&);
        nodoPatatina(const nodoPatatina&);
        nodoPatatina& operator=(const nodoPatatina&);
        ~nodoPatatina();
        Patatina* pat;
    };
    smartp first;
    int numero;
public:
    class iteratore{
        friend class Scontrino;
    private:
        Scontrino::smartp punt;
    public:
        bool operator==(const iteratore&)const;
        bool operator!=(const iteratore&)const;
        iteratore& operator++();
        iteratore operator++(int);
    };

    Scontrino(int =0);
    virtual ~Scontrino();
    int getNumero() const;
    void inserisciMenu(const Menu&);
    void inserisciPanino(const Panino&);
    void inserisciBibita(const Bibita&);
    void inserisciPatatina(const Patatina&);
    void rimuoviMenu(const Menu&);
    void rimuoviPanino (const Panino&);
    void rimuoviBibita (const Bibita&);
    void rimuoviPatatina (const Patatina&);
    virtual double calcolaPrezzo() const;
    int pezziTotaliInseriti() const;
    QVector<Menu*> listaMenu() const;
    QVector<Panino*> listaPanino() const;
    QVector<Bibita*> listaBibita() const;
    QVector<Patatina*> listaPatatina() const;
    iteratore begin() const;
    iteratore end() const;
    Scontrino::nodo* operator[](const iteratore &)const;
    int size()const;
};
std::ostream& operator<<(std::ostream& os,const Scontrino&);
#endif // SCONTRINO_H
