/*
ID: harshri1
TASK: gift1
LANG: C++
*/

#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

int main() {
  ifstream cin("gift1.in");
  ofstream cout("gift1.out");

  int n, amount, parts, share, rem;
  string s, giver, receiver;

  cin >> n;
  unordered_map<string, int> hm;
  vector<string> temp;

  for (int i = 1; i <= n; i++) {
    cin >> s;
    hm[s] = 0;
    temp.push_back(s);
  }

  for (int i = 1; i <= n; i++) {
    cin >> giver;
    cin >> amount >> parts;
    if (parts == 0)
      continue;
    share = amount / parts;
    rem = amount % parts;
    hm[giver] -= amount;
    hm[giver] += rem;
    while (parts--) {
      cin >> receiver;
      hm[receiver] += share;
    }
  }

  for (auto it : temp) {
    cout << it << " " << hm[it] << endl;
  }
}