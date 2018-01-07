//
//  main.cpp
//  PD V1P2
//
//  Created by Stefan Ciltea on 33/-2/2070.
//  Copyright © 2017 Stefan Ciltea. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

struct cord
{
    int i,j;
};

int n, m;
int MATRICE[1000][1000];
int matCost[1000][1000];
cord matDrum[1000][1000];

void citire();
void afisare();
void robotel(int,int,int);
void VECINARE(int,int);

int main() {
    
    citire();
    
    robotel(1,1,0);
    
    afisare();
    return 0;
}

void citire()
{
    ifstream f("/Users/stefan/Desktop/TAP/PD V1P2/PD V1P2/date.in");
    f >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f >> MATRICE[i][j];
        }
    }
}

void afisare()
{
    ofstream g("/Users/stefan/Desktop/TAP/PD V1P2/PD V1P2/date.out");
    g << matCost[n][m] << endl;
    
    int i=n,j=m;
    
    while(i != 1 || j != 1)
    {
        g << i << " " << j << endl;
        int auxi;
         auxi = matDrum[i][j].i;
            j = matDrum[i][j].j;
            i = auxi;
    }
    g << 1 << " " << 1;
}

void robotel(int i, int j, int sum)
{
    sum += MATRICE[i][j];
    
    if (sum <= matCost[i][j])
        return;
    else
        if(matCost[i][j] == 0)
    {
        matCost[i][j] = sum;
        VECINARE(i, j);
    }
    else
    {
        matCost[n][m] += sum-matCost[i][j];
        VECINARE(i, j);
    }
        
    if(j+1 <= m)
        robotel(i, j+1, sum);
    if(i+1 <= n)
        robotel(i+1, j, sum);
}

void VECINARE(int i, int j)
{
    if(matCost[i][j] > matCost[i-1][j+1]){
        matDrum[i][j+1].i = i;
        matDrum[i][j+1].j = j;
    }
    if(matCost[i][j] > matCost[i+1][j-1]){
    matDrum[i+1][j].i = i;
    matDrum[i+1][j].j = j;
    }
}
