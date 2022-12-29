
# [36. Valid Sudoku](https://leetcode.com/problems/valid-sudoku/?envType=study-plan&id=data-structure-i)

<p>
Determine if a <code>9 x 9</code> Sudoku board is valid. Only the filled cells need to be validated <strong>according to the following rules:</strong>

Each row must contain the digits <code>1-9</code> without repetition.
Each column must contain the digits <code>1-9</code> without repetition.
Each of the nine <code>3 x 3</code> sub-boxes of the grid must contain the digits <code>1-9</code> without repetition.

<strong>Note:</strong>
<ul>
<li>A Sudoku board (partially filled) could be valid but is not necessarily solvable.</li>
<li>Only the filled cells need to be validated according to the mentioned rules.</li>
</ul>
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

![referance image](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
<pre><strong>Input:</strong> board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
<strong>Output:</strong> true
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
<strong>Output:</strong> false
<strong>Explaination:</strong>Same as Example 1, except with the <strong>5</strong> in the top left corner being modified to <strong>8</strong>. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>board.length == 9</code></li>
    <li><code>board[i].length == 9</code></li>
    <li><code>board[i][j] </code>is a digit <code>1-9</code> or <code>'.'</code>.</li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/),
[Hash Table](https://leetcode.com/tag/hash-table/)
[Matrix](https://leetcode.com/tag/matrix/)

## Solution 1.

```cpp
class Sudoku
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9][9] = {0};       // rows[5][0] means whether number 1('0'+1) in row 5 has appeared.
        int cols[9][9] = {0};       // cols[3][8] means whether number 9('8'+1) in col 3 has appeared.
        int blocks[3][3][9] = {0};  // blocks[0][2][5] means whether number '6' in block 0,2 (row 0~2,col 6~8) has appeared.
        for (int r = 0; r < 9; r++) // traverse board r,c
            for (int c = 0; c < 9; c++)
                if (board[r][c] != '.')
                {                                   // skip all number '.'
                    int number = board[r][c] - '1'; // calculate the number's index(board's number minus 1)
                    if (rows[r][number]++)
                        return false; // if the number has already appeared once, return false.
                    if (cols[c][number]++)
                        return false;
                    if (blocks[r / 3][c / 3][number]++)
                        return false;
                }
        return true;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board)
    { 
        return  Sudoku().isValidSudoku(board);
    }
};
```