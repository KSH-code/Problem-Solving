#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

struct node {
	ll mul, sum;
	int i;
};

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  ll a[N], b[N];
  for (int i = 0; i < N; i++) cin >> a[i] >> b[i];

  ll result = 1e11;

  queue<node> q;
  q.push({ 0, 0, 0 });
  while (q.size()) {
    auto [mul, sum, i] = q.front();
    q.pop();
    if (mul >= 1e10) continue;
    if (sum > 0) result = min(result, abs(mul - sum));
    if (i == N) continue;

    q.push({ (!mul ? 1 : mul) * a[i], sum + b[i], i + 1});
    q.push({ mul, sum, i + 1 });
  }

  cout << result;

  return 0;
}
