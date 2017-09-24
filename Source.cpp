//Huy Tran
//Hw1 part 3
//	I have trouble removing an object in the array.Setting the obj at that index to new T() is not an
//	optimal solution since there is still gap between the objects and also the size of the array will not
//	act properly (we can not decrement size since we lose the last element).
//	C++ array doesn't allow us to delete an element unless its a pointer.

#include <iostream>
using namespace std;
#include<stdlib.h> //to use the random function

template <class T>
class Collection {
private:
	T collection[1000];
	int size = 0;
	void remove(int x);
public:
	bool isEmpty();
	void makeEmpty();
	void insert(T x);
	void remove(T x);
	void removeRandom();
	bool notContained(T x);
};

template <class T>
bool Collection<T>::isEmpty() {
	if (size == 0) {
		cout << "The collection is empty." << endl;
		return true;
	}
	cout << "The collection is not empty." << endl;
	return false;
}

template <class T>
void Collection<T>::insert(T x) {
	collection[size] = x;
	size++;
	cout << "Insert successful! " << endl;
}

template <class T>
void Collection<T>::remove(T x) {
	if (size == 0) {
		return;
	}
	for (int i = 0; i < size; i++) {
		if (collection[i] == x) {
			collection[i] = collection[999];
			cout << "Removed index " << i << endl;
		}
		return;
	}
}

template <class T>
void Collection<T>::remove(int x) {
	if (x < size && x >= 0) {
		collection[x] = collection[999];
		cout << "Removed index " << x << endl;
	}
}

template <class T>
void Collection<T>::removeRandom() {
	int toRemove = rand() % size;
	remove(toRemove);
	cout << "Remove randomly successful!" << endl;
	return;
}

template <class T>
void Collection<T>::makeEmpty() {
	for (int i = 0; i < size; i++) {
		collection[i] = collection[999];
	}
	cout << "Making empty successful!" << endl;
	return;
}

template <class T>
bool Collection<T>::notContained(T x) {
	for (int i = 0; i < size; i++) {
		if (collection[i] == x) {
			cout <<"Contained" << endl;
			return false;
		}
	}
	cout << "Not contained" << endl;
	return true;
}


int main() {
	Collection<string> stringCollection;
	stringCollection.isEmpty();

	string toInsert1 = "insert this!";
	string toInsert2 = "insert this too1";
	string toInsert3 = "insert this three!";
	cout << "Trying to insert \"insert this!\": ";
	stringCollection.insert(toInsert1);
	cout << endl;

	cout << "Testing if contained \"insert this!\": ";
	stringCollection.notContained(toInsert1);
	cout << endl;

	cout << "Testing if contained \"boooo\": ";
	stringCollection.notContained("boooo");
	cout << endl;

	cout << "Testing removing \"insert this!\": ";
	stringCollection.remove(toInsert1);
	cout << endl;

	cout << "Testing if empty : ";
	stringCollection.isEmpty();
	cout << endl;

	cout << "Inserting 3 strings: " << endl;
	stringCollection.insert(toInsert1);
	stringCollection.insert(toInsert2);
	stringCollection.insert(toInsert3);
	cout << endl;

	cout << "Testing if empty: ";
	stringCollection.isEmpty();
	cout << endl;

	cout << "Testing removing randomly: " << endl;
	stringCollection.removeRandom(); // the random function generates the same sequence every run
									 // we could change the seed to change the sequence but its not the point of the assignment
	cout << endl;

	cout << "Making the collection empty: ";
	stringCollection.makeEmpty();
	return 0;
}