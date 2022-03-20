#include <iostream>
#include <string>
#include <unordered_set>
typedef long long ll;
using namespace std;

void solve(){
  int N; cin >> N;
  int MAX = 2 * N + 1;
  unordered_set<int> s;
  int count = 1;
  for (int i = 0; i <= N; i++) {
    while (s.find(count) != s.end()) count++;
    cout << count << endl;
    s.insert(count);
    int t; cin >> t; if (t == 0) break;
    s.insert(t);
  }
}

int main(){
  solve();
  return 0;
}
