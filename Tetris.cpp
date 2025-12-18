#include <unordered_map>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

mutex mlock;
int score, lines, ticks, FIELD_HEIGHT, FIELD_WIDTH, figureX, figureY, figureMaxX, figureMinX, currentFigure, nextFigure;
char FIGURE_GLYPH_A, FIGURE_GLYPH_B;
bool block;
vector<int> fieldColors, fieldColorsClear;
vector<string> field, fieldClear, colors;
string clearLine, fullLine, lowerBorder;

string getFigure(int figureIndex) {
  unordered_map<int, string> figures;
  figures[0] = ".....@@..@@.....";
  figures[1] = "....@@@@........";
  figures[2] = "..@...@...@...@.";
  figures[3] = "......@@.@@.....";
  figures[4] = "..@...@@...@....";
  figures[5] = ".....@@...@@....";
  figures[6] = "...@..@@..@.....";
  figures[7] = ".....@@@.@......";
  figures[8] = "..@...@...@@....";
  figures[9] = "...@.@@@........";
  figures[10] = ".@@...@...@.....";
  figures[11] = ".....@@@...@....";
  figures[12] = "..@@..@...@.....";
  figures[13] = ".@...@@@........";
  figures[14] = "..@...@..@@.....";
  figures[15] = ".....@@@..@.....";
  figures[16] = "..@...@@..@.....";
  figures[17] = "..@..@@@........";
  figures[18] = "..@..@@...@.....";
  return figures[figureIndex];
}

void coutField() {
  string screen, nextFigurePattern;
  int xPos, yPos;

  FIGURE_GLYPH_A = '(';
  FIGURE_GLYPH_B = ')';
  FIELD_HEIGHT = 20 + 1;
  FIELD_WIDTH = 15;
  screen = "";
  nextFigurePattern = getFigure(nextFigure);

  for (yPos = 1; yPos < FIELD_HEIGHT; ++yPos) {
    screen += "\033[0;49m|";
    for (xPos = 0; xPos < FIELD_WIDTH; ++xPos) {
      screen += colors[fieldColors[yPos * FIELD_WIDTH + xPos]] + field[yPos][xPos];

      if (xPos == FIELD_WIDTH - 1 && FIGURE_GLYPH_B == ' ') {
        break;
      }

      if (field[yPos][xPos] == ' ') {
        screen += ' ';
      }
      else {
        screen += FIGURE_GLYPH_B;
      }
    }
    screen += "\033[0;49m|";

    if (yPos == 1) {
      screen += "Next figure: ";
    }

    if (yPos > 1 && yPos < 5) {
      screen += "   ";
      for (xPos = 0; xPos < 4; ++xPos) {
        if (nextFigurePattern[(yPos - 2) * 4 + xPos] == '.') {
          screen += "\033[0;49m  ";
        }
        else {
          screen += colors[0] + FIGURE_GLYPH_A + FIGURE_GLYPH_B;
        }
      }
    }

    if (yPos == 19) {
      screen += " Line: " + to_string(lines);
    }

    if (yPos == 20) {
      screen += " Score: " + to_string(score);
    }

    screen += "\r\n";
  }

  screen += lowerBorder;
  cout << screen;
}

void setFigure() {
  int yPos, xPos, fieldIndex;

  FIGURE_GLYPH_A = '(';
  FIELD_HEIGHT = 20 + 1;
  FIELD_WIDTH = 15;

  for (yPos = 0; yPos < FIELD_HEIGHT; ++yPos) {
    field[yPos] = fieldClear[yPos];
  }

  for (fieldIndex = 0; fieldIndex < FIELD_HEIGHT * FIELD_WIDTH; ++fieldIndex) {
    fieldColors[fieldIndex] = fieldColorsClear[fieldIndex];
  }

  for (yPos = 0; yPos < 4; ++yPos) {
    for (xPos = 0; xPos < 4; ++xPos) {
      if (getFigure(currentFigure)[xPos + yPos * 4] == '@') {
        field[figureY + yPos][figureX + xPos] = FIGURE_GLYPH_A;
        fieldColors[(figureY + yPos) * FIELD_WIDTH + figureX + xPos] = 0;
      }
    }
  }
}

void setMaxXY() {
  FIELD_WIDTH = 15;
  if (currentFigure == 0 || currentFigure == 2 || currentFigure == 10 ||
    currentFigure == 14 || currentFigure == 18) {
    figureMaxX = FIELD_WIDTH - 3;
  }
  else {
    figureMaxX = FIELD_WIDTH - 4;
  }

  if (currentFigure == 2 || currentFigure == 4 || currentFigure == 6 ||
    currentFigure == 8 || currentFigure == 12 || currentFigure == 16) {
    figureMinX = -2;
  }
  else if (currentFigure == 1) {
    figureMinX = 0;
  }
  else {
    figureMinX = -1;
  }

  if (figureX < figureMinX) {
    figureX = figureMinX;
  }

  if (figureX > figureMaxX) {
    figureX = figureMaxX;
  }
}

void rotate() {
  int savedFigure, savedFigureX, savedFigureY, yPos, xPos, rotations[19] = { 0, 2, 1, 4, 3, 6, 5, 10, 7, 8, 9, 14, 11, 12, 13, 18, 15, 16, 17 };

  FIGURE_GLYPH_A = '(';
  FIELD_HEIGHT = 20 + 1;
  savedFigure = currentFigure;
  savedFigureX = figureX;
  savedFigureY = figureY;

  currentFigure = rotations[currentFigure];

  setMaxXY();
  for (yPos = 0; yPos < 4; ++yPos) {
    for (xPos = 0; xPos < 4; ++xPos) {
      if (getFigure(currentFigure)[xPos + yPos * 4] == '@' &&
        (figureY + yPos > FIELD_HEIGHT - 1 ||
          fieldClear[figureY + yPos][figureX + xPos] == FIGURE_GLYPH_A)) {
        currentFigure = savedFigure;
        figureX = savedFigureX;
        figureY = savedFigureY;
        setMaxXY();
        return;
      }
    }
  }
}

void move(int direction) {
  int yPos, xPos;

  FIGURE_GLYPH_A = '(';

  if (figureX + direction < figureMinX || figureX + direction > figureMaxX) {
    return;
  }

  for (yPos = 0; yPos < 4; ++yPos) {
    for (xPos = 0; xPos < 4; ++xPos) {
      if (getFigure(currentFigure)[xPos + yPos * 4] == '@' &&
        (fieldClear[figureY + yPos][figureX + xPos + direction] == FIGURE_GLYPH_A)) {
        return;
      }
    }
  }

  figureX += direction;
}

void checkCollision() {
  int figureIDs[7] = { 0, 1, 3, 5, 7, 11, 15 }, yPos, xPos;
  bool hasCollision;

  FIELD_HEIGHT = 20 + 1;
  FIGURE_GLYPH_A = '(';
  FIELD_WIDTH = 15;
  hasCollision = false;

  for (yPos = 0; yPos < 4; ++yPos) {
    for (xPos = 0; xPos < 4; ++xPos) {
      if (getFigure(currentFigure)[xPos + yPos * 4] == '@' &&
        (figureY + yPos == FIELD_HEIGHT - 1 ||
          fieldClear[figureY + yPos + 1][figureX + xPos] == FIGURE_GLYPH_A)) {
        hasCollision = true;
        break;
      }
    }
    if (hasCollision) {
      break;
    }
  }

  if (!hasCollision) {
    return;
  }

  for (yPos = 0; yPos < 4; ++yPos) {
    for (xPos = 0; xPos < 4; ++xPos) {
      if (getFigure(currentFigure)[xPos + yPos * 4] == '@') {
        if (fieldClear[figureY + yPos][figureX + xPos] == FIGURE_GLYPH_A) {
          system("cls");
          coutField();
          cout << "  Game Over\r\n";
          exit(0);
        }

        fieldClear[figureY + yPos][figureX + xPos] = FIGURE_GLYPH_A;
        field[figureY + yPos][figureX + xPos] = FIGURE_GLYPH_A;
        fieldColorsClear[(figureY + yPos) * FIELD_WIDTH + figureX + xPos] = 0;
      }
    }
  }

  figureX = FIELD_WIDTH / 2 - 2;
  figureY = 0;

  currentFigure = nextFigure;

  nextFigure = rand() % 7;
  nextFigure = figureIDs[nextFigure];
}

void checkLines() {
  int yPos, xPos, lineAbove;

  FIELD_HEIGHT = 20 + 1;
  FIELD_WIDTH = 15;
  for (yPos = FIELD_HEIGHT - 1; yPos > 0; --yPos) {
    if (fieldClear[yPos] == fullLine) {
      score += 10;
      ++lines;
      fieldClear[yPos] = clearLine;

      for (lineAbove = yPos - 1; lineAbove > 0; --lineAbove) {
        for (xPos = 0; xPos < FIELD_WIDTH; ++xPos) {
          fieldColorsClear[(lineAbove + 1) * FIELD_WIDTH + xPos] =
            fieldColorsClear[lineAbove * FIELD_WIDTH + xPos];
        }
        fieldClear[lineAbove + 1] = fieldClear[lineAbove];
      }
      break;
    }
  }
}

void updateBoard() {
  system("cls");
  setMaxXY();
  checkLines();
  setFigure();
  coutField();
  cout << "\r\n";
}

void yIncrease() {
  while (true) {
    Sleep(750 - 25 * lines);
    mlock.lock();

    checkCollision();
    ++figureY;
    ++ticks;
    if (ticks % 10 == 0) {
      ++score;
    }

    updateBoard();
    mlock.unlock();
  }
}

void gameLoop() {
  int userInput;

  while (true) {
    if (_kbhit()) {
      userInput = _getch();
      mlock.lock();

      if (userInput == 27) {
        exit(0);
      }

      if (userInput == 115 || userInput == 83) {
        checkCollision();
        ++figureY;
        ++ticks;
        if (ticks % 10 == 0) {
          ++score;
        }
      }

      if (userInput == 97 || userInput == 65) {
        move(-1);
      }

      if (userInput == 100 || userInput == 68) {
        move(1);
      }

      if (userInput == 32) {
        rotate();
      }

      updateBoard();
      mlock.unlock();
    }
  }
}

void initGame() {
  int xPos, yPos, fieldIndex;

  FIELD_HEIGHT = 20 + 1;
  FIGURE_GLYPH_A = '(';
  FIGURE_GLYPH_B = ')';
  FIELD_WIDTH = 15;
  score = 0;
  lines = 0;
  ticks = 0;

  figureX = FIELD_WIDTH / 2 - 2;
  figureY = 0;

  figureMaxX = 22;
  figureMinX = -2;

  currentFigure = 15;
  nextFigure = 1;

  clearLine = "";
  fullLine = "";
  lowerBorder = " ";

  colors.clear();
  colors.push_back("\033[0m");

  block = false;

  // Инициализация векторов
  fieldColors.resize(FIELD_HEIGHT * FIELD_WIDTH);
  fieldColorsClear.resize(FIELD_HEIGHT * FIELD_WIDTH);
  field.resize(FIELD_HEIGHT);
  fieldClear.resize(FIELD_HEIGHT);

  for (xPos = 0; xPos < FIELD_WIDTH; ++xPos) {
    clearLine += ' ';
    fullLine += FIGURE_GLYPH_A;

    if (xPos == FIELD_WIDTH - 1 && FIGURE_GLYPH_B == ' ') {
      lowerBorder += '-';
    }
    else {
      lowerBorder += "--";
    }
  }

  for (yPos = 0; yPos < FIELD_HEIGHT; ++yPos) {
    field[yPos] = clearLine;
    fieldClear[yPos] = clearLine;
  }

  for (fieldIndex = 0; fieldIndex < FIELD_HEIGHT * FIELD_WIDTH; ++fieldIndex) {
    fieldColors[fieldIndex] = 0;
    fieldColorsClear[fieldIndex] = 0;
  }
}

int main() {
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);

  initGame();

  srand(time(NULL));

  thread thr1(yIncrease);
  thread thr2(gameLoop);

  thr1.join();
  thr2.join();

  return 0;
}