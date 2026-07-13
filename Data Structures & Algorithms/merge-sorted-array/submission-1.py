class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        del nums1[m:]

        for j in range(n):
            inserted = False
            for i in range(len(nums1)):
                if nums2[j] <= nums1[i]:
                    nums1.insert(i, nums2[j])
                    inserted = True
                    break
            if inserted == False:
                nums1.append(nums2[j])

        
