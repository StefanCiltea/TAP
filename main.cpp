#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int a,b;

struct Interval
{
    int a,b;
};

int comp(Interval x, Interval y)
{
    if(x.b>y.b)
        return 0;
    if(x.b<y.b)
        return 1;
    if(x.a>y.a)
        return 0;
    if(x.a<y.a)
        return 1;
}

int main()
{
    ifstream f("date.in");
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

    sort (interval.begin(), interval.end(), comp);

    /*for(int i=0; i<interval.size(); i++)
    cout<<interval[i].a<<" "<<interval[i].b<<endl;*/

    int i=1, aux1=interval[0].a, aux2=interval[0].b;
    while(a<b && i<nr)
    {
        if(interval[i].a<a)
        { aux1 = interval[i].a;   aux2 = interval[i].b; }
        else
        {   cout << aux1 << " " << aux2 << endl;
            a = aux2;
            aux1 = interval[i].a;   aux2 = interval[i].b;
        }

        i++;
    }

    if(a<b)
        cout<<-1;

    return 0;
}
