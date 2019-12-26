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
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
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
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t3, $v0
	sw $t3, -12($fp)
	lw $t4, -12($fp)
	addi $sp, $sp, -4 
	move $t5, $t4
	sw $t5, -16($fp)
	sw $t4, -12($fp)
	li $t6, 100
	lw $t7, -8($fp)
	bgt $t7, $t6, mylabel0
	j mylabel1
mylabel0:
	li $t8, 50
	lw $t9, -16($fp)
	blt $t9, $t8, mylabel2
	j mylabel3
mylabel2:
	lw $s0, -8($fp)
	lw $s1, -16($fp)
	addi $sp, $sp, -4 
	add $s2, $s1, $s0
	sw $s2, -20($fp)
	sw $s1, -16($fp)
	sw $s0, -8($fp)
	lw $s3, -20($fp)
	move $a0, $s3
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	j mylabel4
mylabel3:
	lw $s4, -8($fp)
	lw $s5, -16($fp)
	addi $sp, $sp, -4 
	sub $s6, $s5, $s4
	sw $s6, -24($fp)
	sw $s5, -16($fp)
	sw $s4, -8($fp)
	lw $s7, -24($fp)
	move $a0, $s7
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
mylabel4:
	j mylabel5
mylabel1:
	li $t0, 100
	lw $t1, -8($fp)
	beq $t1, $t0, mylabel6
	j mylabel7
mylabel6:
	li $t2, 100
	lw $t3, -16($fp)
	blt $t3, $t2, mylabel8
	j mylabel9
mylabel8:
	lw $t4, -16($fp)
	move $a0, $t4
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	j mylabel10
mylabel9:
	li $t5, 100
	lw $s0, -16($fp)
	addi $sp, $sp, -4 
	sub $s1, $s0, $t5
	sw $s1, -28($fp)
	sw $s0, -16($fp)
	lw $s0, -28($fp)
	move $a0, $s0
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
mylabel10:
	j mylabel11
mylabel7:
	li $s1, 100
	lw $s2, -8($fp)
	blt $s2, $s1, mylabel12
	j mylabel13
mylabel12:
	lw $s4, -8($fp)
	lw $s5, -16($fp)
	addi $sp, $sp, -4 
	add $s6, $s5, $s4
	sw $s6, -32($fp)
	sw $s5, -16($fp)
	sw $s4, -8($fp)
	li $s4, 100
	lw $s5, -32($fp)
	bgt $s5, $s4, mylabel14
	j mylabel15
mylabel14:
	lw $s6, -8($fp)
	addi $sp, $sp, -4 
	addi $t6, $s6, 100
	sw $t6, -36($fp)
	sw $s6, -8($fp)
	lw $t6, -36($fp)
	move $a0, $t6
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	j mylabel16
mylabel15:
	li $s6, 100
	move $a0, $s6
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
mylabel16:
mylabel13:
mylabel11:
mylabel5:
	lw $t7, -16($fp)
	lw $t8, -8($fp)
	addi $sp, $sp, -4 
	add $t9, $t8, $t7
	sw $t9, -40($fp)
	sw $t8, -8($fp)
	lw $t8, -40($fp)
	move $a0, $t8
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
