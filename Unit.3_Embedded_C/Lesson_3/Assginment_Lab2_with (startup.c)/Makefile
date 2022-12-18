#@copyright : Amir
#FOR Machine 
CC=arm-none-eabi-
#For architecteure
CFLAGS=-mcpu=cortex-m3  -gdwarf-2
#For Liberary or path of header
INCS=-I .
#for static libraries
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_Name =learn_in_depth_cotrex_m3

all: $(Project_Name).bin
	@echo "=========Builg is done========="
	
#startup.o: startup.c
#	$(CC)gcc.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS)  $< -o $@

$(Project_Name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe  -T  linkerscript.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map 

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $(Project_Name).elf $(Project_Name).bin
	

clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin