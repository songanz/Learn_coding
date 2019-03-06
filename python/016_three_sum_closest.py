class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        temp = 1e100
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                for k in range(j+1, len(nums)):
                    if abs(nums[i] + nums[j] + nums[k] - target) < temp:
                        temp = abs(nums[i] + nums[j] + nums[k] - target)
                        score = nums[i] + nums[j] + nums[k]
        return score


class Solution2(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        score = sum(nums[:3])
        if len(nums) == 3:
            return score

        for i in range(len(nums)-1):
            j, k = i+1, len(nums)-1
            while j < k:
                temp = nums[i] + nums[j] + nums[k]
                if abs(temp - target) < abs(score - target):
                    score = temp
                if temp <= target:
                    j += 1
                elif temp > target:
                    k -= 1
        return score


if __name__ == '__main__':
    s = Solution()
    print(s.threeSumClosest([-1, 2, 1, -4], 1))
