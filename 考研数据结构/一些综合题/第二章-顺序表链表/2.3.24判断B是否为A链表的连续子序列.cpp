#include<iostream>

//B一直从第一个节点开始比 看看跟A一不一样 若不一样 则A指针后移 继续跟B第一个节点比 如果一样 A B 同时后移 若B走到则说明B是A的连续子序列

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }
};

void solve(Node* A, Node* B) {

    while (A != NULL) {
        Node* temp = A;

        Node* temp_B = B;
   
        while (temp_B != NULL) {
            
           
            if (temp != NULL && temp -> data == temp_B -> data) {
                temp = temp -> next;
                temp_B = temp_B -> next;
                if (temp_B == NULL) {
                    cout<<"YES"<<endl;
                    return ;
                }
            } else {
                A = A -> next;
                break;
            }
        }
        
    }
   
    cout<<"NO"<<endl;
    return ;
}

int main() {

    Node* node_B = new Node(4, new Node(8, new Node(9, new Node(11, NULL))));

    Node* node_A = new Node(2, new Node(3, new Node(4, new Node(8, new Node(9, new Node(11, new Node(4, NULL)))))));

    Node* temp_1 = node_A;
    while (temp_1 != NULL)  {
        cout<<temp_1 -> data<<" ";
        temp_1 = temp_1 -> next;
    }
    cout<<endl;

    Node* temp_2 = node_B;
    while (temp_2 != NULL)  {
        cout<<temp_2 -> data<<" ";
        temp_2 = temp_2 -> next;
    }
    cout<<endl;

    solve(node_A, node_B);

    return 0;
}