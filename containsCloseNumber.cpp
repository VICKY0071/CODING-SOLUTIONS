// link : https://app.codesignal.com/challenge/x7heKGPZsaR3oKrc3

bool containsCloseNums(std::vector<int> nums, int k) {
    unordered_map<int, vector<int>> a;
    for(int i = 0;i<nums.size();i++){
        if(a.find(nums[i]) != a.end()){
            vector<int> values = a[nums[i]];
            for(int index : values){
                if(abs(index - i) <= k){
                    return true;
                }
            }
        }
        a[nums[i]].push_back(i);
    }
    return false;
}
