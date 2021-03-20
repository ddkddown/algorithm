package main

// 双指针思想
func removeDuplicates(nums []int) int {
	l := len(nums)
	if 0 == l {
		return 0
	}

	var i int = 0
	for j := 1; j < l; j++ {
		if nums[j] != nums[i] {
			i++
			nums[i] = nums[j]
		}
	}

	return i + 1
}
