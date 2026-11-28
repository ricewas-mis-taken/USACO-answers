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

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    vector<vector<bool>> vision(2002, vector<bool>(2002, false)); // idk why 2002, i'm scared of vector out of bounds haha

    for (int i{}; i < 3; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1000; // add 1000 that way all coordinates are positive
        x2 += 1000;
        y1 += 1000;
        y2 += 1000;
        int yl = max(y1, y2); // find the start and end for the loop for each of these
        int ym = min(y1, y2);
        int xl = max(x1, x2);
        int xm = min(x1, x2);
        if (i == 2) // this is removing the squares the truck blockes
        {

            for (int j{ym}; j < yl; ++j)
            {
                for (int k{xm}; k < xl; ++k)
                {

                    vision[j][k] = false;
                }
            }
            continue;
        }
        for (int j{ym}; j < yl; ++j) // marking squares of billboard since we don't need to distinguish
        {
            for (int k{xm}; k < xl; ++k)
            {

                vision[j][k] = true;
            }
        }
    }

    int see{};
    for (const vector<bool> &v : vision)
    {
        see += count(v.begin(), v.end(), true);
    }
    cout << see;
}
