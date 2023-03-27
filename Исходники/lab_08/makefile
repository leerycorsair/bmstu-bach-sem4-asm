INCPATH = ./inc/
OUTPATH = ./out/
SRCPATH = ./src/

run: app.exe
	./app.exe

app.exe: $(OUTPATH)main.o $(OUTPATH)my_strlen.o  $(OUTPATH)my_strncpy.o 
	gcc -o  $@ $(OUTPATH)my_strncpy.o $(OUTPATH)main.o $(OUTPATH)my_strlen.o 

$(OUTPATH)main.o : $(SRCPATH)main.c | $(OUTPATH)
	gcc -I$(INCPATH) -o $@ -c $<

$(OUTPATH)my_strlen.o : $(SRCPATH)my_strlen.c | $(OUTPATH)
	gcc -I$(INCPATH) -o $@ -c $<

$(OUTPATH)my_strncpy.o : $(SRCPATH)my_strncpy.asm | $(OUTPATH)
	nasm -o $@ -f elf64 $< 

$(OUTPATH):
	mkdir $@

.PHONY: clean
clean: 
	rm -fv *.exe
	rm -fv $(OUTPATH)*.o