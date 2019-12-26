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

search:
	addi $sp, $sp, -4 
	sw $fp, 0($sp) 
	move $fp, $sp 
	addi $sp, $sp, -40
	addi $sp, $sp, -4 
	sw $a0, -4($fp) 
	addi $sp, $sp, -20 
	addi $sp, $sp, -4 
	li $t0, 0
	sw $t0, -28($fp)
mylabel0:
	li $t1, 5
	lw $t2, -28($fp)
	blt $t2, $t1, mylabel1
	j mylabel2
mylabel1:
	lw $t3, -28($fp)
	li $t4, 4
	addi $sp, $sp, -4 
	mul $t5, $t4, $t3
	sw $t5, -32($fp)
	sw $t3, -28($fp)
	lw $t6, -32($fp)
	addi $sp, $sp, -4 
	move $t7, $fp
	addi $t7, -24
	addi $sp, $sp, -4 
	add $t8, $t7, $t6
	sw $t8, -40($fp)
	sw $t7, -36($fp)
	sw $t6, -32($fp)
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t9, $v0
	sw $t9, -44($fp)
	move $s0, $fp
	addi $s0, $s0, -40
	lw $s0, 0($s0)
	lw $s1, -44($fp)
	sw $s1, 0($s0)
	sw $s1, -44($fp)
	lw $s2, -28($fp)
	addi $sp, $sp, -4 
	addi $s3, $s2, 1
	sw $s3, -48($fp)
	sw $s2, -28($fp)
	lw $s4, -48($fp)
	lw $s5, -28($fp)
	move $s5, $s4
	sw $s5, -28($fp)
	sw $s4, -48($fp)
	j mylabel0
mylabel2:
	addi $sp, $sp, -4 
	li $s6, 0
	sw $s6, -52($fp)
	addi $sp, $sp, -4 
	li $s7, 4
	sw $s7, -56($fp)
mylabel3:
	lw $t0, -56($fp)
	lw $t3, -52($fp)
	ble $t3, $t0, mylabel4
	j mylabel5
mylabel4:
	lw $t5, -56($fp)
	lw $t6, -52($fp)
	addi $sp, $sp, -4 
	add $t7, $t6, $t5
	sw $t7, -60($fp)
	sw $t6, -52($fp)
	sw $t5, -56($fp)
	li $t5, 2
	lw $t6, -60($fp)
	div $t6, $t5
	addi $sp, $sp, -4 
	mflo $t7
	sw $t7, -64($fp)
	sw $t6, -60($fp)
	lw $t6, -64($fp)
	addi $sp, $sp, -4 
	move $t7, $t6
	sw $t7, -68($fp)
	sw $t6, -64($fp)
	lw $t6, -68($fp)
	li $t7, 4
	addi $sp, $sp, -4 
	mul $t8, $t7, $t6
	sw $t8, -72($fp)
	sw $t6, -68($fp)
	lw $t6, -72($fp)
	lw $t8, -36($fp)
	addi $sp, $sp, -4 
	add $t9, $t8, $t6
	sw $t9, -76($fp)
	sw $t8, -36($fp)
	sw $t6, -72($fp)
	addi $sp, $sp, -4 
	move $t6, $fp
	addi $t6, $t6, -76
	lw $t6, 0($t6)
	lw $t6, 0($t6)
	addi $sp, $sp, -4 
	move $t8, $t6
	sw $t8, -84($fp)
	sw $t6, -80($fp)
	lw $t6, -4($fp)
	lw $t8, -84($fp)
	beq $t8, $t6, mylabel6
	j mylabel7
mylabel6:
	lw $t9, -68($fp)
	move $v0, $t9 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
mylabel7:
	addi $sp, $sp, -4 
	li $s1, 0
	sw $s1, -88($fp)
	lw $s1, -52($fp)
	li $s2, 4
	addi $sp, $sp, -4 
	mul $s3, $s2, $s1
	sw $s3, -92($fp)
	sw $s1, -52($fp)
	lw $s1, -92($fp)
	lw $s3, -36($fp)
	addi $sp, $sp, -4 
	add $s4, $s3, $s1
	sw $s4, -96($fp)
	sw $s3, -36($fp)
	sw $s1, -92($fp)
	addi $sp, $sp, -4 
	move $s1, $fp
	addi $s1, $s1, -96
	lw $s1, 0($s1)
	lw $s1, 0($s1)
	lw $s3, -84($fp)
	bgt $s3, $s1, mylabel14
	j mylabel12
mylabel14:
	lw $s4, -52($fp)
	li $s5, 4
	addi $sp, $sp, -4 
	mul $s6, $s5, $s4
	sw $s6, -104($fp)
	sw $s4, -52($fp)
	lw $s4, -104($fp)
	lw $s6, -36($fp)
	addi $sp, $sp, -4 
	add $s7, $s6, $s4
	sw $s7, -108($fp)
	sw $s6, -36($fp)
	sw $s4, -104($fp)
	addi $sp, $sp, -4 
	move $s4, $fp
	addi $s4, $s4, -108
	lw $s4, 0($s4)
	lw $s4, 0($s4)
	lw $s6, -4($fp)
	bge $s6, $s4, mylabel13
	j mylabel12
mylabel13:
	lw $s7, -84($fp)
	lw $t1, -4($fp)
	blt $t1, $s7, mylabel11
	j mylabel12
mylabel11:
	lw $t2, -88($fp)
	li $t2, 1
	sw $t2, -88($fp)
mylabel12:
	li $t2, 0
	lw $t4, -88($fp)
	bne $t4, $t2, mylabel8
	j mylabel10
mylabel10:
	addi $sp, $sp, -4 
	li $s0, 0
	sw $s0, -116($fp)
	lw $s0, -52($fp)
	li $t0, 4
	addi $sp, $sp, -4 
	mul $t3, $t0, $s0
	sw $t3, -120($fp)
	lw $t3, -120($fp)
	lw $t5, -36($fp)
	addi $sp, $sp, -4 
	add $t7, $t5, $t3
	sw $t7, -124($fp)
	sw $t5, -36($fp)
	sw $t3, -120($fp)
	addi $sp, $sp, -4 
	move $t3, $fp
	addi $t3, $t3, -124
	lw $t3, 0($t3)
	lw $t3, 0($t3)
	lw $t5, -84($fp)
	blt $t5, $t3, mylabel17
	j mylabel16
mylabel17:
	addi $sp, $sp, -4 
	li $t7, 0
	sw $t7, -132($fp)
	lw $t7, -52($fp)
	li $t6, 4
	addi $sp, $sp, -4 
	mul $t8, $t6, $t7
	sw $t8, -136($fp)
	sw $t7, -52($fp)
	lw $t7, -136($fp)
	lw $t8, -36($fp)
	addi $sp, $sp, -4 
	add $t9, $t8, $t7
	sw $t9, -140($fp)
	sw $t8, -36($fp)
	sw $t7, -136($fp)
	addi $sp, $sp, -4 
	move $t7, $fp
	addi $t7, $t7, -140
	lw $t7, 0($t7)
	lw $t7, 0($t7)
	lw $t8, -4($fp)
	bge $t8, $t7, mylabel18
	j mylabel20
mylabel20:
	lw $t9, -84($fp)
	lw $s2, -4($fp)
	blt $s2, $t9, mylabel18
	j mylabel19
mylabel18:
	lw $s1, -132($fp)
	li $s1, 1
	sw $s1, -132($fp)
mylabel19:
	li $s1, 0
	lw $s3, -132($fp)
	bne $s3, $s1, mylabel15
	j mylabel16
mylabel15:
	lw $s5, -116($fp)
	li $s5, 1
	sw $s5, -116($fp)
mylabel16:
	li $s5, 0
	lw $s4, -116($fp)
	bne $s4, $s5, mylabel8
	j mylabel9
mylabel8:
	li $s6, 1
	lw $t1, -68($fp)
	addi $sp, $sp, -4 
	sub $s7, $t1, $s6
	sw $s7, -148($fp)
	sw $t1, -68($fp)
	lw $t1, -148($fp)
	lw $s7, -56($fp)
	move $s7, $t1
	sw $s7, -56($fp)
	sw $t1, -148($fp)
	j mylabel21
mylabel9:
	lw $t1, -68($fp)
	addi $sp, $sp, -4 
	addi $s7, $t1, 1
	sw $s7, -152($fp)
	sw $t1, -68($fp)
	lw $t1, -152($fp)
	lw $s7, -52($fp)
	move $s7, $t1
	sw $s7, -52($fp)
	sw $t1, -152($fp)
mylabel21:
	j mylabel3
mylabel5:
	li $t1, 1
	li $s7, 0
	addi $sp, $sp, -4 
	sub $t2, $s7, $t1
	sw $t2, -156($fp)
	lw $t2, -156($fp)
	move $v0, $t2 
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
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t4, $v0
	sw $t4, -4($fp)
	lw $t4, -4($fp)
	addi $sp, $sp, -4 
	move $t0, $t4
	sw $t0, -8($fp)
	sw $t4, -4($fp)
	lw $a0, -8($fp) 
	addi $sp, $sp, -4 
	sw $ra, 0($sp) 
	jal search
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t0, $v0
	sw $t0, -12($fp)
	lw $t1, -12($fp)
	move $a0, $t1
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
