#include <iostream>
using namespace std;

//MOST FUNCTIONS MADE WITHIN CLASS BTREE ARE RECURSIVE.  IT SEEMED EASIER TO IMPLIMENT AS IT MAKES TREE
//TRAVERSAL EASIER AND SIMPLER.
//SOME OF THE CLASS SETUP WAS HELPED WITH ONLINE SOURCES FOR BETTER IMPLIMENTATION.

//CONSTRUCTS NODES WITH TWO CHILDREN
struct node
{
	int key_value;
	node* left;
	node* right;
};

//CLASS TO CONTAIN BINARY TREE
class btree
{
//CONSTRUCTOR AND DESTRUCTOR
public:
	btree();
	~btree();

	void insert(int key);
	node* print();
	void destroy_tree();
	node* sum();
	int isBST();

private:
	void destroy_tree(node* leaf);
	void insert(int key, node* leaf);
	node* print(node* leaf);
	node* sum(node* leaf);
	int isBST(node* leaf, int min, int max);
	node* root;
};

//DESTRUCTORS
btree::~btree()
{
	destroy_tree();
}

void btree::destroy_tree()
{
	destroy_tree(root);
}

void btree::destroy_tree(node* leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

//CONSTRUCTORS
btree::btree()
{
	root = NULL;
}

//INSERTION/TREE BUILDING
void btree::insert(int key, node* leaf)
{
	if (key < leaf->key_value)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;    //Sets the left child of the child node to null
			leaf->left->right = NULL;   //Sets the right child of the child node to null
		}
	}
	else if (key >= leaf->key_value)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;  //Sets the left child of the child node to null
			leaf->right->right = NULL; //Sets the right child of the child node to null
		}
	}
}

void btree::insert(int key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

//OUTPUTS CONTENTS OF TREE
node* btree::print(node* leaf)
{
	if (leaf != NULL)
	{
		
		if (leaf->left != NULL) {
			cout << leaf->key_value << " ";
			return print(leaf->left);
		}
		else {
			cout << leaf->key_value << " ";
			return print(leaf->right);
		}
	}
	else return NULL;
}


node* btree::print()
{
	return print(root);
}


//ADDS TOGETHER THE TOTAL OF ALL NODES (RECURSIVLEY) #3
node* btree::sum() {
	return sum(root);
}

int total;
node* btree::sum(node* leaf) {
	if (leaf != NULL) {
		if (leaf->left != NULL) {
			total += leaf->key_value;
			return sum(leaf->left);
		}
		else {
			total += leaf->key_value;
			return sum(leaf->right);
		}
	}
	else {
		cout << total;
		return NULL;
		}
}

//TEST IF BINARY TREE IS A BINARY SEARCH TREE #4
int btree::isBST()
{
	return(isBST(root, INT_MIN, INT_MAX));
}

/* RETURNS TRUE (1) IF THE GIVEN TREE IS BST AND VALUES ARE >= MIN AND <= MAX.
   RETURNS FALSE (0) IF NOT. */
int btree::isBST(node* leaf, int min, int max)
{

	//IF EMPTY TREE
	if (leaf == NULL)
		return 1;

	if (leaf->key_value < min || leaf->key_value > max)
		return 0;

	//CHECKS TREE ADJUSTING MIN AND MAX
	return
		isBST(leaf->left, min, leaf->key_value - 1) &&  // Allow only distinct values
		isBST(leaf->right, leaf->key_value + 1, max);  // Allow only distinct values
}


int main() {

	//SAMPLE CONSTRUCTION AND OUTPUT
	btree Dave;
	Dave.insert(1);
	Dave.insert(2);
	Dave.insert(3);
	Dave.insert(4);
	Dave.insert(5);
	Dave.print();
	cout << endl;
	Dave.sum();
	cout << endl;
	cout << Dave.isBST();

	return 0;
}