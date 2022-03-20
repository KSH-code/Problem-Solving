#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
  cin.tie(0) -> sync_with_stdio(false);
  int a[6] = {1,1,2,2,2,8};
  int b[6] = {1,1,2,2,2,8};
  for (int i = 0; i < 6;i++){
    cin >> a[i];
    cout << b[i] - a[i] << ' ';
  }
  return 0;
}
