#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<ll>> vvi;
typedef set<ll> si;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
#define fi first
#define se second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // # of test sets
    cin >> t;
    for (int i{}; i < t; ++i)
    {
        int n, m;
        cin >> n >> m;

        vvi cards;

        for (int j{}; j < n; ++j)
        {
            vi temp;
            for (int k{}; k < m; ++k)
            {
                int x;
                cin >> x;
                temp.pb(x);
            }
            cards.pb(temp);
        }

        ll winnings{};

        for (int j{}; j < m; ++j)
        {
            vi columns; // this is a neat little way to find the abs value total without TLE with n^2
            for (int k{}; k < n; ++k)
            {
                columns.pb(cards[k][j]); // put the cards of the same column together
            }
            sort(columns.begin(), columns.end()); // sort them
            ll running{};                         // running sum of the counted past #'s
            for (int k{}; k < n; ++k)
            {
                winnings += ((k * columns[k]) - running);
                running += columns[k];
            }
        }

        cout << winnings << "\n";
    }
}
