#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main(){
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;
  vector<pair<double, double> > v;
  for (int i = 0; i < N; i++) {
    double a, b; cin >> a >> b;
    v.push_back({ a, b });
  }

  double result = 0;
  for (int i = 0; i < N; i++) {
    result += v[i].first * v[(i + 1) % N].second - v[i].second * v[(i + 1) % N].first;
  }
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);
  cout << round(abs(result) * 5) / 10;
  return 0;
}
