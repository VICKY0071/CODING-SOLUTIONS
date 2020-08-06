//link to question : https://app.codesignal.com/challenge/3WnyDCQcP7az5mjSH/comments/am7uqhCmRRLx3iHET

nt sumInRange(std::vector<int> nums, std::vector<std::vector<int>> queries) {
    typedef long long ll;
    const int MOD = 1e9 + 7;
    vector<ll> cum_sum;
    cum_sum.push_back(nums[0]);
    for(int i = 1;i<nums.size();i++){
        cum_sum.push_back(cum_sum[i - 1] + nums[i]);
    }
    
    int result = 0;
    ll val;
    for(vector<int> a : queries){
        if(a[0] == a[1])    val = nums[a[0]];
        else if(a[0] == 0)   val = cum_sum[a[1]];
        else    val = cum_sum[a[1]] - cum_sum[a[0] - 1];
        result = ((result % MOD) + val % MOD) % MOD; 
    }
    return (result < 0) ? ((result + MOD) % MOD) : (result % MOD);
}
