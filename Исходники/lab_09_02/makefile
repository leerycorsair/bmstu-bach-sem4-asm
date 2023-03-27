CC := gcc

# Флаги компиляции
CFLAGS := -std=gnu99 -Wall -Wpedantic -Wextra -masm=intel

# Папки
SRCDIR := src/
INCDIR := inc/
OUTDIR := out/

# Цель сборки
TARGET := app.exe

SRCS := $(wildcard $(SRCDIR)*.c)
OBJS := $(SRCS:$(SRCDIR)%.c=$(OUTDIR)%.o)
DEPS := $(SRCS:$(SRCDIR)%.c=$(OUTDIR)%.d)

.PHONY : build
build : $(TARGET)



$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(OUTDIR)%.o : $(SRCDIR)%.c | $(OUTDIR)
	$(CC) $(CFLAGS) -MMD -I$(INCDIR) -o $@ -c $<

-include $(DEPS)

$(OUTDIR) :
	mkdir $@

.PHONY : clean
clean :
	@rm -f $(TARGET) $(OUTDIR)*
