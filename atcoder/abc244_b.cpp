#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

void solve(){
  int N; cin >> N;
  string str; cin >> str;
  int xxxx[]={1,0,-1,0};
  int yyyy[]={0,-1,0,1};
  int x=0, y=0, z=0;
  for (int i = 0; i < N; i++) {
    if (str[i] == 'R') z = (z + 1) % 4;
    else {
      x += xxxx[z];
      y += yyyy[z];
    }
  }
  cout << x << ' ' << y;
}

int main(){
  cout.tie(0);cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
