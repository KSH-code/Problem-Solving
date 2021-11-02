#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    char minimum = s[0];
    int index = 0;
    for (int i = 1; i < s.length(); i++)
    {
      if (minimum > s[i])
      {
        index = i;
        minimum = s[i];
      }
    }
    cout << minimum << " ";
    for (int i = 0; i < s.length(); i++)
    {
      if (i == index)
        continue;
      cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
