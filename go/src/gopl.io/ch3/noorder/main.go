package main

import "fmt"

//NoOrderEqual compare "abcc"=="accb"
func NoOrderEqual(s1, s2 string) bool {
	r1, r2 := []rune(s1), []rune(s2)
	if len(r1) != len(r2) {
		return false
	}

	for i := 0; i < len(r1); i++ {
		flag := r1[i]
		found := false
		for j := 0; j < len(r2); j++ {
			fmt.Printf("flag=%d, r2[j]=%d\n", flag, r2[j])
			if r2[j] == flag {
				// r2 = r2[:j] + r2[j+1:]
				r2 = append(r2[:j], r2[j+1:]...)
				found = true
				break
			}
		}
		fmt.Printf("r1=%s, r2=%s\n", string(r1), string(r2))
		if !found {
			return false
		}
	}

	return true
}

func main() {
	s1 := "我是中国人"
	s2 := "中国人是我"
	fmt.Println(NoOrderEqual(s1, s2))
	fmt.Printf("s1=%s, s2=%s\n", s1, s2)
	//fmt.Println(NoOrderEqual("abccdd", "bccda"))
	//fmt.Println(NoOrderEqual("abccdd", "bccdaa"))
}
