#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int main()
{
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;
  while (T--)
  {
    long long k, n;
    cin >> k;

    priority_queue<pair<long long, int>> desc;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> asc;
    bool deleted[k];
    memset(deleted, 0, sizeof(deleted));
    for (int z = 0; z < k; z++)
    {
      string str;
      cin >> str >> n;
      if (str[0] == 'D')
      {
        if (n == 1)
        {
          if (desc.size())
          {
            auto t = desc.top();
            deleted[t.second] = true;
            desc.pop();
          }
        }
        else
        {

          if (asc.size())
          {
            auto t = asc.top();
            deleted[t.second] = true;
            asc.pop();
          }
        }
      }
      else
      {
        desc.push({n, z});
        asc.push({n, z});
      }

      while (desc.size() && deleted[desc.top().second])
      {
        desc.pop();
      }
      while (asc.size() && deleted[asc.top().second])
      {
        asc.pop();
      }
    }

    if (desc.empty())
      cout << "EMPTY\n";
    else
      cout << desc.top().first << " " << asc.top().first << "\n";
  }
  return 0;
}
