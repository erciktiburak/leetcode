def is_palindrome(x)
    # Negative numbers are not palindromic
    return false if x < 0

    original_number = x
    reversed_number = 0

    while x > 0
        digit = x % 10
        reversed_number = reversed_number * 10 + digit
        x /= 10
    end

    original_number == reversed_number
end