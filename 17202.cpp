#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main(){
  string a, b; cin >> a >> b;
  string t; for (int i = 0; i < a.size(); i++) t += a[i], t += b[i];
  a = t;
  while (a.size() > 2) {
    b = "";
    for (int i = 0; i < a.size() - 1; i++) {
      b += ((a[i] - '0' + a[i + 1] - '0') % 10) + '0';
    }
    a = b;
  }

  cout << a;
  return 0;
}
