#ifndef POLYNOM_H
#define POLYNOM_H

#include <vector>
class Algebra
{
public:
    Algebra(unsigned int arg = 0);
    Algebra(Algebra&);
    void setSumaRadacini(std::vector<double>&);
    void setProdusRadacini(std::vector<double>&);
    void setTermeni(unsigned int);
    double getSumaRadacini();
    double getProdusRadacini();
    double getSumaRadaciniPatrate();
private:
    unsigned int termeni;
    double sumarad, produsrad;

};

class Polynom
{
public:
    Polynom(unsigned int arg = 0);
    Polynom(Polynom&);
    int GetGrade();
    double Result();
    void SetGrade(unsigned int);
    void ProcessSuma();
    void ProcessProdus();
    double SumaRad();
    double ProdusRad();
    double SumaRadPatrat();
    Polynom& operator +=(Polynom&);
    Polynom& operator +=(double);
    Polynom& operator -=(Polynom&);
    Polynom& operator -=(double);
    Polynom& operator *=(Polynom&);
    Polynom& operator *=(double);
    friend bool operator == (Polynom&, Polynom&);
    friend bool operator != (Polynom&, Polynom&);
    friend Polynom operator +(Polynom&, Polynom&);
    friend Polynom operator -(Polynom&, Polynom&);
    friend Polynom operator *(Polynom&, Polynom&);
    friend Polynom operator *(double, Polynom&);
    friend Polynom operator *(Polynom&, double);
    friend std::ifstream& operator >> (std::ifstream&, Polynom&);
    friend std::istream& operator >> (std::istream&, Polynom&);
    friend std::ofstream& operator << (std::ofstream& , Polynom&);
    friend std::ostream& operator << (std::ostream& , Polynom&);
private:
    unsigned int grad;
    std::vector<double> polinom;
    Algebra alg;
    void alocate();
};

#endif 
