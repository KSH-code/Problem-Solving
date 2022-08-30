#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

long double S,V;
int current[100];
bool visited[100];
int N,M;
pair<long double, long double> arr[100];
pair<long double, long double> arr2[100];
bool dfs(int x) {
    if (visited[x]) return false;
    visited[x] = true;
    long double x1 = arr[x].first;
    long double y1 = arr[x].second;
    for (int i = 0; i < M; i++) {
        long double x2 = arr2[i].first;
        long double y2 = arr2[i].second;
        long double d = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
        long double can = V*S*V*S;
        if (can < d) continue;
        if (current[i] == -1 || dfs(current[i])) {
            current[i] = x;
            return true;
        }
    }
    return false;
}

void solve(){
    memset(current, -1, sizeof current);
    cin>>N>>M>>S>>V;
    for (int i = 0; i < N; i++)cin>>arr[i].first>>arr[i].second;
    for (int i = 0; i < M; i++)cin>>arr2[i].first>>arr2[i].second;
    int result = N;
    for (int i = 0; i < N; i++) {
        memset(visited, 0, sizeof visited);
        if (dfs(i)) result--;
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
