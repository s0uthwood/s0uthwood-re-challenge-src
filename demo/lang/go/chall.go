package main

import "fmt"

func main ()  {
	fmt.Println("Input the flag:")
	var flag string
	_, err := fmt.Scanf("%s", &flag)
	if err != nil {
		fmt.Println("Input error!")
		return
	}
	slice_flag := []byte(flag)
	for i := 0; i < len(slice_flag); i++{
		slice_flag[i] ^= byte(0x10 + i)
	}
	cipher := []byte("v}storyHtxt|i|yz]")
	if len(slice_flag) != len(cipher){
		fmt.Println("Wrong")
		return
	}
	for i := 0; i < len(cipher); i++{
		if cipher[i] != slice_flag[i]{
			fmt.Println("Wrong")
			return
		}
	}
	fmt.Println("Good")
	return
}
