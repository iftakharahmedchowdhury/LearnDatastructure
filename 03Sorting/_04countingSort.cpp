#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int max = -5, a;
    int A[n+1];
    cout<<"Enter "<<n<<" numbers: ";
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        A[i]=a;
        if(a >max)
        {
            max=a;
        }
    }

    cout<<"Max value is: "<<max<<endl;

    int C[max+1]={0};

    for(int i=1;i<=n;i++)
    {
        C[A[i]] = C[A[i]] + 1;
    }

    for(int i=1;i<=max;i++)
    {
        cout<<C[i] << " ";
    }
    cout<<endl;
    int cA[max+1]={0};
    cA[1]=C[1];
    for(int i=2;i<=max;i++)
    {
        cA[i]= cA[i-1]+C[i];
    }

    for(int i=1;i<=max;i++)
    {
        cout<<cA[i] << " ";
    }
   cout<<endl;
    int B[n+1];

    for(int i=n;i>=1;i--)
    {
        int x = A[i];
        int y = cA[x];
        B[y]=x;
        cA[x] = cA[x]-1;
    }
    cout<<"After sorting: ";

    for(int i=1;i<=n;i++)
    {
        cout<<B[i] << " ";
    }

}
