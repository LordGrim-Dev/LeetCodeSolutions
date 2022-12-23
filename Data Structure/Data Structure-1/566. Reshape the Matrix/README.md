
# [566. Reshape the Matrix](https://leetcode.com/problems/reshape-the-matrix/?envType=study-plan&id=data-structure-i)

<p>
In MATLAB, there is a handy function called <code>reshape</code> which can reshape an <code>m x n</code> matrix into a new one with a different size <code>r x c</code> keeping its original data.

You are given an <code>m x n</code> matrix <code>mat</code> and two integers <code>r</code> and <code>c</code> representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the <code>reshape</code> operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/04/24/reshape1-grid.jpg)
<pre><strong>Input:</strong> mat = [[1,2],[3,4]], r = 1, c = 4
<strong>Output:</strong> [[1,2,3,4]]
</pre>

<p><strong>Example 2:</strong></p>

![referance image](https://assets.leetcode.com/uploads/2021/04/24/reshape2-grid.jpg)
<pre><strong>Input:</strong> mat = [[1,2],[3,4]], r = 2, c = 4
<strong>Output:</strong> [[1,2],[3,4]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>m == mat.length</code></li>
    <li><code>n == mat[i].length</code></li>
    <li><code>1 <= m, n <= 100</code></li>
    <li><code>-1000 <= mat[i][j] <= 1000</code></li>
    <li><code>1 <= r, c <= 300</code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/),
[Dynamic Programming](https://leetcode.com/tag/matrix/)
[Simulation](https://leetcode.com/tag/simulation/)

## Solution 1.

```cpp
class MatrixReshape {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result;
        // Keep an Aux  vector which adds element
        // when rowCouner == 0, i.e r = 3 , 3 rows in result
        // so initialise till then add it aux vector.
        
        int totalElements = mat.size() * mat[0].size();
        
        if( totalElements != r*c)
            result= mat;
        else
        {
            vector<int> aux;
            int rowCounter = totalElements/r;
            int row =0;
            int column =0;
            for(int i=0;i<totalElements;i++)
            {
                int element = mat[row][column++]; 
                
                aux.push_back(element);
                
                if(column == mat[row].size())
                {
                    column = 0;
                    row++;
                }
                rowCounter --;
                if(rowCounter == 0)
                {
                    result.push_back(aux);
                    rowCounter = totalElements/r;
                    aux.clear();
                }
            }
            
            
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        return  MatrixReshape().matrixReshape(mat,r,c);
    }
};
```