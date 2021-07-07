#pragma once
#include <iostream>
#include <string>
using namespace std;

class Elevator {
private:

	int floor;
	int direction;
	int check;
	queue<int> next;
	
public:

	Elevator();
	void up_floors(int);
	void down_floors(int);
	void output();
	void no_direction(int);
	void execute();
	void check_queue(int);
	
};