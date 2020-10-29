#include "Kolekcije.h"

Kolekcije::Kolekcije(KolekcijaPreduzeca &preduzeca, KolekcijaOdeljenja &odeljenja, KolekcijaRadnika &radnici, KolekcijaNagrada &nagrade)
: preduzeca(preduzeca), odeljenja(odeljenja), radnici(radnici), nagrade(nagrade) { 

}

void Kolekcije::popuniPreduzeca() {
    for (Preduzece *preduzece : preduzeca.getKolekcija()) {
        for (Odeljenje *odeljenje : odeljenja.getKolekcija()) {
            if (preduzece->getMaticniBroj() == odeljenje->getPreduzece()->getMaticniBroj()) {
                preduzece->getOdeljenja()->push_back(odeljenje);
                odeljenje->setPreduzece(preduzece);
            }
        }
    }
}

void Kolekcije::popuniOdeljenja() {
    for (Odeljenje *odeljenje : odeljenja.getKolekcija()) {
        for (Radnik *radnik : radnici.getKolekcija()) {
            // Dodela zaposlenog odeljenju
            if (odeljenje->getId() == radnik->getOdeljenje()->getId()) {
                odeljenje->getZaposleni()->push_back(radnik);
                radnik->setOdeljenje(odeljenje);
            }
            // Dodela sefa odeljenju
            Radnik *sef = odeljenje->getSef();
            if (sef == nullptr) {
                continue;
            }
            else if (sef->getId() == radnik->getId()) {
                odeljenje->setSef(radnik);
            }
        }
    }
}

void Kolekcije::dodeliNadredjene() {
    for (Radnik *sef : radnici.getKolekcija()) {
        for (Radnik *radnik : radnici.getKolekcija()) {
            if (sef->getId() == radnik->getIdNadredjeni()) {
                radnik->setNadredjeni(sef);
            }
        }
    }

}

void Kolekcije::dodeliNagrade() {
    for (Radnik *radnik : radnici.getKolekcija()) {
        for (Nagrada *nagrada : nagrade.getKolekcija()) {
            if (radnik->getId() == nagrada->getRadnik()->getId()) {
                radnik->getNagrade()->push_back(nagrada);
                nagrada->setRadnik(radnik);
            }
        }
    }
}

void Kolekcije::ukloniPreduzece(Preduzece *preduzece) {
    for(int i = preduzece->getOdeljenja()->size() - 1; i >= 0; i--) {
        Odeljenje *odeljenje = preduzece->getOdeljenja()->at(i);
        ukloniOdeljenje(odeljenje);
    }
    preduzeca.ukloni(preduzece);
}

void Kolekcije::ukloniOdeljenje(Odeljenje *odeljenje) {
    for(int i = odeljenje->getZaposleni()->size() - 1; i >= 0; i--) {
        Radnik *radnik = odeljenje->getZaposleni()->at(i);
        ukloniRadnika(radnik);
    }
    odeljenje->getPreduzece()->ukloniOdeljenje(odeljenje);
    odeljenja.ukloni(odeljenje);
}

void Kolekcije::ukloniRadnika(Radnik *radnik) {
    for(int i = radnik->getNagrade()->size() - 1; i >= 0; i--) {
        Nagrada *nagrada = radnik->getNagrade()->at(i);
        ukloniNagradu(nagrada);
    }
    radnik->getOdeljenje()->otkaz(radnik);
    radnici.ukloni(radnik);
}

void Kolekcije::ukloniNagradu(Nagrada *nagrada) {
    nagrada->getRadnik()->ukloniNagradu(nagrada);
    nagrade.ukloni(nagrada);
}

void Kolekcije::poveziPodatke() {
    popuniPreduzeca();
    popuniOdeljenja();
    dodeliNadredjene();
    dodeliNagrade();
}

void Kolekcije::procitajPodatke() {
    ifstream input("podaci.txt");
    input >> preduzeca;
    input >> odeljenja;
    input >> radnici;
    input >> nagrade;
    input.close();
}

void Kolekcije::ispisiPodatke() {
    ofstream output("podaci.txt");
    output << preduzeca;
    output << odeljenja;
    output << radnici;
    output << nagrade;
    output.close();
}