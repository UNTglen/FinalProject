; Filename:     debug.asm
; Author:       CFry
; Helper:	Glen Newell
; Course:	CSI 2334
; Assignment:	Assignment 5A         
; Helpers:      None
;
; This program inputs two numbers, computes their sum, and displays
; the numbers and the sum on the standard output device (monitor).
;

.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

INCLUDE io.h					    	; header file for input/output

cr      EQU     0dh					; carriage return character
Lf      EQU     0ah					; line feed

.STACK 4096						; reserve 4096-byte stack

.DATA
prompt1 BYTE	"Enter first number:  ",0
prompt2 BYTE	"Enter second number:  ",0
label1  BYTE	cr,Lf,"The numbers you entered were ",cr,Lf
number1	BYTE	40 DUP(?)
	BYTE	cr,Lf," and ",cr,Lf 
number2	BYTE	40 DUP(?)
	BYTE	cr,Lf,"The sum is "
sum	BYTE	11 DUP(?)
        BYTE	cr,Lf,0
                                                        
.CODE	       						; start of main program code 
_start: 					             
        output  prompt1					; prompt for first number
        input   number1,40				; read ASCII characters
      	atod	number1					; convert number1 to a dword
	mov	ebx,eax					; store the dword (ebx)

        output  prompt2					; prompt for second number
        input   number2,40				; read ASCII characters
	atod	number2					; convert number2 to a dword
	add	eax,ebx					; add the first number to the second
        
        dtoa	sum,eax					; convert result to ASCII, store in memory
	output  label1					; output label, numbers, and sum

        INVOKE  ExitProcess,0				; exit with return code 0

PUBLIC _start						; make entry point public

END							; end of source code
