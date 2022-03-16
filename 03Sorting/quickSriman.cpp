#include <iostream>
using namespace std;
int temp;

int partition(int arr[], int start, int end)
{
    int piv = arr[start]; 
    int i = start;
    int j = end;
    while (i < j)
    {
        /* code */
        while (arr[i] <= piv && i<end)
        {
            /* code */
            i++;
        }
        while (arr[j] > piv)
        {
            j--;
        }
        if (i < j)
        {
           // swap(arr[i], arr[j]);
            temp = arr[i];

            arr[i] = arr[j];

            arr[j] = temp;
        }
    }

   // swap(arr[start], arr[j]);
             temp = arr[start];

            arr[start] = arr[j];

            arr[j] = temp;
    return j;
}

void quick_sort(int arr[], int start, int end)
{
    int piv_pos;

    if (start < end)
    {
        piv_pos = partition(arr, start, end);
        quick_sort(arr, start, piv_pos - 1);

        quick_sort(arr, piv_pos + 1, end);
    }
}

int main()
{
    int arr[] = {4,3,2,6,33,66,11,333,555,22222,664636};
    int i;
    int n = sizeof(arr) / sizeof(arr[0]); // n=7/1=7

    cout << n << endl;

    int start = arr[0];
    int end = arr[n];

    cout << arr[0] << endl;
    cout << arr[n] << endl;
    quick_sort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}