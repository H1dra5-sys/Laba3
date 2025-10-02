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
  cout << "d =";
  cin >> d; 
  cout << "a =";
  cin >> a;
  
  for(double W = 10.0; W < 20.0; W += 10.0) {
    Pe = W * d / a;
    if (Pe > pow1) {
      Nu = 3.4 + 0.014 * pow(Pe, 0.8);
    }
        else {
          Nu = 5.0 + 0.021 * Pe;
        }
        
  cout << "first" << endl
       << "Nu = " << Nu << endl
       << "Pe = " << Pe << endl;
  }

  for(double W = 20.0; W < 50.0; W += 30.0) {
    Pe = W * d / a;
    if (Pe > pow1) {
      Nu = 3.4 + 0.014 * pow(Pe, 0.8);
    }
        else {
          Nu = 5.0 + 0.021 * Pe;
        }
  }
  
  for(double W = 50.0; W < 100.0; W += 50.0) {
    Pe = W * d / a;
    if (Pe > pow1) {
      Nu = 3.4 + 0.014 * pow(Pe, 0.8);
    }
        else {
          Nu = 5.0 + 0.021 * Pe;
        }
  }
  
  for(double W = 100.0; W < 200.0; W += 100.0) {
    Pe = W * d / a;
    if (Pe > pow1) {
      Nu = 3.4 + 0.014 * pow(Pe, 0.8);
    }
        else {
          Nu = 5.0 + 0.021 * Pe;
        }
  }
  
  for(double W = 200.0; W < 800.0; W += 300.0) {
    Pe = W * d / a;
    if (Pe > pow1) {
      Nu = 3.4 + 0.014 * pow(Pe, 0.8);
    }
        else {
          Nu = 5.0 + 0.021 * Pe;
        }
  }

  cout << "last"  << endl
       << "Nu = " << Nu << endl
       << "Pe = " << Pe << endl;
}

  