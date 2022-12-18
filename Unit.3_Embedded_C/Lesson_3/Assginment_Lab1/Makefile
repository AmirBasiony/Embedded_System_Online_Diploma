# map_file verastilepb 
# Eng.Amir
CC=arm-none-eabi-
CFLAGS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As  = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_Name=learn_in_depth

all: $(Project_Name).bin
	@echo "========Build is Done========="

startup.o: startup.s
	$(CC)as.exe -c $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linkerscript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map
	
	
$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary  $<  $@

clean_all:
	rm *.o *.elf *.bin
	@echo "======Clean is Done======"
clean:
	rm *.elf *.bin