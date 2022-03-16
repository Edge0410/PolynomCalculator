#include <bits/stdc++.h>
#include <string>
#include "Polynom.h"

//functions for classes used in composition

Algebra::Algebra(unsigned int arg)
{
    this->termeni = arg + 1;
}

Algebra::Algebra(Algebra &ob)
{
    this->termeni = ob.termeni;
}

void Algebra::setTermeni(unsigned int x)
{
    this->termeni = x;
}

void Algebra::setSumaRadacini(std::vector<double> &v)
{
    double denominator = v[0];
    if(denominator != 0 && v.size() > 1)
    {
        this->sumarad = (-1.0 * v[1]) / denominator; 
    }
    else
        this->sumarad = 0.0;
}

void Algebra::setProdusRadacini(std::vector<double> &v)
{
    double denominator = v[0];
    if(denominator != 0 && v.size() == 2)
    {
        this->produsrad = (-1.0 * v[1]) / denominator;
    }
    else if(denominator != 0 && v.size() > 1)
    {
        this->produsrad = (1.0 * v[2]) / denominator; 
    }
    else this->produsrad = 0.0;
}

double Algebra::getSumaRadacini()
{
    return this->sumarad;
}

double Algebra::getProdusRadacini()
{
    return this->produsrad;
}

double Algebra::getSumaRadaciniPatrate()
{
    double suma = this->sumarad;
    double prod = this->produsrad;
    return (suma * suma) - 2 * prod;
}

//functions for main implementation of parent class

int Polynom::GetGrade()
{
    return this->grad;
}

void Polynom::SetGrade(unsigned int arg)
{
    this->grad = arg;
    alg.setTermeni(arg);
    alocate();
}

void Polynom::alocate()
{
    int temp = this->grad + 1;
    this->polinom.resize(temp);
    for(int i=0; i< temp;i++)
    {
        this->polinom[i] = 0;
    }
}

Polynom::Polynom(unsigned int arg)
    :alg(arg)
{
    this->grad = arg;
    alocate();
}

Polynom::Polynom(Polynom &ob)
{
    SetGrade(ob.grad);
    this->polinom = ob.polinom;
}

void Polynom::ProcessSuma()
{
    alg.setSumaRadacini(this->polinom);
}

void Polynom::ProcessProdus()
{
    alg.setProdusRadacini(this->polinom);
}

double Polynom::SumaRad()
{
    return alg.getSumaRadacini();
}

double Polynom::ProdusRad()
{
    return alg.getProdusRadacini();
}

double Polynom::SumaRadPatrat()
{
    double n1 = SumaRad();
    return n1 * n1 - 2 * ProdusRad();
}

Polynom operator -(Polynom& ob1, Polynom& ob2)
{
    //de facut adunarea dintre this cu ob
    Polynom temp;
    int i,j;
    if(ob1.grad > ob2.grad)
    {
        temp.SetGrade(ob1.grad);
        for(i = 0; i < ob1.grad - ob2.grad; i++)
        {
            temp.polinom[i] = ob1.polinom[i];
        }
        for(j = 0; j <= ob2.grad; j++)
        {
            temp.polinom[i] = ob1.polinom[i] - ob2.polinom[j];
            i++;
        }
        return temp;
    }
    else if(ob1.grad < ob2.grad)
    {
        temp.SetGrade(ob2.grad);
        for(i = 0; i < ob2.grad - ob1.grad; i++)
        {
            temp.polinom[i] = ob2.polinom[i];
        }
        for(j = 0; j <= ob1.grad; j++)
        {
            temp.polinom[i] = ob1.polinom[j] - ob2.polinom[i];
            i++;
        }
        return temp;
    }
    else
    {
        int foundfirst = 0;
        int indextemp = 0;
        for(i = 0; i <= ob2.grad; i++)
        {
            if(foundfirst == 1)
            {
                temp.polinom[indextemp] = ob1.polinom[i] - ob2.polinom[i];
                indextemp++;
            }
            if(foundfirst == 0 && (ob1.polinom[i] - ob2.polinom[i]) != 0)
            {
                foundfirst = 1;
                temp.SetGrade(ob2.grad - i);
                temp.polinom[indextemp] = ob1.polinom[i] - ob2.polinom[i];
                indextemp++;
            }
        }
        return temp;
    }
}

Polynom operator +(Polynom& ob1, Polynom& ob2)
{
    //de facut adunarea dintre this cu ob
    Polynom temp;
    int i,j;
    if(ob1.grad > ob2.grad)
    {
        temp.SetGrade(ob1.grad);
        for(i = 0; i < ob1.grad - ob2.grad; i++)
        {
            temp.polinom[i] = ob1.polinom[i];
        }
        for(j = 0; j <= ob2.grad; j++)
        {
            temp.polinom[i] = ob1.polinom[i] + ob2.polinom[j];
            i++;
        }
        return temp;
    }
    else if(ob1.grad < ob2.grad)
    {
        temp.SetGrade(ob2.grad);
        for(i = 0; i < ob2.grad - ob1.grad; i++)
        {
            temp.polinom[i] = ob2.polinom[i];
        }
        for(j = 0; j <= ob1.grad; j++)
        {
            temp.polinom[i] = ob1.polinom[j] + ob2.polinom[i];
            i++;
        }
        return temp;
    }
    else
    {
        int foundfirst = 0;
        int indextemp = 0;
        for(i = 0; i <= ob2.grad; i++)
        {
            if(foundfirst == 1)
            {
                temp.polinom[indextemp] = ob1.polinom[i] + ob2.polinom[i];
                indextemp++;
            }
            if(foundfirst == 0 && (ob1.polinom[i] + ob2.polinom[i]) != 0)
            {
                foundfirst = 1;
                temp.SetGrade(ob2.grad - i);
                temp.polinom[indextemp] = ob1.polinom[i] + ob2.polinom[i];
                indextemp++;
            }
        }
        if(foundfirst == 0)
            temp.SetGrade(0);
        return temp;
    }
}

Polynom& Polynom::operator += (Polynom& ob1)
{
    *this = *this + ob1;
    return *this;
}

Polynom& Polynom::operator += (double nr)
{
    this->polinom[this->grad] += nr;
    return *this;
}

Polynom& Polynom::operator -= (Polynom& ob1)
{
    *this = *this - ob1;
    return *this;
}

Polynom& Polynom::operator -= (double nr)
{
    this->polinom[this->grad] -= nr;
    return *this;
}

Polynom& Polynom::operator *= (Polynom& ob1)
{
    *this = *this * ob1;
    return *this;
}

Polynom& Polynom::operator *= (double nr)
{
    for(int i = 0; i<=this->grad; i++)
        this->polinom[i] *= nr;
    return *this;
}

bool operator == (Polynom& ob1, Polynom& ob2)
{
    if(ob1.grad != ob2.grad)
        return false;
    for(int i = 0; i<=ob1.grad; i++)
    {
        if(ob1.polinom[i] != ob2.polinom[i])
            return false;
    }
    return true;
}

bool operator != (Polynom& ob1, Polynom& ob2)
{
    if(ob1.grad != ob2.grad)
        return true;
    for(int i = 0; i<=ob1.grad; i++)
    {
        if(ob1.polinom[i] != ob2.polinom[i])
            return true;
    }
    return false;
}




Polynom operator *(Polynom &ob1, Polynom &ob2)
{
    Polynom temp;
    int i,j;
    j = 0;
    temp.SetGrade(ob1.grad + ob2.grad);
    for(i=0; i<=temp.grad; i++)
        temp.polinom[i] = 0;
    for(i=0; i<=ob1.grad; i++)
    {
        while(j <= ob2.grad)
        {
            int grad1 = ob1.grad - i;
            int grad2 = ob2.grad - j;
            temp.polinom[temp.grad - (grad1 + grad2)] += ob1.polinom[i] * ob2.polinom[j];
            j++;
        }
        j = 0;
    }
    return temp;
}

Polynom operator *(Polynom &ob1, double nr)
{
    if(nr == 0)
    {
        ob1.SetGrade(0);
        ob1.polinom[0] = 0;
        return ob1;
    }
    for(int i = 0; i<= ob1.grad; i++)
    {
        ob1.polinom[i] *= nr;
    }
    return ob1;
}

Polynom operator *(double nr, Polynom& ob1)
{
    if(nr == 0)
    {
        ob1.SetGrade(0);
        ob1.polinom[0] = 0;
        return ob1;
    }
    for(int i = 0; i<= ob1.grad; i++)
    {
        ob1.polinom[i] *= nr;
    }
    return ob1;
}

std::ifstream &operator >>(std::ifstream &stream, Polynom &ob)
{
    stream >> std::ws;
    for (int i = 0; i <= ob.grad; i++)
        stream >> ob.polinom[i];
    return stream;
}

std::istream &operator >>(std::istream &stream, Polynom &ob)
{
    stream >> std::ws;
    for (int i = 0; i <= ob.grad; i++)
        stream >> ob.polinom[i];
    return stream;
}

std::ofstream &operator <<(std::ofstream &stream, Polynom &ob)
{
    bool primul = 0;
    for (int i = 0; i <= ob.grad; i++){
        if(ob.polinom[i] != 0){
            if(primul == 1)
            {
                if(ob.polinom[i] < 0)
                    stream << " - ";
                else
                    stream << " + ";
                if(i != ob.grad)
                    stream<<fabs(ob.polinom[i])<<"x^"<<ob.grad-i;
                else
                    stream<<fabs(ob.polinom[i]);
            }
            if(primul == 0)
            {
                primul = 1;
                if(ob.polinom[i] < 0)
                    stream << "-";
                if(i != ob.grad)
                    stream<<fabs(ob.polinom[i])<<"x^"<<ob.grad-i;
                else
                    stream<<fabs(ob.polinom[i]);
            }
        }
    }
    if(ob.grad == 0 && ob.polinom[0] == 0)
        stream << 0;
    return stream;
}

std::ostream &operator <<(std::ostream &stream, Polynom &ob)
{
    bool primul = 0;
    for (int i = 0; i <= ob.grad; i++){
        if(ob.polinom[i] != 0){
            if(primul == 1)
            {
                if(ob.polinom[i] < 0)
                    stream << " - ";
                else
                    stream << " + ";
                if(i != ob.grad)
                    stream<<fabs(ob.polinom[i])<<"x^"<<ob.grad-i;
                else
                    stream<<fabs(ob.polinom[i]);
            }
            if(primul == 0)
            {
                primul = 1;
                if(ob.polinom[i] < 0)
                    stream << "- ";
                if(i != ob.grad)
                    stream<<fabs(ob.polinom[i])<<"x^"<<ob.grad-i;
                else
                    stream<<fabs(ob.polinom[i]);
            }
        }
    }
    if(ob.grad == 0 && ob.polinom[0] == 0)
        stream << 0;
    return stream;
}