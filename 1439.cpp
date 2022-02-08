#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  string str;
  cin >> str;

  int count = 0;
  for (int i = 1; i < str.size(); i++)
    if (str[i] != str[i - 1])
      count++;
  cout << count / 2 + count % 2;
  return 0;
}
