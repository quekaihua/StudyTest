package main

func rangeBitwiseAnd(m int, n int) int {
	var ret = m
	for i := m + 1; i <= n; i++ {
		ret = ret & i
	}
	return ret
}
