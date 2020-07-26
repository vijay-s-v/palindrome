#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

// Returns true if input string is a palindrome
// Returns false otherwise
// Assumes input string does not contain punctuation, spacing, or capitals

bool isPalindrome(string s){
	
	// Split input in half
	int midIdx = s.length() / 2;
	string firstHalf, secondHalf;
	
	if(s.length() % 2 == 0){
		
		firstHalf = s.substr(0, midIdx);
		secondHalf = s.substr(midIdx, midIdx);

	}

	else{

		firstHalf = s.substr(0, midIdx);
		secondHalf = s.substr(midIdx + 1, midIdx);		
		
	}

	// Reverse the second half to see if it matches the first
	reverse(secondHalf.begin(), secondHalf.end());
	if(firstHalf == secondHalf){return true;}
	else{return false;}

}

// Given an input string, prints all vowels in order 
// if input string is a palindrome
// Otherwise, prints all consonants in order
int main(int argc, char* argv[]){

	string input = argv[1];
	string vowels = "aeiou";
	
	// Strip input of punctuation and spacing, convert to lower case
	string temp, result;
	remove_copy_if(input.begin(), input.end(), back_inserter(temp), 
		ptr_fun<int, int>(ispunct));
	remove_copy_if(temp.begin(), temp.end(), back_inserter(result), 
		ptr_fun<int, int>(isspace));
	transform(result.begin(), result.end(), result.begin(),
    	[](unsigned char c){return tolower(c);});

	// No input string is given
	if(argc == 1){
		cout << "Error: please provide an input string" << endl;
	}

	else{

		bool palindrome = isPalindrome(result);

		if(palindrome){
			
			for(int i = 0; i < result.length(); ++i){

				size_t found = vowels.find(result[i]);
				if(found != string::npos){
					cout << result[i];
				}

			}
			cout << endl;

		}

		else{

			for(int i = 0; i < result.length(); ++i){

				size_t found = vowels.find(result[i]);
				if(found == string::npos){
					cout << result[i];
				}

			}
			cout << endl;

		}

	}

	return 0;

}