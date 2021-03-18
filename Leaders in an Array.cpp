#include <iostream>
using namespace std;
// Complexity = n^2
int main() {
		int T;
	int size, *arr = NULL;
	cin>>T;
	while(T--)
	{
	    cin>>size;
	    arr = new int[size];

	    for(int i=0; i<size; i++)
	        cin>>arr[i];

	   int flag = 1;

	    for(int i=0; i< size - 1; i++)
	    {
	        for(int j=i+1;j<size;j++)
	        {
	            if(arr[i] < arr[j])
	            {
	                flag = 0;
	                break;
	            }
	        }
	        if(flag == 1)
	        {
	            cout<<arr[i]<<" ";
	        }
	        flag = 1;
	    }

	    cout<<arr[size -1]; // last element of arr is always leader.

	    delete []arr;
	}

	return 0;
}
