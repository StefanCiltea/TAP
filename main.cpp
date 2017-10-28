#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    int a,b;
};

int comp(Interval x, Interval y)
{
    if(x.a>y.a)
        return 0;
    if(x.a<=y.a)
        return 1;
}

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");
    
    int a,b;
    f >>a >>b;

    int nr;
    f>>nr;

    vector <Interval> interval;
    Interval aux;
    for(int i=1; i<=nr; i++)
       {
           f >> aux.a >> aux.b;
            interval.push_back(aux);
       }

    sort (interval.begin(), interval.end(), comp); //ordonare intervale crescator dupa marginea stanga

    vector <Interval> intervalSolutie;    //vectorul cu intervalele ce compun solutia daca exista
    Interval greed=interval[0];  //variabila tip interval ce retine cea mai buna solutiepana cand se ajunge la un element din vector cu marginea stanga mai mare decat  marginea stanga a intervalului dat la inceput
    for(int i=1; i<interval.size(); i++)       //Parcurgem vectorul de intervale
    {
        if(interval[i].a > a)
            if(greed.a <= a && greed.b > a)
                {
                    a = greed.b; intervalSolutie.push_back(greed); greed = interval[i];  //mereu se micsoreaza interalul dat la inceput, noua lui margine stanga fiind marginea dreapta a lui greed
                }
                else
                ;
        else
            if(greed.b < interval[i].b)
            greed = interval[i];

    }


    if(greed.a <= a && greed.b > a)
    {
        a = greed.b; intervalSolutie.push_back(greed);
    }


    if(a<b)
        g<<-1;
    else
        for(int i=0; i<intervalSolutie.size(); i++)
            g<<intervalSolutie[i].a<<" "<<intervalSolutie[i].b<<endl;


    return 0;
}
