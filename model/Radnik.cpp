#include "Radnik.h"
#include "Odeljenje.h"

Radnik::Radnik() {
    nagrade = new vector<Nagrada*>;
}

Radnik::Radnik(string id, string ime, string prezime, double plata, vector<Nagrada*> *nagrade, Odeljenje *odeljenje, Radnik *nadredjeni) 
: id(id), ime(ime), prezime(prezime), plata(plata), odeljenje(odeljenje), nagrade(nagrade), nadredjeni(nadredjeni) {

}

Radnik::~Radnik() {
    for (size_t i = 0; i < nagrade->size(); i++) {
        delete nagrade->at(i);
    }
    delete nagrade;
}

string Radnik::getId() const {
    return id;
}

void Radnik::setId(string id) {
    this->id = id;
}

string Radnik::getIme() const {
    return ime;
}

void Radnik::setIme(string ime) {
    this->ime = ime;
}

string Radnik::getPrezime() const {
    return prezime;
}

void Radnik::setPrezime(string prezime) {
    this->prezime = prezime;
}

double Radnik::getPlata() const {
    double plataBonusi = plata;
    for (size_t i = 0; i < nagrade->size(); i++) {
        plataBonusi += plataBonusi * nagrade->at(i)->getProcenti() / 100;
    }
    return plataBonusi;
}

void Radnik::setPlata(double plata) {
    this->plata = plata;
}

Odeljenje* Radnik::getOdeljenje() const {
    return odeljenje;
}

void Radnik::setOdeljenje(Odeljenje *odeljenje) {
    this->odeljenje = odeljenje;
}

vector<Nagrada*>* Radnik::getNagrade() const {
    return nagrade;
}

void Radnik::setNagrade(vector<Nagrada*> *nagrade) {
    this->nagrade = nagrade;
}

string Radnik::getIdNadredjeni() const {
    return idNadredjeni;
}

Radnik* Radnik::getNadredjeni() const {
    return nadredjeni;
}

void Radnik::setNadredjeni(Radnik *nadredjeni) {
    this->nadredjeni = nadredjeni;
}

void Radnik::dodajNagradu(Nagrada *nagrada) {
    nagrade->push_back(nagrada);
}

void Radnik::ukloniNagradu(Nagrada *nagrada) {
    for (size_t i = 0; i < nagrade->size(); i++) {
        if (nagrada == nagrade->at(i)) {
            nagrade->erase(nagrade->begin() + i);
            return;
        }
    }
}

void Radnik::procitaj(istream &input, vector<string> elementi) {
    id = elementi[0];
    ime = elementi[1];
    prezime = elementi[2];
    plata = stod(elementi[3]);
    Odeljenje *odeljenje = new Odeljenje();
    odeljenje->setId(elementi[4]);
    this->odeljenje = odeljenje;
    idNadredjeni = elementi[5];
}

void Radnik::zapisi(ostream &output) const {
    output << getPosao() << endl;
    output << id << SEP << ime << SEP << prezime << SEP << plata << SEP << odeljenje->getId() << SEP << nadredjeni->getId();
}

istream& operator>>(istream& input, Radnik* radnik) {
    string linija;
    getline(input, linija);
    vector<string> elementi = tokenizacija(linija, SEP);
    radnik->procitaj(input, elementi);
    return input;
}

ostream& operator<<(ostream& output, const Radnik* radnik) {
    radnik->zapisi(output);
    return output;
}