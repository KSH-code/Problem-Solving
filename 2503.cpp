#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

struct Node {
  string number;
  int strike,ball;
};

void solve(){
  int N; cin >> N;
  Node nodes[N];
  for (int i = 0; i < N; i++) {
    cin >> nodes[i].number >> nodes[i].strike >> nodes[i].ball;
  }

  int result = 0;
  for (char a1='1'; a1<= '9'; a1++) {
    for (char a2='1'; a2<= '9'; a2++) {
      for (char a3='1'; a3<= '9'; a3++) {
        if (a1 == a2 || a2 == a3 || a1 == a3) continue;
        bool found = true;
        for (int i = 0; i < N; i++) {
          auto [number, strike, ball] = nodes[i];
          int f_strike = (a1 == number[0]) + (a2 == number[1]) + (a3 == number[2]);
          int f_ball = (a1 == number[1] || a1 == number[2]) + (a2 == number[0] || a2 == number[2]) + (a3 == number[0] || a3 == number[1]);
          found &= f_strike == strike && f_ball == ball;
        }
        if (found) result++;
      }
    }
  }

  cout << result;
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
