#include<iostream>
using namespace std;
int main()
{
    int a[20];
    int temp,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n-1;j++)
    {
        
        for(int p=0;p<n-1 - j;p++)
        {
            temp=a[p];
            a[p]=a[p+1];
            a[p+1]=temp;
        }
    }
    for(int m=0;m<n;m++)
    {
        cout<<a[m];
    }
    return 0;
}
