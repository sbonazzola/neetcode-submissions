class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
     
        m = len(matrix)
        n = len(matrix[0])
        
        lo, hi = 0, n*m -1

        while lo <= hi:
            mid = (lo + hi)//2

            row = mid //n
            col = mid % n

            if target > matrix[row][col]:
                lo = mid +1
            elif target < matrix[row][col]:
                hi = mid - 1
            else:
                return True
        
        return False

