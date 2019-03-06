import collections


class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        def isAnagrams(s, t):
            if len(s) != len(t):
                return False
            return sorted(s) == sorted(t)

        if len(strs) <= 1:
            return strs

        # Use collection to save different groups
        result = collections.defaultdict(list)
        # result = {}

        for i in strs:
            result[tuple(sorted(i))].append(i)

        return result.values()


if __name__ == "__main__":
    s = Solution()
    print(s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
