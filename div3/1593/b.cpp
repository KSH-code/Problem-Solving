#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  while (n--)
  {
    string str;
    cin >> str;

    int length = str.length();
    int result = length;
    for (int i = 0; i < length - 1; i++)
    {
      for (int j = i + 1; j < length; j++)
      {
        int temp = (str[i] - '0') * 10 + str[j] - '0';
        if (temp % 25 == 0)
          result = min(result, length - i - 2);
      }
    }
    cout << result << "\n";
  }

  return 0;
}
