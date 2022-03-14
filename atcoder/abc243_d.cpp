#include <iostream>
#include <deque>
#include <string>
using namespace std;

typedef long long ll;
int main(){
  ll N, X; cin >> N >> X;
  string str; cin >> str;
  deque<char> dq;
  for(int i = 0; i < N; i++){
    switch(str[i]) {
      case 'U': {
        if (dq.size()) dq.pop_back();
        else X /= 2;
        break;
      }
      default: {
        dq.push_back(str[i]);
        break;
      }
    }
  }
  while (dq.size()) {
    char x = dq.front();
    dq.pop_front();
    if (x == 'L') X *= 2;
    else X = X * 2 + 1;
  }
  cout << X;
  return 0;
}
