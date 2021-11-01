#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string word;
  cin >> n >> word;
  unordered_map<string, int> map;
  for (int i = 0; i < n - 1; i++)
  {
    string found;
    found += word[i];
    found += word[i + 1];
    map[found] += 1;
  }

  int max = 0;
  string result;
  for (auto dict : map)
  {
    if (dict.second > max)
    {
      result = dict.first;
      max = dict.second;
    }
  }

  cout << result;
  return 0;
}
