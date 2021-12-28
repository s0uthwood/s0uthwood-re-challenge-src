# go language

```shell
$ go version
go version go1.15.6 windows/amd64

$ go build -ldflags="-s -w" ./chall.go
```

Symbols was striped while building, can you recover the symbols?

Hint: maybe IDA 7.6 can help you.

It is recommended that you compile this challenge with different versions, as the binaries compiled by different versions differ significantly.
