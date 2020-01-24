#include<iostream>
#include<fstream>
using namespace std;

int wordcount()
{
    ifstream fin;
    fin.open("shakespeare1.txt");
    string data;
    long int Count=0;
    while(fin.eof()!=1)
    {
        fin>>data;
        //cout<<data[0];
        if ((data[0]>=65 && data[0]<=90)||(data[0]>=97 && data[0]<=122))
        {
            Count++;
        }

    }

    //cout<<Count;
    return Count;
}
//807861
