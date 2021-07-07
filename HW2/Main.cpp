//DAYLAN QUINN
//CS303-PROJECT_2

#include <iostream>
#include <string>
#include <fstream>
#include "Mtree.h"
using namespace std;

int main() {

	//CREATES TREE AND ALLOWS FUNCTIONS TO BE USED TO ENCODE OR DECODE
	Mtree Code;

	//ENCODES LETTERS/WORDS TO SYMBOLS
	Code.encode(ask_encode());
	cout << endl;

	//DECODES SYMBOLS TO LETTERS
	Code.decode(ask_decode());
	cout << endl;

	system("pause");
	return 0;
}