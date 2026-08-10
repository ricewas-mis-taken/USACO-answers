#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> road;
    vector<tuple<int, int, int>> bessie; // bessie's road segments
    int counter{};                       // counter simulates the positions, start, end of the road
    //               this makes it easy too simulate later
    for (int i{}; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        road.push_back({counter, counter + a, b}); // road start, road end, and speed
        counter += a;                              // incrementing road start to road end
    }
    int counter1{}; // same thing for bessie

    for (int i{}; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        bessie.push_back({counter1, counter1 + a, b});
        counter1 += a;
    }
    int worst{};

    for (int i{}; i < m; ++i)
    {
        int cpos = get<0>(bessie[i]);
        int end = get<1>(bessie[i]);
        int speed = get<2>(bessie[i]);
        for (int j{}; j < n; ++j)
        {
            int roadbegin = get<0>(road[j]);
            int roadend = get<1>(road[j]);
            int roadspeed = get<2>(road[j]);

            if (roadbegin <= cpos && roadend > cpos) // the beginning of the road must be less than or equal to bessie's spot,
            // the end of the road segment must be larger than bessie's, that way the end of one road cannot be counted as the beginning of another
            {
                if (roadend < end) // if road is less then the end of bessie's segment, then increment based on road
                {
                    cpos += (roadend - cpos);
                }
                else // opposite logic
                {
                    cpos += (end - cpos);
                }
                worst = max(worst, (speed - roadspeed));
            }

            if (cpos == end)
            {
                break;
            }
        }
    }
    cout << worst;
}
