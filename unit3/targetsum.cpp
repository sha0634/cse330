//link https://www.geeksforgeeks.org/problems/champagne-overflow2636/1
class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        // code here
        vector<vector<vector<double>>> dp;
        dp.push_back({{1,K-1}});
        for(int i=1;i<R;i++){
            vector<vector<double>> v;
            for(int j=0;j<=i;j++){
                double quant= (j-1>=0)?dp[i-1][j-1][1]/2.0:0;
                quant= (j<dp[i-1].size())? quant+dp[i-1][j][1]/2.0:quant;
                if(quant>1) v.push_back({1.0,quant-1.0});
                else v.push_back({quant,0});
            }
            dp.push_back(v);
        }
        return dp[R-1][C-1][0];
    }
};