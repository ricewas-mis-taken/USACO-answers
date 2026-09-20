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

// you should be able to understand this code by simply looking at it, if you can't you either need english lessons or glasses :)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin >> n;

    vector<pair<ll, ll>> cows;

    for (int i{}; i < n; ++i)
    {
        ll time, question;
        cin >> time >> question;

        cows.pb({time, question});
    }
    sort(cows.begin(), cows.end());
    int time{};

    for (int i{}; i < n; ++i)
    {
        int arrival = cows[i].fi;
        int time_needed = cows[i].se;

        if (arrival > time)
        {
            time = arrival;
            time += time_needed;
        }
        else
        {
            time += time_needed;
        }
    }
    cout << time;
}
