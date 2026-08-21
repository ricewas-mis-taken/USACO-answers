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

	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	vvi p = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}}; // the 8 possible ways to make 3 in a row

	vector<char> cows;
	for (int i{}; i < 9; ++i)
	{
		char temp;
		cin >> temp;
		cows.pb(temp);
	}

	int singlewin{};
	set<char> singletest = {cows.begin(), cows.end()}; // has a list of each unique letter, to keep track of cows that haven't won

	for (int i{}; i < p.size(); ++i)
	{
		char x = cows[p[i][0]];
		char y = cows[p[i][1]];
		char z = cows[p[i][2]];
		if (x == y && y == z)
		{
			if (singletest.count(x))
			{
				singlewin++;
				singletest.erase(x);
			}
		}
	}

	int doublewin{};
	vector<pair<char, char>> doublecheck; // to keep track of pairs of cows that have already won

	for (int i{}; i < 9; ++i)
	{
		for (int j{}; j < 9; ++j)
		{
			char first = cows[i];
			char second = cows[j];
			if (first <= second) // make sure first isn't the same as second, note i<=j does NOT work
			{
				continue;
			}

			for (int k{}; k < doublecheck.size(); ++k) // making sure pair hasn't already won
			{
				if ((first == doublecheck[k].first && second == doublecheck[k].second) || (first == doublecheck[k].second && second == doublecheck[k].first))
				{
					goto end;
				}
			}

			for (int k{}; k < 8; ++k)
			{
				char x = cows[p[k][0]];
				char y = cows[p[k][1]];
				char z = cows[p[k][2]];

				int firstcheck = (x == first) + (y == first) + (z == first);	 // how many x matches, should be either 1 or 2
				int secondcheck = (x == second) + (y == second) + (z == second); // how many y matches, should be either 1 or 2

				if ((firstcheck == 2 && secondcheck == 1) || (firstcheck == 1 && secondcheck == 2)) // only in these specific orderings do the cows win
				{
					++doublewin;
					doublecheck.pb({first, second});
					break;
				}
			}

		end:;
		}
	}
	cout << singlewin << "\n"
		 << doublewin;
}
