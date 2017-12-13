; Filename:     rectangle.asm
; Author:       Glen Newell
; Course:	CSI 2334
; Assignment:	Assignment 5A         
; Helpers:      None
;
; This program will caclulate the area of a rectangle
; 

.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

INCLUDE io.h					    		; header file for input/output
	
cr      EQU     0dh						; carriage return character
Lf      EQU     0ah						; line feed

.STACK 4096							; reserve 4096-byte stack

.DATA
prompt1 BYTE	"Enter inside length:  ",0			; prompts for user input
prompt2 BYTE	"Enter inside width:  ",0			; prompts for user input
dimens	BYTE	40 DUP(?)			  		; allocates space for 32 bit input
results	BYTE	cr,lf, "The total area, inluding borde, is" 	; displays areas size
answer	BYTE	11 DUP(?)
        BYTE	cr,Lf,0

.CODE
_start:
	output	prompt1						; prompts for length
	input	dimens, 40					; set input
	atod	dimens						; convert input from ASCII to dec
	mov	ebx, eax					; move to scratch reg

	output	prompt2						; prompts for width
	input	dimens, 40					; sets input
	atod	dimens						; converts input from ASCII to dec

	add	eax, ebx					; add width
	add	eax, eax					; doubles answer
	dtoa	answer, ebx					; converts to usable ASCII
	output	results						; displays result

	INVOKE EXITPROCESS, 0					; ending program

PUBLIC _start							; end source code

END								; end program
                               
