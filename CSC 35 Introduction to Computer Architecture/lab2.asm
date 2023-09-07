#lab2.asm
#Kevin Cendana
#Assemble:	as -o lab2.o lab2.asm
#Link:		ld -o a.out lab2.o csc35.o

.intel_syntax noprefix
.data

Billboard:
	.ascii "Votes gained from billboards. \n\0"

BillboardQuad:
	.quad 0

Commercial:
	.ascii "Votes gained from commercials. \n\0"

CommercialQuad:
	.quad 0

Hackers:
	.ascii "Votes lost from hackers. \n\0"

HackersQuad:
	.quad 0

TaxFraud:
	.ascii "Votes lost from tax fraud. \n\0"

TaxFraudQuad:
	.quad 0

NetVoteChange:
	.ascii "The net change in votes is \0"

.text
.global _start

_start:
	lea rbx, Billboard		#load Billboard into rbx
	call PrintCString
	call ScanInt			#add user input into rbx
	mov BillboardQuad, rbx		#move rbx into BillboardQuad
	
	lea rbx, Commercial
	call PrintCString
	call ScanInt
	mov CommercialQuad, rbx		

	lea rbx, Hackers
	call PrintCString
	call ScanInt
	mov HackersQuad, rbx

	lea rbx, TaxFraud
	call PrintCString
	call ScanInt
	mov TaxFraudQuad, rbx

	lea rbx, NetVoteChange
	call PrintCString
	mov rbx, 0
	add rbx, BillboardQuad
	add rbx, CommercialQuad
	sub rbx, HackersQuad
	sub rbx, TaxFraudQuad
	call PrintInt
	mov rbx, '\n'
	call PrintChar

	call EndProgram
	
