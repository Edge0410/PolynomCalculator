#include<bits/stdc++.h>
#include "Polynom.h"
using namespace std;
int main()
{
    Polynom ob1(3), ob2(3), ob3; //cream 3 polinoame, dintre care 2 sunt de gradul 3
    cout<<"Introduceti "<<ob1.GetGrade()+1<<" coeficienti: "<<endl;
    cin >> ob1; //suprascrierea operatorilor de citire
    cout<<"Introduceti "<<ob2.GetGrade()+1<<" coeficienti: "<<endl; 
    cin >> ob2;

    cout<<"\n"<<ob1<<"\n"<<ob2<<"\n";

    if(ob1 == ob2) //daca polinoamele sunt egale, adica au aceiasi coeficienti si acelasi grad
    {
        cout<<"Da, sunt egale"<<endl;
    }
    else
    {
        cout<<"Nu, nu sunt egale"<<endl;
    }

    cout<<"Polinomul 2: ";
    ob3 = ob2; //copiem un polinom
    cout<<ob3<<"\n";

    cout<<"Cele 2 polinoame adunate: ";
    ob3 = ob1 + ob2; //adunam doua polinoame
    cout<<ob3<<"\n";

    cout<<"Polinomul 1 + Polinomul 1: ";
    ob3 = ob1; //varianta alternativa
    ob3 += ob1;
    cout<<ob3<<"\n";

    cout<<"Polinomul 1 - Polinomul 2: ";
    ob3 = ob1 - ob2; //scadem doua polinoame
    cout<<ob3<<"\n";

    cout<<"Polinomul 1 - Polinomul 1: ";
    ob3 = ob1; //varianta alternativa
    ob3 -= ob1;
    cout<<ob3<<"\n";

    cout<<"Polinomul 1 * Polinomul 2: ";
    ob3 = ob1 * ob2; //inmultim doua polinoame
    cout<<ob3<<"\n";

    cout<<"Polinomul 1 la patrat: ";
    ob3 = ob1; //varianta alternativa
    ob3 *= ob1;
    cout<<ob3<<"\n";

    cout<<"Polinomul 1 inmultit cu o constanta //3 * polinomul 1: ";
    ob3 *= 3; //inmultim polinomul cu o constanta
    cout<<ob3<<"\n";

    //Relatiile lui Viete pe polinomul ob3:
    ob3.ProcessSuma();
    cout<<"Suma radacinilor polinomului este: "<<ob3.SumaRad()<<endl; 

    ob3.ProcessProdus();
    cout<<"Produsul radacinilor polinomului este: "<<ob3.ProdusRad()<<endl; 
    cout<<"Suma radacinilor la patrat ale polinomului este: "<<ob3.SumaRadPatrat()<<endl;

    return 0; 
}