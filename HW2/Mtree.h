#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//NODES FOR TREE
struct node {
	char data;
	node* left;
	node* right;
};

//TREE AND FUCTIONS THAT CONTROL EVERYTHING
class Mtree {
public:
	Mtree();  
	~Mtree();

	void insert(char letter, string symbols);
	void encode(string letters);	
	void decode(string symbols);
	void destroy_tree();
	void inorder_print();

private:
	void destroy_tree(node* leaf);
	void insert(char letter, string symbols, node* leaf, int place);
	void encode(node* leaf, string letters, int place);		
	void decode(node *leaf, string symbols, int place);
	void inorder_print(node* leaf);
	void createpath(node* leaf, vector<char>& code, char letter);
	bool pathcheck(node* leaf, vector<char>& store, char letter);

	node* root;
};

//THESE ARE FOR EASY USER INPUT
string ask_encode();
string ask_decode();