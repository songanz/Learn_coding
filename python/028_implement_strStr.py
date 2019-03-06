class Solution(object):
    def strStr(self, sourse, target):
        if len(target) == 0 or sourse == target:
            return 0
        
        for i in range(len(sourse)-len(target)+1):
            for j in range(len(target)):
                if sourse[i+j] != target[j]:
                    break
            else:  # No break
                return i
        return -1


if __name__ == '__main__':
    s = Solution()
    print(s.strStr("hello", "ll"))
    print(s.strStr("", ""))
    print(s.strStr("a", "a"))
    print(s.strStr("mississippi","pi"))