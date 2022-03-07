#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  string str; cin >> str;
  map<int, int> map;
  int result = -1;
  int a = 0;
  for (int i = 0; i < str.size(); i++) {
    str[i] == 'S' ? a+= 2 : a--;
    if (map.find(a) == map.end) map[-a] = i;
    else result = max(result, i - map[-a]);
  }

  cout << result;
  return 0;
}
