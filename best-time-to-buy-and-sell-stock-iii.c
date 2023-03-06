#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
int maxProfit(int* prices, int pricesSize) {
    int price_1 = prices[0], price_2 = prices[0], profit_1 = 0, profit_2 = 0;
    for (int i = 1; i < pricesSize; i++) {
        price_1 = min(price_1, prices[i]);
        profit_1 = max(profit_1, prices[i] - price_1);
        price_2 = min(price_2, prices[i] - profit_1);
        profit_2 = max(profit_2, prices[i] - price_2);
    };
    return profit_2;
}