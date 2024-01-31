function isPalindrome(x: number): boolean {
    // Negative numbers are not palindromic
    if (x < 0) {
        return false;
    }

    const originalNumber: number = x;
    let reversedNumber: number = 0;

    while (x > 0) {
        // Extract the last digit of the number
        const digit: number = x % 10;

        // Reverse the number by adding one digit at a time
        reversedNumber = reversedNumber * 10 + digit;

        // Remove the rightmost digit from the number
        x = Math.floor(x / 10);
    }

    // Check if the reversed number is equal to the original number
    return originalNumber === reversedNumber;
}

// Example usage
console.log(isPalindrome(121));  // true
console.log(isPalindrome(-121)); // false
console.log(isPalindrome(10));    // false