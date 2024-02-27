/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function(s1, s2) {
    const count = new Map();
    
    // Split the sentences into words
    const words1 = s1.split(' ');
    const words2 = s2.split(' ');
    
    // Count the frequency of words in s1
    words1.forEach(word => {
        count.set(word, (count.get(word) || 0) + 1);
    });
    
    // Count the frequency of words in s2
    words2.forEach(word => {
        count.set(word, (count.get(word) || 0) + 1);
    });
    
    // Collect uncommon words
    const uncommonWords = [];
    count.forEach((value, key) => {
        if (value === 1) {
            uncommonWords.push(key);
        }
    });
    
    return uncommonWords;
};

// Example usage
const s1 = "this apple is sweet";
const s2 = "this apple is sour";
console.log(uncommonFromSentences(s1, s2)); // Output: ["sweet", "sour"]

const s3 = "apple apple";
const s4 = "banana";
console.log(uncommonFromSentences(s3, s4)); // Output: ["banana"]