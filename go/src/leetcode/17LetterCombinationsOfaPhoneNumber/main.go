package main

import (
	"fmt"
	"strconv"
)

func letterCombinations(digits string) []string {

	letters := [...]string{
		"", "",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"}

	var res []string
	for _, v := range digits {
		var temp []string
		number, _ := strconv.Atoi(string(v))
		for _, t := range letters[number] {
			s := string([]rune{t})
			temp = append(temp, s)
		}
		if res == nil {
			res = temp
		} else {
			var out []string
			for _, r := range res {
				for _, t := range temp {
					s := r + t
					out = append(out, s)
				}
			}
			res = out
		}
	}

	return res
}

func main() {
	res := letterCombinations("2")
	fmt.Println(res)
}
