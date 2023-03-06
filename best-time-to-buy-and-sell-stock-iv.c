#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
int maxProfit(int k, int* prices, int pricesSize) {
    int price[k], profit[k];
    for (int i = 0; i < k; i++) {
        price[i] = prices[0];
        profit[i] = 0;
    }
    for (int i = 1; i < pricesSize; i++) {
        for (int j = 0; j < k; j++) {
            price[j] = min(price[j], prices[i] - (j <= 0 ? 0 : profit[j-1]));
            profit[j] = max(profit[j], prices[i] - price[j]);
        }
    }
    return profit[k-1];
}