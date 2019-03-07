# Time Limit Exceed
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def all_perms(elements):
            if len(elements) <= 1:
                yield elements
            else:
                for perm in all_perms(elements[1:]):
                    for i in range(len(elements)):
                        # nb elements[0:1] works in both string and list contexts
                        yield perm[:i] + elements[0:1] + perm[i:]

        def isValid(s):  # from 020
            stack = []
            mapping = {")": "("}

            for char in s:
                if char in mapping:
                    if stack:
                        stack.pop()
                    else:
                        return False
                else:
                    stack.append(char)
            return not stack

        string = "()" * n
        perms = all_perms(string)
        str_list = []

        for j in perms:
            if isValid(j) and j not in str_list:
                str_list.append(j)

        return str_list


# use recursion function
class Solution2(object):
    def generateParenthesis(self, n):
        ans = []

        def backtrack(S='', left=0, right=0):
            if len(S) == 2 * n:
                ans.append(S)
                return
            if left < n:
                backtrack(S+'(', left+1, right)
            if right < left:
                backtrack(S+')', left, right+1)

        backtrack()
        return ans


if __name__ == "__main__":
    sol = Solution2()
    print(sol.generateParenthesis(6))
