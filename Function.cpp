/**********************
* Автор: Коновалов К.М.*
* Работа: Вариант 9    *
**********************/

#include <iostream>

using namespace std;

int main() {
    
  int  numberOfArrayxElements, numberOfArrayyElements, numberOfArrayzElements, array [numberOfArrayxElements], arrayElement, theSecondElementOfTheArray, maximumElementOfTheArrayX, maximumElementOfTheArrayY, maximumElementOfTheArrayZ;
  
  cout << "Enter numberOfArrayxElements" << endl;
  cin >> numberOfArrayxElements;
  cout << endl;
  
  cout << "Enter numberOfArrayyElements" << endl;
  cin >> numberOfArrayyElements;
  cout << endl;
  
  cout << "Enter numberOfArrayzElements" << endl;
  cin >> numberOfArrayzElements;
  cout << endl;
  
  maximumElementOfTheArrayX = 0;
  maximumElementOfTheArrayY = 0;
  maximumElementOfTheArrayZ = 0;

  cout << "Enter arrayX Elements:" << endl;
  for (arrayElement = 0; arrayElement < numberOfArrayxElements; ++arrayElement) {
    cin >> array [arrayElement];
  }
  cout << endl;
  cout << "arrayX elements: ";
  for (arrayElement = 0; arrayElement < numberOfArrayxElements; ++arrayElement) {
    cout << array [arrayElement] << ", ";
  }
  cout << endl;
  for (arrayElement = 0; arrayElement < numberOfArrayxElements; ++arrayElement) {
    for (theSecondElementOfTheArray = arrayElement + 1; theSecondElementOfTheArray < numberOfArrayxElements; ++theSecondElementOfTheArray) {
      if (array [arrayElement] >  maximumElementOfTheArrayX) {
        maximumElementOfTheArrayX = array [arrayElement];
      }  else {
           maximumElementOfTheArrayX = maximumElementOfTheArrayX;
      }
    }
  }
  cout << endl;
  cout << "Maximum element of the arrayX" << endl;
  cout << maximumElementOfTheArrayX;
  cout << endl;
  
  cout << endl;
  cout << "Enter arrayY Elements:" << endl;
  for (arrayElement = 0; arrayElement < numberOfArrayyElements; ++arrayElement) {
    cin >> array [arrayElement];
  }
  cout << endl;
  cout << "arrayY elements: ";
  for (arrayElement = 0; arrayElement < numberOfArrayyElements; ++arrayElement) {
    cout << array [arrayElement] << ", ";
  }
  cout << endl;
  for (arrayElement = 0; arrayElement < numberOfArrayyElements; ++arrayElement) {
    for (theSecondElementOfTheArray = arrayElement + 1 ;theSecondElementOfTheArray < numberOfArrayyElements; ++theSecondElementOfTheArray) {
      if (array [arrayElement] > maximumElementOfTheArrayY) {
        maximumElementOfTheArrayY = array [arrayElement];
      }  else {
           maximumElementOfTheArrayY = maximumElementOfTheArrayY;
      }
    }
  }
  cout << endl;
  cout << "Maximum element of the arrayY" << endl;
  cout << maximumElementOfTheArrayY;
  cout << endl;
  
  cout << endl;
  cout << "Enter arrayY Elements:" << endl;
  for (arrayElement = 0; arrayElement <numberOfArrayzElements; ++arrayElement) {
    cin >> array [arrayElement];
  }
  cout << endl;

  cout << "arrayY elements: ";
  for (arrayElement = 0; arrayElement < numberOfArrayzElements; ++arrayElement) {
    cout << array [arrayElement] << ", ";
  }
  cout << endl;

  for (arrayElement = 0; arrayElement < numberOfArrayzElements; ++arrayElement) {
    for (theSecondElementOfTheArray = arrayElement + 1; theSecondElementOfTheArray < numberOfArrayzElements; ++theSecondElementOfTheArray) {
      if (array [arrayElement] > maximumElementOfTheArrayZ) {
        maximumElementOfTheArrayZ = array [arrayElement];
      }  else {
           maximumElementOfTheArrayZ = maximumElementOfTheArrayZ;
      }
    }
  }
  cout << endl;
  cout << "Maximum element of the arrayZ" << endl;
  cout << maximumElementOfTheArrayZ;
}