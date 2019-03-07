class Solution:
    def fourSum(self, nums, target):
        def threeSum(left, left_targ):
            left_result = []
            for a in range(len(left)):
                b, c = a+1, len(left)-1
                while b < c:
                    if left[a] + left[b] + left[c] < left_targ:
                        b += 1
                    elif left[a] + left[b] + left[c] > left_targ:
                        c -= 1
                    else:
                        if [left[a], left[b], left[c]] not in left_result:
                            left_result.append([left[a], left[b], left[c]])
                        b += 1
            return left_result

        nums.sort()
        if len(nums) < 4:
            return []

        result = []

        for u in range(len(nums)):
            left_input = nums[u+1:]
            left_target = target - nums[u]
            left_result_list = threeSum(left_input, left_target)
            for li in left_result_list:
                if [nums[u]] + li not in result:
                    result.append([nums[u]] + li)

        return result


if __name__ == "__main__":
    s = Solution()
    nums = [1, 0, -1, 0, -2, 2]
    nums2 = [1, 2, 3, 4]
    target = 0
    print(s.fourSum(nums, target))
