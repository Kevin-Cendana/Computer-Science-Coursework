#lab3.s
#Kevin Cendana

.intel_syntax noprefix
.data
Greetings:
	.ascii "Welcome, adventurer! Here we will decide your destiny!\n\0"
Prompt1:
	.ascii "Do you prefer (1) fighting up close or (2) attacking from afar?\n\0"
Prompt2a:
	.ascii "Would you rather (1) rely on brute strength or (2) rely on your stealthiness?\n\0"
Prompt2b:
	.ascii "Are you a believer of the (1) natural forces of the Earth or (2) the power of the arcane?\n\0"
Prompt3a:
	.ascii "Warrior!\n\0"
Prompt3b:
	.ascii "Rogue!\n\0"
Prompt3c:
	.ascii "Druid!\n\0"
Prompt3d:
	.ascii "Mage!\n\0"
Closing:
	.ascii "You are a \0"
.text
.global _start

_start:
	lea rbx, Greetings
	call PrintCString
	lea rbx, Prompt1	
	call PrintCString	
	call ScanInt		#read input into rbx
	cmp rbx, 1		#compare rbx to 1
	je Branch2a		#if true, jump to Branch2a
	jmp Branch2b		#else, jump to Branch2b
Branch2a:
	lea rbx, Prompt2a
	call PrintCString
	call ScanInt
	cmp rbx, 1
	je Branch3a
	jmp Branch3b
Branch2b:
	lea rbx, Prompt2b
	call PrintCString
	call ScanInt
	cmp rbx, 1
	je Branch3c
	jmp Branch3d
Branch3a:
	lea rbx, Closing
	call PrintCString
	lea rbx, Prompt3a
	call PrintCString
	call EndProgram
Branch3b:
	lea rbx, Closing
	call PrintCString
	lea rbx, Prompt3b
	call PrintCString
	call EndProgram
Branch3c:
	lea rbx, Closing
	call PrintCString
	lea rbx, Prompt3c
	call PrintCString
	call EndProgram
Branch3d:
	lea rbx, Closing
	call PrintCString
	lea rbx, Prompt3d
	call PrintCString
	call EndProgram

