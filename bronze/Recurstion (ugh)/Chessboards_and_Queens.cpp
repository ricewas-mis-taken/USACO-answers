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

// set<vector<vector<bool>>> ways;
int ways{};
void placequeen(int queensplaced, vector<vector<bool>> board)
{
    if (queensplaced == 8)
    {
        // ways.insert(board);
        ++ways;
        return;
    }

    for (int i{}; i < 8; ++i)
    {
        if (board[queensplaced][i])
        { // attacked or reserved square
            continue;
        }
        // square is fine, so make copy of board and start marking what the new queen now attacks
        vector<vector<bool>> temp = board;
        for (int j{}; j < 8; ++j)
        { // mark whole column as attacked and also the spot where the queen is placed
            temp[j][i] = true;
        }
        for (int j{}; j < 8; ++j)
        { // mark entire row as placed, not neccessary, but this is no danger to TLE :)
            temp[queensplaced][j] = true;
        }
        // handy little way to do diagonals: order in: +m going up, +m going down, -m going up, -m going down
        vi x = {1, -1, -1, 1}; // order doesn't really matter as long as you get the pairs right
        vi y = {-1, 1, -1, 1};

        for (int j{}; j < 4; ++j)
        {
            for (int k{1}; k < 8; ++k)
            {
                int xmove = i + (x[j] * k); // haha variable names are cooked but wtv
                int ymove = queensplaced + (y[j] * k);
                if (xmove > 7 || ymove > 7 || xmove < 0 || ymove < 0) // out of bounds, break
                {
                    break;
                }
                temp[ymove][xmove] = true;
            }
        }
        placequeen(queensplaced + 1, temp);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<bool>> input(8, vector<bool>(8, false));
    for (int i{}; i < 8; ++i)
    {
        for (int j{}; j < 8; ++j)
        {
            char c;
            cin >> c;
            if (c == '*')
            {
                input[i][j] = true;
            }
        }
    }
    placequeen(0, input);
    // cout << ways.size();
    cout << ways;
}
