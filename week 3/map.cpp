#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<int, int> freq;
    freq[1] = 1;
    freq[2] = 1;
    freq[3] = 1;
    for (auto [key, count] : freq)
    {
        cout << key << "  " << count << " times\n";
    }

    return 0;
}
