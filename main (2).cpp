 /******************************
* Сделал: Коновалов Константин *
* Работа: Вариант N9           *
*******************************/

#include <iostream>
#include <cmath>

using namespace std;
int main() {

  double a, W, pow1, Pe, Nu, d;
  int iteration;

  pow1 = 3.0 * pow(10.0, 3.0);
  cout << "d = ";
  cin >> d; 
  cout << "a = ";
  cin >> a;

  for (iteration = 0; iteration < 6; iteration += 1) {
    cout << "W =";
    cin >> W;
    Pe = W * d / a;
    if (Pe > pow1) {
      Nu = 3.4 + 0.014 * pow(Pe, 0.8);
    } else {
      Nu = 5.0 + 0.021 * Pe;
    }

     cout << "Nu = " << Nu << endl
         << "Pe = " << Pe << endl;
  }
}