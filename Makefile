TARGET = shuffle_experiment

CC = gcc

COMPILE = $(CC) -c
LINK = $(CC)

CFLAGS = -Wall -std=c11
LFLAGS = -Wall

SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c) 
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
BINARY  = $(BINDIR)/$(TARGET)

$(BINARY): $(OBJECTS)
	test -d $(@D) || mkdir $(@D)
	$(LINK) $? -o $@ $(LFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	test -d $(@D) || mkdir $(@D)
	$(COMPILE) $< -o $@ $(CFLAGS)

clean:
	rm -r $(OBJDIR) $(BINDIR)