package main

import "fmt"

func numJewelsInStones(J string, S string) int {
	var count = make(map[byte]int, 52)
	for i := 0; i < len(S); i++ {
		count[S[i]]++
	}
	var ret int
	for i := 0; i < len(J); i++ {
		ret += count[J[i]]
	}
	return ret
}

func main() {
	fmt.Println(numJewelsInStones("z", "ZZ"))
}
