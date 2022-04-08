#include <iostream>
using namespace std;
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    int a,b,c;cin >>a>>b>>c;
    if(a*b/gcd(a,b)<=c) cout << "yes";
    else cout << "no";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
