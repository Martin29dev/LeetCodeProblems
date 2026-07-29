#include <iostream>
#include <vector>
using namespace std;

// You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

// moje rozwiązanie
// 2 petla wszystko ze wszyskim trzeba sprawdzic
// sprawdzilem na leetcode, poszedl accept
vector<int> twoSum(vector<int> &nums, int target)
{
	int sum = 0;
	for(int i = 0; i < nums.size(); i++)
	{
		for(int j = 0; j < nums.size(); j++)
		{
			if(i == j)
				continue;

			sum = nums[i] + nums[j];
			if(sum == target)
			{
				// te 2 couty to do testow
				cout << i << endl;
				cout << j << endl;
				return {i, j};
			}
		}
	}
	// return empty vector if no solution was found
	return {};
}

int main() 
{
	vector<int> nums = {3, 2, 3};
	twoSum(nums, 6);
	//cout << twoSum(nums, 9) << endl;
	return 0;
}

// 1 2 3 4 5 6 7 8 9


// w wypadku 3 2 3 1 to rzeba 3 z 2, 3 z 3, 3 z 1, potem 2 z 3, 2 z 1, potem 3 z 1