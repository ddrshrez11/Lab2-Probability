// C program for Merge Sort */
#include<stdlib.h>
#include<iostream>
#include<string>


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[],std::string arrs[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];
    std::string Ls[n1], Rs[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        Ls[i] = arrs[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1+ j];
        Rs[j] = arrs[m + 1+ j];
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
        {
            arr[k] = L[i];
            arrs[k] = Ls[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            arrs[k] = Rs[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        arrs[k] = Ls[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        arrs[k] = Rs[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array of arr to be sorted */
void mergeSort(int arr[],std::string arrs[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr,arrs, l, m);
        mergeSort(arr,arrs, m+1, r);

        merge(arr,arrs, l, m, r);
    }
}

/* Function to print an array */
//void printArray(int A[],std::string As[], int size)
//{
//    int i;
//    for (i=0; i < 20; i++)
//        std::cout<<std::endl<<A[i]<<"\t"<<As[i]<<std::endl;
//
//}
