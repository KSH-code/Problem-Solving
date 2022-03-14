#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main(){
  int N; cin >> N;
  int people[N][2];
  for (int i = 0; i < N; i++) cin >> people[i][0] >> people[i][1];

  map<int, int> right;
  map<int, int> left;

  string str; cin >> str;
  for (int i = 0; i < N; i++) {
    int y = people[i][1];
    int x = people[i][0];
    if (str[i] == 'L') {
      if (left.find(y) == left.end()) {
        left[y] = x;
      } else {
        left[y] = max(left[y], x);
      }
    } else {
      if (right.find(y) == right.end()) {
        right[y] = x;
      } else {
        right[y] = min(right[y], x);
      }
    }
  }
  for (auto [y, x] : right) {
   if (left.find(y) != left.end() && left[y] >= x) {
     cout << "Yes";
     return 0;
   }
  }
  cout << "No";
  return 0;
}
