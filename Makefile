#inspiration taken from Henry Walker's simplified Makefile

#----------------------------------------------------------------------------
# Use the clang compiler
CC = clang

# Set compilation flags
#   -ansi       check syntax against the American National Standard for C
#   -g          include debugging information
#   -Wall       report all warnings
#   -std=gnu99  use the GNU extensions of the C99 standard
CFLAGS = -ansi -g -Wall -std=gnu99

#----------------------------------------------------------------------------
# build rules:
#
# Each rule takes the following form  (Note there MUST be a tab,
# as opposed to several spaces, preceeding each command.
#
# target_name:  dependency_list
#	command(s)

all: project-4

# List program components, what they depend on, and how to compile or link each

project-4:  project-4.o project-4-functions.o
	$(CC) -o $@ $^

project-4.o:  project-4.c project-4.h
	$(CC) $(CFLAGS) -c $<

project-4-functions.o:  project-4-functions.c project-4.h
	$(CC) $(CFLAGS) -c $<


#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   the built program, object files, old emacs source versions, and core dumps.

clean:
	rm -f list *.o *~ core*
