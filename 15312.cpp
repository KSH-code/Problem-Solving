#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
const int counts[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int main(){
  string a, b; cin >> a >> b;
  string t; for (int i = 0; i < a.size(); i++) t += counts[a[i] - 'A'] + '0', t += counts[b[i] - 'A'] + '0';
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
