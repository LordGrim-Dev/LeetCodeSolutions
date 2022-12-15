# [1523. Count Odd Numbers in an Interval Range](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range?envType=study-plan&id=programming-skills-i)

<p>You are given two integers, <code>x</code> and <code>y</code>, which represent your current location on a Cartesian grid: <code>(x, y)</code>. You are also given an array <code>points</code> where each <code>points[i] = [ai, bi]</code> represents that a point exists at <code>(ai, bi)</code>. A point is <strong>valid</strong> if it shares the same x-coordinate or the same y-coordinate as your location.

Return <em>the index <strong>(0-indexed)</strong></em> of the <strong>valid</strong> point with the smallest <strong>Manhattan distance</strong> from your current location. If there are multiple, return the valid point with the <em><strong>smallest</strong></em> index. If there are no valid points, return <code>-1</code>.

The <strong>Manhattan distance</strong> between two points <code>(x1, y1)</code> and <code>(x2, y2)</code> is <code>abs(x1 - x2) + abs(y1 - y2)</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> x = 3, y = 4, points = [[1,2],[3,1],[2,4],[2,3],[4,4]]
<strong>Output:</strong> 2
<strong>Explanation</strong><strong>:</strong>
Of all the points, only [3,1], [2,4] and [4,4] are valid. Of the valid points, [2,4] and [4,4] have the smallest Manhattan distance from your current location, with a distance of 1. [2,4] has the smallest index, so return 2.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> x = 3, y = 4, points = [[3,4]]
<strong>Output:</strong> 0
<strong>Explanation</strong><strong>:</strong>
The answer is allowed to be on the same location as your current location.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong> x = 3, y = 4, points = [[2,3]]
<strong>Output:</strong> -1
<strong>Explanation</strong>: 
There are no valid points.
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 <= points.length <= 104</code></li>
    <li><code>points[i].length == 2</code></li>
    <li><code>1 <= x, y, ai, bi <= 104</code></li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/)

## Solution 1.

```cpp
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
```