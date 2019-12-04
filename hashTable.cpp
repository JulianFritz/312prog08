#include <string>
#include <iostream>
#include <vector>
#include "hashTable.h"

using namespace std;

HashTable::HashTable() { //Constructor
	tableSize = MAX_SIZE;	//given size is 100,000 declared in the header file
	table = new vector<int>[MAX_SIZE];	//the hash table is a list of vectors that holds the document index
}

void HashTable::insertHash(string key, int fileNameIdx) {
	int idx = hashFunction(key);
	table[idx].push_back(fileNameIdx);
}

void HashTable::deleteHash(string key) {
	//didn't end up using this function
}

int HashTable::hashFunction(string key) {
	int result = 0;
	for(int i = 0; i < key.length(); i++) {
		result = result + (key[i]*key[i]);	//the hash function is adding up the square of the ascii values of the string, modded by tablesize
	}
	return result % tableSize;
}

void HashTable::displayHash() {	//this function is for debugging purposes only, so that I can see if stuff is added to the hashtable correctly
                        for(int i = 0;i < tableSize;i++) {
                                cout << i;
                                for(int j = 0;j < table[i].size();j++)
                                        cout << " --> " << table[i][j];
                                cout << endl;
                        }
                }

void HashTable::countCollisions(int ** collCount) {
	for(int i = 0;i < tableSize;i++) { //for every index in the table
        	if(table[i].size() > 1) { //only if there's a collision at that index
                	for(int j = 0;j < table[i].size() - 1;j++) {
                        	for(int k = j+1;k < table[i].size();k++) { //nested for loops check every combination of the entries in the vector
                                	if(table[i][j] != table[i][k]) {
                                        	//add that collision to the 2d array
                                               	collCount[table[i].at(j)][table[i].at(k)]++;
					}
				}
			}
		}
	}
}

HashTable::~HashTable() {
	//nothing needs to be done in the destructor
	//cout << "In destructor" << endl;
	//displayHash();
}

