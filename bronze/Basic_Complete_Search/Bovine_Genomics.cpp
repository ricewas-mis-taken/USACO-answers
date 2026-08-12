#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<char>> spotty;
    vector<vector<char>> plain;
    for (int i{}; i < n; ++i)
    {
        vector<char> temp;
        for (int j{}; j < m; ++j)
        {
            char x;
            cin >> x;
            temp.push_back(x);
        }
        spotty.push_back(temp);
    }
    for (int i{}; i < n; ++i)
    {
        vector<char> temp;
        for (int j{}; j < m; ++j)
        {
            char x;
            cin >> x;
            temp.push_back(x);
        }
        plain.push_back(temp);
    }
    int explain{}; // spots m that can explain for spottiness
    for (int i{}; i < m; ++i)
    {
        set<char> spottyup; // records the letters of m that spotty cows have
        for (int j{}; j < n; ++j)
        {
            spottyup.insert(spotty[j][i]);
        }
        bool check{true}; // keeps track of next part:
        for (int j{}; j < n; ++j)
        {
            char plainup = plain[j][i];
            if (spottyup.count(plainup)) // tries to find if exists in plain genome from spotty
            {
                check = false; // if so then false, so wont be iterated
            }
        }
        if (check)
        {
            explain++;
        }
    }
    cout << explain;
}
