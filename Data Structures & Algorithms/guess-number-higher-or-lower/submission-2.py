# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        lo = 1
        hi = n
        
        if guess(n) == 0:
                return n

        
        while (lo <= hi):
            num = (lo + hi) // 2
            result = guess(num)
            if result == 0:
                return num
            
            elif result == -1:
                hi = num -1
            elif result == 1:
                lo = num+1         