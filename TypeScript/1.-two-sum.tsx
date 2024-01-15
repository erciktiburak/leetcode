function twoSum(nums: number[], target: number): number[] | null {
    const numMap: Map<number, number> = new Map();

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];

        // Check if the complement is already in the map
        if (numMap.has(complement)) {
            return [numMap.get(complement)!, i];
        }

        // Add the current number and its index to the map
        numMap.set(nums[i], i);
    }

    // If no solution is found
    return null;
}

// Example:
const nums1: number[] = [2, 7, 11, 15];
const target1: number = 9;
console.log(twoSum(nums1, target1));  // output: [0, 1]

const nums2: number[] = [3, 2, 4];
const target2: number = 6;
console.log(twoSum(nums2, target2));  // output: [1, 2]

const nums3: number[] = [3, 3];
const target3: number = 6;
console.log(twoSum(nums3, target3));  // output: [0, 1]
