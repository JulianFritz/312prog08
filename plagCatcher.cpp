#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "hashTable.h"
#include <cstdlib>

using namespace std;

int getdir (string dir, vector<string> &files);

int main(int argc, char* argv[]) {

	string filePath = argv[1];
	const int QUEUESIZE = atoi(argv[2]);
	const int PLAGCUTOFF = atoi(argv[3]);

	string dir = string(filePath);
	vector<string> files = vector<string>();

	getdir(dir,files);
	files.erase(files.begin());
	files.erase(files.begin());	//to get rid of the . and .. current directory things at the beginning of the list
	
	HashTable ht;

	for(int idx = 0;idx < files.size();idx++) {

		ifstream inFile;
		string file = filePath + files.at(idx);
		inFile.open(file.c_str());
		if(!inFile) {
			cout << "couldn't open the file" << endl;
			return 0;
		}
		vector<string> queue;
		string key;
		string temp;
		string fileName = files[idx];
	
		for(int i = 0;i < QUEUESIZE;i++) {	//just creates the first n length chunk (aka key)
			inFile >> temp;
			queue.push_back(temp);
			key = key + queue[i];
		}
		ht.insertHash(key, idx);	//passes in idx bc that's the identifier for which file it is, just like fileName
	
	        while(!(inFile.eof())) {
			queue.erase(queue.begin());
			inFile >> temp;
			queue.push_back(temp);
			string tempkey;
			for(int i = 0;i < QUEUESIZE;i++) {
				tempkey = tempkey + queue[i];	//form a new chunk out of the n things in the queue
			}
			ht.insertHash(tempkey, idx);
		}
		//now the whole document is in
	}
	//now all documents are in, need to traverse the hash table to find collisions

	int size = files.size();
	int ** collCount = new int * [size];
	for(int i = 0; i < size; i++){
		collCount[i] = new int[size];	//mallocs the 2D array
		for(int j = 0;j < size;j++)
			collCount[i][j] = 0;	//initialize it to 0
	}
	ht.countCollisions(collCount);	
	//display it:
/*	for(int i = 0;i < size;i++) {
		for(int j = 0;j < size;j++) {
			cout << collCount[i][j] << " ";
		}
		cout << endl << endl;
	}
*/
	for(int i = 0;i < size;i++) {
                for(int j = 0;j < size;j++) {
                        if(collCount[i][j] >= PLAGCUTOFF) {
				//output number of collisions and file names:
				cout << collCount[i][j] << ": " << files[i] << ", " << files[j] << endl;
			}
                }
        }


	for(int i = 0;i < size;i++) {
		delete collCount[i];
	}
	delete collCount;	//free the space so no memory leak

}

//Priebe's code for getting files from a directory
int getdir (string dir, vector<string> &files) {
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}







