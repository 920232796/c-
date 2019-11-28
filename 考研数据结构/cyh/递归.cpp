#include<iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

int r,c;
int a[20][20];
Point source;
Point target;
int mindis=1000;
int use[100][100];  //初始化路径数组
Point res_p[100];

bool judgement(Point P)
{
    if(P.x<0||P.y<0||P.x>r-1||P.y>c-1)
    {
        return false;
    }
    else return true;
}

void travers(Point P,int distance,Point trace[])
{
    int dire[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0; i<4; i++)
    {
        P.x=P.x+dire[i][0];
        P.y=P.y+dire[i][1];
        bool judge=judgement(P);
        if(judge)
        {
            if(a[P.x][P.y]==3)
            {
                distance++;
                trace[distance].x = P.x;
                trace[distance].y = P.y;
                if(distance<mindis)
                {
                    mindis=distance;
                    for(int m=0;m<=mindis;m++)
                    {
                        res_p[m]=trace[m];
                    }
                }
                return;
            }
            if(a[P.x][P.y]==0&&use[P.x][P.y]==0)
            {
                use[P.x-dire[i][0]][P.y-dire[i][1]]=1;
                distance++;

                trace[distance].x=P.x;
                trace[distance].y=P.y;

                travers(P,distance,trace);
                use[P.x-dire[i][0]][P.y-dire[i][1]]=0;
                distance--;
            }

        }
        P.x=P.x-dire[i][0];
        P.y=P.y-dire[i][1];
    }
}


int main()
{
    cout<<"请输入二维数组的行数r："<<endl;
    cin>>r;
    cout<<"请输入二维数组的列数c："<<endl;
    cin>>c;
    cout<<"请输入二维数组："<<endl;
    int distance=0;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            use[i][j]=0;
        }
    }


    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(a[i][j]==2)
            {
                source.x=i;
                source.y=j;
            }
            if(a[i][j]==3)
            {
                target.x=i;
                target.y=j;
            }
        }
    }

    Point trace[100];
    trace[0].x=source.x;
    trace[0].y=source.y;

    travers(source,distance,trace);
    cout<<mindis<<endl;

    for(int r=0;r<=mindis;r++)
    {
       cout<<'('<<res_p[r].x<<','<<res_p[r].y<<')'<<' ';
    }
    return 0;
}