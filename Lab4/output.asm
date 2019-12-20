main:
a := #0
b := #1
i := #0
addi $sp, $sp, -4
sw $ra, 0($sp)
jal read
lw $ra, 0($sp)
addi $sp, $sp, 4
move –ñª…‚U, $v0
n := myvar4
add , , 
a := myvar6
move $a0, 
addi $sp, $sp, -4
sw $ra, 0($sp)
jal write
lw $ra, 0($sp)
addi $sp, $sp, 4
move $v0,  
jr $ra
