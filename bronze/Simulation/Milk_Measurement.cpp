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

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n;
    cin >> n;

    vector<tuple<int, int, int>> cows; // day, name, output change

    for (int i{}; i < n; ++i)
    {
        string a;
        int b, c;

        cin >> b >> a >> c;

        if (a == "Bessie")
        {
            cows.pb({b, 0, c}); // choose #s that correlate with later indexing of milk, so start with 0!!!
        }
        else if (a == "Mildred")
        {
            cows.pb({b, 1, c});
        }
        else
        {
            cows.pb({b, 2, c});
        }
    }
    sort(cows.begin(), cows.end()); // just a precaution

    int changes{};
    vi milk = {7, 7, 7};                        // read carefully, problem states that it starts at 7
    vector<bool> champ = {false, false, false}; // the current board, don't need to track max output, that's tracked with milk
    for (int i{}; i < n; ++i)
    {
        milk[get<1>(cows[i])] += get<2>(cows[i]); // specific cow gets the output change

        int compare = *max_element(milk.begin(), milk.end()); // find the largest value to generate new board
        vector<bool> temp = {false, false, false};            // temp new board
        if (compare == milk[0])                               // see if each of the 3 cows need to be on new board
        {
            temp[0] = true;
        }
        if (compare == milk[1])
        {
            temp[1] = true;
        }
        if (compare == milk[2])
        {
            temp[2] = true;
        }

        if (temp != champ) // if new board is not same as old board, increment
        {
            ++changes;
            champ = temp;
        }
    }
    cout << changes;
}
