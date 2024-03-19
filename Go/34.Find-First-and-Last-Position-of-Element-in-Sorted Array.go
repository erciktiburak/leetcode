func searchRange(nums []int, target int) []int {
    result := []int{-1, -1}

    // Find the leftmost occurrence of target
    leftIdx := binarySearch(nums, target, true)
    if leftIdx == -1 {
        return result
    }

    // Find the rightmost occurrence of target
    rightIdx := binarySearch(nums, target, false)

    result[0] = leftIdx
    result[1] = rightIdx
    return result
}

func binarySearch(nums []int, target int, left bool) int {
    low := 0
    high := len(nums) - 1
    result := -1

    for low <= high {
        mid := low + (high - low) / 2
        if nums[mid] == target {
            result = mid
            if left {
                high = mid - 1
            } else {
                low = mid + 1
            }
        } else if nums[mid] < target {
            low = mid + 1
        } else {
            high = mid - 1
        }
    }

    return result
}
