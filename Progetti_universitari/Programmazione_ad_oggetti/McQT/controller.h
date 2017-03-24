#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"panino.h"
#include<QString>
#include"scontrino.h"
#include<sstream>
#include<QVector>
#include<QWidget>
#include<QCheckBox>
#include<QSpinBox>
class Controller
{
private:
    Scontrino* scontr;
    Panino* puntatorePanino;
    Panino* puntatoreRimuoviPanino;
    Menu* puntatoreMenu;
    Menu* puntatoreRimuoviMenu;
    Patatina* puntatorePatatine;
    Patatina* puntatoreRimuoviPatatine;
    Bibita* puntatoreBibita;
    Bibita* puntatoreRimuoviBibita;
    QVector<QWidget*> aggiungiPanini;
    QVector<QWidget*> RimuoviProdotto;
    QVector<QString> nomiprodotti;
    QVector<QWidget*> aggiungiPatatine;
    QVector<QWidget*> RimuoviPatatine;
    QVector<QWidget*> aggiungiMenu;
    QVector<QWidget*> RimuoviMenu;
    QVector<QWidget*> aggiungiBibite;
    QVector<QWidget*> RimuoviBibita;

public:
    Controller(Scontrino *);
    virtual ~Controller();
    Scontrino* getScontrino() const;
    QString convertScontrino()const;
    //Panino
    void setPuntatorePanino(Panino*);
    void modificaNomePanino(const QString&);
    void modificaQuantitaPanino(int);
    QSpinBox *inserisciProdotto(const Prodotto&, bool);
    void modificaQuantitaProdotto(int,const Prodotto&);
    void inserisciPanino();
    //Rimuovi Panino
    QVector<std::string> getNomiProdotti() const;
    QVector<QWidget*> getRimuoviProdotto();
    QVector<QString> getNomiProdotti();
    void setPuntatoreRimuoviPanino(Panino*);
    Panino* getPuntatoreRimuoviPanino() const;
    void rimuoviProdottoInPanino(const Prodotto&);
    void rimuoviProdottoInPaninoQuantita(const Prodotto&,int);
    void aggiungiProdottoRimuoviPanini(const Prodotto&,bool);
    //Aggiungi Bibita
    void setPuntatoreBibita(Bibita*);
    void modificaQuantitaBibita(int);
    void inserisciBibita();
    void setBibitaNome(std::string);
    void setBibitaSize(std::string);
    //Rimuovi Bibita
    void setPuntatoreRimuoviBibita(Bibita*);
    Bibita* getPuntatoreRimuoviBibita() const;
    QVector<QWidget*> getRimuoviBibita();
    void modificaNomeRimuoviBibita(std::string);
    void modificaSizeRimuoviBibita(std::string);
    //Aggiungi Menu
    void setPuntatoreMenu(Menu*);
    void modificaQuantitaMenu(int);
    void inserisciMenu();
    void modificaNomeBibitaMenu(std::string);
    //Rimuovi Menu
    void setPuntatoreRimuoviMenu(Menu*);
    Menu* getPuntatoreRimuoviMenu() const;
    QVector<QWidget*> getRimuoviMenu();
    void modificaNomeBibitaRimuoviMenu(std::string);
    //Aggiungi Patatine
    void setPuntatorePatatina(Patatina *);
    void modificaQuantitaPatatina(int);
    void inserisciPatatina();
    void modificaSizePatatina(std::string);
    //Rimuovi Patatine
    void setPuntatoreRimuoviPatatina(Patatina*);
    Patatina* getPuntatoreRimuoviPatatina() const;
    QVector<QWidget*> getRimuoviPatatina();
    void modificaSizeRimuoviPatatina(std::string);

    void insertWidget(QWidget*, const QString&);
    void removeWidget(const QString&, const QString&);
    void stampa();
};

#endif // CONTROLLER_H
