CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR) -g -Wall # -g : gdb debugger, -Wall : show all warning message
LIB_DIR:=../../shared_libraries/binary_tree_utils
LDFLAGS:=-L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -lbinary_tree_utils
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=637_Average_of_Levels_in_Binary_Tree.o test_637.o
EXE:=test_637

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)