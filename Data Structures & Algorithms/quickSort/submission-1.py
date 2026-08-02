# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def quickSort(self, pairs: List[Pair]) -> List[Pair]:
        # call helper function
        self.quickSortHelper(pairs, 0, len(pairs)-1)
        return pairs
    
    def quickSortHelper(self, arr: List[Pair], start: int, end: int) -> None:

        if end - start + 1 <= 1:
            return
        
        if start >= end:
            return
        
        # partition elements smaller than the pivot on the left side
        

        pivot = end
        left = start

        for i in range(end):
            if arr[i].key <= arr[pivot].key:
                arr[i], arr[left] = arr[left], arr[i]
                left += 1

        #place pivto correctly
        arr[end], arr[left]=arr[left], arr[end]
        self.quickSortHelper(arr, start, left-1)
        self.quickSortHelper(arr, left+1, end)


        
        