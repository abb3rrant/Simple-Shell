# Simple Shell for OSCP

A simple shell written in C, change IP and port and build.

**Build Windows:**
```bash
x86_64-w64-mingw32-gcc shell.c -o shell.exe -lws2_32
```

**Build Linux (static):**
```bash
CGO_ENABLED=0 go build -ldflags "-s -w" -o shell shell.go
```

