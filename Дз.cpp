/**********************
 * Имя:Коновалов К.М. *
 * Название:Вариант 9 *
 **********************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
  float u, P, R0, R1, R2, a, degree1, degree2, Pi, Q1, Q2, Q3, l, ln, preln, sqr;
  
  degree1 = pow(10, -4);
  degree2 = pow(10, 4);
  
  u = 2.4 * degree1; 
  P = 0.721 * degree2;
  l = 154;
  
  R0 = 8.16;
  R1 = 8.16;
  a = 0.816;
  R2 = 2.64;
  
  Pi = 3.14;
  
  Q1 = 0;
  Q2 = 0 ;
  Q3 = 0;
  
  preln = R2 / R1;
  ln = log(preln);
  
  sqr = sqrt(3);
  
  Q1 = (Pi * (R0 * R0 * R0 * R0) / 8) * (P / (u * l) );
  cout << "Q1 = " << Q1 << endl;
  
  Q2 = ( ( Pi / 8) * ( P / (u * l) ) ) * ( ( (R1 * R1 - R2 * R2 ) * (R1 * R1 - R2 * R2 ) / ln) + (R1 * R1 * R1 * R1 - R2 * R2 * R2 * R2) );
  cout << "Q2 = " << Q2 << endl;

  
  Q3 = (a * a * a * a * sqr / 320) * (P / (u * l));
  cout << "Q3 = " << Q3 << endl;
}