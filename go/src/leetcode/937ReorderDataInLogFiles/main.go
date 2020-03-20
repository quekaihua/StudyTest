package main

import "fmt"
import "strings"

func reorderLogFiles(logs []string) []string {
	for P := 1; P < len(logs); P++ {
		var Temp = logs[P]
		var i int
		for i = P; i > 0 && compare(logs[i-1], Temp) > 0; i-- {
			logs[i] = logs[i-1]
		}
		logs[i] = Temp
	}
	return logs
}

func compare(s string, t string) int {
	var index1, index2 = strings.Index(s, " "), strings.Index(t, " ")
	var value1, value2 = s[index1+1], t[index2+1]
	var ok1, ok2 = isDigit(value1), isDigit(value2)
	if ok1 && ok2 { //两个数字的情况 不换
		return -1
	} else if ok1 && !ok2 { //第一个数字始终
		return 1
	} else if !ok1 && ok2 {
		return -1
	} else if value1 < value2 {
		return -1
	} else if value1 == value2 {
		return compareLexi(s[index1+2:], t[index2+2:])
	} else {
		return 1
	}
}

func compareLexi(s string, t string) int {
	for i := 0; i < len(s) && i < len(t); i++ {
		if s[i] > t[i] {
			return 1
		} else if s[i] < t[i] {
			return -1
		}
	}
	return 1
}

func isDigit(v byte) bool {
	return v >= 48 && v <= 57
}

func main() {
	var logs = []string{
		"dig1 8 1 5 1",
		"let1 art can",
		"dig2 3 6",
		"let2 own kit dig",
		"let3 art zero",
	}
	logs = reorderLogFiles(logs)
	fmt.Println(logs)
}
