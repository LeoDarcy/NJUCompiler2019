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
	addi $sp, $sp, -32 
	addi $sp, $sp, -32 
	addi $sp, $sp, -32 
	addi $sp, $sp, -32 
	addi $sp, $sp, -4 
	li $t0, 0
	sw $t0, -132($fp)
	addi $sp, $sp, -4 
	li $t1, 0
	sw $t1, -136($fp)
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	jal read
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	addi $sp, $sp, -4 
	move $t2, $v0
	sw $t2, -140($fp)
	lw $t3, -140($fp)
	addi $sp, $sp, -4 
	move $t4, $t3
	sw $t4, -144($fp)
	sw $t3, -140($fp)
mylabel0:
	lw $t5, -144($fp)
	lw $t6, -136($fp)
	blt $t6, $t5, mylabel1
	j mylabel2
mylabel1:
	lw $t7, -136($fp)
	li $t8, 4
	addi $sp, $sp, -4 
	mul $t9, $t8, $t7
	sw $t9, -148($fp)
	sw $t7, -136($fp)
	lw $s0, -148($fp)
	addi $sp, $sp, -4 
	move $s1, $fp
	addi $s1, -32
	addi $sp, $sp, -4 
	add $s2, $s1, $s0
	sw $s2, -156($fp)
	sw $s1, -152($fp)
	sw $s0, -148($fp)
	li $s3, 1
	li $s4, 0
	addi $sp, $sp, -4 
	sub $s5, $s4, $s3
	sw $s5, -160($fp)
	move $s6, $fp
	addi $s6, $s6, -156
	lw $s6, 0($s6)
	lw $s7, -160($fp)
	sw $s7, 0($s6)
	sw $s7, -160($fp)
	lw $t0, -136($fp)
	addi $sp, $sp, -4 
	addi $t1, $t0, 1
	sw $t1, -164($fp)
	sw $t0, -136($fp)
	lw $t0, -164($fp)
	lw $t1, -136($fp)
	move $t1, $t0
	sw $t1, -136($fp)
	sw $t0, -164($fp)
	j mylabel0
mylabel2:
	lw $t0, -136($fp)
	li $t0, 0
	sw $t0, -136($fp)
	addi $sp, $sp, -4 
	li $t0, 1
	sw $t0, -168($fp)
mylabel3:
	li $t0, 1
	lw $t1, -168($fp)
	beq $t1, $t0, mylabel4
	j mylabel5
mylabel4:
	lw $t2, -144($fp)
	lw $t3, -136($fp)
	beq $t3, $t2, mylabel6
	j mylabel7
mylabel6:
	addi $sp, $sp, -4 
	li $t4, 1
	sw $t4, -172($fp)
	addi $sp, $sp, -4 
	li $t4, 0
	sw $t4, -176($fp)
mylabel8:
	lw $t4, -144($fp)
	lw $t7, -176($fp)
	blt $t7, $t4, mylabel9
	j mylabel10
mylabel9:
	lw $t9, -176($fp)
	li $s0, 4
	addi $sp, $sp, -4 
	mul $s1, $s0, $t9
	sw $s1, -180($fp)
	sw $t9, -176($fp)
	lw $t9, -180($fp)
	addi $sp, $sp, -4 
	move $s1, $fp
	addi $s1, -64
	addi $sp, $sp, -4 
	add $s2, $s1, $t9
	sw $s2, -188($fp)
	sw $s1, -184($fp)
	sw $t9, -180($fp)
	move $t9, $fp
	addi $t9, $t9, -188
	lw $t9, 0($t9)
	li $s1, 1
	sw $s1, 0($t9)
	lw $s2, -176($fp)
	li $s5, 4
	addi $sp, $sp, -4 
	mul $s7, $s5, $s2
	sw $s7, -192($fp)
	sw $s2, -176($fp)
	lw $s2, -192($fp)
	addi $sp, $sp, -4 
	move $s7, $fp
	addi $s7, -96
	addi $sp, $sp, -4 
	add $t5, $s7, $s2
	sw $t5, -200($fp)
	sw $s7, -196($fp)
	sw $s2, -192($fp)
	move $t5, $fp
	addi $t5, $t5, -200
	lw $t5, 0($t5)
	li $s2, 1
	sw $s2, 0($t5)
	lw $s7, -176($fp)
	li $t6, 4
	addi $sp, $sp, -4 
	mul $t8, $t6, $s7
	sw $t8, -204($fp)
	sw $s7, -176($fp)
	lw $t8, -204($fp)
	addi $sp, $sp, -4 
	move $s7, $fp
	addi $s7, -128
	addi $sp, $sp, -4 
	add $s3, $s7, $t8
	sw $s3, -212($fp)
	sw $s7, -208($fp)
	sw $t8, -204($fp)
	move $t8, $fp
	addi $t8, $t8, -212
	lw $t8, 0($t8)
	li $s3, 1
	sw $s3, 0($t8)
	lw $s7, -176($fp)
	addi $sp, $sp, -4 
	addi $s4, $s7, 1
	sw $s4, -216($fp)
	sw $s7, -176($fp)
	lw $s4, -216($fp)
	lw $s7, -176($fp)
	move $s7, $s4
	sw $s7, -176($fp)
	sw $s4, -216($fp)
	j mylabel8
mylabel10:
	lw $s4, -176($fp)
	li $s4, 0
	sw $s4, -176($fp)
mylabel11:
	lw $s4, -144($fp)
	lw $s7, -176($fp)
	blt $s7, $s4, mylabel12
	j mylabel13
mylabel12:
	lw $s6, -176($fp)
	li $t0, 4
	addi $sp, $sp, -4 
	mul $t1, $t0, $s6
	sw $t1, -220($fp)
	sw $s6, -176($fp)
	lw $t1, -220($fp)
	lw $s6, -152($fp)
	addi $sp, $sp, -4 
	add $t2, $s6, $t1
	sw $t2, -224($fp)
	sw $s6, -152($fp)
	sw $t1, -220($fp)
	addi $sp, $sp, -4 
	move $t1, $fp
	addi $t1, $t1, -224
	lw $t1, 0($t1)
	lw $t1, 0($t1)
	li $t2, 4
	addi $sp, $sp, -4 
	mul $s6, $t2, $t1
	sw $s6, -232($fp)
	sw $t1, -228($fp)
	lw $t1, -232($fp)
	lw $s6, -184($fp)
	addi $sp, $sp, -4 
	add $t3, $s6, $t1
	sw $t3, -236($fp)
	sw $s6, -184($fp)
	sw $t1, -232($fp)
	li $t1, 1
	addi $sp, $sp, -4 
	move $t3, $fp
	addi $t3, $t3, -236
	lw $t3, 0($t3)
	lw $t3, 0($t3)
	bne $t3, $t1, mylabel14
	j mylabel17
mylabel17:
	lw $s6, -176($fp)
	li $t4, 4
	addi $sp, $sp, -4 
	mul $t7, $t4, $s6
	sw $t7, -244($fp)
	lw $t7, -244($fp)
	lw $s0, -152($fp)
	addi $sp, $sp, -4 
	add $t9, $s0, $t7
	sw $t9, -248($fp)
	sw $s0, -152($fp)
	sw $t7, -244($fp)
	addi $sp, $sp, -4 
	move $t7, $fp
	addi $t7, $t7, -248
	lw $t7, 0($t7)
	lw $t7, 0($t7)
	li $t9, 4
	addi $sp, $sp, -4 
	mul $s0, $t9, $t7
	sw $s0, -256($fp)
	sw $t7, -252($fp)
	lw $t7, -256($fp)
	lw $s0, -196($fp)
	addi $sp, $sp, -4 
	add $s1, $s0, $t7
	sw $s1, -260($fp)
	sw $s0, -196($fp)
	sw $t7, -256($fp)
	li $t7, 1
	addi $sp, $sp, -4 
	move $s0, $fp
	addi $s0, $s0, -260
	lw $s0, 0($s0)
	lw $s0, 0($s0)
	bne $s0, $t7, mylabel14
	j mylabel16
mylabel16:
	lw $s1, -176($fp)
	li $s5, 4
	addi $sp, $sp, -4 
	mul $t5, $s5, $s1
	sw $t5, -268($fp)
	sw $s1, -176($fp)
	lw $t5, -268($fp)
	lw $s1, -152($fp)
	addi $sp, $sp, -4 
	add $s2, $s1, $t5
	sw $s2, -272($fp)
	sw $s1, -152($fp)
	sw $t5, -268($fp)
	addi $sp, $sp, -4 
	move $t5, $fp
	addi $t5, $t5, -272
	lw $t5, 0($t5)
	lw $t5, 0($t5)
	li $s1, 4
	addi $sp, $sp, -4 
	mul $s2, $s1, $t5
	sw $s2, -280($fp)
	sw $t5, -276($fp)
	lw $t5, -280($fp)
	lw $s2, -208($fp)
	addi $sp, $sp, -4 
	add $t6, $s2, $t5
	sw $t6, -284($fp)
	sw $s2, -208($fp)
	sw $t5, -280($fp)
	li $t5, 1
	addi $sp, $sp, -4 
	move $t6, $fp
	addi $t6, $t6, -284
	lw $t6, 0($t6)
	lw $t6, 0($t6)
	bne $t6, $t5, mylabel14
	j mylabel15
mylabel14:
	lw $s2, -172($fp)
	li $s2, 0
	sw $s2, -172($fp)
	lw $s2, -144($fp)
	lw $t8, -176($fp)
	move $t8, $s2
	sw $t8, -176($fp)
	sw $s2, -144($fp)
	j mylabel18
mylabel15:
	lw $t8, -176($fp)
	li $s2, 4
	addi $sp, $sp, -4 
	mul $s3, $s2, $t8
	sw $s3, -292($fp)
	sw $t8, -176($fp)
	lw $t8, -292($fp)
	lw $s3, -152($fp)
	addi $sp, $sp, -4 
	add $s4, $s3, $t8
	sw $s4, -296($fp)
	sw $s3, -152($fp)
	sw $t8, -292($fp)
	addi $sp, $sp, -4 
	move $t8, $fp
	addi $t8, $t8, -296
	lw $t8, 0($t8)
	lw $t8, 0($t8)
	li $s3, 4
	addi $sp, $sp, -4 
	mul $s4, $s3, $t8
	sw $s4, -304($fp)
	sw $t8, -300($fp)
	lw $t8, -304($fp)
	lw $s4, -184($fp)
	addi $sp, $sp, -4 
	add $s7, $s4, $t8
	sw $s7, -308($fp)
	sw $s4, -184($fp)
	sw $t8, -304($fp)
	move $t8, $fp
	addi $t8, $t8, -308
	lw $t8, 0($t8)
	li $s4, 0
	sw $s4, 0($t8)
	addi $sp, $sp, -4 
	li $s7, 0
	sw $s7, -312($fp)
mylabel19:
	li $s7, 1
	lw $t0, -144($fp)
	addi $sp, $sp, -4 
	sub $t2, $t0, $s7
	sw $t2, -316($fp)
	sw $t0, -144($fp)
	lw $t0, -316($fp)
	lw $t2, -312($fp)
	blt $t2, $t0, mylabel20
	j mylabel21
mylabel20:
	lw $t1, -312($fp)
	li $t3, 4
	addi $sp, $sp, -4 
	mul $t4, $t3, $t1
	sw $t4, -320($fp)
	sw $t1, -312($fp)
	lw $t1, -320($fp)
	lw $t4, -196($fp)
	addi $sp, $sp, -4 
	add $s6, $t4, $t1
	sw $s6, -324($fp)
	sw $t4, -196($fp)
	sw $t1, -320($fp)
	lw $t1, -312($fp)
	addi $sp, $sp, -4 
	addi $t4, $t1, 1
	sw $t4, -328($fp)
	sw $t1, -312($fp)
	lw $t1, -328($fp)
	li $t4, 4
	addi $sp, $sp, -4 
	mul $s6, $t4, $t1
	sw $s6, -332($fp)
	sw $t1, -328($fp)
	lw $t1, -332($fp)
	lw $s6, -196($fp)
	addi $sp, $sp, -4 
	add $t9, $s6, $t1
	sw $t9, -336($fp)
	sw $s6, -196($fp)
	sw $t1, -332($fp)
	move $t1, $fp
	addi $t1, $t1, -324
	lw $t1, 0($t1)
	addi $sp, $sp, -4 
	move $t9, $fp
	addi $t9, $t9, -336
	lw $t9, 0($t9)
	lw $t9, 0($t9)
	sw $t9, 0($t1)
	sw $t9, -340($fp)
	lw $t9, -312($fp)
	addi $sp, $sp, -4 
	addi $s6, $t9, 1
	sw $s6, -344($fp)
	sw $t9, -312($fp)
	lw $t9, -344($fp)
	lw $s6, -312($fp)
	move $s6, $t9
	sw $s6, -312($fp)
	sw $t9, -344($fp)
	j mylabel19
mylabel21:
	li $t9, 1
	lw $s6, -144($fp)
	addi $sp, $sp, -4 
	sub $t7, $s6, $t9
	sw $t7, -348($fp)
	sw $s6, -144($fp)
	lw $t7, -348($fp)
	li $s6, 4
	addi $sp, $sp, -4 
	mul $s0, $s6, $t7
	sw $s0, -352($fp)
	sw $t7, -348($fp)
	lw $t7, -352($fp)
	lw $s0, -196($fp)
	addi $sp, $sp, -4 
	add $s5, $s0, $t7
	sw $s5, -356($fp)
	sw $s0, -196($fp)
	sw $t7, -352($fp)
	move $t7, $fp
	addi $t7, $t7, -356
	lw $t7, 0($t7)
	li $s0, 1
	sw $s0, 0($t7)
	lw $s5, -176($fp)
	li $s1, 4
	addi $sp, $sp, -4 
	mul $t5, $s1, $s5
	sw $t5, -360($fp)
	sw $s5, -176($fp)
	lw $t5, -360($fp)
	lw $s5, -152($fp)
	addi $sp, $sp, -4 
	add $t6, $s5, $t5
	sw $t6, -364($fp)
	sw $s5, -152($fp)
	sw $t5, -360($fp)
	li $t5, 0
	addi $sp, $sp, -4 
	move $t6, $fp
	addi $t6, $t6, -364
	lw $t6, 0($t6)
	lw $t6, 0($t6)
	bne $t6, $t5, mylabel22
	j mylabel23
mylabel22:
	lw $s5, -176($fp)
	li $s2, 4
	addi $sp, $sp, -4 
	mul $s3, $s2, $s5
	sw $s3, -372($fp)
	sw $s5, -176($fp)
	lw $s3, -372($fp)
	lw $s5, -152($fp)
	addi $sp, $sp, -4 
	add $t8, $s5, $s3
	sw $t8, -376($fp)
	sw $s5, -152($fp)
	sw $s3, -372($fp)
	li $t8, 1
	addi $sp, $sp, -4 
	move $s3, $fp
	addi $s3, $s3, -376
	lw $s3, 0($s3)
	lw $s3, 0($s3)
	addi $sp, $sp, -4 
	sub $s5, $s3, $t8
	sw $s5, -384($fp)
	sw $s3, -380($fp)
	lw $s3, -384($fp)
	li $s5, 4
	addi $sp, $sp, -4 
	mul $s4, $s5, $s3
	sw $s4, -388($fp)
	sw $s3, -384($fp)
	lw $s3, -388($fp)
	lw $s4, -196($fp)
	addi $sp, $sp, -4 
	add $s7, $s4, $s3
	sw $s7, -392($fp)
	sw $s4, -196($fp)
	sw $s3, -388($fp)
	move $s3, $fp
	addi $s3, $s3, -392
	lw $s3, 0($s3)
	li $s4, 0
	sw $s4, 0($s3)
mylabel23:
	li $s7, 1
	lw $t0, -144($fp)
	addi $sp, $sp, -4 
	sub $t2, $t0, $s7
	sw $t2, -396($fp)
	sw $t0, -144($fp)
	lw $t0, -396($fp)
	lw $t2, -312($fp)
	move $t2, $t0
	sw $t2, -312($fp)
	sw $t0, -396($fp)
mylabel24:
	li $t0, 0
	lw $t2, -312($fp)
	bgt $t2, $t0, mylabel25
	j mylabel26
mylabel25:
	lw $t3, -312($fp)
	li $t4, 4
	addi $sp, $sp, -4 
	mul $t1, $t4, $t3
	sw $t1, -400($fp)
	sw $t3, -312($fp)
	lw $t1, -400($fp)
	lw $t3, -208($fp)
	addi $sp, $sp, -4 
	add $t9, $t3, $t1
	sw $t9, -404($fp)
	sw $t3, -208($fp)
	sw $t1, -400($fp)
	li $t1, 1
	lw $t3, -312($fp)
	addi $sp, $sp, -4 
	sub $t9, $t3, $t1
	sw $t9, -408($fp)
	sw $t3, -312($fp)
	lw $t3, -408($fp)
	li $t9, 4
	addi $sp, $sp, -4 
	mul $s6, $t9, $t3
	sw $s6, -412($fp)
	sw $t3, -408($fp)
	lw $t3, -412($fp)
	lw $s6, -208($fp)
	addi $sp, $sp, -4 
	add $t7, $s6, $t3
	sw $t7, -416($fp)
	sw $s6, -208($fp)
	sw $t3, -412($fp)
	move $t3, $fp
	addi $t3, $t3, -404
	lw $t3, 0($t3)
	addi $sp, $sp, -4 
	move $t7, $fp
	addi $t7, $t7, -416
	lw $t7, 0($t7)
	lw $t7, 0($t7)
	sw $t7, 0($t3)
	sw $t7, -420($fp)
	li $t7, 1
	lw $s6, -312($fp)
	addi $sp, $sp, -4 
	sub $s0, $s6, $t7
	sw $s0, -424($fp)
	sw $s6, -312($fp)
	lw $s0, -424($fp)
	lw $s6, -312($fp)
	move $s6, $s0
	sw $s6, -312($fp)
	sw $s0, -424($fp)
	j mylabel24
mylabel26:
	lw $s0, -208($fp)
	addi $sp, $sp, -4 
	addi $s6, $s0, 0
	sw $s6, -428($fp)
	sw $s0, -208($fp)
	move $s0, $fp
	addi $s0, $s0, -428
	lw $s0, 0($s0)
	li $s6, 1
	sw $s6, 0($s0)
	lw $s1, -176($fp)
	li $t5, 4
	addi $sp, $sp, -4 
	mul $t6, $t5, $s1
	sw $t6, -432($fp)
	sw $s1, -176($fp)
	lw $t6, -432($fp)
	lw $s1, -152($fp)
	addi $sp, $sp, -4 
	add $s2, $s1, $t6
	sw $s2, -436($fp)
	sw $s1, -152($fp)
	sw $t6, -432($fp)
	li $t6, 1
	lw $s1, -144($fp)
	addi $sp, $sp, -4 
	sub $s2, $s1, $t6
	sw $s2, -440($fp)
	sw $s1, -144($fp)
	lw $s1, -440($fp)
	addi $sp, $sp, -4 
	move $s2, $fp
	addi $s2, $s2, -436
	lw $s2, 0($s2)
	lw $s2, 0($s2)
	bne $s2, $s1, mylabel27
	j mylabel28
mylabel27:
	lw $t8, -176($fp)
	li $s5, 4
	addi $sp, $sp, -4 
	mul $s3, $s5, $t8
	sw $s3, -448($fp)
	sw $t8, -176($fp)
	lw $t8, -448($fp)
	lw $s3, -152($fp)
	addi $sp, $sp, -4 
	add $s4, $s3, $t8
	sw $s4, -452($fp)
	sw $s3, -152($fp)
	sw $t8, -448($fp)
	addi $sp, $sp, -4 
	move $t8, $fp
	addi $t8, $t8, -452
	lw $t8, 0($t8)
	lw $t8, 0($t8)
	addi $sp, $sp, -4 
	addi $s3, $t8, 1
	sw $s3, -460($fp)
	sw $t8, -456($fp)
	lw $t8, -460($fp)
	li $s3, 4
	addi $sp, $sp, -4 
	mul $s4, $s3, $t8
	sw $s4, -464($fp)
	sw $t8, -460($fp)
	lw $t8, -464($fp)
	lw $s4, -208($fp)
	addi $sp, $sp, -4 
	add $s7, $s4, $t8
	sw $s7, -468($fp)
	sw $s4, -208($fp)
	sw $t8, -464($fp)
	move $t8, $fp
	addi $t8, $t8, -468
	lw $t8, 0($t8)
	li $s4, 0
	sw $s4, 0($t8)
mylabel28:
	lw $s7, -176($fp)
	addi $sp, $sp, -4 
	addi $t0, $s7, 1
	sw $t0, -472($fp)
	sw $s7, -176($fp)
	lw $t0, -472($fp)
	lw $s7, -176($fp)
	move $s7, $t0
	sw $s7, -176($fp)
	sw $t0, -472($fp)
mylabel18:
	j mylabel11
mylabel13:
	li $t0, 1
	lw $s7, -172($fp)
	beq $s7, $t0, mylabel29
	j mylabel30
mylabel29:
	lw $t2, -132($fp)
	addi $sp, $sp, -4 
	addi $t4, $t2, 1
	sw $t4, -476($fp)
	sw $t2, -132($fp)
	lw $t2, -476($fp)
	lw $t4, -132($fp)
	move $t4, $t2
	sw $t4, -132($fp)
	sw $t2, -476($fp)
mylabel30:
	li $t2, 1
	lw $t4, -136($fp)
	addi $sp, $sp, -4 
	sub $t1, $t4, $t2
	sw $t1, -480($fp)
	sw $t4, -136($fp)
	lw $t1, -480($fp)
	lw $t4, -136($fp)
	move $t4, $t1
	sw $t4, -136($fp)
	sw $t1, -480($fp)
	j mylabel31
mylabel7:
mylabel32:
	li $t1, 0
	lw $t4, -136($fp)
	bge $t4, $t1, mylabel35
	j mylabel34
mylabel35:
	lw $t9, -136($fp)
	li $t3, 4
	addi $sp, $sp, -4 
	mul $t7, $t3, $t9
	sw $t7, -484($fp)
	sw $t9, -136($fp)
	lw $t7, -484($fp)
	lw $t9, -152($fp)
	addi $sp, $sp, -4 
	add $s0, $t9, $t7
	sw $s0, -488($fp)
	sw $t9, -152($fp)
	sw $t7, -484($fp)
	li $t7, 1
	lw $t9, -144($fp)
	addi $sp, $sp, -4 
	sub $s0, $t9, $t7
	sw $s0, -492($fp)
	sw $t9, -144($fp)
	lw $t9, -492($fp)
	addi $sp, $sp, -4 
	move $s0, $fp
	addi $s0, $s0, -488
	lw $s0, 0($s0)
	lw $s0, 0($s0)
	bge $s0, $t9, mylabel33
	j mylabel34
mylabel33:
	lw $s6, -136($fp)
	li $t5, 4
	addi $sp, $sp, -4 
	mul $t6, $t5, $s6
	sw $t6, -500($fp)
	sw $s6, -136($fp)
	lw $t6, -500($fp)
	lw $s6, -152($fp)
	addi $sp, $sp, -4 
	add $s1, $s6, $t6
	sw $s1, -504($fp)
	sw $s6, -152($fp)
	sw $t6, -500($fp)
	li $t6, 1
	li $s1, 0
	addi $sp, $sp, -4 
	sub $s6, $s1, $t6
	sw $s6, -508($fp)
	move $s6, $fp
	addi $s6, $s6, -504
	lw $s6, 0($s6)
	lw $s2, -508($fp)
	sw $s2, 0($s6)
	sw $s2, -508($fp)
	li $s2, 1
	lw $s5, -136($fp)
	addi $sp, $sp, -4 
	sub $s3, $s5, $s2
	sw $s3, -512($fp)
	sw $s5, -136($fp)
	lw $s3, -512($fp)
	lw $s5, -136($fp)
	move $s5, $s3
	sw $s5, -136($fp)
	sw $s3, -512($fp)
	j mylabel32
mylabel34:
	li $s3, 1
	li $s5, 0
	addi $sp, $sp, -4 
	sub $t8, $s5, $s3
	sw $t8, -516($fp)
	lw $t8, -516($fp)
	lw $s4, -136($fp)
	beq $s4, $t8, mylabel36
	j mylabel37
mylabel36:
	lw $t0, -168($fp)
	li $t0, 0
	sw $t0, -168($fp)
	j mylabel38
mylabel37:
	lw $t0, -136($fp)
	li $s7, 4
	addi $sp, $sp, -4 
	mul $t2, $s7, $t0
	sw $t2, -520($fp)
	sw $t0, -136($fp)
	lw $t0, -520($fp)
	lw $t2, -152($fp)
	addi $sp, $sp, -4 
	add $t1, $t2, $t0
	sw $t1, -524($fp)
	sw $t2, -152($fp)
	sw $t0, -520($fp)
	lw $t0, -136($fp)
	li $t1, 4
	addi $sp, $sp, -4 
	mul $t2, $t1, $t0
	sw $t2, -528($fp)
	sw $t0, -136($fp)
	lw $t0, -528($fp)
	lw $t2, -152($fp)
	addi $sp, $sp, -4 
	add $t4, $t2, $t0
	sw $t4, -532($fp)
	sw $t2, -152($fp)
	sw $t0, -528($fp)
	addi $sp, $sp, -4 
	move $t0, $fp
	addi $t0, $t0, -532
	lw $t0, 0($t0)
	lw $t0, 0($t0)
	addi $sp, $sp, -4 
	addi $t2, $t0, 1
	sw $t2, -540($fp)
	sw $t0, -536($fp)
	move $t0, $fp
	addi $t0, $t0, -524
	lw $t0, 0($t0)
	lw $t2, -540($fp)
	sw $t2, 0($t0)
	sw $t2, -540($fp)
	lw $t2, -136($fp)
	addi $sp, $sp, -4 
	addi $t4, $t2, 1
	sw $t4, -544($fp)
	sw $t2, -136($fp)
	lw $t2, -544($fp)
	lw $t4, -136($fp)
	move $t4, $t2
	sw $t4, -136($fp)
	sw $t2, -544($fp)
mylabel38:
mylabel31:
	j mylabel3
mylabel5:
	lw $t2, -132($fp)
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
