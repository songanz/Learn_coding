class Solution(object):
    def letterCombinations(self, digits):
        D = {'2': ['a', 'b', 'c'],
             '3': ['d', 'e', 'f'],
             '4': ['g', 'h', 'i'],
             '5': ['j', 'k', 'l'],
             '6': ['m', 'n', 'o'],
             '7': ['p', 'q', 'r', 's'],
             '8': ['t', 'u', 'v'],
             '9': ['w', 'x', 'y', 'z']}

        n = len(digits)

        if n == 0:
            return []

        strList = D[digits[0]].copy()
        total = len(strList)

        for i in range(1, n):
            m = len(strList)
            total *= len(D[digits[i]])
            for j in range(m):
                temp = strList[j]
                for k in D[digits[i]]:
                    strList.append(temp + k)

        return strList[-total:]


if __name__ == "__main__":
    s = Solution()
    print(s.letterCombinations("23"))
