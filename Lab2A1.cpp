#include<iostream>
#include<string>
#include "sorting.cpp"
#include "LinearProbing.cpp"
#include "Remove Symbols.cpp"

using namespace std;
void printArray(int A[],std::string As[], int size)
{
    int i;
    for (i=0; i < 20; i++)
        std::cout<<std::endl<<i<<"\t"<<As[i]<<"\t"<<A[i]<<std::endl;

}
int SORTING(int arr[],int n, string arrs[])
{

    mergeSort(arr,arrs, 0, n - 1);
    printArray(arr,arrs, n);
    return 0;
}

int main()
{
    DoubleHash dh;
    int n;
    ifstream fin;
    fin.open("shakespeare1.txt");
    string key;
    //cout << "Table Size = 90" << endl;
    n=wordcount();
    cout << "Number of words:"<<n<<endl;
//    if (n > tablesize)
//    {
//        cout << "Number of Keys exceed Table capacity" << endl;
//    }
//    else
//    {
         while (fin.eof()!=1)
        {
      		fin >> key;
            dh.Insert(key);
    	}
    //}
    //dh.display();
    cout<<"Number of unique Words:"<<dh.CNT<<endl;
    SORTING(dh.Freq,sizeof(dh.Freq)/sizeof(dh.Freq[0]),dh.hashtable);

}
