#include <iostream>
using namespace std;

int main(){
  int V,A,B,C; cin >> V >> A >> B >> C;
  V %= (A + B + C);
  if (V < A) {
    cout << "F";
    return 0;
  }
  V -= A;
  if (V < B) {
    cout << "M";
    return 0;
  }
  V -= B;
  cout << "T";
  return 0;
}
