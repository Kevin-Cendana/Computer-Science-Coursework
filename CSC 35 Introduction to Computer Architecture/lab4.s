# lab4.s
# Kevin Cendana
# 
# 1. Assemble : as -o lab4.o lab4.asm
# 2. Link     : ld -o a.out lab4.o csc35.o
# 3. Execute  : a.out

.intel_syntax noprefix			#Use Intel formatting
.data					#Start the data section

Info1:				
	.ascii "\nKilling a Goomba	: 10 points \n\0"
Info2:
	.ascii "Losing a life		: -5 points \n\n\0"
Prompt1:
	.ascii "How many Goombas did Mario kill? \n\0"
Prompt2:
	.ascii "How many lives did Mario lose? \n\0"
Prompt3:
	.ascii "How many Goombas did Luigi kill? \n\0"
Prompt4:
	.ascii "How many lives did Luigi lose? \n\0"
PointsInfo1:
	.ascii "\nMario gained \0"
PointsInfo2:
	.ascii "Luigi gained \0"
PointsString:
	.ascii " points \n\0"
MarioWins:
	.ascii "Mario wins! \n\0"
LuigiWins:
	.ascii "Luigi wins! \n\0"
Tie:
	.ascii "It's a tie! \n\0"
MarioPointsQuad:
	.quad 0
LuigiPointsQuad:
	.quad 0

.text					#Start the text section
.global _start				#Make the _start label public

_start:
	# Print information: How much are points worth?
	lea rbx, Info1	
	call PrintCString
	lea rbx, Info2
	call PrintCString
	
	
	# Ask user how many Goombas Mario killed, add to total
	lea rbx, Prompt1	
	call PrintCString
	call ScanInt
	imul rbx, 10
	mov MarioPointsQuad, rbx
	
	# Ask user how many lives Mario lost, add negative number to total
	lea rbx, Prompt2
	call PrintCString
	call ScanInt
	imul rbx, -5
	add MarioPointsQuad, rbx
	
	# Ask user how many Goombas Luigi killed, add to total	
	lea rbx, Prompt3
	call PrintCString
	call ScanInt
	imul rbx, 10
	mov LuigiPointsQuad, rbx
	
	# Ask user how many lives Luigi killed, add negative number to total
	lea rbx, Prompt4
	call PrintCString
	call ScanInt
	imul rbx, -5
	add LuigiPointsQuad, rbx

	# Display Mario's score
	lea rbx, PointsInfo1 	
	call PrintCString	
	mov rbx, MarioPointsQuad
	call PrintInt
	lea rbx, PointsString
	call PrintCString
	
	# Display Luigi's score
	lea rbx, PointsInfo2
	call PrintCString
	mov rbx, LuigiPointsQuad
	call PrintInt
	lea rbx, PointsString
	call PrintCString	

	# Compare points. Who won?
	mov rax, MarioPointsQuad
	mov rbx, LuigiPointsQuad
	cmp rax, rbx
	jg MarioWinsBlock
	jl LuigiWinsBlock
	lea rbx, Tie			# Points are equal? It's a tie!
	call PrintCString
	call EndProgram

MarioWinsBlock:
	lea rbx, MarioWins
	call PrintCString
	call EndProgram

LuigiWinsBlock:
	lea rbx, LuigiWins
	call PrintCString
	call EndProgram
