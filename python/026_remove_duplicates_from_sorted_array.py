class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums == []:
            return 0

        i = 0
        while i < len(nums) - 1:
            if nums[i] == nums[i + 1]:
                nums.pop(i)
            else:
                i += 1

        return i + 1


if __name__ == "__main__":
    s = Solution()
    nums = [1, 1, 2]
    print(s.removeDuplicates(nums))
