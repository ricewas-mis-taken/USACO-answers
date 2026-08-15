#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    int m, n, k;
    cin >> m >> n >> k;
    vector<string> signal; // the final signal
    for (int i{}; i < m; ++i)
    {
        string temp;
        for (int j{}; j < n; ++j)
        {
            char x;
            cin >> x;
            for (int a{}; a < k; ++a) // before pushing string to the signal, make sure the characters are expanded horizontally by k
            {
                temp.push_back(x);
            }
        }
        for (int a{}; a < k; ++a)
        {
            signal.push_back(temp); // push k strings of temp to create vertical k expansion
        }
    }

    for (string i : signal)
    {
        cout << i << "\n";
    }
}
