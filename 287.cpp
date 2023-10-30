#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int findDuplicate(vector<int> & nums)
{
	unordered_set<int> num;
	for (int i : nums) {
		if (num.find(i) != num.end()) {
			return i;
		}
		else num.insert(i);
	}
	return 0;
}
int findDuplicate1(vector<int>& nums)
{
	int left = 0;
	int right = nums.size() - 1;
	int ans = 0;
	while (right - left > 1) {
		int middle = left + ((right - left) >> 1);
		for (int i = 0; i < nums.size(); i++) {
			ans += (nums[i] <= middle);
		}
		if (ans <= middle)left = middle;
		else right = middle;
		ans = 0;
	}
	return right;
}

int findDuplicate2(vector<int> nums)
{
	int i = 0;
	int j = 0;
	do {
		i = nums[i];
		j = nums[nums[j]];

	} while (i != j);
	i = 0;
	while (i != j) {
		i = nums[i];
		j = nums[j];
	}
	return i;
}
