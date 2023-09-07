# lab1.s
# Kevin Cendana
# 
# 1. Assemble : as -o lab1.o lab1.asm
# 2. Link     : ld -o a.out lab1.o csc35.o
# 3. Execute  : a.out

.intel_syntax noprefix			#Use Intel formatting
.data					#Start the data section
Greeting:				#Message is an address
	.ascii "Hello there!!\n\0"	#Create a buffer of ASCII
Name: 
	.ascii "My name is Kevin Cendana.\n\0"
Quote:
	.ascii "Sand is course and rough and irritating and it gets everywhere.\n\0"
Sentence1:
	.ascii "In the year \0"
Sentence2:
	.ascii ", I graduated high school! \n\0"

.text					#Start the text section
.global _start				#Make the _start label public

_start:					#UNIX starts here
	lea rbx, Greeting		#Put address into rbx
	call PrintCString		#Execute the csc35.o subroutine
	lea rbx, Name
	call PrintCString
	lea rbx, Quote
	call PrintCString
	lea rbx, Sentence1
	call PrintCString
	mov rbx, 2016
	call PrintInt
	lea rbx, Sentence2
	call PrintCString
	call EndProgram			#Execute the csc35.o subroutine
