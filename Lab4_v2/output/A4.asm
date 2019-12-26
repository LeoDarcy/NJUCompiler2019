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

main:
	addi $sp, $sp, -4 
	sw $fp, 0($sp) 
	move $fp, $sp 
	addi $sp, $sp, -40
	addi $sp, $sp, -8 
	addi $sp, $sp, -4 
	li $t0, 0
	sw $t0, -12($fp)
mylabel0:
	li $t1, 5
	lw $t2, -12($fp)
	blt $t2, $t1, mylabel1
	j mylabel2
mylabel1:
	lw $t3, -12($fp)
	li $t4, 4
	addi $sp, $sp, -4 
	mul $t5, $t4, $t3
	sw $t5, -16($fp)
	sw $t3, -12($fp)
	lw $t6, -16($fp)
	addi $sp, $sp, -4 
	move $t7, $fp
	addi $t7, -8
	addi $sp, $sp, -4 
	add $t8, $t7, $t6
	sw $t8, -24($fp)
	sw $t7, -20($fp)
	sw $t6, -16($fp)
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t9, $v0
	sw $t9, -28($fp)
	move $s0, $fp
	addi $s0, $s0, -24
	lw $s0, 0($s0)
	lw $s1, -28($fp)
	sw $s1, 0($s0)
	sw $s1, -28($fp)
	lw $s2, -12($fp)
	addi $sp, $sp, -4 
	addi $s3, $s2, 1
	sw $s3, -32($fp)
	sw $s2, -12($fp)
	lw $s4, -32($fp)
	lw $s5, -12($fp)
	move $s5, $s4
	sw $s5, -12($fp)
	sw $s4, -32($fp)
	j mylabel0
mylabel2:
	lw $s6, -12($fp)
	li $s6, 1
	sw $s6, -12($fp)
mylabel3:
	li $s7, 5
	lw $t0, -12($fp)
	blt $t0, $s7, mylabel4
	j mylabel5
mylabel4:
	lw $t3, -12($fp)
	addi $sp, $sp, -4 
	move $t5, $t3
	sw $t5, -36($fp)
	sw $t3, -12($fp)
mylabel6:
	li $t3, 0
	lw $t5, -36($fp)
	bgt $t5, $t3, mylabel9
	j mylabel8
mylabel9:
	li $t6, 1
	lw $t7, -36($fp)
	addi $sp, $sp, -4 
	sub $t8, $t7, $t6
	sw $t8, -40($fp)
	sw $t7, -36($fp)
	lw $t7, -40($fp)
	li $t8, 4
	addi $sp, $sp, -4 
	mul $t9, $t8, $t7
	sw $t9, -44($fp)
	sw $t7, -40($fp)
	lw $t7, -44($fp)
	lw $t9, -20($fp)
	addi $sp, $sp, -4 
	add $s1, $t9, $t7
	sw $s1, -48($fp)
	sw $t9, -20($fp)
	sw $t7, -44($fp)
	lw $t7, -36($fp)
	li $t9, 4
	addi $sp, $sp, -4 
	mul $s1, $t9, $t7
	sw $s1, -52($fp)
	sw $t7, -36($fp)
	lw $t7, -52($fp)
	lw $s1, -20($fp)
	addi $sp, $sp, -4 
	add $s2, $s1, $t7
	sw $s2, -56($fp)
	sw $s1, -20($fp)
	sw $t7, -52($fp)
	addi $sp, $sp, -4 
	move $t7, $fp
	addi $t7, $t7, -56
	lw $t7, 0($t7)
	lw $t7, 0($t7)
	addi $sp, $sp, -4 
	move $s1, $fp
	addi $s1, $s1, -48
	lw $s1, 0($s1)
	lw $s1, 0($s1)
	bgt $s1, $t7, mylabel7
	j mylabel8
mylabel7:
	lw $s2, -36($fp)
	li $s3, 4
	addi $sp, $sp, -4 
	mul $s4, $s3, $s2
	sw $s4, -68($fp)
	sw $s2, -36($fp)
	lw $s2, -68($fp)
	lw $s4, -20($fp)
	addi $sp, $sp, -4 
	add $s5, $s4, $s2
	sw $s5, -72($fp)
	sw $s4, -20($fp)
	sw $s2, -68($fp)
	addi $sp, $sp, -4 
	move $s2, $fp
	addi $s2, $s2, -72
	lw $s2, 0($s2)
	lw $s2, 0($s2)
	addi $sp, $sp, -4 
	move $s4, $s2
	sw $s4, -80($fp)
	sw $s2, -76($fp)
	lw $s2, -36($fp)
	li $s4, 4
	addi $sp, $sp, -4 
	mul $s5, $s4, $s2
	sw $s5, -84($fp)
	sw $s2, -36($fp)
	lw $s2, -84($fp)
	lw $s5, -20($fp)
	addi $sp, $sp, -4 
	add $s6, $s5, $s2
	sw $s6, -88($fp)
	sw $s5, -20($fp)
	sw $s2, -84($fp)
	li $s2, 1
	lw $s5, -36($fp)
	addi $sp, $sp, -4 
	sub $s6, $s5, $s2
	sw $s6, -92($fp)
	sw $s5, -36($fp)
	lw $s5, -92($fp)
	li $s6, 4
	addi $sp, $sp, -4 
	mul $t1, $s6, $s5
	sw $t1, -96($fp)
	sw $s5, -92($fp)
	lw $t1, -96($fp)
	lw $s5, -20($fp)
	addi $sp, $sp, -4 
	add $t2, $s5, $t1
	sw $t2, -100($fp)
	sw $s5, -20($fp)
	sw $t1, -96($fp)
	move $t1, $fp
	addi $t1, $t1, -88
	lw $t1, 0($t1)
	addi $sp, $sp, -4 
	move $t2, $fp
	addi $t2, $t2, -100
	lw $t2, 0($t2)
	lw $t2, 0($t2)
	sw $t2, 0($t1)
	sw $t2, -104($fp)
	li $t2, 1
	lw $s5, -36($fp)
	addi $sp, $sp, -4 
	sub $t4, $s5, $t2
	sw $t4, -108($fp)
	sw $s5, -36($fp)
	lw $t4, -108($fp)
	li $s5, 4
	addi $sp, $sp, -4 
	mul $s0, $s5, $t4
	sw $s0, -112($fp)
	sw $t4, -108($fp)
	lw $t4, -112($fp)
	lw $s0, -20($fp)
	addi $sp, $sp, -4 
	add $t0, $s0, $t4
	sw $t0, -116($fp)
	sw $s0, -20($fp)
	sw $t4, -112($fp)
	move $t0, $fp
	addi $t0, $t0, -116
	lw $t0, 0($t0)
	lw $t4, -80($fp)
	sw $t4, 0($t0)
	sw $t4, -80($fp)
	li $t4, 1
	lw $s0, -36($fp)
	addi $sp, $sp, -4 
	sub $s7, $s0, $t4
	sw $s7, -120($fp)
	sw $s0, -36($fp)
	lw $s0, -120($fp)
	lw $s7, -36($fp)
	move $s7, $s0
	sw $s7, -36($fp)
	sw $s0, -120($fp)
	j mylabel6
mylabel8:
	lw $s0, -12($fp)
	addi $sp, $sp, -4 
	addi $s7, $s0, 1
	sw $s7, -124($fp)
	sw $s0, -12($fp)
	lw $s0, -124($fp)
	lw $s7, -12($fp)
	move $s7, $s0
	sw $s7, -12($fp)
	sw $s0, -124($fp)
	j mylabel3
mylabel5:
	lw $s0, -12($fp)
	li $s0, 0
	sw $s0, -12($fp)
mylabel10:
	li $s0, 5
	lw $s7, -12($fp)
	blt $s7, $s0, mylabel11
	j mylabel12
mylabel11:
	lw $t3, -12($fp)
	li $t5, 4
	addi $sp, $sp, -4 
	mul $t6, $t5, $t3
	sw $t6, -128($fp)
	sw $t3, -12($fp)
	lw $t3, -128($fp)
	lw $t6, -20($fp)
	addi $sp, $sp, -4 
	add $t8, $t6, $t3
	sw $t8, -132($fp)
	sw $t6, -20($fp)
	sw $t3, -128($fp)
	addi $sp, $sp, -4 
	move $t3, $fp
	addi $t3, $t3, -132
	lw $t3, 0($t3)
	lw $t3, 0($t3)
	move $a0, $t3
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $t6, -12($fp)
	addi $sp, $sp, -4 
	addi $t8, $t6, 1
	sw $t8, -140($fp)
	sw $t6, -12($fp)
	lw $t6, -140($fp)
	lw $t8, -12($fp)
	move $t8, $t6
	sw $t8, -12($fp)
	sw $t6, -140($fp)
	j mylabel10
mylabel12:
	li $v0, 0 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
