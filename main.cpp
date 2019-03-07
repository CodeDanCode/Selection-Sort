#include <iostream>
#include <string>
using namespace std;

void selection_sort(int a[], int size);


int main() {

	int *arr; // pointer for dynamic array
	int size; // size of the array to be sorted
	int *oldArray; // dynamic array to store original numbers
	string answer;  
	bool running;
	string tryAgain;

	do {

		// gets size of array
		cout << "please enter size of array" << endl;
		cin >> size;

		//creates the dynamic array for both original array and the array to be sorted
		arr = new int[size];
		oldArray = new int[size];

		// for loop to get the values to be stored in both arrays
		// for the user the index starts at 1 when in actuality it starts from 0
		for (int i = 0; i < size; i++) {
			cout << "Enter what number you would like in the " << i + 1 << " index : ";
			cin >> arr[i];
			oldArray[i] = arr[i];
		}

		// shows what in current array before sorting
		for (int j = 0; j < size; j++) {
			cout << arr[j] << " ";
		}

		// asks use if they whant to sort or see the list of numbers
		cout << endl;
		cout << "would you like to sort the list of numbers" << endl;
		cout << "please enter 1 or 2\n";
		cout << "1) yes\n";
		cout << "2) no\n";
		cin >> answer; // stores answer

		// if answer is 1 it calls selection sort function and shows both sorted and unsorted numbers
		if (answer == "1") {
			selection_sort(arr, size);
			cout << "your list has been sorted: ";
			for (int k = 0; k < size; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
			cout << "your original list was: ";
			for (int i = 0; i < size; i++) {
				cout << oldArray[i] << " ";
			}
		}
		// if answer is 2 it shows original numbers in array
		else if (answer == "2") {
			cout << "you selected no\n";
			for (int i = 0; i < size; i++) {
				cout << oldArray[i] << " ";
			}
		}
		// error checking for wrong input
		else {
			cout << "you enter wrong number or character" << endl;
			return main();
		}
		
		// asks user if they would like to continue.
		cout << endl;
		cout << endl;
		cout << "would you like to sort another list of numbers" << endl;
		cout << endl;
		cout << "please enter 1 or 2\n";
		cout << "1) yes\n";
		cout << "2) no\n";
		cin >> tryAgain;
		if (tryAgain == "2") {
			running = false;
		}
		else if(tryAgain == "1"){
			running = true;
		}
		else {
			running = false;
		}

		cout << endl;
		cout << endl;

	} while (running == true);


	delete[] arr;
	delete[] oldArray;

	return 0;
} 


// selection sort algorithm sorting from highest to lowest number.
void selection_sort( int a[], int size) {
	int max = 0;
	for (int i = 0; i < size-1; i++) {
		max = i;
		for (int j = (i + 1); j < size; j++) {
			if (a[j] > a[max]) {
				max = j;
			}
		}
		int temp = a[i];
		a[i] = a[max];
		a[max] = temp;
	}
}