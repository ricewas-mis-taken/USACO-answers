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
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int n;
    cin >> n;

    map<string, int> cows; // pre write all values
    cows["Bessie"] = 0;
    cows["Elsie"] = 0;
    cows["Daisy"] = 0;
    cows["Gertie"] = 0;
    cows["Annabelle"] = 0;
    cows["Maggie"] = 0;
    cows["Henrietta"] = 0;
    for (int i{}; i < n; ++i)
    {
        string s;
        int x;

        cin >> s >> x;

        cows[s] += x;
    }

    map<int, vector<string>> values; // orders the values neatly, taking into account multiple
    auto it = cows.begin();
    for (int i{}; i < 7; ++i) // is 7 for 7 cows, not n!!!
    {
        values[it->second].pb(it->first);
        ++it;
    }

    auto jt = values.begin(); // sets to smallest value since we use sorted map, increment one to get second smallest as required by problem
    ++jt;

    if (jt == values.end() || jt->second.size() > 1) // make sure to do values.end() compare first to prevent crash!
    {
        cout << "Tie" << "\n";
    }
    else
    {
        cout << jt->second[0] << "\n";
    }
}
