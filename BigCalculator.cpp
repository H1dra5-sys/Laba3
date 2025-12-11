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

  //Ïðîâåðÿåì ÿâëÿåòñÿ ëè õîòü îäíî ÷èñëî íóë¸ì
  firstBigArrayIsZero = (firstBigArray.size() == 1 and firstBigArray[0] == 0);
  secondBigArrayIsZero = (secondBigArray.size() == 1 and secondBigArray[0] == 0);
  if (firstBigArrayIsZero or secondBigArrayIsZero) {
    zeroResult.push_back(0);
    return zeroResult;
  }

  //Ðåçóëüòàò
  resultSize = firstBigArray.size() + secondBigArray.size();

  // Çàïîëíÿåì ðåçóëüòàò íóëÿìè
  for (index = 0; index < resultSize; ++index) {
    multiplicationResult.push_back(0);
  }

  // Óìíîæàåì â ñòîëáèê
  for (firstBigArrayIndex = 0; firstBigArrayIndex < firstBigArray.size(); ++firstBigArrayIndex) {
    carryValue = 0;  // çíà÷åíèå ïåðåíîñà

    for (secondBigArrayIndex = 0; secondBigArrayIndex < secondBigArray.size(); ++secondBigArrayIndex) {
      // Âû÷èñëÿåì ïîçèöèþ â ðåçóëüòèðóþùåì âåêòîðå
      resultPosition = firstBigArrayIndex + secondBigArrayIndex;

      // Óìíîæàåì òåêóùèå öèôðû
      digitProduct = firstBigArray[firstBigArrayIndex] * secondBigArray[secondBigArrayIndex];

      // Ñóììèðóåì ñ óæå èìåþùèìñÿ çíà÷åíèåì è ïåðåíîñîì
      totalSum = digitProduct + multiplicationResult[resultPosition] + carryValue;

      // Îáíîâëÿåì çíà÷åíèå â ðåçóëüòàòå (åäèíèöû)
      multiplicationResult[resultPosition] = totalSum % 10;

      // Îáíîâëÿåì ïåðåíîñ (äåñÿòêè)
      carryValue = totalSum / 10;
    }

    // Åñëè îñòàëñÿ ïåðåíîñ ïîñëå óìíîæåíèÿ íà âñå öèôðû
    if (carryValue > 0) {
      remainingCarryPosition = firstBigArrayIndex + secondBigArray.size();
      multiplicationResult[remainingCarryPosition] = carryValue;
    }
  }

  // Óäàëÿåì íåçíà÷àùèå íóëè â íà÷àëå ÷èñëà
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
    return true;  // ïåðâîå ÷èñëî áîëüøå
  }

  if (secondBigArrayHasMoreDigits) {
    return false; // âòîðîå ÷èñëî áîëüøå
  }

  for (digitPosition = firstBigArrayDigits.size() - 1; digitPosition >= 0; --digitPosition) {
    digitFromfirstBigArray = firstBigArrayDigits[digitPosition];
    digitFromsecondBigArray = secondBigArrayDigits[digitPosition];
        
    if (digitFromfirstBigArray > digitFromsecondBigArray) {
      return true;  // ïåðâîå ÷èñëî áîëüøå
    }

    if (digitFromfirstBigArray < digitFromsecondBigArray) {
      return true; // âòîðîå ÷èñëî áîëüøå
    }
  }

  return false;  // ÷èñëà ðàâíû
}
vector<int> bigDivide(vector<int> firstBigArray, vector<int> secondBigArray) {
	
  int positionIndex, digitIndex, currentDigit, comparisonFlag, quotientDigit, borrowValue, divisorDigit;
  vector<int> quotientResult, currentRemainder;
  bool isRemainderGreater, isDivisionByZero, isDividendSmaller;

   // Ïðîâåðêà äåëåíèÿ íà íîëü
  isDivisionByZero = (secondBigArray.size() == 1 && secondBigArray[0] == 0);
  if (isDivisionByZero) {
    return { 0 };
  }

  // Åñëè äåëèìîå ìåíüøå äåëèòåëÿ
  isDividendSmaller = (firstBigArray.size() < secondBigArray.size());
  if (isDividendSmaller) {
    return { 0 };
  }

  // Îñíîâíîé öèêë äåëåíèÿ
  for (positionIndex = firstBigArray.size() - 1; positionIndex >= 0; --positionIndex) {
    // Äîáàâëÿåì ñëåäóþùóþ öèôðó ê îñòàòêó
    currentRemainder.insert(currentRemainder.begin(), firstBigArray[positionIndex]);

    // Óäàëÿåì âåäóùèå íóëè èç îñòàòêà
  while (currentRemainder.size() > 1 && currentRemainder.back() == 0) {
    currentRemainder.pop_back();
  }

  // Ïîäáèðàåì öèôðó ÷àñòíîãî
  quotientDigit = 0;

  // Ñðàâíèâàåì îñòàòîê ñ äåëèòåëåì
  while (true) {
    // Ïðîâåðÿåì, áîëüøå ëè îñòàòîê äåëèòåëÿ
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

  // Åñëè îñòàòîê ìåíüøå äåëèòåëÿ, âûõîäèì
  if (!isRemainderGreater) {
    break;
  }

  // Óâåëè÷èâàåì öèôðó ÷àñòíîãî
  quotientDigit = quotientDigit + 1;

  // Âû÷èòàåì äåëèòåëü èç îñòàòêà
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

  // Óäàëÿåì âåäóùèå íóëè ïîñëå âû÷èòàíèÿ
  while (currentRemainder.size() > 1 && currentRemainder.back() == 0) {
    currentRemainder.pop_back();
  }
  }

  // Äîáàâëÿåì íàéäåííóþ öèôðó ê ðåçóëüòàòó
  quotientResult.insert(quotientResult.begin(), quotientDigit);
  }

  // Óäàëÿåì âåäóùèå íóëè èç ðåçóëüòàòà
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

