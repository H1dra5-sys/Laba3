/************************
* Сделал: Коновалов К.М.*
* Работа: Змейка        *   
*************************/

#include <iostream>   // Для ввода/вывода
#include <conio.h>    // Для работы с клавиатурой
#include <windows.h>  // Для очистки экрана

using namespace std;

// Константы игрового поля
const int gameWidth = 20, gameHeight = 20;
int tailX[100], tailY[100], playerScore, snakeLength, headX, headY, fruitX, fruitY;
enum Direction { dirStop = 0, dirLeft, dirRight, dirUp, dirDown };
Direction currentDir;

// ==============================
// ФУНКЦИЯ ИНИЦИАЛИЗАЦИИ
// ==============================
void initializeGame() {
  int centerX,centerY, segment;

  // Начальные значения
  centerX = gameWidth / 2;
  centerY = gameHeight / 2;
  currentDir = dirStop;
  headX = centerX;
  headY = centerY;
  fruitX = rand() % gameWidth;
  fruitY = rand() % gameHeight;
  playerScore = 0;
  snakeLength = 4;

  // Инициализация хвоста
  for (segment = 0; segment < snakeLength; segment++) {
    tailX[segment] = headX - segment - 1;
    tailY[segment] = headY;
  }
}

// ==============================
// ФУНКЦИЯ ОТРИСОВКИ
// ==============================
void renderGame() {
  int row, col, tailIndex;
  bool isTail;

  // Очистка экрана и вывод информации
  system("cls");
  cout << "Score: " << playerScore << " | Snake lenght: " << snakeLength << endl;
  cout << "Control: W/A/S/D (Q - Exit)\n" << endl;

  // Верхняя граница поля
  for (row = 0; row < gameWidth + 2; row++) {
    cout << "#";
  }
  cout << endl;

  // Основное игровое поле
  for (row = 0; row < gameHeight; row++) {
    for (col = 0; col < gameWidth; col++) {
      // Левая граница
      if (col == 0) {
        cout << "#";
      }

      // Проверка на сегмент хвоста
      isTail = false;
      for (tailIndex = 0; tailIndex < snakeLength; tailIndex++) {
        if (tailX[tailIndex] == col && tailY[tailIndex] == row) {
          cout << "o";
          isTail = true;
          break;
        }
      }

      // Отрисовка головы, фрукта или пустой клетки
      if (!isTail) {
        if (row == headY && col == headX) {
          cout << "O";
        } else if (row == fruitY && col == fruitX) {
          cout << "@";
        } else {
          cout << " ";
        }
      }

      // Правая граница
      if (col == gameWidth - 1) {
        cout << "#";
      }
    }
    cout << endl;
  }

  // Нижняя граница поля
  for (row = 0; row < gameWidth + 2; row++) {
    cout << "#";
  }
  cout << endl;
}

// ==============================
// ОБРАБОТКА ВВОДА
// ==============================
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

// ==============================
// ИГРОВАЯ ЛОГИКА
// ==============================
void updateGame() {
  int prevX, prevY;
  int tempX, tempY, segment;

  // Перемещение первого сегмента хвоста на место головы
  prevX = tailX[0];
  prevY = tailY[0];
  tailX[0] = headX;
  tailY[0] = headY;

  // Обновление позиций остальных сегментов хвоста
  for (segment = 1; segment < snakeLength; segment++) {
    tempX = tailX[segment];
    tempY = tailY[segment];
    tailX[segment] = prevX;
    tailY[segment] = prevY;
    prevX = tempX;
    prevY = tempY;
  }

  // Движение головы змейки
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

  // Телепортация через границы поля
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

  // Проверка столкновения головы с хвостом
  for (segment = 0; segment < snakeLength; segment++) {
    if (tailX[segment] == headX && tailY[segment] == headY) {
      cout << "\nGame over! Score: " << playerScore << endl;
      exit(0);
    }
  }

  // Сбор фрукта
  if (headX == fruitX && headY == fruitY) {
    playerScore += 10;
    fruitX = rand() % gameWidth;
    fruitY = rand() % gameHeight;
    snakeLength++;
  }
}

// ==============================
// ГЛАВНАЯ ФУНКЦИЯ
// ==============================
int main() {
  initializeGame();

  while (true) {
    renderGame();
    processInput();
    updateGame();
  }

  return 0;
}
