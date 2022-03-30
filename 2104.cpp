#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int N;
ll arr[100000];
const int MAX = 1e9;
ll query(int s, int e) {
    if (s==e) return arr[s] * arr[e];
    if (s+1==e) return max({min(arr[s], arr[e]) * (arr[s] + arr[e]), query(s,s), query(e,e) });
    ll result = 0;
    int m = (s+e)/2;
    int l=m,r=m;
    ll mul = arr[m];
    ll sum = arr[m];
    while(l>=s && r <= e) {
        ll a = l > s ? arr[l-1] : -1;
        ll b = r < e ? arr[r+1] : -1;
        if (b >= a) {
            sum += arr[++r];
        } else {
            sum += arr[--l];
        }
        mul = min({ mul, arr[l], arr[r] });
        result = max(result, mul * sum);
        if (s==l && r==e) break;
    }
    return max({result, query(s, m), query(m, e)});
}

void solve() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cout << query(0, N-1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
