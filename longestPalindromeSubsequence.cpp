int longestSubsequencePalindrome(std::vector<int> a) {
    if(a.size() <= 1)   return a.size();
    vector<vector<int>> dp(a.size() , vector<int>(a.size(), 0));
    for(int i = 0;i<a.size();i++){
        dp[i][i] = 1;
    }
    int result = INT_MIN;
    
    for(int l = 2;l<=a.size();l++){
        for(int i = 0;i<a.size() - l + 1;i++){
            int j = i + l - 1;
            if(l == 2 && a[i] == a[j])  dp[i][j] = 2;
            else if(a[i] == a[j])   dp[i][j] = 2 + dp[i + 1][j - 1];
            else    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            result = max(result, dp[i][j]);
        }
    }
    return result;
}
