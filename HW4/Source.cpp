#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Problem 2
int to_number(string mix) {
	if (mix.empty()) {
		return 0;
	}
	char temp = mix.at(0);
	if (isdigit(temp) > 0) {
		return temp - '0' + to_number(mix.substr(1));
	}
	else {
		return to_number(mix.substr(1));
	}
}

//Problem 3
int recSearch(vector<int> vect, int index, int length, int x)
{
	if (length < index)
		return -1;
	if (vect[length] == x)
		return length;
	if (vect[index] == x)
		return index;
	return recSearch(vect, index + 1, length - 1, x);
}

void bubbleSort(vector<int>& a)
{
	bool swapp = true;
	while (swapp) {
		swapp = false;
		for (size_t i = 0; i < a.size() - 1; i++) {
			if (a[i] > a[i + 1]) {
				a[i] += a[i + 1];
				a[i + 1] = a[i] - a[i + 1];
				a[i] -= a[i + 1];
				swapp = true;
			}
		}
	}
}

void selectionSort(vector<int>& vect, int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray  
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array  
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (vect[j] < vect[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element  
		swap(vect[min_idx], vect[i]);
	}
}

void insertionSort(vector<int>& vect, int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		j = i;
		tmp = vect[i];
		while (j > 0 && tmp < vect[j - 1])
		{
			vect[j] = vect[j - 1];
			j--;
		}
		vect[j] = tmp;
	}
}

void shellSort(vector<int>& numbers, int size)
{
	int i, j, increment, temp;
	increment = 3;
	while (increment > 0)
	{
		for (i = 0; i < size; i++)
		{
			j = i;
			temp = numbers[i];
			while ((j >= increment) && (numbers[j - increment] > temp))
			{
				numbers[j] = numbers[j - increment];
				j = j - increment;
			}
			numbers[j] = temp;
		}
		if (increment / 2 != 0)
			increment = increment / 2;
		else if (increment == 1)
			increment = 0;
		else
			increment = 1;
	}
}

vector<int>mergeSort(vector<int> left, vector<int> right) {
	size_t ileft = 0, iright = 0;
	vector<int> results;
	while (ileft < left.size() && iright < right.size()) {
		if (left[ileft] < right[iright])
			results.push_back(left[ileft++]);
		else
			results.push_back(right[iright++]);
		while (ileft < left.size()) results.push_back(left[ileft++]);
		while (iright < right.size()) results.push_back(right[iright++]);
		return results;
	}
}

//Partition for quicksort
int partition(vector<int>& values, int left, int right) {
	int pivotIndex = left + (right - left) / 2;
	int pivotValue = values[pivotIndex];
	int i = left, j = right;
	int temp;
	while (i <= j) {
		while (values[i] < pivotValue) {
			i++;
		}
		while (values[j] > pivotValue) {
			j--;
		}
		if (i <= j) {
			temp = values[i];
			values[i] = values[j];
			values[j] = temp;
			i++;
			j--;
		}
	}
	return i;
}

void quickSort(vector<int>& values, int left, int right) {
	if (left < right) {
		int pivotIndex = partition(values, left, right);
		quickSort(values, left, pivotIndex - 1);
		quickSort(values, pivotIndex, right);
	}
}

	

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void print(vector<int> vect) {
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
	cout << endl;
}

int main() {

	/*
	//Problem 2
	string add_num;
	cout << "Enter string with numbers and letters to add numbers only -> ";
	cin >> add_num;
	cout << endl;
	cout << "Your total is " << to_number(add_num) << endl;
	cout << endl;
	*/

	//Problem 3
	//Index and Length in recSearch function start from 0 index
	vector<int> numbers = { 1, 4, 5, 7, 5, 2, 9 };
	cout << recSearch(numbers, 0, 6, 5) << endl;
	
	

	system("pause");
	return 0;
}