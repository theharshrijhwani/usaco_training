/*
ID: harshri1
PROG: friday
LANG: C++
*/

#include <fstream>
#include <vector>
using namespace std;

int main() {
  ifstream cin("friday.in");
  ofstream cout("friday.out");

  vector<int> numOfThirteens(7, 0); // track of what day it is on 13
  vector<int> numOfDays{31, 28, 31, 30, 31, 30, 31,
                        31, 30, 31, 30, 31}; // number of days in normal year
  vector<int> leapNumOfDays{31, 29, 31, 30, 31, 30, 31,
                            31, 30, 31, 30, 31}; // number of days in leap year
  int currDay = 2;                               // since starting on monday
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    if ((((1900 + i) % 100 == 0) && ((1900 + i) % 400 == 0)) ||
        ((1900 + i) % 4 == 0) && ((1900 + i) % 100 != 0)) {
      for (int month = 0; month < 12; month++) {
        for (int day = 0; day < leapNumOfDays[month]; day++, currDay++) {
          if (currDay == 7)
            currDay = 0;
          if (day == 12) {
            numOfThirteens[currDay]++;
          }
        }
      }
    } else {
      for (int month = 0; month < 12; month++) {
        for (int day = 0; day < numOfDays[month]; day++, currDay++) {
          if (currDay == 7)
            currDay = 0;
          if (day == 12) {
            numOfThirteens[currDay]++;
          }
        }
      }
    }
  }

  for (int i = 0; i < 7; i++) {
    if (i == 6) {
      cout << numOfThirteens[i] << endl;
    } else {
      cout << numOfThirteens[i] << " ";
    }
  }
}