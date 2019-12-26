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

my:
	addi $sp, $sp, -4 
	sw $fp, 0($sp) 
	move $fp, $sp 
	addi $sp, $sp, -4 
	sw $a0, -4($fp) 
	addi $sp, $sp, -4 
	sw $a1, -8($fp) 
	addi $sp, $sp, -4 
	sw $a2, -12($fp) 
	lw $t0, -4($fp)
	move $a0, $t0
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $t1, -8($fp)
	move $a0, $t1
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $t2, -12($fp)
	move $a0, $t2
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
main:
	addi $sp, $sp, -4 
	sw $fp, 0($sp) 
	move $fp, $sp 
	li $t0, 0
	li $t1, 1
	li $t2, 0
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	move $t3, $v0
	move $t4, $t3
	addi $t5, $t1, 9
	move $t0, $t5
	move $a0, $t0
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	sw $t0, -4($fp)
	addi $sp, $sp, -4 
	sw $t1, -8($fp)
	addi $sp, $sp, -4 
	sw $t2, -12($fp)
	addi $sp, $sp, -4 
	sw $t3, -16($fp)
	addi $sp, $sp, -4 
	sw $t4, -20($fp)
	addi $sp, $sp, -4 
	sw $t5, -24($fp)
	lw $a0, -20($fp) 
	lw $a1, -12($fp) 
	lw $a2, -4($fp) 
	addi $sp, $sp, -4 
	sw $ra, 0($sp) 
	jal my
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	move $t0, $v0
	lw $t1, -4($fp)
	move $t1, $t0
	li $v0, 0 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
