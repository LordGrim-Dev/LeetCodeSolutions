
# [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/?envType=study-plan&id=data-structure-i)

<p>
Write an efficient algorithm that searches for a value <code>target</code> in an <code>m x n</code> integer matrix <code>matrix</code>. This matrix has the following properties:

<ul>
<li>Integers in each row are sorted from left to right.</li>
<li>The first integer of each row is greater than the last integer of the previous row.</li>
</ul>
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)
<pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)
<pre><strong>Input:</strong> matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>m == matrix.length</code></li>
    <li><code>n == matrix[i].length</code></li>
    <li><code>-10<sup>4</sup> <= matrix[i][j], target <= 10<sup>4</sup> </code></li>
    <li><code>1 <= m, n <= 100</code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/),
[Binary Search](https://leetcode.com/tag/binary-search/)
[Matrix](https://leetcode.com/tag/matrix/)

## Solution 1.

```cpp
class Matrix
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        bool found = false;
        int low = 0;
        int high = 0;
        int mid = 0;

        // check only one element is present and if so check is it ellement to be searched.
        if (matrix.size() * matrix[0].size() == 1)
        {
            if (target == matrix[0][0])
                found = true;
        }
        else
        {
            // Find row to be used for searching
            int rowToBeUsed = 0;
            for (int i = 0; i < matrix.size(); i++)
            {
                if (target >= matrix[i][0])
                {
                    rowToBeUsed = i;
                }
                else
                {
                    break;
                }
            }

            // Binary search
            high = matrix[0].size();
            mid = (low + high) / 2;

            for (int i = 0; i <= high / 2; i++)
            {
                if (matrix[rowToBeUsed][mid] == target)
                {
                    found = true;
                    break;
                }
                else
                {
                    if (target > matrix[rowToBeUsed][mid])
                        mid = (mid + 1) % high;
                    else
                        mid = (mid - 1) % high;
                }
            }
        }

        return found;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        return  Matrix().searchMatrix(matrix,target);
    }
};
```