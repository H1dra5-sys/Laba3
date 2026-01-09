/***********************************
* Сделал: Коновалов К.М.           *
* Работа: Арифметика длинных чисел *
***********************************/

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
  int  theDigitInTheFirstHugeNumber, theNumberInYourMind, digitOfTheNumber, theDigitInTheSecondHugeNumber, theSumOfLargeNumbers, count;
  char zeroAscii;
  
  zeroAscii = '0';
  digitOfTheNumber = 0;

  for (count = firstHugeNumber.size() - 1; count >= 0; --count) {
    firstBigArray.push_back(firstHugeNumber[count] -  zeroAscii);
  }

  for (count = secondHugeNumber.size() - 1; count >= 0; --count) {
    secondBigArray.push_back(secondHugeNumber[count] -  zeroAscii);
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
  int borrowedAmount, digitPosition, digitToSubtract, currentDigitValue, digitDifference;

  borrowedAmount = 0;
  
  //Если во втором числе есть цифра на данной позиции - берём её
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
  
    while (differenceResult.size() > 1 and differenceResult.back() == 0) {
      differenceResult.pop_back();
    }
  return differenceResult;
}
vector<int> bigMultiply(vector<int> firstBigArray, vector<int> secondBigArray) {

  bool firstBigArrayIsZero, secondBigArrayIsZero;
  vector<int> zeroResult, multiplicationResult;
  int resultSize, index, firstBigArrayIndex, carryValue, secondBigArrayIndex, resultPosition, digitProduct, totalSum, remainingCarryPosition;

  firstBigArrayIsZero = (firstBigArray.size() == 1 and firstBigArray[0] == 0);
  secondBigArrayIsZero = (secondBigArray.size() == 1 and secondBigArray[0] == 0);
  if (firstBigArrayIsZero or secondBigArrayIsZero) {
    zeroResult.push_back(0);
    return zeroResult;
  }

  resultSize = firstBigArray.size() + secondBigArray.size();

  for (index = 0; index < resultSize; ++index) {
    multiplicationResult.push_back(0);
  }

  for (firstBigArrayIndex = 0; firstBigArrayIndex < firstBigArray.size(); ++firstBigArrayIndex) {
    carryValue = 0;  
    
    for (secondBigArrayIndex = 0; secondBigArrayIndex < secondBigArray.size(); ++secondBigArrayIndex) {
      resultPosition = firstBigArrayIndex + secondBigArrayIndex;

      digitProduct = firstBigArray[firstBigArrayIndex] * secondBigArray[secondBigArrayIndex];

      totalSum = digitProduct + multiplicationResult[resultPosition] + carryValue;

      multiplicationResult[resultPosition] = totalSum % 10;

      carryValue = totalSum / 10;
    }

    if (carryValue > 0) {
      remainingCarryPosition = firstBigArrayIndex + secondBigArray.size();
      multiplicationResult[remainingCarryPosition] = carryValue;
    }
  }

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
    return true; 
  }

  if (secondBigArrayHasMoreDigits) {
    return false;
  }

  for (digitPosition = firstBigArrayDigits.size() - 1; digitPosition >= 0; --digitPosition) {
    digitFromfirstBigArray = firstBigArrayDigits[digitPosition];
    digitFromsecondBigArray = secondBigArrayDigits[digitPosition];

    if (digitFromfirstBigArray > digitFromsecondBigArray) {
      return true; 
    }

    if (digitFromfirstBigArray < digitFromsecondBigArray) {
      return true; 
    }
  }

  return false;
}
vector<int> bigDivide(vector<int> firstBigArray, vector<int> secondBigArray) {

  int positionIndex, digitIndex, currentDigit, comparisonFlag, quotientDigit, borrowValue, divisorDigit;
  vector<int> quotientResult, currentRemainder;
  bool isRemainderGreater, isDivisionByZero, isDividendSmaller;

  isDivisionByZero = (secondBigArray.size() == 1 && secondBigArray[0] == 0);
  if (isDivisionByZero) {
    return { 0 };
  }

  isDividendSmaller = (firstBigArray.size() < secondBigArray.size());
  if (isDividendSmaller) {
    return { 0 };
  }

  for (positionIndex = firstBigArray.size() - 1; positionIndex >= 0; --positionIndex) {
    currentRemainder.insert(currentRemainder.begin(), firstBigArray[positionIndex]);

  while (currentRemainder.size() > 1 && currentRemainder.back() == 0) {
    currentRemainder.pop_back();
  }

  quotientDigit = 0;

  while (true) {
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

  if (!isRemainderGreater) {
    break;
  }

  quotientDigit = quotientDigit + 1;

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

  while (currentRemainder.size() > 1 && currentRemainder.back() == 0) {
    currentRemainder.pop_back();
  }
  }

  quotientResult.insert(quotientResult.begin(), quotientDigit);
  }

  while (quotientResult.size() > 1 && quotientResult.back() == 0) {
    quotientResult.pop_back();
  }

  return quotientResult;
}

int main() {
    
  string firstBigString, secondBigString, usersChoice;
  vector<int> firstBigArray, secondBigArray, resultDivide, resulMultiply, resultSum, resultSubstraction;
  bool comparison;
  int count;
  
  cout <<"Enter your first number: ";
  cin >> firstBigString;
  cout << endl;
  cout <<"Enter your second number: ";
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
            cout << "Second array <= First array";
		  }     
      }
}



