CC := gcc

# Флаги компиляции
CFLAGS := -std=c99 -Wall -O0 -Wpedantic -Wextra -masm=intel

# Папки
SRCDIR := src/
INCDIR := inc/
OUTDIR := out/
ASMDIR := asm/

# Цель сборки
TARGET := app.exe

SRCS := $(wildcard $(SRCDIR)*.c)
OBJS := $(SRCS:$(SRCDIR)%.c=$(OUTDIR)%.o)
ASMS := $(SRCS:$(SRCDIR)%.c=$(ASMDIR)%.s)
DEPS := $(SRCS:$(SRCDIR)%.c=$(OUTDIR)%.d)

.PHONY : build
build : $(TARGET)
build : CFLAGS += -m80387

.PHONY: assmembly
assmembly: $(ASMS)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(OUTDIR)%.o : $(SRCDIR)%.c | $(OUTDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -MD -o $@ -c $<

$(ASMDIR)%.s : $(SRCDIR)%.c | $(ASMDIR)
	$(CC) $(CFLAGS) -S -I$(INCDIR) -MD -o $@ -c $<

-include $(DEPS)

$(OUTDIR) :
	mkdir $@

.PHONY : clean
clean :
	@rm -f $(TARGET) $(OUTDIR)*
