package main

func majorityElement(nums []int) int {
	candidate := nums[0]
	count := 1
	l := len(nums)

	for i := 1; i < l; i++ {
		if candidate == nums[i] {
			count++
		} else {
			count--
			if count <= 0 {
				candidate = nums[i]
				count = 1
			}
		}
	}

	return candidate
}
