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

    int n;
    cin >> n;

    vi tuition;
    for (int i{}; i < n; ++i)
    {
        int temp;
        cin >> temp;
        tuition.pb(temp);
    }
    sort(tuition.begin(), tuition.end());
    pair<ll, int> output = {0, INT_MAX}; // to always keep track of the best
    for (int i{}; i < n; ++i)
    {
        pair<ll, int> temp;
        temp.fi = ((ll)(n - i) * tuition[i]); // neat way to find the max in O(2) time!
        temp.se = tuition[i];
        if (temp.fi > output.fi)
        {
            output.fi = temp.fi; // if one changes,
            output.se = temp.se; // than so does this one
        }
        if (output.fi == temp.fi) // since one doesn't change, only check other!
        {
            output.se = min(temp.se, output.se);
        }
    }
    cout << output.fi << " " << output.se;
}
