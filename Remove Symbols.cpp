#include<iostream>
#include<fstream>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("shakespeare.txt");
    ofstream fout;
    fout.open("shakespeare1.txt");
    string data;
    long int Count=0;
    while(fin.eof()!=1)
    {
        fin>>data;
        //cout<<data[0];
        if ((data[0]>=65 && data[0]<=90)||(data[0]>=97 && data[0]<=122))
        {
            transform(data.begin(), data.end(),data.begin(), ::tolower);
            fout<<data<<" ";
            Count++;
        }

    }
    cout<<Count;
}

