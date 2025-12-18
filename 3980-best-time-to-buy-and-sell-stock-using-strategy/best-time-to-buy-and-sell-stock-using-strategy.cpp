class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int m = strategy.size();
        vector<long long>prefixPrice(n+1,0);
        vector<long long>prefixProfit(n+1,0);

        for(int i=0;i<n;i++){
            prefixPrice[i+1] = prefixPrice[i]+prices[i];
            prefixProfit[i+1] = prefixProfit[i] + 1LL * strategy[i] * prices[i];
        }
        long long baseProfit = prefixProfit[n];
        long long gain = 0;
        for(int j=0;j+k<=n;j++){
            long long block = prefixPrice[j+k]-prefixPrice[j+k/2];
            long long old = prefixProfit[j+k]-prefixProfit[j];
            long long g = block - old;
            gain = max(gain,g);
        }
        return baseProfit + gain;
        
    }
};