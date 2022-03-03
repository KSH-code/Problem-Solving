#include <iostream>
#include <cmath>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
int score(char c)
{
    switch (c)
    {
    case 'T':
        return 0;
    case 'G':
        return 1;
    case 'P':
        return 2;
    case 'F':
        return 3;
    }
}

int N;
string str;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> N >> str;
    int count = 0;
    map<int, int> block;
    for (int i = 0; i < N; i++) {
        int idx = score(str[i]);
        int base = (int) pow(10, idx);
        count += base;
        if (count / base % 10 == 3) count -= base * 3;
        block[count]++;
    }
    if (block.find(0) != block.end()) block[0]++;
    int result = 0;
    for (auto [_, c] : block) {
        result += (c - 1) * c / 2;
    }
    cout << result;
    return 0;
}