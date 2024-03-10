func merge(nums1 []int, m int, nums2 []int, n int) {
    i := m - 1 // Pointer for nums1
    j := n - 1 // Pointer for nums2
    k := m + n - 1 // Pointer for the merged array

    // Merge nums1 and nums2, starting from the end of each array
    for i >= 0 && j >= 0 {
        if nums1[i] > nums2[j] {
            nums1[k] = nums1[i]
            i--
        } else {
            nums1[k] = nums2[j]
            j--
        }
        k--
    }

    // Copy any remaining elements from nums2 to nums1
    for j >= 0 {
        nums1[k] = nums2[j]
        j--
        k--
    }
}
