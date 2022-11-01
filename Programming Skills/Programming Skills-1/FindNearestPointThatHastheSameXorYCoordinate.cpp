// You are given two integers, x and y, which represent your current location on a Cartesian grid: (x, y). You are also given an array points where each points[i] = [ai, bi] represents that a point exists at (ai, bi). A point is valid if it shares the same x-coordinate or the same y-coordinate as your location.

// Return the index (0-indexed) of the valid point with the smallest Manhattan distance from your current location. If there are multiple, return the valid point with the smallest index. If there are no valid points, return -1.

// The Manhattan distance between two points (x1, y1) and (x2, y2) is abs(x1 - x2) + abs(y1 - y2).


class FindNearestPointThatHastheSameXorYCoordinate
{
    
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {

        int i = 0;

        int n = points.size();

        int minTillNow = INT_MAX;

        int index = -1;

        int x2 = 0;
        int y2 = 0;

        for (i = 0; i < n; i++)
        {
            x2 = points[i].at(0);
            y2 = points[i].at(1);

            if (x == x2 || y == y2)
            {
                int distance = abs(x - x2) + abs(y - y2);
                if (distance < minTillNow)
                {
                    minTillNow = distance;
                    index = i;
                }
            }
        }

        return index;
    }
};

class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        return FindNearestPointThatHastheSameXorYCoordinate().nearestValidPoint(x, y, points);
    }
};