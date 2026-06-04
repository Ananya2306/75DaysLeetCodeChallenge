class Solution:
    def rob(self, nums: List[int]) -> int:
        if not nums: return 0
        prev, curr = 0, 0
        for val in nums:
            prev, curr = curr, max(curr, prev + val)
        return curr