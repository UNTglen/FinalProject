; Filename:	443.asm
; Author:	Glen Newell
; Course:	CSI 2334
; Assignment:	6a
; Helpers:	None
;
; This program caluclate the sum of 5 test scores
;

.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall, dwExitCode:DWORD

INCLUDE io.h					; Include header file

cr	EQU	0dh				; carriage return
lf	EQU	0ah				; line feed

.STACK 4096

.DATA
prompt1   BYTE	"Enter a grade 1: ",0			; prompts for 1st number
prompt2	  BYTE	"Enter a grade 2: ",0			; prompts for 1st number
prompt3	  BYTE	"Enter a grade 3: ",0			; prompts for 1st number
prompt4	  BYTE	"Enter a grade 4: ",0			; prompts for 1st number
value	  BYTE	16 DUP(?)				; Allocate Temp storage
answer	  BYTE	cr,lf,"The averge test score is: " 	; promopt for output
quotient  BYTE	6 DUP(?)				; memory for quotient
remainder BYTE	6 DUP(?),cr,lf,0			; space for result & EOF

.CODE
_start:
	output	prompt1				; prompt for 1st grade
	input	value, 16			; get a grade
	atoi	value				; covt to int
	mov	dx, ax				; copy to scratch reg

	output	prompt2				; prompt for 2nd grade
	input	value, 16			; get a grade
	atoi	value				; covt to int
	add	dx, ax				; add to sum

	output	prompt3				; prompt for 3rd grade
	input	value, 16			; get a grade
	atoi	value				; covt to int
	add	dx, ax				; add to sum

	output	prompt4				; prompt for 4th grade
	input	value, 16			; get a grade
	atoi	value				; covt to int
	add	ax, ax				; double last score
	add	dx, ax				; add sum

	cdw					; clear registers
	mov	bx, 5				; dets divisor to 5
	idiv	bx				; divides sum by 5
	itoa	quotient, ax			; converts quotient to dec
	mov	ax, dx				; mov ax to dx
	imul 	ax, 100				; mul by 100 for dec point
	cwd					; clear registers
	idiv	bx				; divides
	itoa	remainder, ax			; convert from dec to ASCII
	output	answer				; display answer

	INVOKE	ExitProcess,0
PUBLIC _start
END
