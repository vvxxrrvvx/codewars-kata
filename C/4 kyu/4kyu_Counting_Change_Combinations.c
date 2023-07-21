int count_change(int money, int n_coins, const int coins[n_coins]) {
    int ways[money+1];
    memset(ways, 0, sizeof(ways));
    ways[0] = 1; // There is only one way to make change for 0.
    
    for (int i = 0; i < n_coins; i++) {
        for (int j = coins[i]; j <= money; j++) {
            ways[j] += ways[j - coins[i]];
        }
    }
    
    return ways[money];
}