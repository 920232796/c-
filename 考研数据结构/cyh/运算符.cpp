#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int answer;
    char c;
    cin>>a>>b>>c;
    if(c=="+"||c=="-"||c=="*"||c=="/")
    {
        if(c="+")
        {
            answer=a+b;
            cout<<answer;
        }
        if(c="-")
        {
            answer=a-b;
            cout<<answer;
        }
        if(c="*")
        {
            answer=a*b;
            cout<<answer;
        }
        if(c="/"&&b!=0)
        {
            answer=a / b;
            cout<<answer;
        }
        else{cout<<"Divided by zone!"<<endl;}
    }
    cout<<"Invaild operator!"<<endl;
    return 0;
}