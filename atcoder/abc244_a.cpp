#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

void solve(){
  int N; cin >> N;
  string str; cin >> str;
  cout << str[N-1];
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
