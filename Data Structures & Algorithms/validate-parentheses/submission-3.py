class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        open_type = ['(', '{', '[']
        close_type = [')', '}', ']']

        for ch in s:
            if ch in open_type:
                stack.append(ch)
            else:
                if not stack:
                    return False
                x = stack[-1]
                y = close_type.index(ch)
                if open_type.index(x) == y:
                    stack.pop()
                else:
                    return False

        return len(stack) == 0
