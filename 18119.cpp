#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    int N, M; cin >> N >> M;
    string test = "aeiou";
    int data[N];
    while(N--) {
        string str; cin >> str;
        int mark = 0; for (auto a : str) if (test.find(a) == string::npos) mark |= 1<<(a-'a');
        data[N] = mark;
    }
    int check = (1<<26)-1;
    for (auto a : test) check -= 1<<(a-'a');
    while(M--) {
        int r; char a; cin >> r >> a;
        check ^= 1<<(a-'a');
        int result = 0;
        for (auto m : data) if ((m & check) == m) result++;
        cout << result;
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
