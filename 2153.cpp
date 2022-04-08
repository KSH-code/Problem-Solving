#include <iostream>
#include <string>
using namespace std;

void solve(){
  string str; cin >> str;
  int result = 0;
  for (int i = 0; i < str.size(); i++){
    if (str[i] >= 'a') result += str[i] -'a'+1;
    else result += str[i] - 'A'+27;
  }
  for (int i = 2; i < result; i++){
    if (result % i==0) {
      cout << "It is not a prime word.";
      return;
    }
  }
  cout << "It is a prime word.";
}

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  solve();
  return 0;
}
