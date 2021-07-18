#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;

	Node (int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};


///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////   Recursive Solution   ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

// A simple function to print leaf nodes of a binary tree
void printLeaves (Node* root)
{
	if (root == NULL)
		return;

	printLeaves (root->left);

	// Print it if it is a leaf node
	if (! (root->left) && ! (root->right))
		printf ("%d ", root->data);

	printLeaves (root->right);
}

// A function to print all left boundary nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft (Node* root)
{
	if (root == NULL)
		return;

	if (root->left)
	{
		// to ensure top down order, print the node
		// before calling itself for left subtree
		printf ("%d ", root->data);
		printBoundaryLeft (root->left);
	}
	else if (root->right)
	{
		printf ("%d ", root->data);
		printBoundaryLeft (root->right);
	}
	// do nothing if it is a leaf node, this way we avoid
	// duplicates in output
}

// A function to print all right boundary nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight (Node* root)
{
	if (root == NULL)
		return;

	if (root->right)
	{
		// to ensure bottom up order, first call for right
		// subtree, then print this node
		printBoundaryRight (root->right);
		printf ("%d ", root->data);
	}
	else if (root->left)
	{
		printBoundaryRight (root->left);
		printf ("%d ", root->data);
	}
	// do nothing if it is a leaf node, this way we avoid
	// duplicates in output
}

// A function to do boundary traversal of a given binary tree
void boundaryTraversalRecursive (Node* root)
{
	if (root == NULL)
		return;

	while ((!root->left || !root->right) && ! (root->left == root->right))
	{
		// looping tab tk kro jab tk do child wala node mil nhi jata.
		printf ("%d ", root->data);

		if (root->left)
			root = root->left;
		else if (root->right)
			root = root->right;
	}

	printf ("%d ", root->data);

	// Print the left boundary in top-down manner.
	printBoundaryLeft (root->left);

	// Print all leaf nodes
	printLeaves (root->left);
	printLeaves (root->right);

	// Print the right boundary in bottom-up manner
	printBoundaryRight (root->right);
}




///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////   Iterative Solution   ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

void boundaryTraversalIterative (Node* root)
{
	if (root)
	{
		// If there is only 1 node print it and return
		//if (! (root->left) && ! (root->right))
		//{
		//	cout << root->data << endl;
		//	return;
		//}

		vector<Node*> boundaryNode;
		while ((!root->left || !root->right) && ! (root->left == root->right))
		{
			// looping tab tk kro jab tk do child wala node mil nhi jata.
			boundaryNode.push_back (root);

			if (root->left)
				root = root->left;
			else if (root->right)
				root = root->right;
		}

		boundaryNode.push_back (root);

		// Traverse left boundary without root and last node
		Node* L = root->left;
		while (! (L->left == L->right))	// I do not use leaf node
		{
			boundaryNode.push_back (L);
			if (L->left)
				L = L->left;
			else if (L->right)
				L = L->right;
		}

		/*
		// BFS wala code tabhi sahi output dega, jab sabhi leaf node same level pr ho.
		queue<Node*> q;
		q.push (root);
		while (!q.empty())
		{
			Node* temp = q.front();
			q.pop();
			if (! (temp->left) && ! (temp->right))
				boundaryNode.push_back (temp);
			if (temp->left)
				q.push (temp->left);
			if (temp->right)
				q.push (temp->right);
		}
		*/

		stack<Node *> s;
		Node *temp = root;
		while (temp != NULL || !s.empty())
		{
			// Reach the left most Node of the temp Node
			while (temp !=  NULL)
			{
				s.push (temp);
				temp = temp->left;
			}

			// Current must be NULL at this point
			temp = s.top();
			s.pop();

			if (temp->left == temp->right)	// I want to store only leaf node in vector
				boundaryNode.push_back (temp);

			// we have visited the node and itsleft subtree.  Now, it's right subtree's turn
			temp = temp->right;
		}

		// Traverse right boundary without root and last node
		vector<Node*> list_r;
		Node* R = root->right;
		while (! (R->left == R->right))	// I do not use leaf node
		{
			list_r.push_back (R);
			if (R->right)
				R = R->right;
			else if (R->left)
				R = R->left;
		}

		// Reversing the order
		reverse (list_r.begin(), list_r.end());

		// Concatenating the two lists
		boundaryNode.insert (boundaryNode.end(), list_r.begin(), list_r.end());

		// Printing the node's data from the list
		for (auto i : boundaryNode)
			cout << i->data << " ";
		cout << endl;
		return;
	}
}


int main()
{
	// Let us construct the tree given in the above diagram
	struct Node* root = new Node (1);
	root->right = new Node (2);
	root->right->left = new Node (3);
	root->right->right = new Node (4);
	root->right->left->left = new Node (5);
	root->right->left->right = new Node (6);
	root->right->left->left->right = new Node (7);
	root->right->left->right->left = new Node (8);
	root->right->left->right->right = new Node (9);
	root->right->left->right->left->left = new Node (10);
	root->right->left->right->left->right = new Node (11);
	root->right->right->right = new Node (12);
	root->right->right->right->left = new Node (13);

	//boundaryTraversalIterative (root);
	boundaryTraversalRecursive (root);
	return 0;
}
