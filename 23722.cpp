#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b){
    return b ? gcd(b, a%b) : a;
}

bool solve(){
    int a,b,c,d; cin >> a >> b >> c >> d;
    if(a+b+c+d==0)return false;
    cout << gcd(d,gcd(c,gcd(a,b)));
    return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    while(solve()) cout <<'\n';
    return 0;
}
