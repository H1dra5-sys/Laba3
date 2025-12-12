/************************
* Сделал: Коновалов К.М.*
* Работа: Змейка        *   
*************************/

#include <iostream>   
#include <conio.h>    // Äëÿ ðàáîòû ñ êëàâèàòóðîé
#include <windows.h>  

using namespace std;


const int gameWidth = 20, gameHeight = 20;
int tailX[100], tailY[100], playerScore, snakeLength, headX, headY, fruitX, fruitY;
enum Direction { dirStop = 0, dirLeft, dirRight, dirUp, dirDown };
Direction currentDir;

void initializeGame() {
  int centerX,centerY, segment;

  centerX = gameWidth / 2;
  centerY = gameHeight / 2;
  currentDir = dirStop;
  headX = centerX;
  headY = centerY;
  fruitX = rand() % gameWidth;
  fruitY = rand() % gameHeight;
  playerScore = 0;
  snakeLength = 4;

  for (segment = 0; segment < snakeLength; segment++) {
    tailX[segment] = headX - segment - 1;
    tailY[segment] = headY;
  }
}

void renderGame() {
  int row, col, tailIndex;
  bool isTail;

  system("cls");
  cout << "Score: " << playerScore << " | Snake lenght: " << snakeLength << endl;
  cout << "Control: W/A/S/D (Q - Exit)\n" << endl;

  for (row = 0; row < gameWidth + 2; row++) {
    cout << "#";
  }
  cout << endl;

  for (row = 0; row < gameHeight; row++) {
    for (col = 0; col < gameWidth; col++) {
      // Ëåâàÿ ãðàíèöà
      if (col == 0) {
        cout << "#";
      }

      isTail = false;
      for (tailIndex = 0; tailIndex < snakeLength; tailIndex++) {
        if (tailX[tailIndex] == col && tailY[tailIndex] == row) {
          cout << "o";
          isTail = true;
          break;
        }
      }

      if (!isTail) {
        if (row == headY && col == headX) {
          cout << "O";
        } else if (row == fruitY && col == fruitX) {
          cout << "@";
        } else {
          cout << " ";
        }
      }

      if (col == gameWidth - 1) {
        cout << "#";
      }
    }
    cout << endl;
  }

  for (row = 0; row < gameWidth + 2; row++) {
    cout << "#";
  }
  cout << endl;
}

void processInput() {
  char key = _getch();

  switch (key) {
    case 'a': 
      if (currentDir != dirRight) {
        currentDir = dirLeft;
      }
      break;
    case 'd': 
      if (currentDir != dirLeft) {
        currentDir = dirRight;
      }
      break;
    case 'w': 
      if (currentDir != dirDown) {
        currentDir = dirUp;
      }
      break;
    case 's': 
      if (currentDir != dirUp) {
        currentDir = dirDown;
      }
      break;
    case 'q': 
      exit(0); 
      break;
  }
}

void updateGame() {
  int prevX, prevY;
  int tempX, tempY, segment;

  prevX = tailX[0];
  prevY = tailY[0];
  tailX[0] = headX;
  tailY[0] = headY;

  for (segment = 1; segment < snakeLength; segment++) {
    tempX = tailX[segment];
    tempY = tailY[segment];
    tailX[segment] = prevX;
    tailY[segment] = prevY;
    prevX = tempX;
    prevY = tempY;
  }

  switch (currentDir) {
    case dirLeft:  
      headX--; 
      break;
    case dirRight: 
      headX++; 
      break;
    case dirUp:    
      headY--; 
      break;
    case dirDown:  
      headY++; 
      break;
  }

  if (headX >= gameWidth) {
    headX = 0;
  } else if (headX < 0) {
    headX = gameWidth - 1;
  }
  if (headY >= gameHeight) {
    headY = 0;
  } else if (headY < 0) {
    headY = gameHeight - 1;
  }

  for (segment = 0; segment < snakeLength; segment++) {
    if (tailX[segment] == headX && tailY[segment] == headY) {
      cout << "\nGame over! Score: " << playerScore << endl;
      exit(0);
    }
  }

  if (headX == fruitX && headY == fruitY) {
    playerScore += 10;
    fruitX = rand() % gameWidth;
    fruitY = rand() % gameHeight;
    snakeLength++;
  }
}

int main() {
  initializeGame();

  while (true) {
    renderGame();
    processInput();
    updateGame();
  }

  return 0;
}

