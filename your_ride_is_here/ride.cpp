/*
ID: harshri1
PROG: ride
LANG: C++
*/

#include <fstream>

using namespace std;

int helper(string word) {
  int sum = 1;
  for (char c : word) {
    sum = sum * (c - 64);
  }

  return sum % 47;
}

int main() {
  ifstream cin("ride.in");
  ofstream cout("ride.out");

  string comet, group;
  cin >> comet >> group;

  if (helper(comet) == helper(group)) {
    cout << "GO" << endl;
  } else {
    cout << "STAY" << endl;
  }

  return 0;
}