package main

import (
	"fmt"
)

func isPalindrome(x int) bool {
	// Negative numbers are not palindromic
	if x < 0 {
		return false
	}

	originalNumber := x
	reversedNumber := 0

	for x > 0 {
		// Extract the last digit of the number
		digit := x % 10

		// Reverse the number by adding one digit at a time
		reversedNumber = reversedNumber*10 + digit

		// Remove the rightmost digit from the number
		x /= 10
	}

	// Check if the reversed number is equal to the original number
	return originalNumber == reversedNumber
}

func main() {
	// Example usage
	fmt.Println(isPalindrome(121))  // true
	fmt.Println(isPalindrome(-121)) // false
	fmt.Println(isPalindrome(10))   // false
}