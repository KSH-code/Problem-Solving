#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

vector<int> destructure(int a){
    vector<int> data;
    while (a) {
        data.push_back(a%10);
        a/=10;
    }
    reverse(data.begin(), data.end());
    return data;
}

int structure(vector<int> data){
    int a = 0;for (int i = 0; i < data.size(); i++) a = a*10+data[i];
    return a;
}

void solve(){
    int N, K; cin >> N >> K;
    int result = -1;
    queue<pair<int,int>> q;
    set<pair<int,int>> s;
    q.push({N, 0});
    while (q.size()) {
        auto [x,y] = q.front(); q.pop();
        auto data = destructure(x);
        for (int i = 0; i < data.size() - 1; i++) {
            for (int j = i + 1; j < data.size(); j++) {
                int ns = structure(data);
                auto nx = destructure(ns);
                swap(nx[i], nx[j]);
                if (nx[0] == 0) continue;
                ns = structure(nx);
                if (y+1==K) {
                    result = max(result, ns);
                    continue;
                }
                if (s.count({ns, y+1})) continue;
                s.insert({ns,y+1});
                q.push({ns,y+1});
            }
        }
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
