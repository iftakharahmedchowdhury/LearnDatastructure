
#include <iostream>
using namespace std;
void quick_sort(int[], int, int);
int partition(int[], int, int);
void quick_sort(int arr[], int start, int end)
{
    int piv_pos;
    if (start < end)
    {
        piv_pos = partition(arr, start, end);
        quick_sort(arr, start, piv_pos - 1); // left
        quick_sort(arr, piv_pos + 1, end);   // right
    }
}
int partition(int arr[], int start, int end)
{
    int i = start;
    int piv = arr[end];
    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < piv)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[end], arr[i]);
    return i;
}
int main()
{
    int arr[] = {8, 17, 6, 1, 2, 5, 9, 10};
    int i;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Given Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quick_sort(arr, 0, n - 1);
    cout << " Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
