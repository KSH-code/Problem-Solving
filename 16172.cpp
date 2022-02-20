#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int main()
{
    string temp;
    string substring;
    cin >> temp >>substring;
    ll h = 0;
    string str;
    for (int i = 0; i < temp.size(); i++) if (temp[i] >= '0' && temp[i] <= '9') continue; else str += temp[i];
    // for (int i = 0; i < substring.size(); i++) h += substring[i] * 1000007;
    cout << (str.find(substring) < str.size());

    // ll z=0, l=0;
    // for (int i = 0; i < str.size(); i++) {
    //     z += str[i] * 1000007;
    //     while (z > h && l < i) {
    //         z -= str[l] * 1000007;
    //         l++;
    //     }
    //     if (z == h) {
    //         bool found = true;
    //         for (int j = 0; j < substring.size(); j++) {
    //             if (str[l + j] == substring[j]) continue;
    //             found = false;
    //             break;
    //         }
    //         if (found) {
    //             cout << 1;
    //             return 0;
    //         }
    //     }
    // }
    // cout << 0;
    return 0;
}
