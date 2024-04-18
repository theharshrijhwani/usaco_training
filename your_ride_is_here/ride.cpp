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
    sum = sum * (c - 'A' + 1);
  }

  return sum % 27;
}

int main() {
  ifstream cin("file.in");
  ofstream cout("file.out");

  string comet, group;
  cin >> comet >> group;

  if (helper(comet) == helper(group)) {
    cout << "GO" << endl;
  } else {
    cout << "STAY" << endl;
  }

  return 0;
}