var searchRange = function(nums, target) {
    const result = [-1, -1];

    // Find the leftmost occurrence of target
    let leftIdx = binarySearch(nums, target, true);
    if (leftIdx === -1) {
        return result;
    }

    // Find the rightmost occurrence of target
    let rightIdx = binarySearch(nums, target, false);

    result[0] = leftIdx;
    result[1] = rightIdx;
    return result;
};

const binarySearch = (nums, target, left) => {
    let low = 0;
    let high = nums.length - 1;
    let result = -1;

    while (low <= high) {
        let mid = Math.floor(low + (high - low) / 2);
        if (nums[mid] === target) {
            result = mid;
            if (left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
};
