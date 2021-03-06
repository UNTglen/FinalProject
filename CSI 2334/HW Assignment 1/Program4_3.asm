; Fileneame:	Program4_3.asm
; Author:	Glen Newell
; Course:	CSI 2334.01
; Helpers:	None
; Date:		Feb 10, 2009
;
; Description: This program will prompt the user for 2 input values, subtracts
; second number from frist, and then displays the result.

.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode: DWORD	; defines exit process

INCLUDE io.h						; Header file for I/O

cr	EQU	0dh					; set up carage retun
lf	EQU	0ah					; set up line feed

.STACK 4096						; reserve 4096-byte Stack

.DATA							; Reserve storage for data
prompt1	BYTE	"Enter first number:",0			; prompts first number
prompt2	BYTE	"Enter second number",0			; prompts second number
string	BYTE	40 DUP(?)				; allocates mem for string
label1	BYTE	cr, lf, "The difference is"		; label for sum/difference
sum	BYTE	11 DUP(?)				; allocates mem for sum
	BYTE	cr, lf, 0				; cr & lf with null term.

.CODE
_start:
	output	prompt1					; displays prompt one
	input	string, 40				; asks for user input
	atod	string					; converts string to dec
	move	ebx, eax				; moves eax to ebx

	output	prompt2					; displays prompt2
	input	string, 40				; asks for user input
	atod	string					; converts string to dec

	sub	ebx, eax				; sub 2nd number from 1st
	dtoa	sum, eax				; comverts int to ASCII char
	output	label1					; displays sum and answer

	INVOKE ExitProcess, 0				; exits program

PUBLIC	_start						; makes program public

END							; ends program
