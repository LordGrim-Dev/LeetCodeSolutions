
# [1232. Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/?envType=study-plan&id=programming-skills-i)

<p>
You are given an array <code>coordinates, coordinates[i] = [x, y]</code>, where <code>[x, y]</code> represents the coordinate of a point. Check if these points make a straight line in the XY plane.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg)
<pre><strong>Input:</strong>  coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg)
<pre><strong>Input:</strong> coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 <= coordinates.length <= 1000</code></li>
    <li><code>coordinates[i].length == 2</code></li>
    <li><code>-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4</code></li>
    <li><code>coordinates</code> contains no duplicate point.</li>
</ul>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Geometry](https://leetcode.com/tag/geometry/)

## Solution 1.

```cpp

//    You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
// Slope of line formed by 

// two points (y2, y1), (x2, x1)

// Slope of Line = y2 - y1
//                ---------
//                 x2 - x1

// ---------------------------------------------------------------------------------------
// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true
// ---------------------------------------------------------------------------------------

class CheckIfItIsAStraightLine
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        bool isStright = true;
        int length = coordinates.size();

        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];

        int dy = (y1 - coordinates[0][1]);
        int dx = (x1 - coordinates[0][0]);

        // cout<<" \n ";
        for (int i = 1; i < length; i++)
        {
            int j = 1;

            int y = (coordinates[i][1]);
            int x = (coordinates[i][0]);

            if (dy * (x - x1) != dx * (y - y1))
            {
                isStright = false;
                break;
            }
        }
        return isStright;
    }
};

class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        return CheckIfItIsAStraightLine().checkStraightLine(coordinates);
    }
};
```