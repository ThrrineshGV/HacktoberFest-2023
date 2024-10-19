package main

import (
	"fmt"
	"math"
	"strings"
)

/*
Problem Statement:
Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a subarray
whose sum is greater than or equal to `target`. If there is no such subarray, return 0 instead.
*/

func minSubArrayLen(target int, nums []int) int {
	// Initialize windowSize to a large number (MaxInt64)
	windowSize := math.MaxInt64

	// Initialize the start pointer of the sliding window and sum
	start, totalSum := 0, 0

	// Iterate over nums using the end pointer
	for end := 0; end < len(nums); end++ {
		totalSum += nums[end] // Add current element to the total sum

		// Shrink the window size while maintaining the sum >= target
		for totalSum >= target {
			// Calculate the current subarray length
			currSubArrSize := end - start + 1

			// Update windowSize to the minimum of itself and the current subarray size
			windowSize = min(windowSize, currSubArrSize)

			// Shrink the window from the start
			totalSum -= nums[start]
			start++
		}
	}

	// If we never found a valid subarray, return 0
	if windowSize == math.MaxInt64 {
		return 0
	}

	return windowSize
}

// Helper function to return the minimum of two integers
func min(v1 int, v2 int) int {
	if v1 < v2 {
		return v1
	}
	return v2
}

func main() {
	// Test cases
	targets := []int{
		7,
		4,
		11,
		10,
		5,
		15,
	}

	numsList := [][]int{
		{2, 3, 1, 2, 4, 3},
		{1, 4, 4},
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 3, 4},
		{1, 2, 1, 3},
		{5, 4, 9, 8, 11, 3, 7, 12, 15, 44},
	}

	// Loop through each test case
	for i, target := range targets {
		result := minSubArrayLen(target, numsList[i])

		// Print the result in a readable format
		fmt.Printf("%d.\tminSubArrayLen(%d, %s): %d\n", i+1, target,
			strings.Replace(fmt.Sprint(numsList[i]), " ", ", ", -1), result)
		fmt.Printf("%s\n", strings.Repeat("-", 100))
	}
}
