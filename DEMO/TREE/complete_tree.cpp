#include<iostream>
#include<queue>
using namespace std;

struct Node{
        int val;
        Node* left;
        Node* right;
        Node(int val):val(val),left(NULL),right(NULL)
        {}

};

Node* helper(int val, queue<Node*> myq)
{
        if(myq.empty())
                return NULL;
        Node* temp = myq.front();
        myq.pop();
        if(!temp->left)
        {
                temp->left = new Node(val);
                return temp->left;
        }
        else if(!temp->right)
        {
                temp->right = new Node(val);
                return temp->right;
        }
        else
                return helper(val,myq);

}


Node* create_complete_tree(Node* r, int val)
{
        static queue<Node*> myq;
        if(!r)
        {
                Node* temp= new Node(val);
                myq.push(temp);
                return temp;
        }
        myq.push(helper(val,myq));

}

void display(Node* r)
{
        if(!r)
                return;
        cout<<r->val<<endl;
        display(r->left);
        display(r->right);
}


/*
        Idea is- if any level order traversal(breadth first traversla), if we found any node which is not Full( either not having left or right or both) then subsequent node must be leaf node.
Note: still we have one more issue like (special case)

                10
                /\
               /  \
              20   30       Level Oder Traversal: 10,20,30,40- here 20 is first not Full node- hence 30 & 40 are leafs but still 
                \           still it is not Complete binary tree.so we can handle this situation as well
                 \
                 40
*/
bool is_complete(Node* rm, queue<Node*> myq)
{
        static bool flag = false;
        if(myq.empty())
                return true;
        Node* r = myq.front();myq.pop();
        if(flag && (r->left || r->right))
                return false;
        if(r->left == NULL && r->right == NULL)
        {
                flag = true;
        }
        else if(r->left == NULL && r->right != NULL)
        {
                cout<<"Left is empty but right is Not!!\n";
                return false;
        }
        else
        {
                if(r->left)
                        myq.push(r->left);
                if(r->right)
                        myq.push(r->right);
        }
         return is_complete(r,myq);
}

bool is_completeB(Node* r)
{
        if(!r)
                return true;
        queue<Node*> myq;
        myq.push(r);
        return is_complete(r, myq);
}



int main()
{
        Node* root = create_complete_tree(NULL,10);
        create_complete_tree(root,20);
        create_complete_tree(root,18);
        create_complete_tree(root,6);
        //display(root);
        Node* root1=new Node(10);
        root1->left = new Node(8);
        root1->right = new Node(20);
        root1->left->left = new Node(6);
        root1->left->right= new Node(9);
        //root1->left->left->left = new Node(4);
        //root1->left->left->right= new Node(7);
        if(is_completeB(root1) == true)
                cout<<"Complete Tree!!"<<endl;
        else
                cout<<"NOT a Complete Tree :("<<endl;

}
