#ifndef REVIZOR_H
#define REVIZOR_H

#include "Radnik.h"
#include "Datum.h"

// Revizor sadrži spisak datuma kada je vršio revizije u odeljenju u kojem je zaposlen
class Revizor : public Radnik {
private:
    vector<Datum> revizije; 

public:
    Revizor();
    Revizor(string id, string ime, string prezime, double plata, vector<Nagrada*> nagrade, string odeljenje,
        Radnik *nadredjeni, vector<Datum> revizije);
    virtual ~Revizor();

    vector<Datum> getRevizije() const;
    void setRevizije(vector<Datum> revizije);
    virtual string getPosao() const;

    virtual void procitaj(istream &input, vector<string> elementi);
    virtual void zapisi(ostream &output) const;
};

#endif // REVIZOR_H