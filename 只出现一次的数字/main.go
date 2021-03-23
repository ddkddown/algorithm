package main

func singleNumber(nums []int) int {
	ret := 0
	for _, ele := range nums {
		ret ^= ele
	}

	return ret
}
