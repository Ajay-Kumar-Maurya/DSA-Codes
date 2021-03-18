#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec = {23,54,23,75,43,74,2356,453,64};

	cout<<vec.capacity()<<endl<<endl;

	vec.reserve(2);

	cout<<vec.size()<<"    "<<vec.capacity();

    return 0;
}
