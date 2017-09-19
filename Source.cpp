//Huy Tran
#include <iostream>
using namespace std;
int arr[] = { 1, 2, 3, 4, 5 };

int increment(int x) { //this function returns by value
	return x + 1;
}

int& getIndex(int i){ //this function returns by reference
	return arr[i];
}

const int& getIndexConst(int i) {
	return arr[i];
}
int main() {
	int a = increment(5); // return by value. Variable x is destroyed
	cout << "Return by value: " << a << endl;
	
	cout << "Return by reference arr[2]: " << getIndex(2) << endl;
	getIndex(2) = 4; // we can do this since its not const return
	cout << "Return by refernce arr[2] after changing value: " << getIndex(2) << endl;
	cout << "Return by const reference arr[2]: " << getIndexConst(2) << endl;
	// if we type "getIndexConst(2) = 4;" we get error: cannot be modified.
	
}
