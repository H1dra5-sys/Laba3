/**********************
* Автор: Коновалов К.М.*
* Работа: Вариант 9    *
**********************/

#include <iostream>

using namespace std;

int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int arrayElement = 1; arrayElement < size; ++arrayElement) {
        if (arr[arrayElement] > maxVal) {
            maxVal = arr[arrayElement];
        }
    }
    return maxVal;
}

int main() {
    
  int  size, arr[size], arrayElement;
    
  // First array
  cout << "Number of array X Elements: ";
  cin >> size;
  cout << endl;
  cout << "arrayElement: \n";
  for (int arrayElement = 0; arrayElement < size; ++arrayElement) {
    cin >> arr[arrayElement];
  }
  int maxElementX = findMax(arr, size);
  cout << "Maximum element of the array X: " << maxElementX << endl;
  cout << endl;
    
  // Second array    
  cout << "Number of array Y Elements: : ";
  cin >> size;
  cout << endl;
  cout << "arrayElement: \n";
  for (int arrayElement = 0; arrayElement < size; ++arrayElement) {
    cin >> arr[arrayElement];
  }
  int maxElementY = findMax(arr, size);
  cout << "Maximum element of the array Y: " << maxElementY << endl;
  cout << endl;
    
  // Third array
  cout << "Number of array Z Elements: : ";
  cin >> size;
  cout << endl;
  cout << "arrayElement: \n";
  for (int arrayElement = 0; arrayElement < size; ++arrayElement) {
    cin >> arr[arrayElement];
  }
  int maxElementZ = findMax(arr, size);
  cout << "Maximum element of the array Z: " << maxElementZ << endl;
  cout << endl;
}