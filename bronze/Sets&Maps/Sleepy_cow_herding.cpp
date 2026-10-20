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

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    vi cows;
    for (int i{}; i < 3; ++i)
    {
        int x;
        cin >> x;
        cows.pb(x);
    }
    sort(cows.begin(), cows.end());
    int output1;
    int output2 = max((cows[2] - cows[1]), (cows[1] - cows[0])) - 1; // use this formula to find the maximum, can be easily caluclated by noticing you bring the furthest endpoint closer by one everytime
    if ((cows[0] + 1 == cows[1]) && (cows[1] + 1 == cows[2]))        // no need to touch anything
    {
        output1 = 0;
    }
    else if ((cows[0] + 2 == cows[1]) || (cows[1] + 2 == cows[2])) // gap of 2, perfect insert
    {
        output1 = 1;
    }
    else
    {
        output1 = 2;
    }

    cout << output1 << "\n"
         << output2;
}
