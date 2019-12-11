package main

import (
	"fmt"
	"os"
	"time"
)

func lanch() {
	fmt.Println("Lanch...")
}

func main() {
	fmt.Println("Commencing countdown.")

	abort := make(chan struct{})
	go func() {
		os.Stdin.Read(make([]byte, 1))
		abort <- struct{}{}
	}()

	// tick := time.Tick(1 * time.Second)
	// for countdown := 10; countdown > 0; countdown-- {
	// 	fmt.Println(countdown)
	// 	<-tick
	// }

	select {
	case <-time.After(10 * time.Second):

	case <-abort:
		fmt.Println("Lanuch aborted!")
		return
	}

	lanch()
}
