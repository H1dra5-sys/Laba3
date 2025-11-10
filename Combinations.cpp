#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main() {
  
  int count;
  string line, TwoLetterCombinations;
  map<char, int> charCount;
  map<string, int> countTwoLetterCombinations;

  ifstream file("Text.txt");
  while (getline(file, line)) {
    cout << line << endl;  
        
  for (char c : line) {
    charCount[c]++;
  }
  
  }
   
  for(auto pair : charCount) {
    cout << "Symbol '" << pair.first << "' Found "
         << pair.second << " Time"   << endl;
  }
  cout << endl;
  
  for (count = 0; count < line.length() - 1; ++count) {
     string  TwoLetterCombinations = line.substr(count, 2); 
        countTwoLetterCombinations[TwoLetterCombinations]++;              
  }
     for(auto pair : countTwoLetterCombinations) {
        cout << "Combinations '" << pair.first << "' Found " 
             << pair.second << " Time" << endl;
     }
}

