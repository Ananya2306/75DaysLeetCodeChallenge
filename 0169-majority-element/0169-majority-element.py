class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count_dict = {}
        for num in nums:
            count_dict[num] = count_dict.get(num, 0) + 1
            if count_dict[num] > len(nums) // 2:
                return num