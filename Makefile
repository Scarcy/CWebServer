CC := gcc
CFLAGS := -Wall -Wextra -g
SRCDIR := src
OUTDIR := out
BINDIR := bin
EXEC := webserver

# Find all C source files in the src directory and subdirectories
SRCS := $(shell find $(SRCDIR) -name '*.c')
# Transform the source file paths to output object file paths
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OUTDIR)/%.o)

all: buildrepo $(BINDIR)/$(EXEC)

buildrepo:
	@mkdir -p $(BINDIR)
	@mkdir -p $(dir $(OBJS))

$(BINDIR)/$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OUTDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OUTDIR)/*
	rm -f $(BINDIR)/$(EXEC)
