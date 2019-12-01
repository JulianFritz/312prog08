#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <iostream>


using namespace std;

const int MAX_SIZE = 100000;

class HashTable {
        private:
                int tableSize;
                string table[MAX_SIZE];
        public:
                HashTable() { //Constructor
                        tableSize = MAX_SIZE;
                }

                void insertHash(string key, string fileName) {
                        int idx = hashFunction(key);
                        table[idx] = fileName;
                }

                void deleteHash(string key);

                int hashFunction(string key) {
                        int result = 0;
                        for(int i = 0; i < key.length(); i++) {
                                result = result + (key[i]*key[i]);
                        }
cout << result % tableSize << endl;
                        return result % tableSize; //added up all the ascii values squared
                }

};



#endif
