package main

import (
	"fmt"
	"io/ioutil"

	"gopkg.in/alecthomas/kingpin.v2"
)

const (
	BLACK = "\033[40m  \033[0m"
	WHITE = "\033[47m  \033[0m"
)

var (
	fileDir = kingpin.Flag("file", "Verbose mode.").Short('f').String()
)

func main() {
	kingpin.Parse()

	b, err := ioutil.ReadFile(*fileDir)
	if err != nil {
		panic(err)
	}
	for _, elem := range b {
		// fmt.Printf("%#v\n", elem)
		if elem == 0x31 {
			fmt.Print(BLACK)
		}
		if elem == 0x30 {
			fmt.Print(WHITE)
		}
		if elem == 0xa {
			fmt.Println()
		}
	}
}
