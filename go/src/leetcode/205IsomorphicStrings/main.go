package main

import "fmt"

func isIsomorphic(s string, t string) bool {
	var ss = make(map[byte]byte)
	var sss = make(map[byte]byte)

	for i := 0; i < len(s); i++ {
		var a, b = s[i], t[i]
		// fmt.Println(string(a), string(b))
		if value1, ok := ss[a]; !ok {
			ss[a] = b
		} else if value1 != b {
			return false
		}

		if value2, ok := sss[b]; !ok {
			sss[b] = a
		} else if value2 != a {
			return false
		}
	}

	return true
}

func main() {
	var b bool
	b = isIsomorphic("agag", "bddd")
	fmt.Printf("%v", b)
}
