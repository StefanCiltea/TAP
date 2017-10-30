#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    vector <int> v;

    int n,aux; f >> n;
    for(int i=0; i < n; i++)
    {
        f >> aux;
        v.push_back(aux);
    }

    vector < vector <int> > vv;

    for(vector <int>::iterator it=v.begin(); it != v.end(); it++)
    {
        bool done=false;
        int st=0,dr=vv.size()-1,mij;

        while(st <= dr && !done)
        {
            mij = floor((st+dr)/2);

            if(*it == vv[mij][vv[mij].size()-1])
            {
                vv[mij].push_back(*it);
                done = true;
            }
            else
                if(*it > vv[mij][vv[mij].size()-1])
                st=mij+1;
            else
                dr=mij-1;
        }
        if(done==0)
        {
            if(st<vv.size())
            vv[st].push_back(*it);
        else
            {
                vector <int> a;
                vv.push_back(a);
                vv[vv.size()-1].push_back(*it);
            }
        }
    }

    for(vector < vector <int> >::iterator xx = vv.begin(); xx != vv.end(); xx++ )
    {
        for(vector <int>::iterator tt = (*xx).begin(); tt != (*xx).end(); tt++)
        cout << *tt << " " ;
        cout << endl;
    }


    return 0;
}
