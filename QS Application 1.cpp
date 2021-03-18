#include <iostream>
#include <algorithm>
using namespace std;
void swapping(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void segregate_0and1(int a[], int low, int high)
{
    int left = low;
    int right = high;
    int pivot = 1;

    while(1)
    {
        while(pivot > a[left] && left < high) left++;
        while(pivot <= a[right] && right > low) right--;
        if(left > right) break;
        else swapping(&a[left], &a[right]);
    }
}

void segregate_lesser_greater(int a[], int low, int high)
{
    int left = low;
    int right = high;
    int pivot = 34;

    while(1)
    {
        while(pivot >= a[left] && left < high) left++;
        while(pivot < a[right] && right >= low) right--;
        if(left >= right) break;
        else swapping(&a[left], &a[right]);
    }
}


int main()
{
    //int A[] = {76,34,23,65,34,98,34,27,65,76,45,14,76,48,47,76,59,5,7,17};
    //int A[] = {3,0,3,0,2,0,1,3,2,1,2,1,0,0,1,1,0,2,0,2,0,1};
    int A[] = {1,1,1,1,1,1,1,1};
    int size = sizeof(A)/sizeof(A[0]);

    //segregate_lesser_greater(A,0,size-1);
    segregate_0and1(A,0,size-1);

    for(int i = 0; i<size; i++)
    {
        cout<<A[i]<<"    ";
    }
}

/*      For any value of pivot
                    Type 1
void segregate_lesser_greater(int a[], int low, int high)
{
    int left = low;
    int right = high;
    int pivot = 40;

    while(1)
    {
        while(pivot >= a[left] && left < high) left++;
        while(pivot < a[right] && right >= low) right--;
        if(left >= right) break;
        else swapping(&a[left], &a[right]);
    }
}


            Type 2
void segregate_lesser_greater(int a[], int low, int high)
{
    int left = low;
    int right = high;
    int pivot = 40;

    while(1)
    {
        while(pivot > a[left] && left < high) left++;
        while(pivot <= a[right] && right >= low) right--;
        if(left >= right) break;
        else swapping(&a[left], &a[right]);
    }
}

*/

/*              Segrete 0s nd 1s
void segregate_0and1(int a[], int low, int high)
{
    int left = low;
    int right = high;
    int pivot = 1;

    while(1)
    {
        while(pivot > a[left] && left < high) left++;
        while(pivot <= a[right] && right >= low) right--;
        if(left >= right) break;
        else swapping(&a[left], &a[right]);
    }
}
*/
