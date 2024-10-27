/*
*Project 3
* 
* Date: [10/16/24]
* Authoer: [Reid Burns]
*/

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

//Creates a map to store item frequencies, variables for input and output file
class itemSearch {
private:
	map<string, int> itemFrequency;
	string inputFileName = "D:\\School\\CS_210\\Week_7\\Project_3\\CS210_Project_Three_Input_File.txt";
	string outputFileName = "D:\\School\\CS_210\\Week_7\\Project_3\\frequency.dat";


	//method for reading input file, return frequency 
	void readInputFile() {
		ifstream inputFile(inputFileName);
		string item;
		int frequency;
		while (inputFile >> item >> frequency) {
			itemFrequency[item] = frequency;
		}
		//close text file
		inputFile.close();
	}

	//method for writing output file
	void writeOutputFile() {
		ofstream outputFile(outputFileName);
		for (auto item : itemFrequency) {
			outputFile << item.first << " " << item.second << endl;
		}
		//close text file
		outputFile.close();
	}

	//option 1 function, search item
	void searchForItem() {
		string item;
		cout << "What item are you searching for?";
		cin >> item;
		if (itemFrequency.count(item)) {
			cout << item << " has a frequency of " << itemFrequency[item] << endl;
		}
		else {
			cout << "That item was not found." << endl;
		}
	}

	//option 2 function, print item list
	void printList() {
		cout << "List of item frequencies:" << endl;
		for (auto item : itemFrequency) {
			cout << item.first << " " << item.second << endl;
		}
	}

	//option 3 function, print list histogram
	void printHistogram() {
		cout << "Histogram of item frequncies:" << endl;
		for (auto item : itemFrequency) {
			cout << item.first << " ";
			for (int i = 0; i < item.second; i++) {
				cout << "*";
			}
			cout << endl;
		}
	}

	int main() {
		itemSearch itemsearch;

		//User menu options
		int options;
		do {
			cout << "Display Menu:";
			cout << "1. Search for an item";
			cout << "2. Print list of item frequency";
			cout << "3. Print histogram of item frequency";
			cout << "4. Exit program";
			cin >> options;

			//switch for chosen option
			switch (options) {
			case 1:
				itemsearch.searchForItem();
				break;
			case 2:
				itemsearch.printList();
				break;
			case 3:
				itemsearch.printHistogram();
				break;
			case 4:
				cout << "Now exiting program";
				break;
			default:
				cout << "Not a valid option";
			}
		} 
		while (options != 4);

		return 0;
	}

};