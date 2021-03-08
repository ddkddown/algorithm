package main

func kidsWithCandies(candies []int, extraCandies int) []bool {
	ret := make([]bool, 0)
	max := candies[0]

	for i := 1; i < len(candies); i++ {
		if candies[i] > max {
			max = candies[i]
		}
	}

	for i := 0; i < len(candies); i++ {
		if (candies[i] + extraCandies) >= max {
			ret = append(ret, true)
		} else {
			ret = append(ret, false)
		}
	}

	return ret
}
