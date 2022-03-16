#include <iostream>
using namespace std;

int binarySearchUsingLoop(int arr[], int left, int right, int x)
{

    for (int i = 0; left <= right; i++)
    {

        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return true;
        }
        else if (arr[mid] > x)
        {
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return -1;
}

int main()
{
    int myarr[10];
    int n;
    int output;

    cout << "Please enter 10 elements ASCENDING order" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> myarr[i];
    }
    cout << "Please enter an element to search" << endl;
    cin >> n;

    output = binarySearchUsingLoop(myarr, 0, 9, n);

    if (output == -1)
    {
        cout << "No Data found" << endl;
    }
    else
    {
        cout << "Data found " << endl;
    }

    return 0;
}