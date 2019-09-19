class Solution(object):
    def toLowerCase(self, st):
        """
        :type str: str
        :rtype: str
        """
        new_s = ''
        for i, s in enumerate(st):
            if s.isupper():
                new_s += s.lower()
                continue
            new_s += s
        return new_s


if __name__ == "__main__":
    st = "Hello"
    ss = Solution()
    print(ss.toLowerCase(st))
