class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = []
        for a in range(len(nums)):
            b, c = a+1, len(nums)-1
            while b < c:
                if nums[a] + nums[b] + nums[c] < 0:
                    b += 1
                elif nums[a] + nums[b] + nums[c] > 0:
                    c -= 1
                else:
                    if [nums[a], nums[b], nums[c]] not in result:
                        result.append([nums[a], nums[b], nums[c]])
                    b += 1
        return result


if __name__ == "__main__":
    num_list = [-1, 0, 1, 2, -1, -4]
    s = Solution()
    print(s.threeSum(num_list))
