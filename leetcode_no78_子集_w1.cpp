/* ------------------------------------------------------------------|
给你一个整数数组 nums ，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。

 
示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	递归法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(const int& curr, vector<int>& nums,vector<vector<int>> &res,vector<int> &ans) {
    if (curr == nums.size()) {
        res.emplace_back(ans);
        return;
    }
    ans.emplace_back(nums[curr]);
    dfs(curr + 1, nums, res, ans);
    ans.pop_back();
    dfs(curr + 1, nums, res, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> ans;
    dfs(0, nums, res, ans);
    return res;
}

int main() {
    vector<int> nums = { 1,2,3 };
    subsets(nums);
}