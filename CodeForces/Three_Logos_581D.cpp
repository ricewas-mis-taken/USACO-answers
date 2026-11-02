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

    int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int sidelength = max({x1, x2, x3, y1, y2, y3});

    int area = ((x1 * y1) + (x2 * y2) + (x3 * y3));

    if (sidelength * sidelength != area)
    {
        cout << -1;
    }
    else
    {
        vector<vector<char>> square; // final output

        vector<tuple<int, int, char>> ad_lengths = {{x1, y1, 'A'}, {x2, y2, 'B'}, {x3, y3, 'C'}}; // the different sizes of ads

        // put in the top strip, will also put in 2 horizontal strips if allowed
        int num_hoz_strips{};
        for (int i{}; i < 3; ++i)
        {
            if ((get<1>(ad_lengths[i]) == sidelength) || (get<0>(ad_lengths[i]) == sidelength))
            {

                int x_hoz;
                if (get<0>(ad_lengths[i]) == sidelength)
                {
                    x_hoz = get<1>(ad_lengths[i]);
                }
                else
                {
                    x_hoz = get<0>(ad_lengths[i]);
                }
                // record the strip(s)
                for (int j{}; j < x_hoz; ++j)
                {
                    vector<char> temp;

                    for (int k{}; k < sidelength; ++k)
                    {
                        temp.pb(get<2>(ad_lengths[i]));
                    }
                    square.pb(temp);
                }
                ++num_hoz_strips;
            }
        }
        // top strip is now in, or all in

        // check if all three are in

        if (num_hoz_strips == 3)
        {
            cout << sidelength << "\n";
            for (int i{}; i < sidelength; ++i)
            {
                for (int j{}; j < sidelength; ++j)
                {
                    cout << square[i][j];
                }
                cout << "\n";
            }
        }
        else
        {
            // is either horizontal strips or not
            char need_delete = square[0][0];
            // get rid of the ad already in the square
            for (int i{}; i < 3; ++i)
            {
                if (get<2>(ad_lengths[i]) == need_delete)
                {
                    swap(ad_lengths[i], ad_lengths.back());
                    ad_lengths.pop_back();
                    break;
                }
            }

            int xleft = sidelength - square.size(); // find how many more lines need to be filled
            // premake the remaining vectors
            for (int i{}; i < xleft; ++i)
            {
                square.pb({});
            }
            int xcount{}; // needs to equal two

            for (int i{}; i < 2; ++i)
            {
                if (get<0>(ad_lengths[i]) == xleft || get<1>(ad_lengths[i]) == xleft)
                {
                    ++xcount;
                }
            }

            if (xcount == 2)
            {
                cout << sidelength << "\n";

                for (int i{}; i < 2; ++i)
                {
                    int ycount;
                    if (get<0>(ad_lengths[i]) == xleft)
                    {
                        ycount = get<1>(ad_lengths[i]);
                    }
                    else
                    {
                        ycount = get<0>(ad_lengths[i]);
                    }
                    // put in a slice
                    for (int j{}; j < xleft; ++j)
                    {
                        for (int k{}; k < ycount; ++k)
                        {
                            square[j + (sidelength - xleft)].pb(get<2>(ad_lengths[i]));
                        }
                    }
                }

                for (int i{}; i < sidelength; ++i)
                {
                    for (int j{}; j < sidelength; ++j)
                    {
                        cout << square[i][j];
                    }
                    cout << "\n";
                }
            }
            else
            {
                cout << -1;
            }
        }
    }
}
