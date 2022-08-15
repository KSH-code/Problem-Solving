#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 5e5;
vector<pair<int,int>> arr;
int dp[MAX+1];
int N;

void solve(){
    cin >> N;
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < N; i++) {
        int a,b; cin >> a >> a >> b;
        arr.push_back({a,b});
    }
    sort(arr.begin(), arr.end(), [](const auto data1, const auto data2) {
        if (data1.first == data2.first) return data1.second > data2.second;
        return data1.first < data2.first;
    });

    arr.erase(unique(arr.begin(),arr.end()),arr.end());

    N = arr.size();

    int result = 0;
    for (int i = 0; i < N; i++) {
        const auto [c,d] = arr[i];

        const auto it = upper_bound(dp, dp + result, -d);
        if (it == dp+result) dp[result++] = -d;
        else *it = -d;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
