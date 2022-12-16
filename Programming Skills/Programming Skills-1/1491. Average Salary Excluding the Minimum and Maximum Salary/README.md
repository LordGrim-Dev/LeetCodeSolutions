
# [1491. Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/?envType=study-plan&id=programming-skills-i)

<p>
You are given an array of <strong>unique</strong> integers <code>salary</code> where <code>salary[i]</code> is the salary of the <code>i<sup>th</sup></code> employee. 

Return the average salary of employees excluding the minimum and maximum salary. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> salary = [4000,3000,1000,2000]
<strong>Output:</strong> 2500.00000
<strong>Explanation</strong><strong>:</strong>
<code>Minimum salary and maximum salary are 1000 and 3000 respectively.
</code>
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> salary = [1000,2000,3000]
<strong>Output:</strong> 2000.00000
<strong>Explanation</strong>: 
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 <= salary.length <= 100</code></li>
	<li><code>1000 <= salary[i] <= 106</code></li>
    <li>All the integers of <code>salary</code> are <strong>unique</strong>.</li>
</ul>


**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Sorting](https://leetcode.com/tag/sorting/)

## Solution 1.

```cpp
class AverageSalaryExcludingtheMinimumandMaximumSalary
{
        
public:
    double FindAverage(vector<int> &salary)
    {
        int minSalary = 999999;

        int maxSalary = 0;

        int n = salary.size();

        int sumOfSalary = 0;

        for (int i = 0; i < n; i++)
        {
            int currentSal = salary[i];
            minSalary = min(minSalary, currentSal);
            maxSalary = max(maxSalary, currentSal);
            sumOfSalary += currentSal;
        }
        sumOfSalary -= (minSalary + maxSalary);

        return (sumOfSalary / (double)(n - 2));
    }
};

class Solution
{
public:
    double average(vector<int> &salary)
    {
        return AverageSalaryExcludingtheMinimumandMaximumSalary().FindAverage(salary);
    }
};
```