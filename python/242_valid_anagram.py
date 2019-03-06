import collections


class Solution(object):
    def isAnagram(self, s, t):
        return collections.Counter(s) == collections.Counter(t)


class Solution2(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        return sorted(s) == sorted(t)


if __name__ == "__main__":
    s = Solution()
    print(s.isAnagram("anagram", "nagaram"))
