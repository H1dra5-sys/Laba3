/************************
 *Сделал: Коновалов К.М*
 *Работа: Вариант 9   *
 ***********************/
 
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

using namespace std;

struct Applicant {
  string lastName;
  string name;
  int yearOfGraduation;
  int numberOfSchool;
  int mathEntranceExamScore;
  int russianEntranceExamScore;
  int physicsEntranceExamScore;
};

int main() {
	
  int count, arrayIndex, totalPointsForAllExams, theAverageScoreOfTheEntranceExams;
  Applicant characteristicsOfTheApplicant[99];

  cout << "Count" << endl;
  cin >> count;
  
  ifstream fin("File.txt");
  if (fin.is_open() == 0) {
    cout << "Error of Open" << endl;
  } else {
      for (arrayIndex = 0; arrayIndex < count; ++arrayIndex) {	 
        fin >> characteristicsOfTheApplicant[arrayIndex].lastName
            >> characteristicsOfTheApplicant[arrayIndex].name
            >> characteristicsOfTheApplicant[arrayIndex].yearOfGraduation
            >> characteristicsOfTheApplicant[arrayIndex].numberOfSchool
            >> characteristicsOfTheApplicant[arrayIndex].mathEntranceExamScore
            >> characteristicsOfTheApplicant[arrayIndex].russianEntranceExamScore
            >> characteristicsOfTheApplicant[arrayIndex].physicsEntranceExamScore;
          
        cout << characteristicsOfTheApplicant[arrayIndex].lastName << " "
             << characteristicsOfTheApplicant[arrayIndex].name << " "
             << characteristicsOfTheApplicant[arrayIndex].yearOfGraduation << " "
             << characteristicsOfTheApplicant[arrayIndex].numberOfSchool << " "
             << characteristicsOfTheApplicant[arrayIndex].mathEntranceExamScore << " "
             << characteristicsOfTheApplicant[arrayIndex].russianEntranceExamScore << " "
             << characteristicsOfTheApplicant[arrayIndex].physicsEntranceExamScore << endl
             << endl;
      }
         
	  cout << "Choose a school from the ones below \n"
             << "777"  << ", "
             << "228"  << ", "
             << "1337" << ", "
             << "557"  << ", "
             << "42"   << "." << endl;
         
      cin  >> characteristicsOfTheApplicant[4].numberOfSchool;
      if (characteristicsOfTheApplicant[4].numberOfSchool == 777) {
      	totalPointsForAllExams = characteristicsOfTheApplicant[0].mathEntranceExamScore + characteristicsOfTheApplicant[0].russianEntranceExamScore + characteristicsOfTheApplicant[0].physicsEntranceExamScore;
      	theAverageScoreOfTheEntranceExams = totalPointsForAllExams / 3;
        cout << characteristicsOfTheApplicant[0].lastName << " "
             << characteristicsOfTheApplicant[0].name << ", "
             << "Total points for all exams: "
             << totalPointsForAllExams << endl
             << "The average score of the entrance exams: "
             << theAverageScoreOfTheEntranceExams << endl;
      }
      
      if (characteristicsOfTheApplicant[4].numberOfSchool == 228) {
      	totalPointsForAllExams = characteristicsOfTheApplicant[1].mathEntranceExamScore + characteristicsOfTheApplicant[1].russianEntranceExamScore + characteristicsOfTheApplicant[1].physicsEntranceExamScore;
      	theAverageScoreOfTheEntranceExams = totalPointsForAllExams / 3;
        cout << characteristicsOfTheApplicant[1].lastName << " "
             << characteristicsOfTheApplicant[1].name << ", "
             << "Total points for all exams: "
             << totalPointsForAllExams << endl
             << "The average score of the entrance exams: "
             << theAverageScoreOfTheEntranceExams << endl;
      }
      
      if (characteristicsOfTheApplicant[4].numberOfSchool == 1337) {
      	totalPointsForAllExams = characteristicsOfTheApplicant[2].mathEntranceExamScore + characteristicsOfTheApplicant[2].russianEntranceExamScore + characteristicsOfTheApplicant[2].physicsEntranceExamScore;
      	theAverageScoreOfTheEntranceExams = totalPointsForAllExams / 3;
        cout << characteristicsOfTheApplicant[2].lastName << " "
             << characteristicsOfTheApplicant[2].name << ", "
             << "Total points for all exams: "
             << totalPointsForAllExams << endl
             << "The average score of the entrance exams: "
             << theAverageScoreOfTheEntranceExams << endl;
      }
	    
      if (characteristicsOfTheApplicant[4].numberOfSchool == 557) {
      	totalPointsForAllExams = characteristicsOfTheApplicant[3].mathEntranceExamScore + characteristicsOfTheApplicant[3].russianEntranceExamScore + characteristicsOfTheApplicant[3].physicsEntranceExamScore;
      	theAverageScoreOfTheEntranceExams = totalPointsForAllExams / 3;
        cout << characteristicsOfTheApplicant[3].lastName << " "
             << characteristicsOfTheApplicant[3].name << ", "
             << "Total points for all exams: "
             << totalPointsForAllExams << endl
             << "The average score of the entrance exams: "
             << theAverageScoreOfTheEntranceExams << endl;
      }
      
      if (characteristicsOfTheApplicant[4].numberOfSchool == 42) {
      	totalPointsForAllExams = characteristicsOfTheApplicant[4].mathEntranceExamScore + characteristicsOfTheApplicant[4].russianEntranceExamScore + characteristicsOfTheApplicant[4].physicsEntranceExamScore;
      	theAverageScoreOfTheEntranceExams = totalPointsForAllExams / 3;
        cout << characteristicsOfTheApplicant[4].lastName << " "
             << characteristicsOfTheApplicant[4].name << ", "
             << "Total points for all exams: "
             << totalPointsForAllExams << endl
             << "The average score of the entrance exams: "
             << theAverageScoreOfTheEntranceExams << endl;
	  }
      fin.close();
  }
}

