package main

func RunningSum(nums []int) []int {
    l := len(nums)
    for i:=1; i<l; i++ {
    	nums[i] += nums[i-1]
    }

    return nums
}
