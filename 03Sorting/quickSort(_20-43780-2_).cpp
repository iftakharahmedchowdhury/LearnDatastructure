#include <iostream>
using namespace std;
int partition(int arr[], int start, int last)
{
    int pivot = arr[last];
    int smallIndex = start;

    for (int i = start; i < last; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[smallIndex];
            arr[smallIndex] = temp;
            smallIndex++;
        }
    }

    int temp = arr[last];
    arr[last] = arr[smallIndex];
    arr[smallIndex] = temp;

    return smallIndex;
}

void quickSort(int arr[], int start, int last)
{
    if (start < last)
    {
        int piv = partition(arr, start, last);
        quickSort(arr, start, (piv - 1));
        quickSort(arr, (piv + 1), last);
    }
}

int main()
{

    int n = 0;
    cout << "Enter your array size: " << endl;
    cin >> n;
    int arr[n];

    cout << "Enter your elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Show elements before sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, (n - 1));

    cout << "Show elements after sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
