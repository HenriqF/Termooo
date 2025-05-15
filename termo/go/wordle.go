package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func containsRune(slice []rune, target rune) bool {
	for _, r := range slice {
		if r == target {
			return true
		}
	}
	return false
}

func replaceF(runes []rune, old rune, new rune) []rune {
	for i, r := range runes {
		if r == old {
			runes[i] = new
			break
		}
	}
	return runes
}

func main() {
	keyword := "corra"
	comprimento := len(keyword)
	var answer string
	var win bool
	win = false

	for i := 0; i < comprimento; i++ {
		answer += "-"
	}

	fmt.Println(answer, comprimento+1)
	for j := 0; j < comprimento+1; j++ { // numero de tentativas:
		copyKeyword := []rune(keyword)
		copyAnswer := []rune(answer)

		leitor := bufio.NewReader((os.Stdin))
		input, _ := leitor.ReadString('\n')
		input = strings.Replace(input, "\n", "", -1)
		input = strings.Replace(input, "\r", "", -1)

		guess := []rune(input)

		if len(guess) != comprimento {
			fmt.Println("tenta de novo; tamanho errado desgrama.")
			j--
		} else {
			for i := 0; i < comprimento; i++ {
				if guess[i] == copyKeyword[i] {
					copyAnswer[i] = 'o'
					copyKeyword[i] = '-'
				}
			}
			for i := 0; i < comprimento; i++ {
				if containsRune(copyKeyword, guess[i]) {
					copyKeyword = replaceF(copyKeyword, guess[i], '*')
					copyAnswer[i] = '*'
				}
			}
			fmt.Println(string(copyAnswer), comprimento-j)
			if input == keyword {
				fmt.Println("Parabens fvoce venceu o jogo e etcetera agradeco desde entao.")
				win = true
				break
			}

		}
	}
	if !win {
		fmt.Println("Parabens por ser um bosta léxico")
	}

}
