package main

import "fmt"

func tictactoe(moves [][]int) string {
	var game = buildGame(moves)
	return checkGame(game)
}

func buildGame(moves [][]int) [3][3]int {
	var game [3][3]int
	count := 0
	for _, temp := range moves {
		if count%2 == 0 {
			game[temp[0]][temp[1]] = 1
		} else {
			game[temp[0]][temp[1]] = -1
		}
		count++
	}
	// for i := 0; i < 3; i++ {
	// 	for j := 0; j < 3; j++ {
	// 		fmt.Printf("%2d ", game[i][j])
	// 	}
	// 	fmt.Println()
	// }

	return game
}

func checkGame(game [3][3]int) string {
	full := true
	//hirizontal
	for i := 0; i < 3; i++ {
		hirizontal := 0
		vertical := 0
		for j := 0; j < 3; j++ {
			if game[i][j] == 0 {
				full = false
			}
			hirizontal += game[i][j]
			vertical += game[j][i]
		}
		if hirizontal == 3 || vertical == 3 {
			return "A"
		} else if hirizontal == -3 || vertical == -3 {
			return "B"
		}
	}

	//diagonal
	diagonal1 := game[0][0] + game[1][1] + game[2][2]
	diagonal2 := game[0][2] + game[1][1] + game[2][0]
	if diagonal1 == 3 || diagonal2 == 3 {
		return "A"
	} else if diagonal1 == -3 || diagonal2 == -3 {
		return "B"
	}

	if full {
		return "Draw"
	}
	return "Pending"

}

func main() {
	var moves = [][]int{
		{0, 0}, {1, 1},
	}
	s := tictactoe(moves)
	fmt.Println(s)
}
