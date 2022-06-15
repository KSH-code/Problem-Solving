#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

int N;
string str;
int a,b;

int x;

int l,r;

int dfs() {
    int s = x++;
    int check = 0;

    if (s == a) check++;
    if (s == b) check++;

    while (str[x] != '1') check += dfs();
    check += (x==a) + (x==b);
    x++;

    int e = x;

    if (check == 2) {
        if (l == 0 && r == 0) {
            l = s+1;
            r = e;
        }
    }

    return check;
}

void solve(){
    cin >> N >> str >> a >> b;
    a--,b--;
    dfs();
    cout << l << ' ' << r;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
