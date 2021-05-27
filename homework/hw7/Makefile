CC = g++
CXXFLAGS = -g -Wall -Wextra -pedantic -std=c++11
wordHunt: wordHuntMain.o CTrie.o WordHunt.o
	$(CXX) -o wordHunt wordHuntMain.o CTrie.o WordHunt.o
cTrieTest: CTrieTest.o CTrie.o
	$(CXX) -o cTrieTest CTrieTest.o CTrie.o
TTrieTest.o: TTrieTest.cpp TTrie.h TTrie.inc
	g++ $(CXXFLAGS) -c -o TTrieTest.o TTrieTest.cpp
tTrieTest: TTrieTest.o
	$(CXX) -o tTrieTest TTrieTest.o

