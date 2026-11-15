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

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> symbols(n + 1, vector<bool>(n + 1, false)); //create a 2D map of all the symbol interactions, with the columns losing against the rows, but you can switch it up 
    //I used n+1 for the vector b/c I use i{1} here
    for (int i{1}; i <= n; ++i)
    {
        for (int j{1}; j <= i; ++j)
        {
            char c;
            cin >> c;
            if (c == 'W')
            {
                symbols[j][i] = true; //make sure to read the problem correctly! 
            }
            else if (c == 'L')
            {
                symbols[i][j] = true;
            }
        }
    }
    //go through all test cases 
    for (int i{}; i < m; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2; //get the two Test symbols 

        ll k{}; //ll might not be needed, IDK
        for (int j{1}; j <= n; ++j)
        {
            if (symbols[t1][j] && symbols[t2][j]) //core algo: one of the symbols Bessie uses must beat both of whatever the other cow's names is
            {
                ++k;
            }
        }

        cout << ll(n * n) - ((n - k) * (n - k)) << "\n"; //cool logic: find the total amount of combos, which is area of the square, then minus the seperate combinations that hold two falses
    }
}
