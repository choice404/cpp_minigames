/*
 * Copyright (C) 2025 Choice404
 * See end of file for extended copyright information
 */

#include <iostream>

#define Log(x) (std::cout << x << std::endl)
#define Clear() (system("clear"))

const int ROW = 6, COL = 7;

void printBoard(char[ROW][COL], int &, int &);
int placePiece(char[ROW][COL], int &, int &);
int play(char[ROW][COL], int &, int &);
char checkWin(char[ROW][COL]);
char win(char[ROW][COL], int &);
bool checkLine(char, char, char, char);
bool boardFilled(char[ROW][COL]);

int main() {

  char board[ROW][COL] = {{'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
                          {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
                          {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
                          {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
                          {'\0', '\0', '\0', '\0', '\0', '\0', '\0'},
                          {'\0', '\0', '\0', '\0', '\0', '\0', '\0'}};

  int played = 0;
  int hover = 0;
  int turn = 1;
  char winner = '\0';

  while (winner == '\0' && !boardFilled(board)) {
    printBoard(board, hover, turn);
    played = play(board, hover, turn);
    if (played == 1) {
      break;
    } else if (played == 2) {
      continue;
    }
    winner = checkWin(board);
    turn = turn * -1;
  }

  if (winner == '\0') {
    return 0;
  }

  printBoard(board, hover, turn);
  Log(winner << " is the winner!");
}

void printBoard(char board[ROW][COL], int &hover, int &turn) {
  Clear();
  std::string line =
      "---------------------------------------------------------\n";
  std::string spacer =
      "|       |       |       |       |       |       |       |\n";
  std::cout << '\n';

  char piece = (turn == 1) ? 'X' : 'O';

  for (int i = 0; i < COL; i++) {
    if (i == hover) {
      std::cout << "|   " << piece << "   ";
      continue;
    }
    std::cout << "|       ";
  }
  std::cout << "|\n\n" << line << spacer;
  char curPiece = '\0';
  for (int i = 0; i < ROW; i++) {
    std::cout << "|   ";
    for (int j = 0; j < COL; j++) {
      if (board[i][j] == '\0') {
        curPiece = ' ';
      } else {
        curPiece = board[i][j];
      }
      if (j == COL - 1) {
        std::cout << curPiece << "   |";
        continue;
      }
      std::cout << curPiece << "   |   ";
    }
    std::cout << '\n' << spacer << line;
    if (i != ROW - 1) {
      std::cout << spacer;
    }
  }
}

int placePiece(char board[ROW][COL], int &hover, int &turn) {
  char piece = (turn == 1) ? 'X' : 'O';
  if (board[0][hover] != '\0') {
    std::cout << "Column is full. Please try again";
    return 0;
  }
  if (board[ROW - 1][hover] == '\0') {
    board[ROW - 1][hover] = piece;
    return 0;
  }
  for (int i = 0; i < COL; i++) {
    if (board[i + 1][hover] != '\0') {
      board[i][hover] = piece;
      return 0;
    }
  }
  return 0;
}

int play(char board[ROW][COL], int &hover, int &turn) {
  int command = 0;
  std::cout
      << "1) Place\n2) Move right\n3) Move left\n4) Quit\nEnter command: ";
  std::cin >> command;
  switch (command) {
  case 1:
    placePiece(board, hover, turn);
    break;
  case 2:
    if (hover == COL - 1) {
      std::cout << "Piece is already at the end. Try again" << std::endl;
      return 2;
    }
    hover += 1;
    return 2;
  case 3:
    if (hover == 0) {
      std::cout << "Piece is already at the end. Try again" << std::endl;
      return 2;
    }
    hover -= 1;
    return 2;
  case 4:
    return 1;
  default:
    Log("Invalid input. Please try again");
    return 2;
  }
  return 0;
}

char checkWin(char board[ROW][COL]) {
  for (int r = 0; r < ROW - 3; r++) {
    for (int c = 0; c < COL; c++) {
      if (checkLine(board[r][c], board[r + 1][c], board[r + 2][c],
                    board[r + 3][c])) {
        return board[r][c];
      }
    }
  }

  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COL - 3; c++) {
      if (checkLine(board[r][c], board[r][c + 1], board[r][c + 2],
                    board[r][c + 3])) {
        return board[r][c];
      }
    }
  }

  for (int r = 0; r < ROW - 3; r++) {
    for (int c = 0; c < COL - 3; c++) {
      if (checkLine(board[r][c], board[r + 1][c + 1], board[r + 2][c + 2],
                    board[r + 3][c + 3])) {
        return board[r][c];
      }
    }
  }

  for (int r = 3; r < ROW; r++) {
    for (int c = 0; c < COL - 3; c++) {
      if (checkLine(board[r][c], board[r - 1][c + 1], board[r - 2][c + 2],
                    board[r - 3][c + 3])) {
        return board[r][c];
      }
    }
  }

  return '\0';
}

bool checkLine(char a, char b, char c, char d) {
  if (a != '\0' && a == b && a == c && a == d) {
    return true;
  }
  return false;
}

bool boardFilled(char board[ROW][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if (board[i][j] == '\0') {
        return false;
      }
    }
  }
  return true;
}

/*
 * Copyright (C) 2025 Choice404
 *
 * cpp_minigames
 * A collection of terminal minigames
 *
 * This code is licensed under the GNU General Public License 3.0.
 * Please see the LICENSE file in the root directory of this project for the
 * full license details.
 */
