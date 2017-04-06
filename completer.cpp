
#include "search.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

void notfound(std::string wordfromlist); //Function called when a word is not found

int main(int argc, char *argv[])
{
  std::string wordline;
  std::string compword = "";
  std::vector<std::string> wordsVector;
  std::ifstream fileopen(argv[1]); //Reads from file from command line argument
  while (std::getline(fileopen, wordline)) {
	  std::transform(wordline.begin(), wordline.end(), wordline.begin(), ::tolower);
	  //Makes all words lowercase
	  wordsVector.push_back(wordline); //Appends to end of vector wordsVector
  };
  std::cout << "Search for strings by partial match.\nType C-z to halt." << std::endl;
  while (std::cin >> compword) { 
	  //Gathers user input from standard in and exits when input is ^Z
	  std::transform(compword.begin(), compword.end(), compword.begin(), ::tolower);
	  //Makes all characters from user input lowercase
	SearchResultType<std::string> searchresult = iterative_binary_search(wordsVector, compword);
	//Sends vector and word to iterative binary search template
	if (searchresult.found) {
		std::cout << "found: accepting " << searchresult.value << "\n" << std::endl;
		//Simple case when the word is found
	}
	else {
		notfound(searchresult.value);
		//Calls function when word is not found
	};
	std::cout << "Search for strings by partial match.\nType C-z to halt." << std::endl;
	//Repeats the standard out message
  };
  return 0;
  //Return 0 at end of program
};

void notfound(std::string wordfromlist) {
	std::string yesno;
	std::cout << "Not found: accept " << wordfromlist << "? Y/N: ";
	//Gathers user input to accept word
	std::cin >> yesno;
	if (yesno == "y" || yesno == "Y" || yesno == "Yes" || yesno == "YES" || yesno == "yes") {
		std::cout << "ok: accepting " << wordfromlist << "\n" << std::endl;
		//Accepts word if an acceptable yes input is used
	}
	else if (yesno == "n" || yesno == "N" || yesno == "No" || yesno == "NO" || yesno == "no") {
		std::cout << "ok: rejecting " << wordfromlist << "\n" << std::endl;
		//Rejects word if an acceptable no input is used
	}
	else std::cout << "Command not recognized." << "\n" << std::endl;
	//If the command is not valid
};