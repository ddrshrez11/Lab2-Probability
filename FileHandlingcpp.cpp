#include<iostream>
#include<fstream>
using namespace std;

int main()
{
//WRITE
//    ofstream fin;
//    fin.open("yunip.txt");
//    fin<<"k cha"<<endl;
//    fin.close();

//READ
    ifstream fin;
    string data;
    fin.open("shakespeare.txt");
    fin>>data;
    cout<<data;
    fin>>data;
    cout<<data;

}
