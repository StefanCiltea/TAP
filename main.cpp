//
//  main.cpp
//  PD V1P1
//
//  Created by Stefan Ciltea on 27/11/2017.
//  Copyright © 2017 Stefan Ciltea. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct piesa
{
    int ms,md;
};

void LM(int,vector<int>);                      //func de calc a subsirului de lungime maxima
void DoneOrNotDone(int,vector<int>);           //func de introdus piesa
int Isol;                                      //indicele din VP pt o solutime max
vector<vector<piesa>> VP;                      //vector de sol
unsigned long nrmax = 1;                       //nr de piese al solutiei maxime
vector<piesa> v;                               //vector de piese
vector<int> nr;                                //nr de sol de lungime max pt fiecare piesa
int DontJudgeMe(piesa);                        // Returneaza indicele in sirul de piese al piesei date
void finally(vector<int>);                     //Pasul final

int main(int argc, const char * argv[]) {
    
    ifstream f("/Users/stefan/Desktop/TAP/PD V1P1/PD V1P1/date.in");
    int n; f >> n; VP.resize(n); nr.resize(n);
    
    for(int i = 0; i < n; i++)
    {
        piesa auxpiesa;
        f >> auxpiesa.ms >> auxpiesa.md;
        v.push_back(auxpiesa);
        VP[i].push_back(auxpiesa);
    }
    vector<int> IPP;
    
    
    for(  int i = 0; i < n; i++) // Apelarea functiei de calcul pentru fiecare piesa
    LM( i, IPP );
    int nrofall = 0;
    for (int i = 0; i < VP.size(); i++) {
        if( VP[i].size() > nrmax ){
            nrmax = VP[i].size();
            Isol = i;
        }
        if( VP[i].size() == nrmax )
            nrofall += nr[i];
    }
     cout << endl << "O solutie:" << endl;
     for(vector<piesa>::iterator i = VP[Isol].begin(); i != VP[Isol].end(); i++)
        cout << i->ms << " " << i->md << endl;
     cout << "Numarul de solutii:" << nrofall << "\n\n\n\n\n";
    
    
    // Cum arata matricea pentru fiecare piesa:
    unsigned long k = 0;
    while(k < v.size()){
        cout << "sirul de la piesa [" << v[k].ms << " " << v[k].md << "] : ";
        for(vector<piesa>::iterator i = VP[k].begin(); i != VP[k].end(); i++)
            cout << "(" << i->ms << " " << i->md << ") | ";
        cout << endl;
        k++;
    }
    
    
    return 0;
}

void LM(int IPC, vector<int> IPP) //IPP vect de indici ai pieselor precedente, IPC= indicele piesei curente IPS = vec de piese al solutiei potentiale
{
    IPP.push_back(IPC);
    int ok = 1;
    for ( int i = IPC+1; i < v.size(); i++) {
        if( v[IPC].md == v[i].ms ) {
            ok = 0;
            DoneOrNotDone(i, IPP);  //adaug piesa cu indicele i sau sirul de piese de pe indicele i la stivele de piese precedente
        }
    }
    if( ok )
        finally(IPP);
    return;
}

void DoneOrNotDone(int IPC, vector<int> IPP)
{
    if( VP[IPC].size() > 1 ){    // s-a rezolvat subproblema pentru piesa IPC
        for(int i = 1; i < VP[IPC].size(); i++)
            IPP.push_back( DontJudgeMe(VP[IPC][i]) ); //asocierea problemei rezolvate
        finally(IPP);
    }
    else
    LM( IPC, IPP);
    return;
}
int DontJudgeMe(piesa x)  // Returneaza indicele in sirul de piese al piesei date
{
    for( int i = 0; i < v.size(); i++)
        if( x.ms == v[i].ms && x.md == v[i].md)
            return i;
    return -1;
}
void finally(vector<int> IPP)
{
    if( IPP.size() > VP[IPP[0]].size() ){
        nr[IPP[0]] = 1;
        for(int j = 0; j < IPP.size() - 1; j++){
            vector<piesa> vaux;
            for ( int fo = j; fo < IPP.size(); fo++) {
                vaux.push_back(v[IPP[fo]]);
            }
            VP[IPP[j]] = vaux;
        }
    }
    else
        if(IPP.size() == VP[IPP[0]].size())
            nr[IPP[0]]++;
}
