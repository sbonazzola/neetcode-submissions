class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
       
        length = len(nums)
        new_length = 2 * len(nums)
        arr = [0] * new_length
        for i in range(0,length -1):
            arr[i] = nums[i]
        for i in range(length, new_length -1):
            arr[i] = nums[i]
        
        return(arr)
