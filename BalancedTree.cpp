// Returns the height of the tree if the tree (and each subtree) is balanced. Returns -1 if not.
// Balanced tree: Height(LeftSubtree) - Height(RightSubtree) <= 1

#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int height;
};

int TreeHeight(Node node)
{
    int leftheight, rightheight;
    if(node.left==0) leftheight = 0;
    else leftheight = TreeHeight(*node.left);
    if(node.right==0) rightheight = 0;
    else rightheight = TreeHeight(*node.right);
    if(leftheight==-1 || rightheight==-1) return -1;
    if(abs(leftheight-rightheight)>1) return -1;
    return 1+max(leftheight, rightheight);
}

int main()
{
    /*
    
        n1
       /  \
      n2  n3
     /
    n4
      \
      n5
      
    */
    Node* n1 = new Node();
    Node* n2 = new Node();
    Node* n3 = new Node();
    Node* n4 = new Node();
    Node* n5 = new Node();
    
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = 0;
    n3->left = 0;
    n3->right = 0;
    n4->left = 0;
    n4->right = n5;
    n5->left = 0;
    n5->right = 0;
    
    int h = TreeHeight(*n1);
    cout << h << endl;
}
