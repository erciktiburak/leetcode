public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.Length;
        int n2 = nums2.Length;
        int[] merged = new int[n1 + n2];
        
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                merged[k++] = nums1[i++];
            } else {
                merged[k++] = nums2[j++];
            }
        }
        
        while (i < n1) {
            merged[k++] = nums1[i++];
        }
        
        while (j < n2) {
            merged[k++] = nums2[j++];
        }
        
        if ((n1 + n2) % 2 == 0) {
            return (double)(merged[(n1 + n2) / 2 - 1] + merged[(n1 + n2) / 2]) / 2;
        } else {
            return (double)merged[(n1 + n2) / 2];
        }
    }
}
