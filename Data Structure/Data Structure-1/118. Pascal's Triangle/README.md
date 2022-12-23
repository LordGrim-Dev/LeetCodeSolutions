
# [118. Pascal's Triangle](https://leetcode.com/problems/pascals-triangle/?envType=study-plan&id=data-structure-i)

<p>
Given an integer numRows, return the first <code>numRows</code> of <strong>Pascal's triangle.<strong>

In <strong>Pascal's triangle,</strong> each number is the sum of the two numbers directly above it as shown:

![referance image](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> numRows = 5
<strong>Output:</strong> [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> numRows = 1
<strong>Output:</strong> [[1]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= numRows <= 30</code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/),
[Dynamic Programming](https://leetcode.com/tag/matrix/)

## Solution 1.

```cpp
class PascalsTriangle {
public:
    vector<vector<int>> generate(int numRows) {
        //Result vector
        vector<vector<int>> result;
        
        int column;
        //Initialise vector with ateast one val
        result.push_back({1});
        
        //Previous row pointer
        int previousColumnIndex =0;
        for(int row =1 ; row <= numRows-1; row++)
        {
            vector<int> current;
            
            //Initialise on Every new Row
            previousColumnIndex = 0;
            for(column = 0 ; column <= row; column++)
            {
                //Push 1 directly for FIRST and LAST pos
                if(column ==0 || column == row)
                {
                    current.push_back(1);
                }
                else
                {
                    //Take last row 
                    // vector<int> previous = result[i-1];
                    
                    int prevRowSize = result[row - 1].size();
                    int curIndex = previousColumnIndex % prevRowSize;
                    int nextIndex = (previousColumnIndex +1)% prevRowSize;
                    
                    int sumOfTwoPrevious = result[row-1][curIndex] +result[row-1][nextIndex];
                    
                    current.push_back(sumOfTwoPrevious);
                 
                    previousColumnIndex= (previousColumnIndex + 1 )% prevRowSize;
                }
            }
            result.push_back(current);
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        return  PascalsTriangle().generate(numRows);
    }
};
```