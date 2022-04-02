#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct Node {
  ll a,b;
};
void solve(int N){
  vector<Node> v;
  v.push_back({1,1});
  int l = 0, fn = 1;
  while (v.back().a < N) {
    auto [a,b] = v.back();

    fn++;
    v.push_back({a+v[l].b, fn});
    if (fn >= v[l+1].a) l++;
  }
  cout << (v.back().a > N ? fn-1 : fn);
}

int main()
{
  int N; cin >> N; solve(N);
  return 0;
}
