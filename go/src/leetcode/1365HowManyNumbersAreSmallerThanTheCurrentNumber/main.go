package main

import (
	"fmt"
	"sort"
)

func smallerNumbersThanCurrent(nums []int) []int {
	var orgin = make([]int, len(nums))
	copy(orgin, nums)
	sort.Ints(nums)
	// fmt.Println(orgin)
	// fmt.Println(nums)
	var ret = []int{}
	var index int
	for _, v := range orgin {
		index = sort.SearchInts(nums, v)
		// fmt.Printf("v=%d, index=%d\n", v, index)
		ret = append(ret, index)
	}
	return ret
}

func main() {
	nums := []int{
		8, 1, 2, 2, 3,
	}
	fmt.Println(smallerNumbersThanCurrent(nums))
}
