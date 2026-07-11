#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum & 1) {
        cout << "NO";
        return 0;
    }
    cout << "YES"<<endl;
    vector<int> ans1, ans2;
    long long need = sum / 2;
    for (int i = n; i >= 1; i--) {
        if (need >= i) {
            ans1.push_back(i);
            need -= i;
        } else {
            ans2.push_back(i);
        }
    }

    cout << ans1.size() << endl;
    for (auto x : ans1) cout << x << " ";
    cout <<endl<< ans2.size() << endl;
    for (auto x : ans2) cout << x << " ";
    cout << endl;
}
