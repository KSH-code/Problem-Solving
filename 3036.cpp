#include <iostream>
using namespace std;
int main(){
  int N;
  cin >> N;
  N--;
  int f; cin >> f;
  while(N--) {
    int b; cin >> b;
    int a = f;
    for (int i = 2; i <= b; i++) {
      if (a % i == 0 && b % i == 0) {
        a /= i;
        b /= i;
        i--;
      }
    }
    cout << a << "/" << b << "\n";
  }
  return 0;
}
