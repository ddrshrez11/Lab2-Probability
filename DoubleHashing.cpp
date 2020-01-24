#include<iostream>
#include <fstream>
#include<string>
#include"Word Count.cpp"
using namespace std;

const int tablesize = 90;
const int prime = 67;

class DoubleHash
{
   public:
   string hashtable [tablesize];
   int Freq[tablesize]={0};

    void Insert(string key)
    {
        int index=hash1(key);
        //cout<<endl<<index<<endl;
        if (hashtable [index].empty() != 1)
        {
            if(check(index,key))
            {
                int index2=hash2(key);
                int i = 1;
                while (i < tablesize)
                {
                    int newindex = (index + i * index2) % tablesize;
                    //cout<<endl<<newindex<<endl;
                    if (hashtable [newindex].empty() == 1)
                    {
                        hashtable [newindex] = key;
                        Freq[newindex]++;
                        break;
                    }
                    else
                    {
                        if(check(newindex,key)==0)
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

    int hash1(string key)
    {
        return key[0] % tablesize;
    }

    int hash2(string key)
    {
        return prime - (key[0] %prime);
    }
};

int main()
{
    DoubleHash dh;
    int n;
    ifstream fin;
    fin.open("lorem.txt");
    string key;
    cout << "Table Size = 90" << endl;
    n=wordcount();
    cout << "number of keys:"<<n;
    if (n > tablesize)
    {
        cout << "Number of Keys exceed Table capacity" << endl;
    }
    else
    {
         while (fin.eof()!=1)
        {
      		fin >> key;
            dh.Insert(key);
    	}
    	//dh.display();
    }
    dh.display();
}

