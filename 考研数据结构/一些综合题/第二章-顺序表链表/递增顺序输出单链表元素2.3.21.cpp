#include<iostream>
// 循环一次找出一个最小的 循环两次找次小的。。依次进行下去
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};

void solve(Node* node) {
   
    Node* q;//保存每次遍历的最小节点的前驱节点 方便删除后面的最小节点
    Node* pre;//前驱节点 删除用的
    int min_data = 10000;
    Node* head = new Node(-1, node);

    while (true) {
        if (head -> next == NULL) {
            break;
        }
        Node* temp = head;
        while (temp -> next != NULL) {
            if (temp -> next -> data < min_data) {
                //  找到更小的节点了
                //
                 min_data = temp -> next -> data;
                 q = temp;       
            }
            temp = temp -> next;
        
        }
        //此时q就是最小节点前驱 输出最小数值， 删除q，还原node 还原min_data
        cout<<min_data<<endl;
        Node* u = q -> next; //得到最小节点数据 为了free掉！
        q -> next = q -> next -> next;//删除最小的那个数值 
        free(u);
        // cout<<q -> data<<endl;
        min_data = 10000;

    }

}


int main() {

    Node* node = new Node(5, new Node(4, new Node(8, new Node(1, new Node(4, new Node(4, NULL))))));

    Node* temp = node;
    while (temp != NULL)  {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;

    solve(node);

    return 0;
}