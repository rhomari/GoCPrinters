package main

// #cgo LDFLAGS: -lwinspool
// #include "cprinters.h"
import "C"

func main() {

	C.listPrinters()

}
