package main

import "fmt"

func romanToInt(s string) int {
	// Roman numerals are represented by a map.
	romanToIntMapping := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	// Initialize a variable to store the total value.
	total := 0

	// Iterate through Roman numerals from left to right.
	for i := 0; i < len(s); i++ {
		// If the current numeral is smaller than the next one, subtraction rules apply.
		if i < len(s)-1 && romanToIntMapping[s[i]] < romanToIntMapping[s[i+1]] {
			// According to the subtraction rule, subtract the value of the current numeral.
			total -= romanToIntMapping[s[i]]
		} else {
			// Otherwise, simply add the value to the total.
			total += romanToIntMapping[s[i]]
		}
	}

	// Return the result.
	return total
}

func main() {
	// Example usage:
	fmt.Println(romanToInt("III"))      // 3
	fmt.Println(romanToInt("LVIII"))    // 58
	fmt.Println(romanToInt("MCMXCIV"))  // 1994
}