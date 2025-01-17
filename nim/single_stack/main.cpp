/*
 * Copyright (C) 2025 Choice404
 * See end of file for extended copyright information
 */

#include <iostream>

#define Log(x) (std::cout << x << std::endl)
#define newline() (std::cout << std::endl)

class CPU {
public:
  int removeSticks(int *sticks, int maxSticks) {
    m_RemoveAmount = *sticks % (maxSticks + 1) - 1;
    if (m_RemoveAmount == -1)
      m_RemoveAmount = maxSticks;
    if (m_RemoveAmount > *sticks)
      m_RemoveAmount = *sticks - 1;
    if (m_RemoveAmount == 0)
      m_RemoveAmount = 1;
    *sticks -= m_RemoveAmount;
    return m_RemoveAmount;
  }

private:
  int m_RemoveAmount = 0;
};

int main() {

  srand(time(NULL));

  int sticks = 0;
  int maxSticks = 0;
  int gameMode = 1;
  int randomTurn = 1 + rand() / ((RAND_MAX + 1u) / 2);
  int removeAmount = 1;

  CPU Player2;

  signed int turn = (randomTurn == 1) ? 1 : -1;

  Log("#####################");
  Log("#                   #");
  Log("#        NIM        #");
  Log("#                   #");
  Log("#####################");

  do {
    if (!std::cin) {
      Log("Invalid input: Try again");
      std::cin.clear();
      std::cin.ignore(255, '\n');
    }
    if (gameMode < 1 || gameMode > 2) {
      Log("Invalid input: Try again");
    }
    newline();
    Log("1) 1 Player");
    Log("2) 2 Players");
    std::cout << "Select mode: ";
    std::cin >> gameMode;
  } while (!std::cin || gameMode < 1 || gameMode > 2);

  std::cout << "Number of sticks: ";
  std::cin >> sticks;
  newline();

  std::cout << "Most number of sticks that can be removed: ";
  std::cin >> maxSticks;
  newline();

  while (sticks != 0) {
    if (turn == 1) {
      do {
        if (!std::cin) {
          Log("Invalid stick amount: Try again");
          std::cin.clear();
          std::cin.ignore(255, '\n');
        }
        if (removeAmount < 1 || removeAmount > maxSticks ||
            removeAmount > sticks) {
          Log("Invalid stick amount: Try again");
        }
        Log(sticks << " sticks remaining");
        std::cout << "Player 1, how many sticks to remove: ";
        std::cin >> removeAmount;
      } while (!std::cin || removeAmount < 1 || removeAmount > maxSticks ||
               removeAmount > sticks);

      sticks -= removeAmount;

      newline();
      Log("Player 1 removed " << removeAmount << " sticks");
      newline();
      turn = -1;
    } else if (turn == -1) {
      if (gameMode == 2) {
        do {
          if (!std::cin) {
            Log("Invalid stick amount: Try again");
            std::cin.clear();
            std::cin.ignore(255, '\n');
          }
          if (removeAmount < 1 || removeAmount > maxSticks ||
              removeAmount > sticks) {
            Log("Invalid stick amount: Try again");
          }
          Log(sticks << " sticks remaining");
          std::cout << "Player 2, how many sticks to remove: ";
          std::cin >> removeAmount;
        } while (!std::cin || removeAmount < 1 || removeAmount > maxSticks ||
                 removeAmount > sticks);

        sticks -= removeAmount;

        newline();
        Log("Player 2 removed " << removeAmount << " sticks");
      }

      if (gameMode == 1) {
        removeAmount = Player2.removeSticks(&sticks, maxSticks);
        Log("AI removed " << removeAmount << " sticks");
      }
      newline();
      turn = 1;
    }
    removeAmount = 1;
  }

  std::string result = (turn == 1) ? "Player 1" : "Player 2";

  Log("Winner is " << result << "!!!");
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
