class Solution {

private:
    void func(int ind, int sum, vector<int>& ans, vector<vector<int>>& res, int k, int n) {
        //base case
        if(sum == n && ans.size() == k) {
            res.push_back(ans);
            return;
        }

        for(int  i= ind; i  <= 9; i++) {
            if(sum + i > n || ans.size() == k) break;
                ans.push_back(i);
                func(i + 1, sum + i, ans, res, k, n);
                ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
            vector<int> ans;
            vector<vector<int>> res;
            func(1, 0, ans, res, k, n);
            return res;
    }
};