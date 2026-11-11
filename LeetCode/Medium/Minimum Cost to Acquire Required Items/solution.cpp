class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int minNeedBoth = min(need1,need2);
        long long minCost = 0;
        if(costBoth < (cost1 + cost2)){
            minCost += (long long)minNeedBoth * costBoth;
            need1 -= minNeedBoth;
            need2 -= minNeedBoth;
        }
        if(need1 > 0){
            if(cost1 > costBoth) minCost += (long long)need1 * costBoth;
            else minCost += (long long)need1 * cost1;
        }
        if(need2 > 0){
            if(cost2 > costBoth) minCost += (long long)need2 * costBoth;
            else minCost += (long long)need2 * cost2;
        }

        return minCost;
    }
};