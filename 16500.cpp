#include <iostream>
#include <string>

using namespace std;
int N;
string arr[100];
string str;

bool c[101];

void solve(){
    cin>>  str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    c[0]=true;

    for (int i = 1; i <= str.size(); i++) {
        for (int j = 0; j < N; j++) {
            bool yes = true;
            if (str.size() < arr[j].size() + i - 1) continue;

            for (int k = 0; k < arr[j].size(); k++) {
                yes &= arr[j][k] == str[i+k-1];
            }
            if (yes && c[i-1]) c[-1+i+arr[j].size()]=true;
        }
    }

    cout << (c[str.size()]?1:0);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
