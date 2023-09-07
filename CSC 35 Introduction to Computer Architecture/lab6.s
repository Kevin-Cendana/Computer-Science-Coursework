# lab6.s
# Kevin Cendana
# 1. Assemble : as -o lab6.o lab65.s
# 2. Link     : ld -o a.out lab6.o csc35.o
# 3. Execute  : a.out

.intel_syntax noprefix
.data

Greetings:
	.ascii "\nWelcome to the PokeMart! \n\0"
Potion:
	.ascii "1. Potion (5 cents) \n\0"
SuperPotion:
	.ascii "2. Super Potion (10 cents) \n\0"
Revive:
	.ascii "3. Revive (25 cents) \n\0"
PokeBall:
	.ascii "4. PokeBall (15 cents) \n\0"
Cancel:
	.ascii "5. Cancel (0 cents) \n\0"
CentsPrompt:
	.ascii "\nHow many cents were entered? \n\0" 
SelectionPrompt:
	.ascii "\nEnter your selection: \n\0"
SelectionInfo:
	.ascii "\nYou selected: \n\0"
ChangeInfo:
	.ascii "\nYour change is \0"
ChangeInfo2:
	.ascii " cents.\n\0"
ChangeInfo3:
	.ascii "Dispensing \0"
ChangeInfo4:
	.ascii " quarter(s) and \0"
ChangeInfo5:
	.ascii " pennies.\n\n\0"

CentsQuad:
	.quad 0
CostQuad:
	.quad 0
ChangeQuad:
	.quad 0
QuartersQuad:
	.quad 0
PenniesQuad:
	.quad 0
ItemIndexQuad:
	.quad 0

Items:
	.quad Potion
	.quad SuperPotion
	.quad Revive
	.quad PokeBall
	.quad Cancel

Costs:
	.quad 5
	.quad 10
	.quad 25
	.quad 15
	.quad 0

.text
.global _start

_start:
	# Print Prompts
	lea rbx, Greetings
	call PrintCString
	lea rbx, Potion
	call PrintCString
	lea rbx, SuperPotion
	call PrintCString
	lea rbx, Revive
	call PrintCString
	lea rbx, PokeBall
	call PrintCString
	lea rbx, Cancel
	call PrintCString
	jmp AskForCents

AskForCents:
	# Ask for cents and selection
	lea rbx, CentsPrompt 
	call PrintCString
	call ScanInt

	#Input Validation: Ensure cents is not negative
	cmp rbx, 0
	jl AskForCents	

	mov CentsQuad, rbx
	jmp AskForSelection

AskForSelection:
	# Ask for selection
	lea rbx, SelectionPrompt
	call PrintCString
	call ScanInt
	mov rax, CentsQuad 	# Move cents into rax 
	mov ItemIndexQuad, rbx

	# Look up cost based on input		
	mov rdi, ItemIndexQuad
	mov rbx, [Costs + (rdi - 1) * 8] 	
	mov CostQuad, rbx	

	# Input Validation: Compare rbx (cost) w/ rax (cents) to make sure they have enough money
	cmp rbx, rax
	jg AskForSelection

	# Input Validation: Compare rbx (index) w/ 0 and 5 to make sure input is in range
	mov rbx, ItemIndexQuad
	cmp rbx, 0
	jl AskForSelection
	cmp rbx, 6
	jg AskForSelection
	
	jmp OutputItem

OutputItem:	
	# "You entered ..."
	lea rbx, SelectionInfo
	call PrintCString
	
	# Look up item based on input
	mov rdi, ItemIndexQuad
	mov rbx, [Items + (rdi - 1) * 8] 
	call PrintCString

	# Calculate change amount
	lea rbx, ChangeInfo
	call PrintCString
	mov rbx, CentsQuad	#Subtract Cents - Costs
	sub rbx, CostQuad
	mov ChangeQuad, rbx
	call PrintInt
	lea rbx, ChangeInfo2
	call PrintCString
	
	# Calculate change type (how many quarters and pennies)
	mov rax, ChangeQuad
	mov rbx, 25
	cqo
	idiv rbx
	mov QuartersQuad, rax
	mov PenniesQuad, rdx
	
	# Display Change info
	lea rbx, ChangeInfo3
	call PrintCString
	mov rbx, QuartersQuad
	call PrintInt
	lea rbx, ChangeInfo4
	call PrintCString
	mov rbx, PenniesQuad
	call PrintInt
	lea rbx, ChangeInfo5
	call PrintCString
	call EndProgram

	
