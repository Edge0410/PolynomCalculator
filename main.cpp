#include<bits/stdc++.h>
#include "Polynom.h"
using namespace std;
int main()
{
    Polynom ob1(2), ob2(2), ob3, ob4;
    cin >> ob1;
    cin >> ob2;
    cout<<"\n"<<ob1<<"\n"<<ob2<<"\n";

    if(ob1 == ob2)
    {
        cout<<"DA";
    }
    else
    {
        cout<<"NU";
    }



    /*
    //Viete 
    ob3.ProcessSuma();
    cout<<ob3.SumaRad();

    ob3.ProcessProdus();
    cout<<ob3.ProdusRad();
    */

    //adunare
    /*ob3 = ob1 + ob2;
    ob4 = ob3;
    cout << "polinomul 3 " << ob3 <<"\n";
    cout << "polinomul 4 " << ob4 <<"\n";
    ob4 = ob4 + ob3;
    ob3 = ob3;
    cout << "polinomul 3 " << ob3 <<"\n";
    cout << "polinomul 4 " << ob4 <<"\n";
    */
    return 0;
}