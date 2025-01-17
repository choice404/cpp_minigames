/*
 * Copyright (C) 2025 Choice404
 * See end of file for extended copyright information
 */

#include <iostream>

#define Log(x) (std::cout << x << std::endl)
#define Clear() (system("clear"))

const int ROW = 4, COL = 4;

void printBoard(int[ROW][COL]);
bool collide(int[ROW][COL], int);
void merge(int[ROW][COL], int);
void checkBoard(int[ROW][COL]);
bool play(int[ROW][COL]);
bool newPiece(int[ROW][COL]);
bool canMerge(int[ROW][COL]);
bool canMerge(int[ROW][COL], int);

int main() {
  std::srand(time(NULL));
  int board[ROW][COL] = {};

  Clear();
  newPiece(board);
  printBoard(board);
  bool game = true;

  while (canMerge(board) && game) {
    game = play(board);
    Clear();
    printBoard(board);
  }
  Clear();
  return 0;
}

void printBoard(int board[ROW][COL]) {
  std::string piece;
  std::string line = "-------------------------------------------------\n";
  std::string empty = "|           |           |           |           |\n";

  for (int i = 0; i < ROW; i++) {
    std::cout << line << empty << empty;
    for (int j = 0; j < COL; j++) {
      piece = std::to_string(board[i][j]);
      if (piece == "0") {
        std::cout << "|           ";
      } else if (piece.length() == 1) {
        std::cout << "|     " << piece[0] << "     ";
      } else if (piece.length() == 2) {
        std::cout << "|    " << piece[0] << " " << piece[1] << "    ";
      } else if (piece.length() == 3) {
        std::cout << "|   " << piece[0] << " " << piece[1] << " " << piece[2]
                  << "   ";
      } else if (piece.length() == 4) {
        std::cout << "|  " << piece[0] << " " << piece[1] << " " << piece[2]
                  << " " << piece[3] << "  ";
      } else if (piece.length() == 5) {
        std::cout << "| " << piece[0] << " " << piece[1] << " " << piece[2]
                  << " " << piece[3] << " " << piece[4] << " ";
      }
    }
    std::cout << "|\n" << empty << empty;
  }
  std::cout << line;
}

bool play(int board[ROW][COL]) {
  int choice = 0;
  Log("1. Up\n2. Down\n3. Left\n4. Right\n5. Quit");
  std::cin >> choice;
  switch (choice) {
  case 1:
    if (collide(board, 1) || canMerge(board, 1)) {
      merge(board, 1);
      collide(board, 1);
      return newPiece(board);
    }
    return true;

  case 2:
    if (collide(board, 2) || canMerge(board, 2)) {
      merge(board, 2);
      collide(board, 2);
      return newPiece(board);
    }
    return true;

  case 3:
    if (collide(board, 3) || canMerge(board, 3)) {
      merge(board, 3);
      collide(board, 3);
      return newPiece(board);
    }
    return true;

  case 4:
    if (collide(board, 4) || canMerge(board, 4)) {
      merge(board, 4);
      collide(board, 4);
      return newPiece(board);
    }
    return true;

  case 5:
    return false;

  default:
    return true;
  }
  return false;
}

bool collide(int board[ROW][COL], int dir) {
  bool flag = false;
  do {
    if (dir == 0) {
      return false;
    } else if (dir == 1) {
      for (int i = ROW - 1; i > 0; i--) {
        for (int j = 0; j < COL; j++) {
          if (board[i - 1][j] == 0 && board[i][j] != 0) {
            board[i - 1][j] = board[i][j];
            board[i][j] = 0;
            flag = true;
          }
        }
      }
    } else if (dir == 2) {
      for (int i = 0; i < ROW - 1; i++) {
        for (int j = 0; j < COL; j++) {
          if (board[i + 1][j] == 0 && board[i][j] != 0) {
            board[i + 1][j] = board[i][j];
            board[i][j] = 0;
            flag = true;
          }
        }
      }
    } else if (dir == 3) {
      for (int i = 0; i < ROW; i++) {
        for (int j = COL - 1; j > 0; j--) {
          if (board[i][j - 1] == 0 && board[i][j] != 0) {
            board[i][j - 1] = board[i][j];
            board[i][j] = 0;
            flag = true;
          }
        }
      }
    } else if (dir == 4) {
      for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL - 1; j++) {
          if (board[i][j + 1] == 0 && board[i][j] != 0) {
            board[i][j + 1] = board[i][j];
            board[i][j] = 0;
            flag = true;
          }
        }
      }
    }
    if (!flag) {
      dir = 0;
    }
  } while (collide(board, dir));
  return flag;
}

void merge(int board[ROW][COL], int dir) {
  if (dir == 1) {
    for (int i = 0; i < ROW - 1; i++) {
      for (int j = 0; j < COL; j++) {
        if (board[i + 1][j] == board[i][j]) {
          board[i][j] += board[i + 1][j];
          board[i + 1][j] = 0;
        }
      }
    }
  } else if (dir == 2) {
    for (int i = ROW - 1; i > 0; i--) {
      for (int j = 0; j < COL; j++) {
        if (board[i - 1][j] == board[i][j]) {
          board[i][j] += board[i - 1][j];
          board[i - 1][j] = 0;
        }
      }
    }
  } else if (dir == 3) {
    for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL - 1; j++) {
        if (board[i][j + 1] == board[i][j]) {
          board[i][j] += board[i][j + 1];
          board[i][j + 1] = 0;
        }
      }
    }
  } else if (dir == 4) {
    for (int i = 0; i < ROW; i++) {
      for (int j = COL - 1; j > 0; j--) {
        if (board[i][j - 1] == board[i][j]) {
          board[i][j] += board[i][j - 1];
          board[i][j - 1] = 0;
        }
      }
    }
  }
}

bool newPiece(int board[ROW][COL]) {
  bool rows[ROW] = {};
  bool cols[COL] = {};

  int rowSel = 0;
  int colSel = 0;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if (board[i][j] == 0) {
        rows[i] = true;
        break;
      }
    }
  }

  for (int i = 0; i < ROW; i++) {
    if (rows[i] == true) {
      break;
    }
    if (i == ROW - 1 && rows[i] == false) {
      return false;
    }
  }

  do {
    rowSel = std::rand() / ((RAND_MAX + 1u) / ROW);
  } while (!rows[rowSel]);

  for (int i = 0; i < COL; i++) {
    if (board[rowSel][i] == 0) {
      cols[i] = true;
    }
  }

  do {
    colSel = std::rand() / ((RAND_MAX + 1u) / COL);
  } while (!cols[colSel]);

  int pieceGen = std::rand() / ((RAND_MAX + 1u) / 10);

  if (pieceGen < 9) {
    board[rowSel][colSel] = 2;
  } else if (pieceGen == 9) {
    board[rowSel][colSel] = 4;
  }

  return true;
}

bool canMerge(int board[ROW][COL], int dir) {
  if (dir == 1) {
    for (int i = 0; i < ROW - 1; i++) {
      for (int j = 0; j < COL; j++) {
        if (board[i + 1][j] == board[i][j] && board[i][j] != 0) {
          return true;
        }
      }
    }
  } else if (dir == 2) {
    for (int i = ROW - 1; i > 0; i--) {
      for (int j = 0; j < COL; j++) {
        if (board[i - 1][j] == board[i][j] && board[i][j] != 0) {
          return true;
        }
      }
    }
  } else if (dir == 3) {
    for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL - 1; j++) {
        if (board[i][j + 1] == board[i][j] && board[i][j] != 0) {
          return true;
        }
      }
    }
  } else if (dir == 4) {
    for (int i = 0; i < ROW; i++) {
      for (int j = COL - 1; j > 0; j--) {
        if (board[i][j - 1] == board[i][j] && board[i][j] != 0) {
          return true;
        }
      }
    }
  }
  return false;
}

bool canMerge(int board[ROW][COL]) {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if (board[i][j] == 0) {
        return true;
      }
      if (i != 0 && i != ROW - 1 && j != 0 && j != COL) {
        if (board[i][j] == board[i + 1][j] || board[i][j] == board[i - 1][j] ||
            board[i][j] == board[i][j + 1] || board[i][j] == board[i][j - 1]) {
          return true;
        }
      }
      if (i == 0) {
        if (board[i][j] == board[i + 1][j]) {
          return true;
        }
      }
      if (i == ROW - 1) {
        if (board[i][j] == board[i - 1][j]) {
          return true;
        }
      }
      if (j == 0) {
        if (board[i][j] == board[i][j + 1]) {
          return true;
        }
      }
      if (j == COL - 1) {
        if (board[i][j] == board[i][j - 1]) {
          return true;
        }
      }
    }
  }
  return false;
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
