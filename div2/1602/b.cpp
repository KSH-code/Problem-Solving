#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n;
    vector<vector<int>> arr;
    arr.push_back(vector<int>(n));
    for (int i = 0; i < n; i++)
    {
      cin >> arr[0][i];
    }
    bool same = false;
    while (!same)
    {
      unordered_map<int, int> count;
      for (int i = 0; i < n; i++)
      {
        count[arr[arr.size() - 1][i]]++;
      }
      arr.push_back(vector<int>(n));
      for (int i = 0; i < n; i++)
      {
        arr[arr.size() - 1][i] = count[arr[arr.size() - 2][i]];
      }
      same = true;
      for (int i = 0; i < n; i++)
      {
        if (arr[arr.size() - 1][i] != arr[arr.size() - 2][i])
          same = false;
      }
    }

    cin >> q;
    while (q--)
    {
      int x, k;
      cin >> x >> k;

      cout << arr[k >= arr.size() ? arr.size() - 1 : k][x - 1] << endl;
    }
  }
  return 0;
}
