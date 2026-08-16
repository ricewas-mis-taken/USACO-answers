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
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int n;
    cin >> n;

    vpii coords;
    for (int i{}; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        coords.pb({a, b});
    }

    int area{INT_MIN};

    for (int i{}; i < n; ++i) // first coordinate
    {
        for (int j{}; j < n; ++j) // second coordinate
        {
            if (i == j) // make sure points aren't the same
            {
                continue;
            }
            for (int k{}; k < n; ++k) // third coordinate
            {
                if (i == k || k == j)
                {
                    continue;
                }
                // get the x and y coordinates of all three points
                int x1 = coords[i].fi;
                int y1 = coords[i].se;
                int x2 = coords[j].fi;
                int y2 = coords[j].se;
                int x3 = coords[k].fi;
                int y3 = coords[k].se;

                bool x_axis{}; // checks if two points are parallel to the x axis
                bool y_axis{}; // checks if two points are parallel to the y axis

                int xlength;  // length of one side
                int ylength;  // length of the other
                if (x1 == x2) // lots of if statements to figure out the above bools and ints
                {
                    y_axis = true;
                    ylength = abs(y1 - y2);
                }
                else if (x1 == x3)
                {
                    y_axis = true;
                    ylength = abs(y1 - y3);
                }
                else if (x2 == x3)
                {
                    y_axis = true;
                    ylength = abs(y2 - y3);
                }
                if (y1 == y2)
                {
                    x_axis = true;
                    xlength = abs(x1 - x2);
                }
                else if (y1 == y3)
                {
                    x_axis = true;
                    xlength = abs(x1 - x3);
                }
                else if (y2 == y3)
                {
                    x_axis = true;
                    xlength = abs(x2 - x3);
                }

                if (x_axis && y_axis) // find largest area
                {
                    int temp = xlength * ylength;
                    area = max(temp, area);
                }
            }
        }
    }
    cout << area;
}
