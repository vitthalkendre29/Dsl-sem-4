class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
            res=nums1+nums2
            count=0
            for i in res:
                count=i+count
            med=count/(len(res))
            formatted_number = f"{med:.5f}"
            print((formatted_number))

nums1 = [1,3]
nums2 = [2]

vk=Solution()
vk.findMedianSortedArrays(nums1,nums2)