#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    int N,M; cin >> N >> M;
    set<int> A; for (int i = 0; i < N; i++) {int a; cin >> a; A.insert(a);}
    set<int> B; for (int i = 0; i < M; i++) {int a; cin >> a; B.insert(a);}
    set<int> C;
    for (auto a : A) if (!B.count(a)) C.insert(a);
    for (auto a : B) if (!A.count(a)) C.insert(a);
    cout << C.size();
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
