package main

func hammingWeight(num uint32) int {
	var count int = 0

	for ; num > 0; num = num >> 1 {
		if (num & 1) > 0 {
			count++
		}
	}

	return count
}
