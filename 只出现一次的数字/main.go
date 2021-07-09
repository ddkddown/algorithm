package main

func singleNumber(nums []int) int {
	ret := 0
	for _, ele := range nums {
		ret ^= ele
	}

	return ret
}

func kthToLast(head *ListNode, k int) int {
    l := 0
    var tmp []int
    for head != nil {
        l++
        tmp := append(tmp, head->Val)
		head = head->Next
    }

    l -= k
    return tmp[l]

}