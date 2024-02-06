package main

import (
	"fmt"
	"sort"
)

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	// Sort the slice of strings
	sort.Strings(strs)

	// Take the first and last strings after sorting
	first := strs[0]
	last := strs[len(strs)-1]

	// Find the common prefix between the first and last strings
	commonPrefixLength := 0
	minLength := min(len(first), len(last))
	for i := 0; i < minLength; i++ {
		if first[i] == last[i] {
			commonPrefixLength++
		} else {
			break
		}
	}

	// Return the common prefix
	return first[:commonPrefixLength]
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	strs := []string{"flower", "flow", "flight"}
	result := longestCommonPrefix(strs)
	fmt.Println("Longest Common Prefix:", result)
}