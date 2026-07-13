class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
       
        length = len(nums)
        new_length = 2 * len(nums)
        arr = [0] * new_length
       
        for i in range(length):
            arr[i] = nums[i]
            arr[i + length] = nums[i]

        
        return(arr)
