/**********************
* Автор: Коновалов К.М.*
* Работа: Вариант 9    *
**********************/


#include <iostream>

using namespace std;

int main() {

  int rows, row_element, columns, column_element,  matrix[rows] [columns];
  
  cout << "Enter the number of rows of the matrix: ";
  cin  >> rows;
  cout << endl;
  
  cout << "Enter the number of columns of the matrix: ";
  cin  >> columns;
  cout << endl;
  
  cout << "Enter the elements of the matrix: " << endl;
  for (row_element = 0; row_element < rows; ++row_element) {
    for (column_element = 0; column_element < columns; ++column_element) {
      cin >> matrix[row_element] [column_element];
    }
  }
  
  cout << endl
       << "The usual matrix" << endl; 
  for (row_element = 0; row_element < rows; ++row_element) {
    for (column_element = 0; column_element < columns; ++column_element) {
  cout << matrix[row_element] [column_element] << " ";
    }
    cout << endl;
  }
  
  cout << endl
       << "The transposed matrix" << endl;  
  for (row_element = 0; row_element < columns; ++row_element) {
    for (column_element = 0; column_element < rows; ++column_element) {
  cout << matrix[column_element] [row_element] << " ";
    }
    cout << endl;
  }
  
  cout << endl
       << "The main diagonal" << endl;
  for (row_element = 0; row_element < columns; ++row_element) {
      cout << matrix[row_element] [row_element] << " ";
  }
  
  cout << endl;
}
