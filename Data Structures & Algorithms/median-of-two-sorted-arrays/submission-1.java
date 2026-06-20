class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length;
        int n2 = nums2.length;
        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }

        int start = 0;
        int end = n1;
        int totalElements = (n1 + n2 + 1) / 2;              // +1 coz if n1+n2 is odd then in left side size > right side size
        
        while(start <= end){
            int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE,
            r1 = Integer.MAX_VALUE, r2 = Integer.MAX_VALUE;
            int mid1 = start + (end - start) / 2;
            int mid2 = totalElements - mid1;
            
            if(mid1 - 1 >= 0)    l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0)    l2 = nums2[mid2 - 1];
            if(mid1 < n1)    r1 = nums1[mid1];
            if(mid2 < n2)    r2 = nums2[mid2];

            if(l1 <= r2 && l2 <= r1){
                if((n1 + n2) % 2 != 0)  return Math.max(l1,l2);
                else    return (double)(Math.max(l1, l2) + Math.min(r1, r2)) / 2;
            } else if(l1 > r2){
                end = mid1 - 1;
            } else {
                start = mid1 + 1;
            }
        }

        return -1;

    }
}
