#@copyright : Amr
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS  = $(wildcard *.s)
AsOBJ= $(AS:.s=.o)
Project_name=learn_in_depth_cortex_m3

all: $(Project_name).bin
	@echo "Build is done"
	
startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin



	
	