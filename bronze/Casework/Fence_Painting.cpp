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

    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    vector<bool> fence(100, false); // easiest way to solve this problem, casework not required, simply painted or not painted by true/false

    for (int i{a}; i < b; ++i)
    {
        fence[i] = true;
    }
    for (int i{c}; i < d; ++i)
    {
        fence[i] = true;
    }

    int total = count(fence.begin(), fence.end(), true);

    cout << total;
}
