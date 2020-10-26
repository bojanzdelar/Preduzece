#include "Odeljenje.h"

Odeljenje::Odeljenje() {
    zaposleni = new vector<Radnik*>;
}

Odeljenje::Odeljenje(string naziv, Radnik* sef, vector<Radnik*> *zaposleni, string preduzece) 
: naziv(naziv), sef(sef), zaposleni(zaposleni), preduzece(preduzece) {

}

Odeljenje::~Odeljenje() {

}

string Odeljenje::getId() const {
    return id;
}

void Odeljenje::setId(string id) {
    this->id = id;
}

string Odeljenje::getNaziv() const {
    return naziv;
}

void Odeljenje::setNaziv(string naziv) {
    this->naziv = naziv;
}

Radnik* Odeljenje::getSef() const {
    return sef;
}

void Odeljenje::setSef(Radnik* sef) {
    this->sef = sef;
}

vector<Radnik*>* Odeljenje::getZaposleni() const {
    return zaposleni;
}

void Odeljenje::setZaposleni(vector<Radnik*> *zaposleni) {
    this->zaposleni = zaposleni;
}

string Odeljenje::getPreduzece() const {
    return preduzece;
}

void Odeljenje::setPreduzece(string preduzece) {
    this->preduzece = preduzece;
}

double Odeljenje::minimalnaPlata() {
    double min = zaposleni->size() ? zaposleni->at(0)->getPlata() : -1;
    for (size_t i = 1; i < zaposleni->size(); i++) {
        double plata = zaposleni->at(i)->getPlata();
        if (min > plata) {
            min = plata;
        }
    }
    return min;
}

double Odeljenje::prosecnaPlata() {
    double prosek = 0;
     for (size_t i = 0; i < zaposleni->size(); i++) {
         prosek += zaposleni->at(i)->getPlata();
    }
    return prosek / zaposleni->size();
}

double Odeljenje::maksimalnaPlata() {
    double max = zaposleni->size() ? zaposleni->at(0)->getPlata() : -1;
    for (size_t i = 1; i < zaposleni->size(); i++) {
        double plata = zaposleni->at(i)->getPlata();
        if (max < plata) {
            max = plata;
        }
    }
    return max;
}

void Odeljenje::zaposli(Radnik* radnik) {
    zaposleni->push_back(radnik);
}

void Odeljenje::otkaz(int indeks) {
    if (indeks < 0 || indeks >= zaposleni->size()) {
        return;
    }
    zaposleni->erase(zaposleni->begin() + indeks);
}

istream& operator>>(istream &input, Odeljenje *odeljenje) {
    string linija;
    getline(input, linija);
    vector<string> elementi = tokenizacija(linija, SEP);
    odeljenje->id = elementi[0];
    odeljenje->naziv = elementi[1];
    Radnik *sef = new Revizor(); // privremeno, samo da se sacuva id sefa
    sef->setId(elementi[2]);
    odeljenje->sef = sef;
    odeljenje->preduzece = elementi[3];
    return input;
}

ostream& operator<<(ostream &output, const Odeljenje *odeljenje) {
    output << odeljenje->id << SEP << odeljenje->naziv << SEP << odeljenje->sef->getId() << SEP << odeljenje->preduzece << endl;
    return output;
}