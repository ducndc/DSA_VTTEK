CC:= gcc
CFLAG:= -Wall
LDFLAGS:=
OBJECTFILES:= list.o problem.o
TARGET:= linked_list

all: $(TARGET)
 
$(TARGET): $(OBJECTFILES)
	$(CC) $(CFLAG) -o $(TARGET) $(OBJECTFILES) $(LDFLAGS)

clean:
	rm -f $(OBJECTFILES) $(TARGET) 
