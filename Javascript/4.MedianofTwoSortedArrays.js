var findMedianSortedArrays = function(nums1, nums2) {
    const merged = [];
    let i = 0, j = 0;
    
    while (i < nums1.length && j < nums2.length) {
        if (nums1[i] < nums2[j]) {
            merged.push(nums1[i]);
            i++;
        } else {
            merged.push(nums2[j]);
            j++;
        }
    }
    
    while (i < nums1.length) {
        merged.push(nums1[i]);
        i++;
    }
    
    while (j < nums2.length) {
        merged.push(nums2[j]);
        j++;
    }
    
    const totalLength = merged.length;
    if (totalLength % 2 === 0) {
        return (merged[totalLength / 2 - 1] + merged[totalLength / 2]) / 2;
    } else {
        return merged[Math.floor(totalLength / 2)];
    }
};

// Example usage
const nums1 = [1, 3];
const nums2 = [2];
console.log(findMedianSortedArrays(nums1, nums2));  // Output: 2.0

const nums3 = [1, 2];
const nums4 = [3, 4];
console.log(findMedianSortedArrays(nums3, nums4));  // Output: 2.5
