TARGET = shuffle_experiment

CC = gcc

COMPILE = $(CC) -c
LINK = $(CC)

CFLAGS = -std=c11
LFLAGS = -std=c11

SRCDIR = src
OBJDIR = obj
BINDIR = bin

DEPENDS = $(wildcard $(SRCDIR)/*.h) $(wildcard $(SRCDIR)/*/*.h) 
SOURCES = $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/*/*.c) 
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
BINARY  = $(BINDIR)/$(TARGET)

$(BINARY): $(OBJECTS)
	test -d $(@D) || mkdir $(@D)
	$(LINK) $? -o $@ $(LFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPENDS)
	test -d $(@D) || mkdir $(@D)
	$(COMPILE) $< -o $@ $(CFLAGS)

clean:
	rm -r $(OBJDIR) $(BINDIR)