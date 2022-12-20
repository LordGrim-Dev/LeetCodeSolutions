
# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/?envType=study-plan&id=data-structure-i)

<p>
You are given an array <code>prices</code> where <code>prices[i]</code> is the price of a given stock on the ith day.

You want to maximize your profit by choosing a <strong>single day</strong> to buy one stock and choosing a <strong>different day in the future</strong> to sell that stock.

Return <em>the maximum profit you can achieve from this transaction.</em> If you cannot achieve any profit, return <code>0</code>.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> prices = [7,1,5,3,6,4]
<strong>Output:</strong> 5.
<strong>Explanation</strong><strong>:</strong> Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> prices = [7,6,4,3,1]
<strong>Output:</strong> 0.
<strong>Explanation</strong><strong>:</strong> In this case, no transactions are done and the max profit = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
    <li><code>1 <= prices.length <= 105</code></li>
    <li><code>0 <= prices[i] <= 104</code></li>
</ul>

<p>&nbsp;</p>

**Related Topics**:  
[Array](https://leetcode.com/tag/array/),
[Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)

## Solution 1.

```cpp
class ProfitFinder {
public:
    int maxProfit(vector<int>& prices) {
       
        int maxProfit = 0;
        int minPrice = prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            profit= prices[i]-minPrice;
            
            maxProfit = max(maxProfit, profit);
            
            minPrice = min(minPrice, prices[i]);
        }
        
        
        return maxProfit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return  ProfitFinder().maxProfit(prices);
    }
};
```