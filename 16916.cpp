#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string substring;
    cin >> str >>substring;
    int h = 0;
    for (int i = 0; i < substring.size(); i++) h += substring[i] * 3;

    int z=0, l=0;
    for (int i = 0; i < str.size(); i++) {
        z += str[i] * 3;
        while (z > h && l < i) {
            z -= str[l] * 3;
            l++;
        }
        if (z == h) {
            bool found = true;
            for (int j = 0; j < substring.size(); j++) {
                if (str[l + j] == substring[j]) continue;
                found = false;
                break;
            }
            if (found) {
                cout << 1;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}
