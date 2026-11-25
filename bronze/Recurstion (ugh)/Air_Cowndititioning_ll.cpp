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
int n, m;
vector<tuple<int, int, int, int>> ac;

int cool_cows(int index, vi heat, int cost) // use recursion to solve problem, at each step choose whether to turn an AC on or not
{
    if (index == m)
    {
        bool notcooled{false};
        for (int i{}; i < heat.size(); ++i) // check that this combination of on/off AC's actually sufficently cools the cows
        {
            if (heat[i] > 0)
            {
                notcooled = true;
                break;
            }
        }
        if (notcooled)
        {
            return INT_MAX; // lazy way to mark that this one isn't viable, there are better ways
        }
        return cost;
    }

    int start = get<0>(ac[index]);
    int end = get<1>(ac[index]);
    int power = get<2>(ac[index]);
    int price = get<3>(ac[index]);

    vi temp = heat;
    for (int j{start}; j <= end; ++j)
    {
        temp[j] -= power;
    }
    return min(cool_cows(index + 1, temp, cost + price), cool_cows(index + 1, heat, cost));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<tuple<int, int, int>> cows;
    cin >> n >> m;
    for (int i{}; i < n; ++i)
    {
        int s, t, c;
        cin >> s >> t >> c;
        cows.pb({s, t, c});
    }
    vi heatneeded(101, 0);
    for (int i{}; i < cows.size(); ++i)
    {
        int start = get<0>(cows[i]);
        int end = get<1>(cows[i]);
        int needed = get<2>(cows[i]);
        for (int j{start}; j <= end; ++j)
        {
            heatneeded[j] = needed;
        }
    }
    for (int i{}; i < m; ++i)
    {
        int a, b, p, c;
        cin >> a >> b >> p >> c;
        ac.pb({a, b, p, c});
    }
    cout << cool_cows(0, heatneeded, 0);
}
