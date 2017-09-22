;Final project speaker rotate program
;5 IR break beam sensors spaced at 20cm, 60cm, 100cm, 140cm, and 180cm
;IRBBS connected to port A of 8255 (input) w/ pullup resistors
;spin dude 1A, 1B, 2A, 2B connected to B0- B3 of 8255 (output)
;LCD connected to Port C of the 8255 (output) as well as E is 3.5 and R/S is 3.4
;external interrupt 0 on P3.2 tied to PSoC scanning comparator interrupt
;external interrupt 1 on P3.3 tied to PSoC ADC output
;r0 = # steps per transition
;r1 = current position in motor table
;r2 =
;r3 =
;r4 = current position in motor table
;r5 = loop counter to print 'Volume is:' to LCD
;r6 = delay loop register
;r7 = delay loop register
.org 00h
	ljmp init								; jump to initilization

.org 03h									; external interrupt 0 on P3.2
	ljmp irbbs					  	; determine how many steps to move the motor

;.org 0Bh									; timer 0 interrupt

;.org 013h									; external interrupt 1 on P3.3
	;used for adc_wait subroutine
;.org 01Bh									; timer 1 interrupt



.org 100h
motor_table: 								; the 8 motor values which are looped through for half stepping each time(7.5 degrees)
	;.db 0F1h, 0F5h, 0F4h, 0F6h, 0F2h, 0FAh, 0F8h, 0F9h
	.db 3Dh, 2Fh, 3Bh, 1Fh
.org 300h
LCD_volume:
	.db "Volume is:"
; Initilizatin :
; 1) start the ADC
; 2) configures 8255 properly
; 3) sets up timers/interrupts
; 4) starts up LCD Screen with necessary setup commands
init:
	mov dptr, #0FE08h 			; the ADC register
	movx @dptr, a 					; initilizate the conversation
	mov dptr, #0FE03h       ; configure the 8255
	mov a, #90h             ; port A input, port B output, Port C output
	movx @dptr, a           ; push to the 8255

	setb it0                ; external interrupt on transition
	mov IE, #8Bh            ; enable external interrupts
	lcall lcd_start					; initilize LCD
	ljmp volume_level				; display volume information

lcd_start:
	mov a, #38h             ; 8-bit, 5x7 char set, 2 lines
	lcall lcd_drive         ; execute command
	mov a, #0Ch             ; turn display on, hide cursor
	lcall lcd_drive         ; execute command
	mov a, #01h             ; clear display
	lcall lcd_drive         ; execute command
	mov a, #80h             ; set RAM address to 0
	lcall lcd_drive         ; execute command
	ret

; this subroutine runs the commands to clear and reset the cursor of the lcd
lcd_reset:
	mov a, #80h             ; set RAM address to 0
	lcall lcd_drive         ; execute command
	ret

; lcd_write - this subroutine does the necessary latching
; of the enable lines using the data in a to write to
; the lcd. The value of the r/s line is controlled by
; adding the value of the r1 register
lcd_write:
	clr P3.5									; lower E
	mov dptr, #0FE02h       ; port C data location
	movx @dptr, a           ; push drive out
	setb P3.5								;raise E
	lcall delay
	clr P3.5									; lower E
	lcall delay
	ret

; this subroutine uses the lcd_write procedure but makes sure the r/s line
; is low to send driving commands
lcd_drive:
	clr P3.4			            ; drive r/s  low
	ljmp lcd_write          ; jump, it will do the ret

; this subroutine uses the lcd_write procedure but makes sure the r/s line
; is high to send data
lcd_data:
	setb P3.4          			; drive r/s high
	ljmp lcd_write          ; jump, it will do the ret


; takes voltage output of ADC connected to microphone and displays crude 'volume'
; information on LCD screen
volume_level:
	lcall lcd_reset
	mov r5, #00             ; start at location 0
volume_loop:
  mov dptr, #300h        ; location of the bytes
  mov a, r5               ; the offset in r0
  movc a, @a + dptr       ; get the value from the table
  lcall lcd_data          ; display the data on the screen
  inc r5                  ; increment up
  cjne r5, #10, volume_loop ; loop if not 10
adc_read:
; this subroutine reads a value from the adc and puts the byte in acc

	mov dptr, #0FE08h       ; address of the adc
	movx @dptr, a           ; initiate a conversion
adc_wait:
	jb p3.3, adc_wait       ; wait for conversion to finish
	movx a, @dptr           ; get the value of the adc to a

print_out:
	mov b, #51              ; a single volt in b
	div ab                  ; divide a by b
	add a, #30h             ; change to ascii
	lcall lcd_data          ; push the ones digit out
	mov a, #2Eh             ; period character
	lcall lcd_data          ; push out a digit
	mov a, b                ; get the remainder in a
	mov b, #5               ; a single digit in b
	div ab                  ; divide a by b again
	add a, #30h             ; change to ascii
	lcall lcd_data          ; push the tens digit out
	sjmp volume_level



irbbs:
; This interrupt service routine is triggered by external interrupt from PSoC
; which means one of the infared sensors has been triggered. It jumps to appropriate lines
; to skip through motor table correct number of times
	push acc
	push dpl
	push dph
	mov dptr, #0FE00h				; point to IRBBS byte in Port A (top 5 bits)
	movx a, @dptr						; and move byte into acc
	anl a, #0F8h						; mask off bottom 3 bits
check0:
	cjne a, #0F8h, check1   ; if no sensor triggered then face center of beam 3
center:
	;check if current motor state(r4) is less than or greater than desired state
	;if so set 00h
	;subtract value associated w/ state from r4 or vice versa depending on 00h
	mov P1, #00000001b
	clr OV
	clr 00h
	mov a, #04h
	subb a, r4
	jbc OV, positive1
	setb 00h
positive1:
	ljmp sensor3middle
check1:
	cjne a, #0F0h, check2	  ; if sensor 1 triggered then face center of beam1
sensor1middle:

	mov P1, #00000010b
	clr OV
	clr 00h
	mov a, #00h
	subb a, r4
	jbc OV, positive2
	setb 00h
positive2:
	ljmp rotation_step
check2:
	cjne a, #0E0h, check3	  ; if sensor 1&2 triggered then face center of beam1&2
sensor12middle:
	mov P1, #00000100b
	clr OV
	clr 00h
	mov a, #01h
	subb a, r4
	jbc OV, positive3
	setb 00h
positive3:
	ljmp rotation_step
check3:
	cjne a, #0E8h, check4	  ; if sensor 2 triggered then face center of beam2
sensor2middle:

	mov P1, #00001000b
	clr OV
	clr 00h
	mov a, #02h
	subb a, r4
	jbc OV, positive4
	setb 00h
positive4:
	ljmp rotation_step
check4:
	cjne a, #0C8h, check5	  ; if sensor 2&3 triggered then face center of beam2&3
sensor23middle:

	mov P1, #00010000b
	clr OV
	clr 00h
	mov a, #03h
	subb a, r4
	jbc OV, positive5
	setb 00h
positive5:
	ljmp rotation_step
check5:
	cjne a, #0D8h, check6	  ; if sensor 3 triggered then face center of beam3
sensor3middle:

	mov P1, #00100000b
	clr OV
	clr 00h
	mov a, #04h
	subb a, r4
	jbc OV, positive6
	setb 00h
positive6:
	ljmp rotation_step
check6:
	cjne a, #098h, check7	  ; if sensor 3&4 triggered then face center of beam3&4
sensor34middle:

	mov P1, #01000000b
	clr OV
	clr 00h
	mov a, #05h
	subb a, r4
	jbc OV, positive7
	setb 00h
positive7:
	ljmp rotation_step
check7:
	cjne a, #0B8h, check8	  ; if sensor 4 triggered then face center of beam4
sensor4middle:

	mov P1, #10000000b
	clr OV
	clr 00h
	mov a, #06h
	subb a, r4
	jbc OV, positive8
	setb 00h
positive8:
	ljmp rotation_step
check8:
	cjne a, #038h, check9	  ; if sensor 4&5 triggered then face center of beam4&5
sensor45middle:

	mov P1, #10000001b
	clr OV
	clr 00h
	mov a, #07h
	subb a, r4
	jbc OV, positive9
	setb 00h
positive9:
	ljmp rotation_step
check9:
	cjne a, #078h, exit	  ; if sensor 5 triggered then face center of beam5
sensor5middle:

	mov P1, #10000010b
	clr OV
	clr 00h
	mov a, #08h
	subb a, r4
	jbc OV, positive10
	setb 00h
positive10:
	ljmp rotation_step
exit:										; pop data pointer and acc
	pop dph
	pop dpl
	pop acc
	reti


	rotation:
	; This routine runs one full rotation of the attached SpinDude
	; platform, using 24 steps and a delay between the steps equal
	; to the inital value in r3 * 100ms. It chooses direction
	; based on the bit in 00h

		mov r0, #24               ; 24 steps in a rotation
		mov r1, #0h               ; count starts at 0
		mov r3, #02h
		mov r7, #00h              ; initialize stall values
		mov r6, #0b4h             ; 180 counts on middle loop
	rotation_loop:
		mov dptr, #motor_table    ; point at the motor_table
		mov a, r1                 ; get the current count
		mov b, #04h               ; use mod 4 arithmetic
		div ab                    ; divide count by 4
		mov a, b                  ; get the remainder of the division
		movc a, @a + dptr         ; byte from the table
		mov dptr, #0FE01h         ; port B register location on 8255
		movx @dptr, a             ; push that byte to the Port B
		jb 00h, counter_clockwise
	clockwise:
		dec r1                    ; decrement count for clockwise
		sjmp rotation_stall
	counter_clockwise:
		inc r1                    ; increment the count for counter
	rotation_stall:
		djnz r7, rotation_stall   ; lowest loop stall for 256
		djnz r6, rotation_stall   ; middle loop stall for
		mov r6, #0b4h             ; 180 rounds
		djnz r2, rotation_stall   ; highest loop, variable and set by r3
		mov a, r3                 ; reset our counter
		mov r2, a                 ; for outermost loop
		djnz r0, rotation_loop    ; decrement our step counter
		pop dph
		pop dpl
		pop acc
		reti
; rotation:
; ; This routine does one transition using 2 steps. It chooses direction
; ; based on the bit in 00h. The current motor position is stored in r1
;
; 	mov r0, #4               ; 2 steps in a transition
; rotation_step:
; 	mov dptr, #motor_table    ; point at the motor_table
; 	mov a, r1                 ; get the current count
;
; 	mov b, #08h               ; use mod 8 arithmetic
; 	div ab                    ; divide count by 8
; 	mov a, b                  ; get the remainder of the division
; 	movc a, @a + dptr         ; byte from the table
; 	mov dptr, #0FE01h         ; port B register location on 8255
; 	movx @dptr, a             ; push that byte to the Port B
; 	jb 00h, counter_clockwise
; clockwise:
; 	dec r1                    ; decrement count for clockwise
; 	; delay
; 	sjmp fin
; counter_clockwise:
; 	inc r1                    ; increment the count for counter
; fin:
; 	mov a, r1									; save position in motor table into r4
; 	mov r4, a
; 	djnz r0, rotation_step    ; decrement our step counter
; 	pop dph
; 	pop dpl
; 	pop acc
; 	reti
;
; delay:
; 	mov r6, #0FFh
; 	mov r7, #0FFh
; 	loop1:
; 		djnz r7, loop1
; 	djnz r6, loop1
; 	ret
