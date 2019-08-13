#include<iostream>
using namespace std;
int main()
{
    int i,j,p,q,r,t;
    int n,m,k;
    int a[100][100],b[100][100],c[100][100];
    cin>>n>>m>>k;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>a[i][j];
        }
    }
    for(p=0; p<m; p++)
    {
        for(q=0; q<k; q++)
        {
            cin>>b[p][q];
        }
    }


    for(int y=0; y<n; y++)
    {
        for(int e=0; e<k; e++)
        {
            c[y][e]=0;
        }
    }
    for(int r=0; r<n; r++)
    {
        for(int v=0; v<k; v++)
        {
            for(int t=0; t<m; t++)
            {
                c[r][v]=c[r][v]+a[r][t]*b[t][v];
            }
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<k; j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}