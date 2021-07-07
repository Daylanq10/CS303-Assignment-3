#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

//Write a Compare function class that inserts Person objects in a priority queue based on the number of dependents a person has.
//The Person object with the largest number of dependents should be removed first.

//STRUCTURE TO HOLD PERSONS INFO
struct Persons {
	string name; 
	int depend;
};


//CLASS TO COMPARE AND FIND HIGHEST DEPENDENT
class Compare {
private:
	vector<Persons> pri_que;
	int highest;
public:
	Compare() {
		highest = 0;
	};
	void sort_que();
	void take_vect(vector<Persons>);
	void print_que();
	void print_highest();
};

//FINDS HIGHEST DEPENDENT
void Compare::sort_que()
{
	int high = 0;
	int holder = 0;
	for (int i = 0; i < pri_que.size() - 1; i++) {
		for (int j = 0; i < pri_que.size() - 1; i++) {
			if (pri_que.at(i).depend > pri_que.at(j).depend) {
				if (pri_que[i].depend > high) {
					holder = i;
				}
			}
		}
	}
	highest = holder;
}

//ALLOWS PLACEMENT OF VECTOR
void Compare::take_vect(vector<Persons> it)
{
	pri_que = it;
}

//PRINTS OUT ENTIRITY IF NEEDED
void Compare::print_que()
{
	while (!pri_que.empty()) {
		cout << " " << pri_que.back().name;
		pri_que.pop_back();
	}
}

//PRINTS HIGHEST DEPENDENT
void Compare::print_highest()
{
	cout << "Highest dependent is " << pri_que.at(highest).name << endl;
}

//EXAMPLE RUN THROUGH
int main() {
	Persons Dave;
	Persons Lily;
	Persons Daylan;

	Dave.depend = 4;
	Dave.name = "Dave";
	Lily.depend = 8;
	Lily.name = "Lily";
	Daylan.depend = 3;
	Daylan.name = "Daylan";
	
	vector<Persons> People;
	People = { Dave, Lily, Daylan };
	Compare Attempt;
	Attempt.take_vect(People);
	Attempt.sort_que();
	Attempt.print_highest();


	system("pause");
	return 0;
}


