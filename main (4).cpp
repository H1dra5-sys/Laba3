/**************************************
* Автор: Коновалов К.М.               *
* Работа: Арабские и Римские цифры    *
***************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string translationIntoRoman(int arabicNumber) {
    map <int, string, greater<int>> arabicAndRomanNumbers  = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"}, 
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"},
    };
           
    string result = "";
    
    for (auto map : arabicAndRomanNumbers) {           
        while (arabicNumber >= map.first) {      
            result += map.second;       
            arabicNumber -= map.first;            
        }
    }
    
    return result;
}

int translationIntoArabic(string romanNumber) {

  map <char, int> arabicAndRomanNumbers  = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1},
  };
           
  int result = 0;
    
  for (char letter : romanNumber) {      
    if (arabicAndRomanNumbers.count(letter) ) { 
      result += arabicAndRomanNumbers[letter];
  }

  }  
  return result;
}



int main() {
    
  int arabicNumber;
  string romanNumber,translatedNumber;
    
  cout << "Write any number from 1 to 3999: ";
  cin >> arabicNumber;
  cout << arabicNumber << " " << "---> " <<  translationIntoRoman(arabicNumber) << endl; 
  
  cout << "Write any number from I to MMMCMXCIX: ";
  cin  >> romanNumber;
  cout << translatedNumber << " " << "---> " <<  translationIntoArabic(romanNumber);
}