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
	addi $sp, $sp, -40
	addi $sp, $sp, -4 
	sw $a0, -4($fp) 
	addi $sp, $sp, -4 
	sw $a1, -8($fp) 
	addi $sp, $sp, -4 
	sw $a2, -12($fp) 
	addi $sp, $sp, -4 
	sw $a3, -16($fp) 
	addi $sp, $sp, -4 
	lw $a3, 8($fp) 
	sw $a3, -20($fp) 
	addi $sp, $sp, -4 
	lw $a3, 12($fp) 
	sw $a3, -24($fp) 
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
	lw $t3, -16($fp)
	move $a0, $t3
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $t4, -20($fp)
	move $a0, $t4
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $t5, -24($fp)
	move $a0, $t5
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
	addi $sp, $sp, -40
	addi $sp, $sp, -4 
	li $t6, 0
	sw $t6, -4($fp)
	addi $sp, $sp, -4 
	li $t7, 1
	sw $t7, -8($fp)
	addi $sp, $sp, -4 
	li $t8, 0
	sw $t8, -12($fp)
	addi $sp, $sp, -4 
	li $t9, 10
	sw $t9, -16($fp)
	addi $sp, $sp, -4 
	li $s0, 9
	sw $s0, -20($fp)
	addi $sp, $sp, -4 
	li $s1, 8
	sw $s1, -24($fp)
	addi $sp, $sp, -4 
	li $s2, 7
	sw $s2, -28($fp)
	addi $sp, $sp, -4 
	li $s3, 6
	sw $s3, -32($fp)
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $s4, $v0
	sw $s4, -36($fp)
	lw $s5, -36($fp)
	addi $sp, $sp, -4 
	move $s6, $s5
	sw $s6, -40($fp)
	sw $s5, -36($fp)
	lw $s7, -8($fp)
	addi $sp, $sp, -4 
	addi $t6, $s7, 9
	sw $t6, -44($fp)
	sw $s7, -8($fp)
	lw $t6, -44($fp)
	lw $t7, -4($fp)
	move $t7, $t6
	sw $t7, -4($fp)
	sw $t6, -44($fp)
	lw $t6, -4($fp)
	move $a0, $t6
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	li $t0, 60
	move $a0, $t0 
	lw $a1, -12($fp) 
	lw $a2, -40($fp) 
	lw $a3, -32($fp) 
	addi $sp, $sp, -4 
	addi $sp, $sp, -4 
	lw $t1, -28($fp) 
	sw $t1, 0($sp) 
	addi $sp, $sp, -4 
	lw $t1, -24($fp) 
	sw $t1, 0($sp) 
	addi $sp, $sp, -4 
	sw $ra, 0($sp) 
	jal my
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	move $t1, $v0
	sw $t1, -52($fp)
	lw $t2, -52($fp)
	lw $t3, -4($fp)
	move $t3, $t2
	sw $t3, -4($fp)
	sw $t2, -52($fp)
	li $v0, 0 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
