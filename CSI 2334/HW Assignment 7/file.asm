; Filename:     file.asm
; Author:       Glen Newell
; Course:       CSI 2334
; Assignment:	6.1
; Date:		3-2-09
; Helpers:      
;
; The User will be promopted to enter twenty 32-bit values into an array. 
; The program will ouput the array to the screen as well as a count of 
; positive, negative and zeros entered into the array.

.386
.MODEL FLAT

ExitProcess PROTO NEAR32 stdcall: DWORD

INCLUDE io.h					; header file for input/output

cr	equ	0dh				; carriage return char
lf	equ	0ah				; line feed
MAX	equ	20				; max number of input values

.STACK 4096					; 4096-byte stack saved

.DATA						; storage for data
desc	BYTE	cr,lf,"The User will be promopted to enter twenty" ; description 
	BYTE	" 32-bit values into an array. The program will"
	BYTE	" ouput the array to the screen as well as a count"
	BYTE	" of positive, negative and zeros entered into the"
	BYTE	" array.",cr, lf,0
prompt	BYTE	"Enter a value: ", 0		; prompt for a value
myArray	DWORD	MAX DUP (?)			; builds the array
value	BYTE	40 DUP (?)			; value to be stored
label1	BYTE	cr,lf,lf,"The number of positve values is: "	   ; lable 1
count1	BYTE	11 DUP (?),cr,lf
label2	BYTE	"The number of negative values is: "		   ; lable 2
count2	BYTE	11 DUP (?),cr,lf
label3	BYTE	"The nubmer of zeros are: "			   ; lable 3
count3	BYTE	11 DUP (?),cr,lf,0		; count for values

.CODE
_start:  mov	ecx,MAX				; sets count to zero
	 sub	edx,edx				; sets POS count to zero
	 lea	ebx,myArray			; load address of myArra
	 output	desc

PROCESS: output prompt				; output prompt for value
	 input	value,40			; asks for user input
	 atod	value				; converts ASCII to int
	 mov	DWORD PTR[ebx],eax		; load value in myArray
	 dec	ecx				; increment counter
	 cmp	ecx, 0				; check count to 20
	 jz	DONE				; done if 20 values
	 cmp	eax,0				; compare value to 0
	 jge	POS				; jump if not negatinve
	 add	ebx,2
	 jmp	PROCESS

POS:	 add	ebx,2
	 inc	edx
	 cmp	eax,1				; compare to POS 1
	 jl	ZERO				; if less than its 0
	 jmp	PROCESS				; jumpt to PROCESS

ZERO:	 
	 jmp	PROCESS

DONE:	 dtoa	count1,edx			; zero count converted and stored
	 output	label1				; output results

	 INVOKE 	ExitProcess, 0  	; exit with return code 0

PUBLIC _start                   		; make entry point public
END     					; end program


