 /******************************
* Сделал: Коновалов Константин *
* Работа: Вариант N9           *
*******************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double a, W, pow1, step1, step2,  step3,  step4,  step5, Pe, Nu, d;

  pow1 = 3.0 * pow(10.0,3.0);
    
  d = 3.5;
  W = 10.0;
  a = 0.062;

  step1 = 10.0;
  step2 = 30.0;
  step3 = 50.0;
  step4 = 100.0;
  step5 = 300.0;
 
  Pe = W * d / a;
  if (Pe > pow1) {
    Nu = 3.4 + 0.0014 * pow(Pe,0.8);
  }  else {
      Nu = 5 + 0.021 * Pe;
    }

  cout << "Nu = " << Nu << endl
       << "W = "  << W  << endl;
  
  W += step1;
  
  Pe = W * d / a;
  if (Pe > pow1) {
    Nu = 3.4 + 0.0014 * pow(Pe,0.8);
  }  else {
      Nu = 5 + 0.021 * Pe;
     }

  cout << "Nu = " << Nu << endl
       << "W = "  << W  << endl;
  
  W += step2;
  
  Pe = W * d / a;
  if (Pe > pow1) {
    Nu = 3.4 + 0.0014 * pow(Pe,0.8);
  }  else {
      Nu = 5 + 0.021 * Pe;
     }
     
  W += step3;
  
  cout << "Nu = " << Nu << endl
       << "W = "  << W  << endl;
  
  Pe = W * d / a;
  if (Pe > pow1) {
    Nu = 3.4 + 0.0014 * pow(Pe,0.8);
  }  else {
      Nu = 5 + 0.021 * Pe;
     }
  
  W += step4;
  
  cout << "Nu = " << Nu << endl
       << "W = "  << W  << endl;
  
  Pe = W * d / a;
  if (Pe > pow1) {
    Nu = 3.4 + 0.0014 * pow(Pe,0.8);
  }  else {
      Nu = 5 + 0.021 * Pe;
     }
     
  W += step5;
  
  cout << "Nu = " << Nu << endl
       << "W = "  << W  << endl;
  
    Pe = W * d / a;
  if (Pe > pow1) {
    Nu = 3.4 + 0.0014 * pow(Pe,0.8);
  }  else {
      Nu = 5 + 0.021 * Pe;
     }
     
  cout << "Nu = " << Nu << endl;
}