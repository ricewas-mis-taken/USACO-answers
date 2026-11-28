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
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x1a, x1b, x2a, x2b, y1a, y1b, y2a, y2b; // you can use loop, I chose not too b/c of small input size
    cin >> x1a >> y1a >> x2a >> y2a;
    cin >> x1b >> y1b >> x2b >> y2b;
    int xmin = min(x1a, x1b);
    int xmax = max(x2a, x2b);
    int ymin = min(y1a, y1b);
    int ymax = max(y2a, y2b);
    int sidelen = max((xmax - xmin), (ymax - ymin)); // simply calculate side len
    cout << sidelen * sidelen;
}
