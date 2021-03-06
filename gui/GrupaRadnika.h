#ifndef GRUPA_RADNIKA_H
#define GRUPA_RADNIKA_H

#include <FL/Fl_Input.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H>

#include "Tabela.hpp"
#include "PrikazPlata.h"
#include "../kolekcije/Kolekcije.h"

const int MAX_REVIZIJE = 5;
const int MAX_KONTAKTI = 5;

class GrupaRadnika : public Fl_Group {
protected:
    Kolekcije *kolekcije;
    Tabela<Radnik*> *tabela;
    Fl_Input *id;
    Fl_Input *ime;
    Fl_Input *prezime;
    Fl_Float_Input *plata;
    Fl_Input *odeljenje;
    Fl_Input *nadredjeni;
    Fl_Choice *posao;

    // Racunovodja
    Fl_Input *izdavacLicence;
    Fl_Float_Input *maksimalniPrihod;
    // Revizor
    Fl_Choice *brojRevizija;
    Fl_Input *revizije[MAX_REVIZIJE];
    // Komercijalista
    Fl_Choice *brojPoslovnihKontakta;
    Fl_Input *kontakti[MAX_KONTAKTI];
    
    Fl_Button *dodajButton;
    Fl_Button *prikaziButton;
    Fl_Button *izmeniButton;
    Fl_Button *ukloniButton;

    PrikazPlata *plateOdeljenje;
    PrikazPlata *platePreduzece;
    
    static void promeniPosao(Fl_Widget *widget, void *data);
    static void promeniBrojRevizija(Fl_Widget *widget, void *data);
    static void promeniBrojKontakta(Fl_Widget *widget, void *data);
    
    static void dodaj(Fl_Widget *widget, void *data);
    static void prikazi(Fl_Widget *widget, void *data);
    static void izmeni(Fl_Widget *widget, void *data);
    static void ukloni(Fl_Widget *widget, void *data);

public:
    GrupaRadnika(int x, int y, int w, int h, Kolekcije *kolekcije, const char *label = "Radnici");
    virtual ~GrupaRadnika();

    void azuriraj();
};

#endif // GRUPA_RADNIKA_H