class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        k = len(nums) - k 

        def quickselect(l, r):
            pivot = nums[random.randint(l, r)]
            i, j = l, r
            while i <= j:
                while nums[i] < pivot:
                    i += 1
                while nums[j] > pivot:
                    j -= 1
                if i <= j:
                    nums[i], nums[j] = nums[j], nums[i]
                    i, j = i + 1, j - 1

            if k <= j:
                return quickselect(l, j)
            elif k >= i:
                return quickselect(i, r)
            else:
                return nums[k]

        return quickselect(0, len(nums) - 1)