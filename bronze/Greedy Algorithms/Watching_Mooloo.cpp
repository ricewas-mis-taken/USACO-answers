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

    ll n, k;
    cin >> n >> k;

    ll moonies{};
    ll prevday;
    for (ll i{}; i < n; ++i)
    {
        if (i == 0)
        {
            ll day;
            cin >> day;
            moonies += k + 1;  // start a new subscription on day one
            prevday = day + 1; // add one day because we already extended one day
            continue;
        }
        ll day;
        cin >> day;
        if (day - prevday <= k) // extending is better than starting a new subscription
        {

            moonies += (day - prevday + 1);
        }
        else
        {
            moonies += k + 1;
        }
        prevday = day + 1;
    }
    cout << moonies;
}
