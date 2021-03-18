#include<iostream>
using namespace std;

void swapping(int &a, int &b) {
   int temp;
   temp = a;
   a = b;
   b = temp;
}

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

            // By Tutorials Point
int partition(int *array, int lower, int upper) {
   int pivot, start, end;
   pivot = array[lower];      //first element as pivot
   start = lower; end = upper;

   while(start < end) {
      while(array[start] <= pivot && start<end) start++;      //start pointer moves to right
      while(array[end] > pivot) end--;

      if(start < end) {
         swap(array[start], array[end]); //swap smaller and bigger element
      }
   }
   array[lower] = array[end];
   array[end] = pivot;

   return end;
}

void quickSort(int *array, int left, int right) {
   int q;

   if(left < right) {
      q = partition(array, left, right);
      quickSort(array, left, q-1);    //sort left sub-array
      quickSort(array, q+1, right);   //sort right sub-array
   }
}


                    // By AKM

int par(int a[], int low, int high)             // 100% Working    pivot = low index
{
    int left = low+1;
    int right = high;
    int pivot = a[low];

    while(1)
    {
        while(pivot >= a[left] && left < high) left++;
        while(pivot < a[right] && right >= low) right--;
        if(left >= right) break;
        else swapping(a[left], a[right]);
    }
    swapping(a[right], a[low]);

    return right;
}

int part(int a[], int low, int high)    // pivote = high    100% Correct
{
    int left = low;
    int right = high-1;
    int pivot = a[high];

    while(1)
    {
        while(pivot >= a[left] && left < high) left++;
        while(pivot < a[right] && right >= low) right--;
        if(left >= right) break;
        else swapping(a[left], a[right]);
    }
    swapping(a[left], a[high]);

    return left;
}



int main() {

    int arr[] = {76,23,65,98,34,27,65,45,14,48,47,59,5,7,17};
    //int arr[] = {0,0,1,3,2,0,2,0,2,2,0,1};
    //int arr[] = {23,65,98,34,27,65,45,48,47,59,5,7,17};
    //int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"size = "<<size<<endl<<"first = 0\t"<<"second = "<<size-1<<endl<<endl;
    //int p= partition(arr, 0, size-1);
    //int p= part(arr, 0, size-1);
    //cout<<"Partition Index : = "<<p<<endl;

    //int p= par(arr, 0, size-1);
    cout<<"Partition Index : = "<<p<<endl;

    /*
   cout << "Array before Sorting: ";
   display(arr, size);
   quickSort(arr, 0, size-1); //(size-1) for last index
   cout << "Array after Sorting: ";
   display(arr, size);
*/
}
