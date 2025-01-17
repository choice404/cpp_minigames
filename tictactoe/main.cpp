/*
 * Copyright (C) 2025 Choice404
 * See end of file for extended copyright information
 */

#include <iostream>

#define Clear() (system("clear"))

void printBoard(char[3][3]);
bool cellCheck(char[3][3], int, int);
char winCheck(char[3][3]);

int main() {
  int turn = 1, location = 0;
  char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
  char piece = '\0', winner = '\0';

  do {
    printBoard(board);

    piece = (turn == 1) ? 'X' : 'O';

    bool played = false;

    do {

      std::cout << "\nEnter where you would like to place your piece: ";
      std::cin >> location;

      if (location == 1 && board[0][0] == '1') {
        board[0][0] = piece;
        played = true;
      } else if (location == 2 && board[0][1] == '2') {
        board[0][1] = piece;
        played = true;
      } else if (location == 3 && board[0][2] == '3') {
        board[0][2] = piece;
        played = true;
      } else if (location == 4 && board[1][0] == '4') {
        board[1][0] = piece;
        played = true;
      } else if (location == 5 && board[1][1] == '5') {
        board[1][1] = piece;
        played = true;
      } else if (location == 6 && board[1][2] == '6') {
        board[1][2] = piece;
        played = true;
      } else if (location == 7 && board[2][0] == '7') {
        board[2][0] = piece;
        played = true;
      } else if (location == 8 && board[2][1] == '8') {
        board[2][1] = piece;
        played = true;
      } else if (location == 9 && board[2][2] == '9') {
        board[2][2] = piece;
        played = true;
      } else {
        std::cout << "Error: Invalid input. Please try again" << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
      }

    } while (!played);

    winner = winCheck(board);

    turn *= -1;

  } while (winner == '\0');

  printBoard(board);

  std::cout << std::endl;

  std::string winResult = (winner == 'X') ? "X wins!" : "O wins!";

  if (winner == 'd') {
    winResult = "Draw!";
  }

  std::cout << winResult << std::endl;

  return 0;
}

void printBoard(char board[3][3]) {
  Clear();
  std::string emptyRow = "|     |     |     |";
  std::string dividerRow = "|-----------------|";

  std::cout << dividerRow << std::endl;
  for (int i = 0; i < 3; i++) {
    std::cout << emptyRow << std::endl
              << "|  " << board[i][0] << "  |  " << board[i][1] << "  |  "
              << board[i][2] << "  |" << std::endl
              << emptyRow << std::endl
              << dividerRow << std::endl;
  }
}

bool cellCheck(char board[3][3], int row, int col) {
  if (board[row][col] == 'X' || board[row][col] == 'O') {
    return true;
  } else {
    return false;
  }
}

char winCheck(char board[3][3]) {
  char winner = '\0';

  for (int i = 0; i < 3; i++) {
    if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
      winner = board[i][0];
      if (winner == 'X' || winner == 'O') {
        return winner;
      }
    }
    if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
      winner = board[0][i];
      if (winner == 'X' || winner == 'O') {
        return winner;
      }
    }
  }
  if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
    winner = board[1][1];
    if (winner == 'X' || winner == 'O') {
      return winner;
    }
  } else if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
    winner = board[1][1];
    if (winner == 'X' || winner == 'O') {
      return winner;
    }
  }
  if (board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
      board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
      board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9') {
    return 'd';
  }
  return '\0';
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
