#include<stdio.h>
#include<iostream>

using namespace std;
int main()
{
    int a[100],n,i,m,count;
    while(scanf("%d",&n)!=EOF)
    {
        count=0;
        for(i=0;i<n;i++)
        {
            // scanf("%d",&a[i]);
            cin>>a[i];
        }
        scanf("%d",&m);
        for(i=0;i<n;i++)
        {
            if(a[i]==m)
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}