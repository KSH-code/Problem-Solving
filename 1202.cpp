#include <iostream>
#include <algorithm>
#include <set>
typedef long long ll;
using namespace std;

void solve(){
    int N, M; cin >> N >> M;
    pair<int,int> arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i].second >> arr[i].first;
        arr[i].second = -arr[i].second;
    }
    sort(arr, arr+N);
    multiset<int> s;
    for (int i = 0 ; i < M ;i++) {
        int b; cin >> b;
        s.insert(b);
    }
    ll result = 0;
    for (int i = N-1; i >= 0; i--) {
        auto [price, weight] = arr[i];
        weight = -weight;
        auto it = s.lower_bound(weight);
        if ((*it) >= weight) {
            result += price;
            s.erase(it);
        }
    }
    cout << result;
}

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    solve();
    return 0;
}
