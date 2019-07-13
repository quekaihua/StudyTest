package main

import (
	"fmt"
	"strings"
)

func comma(s string) string {
	n := len(s)
	if n <= 3 {
		return s
	}
	return comma(s[:n-3]) + "," + s[n-3:]
}

func commaFor(s string) string {
	sep := strings.LastIndex(s, ".")
	var integer, decimals string
	if sep > 0 {
		integer, decimals = s[:sep], s[sep:]
	} else {
		integer = s
	}
	r := integer
	count := 0
	for i := len(integer) - 1; i > 0; i-- {
		count++
		if count%3 == 0 {
			r = r[:i] + "," + r[i:]
			count = 0
		}
	}
	return r + decimals
}

func main() {
	fmt.Println(commaFor("123456789"))
	fmt.Println(commaFor("123"))
	fmt.Println(commaFor("12342324324243245.3434344"))
}
