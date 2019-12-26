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
	addi $sp, $sp, -20 
	lw $t0, -20($fp)
	li $t0, 20 
	sw $t0, -20($fp) 
	li $t1, 0
	li $t2, 1
	li $t3, 0
mylabel0:
	li $t4, 5
	blt $t3, $t4, mylabel1
	j mylabel2
mylabel1:
	li $t5, 4
	mul $t6, $t5, $t3
	move $t7, $fp
	addi $t7, -20
	add $t8, $t7, $t6
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	move $t9, $v0
	move $s0, $t8
	sw $t9, 0($s0)
	addi $s1, $t3, 1
	move $t3, $s1
	j mylabel0
mylabel2:
	li $t3, 0
mylabel3:
	blt $t3, $t4, mylabel4
	j mylabel5
mylabel4:
	mul $s2, $t5, $t3
	add $s3, $t7, $s2
	lw $s4, 0($s3)
	move $a0, $s4
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $s5, $t3, 1
	move $t3, $s5
	j mylabel3
mylabel5:
