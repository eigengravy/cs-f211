// Write the O(n lg n) time algorithm for Question 1 in this file. You can declare your own functions and classes.

int solve(DSA_Vector &prices)
{
    int n = prices.Size();
    int buy = prices.GetElement(0);
    int maxProfit = 0;

    for (int i = 1; i < n; i++){
        int elem = prices.GetElement(i);
        if (elem < buy){
            buy = elem;
            continue;
        } 
        int profit = elem - buy;
        maxProfit = max(profit, maxProfit);
    }
    
    return maxProfit;
}
