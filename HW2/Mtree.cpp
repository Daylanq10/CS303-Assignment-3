#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include "Mtree.h"
using namespace std;


//CONSTRUCTOR THAT CREATES TREE WHEN MADE
Mtree::Mtree()
{
	root = new node;
	root->left = new node;
	root->right = new node;

	
	ifstream infile;
	infile.open("morse.txt");
	if (infile) {
		char let;
		string sym;
		while (!infile.eof()) {
			infile >> let;
			infile >> sym;
			insert(let, sym);
		}
	}
	infile.close();
	
}

//DESTRUCTORS
Mtree::~Mtree()
{
	destroy_tree();
}

void Mtree::destroy_tree(node* leaf)
{
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void Mtree::destroy_tree()
{
	destroy_tree(root);
}


//USED IN TREE CONSTRUCTION TO PLACE IN CORRECT PARTS OF TREE
void Mtree::insert(char letter, string symbols, node* leaf, int place) {

	if (symbols[place] == '.') {				
		if ((place < symbols.size() - 1)) {
			insert(letter, symbols, leaf->left, place + 1);
		}
		else {
			leaf->left = new node;
			leaf->left->data = letter;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
		}
	}

	if (symbols[place] == '_') {
		if ((place < symbols.size() - 1)) {
			insert(letter, symbols, leaf->right, place + 1);
		}
			else {
			leaf->right = new node;
			leaf->right->data = letter;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
		}
	}
}


void Mtree::insert(char letter, string symbols)
{
	if (root != NULL) {
		insert(letter, symbols, root, 0);	
	}
}

//CHANGES LETTERS TO MORSE CODE FROM OTHER FUNCTIONS
void Mtree::encode(node* leaf, string letters, int place)
{
	vector<char> code;

	for (int i = 0; i < letters.size(); ++i) {
		createpath(leaf, code, letters[i]);
	}
	
	for (int i = 0; i < code.size(); ++i) {
		cout << code[i];
	}
}

void Mtree::encode(string letters)
{
	encode(root, letters, 0);
	cout << endl;
}

//DECODES MORSE CODE INTO LETTERS
void Mtree::decode(node* leaf, string symbols, int place)
{

	if (symbols[place] == '.') {
		decode(leaf->left, symbols, place + 1);
	}
	if (symbols[place] == '_') {
		decode(leaf->right, symbols, place + 1);
	}
	if (symbols[place] == ' ') {
		cout << leaf->data;
		decode(root, symbols, place + 1);
	}
	if (symbols[place] == '/') {
		cout << leaf->data;
		cout << " ";
		decode(root, symbols, place + 1);
	}
	if (place == symbols.size()) {
		cout << leaf->data;
	}
}

void Mtree::decode(string symbols)
{
	decode(root, symbols, 0);
	cout << endl;
}

//INORDER PRINT TO SEE TREE CONSTRUCTION
void Mtree::inorder_print(node* leaf)
{

	if (leaf != NULL) {
		inorder_print(leaf->left);
		cout << leaf->data << ", ";
		inorder_print(leaf->right);
	}
}

void Mtree::inorder_print()
{
	inorder_print(root);
	cout << endl;
}

//CREATES PATH TAKEN TO GET TO LETTER
void Mtree::createpath(node* leaf, vector<char>& code, char letter)
{
	vector<char> store;

	if (pathcheck(root, store, letter)) {
		for (int i = store.size() - 1; i >= 0; --i) {
			code.push_back(store[i]);
		}
	}
	code.push_back('/');
}

//CHECKS IF PATH IS CORRECT OR NOT
bool Mtree::pathcheck(node* leaf, vector<char>& store, char letter)
{
	if (leaf == NULL) {
		return false;
	}

	if (leaf->data == letter) {
		return true;
	}

	if (pathcheck(leaf->left, store, letter)) {
		store.push_back('.');
		return true;
	}
	if (pathcheck(leaf->right, store, letter)) {
		store.push_back('_');
		return true;
	}
	return false;
}

//ASK FOR WORDS TO ENCODE
string ask_encode()
{
	string words;
	string words_lower;
	cout << "Enter letters/words you want to be translated into morse code" << endl;
	cout << "(Your letters/words will be seperated by '/' for different letters and";
	cout << " '//' for a new word. ==>";
	getline(cin, words);
	cout << endl;
	for (int i = 0; i < words.size(); ++i) {
		words_lower += tolower(words[i]);
	}
	return words_lower;
}

//ASK FOR SYMBOLS TO DECODE
string ask_decode()
{
	string code;
	cout << "Enter '.' and '_' is sequence to translate from morse code to letters/words." << endl;
	cout << "Enter a space between letters and '/' between words. ==>";
	getline(cin, code);
	cout << endl;
	return code;
}
