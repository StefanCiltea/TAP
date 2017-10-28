#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct activitate
{
    int h,till,nr;
};

int comp(activitate a, activitate b)
{
    if((a.till-a.h)-(b.till-b.h) > 0)
        return 0;
    else
        return 1;
}

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    int n; f >>n;

    vector <activitate> activitati;
    activitate aux;

    for(int i=0; i<n; i++)
    {
        f >> aux.h >> aux.till;
        aux.nr = i+1;
        activitati.push_back(aux);
    }


    sort(activitati.begin(),activitati.end(),comp);



    int greed=0,maxi=numeric_limits<int>::max();

    for(int i=0; i<activitati.size(); i++)
        {   g << "activitatea " << activitati[i].nr << ": intervalul " << greed << " ";
            greed = greed + activitati[i].h;
            g << greed<< " interziere ";
            maxi = max(0,greed-activitati[i].till);
            g << maxi << endl;
        }
    g << "Intarziere planificare " << maxi << endl;


    return 0;
}
