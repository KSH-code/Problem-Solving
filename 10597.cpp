#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};
string str;
bool visited[51];
vector<int> result;

bool dfs(int x){
    if (x >= str.size()) {
        bool all = true;
        for (int i = 1; i <= result.size(); i++) all &= visited[i];
        if (!all) return false;
        for (auto s : result) {
            cout << s;
            cout << ' ';
        }
        return true;
    }
    int temp = 0;
    for (int i = x; i < str.size(); i++) {
        temp = temp * 10 + str[i] - '0';
        if (temp > 50) break;
        if (visited[temp]) continue;

        visited[temp] = true;
        result.push_back(temp);
        if (dfs(i + 1)) {
            return true;
        } else result.pop_back();
        visited[temp] = false;
    }
    return false;
}

void solve(){
    cin >> str;
    dfs(0);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
