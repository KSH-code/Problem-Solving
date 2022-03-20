#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str, t; cin >> str >> t;
    vector<char> st;
    for (int i = 0; i < str.size(); i++) {
        st.push_back(str[i]);

        while (st.size() >= t.size()) {
            bool matched = true;
            for (int j = 0; j < t.size(); j++) {
                if (st[st.size() - t.size() + j] != t[j]) matched = false;
            }
            if (!matched) break;

            for (int j = 0; j < t.size(); j++) st.pop_back();
        }
    }

    if (st.empty()) cout << "FRULA";
    else for (auto c : st) cout << c;

    return 0;
}
