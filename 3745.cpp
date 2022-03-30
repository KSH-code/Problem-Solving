#include <iostream>
#include <set>
using namespace std;

typedef long long ll;

void solve(int N){
  set<int> arr;
  for (int i =0;i<N;i++) {
    int t; cin >> t;
    if (arr.lower_bound(t) != arr.end()) arr.erase(arr.lower_bound(t));
    arr.insert(t);
  }
  cout << arr.size();
}

int main(){
  cin.tie(0)->sync_with_stdio(false);
  while (true) {
    int N; cin >> N;
    if (cin.eof()) break;
    solve(N); cout <<'\n';
  }
  return 0;
}
