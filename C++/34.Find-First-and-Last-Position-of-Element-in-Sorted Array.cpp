class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};

        // Find the leftmost occurrence of target
        int leftIdx = binarySearch(nums, target, true);
        if (leftIdx == -1) {
            return result;
        }

        // Find the rightmost occurrence of target
        int rightIdx = binarySearch(nums, target, false);

        result[0] = leftIdx;
        result[1] = rightIdx;
        return result;
    }

    int binarySearch(vector<int>& nums, int target, bool left) {
        int low = 0;
        int high = nums.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
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
    }
};
