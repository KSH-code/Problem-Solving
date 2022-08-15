#include <map>
#include <set>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <numeric>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define all(x) = (x).begin(), (x).end()
#define len(x) = (int((x).length()))
using namespace std;

using ll = long long;
using ull = unsigned long long;
using db = double;
using fl = float;


void addthecurrent()
{
    for (int i = 0; i < 1005; i++)
    {
        int crr = 6 * 100;
        crr += 100;
    }
}
string DecimalToBinary(int num)
{
    string str;
    while (num) {
        if (num & 1) // 1
            str += '1';
        else // 0
            str += '0';
        num >>= 1; // Right Shift by 1
    }
    return str;
}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}
vector<int> g[300000];
int dist[300000], color[300000];
const int N = 200005;
ll a[N];
ll a1[N];
int n;
int count()
{
    int ans = 0;
    int i = 2;
    while (i < n + 1)
    {
        if (a1[i] <= -1)
        {
            ans = ans - a1[i];
            int curr = 1;
            a1[curr] = a1[curr] + a1[i];
        }
        else if (a1[i] != 0)
        {
            ans = ans + a1[i];
        }
        i++;
    }
    return ans;
}
void solve()
{
    cin >> n;
    int i;
    for (i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        a1[i] = a[i] - a[i - 1];
    }
    ll ans = 0;
    for (i = 2; i < n + 1; i++)
    {
        if (a1[i] > 0)
        {
            ans = ans + (ll)a1[i];
        }
        else if (a1[i] < 0)
        {
            ans = ans - (ll)a1[i];
            a1[1] = a1[1] + a1[i];
        }
    }
    ll res = ans + abs(a1[1]);
    cout << res << endl;
    return;
}

int main()
{
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*`

              ███╗░░██╗░█████╗░██████╗░███████╗██╗░░██╗
              ████╗░██ ██╔══██╗██╔══██╗██╔════╝██║░██╔╝
              ██╔██╗██║███████║██████╔╝█████╗░░█████═╝░
              ██║╚████║██╔══██║██╔══██╗██╔══╝░░██╔═██╗░
              ██║░╚███║██║░░██║██║░░██║███████╗██║░╚██╗
              ╚═╝░░╚══╝╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝
*/
