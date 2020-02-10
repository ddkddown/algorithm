#!/usr/local/env python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        length = len(nums)
        i = 0
        j = 0
        count = 0
        while j < length:
            if nums[j] != val:
                nums[i] = nums[j]
                i = i + 1
                j = j + 1
                count = count + 1
            else:
                j = j + 1
        return count
