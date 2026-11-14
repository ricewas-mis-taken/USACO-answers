#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;

    // find the bottom-rightmost corner with a cow that is tipped over and then flip all cows

    vector<vector<bool>> cows;

    for (int i{}; i < n; ++i)
    {
        vector<bool> temp;
        for (int j{}; j < n; ++j)
        {
            char c;
            cin >> c;
            temp.pb((c == '1')); // nice trick to avoid using if/else
        }
        cows.pb(temp);
    }
    int uses{};
    for (int i{n - 1}; i >= 0; --i) // count backwards to find the bottommost
    {
        for (int j{n - 1}; j >= 0; --j) // count backwards to find the rightmost
        {
            if (cows[i][j])
            {
                ++uses;
                for (int k{}; k <= i; ++k) // use the machine
                {
                    for (int l{}; l <= j; ++l)
                    {
                        if (cows[k][l])
                        {
                            cows[k][l] = false;
                        }
                        else
                        {
                            cows[k][l] = true;
                        }
                    }
                }
            }
        }
    }
    cout << uses;
}
