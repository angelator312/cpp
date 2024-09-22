#include "Index.hpp"
#include <fstream>
struct IB
{
  Index ind;
  bool b;
  IB(Index ind, bool b)
  {
    this->ind = ind;
    this->b = b;
  }
};
struct Board
{
  fstream out;
  int board[9][9]{};
  int assumptions[9][9][10]{};
  bool countM = false;
  int count = 0; 
  Board(string fN) : out(fN, out.out) {}
  // int assumptions_old[9][9][10]{};
  bool eInSquare(Index ind, int e)
  {
    Index i = ind.startOfSquare();
    do
    {
      if (i.x == ind.x && i.y == ind.y)
        continue;
      if (board[i.y][i.x] == e)
      {
        return false;
      }
    } while (i.nextInSquare());
    return true;
  };
  bool eInRow(Index ind, int e)
  {
    Index i = ind.startOfRow();
    do
    {
      if (i.x == ind.x)
        continue;
      if (board[i.y][i.x] == e)
      {
        return false;
      }
    } while (i.nextInRow());
    return true;
  };
  bool eInCol(Index ind, int e)
  {
    Index i = ind.startOfCol();
    do
    {
      if (i.y == ind.y)
        continue;
      if (board[i.y][i.x] == e)
      {
        return false;
      }
    } while (i.nextInCol());
    return true;
  };
  bool eInPlace(Index ind, int e)
  {
    return eInCol(ind, e) && eInRow(ind, e) && eInSquare(ind, e);
  };
  void read(istream &cin)
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        char e;
        cin >> e;
        if (e == '.')
        {
          e = '0';
        }
        if (e < '0' || e > '9')
        {
          cerr << "Invalid entry : " << e << endl;
          exit('p');
        }
        board[i][j] = e - '0';
      }
    }
  };
  void write() { write(cout); };
  void write(ostream &cout)
  { /* condition */
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
      {
        char e = '0' + board[i][j];
        if (e == '0')
        {
          e = '.';
        };
        cout << e << " ";
        if (j % 3 == 2 && j > 0)
        {
          cout << "| ";
        };
      };
      if (i % 3 == 2 && i > 0)
      {
        cout << endl
             << "------|-------|-------|";
      };
      cout << endl;
    };
  };
  bool isValidSudoku()
  {
    Index ind(0, 0);
    do
    {
      if (!eInPlace(ind, board[ind.y][ind.x]))
      {
        return false;
      }
    } while (ind.next());
    return true;
  };
  // vector<Index> findNumbers(int number){
  //   Index ind(0,0);
  //   vector<Index> numbers;
  //   do {
  //     if (board[ind.y][ind.x]==number) {
  //       numbers.push_back(ind)
  //     }
  //   } while (ind.next());
  // };
  Index findMinAssumptions()
  {
    Index ind(0, 0);
    int min = 999;
    do
    {
      int assum = assumptions[ind.y][ind.x][0];
      if (board[ind.y][ind.x])
      {
        continue;
      };
      if (assum < min)
      {
        if (assum == 1)
        {
          return ind;
        }
        else
        {
          min = assum;
        };
      };
    } while (ind.next());
    ind.x = 0;
    ind.y = 0;
    do
    {
      int assum = assumptions[ind.y][ind.x][0];
      if (assum == min)
      {
        return ind;
      }
    } while (ind.next());
    return ind;
  }
  void copyAssumptions(int (&to)[9][9][10], int (&from)[9][9][10])
  {
    Index ind(0, 0);
    do
    {
      for (int i = 0; i < 10; i++)
      {
        to[ind.y][ind.x][i] = from[ind.y][ind.x][i];
      }
    } while (ind.next());
  }
  int sumAssumptions()
  {
    int sum = 0;
    Index ind;
    do
    {
      sum += assumptions[ind.y][ind.x][0];
    } while (ind.next());
    return sum;
  }
  void buildAssumptions()
  {
    Index ind(0, 0);
    do
    {
      if (board[ind.y][ind.x])
      {
        continue;
      };
      for (int number = 1; number < 10; number++)
      {
        if (eInPlace(ind, number))
        {
          assumptions[ind.y][ind.x][number] = 1;
          assumptions[ind.y][ind.x][0]++;
        };
      };
    } while (ind.next());
  };
  void deleteAssumptions(Index pInd)
  {
    Index ind = pInd.startOfRow();
    int e = board[pInd.y][pInd.x];
    do
    {
      if (assumptions[ind.y][ind.x][e])
      {
        assumptions[ind.y][ind.x][e] = 0;
        assumptions[ind.y][ind.x][0]--;
      };
    } while (ind.nextInRow());
    ind = pInd.startOfCol();
    do
    {
      if (assumptions[ind.y][ind.x][e])
      {
        assumptions[ind.y][ind.x][e] = 0;
        assumptions[ind.y][ind.x][0]--;
      };
    } while (ind.nextInCol());
    ind = pInd.startOfSquare();
    do
    {
      if (assumptions[ind.y][ind.x][e])
      {
        assumptions[ind.y][ind.x][e] = 0;
        assumptions[ind.y][ind.x][0]--;
      };
    } while (ind.nextInSquare());
  };
  bool fillAssumption()
  {
    Index ind = findMinAssumptions();
    if (!ind.isValid())
    {
      if (countM)
      {
        if (isValidSudoku())
        {
          count++;
          out << "Solution number: " << count << endl;
          write(out);
        }
        return false;
      }
      return isValidSudoku();
    }

    // cout << "[" << ind.toString() << "]" << endl;
    int(&assum)[10] = assumptions[ind.y][ind.x];
    for (int number = 1; number < 10; number++)
    {
      if (assum[number] == 1)
      {
        int assump[9][9][10];
        copyAssumptions(assump, assumptions);
        board[ind.y][ind.x] = number;
        deleteAssumptions(ind);
        // write();
        if (!fillAssumption())
        {
          copyAssumptions(assumptions, assump);
          board[ind.y][ind.x] = 0;
          continue;
        }
        else
        {
          return isValidSudoku();
        }
      };
    };
    return isValidSudoku();
  };
  bool algorithm()
  {
    buildAssumptions();
    return fillAssumption();
  }
};