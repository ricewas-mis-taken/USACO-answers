#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vvi;

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
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, m;
    cin >> x >> y >> m;

    int milk{};

    int ycounter = m / y; // how many times y can be poured into m

    for (int i{}; i <= ycounter; ++i) // iterate through all possible pours of y, shorter than x, because y is poured much less
    {
        int xcounter = ((m - (i * y)) / x); // find max times x can be poured into m
        int temp{};
        temp += (i * y);
        temp += (xcounter * x);
        milk = max(milk, temp);
    }
    cout << milk;
}
