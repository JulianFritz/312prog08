#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 100000;

class HashTable {
	private:
		int tableSize;
		vector<int> *table;
	public:
		HashTable();  //Constructor

		void insertHash(string key, int fileNameIdx);	//to insert a key into the hashtable
		
		void deleteHash(string key);	//Didn't end up using this function
		
		int hashFunction(string key);	//returns the hash index of a given key

		void displayHash();	//prints out the whole hash table

		void countCollisions(int ** collCount);	//fills the 2D array with collision counts

		~HashTable(); 	//destructor

};



#endif
