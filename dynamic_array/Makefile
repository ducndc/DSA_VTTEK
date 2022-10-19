CC:= gcc
CFLAG:= -Wall
LDFLAGS:=
OBJECTFILES_1:= lib/vector.o src/suffix_structures.o 
OBJECTFILES_2:= lib/vector.o src/action_follow_k.o
OUTPUTFILE:= 
TARGET_1:= suffix_structures 
TARGET_2:= action_follow_k

all: $(TARGET_1) $(TARGET_2)
 

$(TARGET_1): $(OBJECTFILES_1)
	$(CC) $(CFLAG) -o $(TARGET_1) $(OBJECTFILES_1) $(LDFLAGS)

$(TARGET_2): $(OBJECTFILES_2)
	$(CC) $(CFLAG) -o $(TARGET_2) $(OBJECTFILES_2) $(LDFLAGS)
run:
	./$(TARGET)

clean:
	rm -f $(OBJECTFILES_1) $(OBJECTFILES_2) $(TARGET_1) $(TARGET_2) $(OUTPUTFILE) 
