#include <iostream>
#include <queue>
#include "Elevator.h"
using namespace std;

//CONSTRUCTOR
Elevator::Elevator()
{
	floor = 0;
	direction = 0;
	check = -1;

}

//UP FLOORS
void Elevator::up_floors(int up)
{
	floor += up;
}

//DOWN FLOORS
void Elevator::down_floors(int down)
{
	floor -= down;
}


//USED THIS TO TRACK WHAT THE ELEVATOR WAS DOING
void Elevator::output()
{
	cout << "Floor: " << floor << endl;

	if (direction > 0) {
		cout << "Going up" << endl;
	}
	else if (direction < 0) {
		cout << "Going down" << endl;
	}
	else {
		cout << "Stationary" << endl;
	}

	/*
	int size = next.size();
	for (int i = 0; i < size; i++) {
		cout << next.back();
		next.pop();
	}
	*/
	cout << endl;
}

//USED TO START ELEVATOR FROM NOTHING
void Elevator::no_direction(int call)
{
	if (direction == 0) {
		int dir = (floor - call);
		if (dir > 0) {
			direction = -1;
			next.push(call);
		}
		else {
			direction = 1;
			next.push(call);
		}
	}
}

//USED TO RUN THE ELEVATOR.  RAN INTO A LOT OF PROBLEMS AS DEQUES WERE NOT RESPONDING HOW I WANTED.  A DENCENT AMOUNT OF 
//ERRORS AND NOT ENOUGH TIME PUT TOWARD THIS TO FIX IT.
void Elevator::execute()
{
	int turn;
	if (check != -1) {
		if (next.size() > 0) {
			turn = next.back();
			next.pop();
		}
		else {
			turn = 0;
		}
	}
	else {
		turn = check;
	}

	if (turn < floor) {
		direction = -1;
	}
	else if (turn > floor) {
		direction = 1;
	}
	else if (turn == floor) {
		direction = 0;
	}


	int move = abs(floor - turn);
	if (direction > 0) {
		up_floors(move);
	}
	else if (direction < 0) {
		down_floors(move);
	}
}

//WAS GOING TO USE THIS TO SET PRIORITY TO THE FLOORS ON THE ELEVATORS PATH INSTEAD OF ADDING THEM TO THE BACK OF THE QUEUE ALL THE TIME
void Elevator::check_queue(int call)
{
	
	if (call < floor && direction < 0) {
		check = call;
	}
	else if (call < floor && direction > 0) {
		next.push(call);
	}
	else if (call > floor && direction > 0) {
		check = call;
	}
	else if (call > floor && direction < 0) {
		next.push(call);
	}
	
}


