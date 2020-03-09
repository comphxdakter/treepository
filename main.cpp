#include <iostream>
#include <ctime>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
};
void show(Node *&tree)
{
    if(tree)
    {
        show(tree->left);
        cout << tree->data << " ";
        show(tree->right);
    }
}
void addNode(Node *&tree,int data)
{
    if(!tree)
    {
        tree = new Node;
        tree->data=data;
        tree->left=tree->right=nullptr;
    }
    if(data < tree->data)
    {
        if (tree->left)
        {
            addNode(tree->left,data);
        }
        else
        {
            tree->left=new Node;
            tree->left->left=tree->left->right=nullptr;
            tree->left->data=data;
        }
    }
    if(data > tree->data)
    {
        if (tree->right)
        {
            addNode(tree->right,data);
        }
        else
        {
            tree->right=new Node;
            tree->right->left=tree->right->right=nullptr;
            tree->right->data=data;
        }
    }
}

int main() {
    srand(time(NULL));
    Node *tree = nullptr;
    int *arr = new int [10];
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = rand()%10;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; ++i)
    {
        addNode(tree,arr[i]);
    }
    show(tree);
    return 0;
}
