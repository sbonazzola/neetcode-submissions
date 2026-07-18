class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def hours(k):
            total_time = 0
            for i in range(len(piles)):
                total_time +=  -(-piles[i] // k)
            return total_time
        
        lo, hi = 1, max(piles)

        while (lo <= hi):
            mid = (lo+hi) //2

            if hours(mid) <= h:
                hi = mid-1
            else:
                lo = mid+1
        return lo
   
