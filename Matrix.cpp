/**********************
* Автор: Коновалов К.М.*
* Работа: Вариант 9    *
**********************/


#include <iostream>

using namespace std;

int main() {

  int numberOfRows, rowElement, numberOfColumns, columnElement,  matrix[numberOfRows] [numberOfColumns];

  cout << "Enter the number of rows of the matrix: ";
  cin  >> numberOfRows;
  cout << endl;

  cout << "Enter the number of columns of the matrix: ";
  cin  >> numberOfColumns;
  cout << endl;

  cout << "Enter the elements of the matrix: " << endl;
  for (rowElement = 0; rowElement < numberOfRows; ++rowElement) {
    for (columnElement = 0; columnElement < numberOfColumns; ++columnElement) {
      cin >> matrix[rowElement] [columnElement];
    }
  }

  cout << endl
       << "The usual matrix" << endl; 
  for (rowElement = 0; rowElement < numberOfRows; ++rowElement) {
    for (columnElement = 0; columnElement < numberOfColumns; ++columnElement) {
      cout << matrix[rowElement] [columnElement] << " ";
    }
    cout << endl;
  }

  cout << endl
       << "The transposed matrix" << endl;  
  for (rowElement = 0; rowElement < numberOfColumns; ++rowElement) {
    for (columnElement = 0; columnElement < numberOfRows; ++columnElement) {
      cout << matrix[columnElement] [rowElement] << " ";
    }
    cout << endl;
  }

  cout << endl
       << "The main diagonal" << endl;
  for (rowElement = 0; rowElement < numberOfColumns; ++rowElement) {
    cout << matrix[rowElement] [rowElement] << " ";
  }

  cout << endl;
}
      