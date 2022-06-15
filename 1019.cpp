#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

int arr[10];


void find(int N) {
    int count = 0;
    while (N) {
        int z = 1;
        int f = min(N, 9);
        for (; z <= f; z++) arr[z]++;
        count++;
    }
}

void solve(){
    int N; cin >> N;
    find(N, 0);
    for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
