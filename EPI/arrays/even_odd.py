from typing import List

from pprint import pprint

def partition_by_parity(nums: List[int]):
    left = 0
    right = len(nums)

    while left < right:
        while left < right and nums[left] % 2 == 0:
            left += 1
        
        while left < right and nums[right - 1] % 2:
            right -= 1
        
        if left < right:
            nums[left], nums[right - 1] = nums[right - 1], nums[left]
        
        left += 1
        right -= 1

    return nums


if __name__ == '__main__':
    pprint(partition_by_parity([1, 3, 5, 7, 6]))