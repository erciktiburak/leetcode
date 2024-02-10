/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 0) {
        return "";
    }

    // Sort the array of strings
    strs.sort();

    // Take the first and last strings after sorting
    let first = strs[0];
    let last = strs[strs.length - 1];

    // Find the common prefix between the first and last strings
    let commonPrefix = "";
    for (let i = 0; i < first.length && i < last.length; i++) {
        if (first[i] === last[i]) {
            commonPrefix += first[i];
        } else {
            break;
        }
    }

    return commonPrefix;
};

// Example usage:
let strs1 = ["flower", "flow", "flight"];
let result1 = longestCommonPrefix(strs1);
console.log("Longest Common Prefix 1:", result1);

let strs2 = ["dog", "racecar", "car"];
let result2 = longestCommonPrefix(strs2);
console.log("Longest Common Prefix 2:", result2);