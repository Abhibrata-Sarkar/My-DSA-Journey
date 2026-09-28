class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        mpp = {}

        for i in range(n):
            complement = target - nums[i]
            if complement in mpp:
                return [mpp[complement], i]
            mpp[nums[i]] = i

        return []