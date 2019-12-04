final: plagCatcher.o hashTable.o
	g++ -o plagiarismCatcher plagCatcher.o hashTable.o
plagCatcher.o: plagCatcher.cpp hashTable.h
	g++ -c plagCatcher.cpp
hashTable.o: hashTable.cpp hashTable.h
	g++ -c hashTable.cpp
