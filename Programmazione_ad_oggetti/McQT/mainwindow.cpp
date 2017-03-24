#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QVBoxLayout>
#include<QPdfWriter>
#include<sstream>
#include<QDateTime>
#include<QTextDocument>
#include<QPainter>
#include<QVector>
#include<QCheckBox>
#include<QSignalMapper>
#include<QSpinBox>
#include<QLineEdit>
#include<QRadioButton>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),control(new Controller(new Scontrino)),ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->textBrowser->setText(control->convertScontrino());
    aggiungiLayoutAggiungiPanino();
    aggiungiLayoutAggiungiMenu();
    aggiungiLayoutAggiungiBibita();
    aggiungiLayoutAggiungiPatatina();
    aggiungiLayoutRimuoviPanino();
    aggiungiLayoutRimuoviMenu();
    aggiungiLayoutRimuoviBibita();
    aggiungiLayoutRimuoviPatatina();

}

void MainWindow::aggiungiLayoutAggiungiPanino(){
    ui->scrollAreaAggiungiPanino->setStyleSheet("background-color:transparent;");
    QGridLayout* scrollAreaContenitoreLayout = new QGridLayout();
    scrollAreaVLayoutPanino = new QVBoxLayout();
    scrollAreaVLayoutPaninoQuantita = new QVBoxLayout();
    ui->scrollAreaWidgetContentsAggiungiPanino->setLayout(scrollAreaContenitoreLayout);
    scrollAreaContenitoreLayout->addLayout(scrollAreaVLayoutPanino,0,0,Qt::AlignTop);
    scrollAreaContenitoreLayout->addLayout(scrollAreaVLayoutPaninoQuantita,0,1,Qt::AlignTop);
}

void MainWindow::aggiungiLayoutAggiungiMenu(){
    ui->scrollAreaAggiungiMenu->setStyleSheet("background-color:transparent;");
    scrollAreaMenu= new QVBoxLayout();
    ui->scrollAreaWidgetContentsMenu->setLayout(scrollAreaMenu);
}

void MainWindow::aggiungiLayoutAggiungiPatatina(){
    ui->scrollAreaPatatine->setStyleSheet("background-color:transparent;");
    scrollAreaPatatine= new QVBoxLayout();
    ui->scrollAreaWidgetContentsPatatine->setLayout(scrollAreaPatatine);
}

void MainWindow::aggiungiLayoutAggiungiBibita(){
    ui->scrollAreaBibiteNome->setStyleSheet("background-color:transparent;");
    ui->scrollAreaBibiteSize->setStyleSheet("background-color:transparent;");
    scrollAreaBibiteNome= new QVBoxLayout();
    scrollAreaBibiteSize= new QVBoxLayout();
    ui->scrollAreaWidgetContentsBibiteNome->setLayout(scrollAreaBibiteNome);
    ui->scrollAreaWidgetContentsBibiteSize->setLayout(scrollAreaBibiteSize);
}

void MainWindow::aggiungiLayoutRimuoviPanino(){
    ui->scrollAreaRimuoviProdotto->setStyleSheet("background-color:transparent;");
    ui->scrollAreaAggiungiProdotto->setStyleSheet("background-color:transparent;");
    QGridLayout * RimuoviProdottoContenitore= new QGridLayout();
    QGridLayout * AggiungiProdottoContenitore= new QGridLayout();
    LayoutscrollAreaRimuoviProdottoNome=new QVBoxLayout();
    LayoutscrollAreaRimuoviProdottoSize=new QVBoxLayout();
    LayoutscrollAreaAggiungiProdottoNome=new QVBoxLayout();
    LayoutscrollAreaAggiungiProdottoSize=new QVBoxLayout();
    ui->scrollAreaWidgetContentsRimuoviProdotto->setLayout(RimuoviProdottoContenitore);
    ui->scrollAreaWidgetContentsAggiungiProdotto->setLayout(AggiungiProdottoContenitore);
    RimuoviProdottoContenitore->addLayout(LayoutscrollAreaRimuoviProdottoNome,0,0,Qt::AlignTop);
    RimuoviProdottoContenitore->addLayout(LayoutscrollAreaRimuoviProdottoSize,0,1,Qt::AlignTop);
    AggiungiProdottoContenitore->addLayout(LayoutscrollAreaAggiungiProdottoNome,0,0,Qt::AlignTop);
    AggiungiProdottoContenitore->addLayout(LayoutscrollAreaAggiungiProdottoSize,0,1,Qt::AlignTop);
}

void MainWindow::aggiungiLayoutRimuoviMenu(){
    ui->scrollAreaRimuoviMenuBibita->setStyleSheet("background-color:transparent;");
    LayoutscrollAreaRimuoviBibitaMenuNome=new QVBoxLayout();
    ui->scrollAreaWidgetContentsRimuoviBibitaMenu->setLayout(LayoutscrollAreaRimuoviBibitaMenuNome);
}

void MainWindow::aggiungiLayoutRimuoviPatatina(){
    ui->scrollAreaRimuoviPatatine->setStyleSheet("background-color:transparent;");
    LayoutscrollAreaRimuoviPatatine=new QVBoxLayout();
    ui->scrollAreaWidgetContentsRimuoviPatatine->setLayout(LayoutscrollAreaRimuoviPatatine);
}

void MainWindow::aggiungiLayoutRimuoviBibita(){
    ui->scrollAreaRimuoviBibitaNome->setStyleSheet("background-color:transparent;");
    ui->scrollAreaRimuoviBibitaSize->setStyleSheet("background-color:transparent;");
    LayoutscrollAreaRimuoviBibitaNome=new QVBoxLayout();
    LayoutscrollAreaRimuoviBibitaSize=new QVBoxLayout();
    ui->scrollAreaWidgetContentsRimuoviBibitaNome->setLayout(LayoutscrollAreaRimuoviBibitaNome);
    ui->scrollAreaWidgetContentsRimuoviBibitaSize->setLayout(LayoutscrollAreaRimuoviBibitaSize);
}

MainWindow::~MainWindow()
{
    delete control;
    delete scrollAreaVLayoutPanino;
    delete scrollAreaVLayoutPaninoQuantita;
    delete scrollAreaMenu;
    delete scrollAreaPatatine;
    delete scrollAreaBibiteNome;
    delete scrollAreaBibiteSize;
    delete LayoutscrollAreaRimuoviProdottoNome;
    delete LayoutscrollAreaRimuoviProdottoSize;
    delete LayoutscrollAreaAggiungiProdottoNome;
    delete LayoutscrollAreaAggiungiProdottoSize;
    delete LayoutscrollAreaRimuoviBibitaMenuNome;
    delete LayoutscrollAreaRimuoviPatatine;
    delete LayoutscrollAreaRimuoviBibitaNome;
    delete LayoutscrollAreaRimuoviBibitaSize;
    delete ui;
}

//Aggiungi Panino
void MainWindow::on_comboBoxPanini_currentIndexChanged(const QString &arg1)
{
    control->removeWidget(arg1,"AggiungiPanino");

    ui->PaninoQuantita->setValue(1);

    QCheckBox* addPane=new QCheckBox(tr("Pane"),&(*this));
    QCheckBox* addPaneToast=new QCheckBox(tr("Pane Tostato"),&(*this));
    QCheckBox* addHamburger=new QCheckBox(tr("Hamburger"),&(*this));
    QCheckBox* addProsciutto=new QCheckBox(tr("Prosciutto Cotto"),&(*this));
    QCheckBox* addBacon=new QCheckBox(tr("Bacon"),&(*this));
    QCheckBox* addMozzarella=new QCheckBox(tr("Mozzarella"),&(*this));
    QCheckBox* addSottilette=new QCheckBox(tr("Sottiletta"),&(*this));
    QCheckBox* addPomodoro=new QCheckBox(tr("Pomodoro"),&(*this));
    QCheckBox* addInsalata=new QCheckBox(tr("Insalata"),&(*this));
    QCheckBox* addSottoAceti=new QCheckBox(tr("Sotto Aceti"),&(*this));
    QCheckBox* addCipolla=new QCheckBox(tr("Cipolla"),&(*this));
    QCheckBox* addPeperoni=new QCheckBox(tr("Peperoni"),&(*this));
    QCheckBox* addSalsaFunghi=new QCheckBox(tr("Salsa ai Funghi"),&(*this));

    control->insertWidget(addPane,"AggiungiPanino");
    control->insertWidget(addPaneToast,"AggiungiPanino");
    control->insertWidget(addHamburger,"AggiungiPanino");
    control->insertWidget(addProsciutto,"AggiungiPanino");
    control->insertWidget(addBacon,"AggiungiPanino");
    control->insertWidget(addMozzarella,"AggiungiPanino");
    control->insertWidget(addSottilette,"AggiungiPanino");
    control->insertWidget(addPomodoro,"AggiungiPanino");
    control->insertWidget(addInsalata,"AggiungiPanino");
    control->insertWidget(addSottoAceti,"AggiungiPanino");
    control->insertWidget(addCipolla,"AggiungiPanino");
    control->insertWidget(addPeperoni,"AggiungiPanino");
    control->insertWidget(addSalsaFunghi,"AggiungiPanino");

    QSpinBox* addPaneQuantita=new QSpinBox(&(*this));
    QSpinBox* addPaneToastQuantita=new QSpinBox(&(*this));
    QSpinBox* addHamburgerQuantita=new QSpinBox(&(*this));
    QSpinBox* addProsciuttoQuantita=new QSpinBox(&(*this));
    QSpinBox* addBaconQuantita=new QSpinBox(&(*this));
    QSpinBox* addMozzarellaQuantita=new QSpinBox(&(*this));
    QSpinBox* addSottilettaQuantita=new QSpinBox(&(*this));
    QSpinBox* addPomodoroQuantita=new QSpinBox(&(*this));
    QSpinBox* addInsalataQuantita=new QSpinBox(&(*this));
    QSpinBox* addSottoAcetiQuantita=new QSpinBox(&(*this));
    QSpinBox* addCipollaQuantita=new QSpinBox(&(*this));
    QSpinBox* addPeperoniQuantita=new QSpinBox(&(*this));
    QSpinBox* addSalsaFunghiQuantita=new QSpinBox(&(*this));

    addPaneQuantita->setMinimum(1);
    addPaneToastQuantita->setMinimum(1);
    addHamburgerQuantita->setMinimum(1);
    addProsciuttoQuantita->setMinimum(1);
    addBaconQuantita->setMinimum(1);
    addMozzarellaQuantita->setMinimum(1);
    addSottilettaQuantita->setMinimum(1);
    addPomodoroQuantita->setMinimum(1);
    addInsalataQuantita->setMinimum(1);
    addSottoAcetiQuantita->setMinimum(1);
    addCipollaQuantita->setMinimum(1);
    addPeperoniQuantita->setMinimum(1);
    addSalsaFunghiQuantita->setMinimum(1);

    addPaneQuantita->setObjectName("Pane");
    addPaneToastQuantita->setObjectName("Pane Tostato");
    addHamburgerQuantita->setObjectName("Hamburger");
    addProsciuttoQuantita->setObjectName("Prosciutto Cotto");
    addBaconQuantita->setObjectName("Bacon");
    addMozzarellaQuantita->setObjectName("Mozzarella");
    addSottilettaQuantita->setObjectName("Sottiletta");
    addPomodoroQuantita->setObjectName("Pomodoro");
    addInsalataQuantita->setObjectName("Insalata");
    addSottoAcetiQuantita->setObjectName("Sotto Aceti");
    addCipollaQuantita->setObjectName("Cipolla");
    addPeperoniQuantita->setObjectName("Peperoni");
    addSalsaFunghiQuantita->setObjectName("Salsa ai Funghi");

    control->insertWidget(addPaneQuantita,"AggiungiPanino");
    control->insertWidget(addPaneToastQuantita,"AggiungiPanino");
    control->insertWidget(addHamburgerQuantita,"AggiungiPanino");
    control->insertWidget(addProsciuttoQuantita,"AggiungiPanino");
    control->insertWidget(addBaconQuantita,"AggiungiPanino");
    control->insertWidget(addMozzarellaQuantita,"AggiungiPanino");
    control->insertWidget(addSottilettaQuantita,"AggiungiPanino");
    control->insertWidget(addPomodoroQuantita,"AggiungiPanino");
    control->insertWidget(addInsalataQuantita,"AggiungiPanino");
    control->insertWidget(addSottoAcetiQuantita,"AggiungiPanino");
    control->insertWidget(addCipollaQuantita,"AggiungiPanino");
    control->insertWidget(addPeperoniQuantita,"AggiungiPanino");
    control->insertWidget(addSalsaFunghiQuantita,"AggiungiPanino");

    if(arg1=="Hamburger"){
        control->setPuntatorePanino(new Hamburger);
        scrollAreaVLayoutPanino->addWidget(addPane);
        scrollAreaVLayoutPanino->addWidget(addHamburger);
        scrollAreaVLayoutPanino->addWidget(addPomodoro);
        scrollAreaVLayoutPanino->addWidget(addInsalata);
        scrollAreaVLayoutPanino->addWidget(addSottoAceti);
        scrollAreaVLayoutPaninoQuantita->addWidget(addPaneQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addHamburgerQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addPomodoroQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addInsalataQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addSottoAcetiQuantita);

        addPaneQuantita->setMaximum(1);
        addHamburgerQuantita->setMaximum(1);
        addPomodoroQuantita->setMaximum(2);
        addInsalataQuantita->setMaximum(2);
        addSottoAcetiQuantita->setMaximum(2);
    }
    if(arg1=="Toast"){
        control->setPuntatorePanino(new Toast);
        scrollAreaVLayoutPanino->addWidget(addPaneToast);
        scrollAreaVLayoutPanino->addWidget(addSottilette);
        scrollAreaVLayoutPanino->addWidget(addProsciutto);
        scrollAreaVLayoutPaninoQuantita->addWidget(addPaneToastQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addSottilettaQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addProsciuttoQuantita);

        addPaneToastQuantita->setMaximum(1);
        addProsciuttoQuantita->setMaximum(2);
        addSottilettaQuantita->setMaximum(2);
    }
    if(arg1=="Vegetariano"){
        control->setPuntatorePanino(new Vegetariano);
        scrollAreaVLayoutPanino->addWidget(addPane);
        scrollAreaVLayoutPanino->addWidget(addMozzarella);
        scrollAreaVLayoutPanino->addWidget(addPomodoro);
        scrollAreaVLayoutPanino->addWidget(addInsalata);
        scrollAreaVLayoutPaninoQuantita->addWidget(addPaneQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addMozzarellaQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addPomodoroQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addInsalataQuantita);

        addPaneQuantita->setMaximum(1);
        addMozzarellaQuantita->setMaximum(2);
        addPomodoroQuantita->setMaximum(2);
        addInsalataQuantita->setMaximum(2);
    }

    if(arg1=="A Scelta"){
        control->setPuntatorePanino(new Panino);
        QLineEdit* lineEdit=new QLineEdit(&(*this));
        QLabel* labelnome=new QLabel("Nome:",&(*this));
        control->insertWidget(lineEdit,"AggiungiPanino");
        control->insertWidget(labelnome,"AggiungiPanino");
        ui->horizontalLayoutAggiungiDatiPanino->addWidget(labelnome);
        ui->horizontalLayoutAggiungiDatiPanino->addWidget(lineEdit);

        scrollAreaVLayoutPanino->addWidget(addPane);
        scrollAreaVLayoutPanino->addWidget(addPaneToast);
        scrollAreaVLayoutPanino->addWidget(addHamburger);
        scrollAreaVLayoutPanino->addWidget(addProsciutto);
        scrollAreaVLayoutPanino->addWidget(addBacon);
        scrollAreaVLayoutPanino->addWidget(addMozzarella);
        scrollAreaVLayoutPanino->addWidget(addSottilette);
        scrollAreaVLayoutPanino->addWidget(addPomodoro);
        scrollAreaVLayoutPanino->addWidget(addInsalata);
        scrollAreaVLayoutPanino->addWidget(addSottoAceti);
        scrollAreaVLayoutPanino->addWidget(addSalsaFunghi);
        scrollAreaVLayoutPanino->addWidget(addCipolla);
        scrollAreaVLayoutPanino->addWidget(addPeperoni);

        scrollAreaVLayoutPaninoQuantita->addWidget(addPaneQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addPaneToastQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addHamburgerQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addProsciuttoQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addBaconQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addMozzarellaQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addSottilettaQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addPomodoroQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addInsalataQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addSottoAcetiQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addSalsaFunghiQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addCipollaQuantita);
        scrollAreaVLayoutPaninoQuantita->addWidget(addPeperoniQuantita);
        connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(modificaNomePanino(QString)));
    }
        connect(addPane,SIGNAL(clicked(bool)),this,SLOT(aggiungiPane_checkBox(bool)));
        connect(addPaneToast,SIGNAL(clicked(bool)),this,SLOT(aggiungiPaneToast_checkBox(bool)));
        connect(addHamburger,SIGNAL(clicked(bool)),this,SLOT(aggiungiHamburger_checkBox(bool)));
        connect(addProsciutto,SIGNAL(clicked(bool)),this,SLOT(aggiungiProsciutto_checkBox(bool)));
        connect(addBacon,SIGNAL(clicked(bool)),this,SLOT(aggiungiBacon_checkBox(bool)));
        connect(addMozzarella,SIGNAL(clicked(bool)),this,SLOT(aggiungiMozzarella_checkBox(bool)));
        connect(addSottilette,SIGNAL(clicked(bool)),this,SLOT(aggiungiSottilette_checkBox(bool)));
        connect(addPomodoro,SIGNAL(clicked(bool)),this,SLOT(aggiungiPomodoro_checkBox(bool)));
        connect(addInsalata,SIGNAL(clicked(bool)),this,SLOT(aggiungiInsalata_checkBox(bool)));
        connect(addSottoAceti,SIGNAL(clicked(bool)),this,SLOT(aggiungiSottoAceti_checkBox(bool)));
        connect(addSalsaFunghi,SIGNAL(clicked(bool)),this,SLOT(aggiungiSalsaFunghi_checkBox(bool)));
        connect(addCipolla,SIGNAL(clicked(bool)),this,SLOT(aggiungiCipolla_checkBox(bool)));
        connect(addPeperoni,SIGNAL(clicked(bool)),this,SLOT(aggiungiPeperoni_checkBox(bool)));
        connect(ui->AggiungiPaninoButton,SIGNAL(clicked(bool)),this,SLOT(aggiungiPaninoAdScontrino()));
}

void MainWindow::modificaNomePanino(QString qs){
   control->modificaNomePanino(qs);
}


void MainWindow::on_PaninoQuantita_valueChanged(int arg1){
    control->modificaQuantitaPanino(arg1);
}

void MainWindow::aggiungiPane_checkBox(bool b){
    Prodotto prod("Pane",0.5,1);
    QSpinBox* sb= control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Pane(int)));
    else  disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Pane(int)));
}

void MainWindow::aggiungiPaneToast_checkBox(bool b){
    Prodotto prod("Pane Tostato",0.5,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_PaneToast(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_PaneToast(int)));
}

void MainWindow::aggiungiHamburger_checkBox(bool b){
    Prodotto prod("Hamburger",1,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Hamburger(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Hamburger(int)));
}

void MainWindow::aggiungiProsciutto_checkBox(bool b){
    Prodotto prod("Prosciutto Cotto",0.3,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Prosciutto(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Prosciutto(int)));
}

void MainWindow::aggiungiBacon_checkBox(bool b){
    Prodotto prod("Bacon",0.2,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Bacon(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Bacon(int)));
}

void MainWindow::aggiungiMozzarella_checkBox(bool b){
    Prodotto prod("Mozzarella",0.6,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Mozzarella(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Mozzarella(int)));
}

void MainWindow::aggiungiSottilette_checkBox(bool b){
    Prodotto prod("Sottiletta",0.2,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Sottilette(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Sottilette(int)));
}

void MainWindow::aggiungiPomodoro_checkBox(bool b){
    Prodotto prod("Pomodoro",0.2,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Pomodoro(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Pomodoro(int)));
}

void MainWindow::aggiungiInsalata_checkBox(bool b){
    Prodotto prod("Insalata",0.2,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Insalata(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Insalata(int)));
}

void MainWindow::aggiungiSottoAceti_checkBox(bool b){
    Prodotto prod("Sotto Aceti",0.1,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_SottoAceti(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_SottoAceti(int)));
}

void MainWindow::aggiungiCipolla_checkBox(bool b){
    Prodotto prod("Cipolla",0.2,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Cipolla(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Cipolla(int)));
}

void MainWindow::aggiungiPeperoni_checkBox(bool b){
    Prodotto prod("Peperoni",0.2,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Peperoni(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_Peperoni(int)));
}

void MainWindow::aggiungiSalsaFunghi_checkBox(bool b){
    Prodotto prod("Salsa ai Funghi",0.1,1);
    QSpinBox* sb=control->inserisciProdotto(prod,b);
    if(b) connect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_SalsaFunghi(int)));
    else disconnect(sb,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_SalsaFunghi(int)));
}

void MainWindow::modificaQuantita_Pane(int i){
    Prodotto prod("Pane",0.5);
    control->modificaQuantitaProdotto(i,prod);
}
void MainWindow::modificaQuantita_PaneToast(int i){
    Prodotto prod("Pane Tostato",0.5);
    control->modificaQuantitaProdotto(i,prod);
}
void MainWindow::modificaQuantita_Hamburger(int i){
    Prodotto prod("Hamburger",1);
    control->modificaQuantitaProdotto(i,prod);
}
void MainWindow::modificaQuantita_Prosciutto(int i){
    Prodotto prod("Prosciutto Cotto",0.3);
    control->modificaQuantitaProdotto(i,prod);
}
void MainWindow::modificaQuantita_Bacon(int i){
    Prodotto prod("Bacon",0.2);
    control->modificaQuantitaProdotto(i,prod);
}
void MainWindow::modificaQuantita_Mozzarella(int i){
    Prodotto prod("Mozzarella",0.6);
    control->modificaQuantitaProdotto(i,prod);
}

void MainWindow::modificaQuantita_Sottilette(int i){
    Prodotto prod("Sottiletta",0.2);
    control->modificaQuantitaProdotto(i,prod);
}

void MainWindow::modificaQuantita_Pomodoro(int i){
    Prodotto prod("Pomodoro",0.2);
    control->modificaQuantitaProdotto(i,prod);
}

void MainWindow::modificaQuantita_Insalata(int i){
    Prodotto prod("Insalata",0.2);
    control->modificaQuantitaProdotto(i,prod);
}

void MainWindow::modificaQuantita_SottoAceti(int i){
    Prodotto prod("Sotto Aceti",0.1);
    control->modificaQuantitaProdotto(i,prod);
}

void MainWindow::modificaQuantita_SalsaFunghi(int i){
    Prodotto prod("Salsa ai Funghi",0.1);
    control->modificaQuantitaProdotto(i,prod);
}

void MainWindow::modificaQuantita_Cipolla(int i){
    Prodotto prod("Cipolla",0.2);
    control->modificaQuantitaProdotto(i,prod);
}

void MainWindow::modificaQuantita_Peperoni(int i){
    Prodotto prod("Peperoni",0.2);
    control->modificaQuantitaProdotto(i,prod);
}

void MainWindow::aggiungiPaninoAdScontrino(){
    control->inserisciPanino();
    ui->textBrowser->clear();
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxPanini->setCurrentIndex(-1);
    ui->PaninoQuantita->setValue(1);
    ui->comboBoxRimuoviPanini->setCurrentIndex(0);
    ui->PaninoModificaQuantita->setValue(0);
    QVector<Panino*> pan=control->getScontrino()->listaPanino();
    int size=ui->comboBoxRimuoviPanini->count()-1;
    if(pan.size()>size)ui->comboBoxRimuoviPanini->addItem(QString::fromStdString(pan[0]->getNome()));
    disconnect(ui->AggiungiPaninoButton,SIGNAL(clicked(bool)),this,SLOT(aggiungiPaninoAdScontrino()));
}

//Aggiungi Menu
void MainWindow::on_comboBoxMenu_currentIndexChanged(const QString &arg1)
{
   control->removeWidget(arg1,"AggiungiMenu");
    ui->spinBoxQuantitaMenu->setValue(1);
    if(arg1=="MacVegetariano") control->setPuntatoreMenu(new MacVegetariano);
    if(arg1=="MacCarne"){
        control->setPuntatoreMenu(new MacCarne);
        QRadioButton* Cocacola=new QRadioButton("Cocacola",&(*this));
        QRadioButton* Sprite=new QRadioButton("Sprite",&(*this));
        QRadioButton* Fanta=new QRadioButton("Fanta",&(*this));
        QRadioButton* TheLimone=new QRadioButton("The al Limone",&(*this));
        QRadioButton* ThePesca=new QRadioButton("The alla Pesca",&(*this));
        control->insertWidget(Cocacola,"AggiungiMenu");
        control->insertWidget(Sprite,"AggiungiMenu");
        control->insertWidget(Fanta,"AggiungiMenu");
        control->insertWidget(TheLimone,"AggiungiMenu");
        control->insertWidget(ThePesca,"AggiungiMenu");
        scrollAreaMenu->addWidget(Cocacola);
        scrollAreaMenu->addWidget(Sprite);
        scrollAreaMenu->addWidget(Fanta);
        scrollAreaMenu->addWidget(TheLimone);
        scrollAreaMenu->addWidget(ThePesca);
        connect(Cocacola,SIGNAL(clicked(bool)),this,SLOT(aggiungiCocacola_RadioButton()));
        connect(Sprite,SIGNAL(clicked(bool)),this,SLOT(aggiungiSprite_RadioButton()));
        connect(Fanta,SIGNAL(clicked(bool)),this,SLOT(aggiungiFanta_RadioButton()));
        connect(TheLimone,SIGNAL(clicked(bool)),this,SLOT(aggiungiTheLimone_RadioButton()));
        connect(ThePesca,SIGNAL(clicked(bool)),this,SLOT(aggiungiThePesca_RadioButton()));
    }
}

void MainWindow::aggiungiCocacola_RadioButton(){
    control->modificaNomeBibitaMenu("Cocacola");
}

void MainWindow::aggiungiSprite_RadioButton(){
    control->modificaNomeBibitaMenu("Sprite");
}

void MainWindow::aggiungiFanta_RadioButton(){
    control->modificaNomeBibitaMenu("Fanta");
}

void MainWindow::aggiungiTheLimone_RadioButton(){
control->modificaNomeBibitaMenu("The al Limone");
}

void MainWindow::aggiungiThePesca_RadioButton(){
control->modificaNomeBibitaMenu("The alla Pesca");
}

void MainWindow::on_spinBoxQuantitaMenu_valueChanged(int arg1){
    control->modificaQuantitaMenu(arg1);
}


void MainWindow::on_pushButtonAggiungiMenu_clicked()
{
    control->inserisciMenu();
    ui->textBrowser->clear();
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxMenu->setCurrentIndex(-1);
    ui->spinBoxQuantitaMenu->setValue(1);
    ui->comboBoxRimuoviMenu->setCurrentIndex(0);
    ui->MenuModificaQuantita->setValue(0);
    QVector<Menu*> men=control->getScontrino()->listaMenu();
    int size=ui->comboBoxRimuoviMenu->count()-1;
    if(men.size()>size)ui->comboBoxRimuoviMenu->addItem(QString::fromStdString(men[0]->getNome()));
}

//Aggiungi Patatine
void MainWindow::on_comboBoxPatatine_currentIndexChanged(const QString &arg1)
{
    control->removeWidget(arg1,"AggiungiPatatine");
    ui->spinBoxQuantitaPatatine->setValue(1);
    QRadioButton* Piccola=new QRadioButton("Piccola",&(*this));
    QRadioButton* Media=new QRadioButton("Media",&(*this));
    QRadioButton* Grande=new QRadioButton("Grande",&(*this));
    QRadioButton* ExtraGrande=new QRadioButton("ExtraGrande",&(*this));
    if(arg1=="Lesse" || arg1=="Fritte"){
       if(arg1=="Lesse") control->setPuntatorePatatina(new Patatina("Lesse",1));
       if(arg1=="Fritte") control->setPuntatorePatatina(new Patatina("Fritta",1));
       control->insertWidget(Piccola,"AggiungiPatatine");
       control->insertWidget(Media,"AggiungiPatatine");
       control->insertWidget(Grande,"AggiungiPatatine");
       control->insertWidget(ExtraGrande,"AggiungiPatatine");
       scrollAreaPatatine->addWidget(Piccola);
       scrollAreaPatatine->addWidget(Media);
       scrollAreaPatatine->addWidget(Grande);
       scrollAreaPatatine->addWidget(ExtraGrande);
    }
    connect(Piccola,SIGNAL(clicked(bool)),this,SLOT(aggiungiPiccola_RadioButton()));
    connect(Media,SIGNAL(clicked(bool)),this,SLOT(aggiungiMedia_RadioButton()));
    connect(Grande,SIGNAL(clicked(bool)),this,SLOT(aggiungiGrande_RadioButton()));
    connect(ExtraGrande,SIGNAL(clicked(bool)),this,SLOT(aggiungiExtraGrande_RadioButton()));
}

void MainWindow::aggiungiPiccola_RadioButton(){control->modificaSizePatatina("S");}
void MainWindow::aggiungiMedia_RadioButton(){control->modificaSizePatatina("M");}
void MainWindow::aggiungiGrande_RadioButton(){control->modificaSizePatatina("L");}
void MainWindow::aggiungiExtraGrande_RadioButton(){control->modificaSizePatatina("XL");}

void MainWindow::on_spinBoxQuantitaPatatine_valueChanged(int arg1){
    control->modificaQuantitaPatatina(arg1);
}

void MainWindow::on_pushButtonAggiungiPatatine_clicked(){
    control->inserisciPatatina();
    ui->textBrowser->clear();
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxPatatine->setCurrentIndex(-1);
    ui->spinBoxQuantitaPatatine->setValue(1);
    ui->comboBoxRimuoviPatatine->setCurrentIndex(0);
    ui->PatatineModificaQuantita->setValue(0);
    QVector<Patatina*> pat=control->getScontrino()->listaPatatina();
    int size=ui->comboBoxRimuoviPatatine->count()-1;
    if(pat.size()>size)ui->comboBoxRimuoviPatatine->addItem(QString::fromStdString(pat[0]->getNome()));
}

//Aggiungi Bibite
void MainWindow::on_comboBoxBibite_currentIndexChanged(const QString &arg1)
{
    control->removeWidget(arg1,"AggiungiBibita");
    ui->spinBoxQuantitaBibite->setValue(1);
    if(arg1=="Bibita"){
        control->setPuntatoreBibita(new Bibita("Cocacola",1,1,"S"));
        QRadioButton* Cocacola=new QRadioButton("Cocacola",&(*this));
        QRadioButton* Sprite=new QRadioButton("Sprite",&(*this));
        QRadioButton* Fanta=new QRadioButton("Fanta",&(*this));
        QRadioButton* TheLimone=new QRadioButton("The al Limone",&(*this));
        QRadioButton* ThePesca=new QRadioButton("The alla Pesca",&(*this));
        QRadioButton* Piccola=new QRadioButton("Piccola",&(*this));
        QRadioButton* Media=new QRadioButton("Media",&(*this));
        QRadioButton* Grande=new QRadioButton("Grande",&(*this));
        control->insertWidget(Cocacola,"AggiungiBibita");
        control->insertWidget(Sprite,"AggiungiBibita");
        control->insertWidget(Fanta,"AggiungiBibita");
        control->insertWidget(TheLimone,"AggiungiBibita");
        control->insertWidget(ThePesca,"AggiungiBibita");
        scrollAreaBibiteNome->addWidget(Cocacola);
        scrollAreaBibiteNome->addWidget(Sprite);
        scrollAreaBibiteNome->addWidget(Fanta);
        scrollAreaBibiteNome->addWidget(TheLimone);
        scrollAreaBibiteNome->addWidget(ThePesca);
        control->insertWidget(Piccola,"AggiungiBibita");
        control->insertWidget(Media,"AggiungiBibita");
        control->insertWidget(Grande,"AggiungiBibita");
        scrollAreaBibiteSize->addWidget(Piccola);
        scrollAreaBibiteSize->addWidget(Media);
        scrollAreaBibiteSize->addWidget(Grande);
        connect(Cocacola,SIGNAL(clicked(bool)),this,SLOT(aggiungiCocacolaBibita_RadioButton()));
        connect(Sprite,SIGNAL(clicked(bool)),this,SLOT(aggiungiSpriteBibita_RadioButton()));
        connect(Fanta,SIGNAL(clicked(bool)),this,SLOT(aggiungiFantaBibita_RadioButton()));
        connect(TheLimone,SIGNAL(clicked(bool)),this,SLOT(aggiungiTheLimoneBibita_RadioButton()));
        connect(ThePesca,SIGNAL(clicked(bool)),this,SLOT(aggiungiThePescaBibita_RadioButton()));
        connect(Piccola,SIGNAL(clicked(bool)),this,SLOT(aggiungiPiccolaBibita_RadioButton()));
        connect(Media,SIGNAL(clicked(bool)),this,SLOT(aggiungiMediaBibita_RadioButton()));
        connect(Grande,SIGNAL(clicked(bool)),this,SLOT(aggiungiGrandeBibita_RadioButton()));
    }
    if(arg1=="Acqua"){
        control->setPuntatoreBibita(new Acqua("Naturale",1,"0.5L"));
        QRadioButton* Naturale=new QRadioButton("Naturale",&(*this));
        QRadioButton* Frizzante=new QRadioButton("Frizzante",&(*this));
        QRadioButton* MezzoLitro=new QRadioButton("0.5L",&(*this));
        QRadioButton* UnLitro=new QRadioButton("1L",&(*this));
        control->insertWidget(Naturale,"AggiungiBibita");
        control->insertWidget(Frizzante,"AggiungiBibita");
        control->insertWidget(MezzoLitro,"AggiungiBibita");
        control->insertWidget(UnLitro,"AggiungiBibita");
        scrollAreaBibiteNome->addWidget(Naturale);
        scrollAreaBibiteNome->addWidget(Frizzante);
        scrollAreaBibiteSize->addWidget(MezzoLitro);
        scrollAreaBibiteSize->addWidget(UnLitro);
        connect(Naturale,SIGNAL(clicked(bool)),this,SLOT(aggiungiNaturale_RadioButton()));
        connect(Frizzante,SIGNAL(clicked(bool)),this,SLOT(aggiungiFrizzante_RadioButton()));
        connect(MezzoLitro,SIGNAL(clicked(bool)),this,SLOT(aggiungiL05_RadioButton()));
        connect(UnLitro,SIGNAL(clicked(bool)),this,SLOT(aggiungiL1_RadioButton()));
    }
    if(arg1=="Birra"){
        control->setPuntatoreBibita(new Birra("Bionda",2,1,"0.33L"));
        QRadioButton* Bionda=new QRadioButton("Bionda",&(*this));
        QRadioButton* Rossa=new QRadioButton("Rossa",&(*this));
        QRadioButton* L033=new QRadioButton("0.33L",&(*this));
        QRadioButton* L066=new QRadioButton("0.66L",&(*this));
        control->insertWidget(Bionda,"AggiungiBibita");
        control->insertWidget(Rossa,"AggiungiBibita");
        control->insertWidget(L033,"AggiungiBibita");
        control->insertWidget(L066,"AggiungiBibita");
        scrollAreaBibiteNome->addWidget(Bionda);
        scrollAreaBibiteNome->addWidget(Rossa);
        scrollAreaBibiteSize->addWidget(L033);
        scrollAreaBibiteSize->addWidget(L066);
        connect(Bionda,SIGNAL(clicked(bool)),this,SLOT(aggiungiBionda_RadioButton()));
        connect(Rossa,SIGNAL(clicked(bool)),this,SLOT(aggiungiRossa_RadioButton()));
        connect(L033,SIGNAL(clicked(bool)),this,SLOT(aggiungiL033_RadioButton()));
        connect(L066,SIGNAL(clicked(bool)),this,SLOT(aggiungiL066_RadioButton()));
    }

}
void MainWindow::on_spinBoxQuantitaBibite_valueChanged(int arg1)
{
    control->modificaQuantitaBibita(arg1);
}

void MainWindow::on_pushButtonAggiungiBibite_clicked()
{
    control->inserisciBibita();
    ui->textBrowser->clear();
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxBibite->setCurrentIndex(-1);
    ui->spinBoxQuantitaBibite->setValue(1);
    ui->comboBoxRimuoviBibite->setCurrentIndex(0);
    ui->BibitaModificaQuantita->setValue(0);
    QVector<Bibita*> bib=control->getScontrino()->listaBibita();
    int size=ui->comboBoxRimuoviBibite->count()-1;
    if(bib.size()>size)ui->comboBoxRimuoviBibite->addItem(QString::fromStdString(bib[0]->getNome()));
}


void MainWindow::aggiungiCocacolaBibita_RadioButton(){
    control->setBibitaNome("Cocacola");
}

void MainWindow::aggiungiSpriteBibita_RadioButton(){
    control->setBibitaNome("Sprite");
}

void MainWindow::aggiungiFantaBibita_RadioButton(){
    control->setBibitaNome("Fanta");
}

void MainWindow::aggiungiTheLimoneBibita_RadioButton(){
    control->setBibitaNome("The al Limone");
}

void MainWindow::aggiungiThePescaBibita_RadioButton(){
    control->setBibitaNome("The alla Pesca");
}

void MainWindow::aggiungiPiccolaBibita_RadioButton(){
    control->setBibitaSize("S");
}

void MainWindow::aggiungiMediaBibita_RadioButton(){
    control->setBibitaSize("M");
}

void MainWindow::aggiungiGrandeBibita_RadioButton(){
    control->setBibitaSize("L");
}
void MainWindow::aggiungiNaturale_RadioButton(){
    control->setBibitaNome("Naturale");
}

void MainWindow::aggiungiFrizzante_RadioButton(){
    control->setBibitaNome("Frizzante");
}

void MainWindow::aggiungiL05_RadioButton(){
    control->setBibitaSize("0.5L");
}

void MainWindow::aggiungiL1_RadioButton(){
    control->setBibitaSize("1L");
}

void MainWindow::aggiungiBionda_RadioButton(){
    control->setBibitaNome("Bionda");
}

void MainWindow::aggiungiRossa_RadioButton(){
    control->setBibitaNome("Rossa");
}

void MainWindow::aggiungiL033_RadioButton(){
    control->setBibitaSize("0.33L");
}

void MainWindow::aggiungiL066_RadioButton(){
    control->setBibitaSize("0.66L");
}

//RimuoviPanino
void MainWindow::on_comboBoxRimuoviPanini_currentIndexChanged(int index)
{
    control->removeWidget("","RimuoviPanino");
    if(index>0){
    QVector<Panino*> pan=control->getScontrino()->listaPanino();
    control->setPuntatoreRimuoviPanino(pan.value(pan.size()-index));
    ui->PaninoModificaQuantita->setValue(control->getPuntatoreRimuoviPanino()->getQuantita());
    for(Panino::iteratore it=control->getPuntatoreRimuoviPanino()->begin();it!=control->getPuntatoreRimuoviPanino()->end();it++){
        QCheckBox* qcheckbox=new QCheckBox(QString::fromStdString((*control->getPuntatoreRimuoviPanino())[it].getNome()),this);
        QSpinBox* qspinbox=new QSpinBox(this);
        qspinbox->setObjectName(QString::fromStdString((*control->getPuntatoreRimuoviPanino())[it].getNome()));
        Hamburger* h=dynamic_cast<Hamburger*>(control->getPuntatoreRimuoviPanino());
        Vegetariano* v=dynamic_cast<Vegetariano*>(control->getPuntatoreRimuoviPanino());
        Toast* t=dynamic_cast<Toast*>(control->getPuntatoreRimuoviPanino());
        if(h) {
            if(qcheckbox->text()=="Pane" || qcheckbox->text()=="Hamburger")qspinbox->setMaximum(1);
            else qspinbox->setMaximum(2);
        }
        if(v){
            if(qcheckbox->text()=="Pane") qspinbox->setMaximum(1);
            else qspinbox->setMaximum(2);
        }
        if(t){
            if(qcheckbox->text()=="Pane Tostato") qspinbox->setMaximum(1);
            else qspinbox->setMaximum(2);
        }
        control->insertWidget(qcheckbox,"RimuoviPanino");
        control->insertWidget(qspinbox,"RimuoviPanino");
        qspinbox->setMinimum(1);
        qspinbox->setValue((*control->getPuntatoreRimuoviPanino())[it].getQuantita());
        LayoutscrollAreaRimuoviProdottoNome->addWidget(qcheckbox);
        LayoutscrollAreaRimuoviProdottoSize->addWidget(qspinbox);
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Pane"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviPane_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_PaneRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Pane Tostato"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviPaneToast_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_PaneToastRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Hamburger"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviHamburger_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_HamburgerRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Prosciutto Cotto"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviProsciutto_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_ProsciuttoRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Bacon"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviBacon_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_BaconRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Mozzarella"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviMozzarella_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_MozzarellaRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Sottiletta"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviSottiletta_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_SottilettaRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Pomodoro"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviPomodoro_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_PomodoroRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Insalata"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviInsalata_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_InsalataRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Sotto Aceti"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviSottoAceti_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_SottoAcetiRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Salsa ai Funghi"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviSalsaFunghi_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_SalsaFunghiRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Cipolla"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviCipolla_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_CipollaRimuoviProdotto(int)));
        }
        if((*control->getPuntatoreRimuoviPanino())[it].getNome()=="Peperoni"){
            connect(qcheckbox,SIGNAL(clicked(bool)),this,SLOT(RimuoviPeperoni_checkBox(bool)));
            connect(qspinbox,SIGNAL(valueChanged(int)),this,SLOT(modificaQuantita_PeperoniRimuoviProdotto(int)));
        }
    }
    for(int i=0;i<control->getNomiProdotti().size();i++){
        bool trovato=true;
        int size=control->getRimuoviProdotto().size();
        for(int j=0;j<size;j++){
            QCheckBox* checkbox=dynamic_cast<QCheckBox*>(control->getRimuoviProdotto().at(j));
            if(checkbox){
               if((*checkbox).text()==control->getNomiProdotti().at(i))
               trovato=false;
            }
        }
        if(trovato){
            Hamburger* h=dynamic_cast<Hamburger*>(control->getPuntatoreRimuoviPanino());
            Toast* t=dynamic_cast<Toast*>(control->getPuntatoreRimuoviPanino());
            Vegetariano* v=dynamic_cast<Vegetariano*>(control->getPuntatoreRimuoviPanino());
            if(h || v || t){
               if(h && (control->getNomiProdotti().at(i)=="Insalata" || control->getNomiProdotti().at(i)=="Pomodoro" || control->getNomiProdotti().at(i)=="Sotto Aceti")){
                  QCheckBox* aggiungiProdotto=new QCheckBox(control->getNomiProdotti().at(i).at(i),this);
                  control->insertWidget(aggiungiProdotto,"RimuoviPanino");
                  LayoutscrollAreaAggiungiProdottoNome->addWidget(aggiungiProdotto);
                  if(control->getNomiProdotti().at(i)=="Pomodoro"){
                      connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiPomodoroRimuoviPanino_checkBox(bool)));
                  }
                  if(control->getNomiProdotti().at(i)=="Insalata"){
                      connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiInsalataRimuoviPanino_checkBox(bool)));
                  }
                  if(control->getNomiProdotti().at(i)=="Sotto Aceti"){
                      connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiSottoAcetiRimuoviPanino_checkBox(bool)));
                  }
               }
               if(v && control->getNomiProdotti().at(i)=="Insalata"){
                   QCheckBox* aggiungiProdotto=new QCheckBox(control->getNomiProdotti().at(i),this);
                   control->insertWidget(aggiungiProdotto,"RimuoviPanino");
                   LayoutscrollAreaAggiungiProdottoNome->addWidget(aggiungiProdotto);
                   if(control->getNomiProdotti().at(i)=="Insalata"){
                       connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiInsalataRimuoviPanino_checkBox(bool)));
                   }
               }
               if(t && control->getNomiProdotti().at(i)=="Salsa ai Funghi"){
                   QCheckBox* aggiungiProdotto=new QCheckBox(control->getNomiProdotti().at(i),this);
                   control->insertWidget(aggiungiProdotto,"RimuoviPanino");
                   LayoutscrollAreaAggiungiProdottoNome->addWidget(aggiungiProdotto);
                   if(control->getNomiProdotti().at(i)=="Salsa ai Funghi"){
                      connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiSalsaFunghiRimuoviPanino_checkBox(bool)));
                   }
               }
            }
            else{
                QCheckBox* aggiungiProdotto=new QCheckBox(control->getNomiProdotti().at(i),this);
                control->insertWidget(aggiungiProdotto,"RimuoviPanino");
                LayoutscrollAreaAggiungiProdottoNome->addWidget(aggiungiProdotto);
                if(control->getNomiProdotti().at(i)=="Pane"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiPaneRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Pane Tostato"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiPaneToastRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Hamburger"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiHamburgerRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Prosciutto Cotto"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiProsciuttoRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Bacon"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiBaconRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Mozzarella"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiMozzarellaRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Sottiletta"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiSottiletteRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Pomodoro"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiPomodoroRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Insalata"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiInsalataRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Sotto Aceti"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiSottoAcetiRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Salsa ai Funghi"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiSalsaFunghiRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Cipolla"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiCipollaRimuoviPanino_checkBox(bool)));
                }
                if(control->getNomiProdotti().at(i)=="Peperoni"){
                   connect(aggiungiProdotto,SIGNAL(clicked(bool)),this,SLOT(aggiungiPeperoniRimuoviPanino_checkBox(bool)));
                }
            }
        }
    }
    }
}


void MainWindow::on_RimuoviPaninoButton_clicked()
{
    QVector<Panino*> pan=control->getScontrino()->listaPanino();
    int index=ui->comboBoxRimuoviPanini->currentIndex();
    if(index>0){
        control->getScontrino()->rimuoviPanino(*pan.value(pan.size()-index));
    ui->comboBoxRimuoviPanini->removeItem(index);
    ui->PaninoModificaQuantita->setValue(1);
    ui->comboBoxRimuoviPanini->setCurrentIndex(0);  
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
    }
}

void MainWindow::on_PaninoModificaQuantita_valueChanged(int arg1)
{   int index=ui->comboBoxRimuoviPanini->currentIndex();
    if(index>0){
    QVector<Panino*> pan=control->getScontrino()->listaPanino();
    pan.at(pan.size()-index)->setQuantita(arg1);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
    }
}

void MainWindow::RimuoviPane_checkBox(bool b){
    Prodotto prod("Pane",0.5,1);
    if(b && !dynamic_cast<Hamburger*>(control->getPuntatoreRimuoviPanino()) && !dynamic_cast<Vegetariano*>(control->getPuntatoreRimuoviPanino())){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_PaneRimuoviProdotto(int i){
    Prodotto prod("Pane",0.5);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}


void MainWindow::RimuoviPaneToast_checkBox(bool b){
    Prodotto prod("Pane Tostato",0.5,1);
    if(b && !dynamic_cast<Toast*>(control->getPuntatoreRimuoviPanino())){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_PaneToastRimuoviProdotto(int i){
    Prodotto prod("Pane Tostato",0.5);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviHamburger_checkBox(bool b){
    Prodotto prod("Hamburger",1,1);
    if(b && !dynamic_cast<Hamburger*>(control->getPuntatoreRimuoviPanino())){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_HamburgerRimuoviProdotto(int i){
    Prodotto prod("Hamburger",1);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviProsciutto_checkBox(bool b){
    Prodotto prod("Prosciutto Cotto",0.3,1);
    if(b && !dynamic_cast<Toast*>(control->getPuntatoreRimuoviPanino())){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_ProsciuttoRimuoviProdotto(int i){
    Prodotto prod("Prosciutto Cotto",0.3);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviBacon_checkBox(bool b){
    Prodotto prod("Bacon",0.2,1);
    if(b){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_BaconRimuoviProdotto(int i){
    Prodotto prod("Bacon",0.2);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviMozzarella_checkBox(bool b){
    Prodotto prod("Mozzarella",0.6,1);
    if(b && !dynamic_cast<Vegetariano*>(control->getPuntatoreRimuoviPanino())){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_MozzarellaRimuoviProdotto(int i){
    Prodotto prod("Mozzarella",0.6);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviSottiletta_checkBox(bool b){
    Prodotto prod("Sottiletta",0.2,1);
    if(b && !dynamic_cast<Toast*>(control->getPuntatoreRimuoviPanino())){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_SottilettaRimuoviProdotto(int i){
    Prodotto prod("Sottiletta",0.2);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviPomodoro_checkBox(bool b){
    Prodotto prod("Pomodoro",0.2,1);
    if(b && !dynamic_cast<Vegetariano*>(control->getPuntatoreRimuoviPanino())){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_PomodoroRimuoviProdotto(int i){
    Prodotto prod("Pomodoro",0.2);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviInsalata_checkBox(bool b){
    Prodotto prod("Insalata",0.2,1);
    if(b){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_InsalataRimuoviProdotto(int i){
    Prodotto prod("Insalata",0.2);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviSottoAceti_checkBox(bool b){
    Prodotto prod("Sotto Aceti",0.1,1);
    if(b){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_SottoAcetiRimuoviProdotto(int i){
    Prodotto prod("Sotto Aceti",0.1);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviSalsaFunghi_checkBox(bool b){
    Prodotto prod("Salsa ai Funghi",0.1,1);
    if(b){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_SalsaFunghiRimuoviProdotto(int i){
    Prodotto prod("Salsa ai Funghi",0.1);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviCipolla_checkBox(bool b){
    Prodotto prod("Cipolla",0.2,1);
    if(b){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_CipollaRimuoviProdotto(int i){
    Prodotto prod("Cipolla",0.2);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}

void MainWindow::RimuoviPeperoni_checkBox(bool b){
    Prodotto prod("Peperoni",0.2,1);
    if(b){
        control->rimuoviProdottoInPanino(prod);
        QString out=control->convertScontrino();
        ui->textBrowser->setText(out);
        ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
        ui->PaninoModificaQuantita->setValue(1);
    }
}

void MainWindow::modificaQuantita_PeperoniRimuoviProdotto(int i){
    Prodotto prod("Peperoni",0.2);
    control->rimuoviProdottoInPaninoQuantita(prod,i);
    QString out=control->convertScontrino();
    ui->textBrowser->setText(out);
}


void MainWindow::aggiungiPaneRimuoviPanino_checkBox(bool b){
    Prodotto prod("Pane",0.5,1);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiPaneToastRimuoviPanino_checkBox(bool b){
    Prodotto prod("Pane Tostato",0.5);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiHamburgerRimuoviPanino_checkBox(bool b){
    Prodotto prod("Hamburger",0.5);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiProsciuttoRimuoviPanino_checkBox(bool b){
    Prodotto prod("Prosciutto Cotto",0.3);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiBaconRimuoviPanino_checkBox(bool b){
    Prodotto prod("Bacon",0.2);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiMozzarellaRimuoviPanino_checkBox(bool b){
    Prodotto prod("Mozzarella",0.6);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiSottiletteRimuoviPanino_checkBox(bool b){
    Prodotto prod("Sottiletta",0.2);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiPomodoroRimuoviPanino_checkBox(bool b){
    Prodotto prod("Pomodoro",0.2);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiInsalataRimuoviPanino_checkBox(bool b){
    Prodotto prod("Insalata",0.2);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiSottoAcetiRimuoviPanino_checkBox(bool b){
    Prodotto prod("Sotto Aceti",0.1);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiSalsaFunghiRimuoviPanino_checkBox(bool b){
    Prodotto prod("Salsa ai Funghi",0.1);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiCipollaRimuoviPanino_checkBox(bool b){
    Prodotto prod("Cipolla",0.2);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

void MainWindow::aggiungiPeperoniRimuoviPanino_checkBox(bool b){
    Prodotto prod("Peperoni",0.2);
    control->aggiungiProdottoRimuoviPanini(prod,b);
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(-1);
    ui->PaninoModificaQuantita->setValue(1);
}

//Rimuovi Menu
void MainWindow::on_comboBoxRimuoviMenu_currentIndexChanged(int index)
{
    control->removeWidget("","RimuoviMenu");

    if(index>0){
       QVector<Menu*> men=control->getScontrino()->listaMenu();
       control->setPuntatoreRimuoviMenu(men.value(men.size()-index));
       ui->MenuModificaQuantita->setValue(control->getPuntatoreRimuoviMenu()->getQuantita());
       MacCarne* m=dynamic_cast<MacCarne*>(control->getPuntatoreRimuoviMenu());
       if(m){
           QRadioButton* Cocacola=new QRadioButton("Cocacola",&(*this));
           QRadioButton* Sprite=new QRadioButton("Sprite",&(*this));
           QRadioButton* Fanta=new QRadioButton("Fanta",&(*this));
           QRadioButton* TheLimone=new QRadioButton("The al Limone",&(*this));
           QRadioButton* ThePesca=new QRadioButton("The alla Pesca",&(*this));
           control->insertWidget(Cocacola,"RimuoviMenu");
           control->insertWidget(Sprite,"RimuoviMenu");
           control->insertWidget(Fanta,"RimuoviMenu");
           control->insertWidget(TheLimone,"RimuoviMenu");
           control->insertWidget(ThePesca,"RimuoviMenu");
           LayoutscrollAreaRimuoviBibitaMenuNome->addWidget(Cocacola);
           LayoutscrollAreaRimuoviBibitaMenuNome->addWidget(Sprite);
           LayoutscrollAreaRimuoviBibitaMenuNome->addWidget(Fanta);
           LayoutscrollAreaRimuoviBibitaMenuNome->addWidget(TheLimone);
           LayoutscrollAreaRimuoviBibitaMenuNome->addWidget(ThePesca);
           if(QString::fromStdString(m->getBibita().getNome())==Cocacola->text()) Cocacola->setChecked(true);
           if(QString::fromStdString(m->getBibita().getNome())==Sprite->text()) Sprite->setChecked(true);
           if(QString::fromStdString(m->getBibita().getNome())==Fanta->text()) Fanta->setChecked(true);
           if(QString::fromStdString(m->getBibita().getNome())==TheLimone->text()) TheLimone->setChecked(true);
           if(QString::fromStdString(m->getBibita().getNome())==ThePesca->text()) ThePesca->setChecked(true);
           connect(Cocacola,SIGNAL(clicked(bool)),this,SLOT(aggiungiCocacolaRimuoviMenu_RadioButton()));
           connect(Sprite,SIGNAL(clicked(bool)),this,SLOT(aggiungiSpriteRimuoviMenu_RadioButton()));
           connect(Fanta,SIGNAL(clicked(bool)),this,SLOT(aggiungiFantaRimuoviMenu_RadioButton()));
           connect(TheLimone,SIGNAL(clicked(bool)),this,SLOT(aggiungiTheLimoneRimuoviMenu_RadioButton()));
           connect(ThePesca,SIGNAL(clicked(bool)),this,SLOT(aggiungiThePescaRimuoviMenu_RadioButton()));
       }

    }
}

void MainWindow::aggiungiCocacolaRimuoviMenu_RadioButton(){
    control->modificaNomeBibitaRimuoviMenu("Cocacola");
    ui->comboBoxRimuoviMenu->setCurrentIndex(0);
}

void MainWindow::aggiungiSpriteRimuoviMenu_RadioButton(){
    control->modificaNomeBibitaRimuoviMenu("Sprite");
    ui->comboBoxRimuoviMenu->setCurrentIndex(0);
}

void MainWindow::aggiungiFantaRimuoviMenu_RadioButton(){
    control->modificaNomeBibitaRimuoviMenu("Fanta");
    ui->comboBoxRimuoviMenu->setCurrentIndex(0);
}

void MainWindow::aggiungiTheLimoneRimuoviMenu_RadioButton(){
    control->modificaNomeBibitaRimuoviMenu("The al Limone");
    ui->comboBoxRimuoviMenu->setCurrentIndex(0);
}

void MainWindow::aggiungiThePescaRimuoviMenu_RadioButton(){
    control->modificaNomeBibitaRimuoviMenu("The alla Pesca");
    ui->comboBoxRimuoviMenu->setCurrentIndex(0);
}

void MainWindow::on_MenuModificaQuantita_valueChanged(int arg1)
{
    int index=ui->comboBoxRimuoviMenu->currentIndex();
    if(index>0){
    QVector<Menu*> man=control->getScontrino()->listaMenu();
    int index=ui->comboBoxRimuoviMenu->currentIndex();
    man.at(man.size()-index)->setQuantita(arg1);
    ui->textBrowser->setText(control->convertScontrino());
    }
}

void MainWindow::on_RimuoviMenuButton_clicked()
{
    QVector<Menu*> men=control->getScontrino()->listaMenu();
    int index=ui->comboBoxRimuoviMenu->currentIndex();
    if(index>0){
    control->getScontrino()->rimuoviMenu(*men.value(men.size()-index));
    ui->comboBoxRimuoviMenu->removeItem(index);
    ui->MenuModificaQuantita->setValue(1);
    ui->comboBoxRimuoviMenu->setCurrentIndex(0);
    ui->textBrowser->setText(control->convertScontrino());
    }
}

void MainWindow::on_comboBoxRimuoviPatatine_currentIndexChanged(int index)
{

    control->removeWidget("","RimuoviPatatine");
    if(index>0){
       QVector<Patatina*> pat=control->getScontrino()->listaPatatina();
       control->setPuntatoreRimuoviPatatina(pat.value(pat.size()-index));
       ui->PatatineModificaQuantita->setValue(control->getPuntatoreRimuoviPatatina()->getQuantita());
       QRadioButton* Piccola=new QRadioButton("Piccola",&(*this));
       QRadioButton* Media=new QRadioButton("Media",&(*this));
       QRadioButton* Grande=new QRadioButton("Grande",&(*this));
       QRadioButton* ExtraGrande=new QRadioButton("Extra Grande",&(*this));
       control->insertWidget(Piccola,"RimuoviPatatine");
       control->insertWidget(Media,"RimuoviPatatine");
       control->insertWidget(Grande,"RimuoviPatatine");
       control->insertWidget(ExtraGrande,"RimuoviPatatine");
       LayoutscrollAreaRimuoviPatatine->addWidget(Piccola);
       LayoutscrollAreaRimuoviPatatine->addWidget(Media);
       LayoutscrollAreaRimuoviPatatine->addWidget(Grande);
       LayoutscrollAreaRimuoviPatatine->addWidget(ExtraGrande);
       if(control->getPuntatoreRimuoviPatatina()->getSize()=="S") Piccola->setChecked(true);
       if(control->getPuntatoreRimuoviPatatina()->getSize()=="M") Media->setChecked(true);
       if(control->getPuntatoreRimuoviPatatina()->getSize()=="L") Grande->setChecked(true);
       if(control->getPuntatoreRimuoviPatatina()->getSize()=="XL") ExtraGrande->setChecked(true);
       connect(Piccola,SIGNAL(clicked(bool)),this,SLOT(aggiungiPiccolaRimuoviPatatine_RadioButton()));
       connect(Media,SIGNAL(clicked(bool)),this,SLOT(aggiungiMediaRimuoviPatatine_RadioButton()));
       connect(Grande,SIGNAL(clicked(bool)),this,SLOT(aggiungiGrandeRimuoviPatatine_RadioButton()));
       connect(ExtraGrande,SIGNAL(clicked(bool)),this,SLOT(aggiungiExtraGrandeRimuoviPatatine_RadioButton()));
    }
}

void MainWindow::aggiungiPiccolaRimuoviPatatine_RadioButton(){
    control->modificaSizeRimuoviPatatina("S");
    ui->textBrowser->setText(control->convertScontrino());
}
void MainWindow::aggiungiMediaRimuoviPatatine_RadioButton(){
    control->modificaSizeRimuoviPatatina("M");
    ui->textBrowser->setText(control->convertScontrino());
}
void MainWindow::aggiungiGrandeRimuoviPatatine_RadioButton(){
    control->modificaSizeRimuoviPatatina("L");
    ui->textBrowser->setText(control->convertScontrino());
}
void MainWindow::aggiungiExtraGrandeRimuoviPatatine_RadioButton(){
    control->modificaSizeRimuoviPatatina("XL");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::on_PatatineModificaQuantita_valueChanged(int arg1)
{
    int index=ui->comboBoxRimuoviPatatine->currentIndex();
    if(index>0){
    QVector<Patatina*> pat=control->getScontrino()->listaPatatina();
    pat.at(pat.size()-index)->setQuantita(arg1);
    ui->textBrowser->setText(control->convertScontrino());
    }
}

void MainWindow::on_RimuoviPatatineButton_clicked()
{
    QVector<Patatina*> pat=control->getScontrino()->listaPatatina();
    int index=ui->comboBoxRimuoviPatatine->currentIndex();
    if(index>0){
    control->getScontrino()->rimuoviPatatina(*pat.value(pat.size()-index));
    ui->comboBoxRimuoviPatatine->removeItem(index);
    ui->PatatineModificaQuantita->setValue(1);
    ui->comboBoxRimuoviPatatine->setCurrentIndex(0);
    ui->textBrowser->setText(control->convertScontrino());
    }
}

//Rimuovi Bibita
void MainWindow::on_comboBoxRimuoviBibite_currentIndexChanged(int index)
{

    control->removeWidget("","RimuoviBibita");
    if(index>0){
       QVector<Bibita*> bib=control->getScontrino()->listaBibita();
       control->setPuntatoreRimuoviBibita(bib.value(bib.size()-index));
       ui->BibitaModificaQuantita->setValue(control->getPuntatoreRimuoviBibita()->getQuantita());
       Acqua* a=dynamic_cast<Acqua*>(control->getPuntatoreRimuoviBibita());
       Birra* bi=dynamic_cast<Birra*>(control->getPuntatoreRimuoviBibita());
       if(a || bi){
           if(a){
               QRadioButton* Naturale=new QRadioButton("Naturale",&(*this));
               QRadioButton* Frizzante=new QRadioButton("Frizzante",&(*this));
               QRadioButton* MezzoLitro=new QRadioButton("0.5L",&(*this));
               QRadioButton* UnLitro=new QRadioButton("1L",&(*this));
               control->insertWidget(Naturale,"RimuoviBibita");
               control->insertWidget(Frizzante,"RimuoviBibita");
               control->insertWidget(MezzoLitro,"RimuoviBibita");
               control->insertWidget(UnLitro,"RimuoviBibita");
               LayoutscrollAreaRimuoviBibitaNome->addWidget(Naturale);
               LayoutscrollAreaRimuoviBibitaNome->addWidget(Frizzante);
               LayoutscrollAreaRimuoviBibitaSize->addWidget(MezzoLitro);
               LayoutscrollAreaRimuoviBibitaSize->addWidget(UnLitro);
               connect(Naturale,SIGNAL(clicked(bool)),this,SLOT(aggiungiNaturaleRimuoviBibita_RadioButton()));
               connect(Frizzante,SIGNAL(clicked(bool)),this,SLOT(aggiungiFrizzanteRimuoviBibita_RadioButton()));
               connect(MezzoLitro,SIGNAL(clicked(bool)),this,SLOT(aggiungiL05RimuoviBibita_RadioButton()));
               connect(UnLitro,SIGNAL(clicked(bool)),this,SLOT(aggiungiL1RimuoviBibita_RadioButton()));
           }
           if(bi){
               QRadioButton* Bionda=new QRadioButton("Bionda",&(*this));
               QRadioButton* Rossa=new QRadioButton("Rossa",&(*this));
               QRadioButton* L033=new QRadioButton("0.33L",&(*this));
               QRadioButton* L066=new QRadioButton("0.66L",&(*this));
               control->insertWidget(Bionda,"RimuoviBibita");
               control->insertWidget(Rossa,"RimuoviBibita");
               control->insertWidget(L033,"RimuoviBibita");
               control->insertWidget(L066,"RimuoviBibita");
               LayoutscrollAreaRimuoviBibitaNome->addWidget(Bionda);
               LayoutscrollAreaRimuoviBibitaNome->addWidget(Rossa);
               LayoutscrollAreaRimuoviBibitaSize->addWidget(L033);
               LayoutscrollAreaRimuoviBibitaSize->addWidget(L066);
               connect(Bionda,SIGNAL(clicked(bool)),this,SLOT(aggiungiBiondaRimuoviBibita_RadioButton()));
               connect(Rossa,SIGNAL(clicked(bool)),this,SLOT(aggiungiRossaRimuoviBibita_RadioButton()));
               connect(L033,SIGNAL(clicked(bool)),this,SLOT(aggiungiL033RimuoviBibita_RadioButton()));
               connect(L066,SIGNAL(clicked(bool)),this,SLOT(aggiungiL066RimuoviBibita_RadioButton()));
           }
       }
       else{
           QRadioButton* Cocacola=new QRadioButton("Cocacola",&(*this));
           QRadioButton* Sprite=new QRadioButton("Sprite",&(*this));
           QRadioButton* Fanta=new QRadioButton("Fanta",&(*this));
           QRadioButton* TheLimone=new QRadioButton("The al Limone",&(*this));
           QRadioButton* ThePesca=new QRadioButton("The alla Pesca",&(*this));
           QRadioButton* Piccola=new QRadioButton("Piccola",&(*this));
           QRadioButton* Media=new QRadioButton("Media",&(*this));
           QRadioButton* Grande=new QRadioButton("Grande",&(*this));
           control->insertWidget(Cocacola,"RimuoviBibita");
           control->insertWidget(Sprite,"RimuoviBibita");
           control->insertWidget(Fanta,"RimuoviBibita");
           control->insertWidget(TheLimone,"RimuoviBibita");
           control->insertWidget(ThePesca,"RimuoviBibita");
           LayoutscrollAreaRimuoviBibitaNome->addWidget(Cocacola);
           LayoutscrollAreaRimuoviBibitaNome->addWidget(Sprite);
           LayoutscrollAreaRimuoviBibitaNome->addWidget(Fanta);
           LayoutscrollAreaRimuoviBibitaNome->addWidget(TheLimone);
           LayoutscrollAreaRimuoviBibitaNome->addWidget(ThePesca);
           control->insertWidget(Piccola,"RimuoviBibita");
           control->insertWidget(Media,"RimuoviBibita");
           control->insertWidget(Grande,"RimuoviBibita");
           LayoutscrollAreaRimuoviBibitaSize->addWidget(Piccola);
           LayoutscrollAreaRimuoviBibitaSize->addWidget(Media);
           LayoutscrollAreaRimuoviBibitaSize->addWidget(Grande);
           connect(Cocacola,SIGNAL(clicked(bool)),this,SLOT(aggiungiCocacolaBibitaRimuoviBibita_RadioButton()));
           connect(Sprite,SIGNAL(clicked(bool)),this,SLOT(aggiungiSpriteBibitaRimuoviBibita_RadioButton()));
           connect(Fanta,SIGNAL(clicked(bool)),this,SLOT(aggiungiFantaBibitaRimuoviBibita_RadioButton()));
           connect(TheLimone,SIGNAL(clicked(bool)),this,SLOT(aggiungiTheLimoneBibitaRimuoviBibita_RadioButton()));
           connect(ThePesca,SIGNAL(clicked(bool)),this,SLOT(aggiungiThePescaBibitaRimuoviBibita_RadioButton()));
           connect(Piccola,SIGNAL(clicked(bool)),this,SLOT(aggiungiPiccolaBibitaRimuoviBibita_RadioButton()));
           connect(Media,SIGNAL(clicked(bool)),this,SLOT(aggiungiMediaBibitaRimuoviBibita_RadioButton()));
           connect(Grande,SIGNAL(clicked(bool)),this,SLOT(aggiungiGrandeBibitaRimuoviBibita_RadioButton()));
     }

    }

}

void MainWindow::aggiungiCocacolaBibitaRimuoviBibita_RadioButton(){
 control->modificaNomeRimuoviBibita("Cocacola");
 ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiSpriteBibitaRimuoviBibita_RadioButton(){
    control->modificaNomeRimuoviBibita("Sprite");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiFantaBibitaRimuoviBibita_RadioButton(){
    control->modificaNomeRimuoviBibita("Fanta");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiTheLimoneBibitaRimuoviBibita_RadioButton(){
    control->modificaNomeRimuoviBibita("The al Limone");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiThePescaBibitaRimuoviBibita_RadioButton(){
    control->modificaNomeRimuoviBibita("The alla Pesca");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiPiccolaBibitaRimuoviBibita_RadioButton(){
    control->modificaSizeRimuoviBibita("S");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiMediaBibitaRimuoviBibita_RadioButton(){
    control->modificaSizeRimuoviBibita("M");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiGrandeBibitaRimuoviBibita_RadioButton(){
    control->modificaSizeRimuoviBibita("L");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiNaturaleRimuoviBibita_RadioButton(){
    control->modificaNomeRimuoviBibita("Naturale");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiFrizzanteRimuoviBibita_RadioButton(){
    control->modificaNomeRimuoviBibita("Frizzante");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiL05RimuoviBibita_RadioButton(){
    control->modificaSizeRimuoviBibita("0.5L");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiL1RimuoviBibita_RadioButton(){
    control->modificaSizeRimuoviBibita("1L");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiBiondaRimuoviBibita_RadioButton(){
    control->modificaNomeRimuoviBibita("Bionda");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiRossaRimuoviBibita_RadioButton(){
    control->modificaNomeRimuoviBibita("Rossa");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiL033RimuoviBibita_RadioButton(){
    control->modificaSizeRimuoviBibita("0.33L");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::aggiungiL066RimuoviBibita_RadioButton(){
    control->modificaSizeRimuoviBibita("0.66L");
    ui->textBrowser->setText(control->convertScontrino());
}

void MainWindow::on_BibitaModificaQuantita_valueChanged(int arg1)
{
    int index=ui->comboBoxRimuoviBibite->currentIndex();
    if(index>0){
    QVector<Bibita*> bib=control->getScontrino()->listaBibita();
    bib.at(bib.size()-index)->setQuantita(arg1);
    ui->textBrowser->setText(control->convertScontrino());
    }
}

void MainWindow::on_RimuoviBibitaButton_clicked()
{
    QVector<Bibita*> bib=control->getScontrino()->listaBibita();
    int index=ui->comboBoxRimuoviBibite->currentIndex();
    if(index>0){
    control->getScontrino()->rimuoviBibita(*bib.value(bib.size()-index));
    ui->comboBoxRimuoviBibite->removeItem(index);
    ui->BibitaModificaQuantita->setValue(1);
    ui->comboBoxRimuoviBibite->setCurrentIndex(0);
    ui->textBrowser->setText(control->convertScontrino());
    }
}

void MainWindow::on_pushButtonPagamento_clicked()
{
    control->stampa();
    ui->textBrowser->setText(control->convertScontrino());
    ui->comboBoxRimuoviPanini->setCurrentIndex(0);
    int sizePanino=ui->comboBoxRimuoviPanini->count();
    for(; sizePanino>=1; sizePanino--){
        ui->comboBoxRimuoviPanini->removeItem(sizePanino);
    }
    ui->PaninoModificaQuantita->setValue(1);
    ui->comboBoxRimuoviMenu->setCurrentIndex(0);
    int sizeMenu=ui->comboBoxRimuoviMenu->count();
    for(; sizeMenu>=1; sizeMenu--){
        ui->comboBoxRimuoviMenu->removeItem(sizeMenu);
    }
    ui->MenuModificaQuantita->setValue(1);
    ui->comboBoxRimuoviPatatine->setCurrentIndex(0);
    int sizePatatine=ui->comboBoxRimuoviPatatine->count();
    for(; sizePatatine>=1; sizePatatine--){
        ui->comboBoxRimuoviPatatine->removeItem(sizePatatine);
    }
    ui->comboBoxRimuoviBibite->setCurrentIndex(0);
    int sizeBibita=ui->comboBoxRimuoviBibite->count();
    for(; sizeBibita>=1; sizeBibita--){
        ui->comboBoxRimuoviBibite->removeItem(sizeBibita);
    }
    ui->BibitaModificaQuantita->setValue(1);
}


