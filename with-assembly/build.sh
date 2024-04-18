nasm assembly.asm -f elf64
gcc -c main.c
gcc main.o assembly.o -o main

rm assembly.o
rm main.o