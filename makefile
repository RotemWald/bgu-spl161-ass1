# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
CC = g++
CFLAGS  = -g -Wall -Weffc++
LFLAGS  = -L/usr/lib

# All Targets
all: cyber

# Tool invocations
# Executable "cyber" depends on the files cybersecurity.o, cyberworm.o, cyberexpert.o, cyberpc.o, cyberdns.o
cyber: clean bin/cybersecurity.o bin/cyberworm.o bin/cyberexpert.o bin/cyberpc.o bin/cyberdns.o
	@echo 'Building target: cyber'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/cyber bin/cybersecurity.o bin/cyberworm.o bin/cyberexpert.o bin/cyberpc.o bin/cyberdns.o $(LFLAGS)
	@echo 'Finished building target: cyber'
	@echo ' '

# Depends on the source and header files
bin/cybersecurity.o: src/cybersecurity.cpp
	$(CC) $(CFLAGS) -c -Linclude -I/usr/local/boost/1.57.0/include/boost -o bin/cybersecurity.o src/cybersecurity.cpp

bin/cyberworm.o: src/cyberworm.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberworm.o src/cyberworm.cpp

bin/cyberexpert.o: src/cyberexpert.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberexpert.o src/cyberexpert.cpp
 
bin/cyberpc.o: src/cyberpc.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberpc.o src/cyberpc.cpp

bin/cyberdns.o: src/cyberdns.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/cyberdns.o src/cyberdns.cpp

#Clean the build directory
clean: 
	rm -f bin/*
