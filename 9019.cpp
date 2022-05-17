#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

struct Node {
    int a;
    string s;
};

const int MOD = 1e4;

pair<int,char> D(int a) {
    return {(a * 2) % MOD, 'D'};
}
pair<int,char> S(int a) {
    if (a == 0) return {9999,'S'};
    return {a-1,'S'};
}
pair<int,char> L(int a) {
    int d1=a/1000,d2=a/100%10,d3=a/10%10,d4=a%10;
    return {d2*1000+d3*100+d4*10+d1,'L'};
}
pair<int,char> R(int a) {
    int d1=a/1000,d2=a/100%10,d3=a/10%10,d4=a%10;
    return {d4*1000+d1*100+d2*10+d3,'R'};
}

void solve(){
    int N,M; cin >> N >> M;
    // D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
    // S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
    // L: L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
    // R: R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다.
    queue<Node> q;
    q.push({N, ""});
    bool visited[10001]; memset(visited,0,sizeof(visited));
    while (q.size()) {
        auto [x,y] = q.front(); q.pop();
        pair<int,char> nxx[] = {D(x),S(x),L(x),R(x)};
        for (auto [nx,ny] : nxx) {
            if (visited[nx]) continue;
            if (nx == M) {
                cout << y+ny;
                return;
            }
            visited[nx]=true;
            q.push({nx,y+ny});
        }
    }

}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
