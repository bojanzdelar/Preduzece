#include "KolekcijaNagrada.h"

KolekcijaNagrada::KolekcijaNagrada() {

}

KolekcijaNagrada::KolekcijaNagrada(vector<Nagrada*> *kolekcija) : TabelarnaKolekcija(kolekcija) {

}

KolekcijaNagrada::~KolekcijaNagrada() {

}

int KolekcijaNagrada::kolone() const {
    return 3;
}

string KolekcijaNagrada::zaglavljeKolone(int kolona) const {
    if (kolona == 0) {
        return "ID radnika";
    } 
    else if (kolona == 1) {
        return "Bonus";
    } 
    else if (kolona == 2) {
        return "Broj meseci trajanja";
    } 
    else {
        return "";
    }
}

string KolekcijaNagrada::vrednostPolja(int kolona, int red) const {
    ostringstream out;
    if (kolona == 0) {
        out << kolekcija->at(red)->getRadnik()->getId();
    } 
    else if (kolona == 1) {
        out << kolekcija->at(red)->getProcenti();
    } 
    else if (kolona == 2) {
        out << kolekcija->at(red)->getBrojMeseci();
    }
    return out.str();
}

istream& operator>>(istream &input, KolekcijaNagrada &kolekcijaNagrada) {
    string linija = "";
    while (linija != "#nagrada" && input.peek() != EOF) {
        getline(input, linija);
    }
    while (input.peek() != '#' && input.peek() != EOF) { 
        Nagrada *nagrada = new Nagrada();
        input >> nagrada;
        kolekcijaNagrada.kolekcija->push_back(nagrada);
    }
    return input;
}

ostream& operator<<(ostream &output, const KolekcijaNagrada &kolekcijaNagrada) {
    output << "#nagrada" << endl;
    for (Nagrada *nagrada : *kolekcijaNagrada.kolekcija) {
        output << nagrada;
    }
    return output;
}