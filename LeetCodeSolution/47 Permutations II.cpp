#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a collection of distinct integers, return all possible permutations.
*/

vector<vector<int>> result;


//backtrack
void permuteUniqueHelper(vector<int>& nums, vector<int>& chosen, vector<bool>& used) {
	if (chosen.size() == nums.size()) {
		result.push_back(chosen);
		return;
	}

	for (int i = 0; i < nums.size(); i++) {
		if (used[i] || (i > 0 && nums[i] == nums[i - 1] && used[i - 1])) continue;

		chosen.push_back(nums[i]);                      //choose    
		used[i] = true;

		permuteUniqueHelper(nums, chosen, used);          //explore

		chosen.pop_back();                                //unchoose
		used[i] = false;
	}

}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	vector<bool> used(nums.size(), false);

	vector<int> chosen;

	permuteUniqueHelper(nums, chosen, used);

	return result;
}