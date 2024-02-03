# @param {String} s
# @return {Integer}
def roman_to_int(s)
    # Create a hash to store the values of Roman numerals.
    roman_to_int_mapping = {
      'I' => 1,
      'V' => 5,
      'X' => 10,
      'L' => 50,
      'C' => 100,
      'D' => 500,
      'M' => 1000
    }
  
    # Initialize a variable to store the total value.
    total = 0
  
    # Iterate through Roman numerals from left to right.
    s.each_char.with_index do |numeral, index|
      # If the current numeral is smaller than the next one, subtraction rules apply.
      if index < s.length - 1 && roman_to_int_mapping[numeral] < roman_to_int_mapping[s[index + 1]]
        # According to the subtraction rule, subtract the value of the current numeral.
        total -= roman_to_int_mapping[numeral]
      else
        # Otherwise, simply add the value to the total.
        total += roman_to_int_mapping[numeral]
      end
    end
  
    # Return the result.
    total
  end
  
  # Example usage:
  puts roman_to_int("III")      # 3
  puts roman_to_int("LVIII")    # 58
  puts roman_to_int("MCMXCIV")  # 1994