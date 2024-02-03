/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    // Roman numerals are represented by an object.
    const romanToIntMapping = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };

    // Initialize a variable to store the total value.
    let total = 0;

    // Iterate through Roman numerals from left to right.
    for (let i = 0; i < s.length; i++) {
        // If the current numeral is smaller than the next one, subtraction rules apply.
        if (i < s.length - 1 && romanToIntMapping[s[i]] < romanToIntMapping[s[i + 1]]) {
            // According to the subtraction rule, subtract the value of the current numeral.
            total -= romanToIntMapping[s[i]];
        } else {
            // Otherwise, simply add the value to the total.
            total += romanToIntMapping[s[i]];
        }
    }

    // Return the result.
    return total;
};

// Example usage:
console.log(romanToInt("III"));      // 3
console.log(romanToInt("LVIII"));    // 58
console.log(romanToInt("MCMXCIV"));  // 1994