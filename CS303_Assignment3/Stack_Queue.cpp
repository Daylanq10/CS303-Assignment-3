#include <iostream>;
#include <stack>;
#include <queue>;
#include <string>;
using namespace std;


//PROBLEM #8
//Function to move first element of queue to end
queue<int> move_to_rear(queue<int> numbers) {

	//Assigns first element to hold for later and removes from queue
	int size = numbers.size();
	int to_rear = numbers.front();
	numbers.pop();
	vector<int> holder;

	//Uses temporary vector to hold remaining elements of queue then place previous first element in rear
	for (int i = 0; i < size - 1; i++) {
		holder.push_back(numbers.front());
		numbers.pop();
	}
	holder.push_back(to_rear);
	
	//Places contents of vector back into queue in new order
	for (int i = 0; i < holder.size(); i++) {
		numbers.push(holder[i]);
	}
	return numbers;
}

//Function to print out queue
void print_queue(queue<int> numbers) {
	int size = numbers.size();
	for (int i = 0; i < size; i++) {
		cout << numbers.front() << " ";
		numbers.pop();
	}
	cout << endl;
}


int main() {

	//PROBLEM #3
	string s = "The quick brown fox jumps over the lazy dog.";
	stack <string> sent;
	string word = "";

	//Assigns x to each char in string s
	for (auto x : s) {
		//Accounts for spaces
		if (x == ' ') {
			sent.push(word);
			word = "";
		//Accounts for periods
		}
		else if (x == '.') {
			word = word + x;
			sent.push(word);
		}
		//Concatenates chars into words
		else {
			word = word + x;
		}
	}
	
	//Goes through stack and outputs words LIFO
	while (!sent.empty()) {
		cout << " " << sent.top();
		sent.pop();
	}

	cout << endl;

	//Test for problem #8
	queue<int> numbers;
	numbers.push(10);
	numbers.push(15);
	numbers.push(20);

	numbers = move_to_rear(numbers);
	print_queue(numbers);

	system("pause");
	return 0;
}
