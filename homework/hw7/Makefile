CC = g++
CXXFLAGS = -g -Wall -Wextra -pedantic -std=c++11
wordHunt: wordHuntMain.o CTrie.o WordHunt.o
	$(CXX) -o wordHunt wordHuntMain.o CTrie.o WordHunt.o
cTrieTest: CTrieTest.o CTrie.o
	$(CXX) -o cTrieTest CTrieTest.o CTrie.o
