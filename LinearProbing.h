#include<iostream>
#include <fstream>
#include<string>
#include"Word Count.h"
using namespace std;

const unsigned int tablesize =30000;
const int prime = 22277;

class Hash
{
   public:
   string hashtable [tablesize];
   int Freq[tablesize]={0};//frequency
   int CNT=0;//Count Number of entries(unique)
    void Insert(string key)
    {
        int index=hash1(key);
        if (hashtable [index].empty() != 1)//If not empty
        {
            if(check(index,key))
            {
                int newindex = index;
                int i = 1;
                while (i < tablesize)
                {
                    newindex = (newindex + prime) % tablesize;
                    if (hashtable [newindex].empty() == 1) //Unique Word
                    {
                        hashtable [newindex] = key;
                        Freq[newindex]++;
                        CNT++;
                        break;
                    }
                    else
                    {
                        if(check(newindex,key)==0)//Same Word
                            break;
                    }
                    i++;
                }
            }
        }
        else
        {
            hashtable [index] = key;
            Freq[index]++;
        }
    }

    //Check for Repeated word
    bool check(int index, string key)
    {
        if(key.compare(hashtable[index])==0)
        {
            Freq[index]++;
            //cout<<key;
            return 0;
        }
        return 1;
    }

    //Display Hash Table
    void display()
    {
        cout << endl << "Keys in the Hash Table:" << endl;
        for (int i = 0; i < tablesize; i++)
        {
            if (hashtable [i].empty() != 1)
            {
                cout<< i << "\t" << hashtable[i]<<"\t"<<Freq[i]<<endl;
            }
            else
            {
                cout << i << endl;
            }
        }
    }

    //Hash Function
    int hash1(string key)
    {
        return key[0] % tablesize;
    }
};


