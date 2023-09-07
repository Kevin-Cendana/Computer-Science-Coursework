# lab5.s 
# Kevin Cendana
# 1. Assemble : as -o lab5.o lab5.s
# 2. Link     : ld -o a.out lab5.o csc35.o
# 3. Execute  : a.out

.intel_syntax noprefix			#Use Intel formatting
.data					#Start the data section

BillPrompt:
	.ascii "How much, in knuts, was the bill?\n\0"
TipPrompt:
	.ascii "How much, in percent, is the tip?\n\0"
PeopleAmountPrompt:
	.ascii "How many people are splitting the bill?\n\0"
PostTipBillInfo1:
	.ascii "\nThe total is \0"
PostTipBillInfo2:
	.ascii " knuts. \n\n\0"
AmountPerPersonInfo1:
	.ascii "\nOkay, witches and wizards, give \0"
AmountPerPersonInfo2:
	.ascii " knuts each.\n\0"
Skip1Line:
	.ascii "\n\0"
Skip2Lines:
	.ascii "\n\n\0"
BillQuad:
	.quad 0
PostTipBillQuad:
	.quad 0
AmountPerPersonQuad:
	.quad 0

.text
.global _start

_start:
	#Ask for bill
	lea rbx, BillPrompt
	call PrintCString
	call ScanInt
	mov BillQuad, rbx
	lea rbx, Skip2Lines
	call PrintCString 

	#Ask for tip %
	lea rbx, TipPrompt
	call PrintCString
	call ScanInt
	imul rbx, [BillQuad] 	#Multiply tip by bill

	#Calculating PostTipBill
	mov rax, rbx		#Move rbx (currently tip*bill) into rax
	cqo
	mov rbx, 100		#Divide rbx by 100 to get tip amount
	div rbx			
	mov rbx, rax		
	add rbx, BillQuad	#Add tip to bill, put into PostTipBillQuad
	mov PostTipBillQuad, rbx
	mov rbx, PostTipBillQuad

	#Print PostTipBill (the total)
	lea rbx, PostTipBillInfo1
	call PrintCString
	mov rbx, PostTipBillQuad 
	call PrintInt	#debug
	lea rbx, PostTipBillInfo2
	call PrintCString
	jmp AskPeopleAmount
	call EndProgram
AskPeopleAmount:
	#Ask for PeopleAmount
	lea rbx, PeopleAmountPrompt
	call PrintCString 
	call ScanInt
	cmp rbx, 0
	jle AskPeopleAmount
	jmp Final
	call EndProgram
Final:
	#Calcuate AmountPerPerson
	mov rax, PostTipBillQuad
	cqo
	div rbx
	mov rbx, rax
	mov AmountPerPersonQuad, rbx

	#Print AmountPerPerson
	lea rbx, AmountPerPersonInfo1
	call PrintCString
	mov rbx, AmountPerPersonQuad
	call PrintInt
	lea rbx, AmountPerPersonInfo2
	call PrintCString

	call EndProgram
