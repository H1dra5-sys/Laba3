/***********************
* Автор: Коновалов К.М.*
* Работа: Календарь    *
************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> bigSum(vector <int> firstBigArray, vector <int> secondBigArray) {

  vector<int> theSumOfTheArrays;
  string firstHugeNumber, secondHugeNumber;
  int  theDigitInTheFirstHugeNumber, theNumberInYourMind, digitOfTheNumber, theDigitInTheSecondHugeNumber, theSumOfLargeNumbers;
  int count;

  digitOfTheNumber = 0;

  for (count = firstHugeNumber.size() - 1; count >= 0; --count) {
    firstBigArray.push_back(firstHugeNumber[count] - '0');
  }

  for (count = secondHugeNumber.size() - 1; count >= 0; --count) {
    secondBigArray.push_back(secondHugeNumber[count] - '0');
  }

  theNumberInYourMind = 0;

  while (digitOfTheNumber < firstBigArray.size() or digitOfTheNumber < secondBigArray.size() or theNumberInYourMind > 0) {
    if (digitOfTheNumber < firstBigArray.size()) {
      theDigitInTheFirstHugeNumber = firstBigArray[digitOfTheNumber];
    } else {
        theDigitInTheFirstHugeNumber = 0;
      }

    if (digitOfTheNumber < secondBigArray.size()) {
      theDigitInTheSecondHugeNumber = secondBigArray[digitOfTheNumber];
    } else {
        theDigitInTheSecondHugeNumber = 0;
      }

    theSumOfLargeNumbers = theDigitInTheFirstHugeNumber + theDigitInTheSecondHugeNumber + theNumberInYourMind;
    theSumOfTheArrays.push_back(theSumOfLargeNumbers % 10);
    theNumberInYourMind = theSumOfLargeNumbers / 10;
    ++digitOfTheNumber;
  }
  return theSumOfTheArrays;
};
vector <int> bigSubtraction(vector <int> firstBigArray, vector <int> secondBigArray) {
	
  vector<int> differenceResult;  
  int borrowedAmount,digitPosition, digitToSubtract, currentDigitValue, digitDifference;

  borrowedAmount = 0;

  for (digitPosition = 0; digitPosition < firstBigArray.size(); ++digitPosition) {
    currentDigitValue = firstBigArray[digitPosition] - borrowedAmount;
    digitToSubtract = (digitPosition < secondBigArray.size()) ? secondBigArray[digitPosition] : 0;

    if (currentDigitValue < digitToSubtract) {
      currentDigitValue += 10;
      borrowedAmount = 1;
    } else {
      borrowedAmount = 0;
      }
    digitDifference = currentDigitValue - digitToSubtract;
    differenceResult.push_back(digitDifference);
    }
    while (differenceResult.size() > 1 && differenceResult.back() == 0) {
      differenceResult.pop_back();
    }
  return differenceResult;
}
vector<int> bigMultiply(vector<int> firstBigArray, vector<int> secondBigArray) {

  bool firstBigArrayIsZero, secondBigArrayIsZero;
  vector<int> zeroResult, multiplicationResult;
  int resultSize, index, firstBigArrayIndex, carryValue, secondBigArrayIndex, resultPosition, digitProduct, totalSum, remainingCarryPosition;

  //Проверяем является ли хоть одно число нулём
  firstBigArrayIsZero = (firstBigArray.size() == 1 and firstBigArray[0] == 0);
  secondBigArrayIsZero = (secondBigArray.size() == 1 and secondBigArray[0] == 0);
  if (firstBigArrayIsZero or secondBigArrayIsZero) {
    zeroResult.push_back(0);
    return zeroResult;
  }

  //Результат
  resultSize = firstBigArray.size() + secondBigArray.size();

  // Заполняем результат нулями
  for (index = 0; index < resultSize; ++index) {
    multiplicationResult.push_back(0);
  }

  // Умножаем в столбик
  for (firstBigArrayIndex = 0; firstBigArrayIndex < firstBigArray.size(); ++firstBigArrayIndex) {
    carryValue = 0;  // значение переноса

    for (secondBigArrayIndex = 0; secondBigArrayIndex < secondBigArray.size(); ++secondBigArrayIndex) {
      // Вычисляем позицию в результирующем векторе
      resultPosition = firstBigArrayIndex + secondBigArrayIndex;

      // Умножаем текущие цифры
      digitProduct = firstBigArray[firstBigArrayIndex] * secondBigArray[secondBigArrayIndex];

      // Суммируем с уже имеющимся значением и переносом
      totalSum = digitProduct + multiplicationResult[resultPosition] + carryValue;

      // Обновляем значение в результате (единицы)
      multiplicationResult[resultPosition] = totalSum % 10;

      // Обновляем перенос (десятки)
      carryValue = totalSum / 10;
    }

    // Если остался перенос после умножения на все цифры
    if (carryValue > 0) {
      remainingCarryPosition = firstBigArrayIndex + secondBigArray.size();
      multiplicationResult[remainingCarryPosition] = carryValue;
    }
  }

  // Удаляем незначащие нули в начале числа
  while (multiplicationResult.size() > 1 and multiplicationResult.back() == 0) {
    multiplicationResult.pop_back();
  }

  return multiplicationResult;
}
bool bigComparison(vector<int> firstBigArrayDigits, vector<int> secondBigArrayDigits) {

  bool firstBigArrayHasMoreDigits, secondBigArrayHasMoreDigits;
  int digitPosition, digitFromfirstBigArray, digitFromsecondBigArray;

  firstBigArrayHasMoreDigits = (firstBigArrayDigits.size() > secondBigArrayDigits.size());
  secondBigArrayHasMoreDigits = (firstBigArrayDigits.size() < secondBigArrayDigits.size());

  if (firstBigArrayHasMoreDigits) {
    return true;  // первое число больше
  }

  if (secondBigArrayHasMoreDigits) {
    return false; // второе число больше
  }

  for (digitPosition = firstBigArrayDigits.size() - 1; digitPosition >= 0; --digitPosition) {
    digitFromfirstBigArray = firstBigArrayDigits[digitPosition];
    digitFromsecondBigArray = secondBigArrayDigits[digitPosition];
        
    if (digitFromfirstBigArray > digitFromsecondBigArray) {
      return true;  // первое число больше
    }

    if (digitFromfirstBigArray < digitFromsecondBigArray) {
      return true; // второе число больше
    }
  }

  return false;  // числа равны
}
vector<int> bigDivide(vector<int> firstBigArray, vector<int> secondBigArray) {
	
  int positionIndex, digitIndex, currentDigit, comparisonFlag, quotientDigit, borrowValue, divisorDigit;
  vector<int> quotientResult, currentRemainder;
  bool isRemainderGreater, isDivisionByZero, isDividendSmaller;

   // Проверка деления на ноль
  isDivisionByZero = (secondBigArray.size() == 1 && secondBigArray[0] == 0);
  if (isDivisionByZero) {
    return { 0 };
  }

  // Если делимое меньше делителя
  isDividendSmaller = (firstBigArray.size() < secondBigArray.size());
  if (isDividendSmaller) {
    return { 0 };
  }

  // Основной цикл деления
  for (positionIndex = firstBigArray.size() - 1; positionIndex >= 0; --positionIndex) {
    // Добавляем следующую цифру к остатку
    currentRemainder.insert(currentRemainder.begin(), firstBigArray[positionIndex]);

    // Удаляем ведущие нули из остатка
  while (currentRemainder.size() > 1 && currentRemainder.back() == 0) {
    currentRemainder.pop_back();
  }

  // Подбираем цифру частного
  quotientDigit = 0;

  // Сравниваем остаток с делителем
  while (true) {
    // Проверяем, больше ли остаток делителя
     isRemainderGreater = false;

  if (currentRemainder.size() > secondBigArray.size()) {
    isRemainderGreater = true;
  
  } else if (currentRemainder.size() == secondBigArray.size()) {
      for (digitIndex = currentRemainder.size() - 1; digitIndex >= 0; --digitIndex) {
        if (currentRemainder[digitIndex] > secondBigArray[digitIndex]) {
          isRemainderGreater = true;
            break;
        }
        if (currentRemainder[digitIndex] < secondBigArray[digitIndex]) {
          break;
        }
      }
    }

  // Если остаток меньше делителя, выходим
  if (!isRemainderGreater) {
    break;
  }

  // Увеличиваем цифру частного
  quotientDigit = quotientDigit + 1;

  // Вычитаем делитель из остатка
  borrowValue = 0;
  for (digitIndex = 0; digitIndex < currentRemainder.size(); ++digitIndex) {
    currentDigit = currentRemainder[digitIndex] - borrowValue;
    divisorDigit = (digitIndex < secondBigArray.size()) ? secondBigArray[digitIndex] : 0;

  if (currentDigit < divisorDigit) {
    currentDigit = currentDigit + 10;
    borrowValue = 1;
  } else {
      borrowValue = 0;
    }

  currentRemainder[digitIndex] = currentDigit - divisorDigit;
  }

  // Удаляем ведущие нули после вычитания
  while (currentRemainder.size() > 1 && currentRemainder.back() == 0) {
    currentRemainder.pop_back();
  }
  }

  // Добавляем найденную цифру к результату
  quotientResult.insert(quotientResult.begin(), quotientDigit);
  }

  // Удаляем ведущие нули из результата
  while (quotientResult.size() > 1 && quotientResult.back() == 0) {
    quotientResult.pop_back();
  }

  return quotientResult;
}

int main() {
  string firstBigString, secondBigString;
  vector<int> firstBigArray, secondBigArray, resultDivide, resulMultiply, resultSum, resultSubstraction;
  bool comparison;
  int count;
  string usersChoice;
  
  cin >> firstBigString;
  cout << endl;
  cin >> secondBigString;
  cout << endl;
  cout << "Enter the operation you want to perform: Sum or Sub or Mul or Div or Comp: ";
  cin >> usersChoice;

  for (int count = (int)firstBigString.size() - 1; count >= 0; --count) {
    firstBigArray.push_back(firstBigString[count] - '0');
  }

  for (int count = (int)secondBigString.size() - 1; count >= 0; --count) {
    secondBigArray.push_back(secondBigString[count] - '0');
  }
  resultDivide = bigDivide(firstBigArray, secondBigArray);
  resulMultiply = bigMultiply(firstBigArray, secondBigArray);
  resultSum = bigSum(firstBigArray, secondBigArray);
  resultSubstraction = bigSubtraction(firstBigArray, secondBigArray);
  comparison = bigComparison(firstBigArray, secondBigArray);
   
  if (usersChoice == "Sum") {  
    for (count = (int)resultSum.size() - 1; count >= 0; --count) {
      cout << resultSum[count];
    }
    
  } else if (usersChoice == "Sub") {
  	  for (count = (int)resultSubstraction.size() - 1; count >= 0; --count) {
        cout << resultSubstraction[count];
      }
     
    
  } else if (usersChoice == "Mul") {
  	  for (count = (int)resulMultiply.size() - 1; count >= 0; --count) {
        cout << resulMultiply[count];
      }
  
  } else if (usersChoice == "Div") {
  	  for (count = (int) resultDivide.size() - 1; count >= 0; --count) {
        cout <<  resultDivide[count];
      }

	} else if (usersChoice == "Comp") {
        if (comparison == 0) {
          cout << "Second array >= First array";
        } else if (comparison == 1) {
            cout << "Second array < First array";
		  }     
      }
}
