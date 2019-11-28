#include<iostream>
using namespace std;


struct Point
{
    int x;
    int y;
    int floor;
};

Point source;
Point target;
int r,c;
int floor=0; //代表层数，也是步数
int a[100][100]; //迷宫数组 ！(注意错解：定义为a[r][c])
int use[100][100]; //判断迷宫中的点是否入过队，初始化为0


typedef struct
{
    int front,rear;
    Point data[100];

    void InitSqueue()
    {
        front=rear=0;
    }

    bool IsFull()
    {
        if((rear+1)%100==front)
        {
            cout<<"队列已满";
            return false;
        }
        else return true;
    }
    bool IsEmpty()
    {
        if(front==rear)
        {
            cout<<"队列为空";
            return false;
        }
        else return true;
    }

    void EnSqueue(Point P)
    {
        bool b1=IsFull();
        if(b1)
        {
            data[rear]=P;
            rear=(rear+1)%100;
        }
        else cout<<"队列已满";
    }

    void OutSqueue()
    {
        bool b2=IsEmpty();
        if(b2)
        {
            front=(front+1)%100;
        }
    }

    Point GetFront()
    {
        Point q;
        if(IsEmpty())
        {
            q=data[front];
        }
        return q;
    }

} squeue;

squeue s; //全局变量队列 用于广度遍历

bool judgement(Point P)
{
    if(P.x<0||P.x>r-1||P.y<0||P.y>c-1)  //判断是否出界
    {
        return false;
    }
    else if(use[P.x][P.y]==1||a[P.x][P.y]==1) return false; //判断是否入过队和是否能走

    else return true;
}

void BFS()
{
    int dire[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
    
    s.EnSqueue(source); //起点入队，修改use数组
    use[source.x][source.y]=1;

    while(s.IsEmpty())
    {
        Point temp;//临时变量

        Point P=s.GetFront();
        temp=P;

        s.OutSqueue();
        for(int i=0; i<4; i++)
        {
            temp.x=P.x+dire[i][0];
            temp.y=P.y+dire[i][1];
            if(judgement(temp))
            {
                if(temp.x==target.x&&temp.y==target.y)
                {
                    temp.floor=P.floor+1;
                    cout<<temp.floor<<endl;
                    return;
                }
                else
                {
//                    temp.x=P.x;
//                    temp.y=P.y;
                    temp.floor=P.floor+1;
                    use[temp.x][temp.y]=1;
                    s.EnSqueue(temp);
                }

            }

        }
    }

}

int main()
{
    cout<<"请输入二维数组的行数r："<<endl;
    cin>>r;
    cout<<"请输入二维数组的列数c："<<endl;
    cin>>c;
    cout<<"请输入二维数组："<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>a[i][j];
            if(a[i][j]==2)
            {
                source.x=i;
                source.y=j;
                source.floor=0;
            }
            if(a[i][j]==3)
            {
                target.x=i;
                target.y=j;
            }
        }
    }

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            use[i][j]=0;
        }
    }

    BFS();

    return 0;
}