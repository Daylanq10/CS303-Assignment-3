#include <iostream>
#include <string>
using namespace std;

struct node {
	string data;
	node *next;
};

class list {
private:
	node *head, *tail;
public:
	list() {
		head = NULL;
		tail = NULL;
	}
	void newnode(string name) {
		node *temp = new node;
		temp->data = name;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	void print() {
		node *temp = new node;
		temp = head;
		while (temp != NULL) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	void start(string name) {
		node *temp = new node;
		temp->data = name;
		temp->next = head;
		head = temp;
	}
	void add_postition(int pos, string name) {
		node *pre = new node;
		node *curr = new node;
		node *temp = new node;
		curr = head;
		for (int i = 1; i < pos; i++) {
			pre = curr;
			curr = curr->next;
		}
		temp->data = name;
		pre->next = temp;
		temp->next = curr;
	}
	void delete_first() {
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}

	void delete_last()
	{
		node *curr = new node;
		node *pre = new node;
		curr = head;
		while (curr->next != NULL)
		{
			pre = curr;
			curr = curr->next;
		}
		tail = pre;
		pre->next = NULL;
		delete curr;
	}
};



int main() {

	list names;
	names.start("Tom");
	names.newnode("John");
	names.newnode("Harry");
	names.newnode("Sam");
	names.start("Bill");
	names.add_postition(4, "Sue");
	names.delete_first();
	names.delete_last();

	system("pause");
	return 0;
}