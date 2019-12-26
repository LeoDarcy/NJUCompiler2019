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

countSort:
	addi $sp, $sp, -4 
	sw $fp, 0($sp) 
	move $fp, $sp 
	addi $sp, $sp, -40
	addi $sp, $sp, -20 
	addi $sp, $sp, -40 
	addi $sp, $sp, -20 
	addi $sp, $sp, -4 
	li $t0, 0
	sw $t0, -84($fp)
mylabel0:
	li $t1, 10
	lw $t2, -84($fp)
	blt $t2, $t1, mylabel1
	j mylabel2
mylabel1:
	lw $t3, -84($fp)
	li $t4, 4
	addi $sp, $sp, -4 
	mul $t5, $t4, $t3
	sw $t5, -88($fp)
	sw $t3, -84($fp)
	lw $t6, -88($fp)
	addi $sp, $sp, -4 
	move $t7, $fp
	addi $t7, -60
	addi $sp, $sp, -4 
	add $t8, $t7, $t6
	sw $t8, -96($fp)
	sw $t7, -92($fp)
	sw $t6, -88($fp)
	move $t9, $fp
	addi $t9, $t9, -96
	lw $t9, 0($t9)
	li $s0, 0
	sw $s0, 0($t9)
	lw $s1, -84($fp)
	addi $sp, $sp, -4 
	addi $s2, $s1, 1
	sw $s2, -100($fp)
	sw $s1, -84($fp)
	lw $s3, -100($fp)
	lw $s4, -84($fp)
	move $s4, $s3
	sw $s4, -84($fp)
	sw $s3, -100($fp)
	j mylabel0
mylabel2:
	lw $s5, -84($fp)
	li $s5, 0
	sw $s5, -84($fp)
mylabel3:
	li $s6, 5
	lw $s7, -84($fp)
	blt $s7, $s6, mylabel4
	j mylabel5
mylabel4:
	lw $t0, -84($fp)
	li $t3, 4
	addi $sp, $sp, -4 
	mul $t5, $t3, $t0
	sw $t5, -104($fp)
	sw $t0, -84($fp)
	lw $t0, -104($fp)
	addi $sp, $sp, -4 
	move $t5, $fp
	addi $t5, -20
	addi $sp, $sp, -4 
	add $t6, $t5, $t0
	sw $t6, -112($fp)
	sw $t5, -108($fp)
	sw $t0, -104($fp)
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t0, $v0
	sw $t0, -116($fp)
	move $t0, $fp
	addi $t0, $t0, -112
	lw $t0, 0($t0)
	lw $t5, -116($fp)
	sw $t5, 0($t0)
	sw $t5, -116($fp)
	lw $t5, -84($fp)
	li $t6, 4
	addi $sp, $sp, -4 
	mul $t7, $t6, $t5
	sw $t7, -120($fp)
	sw $t5, -84($fp)
	lw $t5, -120($fp)
	lw $t7, -108($fp)
	addi $sp, $sp, -4 
	add $t8, $t7, $t5
	sw $t8, -124($fp)
	sw $t7, -108($fp)
	sw $t5, -120($fp)
	addi $sp, $sp, -4 
	move $t5, $fp
	addi $t5, $t5, -124
	lw $t5, 0($t5)
	lw $t5, 0($t5)
	li $t7, 4
	addi $sp, $sp, -4 
	mul $t8, $t7, $t5
	sw $t8, -132($fp)
	sw $t5, -128($fp)
	lw $t5, -132($fp)
	lw $t8, -92($fp)
	addi $sp, $sp, -4 
	add $s1, $t8, $t5
	sw $s1, -136($fp)
	sw $t8, -92($fp)
	sw $t5, -132($fp)
	lw $t5, -84($fp)
	li $t8, 4
	addi $sp, $sp, -4 
	mul $s1, $t8, $t5
	sw $s1, -140($fp)
	sw $t5, -84($fp)
	lw $t5, -140($fp)
	lw $s1, -108($fp)
	addi $sp, $sp, -4 
	add $s2, $s1, $t5
	sw $s2, -144($fp)
	sw $s1, -108($fp)
	sw $t5, -140($fp)
	addi $sp, $sp, -4 
	move $t5, $fp
	addi $t5, $t5, -144
	lw $t5, 0($t5)
	lw $t5, 0($t5)
	li $s1, 4
	addi $sp, $sp, -4 
	mul $s2, $s1, $t5
	sw $s2, -152($fp)
	sw $t5, -148($fp)
	lw $t5, -152($fp)
	lw $s2, -92($fp)
	addi $sp, $sp, -4 
	add $s3, $s2, $t5
	sw $s3, -156($fp)
	sw $s2, -92($fp)
	sw $t5, -152($fp)
	addi $sp, $sp, -4 
	move $t5, $fp
	addi $t5, $t5, -156
	lw $t5, 0($t5)
	lw $t5, 0($t5)
	addi $sp, $sp, -4 
	addi $s2, $t5, 1
	sw $s2, -164($fp)
	sw $t5, -160($fp)
	move $t5, $fp
	addi $t5, $t5, -136
	lw $t5, 0($t5)
	lw $s2, -164($fp)
	sw $s2, 0($t5)
	sw $s2, -164($fp)
	lw $s2, -84($fp)
	addi $sp, $sp, -4 
	addi $s3, $s2, 1
	sw $s3, -168($fp)
	sw $s2, -84($fp)
	lw $s2, -168($fp)
	lw $s3, -84($fp)
	move $s3, $s2
	sw $s3, -84($fp)
	sw $s2, -168($fp)
	j mylabel3
mylabel5:
	lw $s2, -84($fp)
	li $s2, 1
	sw $s2, -84($fp)
mylabel6:
	li $s2, 10
	lw $s3, -84($fp)
	blt $s3, $s2, mylabel7
	j mylabel8
mylabel7:
	lw $s4, -84($fp)
	li $s5, 4
	addi $sp, $sp, -4 
	mul $t1, $s5, $s4
	sw $t1, -172($fp)
	sw $s4, -84($fp)
	lw $t1, -172($fp)
	lw $s4, -92($fp)
	addi $sp, $sp, -4 
	add $t2, $s4, $t1
	sw $t2, -176($fp)
	sw $s4, -92($fp)
	sw $t1, -172($fp)
	lw $t1, -84($fp)
	li $t2, 4
	addi $sp, $sp, -4 
	mul $s4, $t2, $t1
	sw $s4, -180($fp)
	sw $t1, -84($fp)
	lw $t1, -180($fp)
	lw $s4, -92($fp)
	addi $sp, $sp, -4 
	add $t4, $s4, $t1
	sw $t4, -184($fp)
	sw $s4, -92($fp)
	sw $t1, -180($fp)
	li $t1, 1
	lw $t4, -84($fp)
	addi $sp, $sp, -4 
	sub $s4, $t4, $t1
	sw $s4, -188($fp)
	sw $t4, -84($fp)
	lw $t4, -188($fp)
	li $s4, 4
	addi $sp, $sp, -4 
	mul $t9, $s4, $t4
	sw $t9, -192($fp)
	sw $t4, -188($fp)
	lw $t4, -192($fp)
	lw $t9, -92($fp)
	addi $sp, $sp, -4 
	add $s0, $t9, $t4
	sw $s0, -196($fp)
	sw $t9, -92($fp)
	sw $t4, -192($fp)
	addi $sp, $sp, -4 
	move $t4, $fp
	addi $t4, $t4, -196
	lw $t4, 0($t4)
	lw $t4, 0($t4)
	addi $sp, $sp, -4 
	move $t9, $fp
	addi $t9, $t9, -184
	lw $t9, 0($t9)
	lw $t9, 0($t9)
	addi $sp, $sp, -4 
	add $s0, $t9, $t4
	sw $s0, -208($fp)
	sw $t9, -204($fp)
	sw $t4, -200($fp)
	move $t4, $fp
	addi $t4, $t4, -176
	lw $t4, 0($t4)
	lw $t9, -208($fp)
	sw $t9, 0($t4)
	sw $t9, -208($fp)
	lw $t9, -84($fp)
	addi $sp, $sp, -4 
	addi $s0, $t9, 1
	sw $s0, -212($fp)
	sw $t9, -84($fp)
	lw $t9, -212($fp)
	lw $s0, -84($fp)
	move $s0, $t9
	sw $s0, -84($fp)
	sw $t9, -212($fp)
	j mylabel6
mylabel8:
	lw $t9, -84($fp)
	li $t9, 0
	sw $t9, -84($fp)
mylabel9:
	li $t9, 10
	lw $s0, -84($fp)
	blt $s0, $t9, mylabel10
	j mylabel11
mylabel10:
	lw $s6, -84($fp)
	li $s7, 4
	addi $sp, $sp, -4 
	mul $t3, $s7, $s6
	sw $t3, -216($fp)
	lw $t3, -216($fp)
	lw $t0, -92($fp)
	addi $sp, $sp, -4 
	add $t6, $t0, $t3
	sw $t6, -220($fp)
	sw $t0, -92($fp)
	sw $t3, -216($fp)
	addi $sp, $sp, -4 
	move $t0, $fp
	addi $t0, $t0, -220
	lw $t0, 0($t0)
	lw $t0, 0($t0)
	move $a0, $t0
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $t3, -84($fp)
	addi $sp, $sp, -4 
	addi $t6, $t3, 1
	sw $t6, -228($fp)
	sw $t3, -84($fp)
	lw $t3, -228($fp)
	lw $t6, -84($fp)
	move $t6, $t3
	sw $t6, -84($fp)
	sw $t3, -228($fp)
	j mylabel9
mylabel11:
	lw $t3, -84($fp)
	li $t3, 0
	sw $t3, -84($fp)
mylabel12:
	li $t3, 5
	lw $t6, -84($fp)
	blt $t6, $t3, mylabel13
	j mylabel14
mylabel13:
	lw $t7, -84($fp)
	li $t8, 4
	addi $sp, $sp, -4 
	mul $s1, $t8, $t7
	sw $s1, -232($fp)
	sw $t7, -84($fp)
	lw $t7, -232($fp)
	lw $s1, -108($fp)
	addi $sp, $sp, -4 
	add $t5, $s1, $t7
	sw $t5, -236($fp)
	sw $s1, -108($fp)
	sw $t7, -232($fp)
	addi $sp, $sp, -4 
	move $t5, $fp
	addi $t5, $t5, -236
	lw $t5, 0($t5)
	lw $t5, 0($t5)
	li $t7, 4
	addi $sp, $sp, -4 
	mul $s1, $t7, $t5
	sw $s1, -244($fp)
	sw $t5, -240($fp)
	lw $t5, -244($fp)
	lw $s1, -92($fp)
	addi $sp, $sp, -4 
	add $s2, $s1, $t5
	sw $s2, -248($fp)
	sw $s1, -92($fp)
	sw $t5, -244($fp)
	li $t5, 1
	addi $sp, $sp, -4 
	move $s1, $fp
	addi $s1, $s1, -248
	lw $s1, 0($s1)
	lw $s1, 0($s1)
	addi $sp, $sp, -4 
	sub $s2, $s1, $t5
	sw $s2, -256($fp)
	sw $s1, -252($fp)
	lw $s1, -256($fp)
	li $s2, 4
	addi $sp, $sp, -4 
	mul $s3, $s2, $s1
	sw $s3, -260($fp)
	sw $s1, -256($fp)
	lw $s1, -260($fp)
	addi $sp, $sp, -4 
	move $s3, $fp
	addi $s3, -80
	addi $sp, $sp, -4 
	add $s5, $s3, $s1
	sw $s5, -268($fp)
	sw $s3, -264($fp)
	sw $s1, -260($fp)
	lw $s1, -84($fp)
	li $s3, 4
	addi $sp, $sp, -4 
	mul $s5, $s3, $s1
	sw $s5, -272($fp)
	sw $s1, -84($fp)
	lw $s1, -272($fp)
	lw $s5, -108($fp)
	addi $sp, $sp, -4 
	add $t2, $s5, $s1
	sw $t2, -276($fp)
	sw $s5, -108($fp)
	sw $s1, -272($fp)
	move $t2, $fp
	addi $t2, $t2, -268
	lw $t2, 0($t2)
	addi $sp, $sp, -4 
	move $s1, $fp
	addi $s1, $s1, -276
	lw $s1, 0($s1)
	lw $s1, 0($s1)
	sw $s1, 0($t2)
	sw $s1, -280($fp)
	lw $s1, -84($fp)
	li $s5, 4
	addi $sp, $sp, -4 
	mul $t1, $s5, $s1
	sw $t1, -284($fp)
	sw $s1, -84($fp)
	lw $t1, -284($fp)
	lw $s1, -108($fp)
	addi $sp, $sp, -4 
	add $s4, $s1, $t1
	sw $s4, -288($fp)
	sw $s1, -108($fp)
	sw $t1, -284($fp)
	addi $sp, $sp, -4 
	move $t1, $fp
	addi $t1, $t1, -288
	lw $t1, 0($t1)
	lw $t1, 0($t1)
	li $s1, 4
	addi $sp, $sp, -4 
	mul $s4, $s1, $t1
	sw $s4, -296($fp)
	sw $t1, -292($fp)
	lw $t1, -296($fp)
	lw $s4, -92($fp)
	addi $sp, $sp, -4 
	add $t4, $s4, $t1
	sw $t4, -300($fp)
	sw $s4, -92($fp)
	sw $t1, -296($fp)
	lw $t1, -84($fp)
	li $t4, 4
	addi $sp, $sp, -4 
	mul $s4, $t4, $t1
	sw $s4, -304($fp)
	sw $t1, -84($fp)
	lw $t1, -304($fp)
	lw $s4, -108($fp)
	addi $sp, $sp, -4 
	add $t9, $s4, $t1
	sw $t9, -308($fp)
	sw $s4, -108($fp)
	sw $t1, -304($fp)
	addi $sp, $sp, -4 
	move $t1, $fp
	addi $t1, $t1, -308
	lw $t1, 0($t1)
	lw $t1, 0($t1)
	li $t9, 4
	addi $sp, $sp, -4 
	mul $s4, $t9, $t1
	sw $s4, -316($fp)
	sw $t1, -312($fp)
	lw $t1, -316($fp)
	lw $s4, -92($fp)
	addi $sp, $sp, -4 
	add $s0, $s4, $t1
	sw $s0, -320($fp)
	sw $s4, -92($fp)
	sw $t1, -316($fp)
	li $t1, 1
	addi $sp, $sp, -4 
	move $s0, $fp
	addi $s0, $s0, -320
	lw $s0, 0($s0)
	lw $s0, 0($s0)
	addi $sp, $sp, -4 
	sub $s4, $s0, $t1
	sw $s4, -328($fp)
	sw $s0, -324($fp)
	move $s0, $fp
	addi $s0, $s0, -300
	lw $s0, 0($s0)
	lw $s4, -328($fp)
	sw $s4, 0($s0)
	sw $s4, -328($fp)
	lw $s4, -84($fp)
	addi $sp, $sp, -4 
	addi $s6, $s4, 1
	sw $s6, -332($fp)
	lw $s6, -332($fp)
	lw $s7, -84($fp)
	move $s7, $s6
	sw $s7, -84($fp)
	sw $s6, -332($fp)
	j mylabel12
mylabel14:
	lw $s6, -84($fp)
	li $s6, 0
	sw $s6, -84($fp)
mylabel15:
	li $s6, 5
	lw $s7, -84($fp)
	blt $s7, $s6, mylabel16
	j mylabel17
mylabel16:
	lw $t0, -84($fp)
	li $t3, 4
	addi $sp, $sp, -4 
	mul $t6, $t3, $t0
	sw $t6, -336($fp)
	lw $t6, -336($fp)
	lw $t8, -264($fp)
	addi $sp, $sp, -4 
	add $t7, $t8, $t6
	sw $t7, -340($fp)
	sw $t8, -264($fp)
	sw $t6, -336($fp)
	addi $sp, $sp, -4 
	move $t6, $fp
	addi $t6, $t6, -340
	lw $t6, 0($t6)
	lw $t6, 0($t6)
	move $a0, $t6
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $t7, -84($fp)
	addi $sp, $sp, -4 
	addi $t8, $t7, 1
	sw $t8, -348($fp)
	sw $t7, -84($fp)
	lw $t7, -348($fp)
	lw $t8, -84($fp)
	move $t8, $t7
	sw $t8, -84($fp)
	sw $t7, -348($fp)
	j mylabel15
mylabel17:
	li $v0, 0 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
bubbleSort:
	addi $sp, $sp, -4 
	sw $fp, 0($sp) 
	move $fp, $sp 
	addi $sp, $sp, -40
	addi $sp, $sp, -20 
	addi $sp, $sp, -4 
	li $t7, 0
	sw $t7, -24($fp)
mylabel18:
	li $t7, 5
	lw $t8, -24($fp)
	blt $t8, $t7, mylabel19
	j mylabel20
mylabel19:
	lw $t5, -24($fp)
	li $s2, 4
	addi $sp, $sp, -4 
	mul $s3, $s2, $t5
	sw $s3, -28($fp)
	sw $t5, -24($fp)
	lw $t5, -28($fp)
	addi $sp, $sp, -4 
	move $s3, $fp
	addi $s3, -20
	addi $sp, $sp, -4 
	add $t2, $s3, $t5
	sw $t2, -36($fp)
	sw $s3, -32($fp)
	sw $t5, -28($fp)
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t2, $v0
	sw $t2, -40($fp)
	move $t2, $fp
	addi $t2, $t2, -36
	lw $t2, 0($t2)
	lw $t5, -40($fp)
	sw $t5, 0($t2)
	sw $t5, -40($fp)
	lw $t5, -24($fp)
	addi $sp, $sp, -4 
	addi $s3, $t5, 1
	sw $s3, -44($fp)
	sw $t5, -24($fp)
	lw $t5, -44($fp)
	lw $s3, -24($fp)
	move $s3, $t5
	sw $s3, -24($fp)
	sw $t5, -44($fp)
	j mylabel18
mylabel20:
	addi $sp, $sp, -4 
	li $t5, 1
	sw $t5, -48($fp)
mylabel21:
	li $t5, 1
	lw $s3, -48($fp)
	beq $s3, $t5, mylabel22
	j mylabel23
mylabel22:
	lw $s5, -48($fp)
	li $s5, 0
	sw $s5, -48($fp)
	lw $s5, -24($fp)
	li $s5, 1
	sw $s5, -24($fp)
mylabel24:
	li $s5, 5
	lw $s1, -24($fp)
	blt $s1, $s5, mylabel25
	j mylabel26
mylabel25:
	lw $t4, -24($fp)
	li $t9, 4
	addi $sp, $sp, -4 
	mul $t1, $t9, $t4
	sw $t1, -52($fp)
	sw $t4, -24($fp)
	lw $t1, -52($fp)
	lw $t4, -32($fp)
	addi $sp, $sp, -4 
	add $s0, $t4, $t1
	sw $s0, -56($fp)
	sw $t4, -32($fp)
	sw $t1, -52($fp)
	li $t1, 1
	lw $t4, -24($fp)
	addi $sp, $sp, -4 
	sub $s0, $t4, $t1
	sw $s0, -60($fp)
	sw $t4, -24($fp)
	lw $t4, -60($fp)
	li $s0, 4
	addi $sp, $sp, -4 
	mul $s4, $s0, $t4
	sw $s4, -64($fp)
	sw $t4, -60($fp)
	lw $t4, -64($fp)
	lw $s4, -32($fp)
	addi $sp, $sp, -4 
	add $s6, $s4, $t4
	sw $s6, -68($fp)
	sw $s4, -32($fp)
	sw $t4, -64($fp)
	addi $sp, $sp, -4 
	move $t4, $fp
	addi $t4, $t4, -68
	lw $t4, 0($t4)
	lw $t4, 0($t4)
	addi $sp, $sp, -4 
	move $s4, $fp
	addi $s4, $s4, -56
	lw $s4, 0($s4)
	lw $s4, 0($s4)
	blt $s4, $t4, mylabel27
	j mylabel28
mylabel27:
	lw $s6, -48($fp)
	li $s6, 1
	sw $s6, -48($fp)
	li $s6, 1
	lw $s7, -24($fp)
	addi $sp, $sp, -4 
	sub $t0, $s7, $s6
	sw $t0, -80($fp)
	sw $s7, -24($fp)
	lw $t0, -80($fp)
	li $s7, 4
	addi $sp, $sp, -4 
	mul $t3, $s7, $t0
	sw $t3, -84($fp)
	sw $t0, -80($fp)
	lw $t0, -84($fp)
	lw $t3, -32($fp)
	addi $sp, $sp, -4 
	add $t6, $t3, $t0
	sw $t6, -88($fp)
	sw $t3, -32($fp)
	sw $t0, -84($fp)
	addi $sp, $sp, -4 
	move $t0, $fp
	addi $t0, $t0, -88
	lw $t0, 0($t0)
	lw $t0, 0($t0)
	addi $sp, $sp, -4 
	move $t3, $t0
	sw $t3, -96($fp)
	sw $t0, -92($fp)
	li $t0, 1
	lw $t3, -24($fp)
	addi $sp, $sp, -4 
	sub $t6, $t3, $t0
	sw $t6, -100($fp)
	sw $t3, -24($fp)
	lw $t3, -100($fp)
	li $t6, 4
	addi $sp, $sp, -4 
	mul $t7, $t6, $t3
	sw $t7, -104($fp)
	sw $t3, -100($fp)
	lw $t3, -104($fp)
	lw $t7, -32($fp)
	addi $sp, $sp, -4 
	add $t8, $t7, $t3
	sw $t8, -108($fp)
	sw $t7, -32($fp)
	sw $t3, -104($fp)
	lw $t3, -24($fp)
	li $t7, 4
	addi $sp, $sp, -4 
	mul $t8, $t7, $t3
	sw $t8, -112($fp)
	sw $t3, -24($fp)
	lw $t3, -112($fp)
	lw $t8, -32($fp)
	addi $sp, $sp, -4 
	add $s2, $t8, $t3
	sw $s2, -116($fp)
	sw $t8, -32($fp)
	sw $t3, -112($fp)
	move $t3, $fp
	addi $t3, $t3, -108
	lw $t3, 0($t3)
	addi $sp, $sp, -4 
	move $t8, $fp
	addi $t8, $t8, -116
	lw $t8, 0($t8)
	lw $t8, 0($t8)
	sw $t8, 0($t3)
	sw $t8, -120($fp)
	lw $t8, -24($fp)
	li $s2, 4
	addi $sp, $sp, -4 
	mul $t2, $s2, $t8
	sw $t2, -124($fp)
	sw $t8, -24($fp)
	lw $t2, -124($fp)
	lw $t8, -32($fp)
	addi $sp, $sp, -4 
	add $t5, $t8, $t2
	sw $t5, -128($fp)
	sw $t8, -32($fp)
	sw $t2, -124($fp)
	move $t2, $fp
	addi $t2, $t2, -128
	lw $t2, 0($t2)
	lw $t5, -96($fp)
	sw $t5, 0($t2)
	sw $t5, -96($fp)
mylabel28:
	lw $t5, -24($fp)
	addi $sp, $sp, -4 
	addi $t8, $t5, 1
	sw $t8, -132($fp)
	sw $t5, -24($fp)
	lw $t5, -132($fp)
	lw $t8, -24($fp)
	move $t8, $t5
	sw $t8, -24($fp)
	sw $t5, -132($fp)
	j mylabel24
mylabel26:
	j mylabel21
mylabel23:
	lw $t5, -24($fp)
	li $t5, 0
	sw $t5, -24($fp)
mylabel29:
	li $t5, 5
	lw $t8, -24($fp)
	blt $t8, $t5, mylabel30
	j mylabel31
mylabel30:
	lw $s3, -24($fp)
	li $s1, 4
	addi $sp, $sp, -4 
	mul $s5, $s1, $s3
	sw $s5, -136($fp)
	lw $s5, -136($fp)
	lw $t9, -32($fp)
	addi $sp, $sp, -4 
	add $t1, $t9, $s5
	sw $t1, -140($fp)
	sw $t9, -32($fp)
	sw $s5, -136($fp)
	addi $sp, $sp, -4 
	move $t1, $fp
	addi $t1, $t1, -140
	lw $t1, 0($t1)
	lw $t1, 0($t1)
	move $a0, $t1
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal write
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	lw $t9, -24($fp)
	addi $sp, $sp, -4 
	addi $s5, $t9, 1
	sw $s5, -148($fp)
	sw $t9, -24($fp)
	lw $t9, -148($fp)
	lw $s5, -24($fp)
	move $s5, $t9
	sw $s5, -24($fp)
	sw $t9, -148($fp)
	j mylabel29
mylabel31:
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
	sw $ra, 0($sp) 
	jal countSort
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t0, $v0
	sw $t0, -4($fp)
	addi $sp, $sp, -4 
	sw $ra, 0($sp) 
	jal bubbleSort
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t0, $v0
	sw $t0, -8($fp)
	li $v0, 0 
	move $sp, $fp 
	lw $fp, 0($sp) 
	addi $sp, $sp, 4 
	jr $ra
