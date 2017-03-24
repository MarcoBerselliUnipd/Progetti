#include "controller.h"
#include<QDateTime>
#include<QPdfWriter>
#include<QTextDocument>
#include<QPainter>

Controller::Controller(Scontrino * s):scontr(s){
    s=new Scontrino;
    nomiprodotti.append("Pane");
    nomiprodotti.append("Pane Tostato");
    nomiprodotti.append("Hamburger");
    nomiprodotti.append("Prosciutto Cotto");
    nomiprodotti.append("Bacon");
    nomiprodotti.append("Mozzarella");
    nomiprodotti.append("Sottiletta");
    nomiprodotti.append("Pomodoro");
    nomiprodotti.append("Insalata");
    nomiprodotti.append("Sotto Aceti");
    nomiprodotti.append("Salsa ai Funghi");
    nomiprodotti.append("Cipolla");
    nomiprodotti.append("Peperoni");
}

void Controller::insertWidget(QWidget * QW, const QString & nome){
    if(nome=="AggiungiPanino") aggiungiPanini.append(QW);
    if(nome=="RimuoviPanino") RimuoviProdotto.append(QW);
    if(nome=="AggiungiBibita") aggiungiBibite.append(QW);
    if(nome=="RimuoviBibita") RimuoviBibita.append(QW);
    if(nome=="AggiungiMenu") aggiungiMenu.append(QW);
    if(nome=="RimuoviMenu") RimuoviMenu.append(QW);
    if(nome=="AggiungiPatatine") aggiungiPatatine.append(QW);
    if(nome=="RimuoviPatatine") RimuoviPatatine.append(QW);
}

void Controller::removeWidget(const QString & type, const QString & nome){
    if(nome=="AggiungiPanino"){
        if(type=="A Scelta" || type=="Vegetariano" || type=="Toast" || type=="Hamburger" || type==""){
            if(!aggiungiPanini.isEmpty()){
                int count=aggiungiPanini.size();
                for(int i=0; i<count; i++){
                    delete aggiungiPanini[i];
                }
                aggiungiPanini.clear();
                if(puntatorePanino && type!="")delete puntatorePanino;
            }
        }
    }
    if(nome=="RimuoviPanino"){
        if(!RimuoviProdotto.isEmpty()){
            int size=RimuoviProdotto.size();
            for(int i=0;i<size;i++ ){
                delete RimuoviProdotto[i];
            }
            RimuoviProdotto.clear();
        }

    }
    if(nome=="AggiungiBibita"){
        if(type=="Acqua" || type=="Bibita" || type=="Birra" || type==""){
            if(!aggiungiBibite.isEmpty()){
                int count=aggiungiBibite.size();
                for(int i=0; i<count; i++){
                    delete aggiungiBibite[i];
                }
                aggiungiBibite.clear();
                if(puntatoreBibita && type!="")delete puntatoreBibita;
            }
        }
    }
    if(nome=="RimuoviBibita"){
        if(!RimuoviBibita.isEmpty()){
            int size=RimuoviBibita.size();
            for(int i=0;i<size;i++ ){
                delete RimuoviBibita[i];
            }
            RimuoviBibita.clear();
        }
    }
    if(nome=="AggiungiMenu"){
        if(type=="MacVegetariano" || type=="MacCarne" || type==""){
            if(!aggiungiMenu.isEmpty()){
                int count=aggiungiMenu.size();
                for(int i=0; i<count; i++){
                    delete aggiungiMenu[i];
                }
                aggiungiMenu.clear();
                if(puntatoreMenu && type!="")delete puntatoreMenu;
            }
        }
    }
    if(nome=="RimuoviMenu"){
        if(!RimuoviMenu.isEmpty()){
            int size=RimuoviMenu.size();
            for(int i=0;i<size;i++ ){
                delete RimuoviMenu[i];
            }
            RimuoviMenu.clear();
        }
    }
    if(nome=="AggiungiPatatine"){
        if(type=="Fritte" || type=="Lesse" || type==""){
            if(!aggiungiPatatine.isEmpty()){
                int count=aggiungiPatatine.size();
                for(int i=0; i<count; i++){
                    delete aggiungiPatatine[i];
                }
                aggiungiPatatine.clear();
                if(puntatorePatatine && type!="")delete puntatorePatatine;
            }
        }
    }
    if(nome=="RimuoviPatatine"){
        if(!RimuoviPatatine.isEmpty()){
            int size=RimuoviPatatine.size();
            for(int i=0;i<size;i++ ){
                delete RimuoviPatatine[i];
            }
            RimuoviPatatine.clear();
        }
    }
}

void Controller::setPuntatorePanino(Panino * pan){
    puntatorePanino=pan;
}

void Controller::modificaNomePanino(const QString &qs){
    if(puntatorePanino) puntatorePanino->setNome(qs.toStdString());
}

void Controller::modificaQuantitaPanino(int quantita){
    if(puntatorePanino) puntatorePanino->setQuantita(quantita);
}

QSpinBox* Controller::inserisciProdotto(const Prodotto & prod, bool b){
    if(b){
        bool nontrovato=false;
        try{puntatorePanino->getProdotto(prod);} catch(int){nontrovato=true;};
        if(nontrovato){
            puntatorePanino->aggiungiProdotto(prod);
        }
    }
    else{
        Prodotto pr;
        try{pr=puntatorePanino->getProdotto(prod);}
        catch(int){
            puntatorePanino->aggiungiProdotto(prod);
        }
        puntatorePanino->rimuoviProdotto(pr);
    }

    QString text;
    for(int i=0; i<aggiungiPanini.size();i++){
        QCheckBox* checkbox=dynamic_cast<QCheckBox*>(aggiungiPanini[i]);
        if(checkbox && checkbox->text()==QString::fromStdString(prod.getNome())){
            text=checkbox->text();
        }
    }
    QSpinBox* sp;
    for(int i=0; i<aggiungiPanini.size() ;i++){
        QSpinBox* spinbox=dynamic_cast<QSpinBox*>(aggiungiPanini[i]);
        if(spinbox && spinbox->objectName()==text){
            sp=spinbox;
        }
    }
    return sp;
}


void Controller::setPuntatoreRimuoviPanino(Panino * pan){
    puntatoreRimuoviPanino=pan;
}

Panino* Controller::getPuntatoreRimuoviPanino() const{
    return puntatoreRimuoviPanino;
}

void Controller::modificaQuantitaProdotto(int i, const Prodotto & prod){
    puntatorePanino->getProdotto(prod).setQuantita(i);
}

void Controller::inserisciPanino(){
    if(puntatorePanino){
        scontr->inserisciPanino(*puntatorePanino);
    }
}

Scontrino* Controller::getScontrino() const{
    return scontr;
}

QString Controller::convertScontrino()const{
    std::ostringstream convert;
    convert<<*scontr;
    std::string convertstring=convert.str();
    QString out=QString::fromStdString(convertstring);
    return out;
}

QVector<QWidget*> Controller::getRimuoviProdotto(){
    return RimuoviProdotto;
}

QVector<QString> Controller::getNomiProdotti(){
    return nomiprodotti;
}

void Controller::rimuoviProdottoInPanino(const Prodotto & prod){
    Prodotto pr;
    try{pr=puntatoreRimuoviPanino->getProdotto(prod);}
    catch(int){puntatoreRimuoviPanino->aggiungiProdotto(pr);}
    puntatoreRimuoviPanino->rimuoviProdotto(pr);
}

void Controller::rimuoviProdottoInPaninoQuantita(const Prodotto & prod, int i){
    puntatoreRimuoviPanino->getProdotto(prod).setQuantita(i);
}

void Controller::aggiungiProdottoRimuoviPanini(const Prodotto & prod, bool b){
    if(b){
        bool nontrovato=false;
        try{puntatoreRimuoviPanino->getProdotto(prod);} catch(int){nontrovato=true;};
        if(nontrovato){
            puntatoreRimuoviPanino->aggiungiProdotto(prod);
        }
    }
    else{
        Prodotto pr;
        try{pr=puntatoreRimuoviPanino->getProdotto(prod);}
        catch(int){
            puntatoreRimuoviPanino->aggiungiProdotto(prod);
        }
        puntatoreRimuoviPanino->rimuoviProdotto(pr);
    }
}

void Controller::setPuntatoreBibita(Bibita * bib){
    puntatoreBibita=bib;
}

void Controller::modificaQuantitaBibita(int i){
    puntatoreBibita->setQuantita(i);
}

void Controller::inserisciBibita(){
    if(puntatoreBibita){
        scontr->inserisciBibita(*puntatoreBibita);
    }
}

void Controller::setBibitaNome(std::string nome){
    if(puntatoreBibita) puntatoreBibita->setNome(nome);
}

void Controller::setBibitaSize(std::string size){
    if(puntatoreBibita) puntatoreBibita->setSize(size);
}

Bibita* Controller::getPuntatoreRimuoviBibita() const{
    return puntatoreRimuoviBibita;
}

void Controller::setPuntatoreRimuoviBibita(Bibita * bib){
    puntatoreRimuoviBibita=bib;
}

QVector<QWidget*> Controller::getRimuoviBibita(){
    return RimuoviBibita;
}

void Controller::modificaNomeRimuoviBibita(std::string nome){
    if(puntatoreRimuoviBibita) puntatoreRimuoviBibita->setNome(nome);
}

void Controller::modificaSizeRimuoviBibita(std::string size){
    if(puntatoreRimuoviBibita) puntatoreRimuoviBibita->setSize(size);
}

void Controller::setPuntatoreMenu(Menu * menu){
    puntatoreMenu=menu;
}

void Controller::modificaQuantitaMenu(int i){
   if(puntatoreMenu) puntatoreMenu->setQuantita(i);
}

void Controller::inserisciMenu(){
    if(puntatoreMenu) scontr->inserisciMenu(*puntatoreMenu);
}

void Controller::modificaNomeBibitaMenu(std::string nome){
    if(puntatoreMenu) const_cast<Bibita&>(puntatoreMenu->getBibita()).setNome(nome);
}

void Controller::setPuntatoreRimuoviMenu(Menu* men){
    puntatoreRimuoviMenu=men;
}

Menu* Controller::getPuntatoreRimuoviMenu() const{
    return puntatoreRimuoviMenu;
}
QVector<QWidget*> Controller::getRimuoviMenu(){
    return RimuoviMenu;
}

void Controller::modificaNomeBibitaRimuoviMenu(std::string nome){
    if(puntatoreRimuoviMenu) const_cast<Bibita&>(puntatoreRimuoviMenu->getBibita()).setNome(nome);
}

void Controller::setPuntatorePatatina(Patatina * pat){
    puntatorePatatine=pat;
}

void Controller::inserisciPatatina(){
    if(puntatorePatatine) scontr->inserisciPatatina(*puntatorePatatine);
}
void Controller::modificaQuantitaPatatina(int i){
    if(puntatorePatatine) puntatorePatatine->setQuantita(i);
}

void Controller::modificaSizePatatina(std::string size){
    if(puntatorePatatine) puntatorePatatine->setSize(size);
}

void Controller::setPuntatoreRimuoviPatatina(Patatina* pat){
    puntatoreRimuoviPatatine=pat;
}

Patatina* Controller::getPuntatoreRimuoviPatatina() const{
    return puntatoreRimuoviPatatine;
}

QVector<QWidget*> Controller::getRimuoviPatatina(){
    return RimuoviPatatine;
}

void Controller::modificaSizeRimuoviPatatina(std::string size){
    if(puntatoreRimuoviPatatine) puntatoreRimuoviPatatine->setSize(size);
}

Controller::~Controller(){
    delete scontr;
    delete puntatorePanino;
    delete puntatoreRimuoviPanino;
    delete puntatoreMenu;
    delete puntatoreRimuoviMenu;
    delete puntatorePatatine;
    delete puntatoreRimuoviPatatine;
    delete puntatoreBibita;
    delete puntatoreRimuoviBibita;
    int size=aggiungiPanini.size();
    for(int i=0; i<size; i++){
        delete aggiungiPanini[i];
    }
    aggiungiPanini.clear();

    int size1=RimuoviProdotto.size();
    for(int i=0; i<size1; i++){
        delete RimuoviProdotto[i];
    }
    RimuoviProdotto.clear();

    int size3=aggiungiPatatine.size();
    for(int i=0; i<size3; i++){
        delete aggiungiPatatine[i];
    }
    aggiungiPatatine.clear();

    int size4=RimuoviPatatine.size();
    for(int i=0; i<size4; i++){
        delete RimuoviPatatine[i];
    }
    RimuoviPatatine.clear();

    int size5=aggiungiMenu.size();
    for(int i=0; i<size5; i++){
        delete aggiungiMenu[i];
    }
    aggiungiMenu.clear();

    int size6=RimuoviMenu.size();
    for(int i=0; i<size6; i++){
        delete RimuoviMenu[i];
    }
    RimuoviMenu.clear();

    int size7=aggiungiBibite.size();
    for(int i=0; i<size7; i++){
        delete aggiungiBibite[i];
    }
    aggiungiBibite.clear();

    int size8=RimuoviBibita.size();
    for(int i=0; i<size8; i++){
        delete RimuoviBibita[i];
    }
    RimuoviBibita.clear();
}

void Controller::stampa(){
    QDateTime date=QDateTime::currentDateTime();
    int numeroScontrino=scontr->getNumero();
    std::ostringstream convert;
    convert << numeroScontrino;
    std::string numero=convert.str();
    if(numeroScontrino<100){
        if(numeroScontrino<10) numero = "00" + numero;
        else numero="0"+numero;
    }
    QString numeroQ = QString::fromStdString(numero);
    QString filename="Scontrino_n."+numeroQ+"_"+date.toString("dd")+"-"+date.toString("MM")+"-"+date.toString("yy")+"_"+date.toString("hh")+"h_"+date.toString("mm")+"m_"+date.toString("ss")+"s_"+".pdf";
    QPdfWriter pdf(filename);
    pdf.setPageSize(QPagedPaintDevice::A4);
    pdf.setPageMargins(QMargins(30, 30, 30, 30));
    QTextDocument* doc=new QTextDocument;
    QPainter painter(&pdf);
    QFont Font("Monotype Corsiva",18,50);
    painter.setFont(Font);
    int size=0;
    QString title="FastFood";
    QString name="McQt";
    painter.drawText(4000,size,title);
    Font.setPointSize(40);
    painter.setFont(Font);
    size += 500;
    painter.drawText(3750,size,name);
    Font.setFamily("Arial");
    Font.setPointSize(14);
    painter.setFont(Font);
    QString data="Mario Rossi & C. srl";
    QString data1="Via abc, 123";
    QString data2="35131 - Padova (PD)";
    QString data3="049-123456";
    QString data4="P.IVA 00000000000";
    size += 500;
    painter.drawText(3500,size,data);
    size += 300;
    painter.drawText(3500,size,data1);
    size += 300;
    painter.drawText(3500,size,data2);
    size += 300;
    painter.drawText(3500,size,data3);
    size += 300;
    painter.drawText(3500,size,data4);
    size += 750;

    QString data5="|Pezzi|Al Pezzo|Totale €|";
    painter.drawText(6000,size,data5);
    Font.setPointSize(12);
    painter.setFont(Font);
    QVector<Menu*> m=scontr->listaMenu();
    QVector<Bibita*> b=scontr->listaBibita();
    QVector<Patatina*> pt=scontr->listaPatatina();
    QVector<Panino*> p=scontr->listaPanino();
    size += 500;
    for(int i=0; i<m.size();i++){
        QString menu="Menu: "+QString::fromStdString(m[i]->getNome());
        QString datimenu;
        if(m[i]->getQuantita()<10) datimenu="|     0";
        else datimenu="|     ";
        std::ostringstream convertquantita;
        convertquantita << m[i]->getQuantita();
        datimenu=datimenu+QString::fromStdString(convertquantita.str())+"|";

        if(m[i]->prezzoAlPezzo()<100){
            if(m[i]->prezzoAlPezzo()<10) datimenu=datimenu+"       ";
            else datimenu=datimenu+"     ";
        }
        std::ostringstream convertprezzoalpezzo;
        convertprezzoalpezzo << m[i]->prezzoAlPezzo();
        datimenu=datimenu+QString::fromStdString(convertprezzoalpezzo.str());

        double resto=m[i]->prezzoAlPezzo();
        while(resto>=1) resto=resto-1;
        if(resto==0) datimenu=datimenu+".00";
        else{
            while(resto>=0.09) resto=resto-0.1;
            if(resto<0.01) datimenu=datimenu+"0";
        }
        datimenu=datimenu+"|     ";
        if(m[i]->calcolaPrezzo()<100){
            if(m[i]->calcolaPrezzo()<10) datimenu=datimenu+"  ";
            else datimenu=datimenu+" ";
        }
        std::ostringstream convertcalcolaprezzo;
        convertcalcolaprezzo<<m[i]->calcolaPrezzo();
        datimenu=datimenu+QString::fromStdString(convertcalcolaprezzo.str());
        double resto1=m[i]->calcolaPrezzo();
        while(resto1>=1) resto1=resto1-1;
        if(resto1==0) datimenu=datimenu+".00";
        else{
            while(resto1>=0.09) resto1=resto1-0.1;
            if(resto1<0.01) datimenu=datimenu+"0";
        }
        datimenu=datimenu+"|";
        painter.drawText(1000,size,menu);
        painter.drawText(6000,size,datimenu);
        size += 300;
        if(size>12500){
          size=0;
          pdf.newPage();
        }
    }

    for(int i=0; i<p.size();i++){
        QString nome;

        QString dati;
        const Hamburger* h=dynamic_cast<const Hamburger*>(p[i]);
        const Toast *t=dynamic_cast<const Toast*>(p[i]);
        const Vegetariano* v=dynamic_cast<const Vegetariano*>(p[i]);
        if(h||t||v){
            if(h){
                nome=QString::fromStdString(h->getNome())+" 10% di sconto";
            }
            if(t){
                nome=QString::fromStdString(t->getNome())+" 10% di sconto";
            }
            if(v){
                nome=QString::fromStdString(v->getNome())+" 10% di sconto";
            }
        }
        else{
            nome="Panino a scelta: "+QString::fromStdString(p[i]->getNome());
        }
        if(p[i]->getQuantita()<10) dati="|     0";
        else dati="|     ";
        std::ostringstream convertquantita;
        convertquantita << p[i]->getQuantita();
        dati=dati+QString::fromStdString(convertquantita.str())+"|";

        if(p[i]->prezzoAlPezzo()<100){
            if(p[i]->prezzoAlPezzo()<10) dati=dati+"       ";
            else dati=dati+"     ";
        }
        std::ostringstream convertprezzoalpezzo;
        convertprezzoalpezzo <<p[i]->prezzoAlPezzo();
        dati=dati+QString::fromStdString(convertprezzoalpezzo.str());

        double resto=p[i]->prezzoAlPezzo();
        while(resto>=1) resto=resto-1;
        if(resto==0) dati=dati+".00";
        else{
            while(resto>=0.09) resto=resto-0.1;
            if(resto<0.01) dati=dati+"0";
        }
        dati=dati+"|    ";

        if(p[i]->calcolaPrezzo()<100){
            if(p[i]->calcolaPrezzo()<10) dati=dati+"  ";
            else dati=dati+" ";
        }
        std::ostringstream convertcalcolaprezzo;
        convertcalcolaprezzo<<p[i]->calcolaPrezzo();
        dati=dati+QString::fromStdString(convertcalcolaprezzo.str());
        double resto1=p[i]->calcolaPrezzo();
        while(resto1>=1) resto1=resto1-1;
        if(resto1==0) dati=dati+".00";
        else{
            while(resto1>=0.09) resto1=resto1-0.1;
            if(resto1<0.01) dati=dati+"0";
        }
        dati=dati+"|";
        painter.drawText(1000,size,nome);
        painter.drawText(6000,size,dati);
        size += 250;
        QString dettagli=" -Dettagli:";
        QString datadettagli="|pz|Al Pezzo|   Tot.|";
        painter.drawText(1000,size,dettagli);
        painter.drawText(5000,size,datadettagli);
        size+=200;
        for(Panino::iteratore it=p[i]->begin(); it!=p[i]->end(); it++){
            QString prodotto=QString::fromStdString((p[i]->operator [](it)).getNome());
            QString dataprodotto;
            if(p[i]->operator [](it).getQuantita()<10) dataprodotto="|0";
            else dataprodotto="|";
            std::ostringstream convertquantitaprod;
            convertquantitaprod << p[i]->operator [](it).getQuantita();
            dataprodotto=dataprodotto+QString::fromStdString(convertquantitaprod.str())+"|";

            if(p[i]->operator [](it).getPrezzoBase()<100){
                if(p[i]->operator [](it).getPrezzoBase()<10) dataprodotto=dataprodotto+"       ";
                else dataprodotto=dataprodotto+"     ";
            }
            std::ostringstream convertprezzobase;
            convertprezzobase <<p[i]->operator [](it).getPrezzoBase();
            dataprodotto=dataprodotto+QString::fromStdString(convertprezzobase.str());

            double resto=p[i]->operator [](it).getPrezzoBase();
            while(resto>=1) resto=resto-1;
            if(resto==0) dataprodotto=dataprodotto+".00";
            else{
                while(resto>=0.09) resto=resto-0.1;
                if(resto<0.01) dataprodotto=dataprodotto+"0";
            }
            dataprodotto=dataprodotto+"|";

            if(p[i]->operator [](it).calcolaPrezzo()<100){
                if(p[i]->operator [](it).calcolaPrezzo()<10) dataprodotto=dataprodotto+"  ";
                else dataprodotto=dataprodotto+" ";
            }
            std::ostringstream convertcalcolaprezzoprod;
            convertcalcolaprezzoprod<<p[i]->operator [](it).calcolaPrezzo();
            dataprodotto=dataprodotto+QString::fromStdString(convertcalcolaprezzoprod.str());
            double resto1=p[i]->operator [](it).calcolaPrezzo();
            while(resto1>=1) resto1=resto1-1;
            if(resto1==0) dataprodotto=dataprodotto+".00";
            else{
                while(resto1>=0.09) resto1=resto1-0.1;
                if(resto1<0.01) dataprodotto=dataprodotto+"0";
            }
            dataprodotto=dataprodotto+"|";

            painter.drawText(1500,size,prodotto);
            painter.drawText(5000,size,dataprodotto);
            size += 200;
            if(size>12500){
              size=0;
              pdf.newPage();
            }
        }
        size+=500;
        if(size>12500){
          size=0;
          pdf.newPage();
        }

    }
    for(int i=0; i<pt.size();i++){
        QString datipatatina;
        if(pt[i]->getQuantita()<10) datipatatina="|     0";
        else datipatatina="|     ";
        std::ostringstream convertquantita;
        convertquantita << pt[i]->getQuantita();
        datipatatina=datipatatina+QString::fromStdString(convertquantita.str())+"|";

        if(pt[i]->prezzoSize()<100){
            if(pt[i]->prezzoSize()<10) datipatatina=datipatatina+"       ";
            else datipatatina=datipatatina+"     ";
        }
        std::ostringstream convertprezzosize;
        convertprezzosize <<pt[i]->prezzoSize();
        datipatatina=datipatatina+QString::fromStdString(convertprezzosize.str());

        double resto=pt[i]->prezzoSize();
        while(resto>=1) resto=resto-1;
        if(resto==0) datipatatina=datipatatina+".00";
        else{
            while(resto>=0.09) resto=resto-0.1;
            if(resto<0.01) datipatatina=datipatatina+"0";
        }
        datipatatina=datipatatina+"|     ";

        if(pt[i]->calcolaPrezzo()<100){
            if(pt[i]->calcolaPrezzo()<10) datipatatina=datipatatina+"  ";
            else datipatatina=datipatatina+" ";
        }
        std::ostringstream convertcalcolaprezzo;
        convertcalcolaprezzo<<pt[i]->calcolaPrezzo();
        datipatatina=datipatatina+QString::fromStdString(convertcalcolaprezzo.str());
        double resto1=pt[i]->calcolaPrezzo();
        while(resto1>=1) resto1=resto1-1;
        if(resto1==0) datipatatina=datipatatina+".00";
        else{
            while(resto1>=0.09) resto1=resto1-0.1;
            if(resto1<0.01) datipatatina=datipatatina+"0";
        }
        datipatatina=datipatatina+"|";
        QString nomepatatina="Patatine "+QString::fromStdString(pt[i]->getNome());
        if(pt[i]->getSize()=="S") nomepatatina=nomepatatina+" Piccole";
        if(pt[i]->getSize()=="M") nomepatatina=nomepatatina+" Medie";
        if(pt[i]->getSize()=="L") nomepatatina=nomepatatina+" Grandi";
        if(pt[i]->getSize()=="XL") nomepatatina=nomepatatina+" Extra Grandi";
        painter.drawText(1000,size,nomepatatina);
        painter.drawText(6000,size,datipatatina);
        size+=500;
        if(size>12500){
          size=0;
          pdf.newPage();
        }

    }

    for(int i=0; i<b.size();i++){
        QString nomebibita;
        const Acqua* a=dynamic_cast<const Acqua*>(b[i]);

        const Birra* bi=dynamic_cast<const Birra*>(b[i]);
        if(a || bi){
            if(a) {
                nomebibita="Acqua "+QString::fromStdString(a->getNome())+" "+QString::fromStdString(a->getSize());
            }
            if(bi){

                nomebibita="Birra "+QString::fromStdString(bi->getNome())+" "+QString::fromStdString(bi->getSize());
            }
        }
        else{
            nomebibita="Bibita: "+QString::fromStdString(b[i]->getNome())+" ";
            if(b[i]->getSize()=="S") nomebibita=nomebibita+" Piccola";
            if(b[i]->getSize()=="M") nomebibita=nomebibita+" Media";
            if(b[i]->getSize()=="L") nomebibita=nomebibita+" Grande";

        }

        QString datibibita;
        if(b[i]->getQuantita()<10) datibibita="|     0";
        else datibibita="|     ";
        std::ostringstream convertquantita;
        convertquantita << b[i]->getQuantita();
        datibibita=datibibita+QString::fromStdString(convertquantita.str())+"|";

        if(b[i]->prezzoSize()<100){
            if(b[i]->prezzoSize()<10) datibibita=datibibita+"       ";
            else datibibita=datibibita+"     ";
        }
        std::ostringstream convertprezzosize;
        convertprezzosize <<b[i]->prezzoSize();
        datibibita=datibibita+QString::fromStdString(convertprezzosize.str());

        double resto=b[i]->prezzoSize();
        while(resto>=1) resto=resto-1;
        if(resto==0) datibibita=datibibita+".00";
        else{
            while(resto>=0.09) resto=resto-0.1;
            if(resto<0.01) datibibita=datibibita+"0";
        }
        datibibita=datibibita+"|     ";

        if(b[i]->calcolaPrezzo()<100){
            if(b[i]->calcolaPrezzo()<10) datibibita=datibibita+"  ";
            else datibibita=datibibita+" ";
        }
        std::ostringstream convertcalcolaprezzo;
        convertcalcolaprezzo<<b[i]->calcolaPrezzo();
        datibibita=datibibita+QString::fromStdString(convertcalcolaprezzo.str());
        double resto1=b[i]->calcolaPrezzo();
        while(resto1>=1) resto1=resto1-1;
        if(resto1==0) datibibita=datibibita+".00";
        else{
            while(resto1>=0.09) resto1=resto1-0.1;
            if(resto1<0.01) datibibita=datibibita+"0";
        }
        datibibita=datibibita+"|";

        painter.drawText(1000,size,nomebibita);
        painter.drawText(6000,size,datibibita);
        size+=500;
        if(size>12500){
          size=0;
          pdf.newPage();
        }

    }

    size += 500;
    QString separatore="------------------------------------------------------------------------------------------------------------------------------";
    painter.drawText(500,size,separatore);
    size+=500;
    if(size>12500) {
        pdf.newPage();
        size=0;
    }
    Font.setPointSize(14);
    painter.setFont(Font);
    QString tot="TOTALE EURO";
    QString tot1=QString::number(scontr->calcolaPrezzo());
    painter.drawText(1000,size,tot);
    painter.drawText(7500,size,tot1);
    size+=500;
    if(size>12500) {
        pdf.newPage();
        size=0;
    }
    Font.setPointSize(12);
    painter.setFont(Font);
    int pezziTotali=scontr->pezziTotaliInseriti();
    QString npr="NUMERO TOTALE DI PRODOTTI: "+QString::number(pezziTotali);
    painter.drawText(1000,size,npr);
    size+=500;
    if(size>12500) {
        pdf.newPage();
        size=0;
    }
    QString d=date.toString("dd")+"/"+date.toString("MM")+"/"+date.toString("yy")+" "+date.toString("hh")+":"+date.toString("mm")+":"+date.toString("ss");
    painter.drawText(1000,size,d);
    painter.drawText(6000,size,"SCONTRINO NUMERO: "+numeroQ);
    size+=500;
    if(size>12500) {
        pdf.newPage();
        size=0;
    }
    QString LogoTipo="MF A0 000000000";
    painter.drawText(3500,size,LogoTipo);
    size+=500;
    if(size>12500) {
        pdf.newPage();
        size=0;
    }
    QString Arrivederci="ARRIVEDERCI E GRAZIE";
    painter.drawText(3250,size,Arrivederci);
    doc->drawContents(&painter);

    delete scontr;
    scontr=new Scontrino(numeroScontrino+1);
}
