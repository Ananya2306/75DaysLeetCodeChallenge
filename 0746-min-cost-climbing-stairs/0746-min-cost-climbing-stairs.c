int minCostClimbingStairs(int* cost, int costSize) {
    int dp[costSize];

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < costSize; i++) {
        if(dp[i - 1] < dp[i - 2])
            dp[i] = cost[i] + dp[i - 1];
        else
            dp[i] = cost[i] + dp[i - 2];
    }

    if(dp[costSize - 1] < dp[costSize - 2])
        return dp[costSize - 1];

    return dp[costSize - 2];
}