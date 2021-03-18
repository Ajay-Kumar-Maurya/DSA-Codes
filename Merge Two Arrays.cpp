#include<iostream>
using namespace std;

// Merging cannot be done in-place. It alwyas requires extra array.    100% Valid

void MergeTwoArrays(int A[], int B[], int C[], int sizeA, int sizeB, int sizeC)
{
    int i = 0, j = 0, m = 0;

    while(1){
        if(A[i] <= B[j]){
            C[m++] = A[i++];
        }
        else{
            C[m++] = B[j++];
        }

        if(i == sizeA || j== sizeB)
            break;
    }

    if(i == sizeA){
        while(j < sizeB){
            C[m++] = B[j++];
        }
    }

    if(j == sizeB){
        while(i < sizeA){
            C[m++] = A[i++];
        }
    }
}


int main()
{
    int A[] = {7,10,13,18,21,26,35,57,65,77};
    int B[] = {5,9,12,16,19,25,28,30,34,39,45,65,75,98};

    int sizeA = sizeof(A)/sizeof(A[0]);
    int sizeB = sizeof(B)/sizeof(B[0]);

    int sizeM = sizeA + sizeB;
    int M[sizeM];

    MergeTwoArrays(A, B, M, sizeA, sizeB, sizeM);

    for(int i=0; i<sizeM; i++)
    {
        cout<<M[i]<<"   ";
    }

    return 0;
}
