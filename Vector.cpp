#include <iostream>
#include <vector>
using namespace std;
// Vector declaration does not allocate memory address.
// pushback  for input values. It allocates new memory address to store data.
// []  to update values. It does not allocates memory address.
int main()
{
    vector<int> vec;

    for(int i=0; i<10; i++)
        //vec[i] = i;                   Error
        // vec.push_back(i);            For memory allocation
        //cin>>vec[i];                  Error
        {
            int u;
            cin>>u;
            vec.push_back(u);
        }

    for(int i = 0 ; i<10; i++)
        cout<<"vec["<<i<<"] = "<<vec[i]<<endl;

    return 0;
}


