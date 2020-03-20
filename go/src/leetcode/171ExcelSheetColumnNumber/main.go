package main

import (
	"fmt"
	"math"
)

func titleToNumber(s string) int {
	var pow, res float64
	for i := len(s) - 1; i >= 0; i-- {
		t := (int)(s[i])
		res += float64(t-64) * math.Pow(float64(26), pow)
		pow++
	}
	return int(res)
}

func main() {
	fmt.Println(titleToNumber("ZY"))
}
