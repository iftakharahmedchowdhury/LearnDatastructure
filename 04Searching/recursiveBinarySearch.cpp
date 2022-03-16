#include <iostream>
using namespace std;

int recursiveBinarySearch(int arr[], int left, int right, int x)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return recursiveBinarySearch(arr, left, mid - 1, x);
        if (arr[mid] < x)
            return recursiveBinarySearch(arr, mid + 1, right, x);
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

    output = recursiveBinarySearch(myarr, 0, 9, n);

    if (output == -1)
    {
        cout << "No Data found" << endl;
    }
    else
    {
        cout << "Data found at position : " << output << endl;
    }

    return 0;
}