#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
bool solve(){
  ll n;
  cin >>n;
  if (!n) return false;
  ll arr[n+1];
  for (int i =0;i<n;i++) cin >>arr[i];
  arr[n] = 0;
  vector<ll> stack;
  ll result=0;
  for (int i =0;i<=n;i++) {
    while (stack.size() && arr[stack.back()] >= arr[i]) {
      ll r = stack.back();
      stack.pop_back();
      ll l = (stack.empty() ? -1 : stack.back());
      result = max(result, arr[r] * (i - l - 1));
    }
    stack.push_back(i);
  }
  cout << result << "\n";
  return true;
}

int main()
{
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  solve();
  return 0;
}
