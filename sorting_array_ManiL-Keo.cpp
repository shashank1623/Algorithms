#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int arr[] = {0, 98, 761, 100, -982, -72};
    // Get size of array
    size_t len = sizeof(arr) / sizeof(arr[0]);
    // Calling sort() function from STL
    // passing starting and ending address of array.
    sort(arr, arr + len);
    // Printing Output
    cout<<"The sorted array is: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}
