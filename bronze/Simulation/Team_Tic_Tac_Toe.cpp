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
	freopen("tttt.in", "r", stdin);
	freopen("tttt.out", "w", stdout);
	vector<vector<int>> p = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
	// ^^ this vector includes the 8 possible ways you can get 3 in a row, useful for calculating single and paired cow wins
	vector<char> cows;

	for (int i{}; i < 9; ++i)
	{
		char temp;
		cin >> temp;
		cows.pb(temp);
	}

	int singlewin{};
	set<char> singletest = {cows.begin(), cows.end()}; // find out how many cows there are, will be subtracted from to make sure a cow doesn't singularly win twice
	for (int i{}; i < p.size(); ++i)
	{
		char x = cows[p[i][0]];
		char y = cows[p[i][1]];
		char z = cows[p[i][2]];
		if (x == y && y == z && x == z)
		{
			for (int j{}; j < 9; ++j)
			{
				char test = cows[j];

				if (singletest.count(test))
				{
					if (test == x)
					{
						singlewin++;
						singletest.erase(test);
					}
				}
			}
		}
	}
	int doublewin{};
	vpii doubledone; // a vector to record pairs that have already won
	for (int i{}; i < 9; ++i)
	{
		for (int j{}; j < 9; ++j)
		{
			char first = cows[i];
			char second = cows[j];
			if (first <= second) // pairs cannot be the same
			{
				continue;
			}
			bool checker{true};
			for (int k{}; k < doubledone.size(); ++k) // check to make sure that the pair hasn't already won
			{

				if ((first == doubledone[k].fi && second == doubledone[k].se) || (first == doubledone[k].se && second == doubledone[k].first))
				{
					checker = false;
				}
			}
			if (checker)
			{
				for (int k{}; k < p.size(); ++k)
				{
					char x = cows[p[k][0]];
					char y = cows[p[k][1]];
					char z = cows[p[k][2]];
					if (x == y && y == z && x == z)
					{
						continue;
					}
					bool firstshow{};
					bool secondshow{};
					bool confirmed{};
					if (x == first || y == first || z == first)
					{
						firstshow = true;
					}
					if (x == second || y == second || z == second)
					{
						secondshow = true;
					}

					// an extremely inefficent way to check for pairs
					if (firstshow && secondshow)
					{

						if (x == y && x == first && z == second)
						{
							confirmed = true;
						}
						else if (x == z && x == first && y == second)
						{
							confirmed = true;
						}
						else if (y == z && y == first && x == second)
						{
							confirmed = true;
						}
						else if (x == y && x == second && z == first)
						{
							confirmed = true;
						}
						else if (x == z && x == second && y == first)
						{
							confirmed = true;
						}
						else if (y == z && y == second && x == first)
						{
							confirmed = true;
						}

						if (confirmed)
						{
							doublewin++;
							doubledone.pb({first, second});
							break;
						}
					}
				}
			}
		}
	}
	cout << singlewin << "\n"
		 << doublewin;
}
