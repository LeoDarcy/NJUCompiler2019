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
	addi $sp, $sp, -20 
	addi $sp, $sp, -4 
	li $t0, 0
	addi $sp, $sp, -4 
	li $t1, 1
	addi $sp, $sp, -4 
	li $t2, 0
mylabel0:
	li $t3, 5
	blt $t2, $t3, mylabel1
	j mylabel2
mylabel1:
	li $t4, 4
	addi $sp, $sp, -4 
	mul $t5, $t4, $t2
	addi $sp, $sp, -4 
	move $t6, $fp
	addi $t6, -20
	addi $sp, $sp, -4 
	add $t7, $t6, $t5
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t8, $v0
	move $t9, $t7
	sw $t8, 0($t9)
	addi $sp, $sp, -4 
	addi $s0, $t2, 1
	move $t2, $s0
	j mylabel0
mylabel2:
	li $t2, 0
mylabel3:
	li $s1, 5
	blt $t2, $s1, mylabel4
	j mylabel5
mylabel4:
	li $s2, 4
	addi $sp, $sp, -4 
	mul $s3, $s2, $t2
	addi $sp, $sp, -4 
	add $s4, $t6, $s3
	addi $sp, $sp, -4 
	lw $s5, 0($s4)
	move $a0, $s5
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	addi $s6, $t2, 1
	move $t2, $s6
	j mylabel3
mylabel5:
	li $v0, 0 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
