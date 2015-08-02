// Returns the next element in a binary search tree.

#include <iostream>
using namespace std;


struct btnode
{
	btnode(int id, btnode* left=NULL, btnode* right=NULL, btnode* parent=NULL)
	{
		Id = id;
		Left = left;
		Right = right;
		Parent = parent;
	}

	int Id;
	btnode* Left;
	btnode* Right;
	btnode* Parent;
};

btnode* Bottomleft(btnode* node)
{
	if (node->Left == NULL) return node;
	return node->Left;
}

btnode* Upright(btnode* node)
{
	if (node->Parent == NULL) return NULL;
	btnode* parent = node->Parent;
	if (parent->Right == NULL) return parent;
	if (parent->Right->Id == node->Id) return Upright(parent);
	return parent;
}

int Btnext(btnode* node)
{
	if (node->Right != NULL)
	{
		btnode* next = Bottomleft(node->Right);
		return next->Id;
	}
	btnode* upright = Upright(node);
	if (upright == NULL) return NULL;
	return Btnext(upright);
}

int main()
{
    /*
    
             n1
          /      \
        n2        n3
      /    \    /    \
    n4      n5 n10   n11
    /  \   /  \
   n6  n7 n8  n9
    
    */
	btnode* n6 = new btnode(6);
	btnode* n7 = new btnode(7);
	btnode* n8 = new btnode(8);
	btnode* n9 = new btnode(9);
	btnode* n4 = new btnode(4, n6, n7);
	btnode* n5 = new btnode(5, n8, n9);
	btnode* n11 = new btnode(11);
	btnode* n10 = new btnode(10);
	btnode* n2 = new btnode(2, n4, n5);
	btnode* n3 = new btnode(3, n11, n10);
	btnode* n1 = new btnode(1, n2, n3, NULL);
	n2->Parent = n1;
	n3->Parent = n1;
	n4->Parent = n2;
	n5->Parent = n2;
	n11->Parent = n3;
	n10->Parent = n3;
	n6->Parent = n4;
	n7->Parent = n4;
	n8->Parent = n5;
	n9->Parent = n5;
	int n = Btnext(n7);
	cout << n << endl;
	int k;
	cin >> k;
}
