.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

cr	EQU	0dh
lr	EQU	0ah

INCLUDE io.h

.STACK 4096

.DATA
prompt1	BYTE	"hello world ",0

.CODE
_start:
	output prompt1

	INVOKE ExitProcess,0

PUBLIC _start
END
