.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n" 
.globl main
.text
read:
	li $v0, 4 
	la $a0, _prompt 
	syscall
	li $v0, 5 
	syscall 
	jr $ra 

write:
	li $v0, 1 
	syscall 
	li $v0, 4 
	la $a0, _ret 
	syscall 
	move $v0, $0 
	jr $ra 

trap:
	addi $sp, $sp, -4 
	sw $fp, 0($sp) 
	move $fp, $sp 
	addi $sp, $sp, -40
	addi $sp, $sp, -4 
	li $t0, 0
	sw $t0, -4($fp)
	addi $sp, $sp, -4 
	li $t1, 0
	sw $t1, -8($fp)
	addi $sp, $sp, -4 
	li $t2, 0
	sw $t2, -12($fp)
	addi $sp, $sp, -4 
	li $t3, 0
	sw $t3, -16($fp)
	addi $sp, $sp, -4 
	li $t4, 0
	sw $t4, -20($fp)
	addi $sp, $sp, -4 
	li $t5, 12
	sw $t5, -24($fp)
	addi $sp, $sp, -4 
	li $t6, 0
	sw $t6, -28($fp)
	addi $sp, $sp, -48 
mylabel0:
	lw $t7, -24($fp)
	lw $t8, -12($fp)
	blt $t8, $t7, mylabel1
	j mylabel2
mylabel1:
	lw $t9, -12($fp)
	li $s0, 4
	addi $sp, $sp, -4 
	mul $s1, $s0, $t9
	sw $s1, -80($fp)
	sw $t9, -12($fp)
	lw $s2, -80($fp)
	addi $sp, $sp, -4 
	move $s3, $fp
	addi $s3, -76
	addi $sp, $sp, -4 
	add $s4, $s3, $s2
	sw $s4, -88($fp)
	sw $s3, -84($fp)
	sw $s2, -80($fp)
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $s5, $v0
	sw $s5, -92($fp)
	move $s6, $fp
	addi $s6, $s6, -88
	lw $s6, 0($s6)
	lw $s7, -92($fp)
	sw $s7, 0($s6)
	sw $s7, -92($fp)
	lw $t0, -12($fp)
	addi $sp, $sp, -4 
	addi $t1, $t0, 1
	sw $t1, -96($fp)
	sw $t0, -12($fp)
	lw $t0, -96($fp)
	lw $t1, -12($fp)
	move $t1, $t0
	sw $t1, -12($fp)
	sw $t0, -96($fp)
	j mylabel0
mylabel2:
	lw $t0, -12($fp)
	li $t0, 0
	sw $t0, -12($fp)
mylabel3:
	lw $t0, -24($fp)
	lw $t1, -12($fp)
	blt $t1, $t0, mylabel6
	j mylabel5
mylabel6:
	lw $t2, -12($fp)
	li $t3, 4
	addi $sp, $sp, -4 
	mul $t4, $t3, $t2
	sw $t4, -100($fp)
	sw $t2, -12($fp)
	lw $t2, -100($fp)
	lw $t4, -84($fp)
	addi $sp, $sp, -4 
	add $t5, $t4, $t2
	sw $t5, -104($fp)
	sw $t4, -84($fp)
	sw $t2, -100($fp)
	li $t2, 0
	addi $sp, $sp, -4 
	move $t4, $fp
	addi $t4, $t4, -104
	lw $t4, 0($t4)
	lw $t4, 0($t4)
	beq $t4, $t2, mylabel4
	j mylabel5
mylabel4:
	lw $t5, -12($fp)
	addi $sp, $sp, -4 
	addi $t6, $t5, 1
	sw $t6, -112($fp)
	sw $t5, -12($fp)
	lw $t5, -112($fp)
	lw $t6, -12($fp)
	move $t6, $t5
	sw $t6, -12($fp)
	sw $t5, -112($fp)
	j mylabel3
mylabel5:
	lw $t5, -24($fp)
	lw $t6, -12($fp)
	bge $t6, $t5, mylabel7
	j mylabel8
mylabel7:
	li $v0, 0 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
mylabel8:
	lw $t9, -12($fp)
	li $s1, 4
	addi $sp, $sp, -4 
	mul $s2, $s1, $t9
	sw $s2, -116($fp)
	sw $t9, -12($fp)
	lw $t9, -116($fp)
	lw $s2, -84($fp)
	addi $sp, $sp, -4 
	add $s3, $s2, $t9
	sw $s3, -120($fp)
	sw $s2, -84($fp)
	sw $t9, -116($fp)
	addi $sp, $sp, -4 
	move $t9, $fp
	addi $t9, $t9, -120
	lw $t9, 0($t9)
	lw $t9, 0($t9)
	lw $s2, -4($fp)
	move $s2, $t9
	sw $s2, -4($fp)
	sw $t9, -124($fp)
	lw $t9, -12($fp)
	lw $s2, -8($fp)
	move $s2, $t9
	sw $s2, -8($fp)
	sw $t9, -12($fp)
	lw $t9, -20($fp)
	li $t9, 0
	sw $t9, -20($fp)
	lw $t9, -12($fp)
	addi $sp, $sp, -4 
	addi $s2, $t9, 1
	sw $s2, -128($fp)
	sw $t9, -12($fp)
	lw $t9, -128($fp)
	lw $s2, -12($fp)
	move $s2, $t9
	sw $s2, -12($fp)
	sw $t9, -128($fp)
mylabel9:
	lw $t9, -24($fp)
	lw $s2, -12($fp)
	blt $s2, $t9, mylabel10
	j mylabel11
mylabel10:
	lw $s3, -12($fp)
	li $s4, 4
	addi $sp, $sp, -4 
	mul $s5, $s4, $s3
	sw $s5, -132($fp)
	sw $s3, -12($fp)
	lw $s3, -132($fp)
	lw $s5, -84($fp)
	addi $sp, $sp, -4 
	add $s7, $s5, $s3
	sw $s7, -136($fp)
	sw $s5, -84($fp)
	sw $s3, -132($fp)
	lw $s3, -4($fp)
	addi $sp, $sp, -4 
	move $s5, $fp
	addi $s5, $s5, -136
	lw $s5, 0($s5)
	lw $s5, 0($s5)
	blt $s5, $s3, mylabel12
	j mylabel13
mylabel12:
	lw $s7, -12($fp)
	li $t7, 4
	addi $sp, $sp, -4 
	mul $t8, $t7, $s7
	sw $t8, -144($fp)
	lw $t8, -144($fp)
	lw $s0, -84($fp)
	addi $sp, $sp, -4 
	add $s6, $s0, $t8
	sw $s6, -148($fp)
	sw $s0, -84($fp)
	sw $t8, -144($fp)
	addi $sp, $sp, -4 
	move $t8, $fp
	addi $t8, $t8, -148
	lw $t8, 0($t8)
	lw $t8, 0($t8)
	lw $s0, -4($fp)
	addi $sp, $sp, -4 
	sub $s6, $s0, $t8
	sw $s6, -156($fp)
	sw $s0, -4($fp)
	sw $t8, -152($fp)
	lw $t8, -156($fp)
	lw $s0, -20($fp)
	addi $sp, $sp, -4 
	add $s6, $s0, $t8
	sw $s6, -160($fp)
	sw $s0, -20($fp)
	sw $t8, -156($fp)
	lw $t8, -160($fp)
	lw $s0, -20($fp)
	move $s0, $t8
	sw $s0, -20($fp)
	sw $t8, -160($fp)
	j mylabel14
mylabel13:
	lw $t8, -20($fp)
	lw $s0, -16($fp)
	addi $sp, $sp, -4 
	add $s6, $s0, $t8
	sw $s6, -164($fp)
	sw $s0, -16($fp)
	sw $t8, -20($fp)
	lw $t8, -164($fp)
	lw $s0, -16($fp)
	move $s0, $t8
	sw $s0, -16($fp)
	sw $t8, -164($fp)
	lw $t8, -12($fp)
	li $s0, 4
	addi $sp, $sp, -4 
	mul $s6, $s0, $t8
	sw $s6, -168($fp)
	sw $t8, -12($fp)
	lw $t8, -168($fp)
	lw $s6, -84($fp)
	addi $sp, $sp, -4 
	add $t0, $s6, $t8
	sw $t0, -172($fp)
	sw $s6, -84($fp)
	sw $t8, -168($fp)
	addi $sp, $sp, -4 
	move $t0, $fp
	addi $t0, $t0, -172
	lw $t0, 0($t0)
	lw $t0, 0($t0)
	lw $t8, -4($fp)
	move $t8, $t0
	sw $t8, -4($fp)
	sw $t0, -176($fp)
	lw $t0, -12($fp)
	lw $t8, -8($fp)
	move $t8, $t0
	sw $t8, -8($fp)
	sw $t0, -12($fp)
	lw $t0, -20($fp)
	li $t0, 0
	sw $t0, -20($fp)
mylabel14:
	lw $t0, -12($fp)
	addi $sp, $sp, -4 
	addi $t8, $t0, 1
	sw $t8, -180($fp)
	sw $t0, -12($fp)
	lw $t0, -180($fp)
	lw $t8, -12($fp)
	move $t8, $t0
	sw $t8, -12($fp)
	sw $t0, -180($fp)
	j mylabel9
mylabel11:
	lw $t0, -20($fp)
	li $t0, 0
	sw $t0, -20($fp)
	lw $t0, -28($fp)
	li $t0, 0
	sw $t0, -28($fp)
	li $t0, 1
	lw $t8, -24($fp)
	addi $sp, $sp, -4 
	sub $s6, $t8, $t0
	sw $s6, -184($fp)
	sw $t8, -24($fp)
	lw $t8, -184($fp)
	lw $s6, -12($fp)
	move $s6, $t8
	sw $s6, -12($fp)
	sw $t8, -184($fp)
mylabel15:
	lw $t8, -8($fp)
	lw $s6, -12($fp)
	bgt $s6, $t8, mylabel18
	j mylabel17
mylabel18:
	lw $t1, -12($fp)
	li $t3, 4
	addi $sp, $sp, -4 
	mul $t2, $t3, $t1
	sw $t2, -188($fp)
	sw $t1, -12($fp)
	lw $t1, -188($fp)
	lw $t2, -84($fp)
	addi $sp, $sp, -4 
	add $t4, $t2, $t1
	sw $t4, -192($fp)
	sw $t2, -84($fp)
	sw $t1, -188($fp)
	li $t1, 0
	addi $sp, $sp, -4 
	move $t2, $fp
	addi $t2, $t2, -192
	lw $t2, 0($t2)
	lw $t2, 0($t2)
	beq $t2, $t1, mylabel16
	j mylabel17
mylabel16:
	li $t4, 1
	lw $t5, -12($fp)
	addi $sp, $sp, -4 
	sub $t6, $t5, $t4
	sw $t6, -200($fp)
	lw $t6, -200($fp)
	lw $s1, -12($fp)
	move $s1, $t6
	sw $s1, -12($fp)
	sw $t6, -200($fp)
	j mylabel15
mylabel17:
	lw $t6, -12($fp)
	li $s1, 4
	addi $sp, $sp, -4 
	mul $t9, $s1, $t6
	sw $t9, -204($fp)
	sw $t6, -12($fp)
	lw $t6, -204($fp)
	lw $t9, -84($fp)
	addi $sp, $sp, -4 
	add $s2, $t9, $t6
	sw $s2, -208($fp)
	sw $t9, -84($fp)
	sw $t6, -204($fp)
	addi $sp, $sp, -4 
	move $t6, $fp
	addi $t6, $t6, -208
	lw $t6, 0($t6)
	lw $t6, 0($t6)
	lw $t9, -28($fp)
	move $t9, $t6
	sw $t9, -28($fp)
	sw $t6, -212($fp)
	li $t6, 1
	lw $t9, -12($fp)
	addi $sp, $sp, -4 
	sub $s2, $t9, $t6
	sw $s2, -216($fp)
	sw $t9, -12($fp)
	lw $t9, -216($fp)
	lw $s2, -12($fp)
	move $s2, $t9
	sw $s2, -12($fp)
	sw $t9, -216($fp)
mylabel19:
	lw $t9, -8($fp)
	lw $s2, -12($fp)
	bgt $s2, $t9, mylabel20
	j mylabel21
mylabel20:
	lw $s4, -12($fp)
	li $s3, 4
	addi $sp, $sp, -4 
	mul $s5, $s3, $s4
	sw $s5, -220($fp)
	sw $s4, -12($fp)
	lw $s4, -220($fp)
	lw $s5, -84($fp)
	addi $sp, $sp, -4 
	add $t7, $s5, $s4
	sw $t7, -224($fp)
	sw $s5, -84($fp)
	sw $s4, -220($fp)
	lw $t7, -28($fp)
	addi $sp, $sp, -4 
	move $s4, $fp
	addi $s4, $s4, -224
	lw $s4, 0($s4)
	lw $s4, 0($s4)
	blt $s4, $t7, mylabel22
	j mylabel23
mylabel22:
	lw $s5, -12($fp)
	li $s7, 4
	addi $sp, $sp, -4 
	mul $s0, $s7, $s5
	sw $s0, -232($fp)
	lw $s0, -232($fp)
	lw $t0, -84($fp)
	addi $sp, $sp, -4 
	add $t8, $t0, $s0
	sw $t8, -236($fp)
	sw $t0, -84($fp)
	sw $s0, -232($fp)
	addi $sp, $sp, -4 
	move $t0, $fp
	addi $t0, $t0, -236
	lw $t0, 0($t0)
	lw $t0, 0($t0)
	lw $t8, -28($fp)
	addi $sp, $sp, -4 
	sub $s0, $t8, $t0
	sw $s0, -244($fp)
	sw $t8, -28($fp)
	sw $t0, -240($fp)
	lw $t0, -244($fp)
	lw $t8, -20($fp)
	addi $sp, $sp, -4 
	add $s0, $t8, $t0
	sw $s0, -248($fp)
	sw $t8, -20($fp)
	sw $t0, -244($fp)
	lw $t0, -248($fp)
	lw $t8, -20($fp)
	move $t8, $t0
	sw $t8, -20($fp)
	sw $t0, -248($fp)
	j mylabel24
mylabel23:
	lw $t0, -20($fp)
	lw $t8, -16($fp)
	addi $sp, $sp, -4 
	add $s0, $t8, $t0
	sw $s0, -252($fp)
	sw $t8, -16($fp)
	sw $t0, -20($fp)
	lw $t0, -252($fp)
	lw $t8, -16($fp)
	move $t8, $t0
	sw $t8, -16($fp)
	sw $t0, -252($fp)
	lw $t0, -12($fp)
	li $t8, 4
	addi $sp, $sp, -4 
	mul $s0, $t8, $t0
	sw $s0, -256($fp)
	sw $t0, -12($fp)
	lw $t0, -256($fp)
	lw $s0, -84($fp)
	addi $sp, $sp, -4 
	add $s6, $s0, $t0
	sw $s6, -260($fp)
	sw $s0, -84($fp)
	sw $t0, -256($fp)
	addi $sp, $sp, -4 
	move $t0, $fp
	addi $t0, $t0, -260
	lw $t0, 0($t0)
	lw $t0, 0($t0)
	lw $s0, -28($fp)
	move $s0, $t0
	sw $s0, -28($fp)
	sw $t0, -264($fp)
	lw $t0, -20($fp)
	li $t0, 0
	sw $t0, -20($fp)
mylabel24:
	li $t0, 1
	lw $s0, -12($fp)
	addi $sp, $sp, -4 
	sub $s6, $s0, $t0
	sw $s6, -268($fp)
	sw $s0, -12($fp)
	lw $s0, -268($fp)
	lw $s6, -12($fp)
	move $s6, $s0
	sw $s6, -12($fp)
	sw $s0, -268($fp)
	j mylabel19
mylabel21:
	lw $s0, -20($fp)
	lw $s6, -16($fp)
	addi $sp, $sp, -4 
	add $t3, $s6, $s0
	sw $t3, -272($fp)
	sw $s6, -16($fp)
	sw $s0, -20($fp)
	lw $t3, -272($fp)
	move $v0, $t3 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
main:
	addi $sp, $sp, -4 
	sw $fp, 0($sp) 
	move $fp, $sp 
	addi $sp, $sp, -40
	addi $sp, $sp, -4 
	sw $ra, 0($sp) 
	jal trap
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t0, $v0
	sw $t0, -4($fp)
	lw $t1, -4($fp)
	addi $sp, $sp, -4 
	move $t2, $t1
	sw $t2, -8($fp)
	sw $t1, -4($fp)
	lw $t3, -8($fp)
	move $a0, $t3
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	li $v0, 0 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
