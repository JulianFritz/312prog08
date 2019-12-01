#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "hashTable.h"

using namespace std;

int main() {

        ifstream inFile;
        inFile.open("words.txt");
        const int QUEUESIZE = 6;
        vector<string> queue;
        string key;
        string temp;
        string fileName = "words.txt";
        for(int i = 0;i < QUEUESIZE;i++) {
                inFile >> temp;
                queue.push_back(temp);
                cout << queue[i] << " ";
                key = key + queue[i];
        }
cout << key << endl;
        HashTable ht;
        ht.insertHash(key, fileName);

        while(!(inFile.eof())) {
                queue.erase(queue.begin());
                inFile >> temp;
                queue.push_back(temp);
                string tempkey;
                for(int i = 0;i < QUEUESIZE;i++) {
                        tempkey = tempkey + queue[i];
                }
cout << tempkey << endl;
                ht.insertHash(tempkey, fileName);
        }
        //now the first document is in
}
