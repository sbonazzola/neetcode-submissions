class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        red =0
        white = 0
        blue = 0

        for i in range(len(nums)):
            if nums[i] == 0:
                red += 1
            elif nums[i] == 1:
                white +=1
            elif nums[i] == 2:
                blue +=1
        
        nums.clear()

        nums += [0] * red
        nums += [1] * white
        nums += [2] * blue
        