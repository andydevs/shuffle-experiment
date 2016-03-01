# Shuffle Experiment: An experiment to determine a pattern in the entropy of an array of given length when shuffled a given amount of times Copyright (C) 2016 Anshul
# 
# This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.

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

INSTALLDIR = /usr/local/bin

$(BINARY): $(OBJECTS)
	test -d $(@D) || mkdir $(@D)
	$(LINK) $? -o $@ $(LFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPENDS)
	test -d $(@D) || mkdir $(@D)
	$(COMPILE) $< -o $@ $(CFLAGS)

clean:
	rm -r $(OBJDIR) $(BINDIR)

install:
	cp $(BINDIR)/$(TARGET) $(INSTALLDIR)

uninstall:
	rm $(INSTALLDIR)/$(TARGET)

run:
	$(BINARY)