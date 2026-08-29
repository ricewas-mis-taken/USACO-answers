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

// using long long because integer will overflow on some test cases
ll n;
vector<ll> apples;

ll min_dif(ll index, ll g1, ll g2) // g1 is group 1, g2 is group 2
{
    if (index == n)
    {
        return abs(g1 - g2); // find the difference
    }

    return min(min_dif(index + 1, g1 + apples[index], g2), min_dif(index + 1, g1, g2 + apples[index])); // choose to add the apple to group 1 or 2, find the smallest one
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{}; i < n; ++i)
    {
        ll temp;
        cin >> temp;
        apples.pb(temp);
    }
    cout << min_dif(0, 0, 0);
}
