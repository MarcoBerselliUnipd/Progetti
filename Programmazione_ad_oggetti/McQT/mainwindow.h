#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QVBoxLayout>
#include <QMap>
#include <QString>
#include "controller.h"
#include "panino.h"
#include "menu.h"
#include "patatina.h"
#include"bibita.h"
#include"scontrino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void aggiungiLayoutAggiungiPanino();
    void aggiungiLayoutAggiungiMenu();
    void aggiungiLayoutAggiungiPatatina();
    void aggiungiLayoutAggiungiBibita();
    void aggiungiLayoutRimuoviPanino();
    void aggiungiLayoutRimuoviMenu();
    void aggiungiLayoutRimuoviPatatina();
    void aggiungiLayoutRimuoviBibita();
    ~MainWindow();

public slots:
    void modificaNomePanino(QString);
    void aggiungiPaninoAdScontrino();
    //Aggiungi Panino
    void aggiungiPane_checkBox(bool);
    void aggiungiPaneToast_checkBox(bool);
    void aggiungiHamburger_checkBox(bool);
    void aggiungiProsciutto_checkBox(bool);
    void aggiungiBacon_checkBox(bool);
    void aggiungiMozzarella_checkBox(bool);
    void aggiungiSottilette_checkBox(bool);
    void aggiungiPomodoro_checkBox(bool);
    void aggiungiInsalata_checkBox(bool);
    void aggiungiSottoAceti_checkBox(bool);
    void aggiungiSalsaFunghi_checkBox(bool);
    void aggiungiCipolla_checkBox(bool);
    void aggiungiPeperoni_checkBox(bool);

    void modificaQuantita_Pane(int);
    void modificaQuantita_PaneToast(int);
    void modificaQuantita_Hamburger(int);
    void modificaQuantita_Prosciutto(int);
    void modificaQuantita_Bacon(int);
    void modificaQuantita_Mozzarella(int);
    void modificaQuantita_Sottilette(int);
    void modificaQuantita_Pomodoro(int);
    void modificaQuantita_Insalata(int);
    void modificaQuantita_SottoAceti(int);
    void modificaQuantita_SalsaFunghi(int);
    void modificaQuantita_Cipolla(int);
    void modificaQuantita_Peperoni(int);
    //Aggiungi Menu
    void aggiungiCocacola_RadioButton();
    void aggiungiSprite_RadioButton();
    void aggiungiFanta_RadioButton();
    void aggiungiTheLimone_RadioButton();
    void aggiungiThePesca_RadioButton();
    //Aggiungi Patatine
    void aggiungiPiccola_RadioButton();
    void aggiungiMedia_RadioButton();
    void aggiungiGrande_RadioButton();
    void aggiungiExtraGrande_RadioButton();
    //Aggiungi Bibita
    void aggiungiCocacolaBibita_RadioButton();
    void aggiungiSpriteBibita_RadioButton();
    void aggiungiFantaBibita_RadioButton();
    void aggiungiTheLimoneBibita_RadioButton();
    void aggiungiThePescaBibita_RadioButton();
    void aggiungiPiccolaBibita_RadioButton();
    void aggiungiMediaBibita_RadioButton();
    void aggiungiGrandeBibita_RadioButton();
    void aggiungiNaturale_RadioButton();
    void aggiungiFrizzante_RadioButton();
    void aggiungiL05_RadioButton();
    void aggiungiL1_RadioButton();
    void aggiungiBionda_RadioButton();
    void aggiungiRossa_RadioButton();
    void aggiungiL033_RadioButton();
    void aggiungiL066_RadioButton();
    //Rimuovi Panino
    void RimuoviPane_checkBox(bool);
    void modificaQuantita_PaneRimuoviProdotto(int);
    void RimuoviPaneToast_checkBox(bool);
    void modificaQuantita_PaneToastRimuoviProdotto(int);
    void RimuoviHamburger_checkBox(bool);
    void modificaQuantita_HamburgerRimuoviProdotto(int);
    void RimuoviProsciutto_checkBox(bool);
    void modificaQuantita_ProsciuttoRimuoviProdotto(int);
    void RimuoviBacon_checkBox(bool);
    void modificaQuantita_BaconRimuoviProdotto(int);
    void RimuoviMozzarella_checkBox(bool);
    void modificaQuantita_MozzarellaRimuoviProdotto(int);
    void RimuoviSottiletta_checkBox(bool);
    void modificaQuantita_SottilettaRimuoviProdotto(int);
    void RimuoviPomodoro_checkBox(bool);
    void modificaQuantita_PomodoroRimuoviProdotto(int);
    void RimuoviInsalata_checkBox(bool);
    void modificaQuantita_InsalataRimuoviProdotto(int);
    void RimuoviSottoAceti_checkBox(bool);
    void modificaQuantita_SottoAcetiRimuoviProdotto(int);
    void RimuoviSalsaFunghi_checkBox(bool);
    void modificaQuantita_SalsaFunghiRimuoviProdotto(int);
    void RimuoviCipolla_checkBox(bool);
    void modificaQuantita_CipollaRimuoviProdotto(int);
    void RimuoviPeperoni_checkBox(bool);
    void modificaQuantita_PeperoniRimuoviProdotto(int);
    void aggiungiPaneRimuoviPanino_checkBox(bool b);
    void aggiungiPaneToastRimuoviPanino_checkBox(bool);
    void aggiungiHamburgerRimuoviPanino_checkBox(bool);
    void aggiungiProsciuttoRimuoviPanino_checkBox(bool);
    void aggiungiBaconRimuoviPanino_checkBox(bool);
    void aggiungiMozzarellaRimuoviPanino_checkBox(bool);
    void aggiungiSottiletteRimuoviPanino_checkBox(bool);
    void aggiungiPomodoroRimuoviPanino_checkBox(bool);
    void aggiungiInsalataRimuoviPanino_checkBox(bool);
    void aggiungiSottoAcetiRimuoviPanino_checkBox(bool);
    void aggiungiSalsaFunghiRimuoviPanino_checkBox(bool);
    void aggiungiCipollaRimuoviPanino_checkBox(bool);
    void aggiungiPeperoniRimuoviPanino_checkBox(bool);
    //Rimuovi Menu
    void aggiungiCocacolaRimuoviMenu_RadioButton();
    void aggiungiSpriteRimuoviMenu_RadioButton();
    void aggiungiFantaRimuoviMenu_RadioButton();
    void aggiungiTheLimoneRimuoviMenu_RadioButton();
    void aggiungiThePescaRimuoviMenu_RadioButton();
    //Rimuovi Patatine
    void aggiungiPiccolaRimuoviPatatine_RadioButton();
    void aggiungiMediaRimuoviPatatine_RadioButton();
    void aggiungiGrandeRimuoviPatatine_RadioButton();
    void aggiungiExtraGrandeRimuoviPatatine_RadioButton();
    //Rimuovi Bibita
    void aggiungiCocacolaBibitaRimuoviBibita_RadioButton();
    void aggiungiSpriteBibitaRimuoviBibita_RadioButton();
    void aggiungiFantaBibitaRimuoviBibita_RadioButton();
    void aggiungiTheLimoneBibitaRimuoviBibita_RadioButton();
    void aggiungiThePescaBibitaRimuoviBibita_RadioButton();
    void aggiungiPiccolaBibitaRimuoviBibita_RadioButton();
    void aggiungiMediaBibitaRimuoviBibita_RadioButton();
    void aggiungiGrandeBibitaRimuoviBibita_RadioButton();
    void aggiungiNaturaleRimuoviBibita_RadioButton();
    void aggiungiFrizzanteRimuoviBibita_RadioButton();
    void aggiungiL05RimuoviBibita_RadioButton();
    void aggiungiL1RimuoviBibita_RadioButton();
    void aggiungiBiondaRimuoviBibita_RadioButton();
    void aggiungiRossaRimuoviBibita_RadioButton();
    void aggiungiL033RimuoviBibita_RadioButton();
    void aggiungiL066RimuoviBibita_RadioButton();

private slots:

    void on_comboBoxPanini_currentIndexChanged(const QString &arg1);

    void on_pushButtonPagamento_clicked();

    void on_PaninoQuantita_valueChanged(int arg1);

    void on_comboBoxMenu_currentIndexChanged(const QString &arg1);

    void on_spinBoxQuantitaMenu_valueChanged(int arg1);

    void on_pushButtonAggiungiMenu_clicked();

    void on_comboBoxPatatine_currentIndexChanged(const QString &arg1);

    void on_spinBoxQuantitaPatatine_valueChanged(int arg1);

    void on_pushButtonAggiungiPatatine_clicked();

    void on_comboBoxBibite_currentIndexChanged(const QString &arg1);

    void on_spinBoxQuantitaBibite_valueChanged(int);

    void on_pushButtonAggiungiBibite_clicked();

    void on_RimuoviPaninoButton_clicked();

    void on_comboBoxRimuoviPanini_currentIndexChanged(int index);

    void on_PaninoModificaQuantita_valueChanged(int arg1);

    void on_comboBoxRimuoviMenu_currentIndexChanged(int index);

    void on_MenuModificaQuantita_valueChanged(int arg1);

    void on_RimuoviMenuButton_clicked();

    void on_comboBoxRimuoviPatatine_currentIndexChanged(int index);

    void on_PatatineModificaQuantita_valueChanged(int arg1);

    void on_RimuoviPatatineButton_clicked();

    void on_comboBoxRimuoviBibite_currentIndexChanged(int index);

    void on_BibitaModificaQuantita_valueChanged(int arg1);

    void on_RimuoviBibitaButton_clicked();

private:
    Controller* control;
    //Layout
    QVBoxLayout * scrollAreaVLayoutPanino;
    QVBoxLayout * scrollAreaVLayoutPaninoQuantita;
    QVBoxLayout * scrollAreaMenu;
    QVBoxLayout * scrollAreaPatatine;
    QVBoxLayout * scrollAreaBibiteNome;
    QVBoxLayout * scrollAreaBibiteSize;
    QVBoxLayout * LayoutscrollAreaRimuoviProdottoNome;
    QVBoxLayout * LayoutscrollAreaRimuoviProdottoSize;
    QVBoxLayout * LayoutscrollAreaAggiungiProdottoNome;
    QVBoxLayout * LayoutscrollAreaAggiungiProdottoSize;
    QVBoxLayout * LayoutscrollAreaRimuoviBibitaMenuNome;
    QVBoxLayout * LayoutscrollAreaRimuoviPatatine;
    QVBoxLayout * LayoutscrollAreaRimuoviBibitaNome;
    QVBoxLayout * LayoutscrollAreaRimuoviBibitaSize;
    //Ui
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
