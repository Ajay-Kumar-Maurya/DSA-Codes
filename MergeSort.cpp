#include<iostream>
using namespace std;



int main()
{
    int A[] = {97,10,53,28,67,34,27,20,37,76,57,48,65,96,87,17,70,65};
    int size = sizeof(A)/sizeof(A[0]);

    MergeSort(A, 0, size-1);

    for(int i=0; i<sizeM; i++)
    {
        cout<<A[i]<<"   ";
    }

    return 0;
}
