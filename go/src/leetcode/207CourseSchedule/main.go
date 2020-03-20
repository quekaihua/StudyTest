package main

import "fmt"

func canFinish(numCourses int, prerequisites [][]int) bool {
	var queue, degree = make([]int, numCourses), make([]int, numCourses)
	var temp = make([]int, 2)
	// var graph [100][100]int
	graph := make([][]int, numCourses)
	for i := 0; i < numCourses; i++ {
		graph[i] = make([]int, numCourses)
	}
	for i := 0; i < numCourses; i++ {
		for j := 0; j < numCourses; j++ {
			graph[i] = append(graph[i], 0)
		}
	}
	//build graph && degree array
	for _, temp = range prerequisites {
		graph[temp[0]][temp[1]] = 1
		degree[temp[0]]++
	}

	// for i := 0; i < numCourses; i++ {
	// 	for j := 0; j < numCourses; j++ {
	// 		fmt.Printf("%d ", graph[i][j])
	// 	}
	// 	fmt.Println()
	// }

	//build init queue
	var j int
	for i := 0; i < numCourses; i++ {
		if degree[i] == 0 {
			queue[j] = i
			j++
		}
	}
	// fmt.Println(queue)
	// fmt.Println(degree)
	// fmt.Println(j)

	var count int
	for j > 0 {
		//dequeue && count
		j--
		var v = queue[j]
		count++
		//邻点减1度
		for k := 0; k < numCourses; k++ {
			if graph[k][v] == 1 {
				degree[k]--
				if degree[k] == 0 {
					queue[j] = k
					j++
				}
			}
		}
	}

	if count != numCourses {
		return false
	}

	return true
}

func main() {
	var numCourses = 6
	var prerequisites = [][]int{
		{3, 5}, {3, 0}, {3, 1},
		{4, 3}, {4, 2},
	}
	b := canFinish(numCourses, prerequisites)
	fmt.Println(b)
}
