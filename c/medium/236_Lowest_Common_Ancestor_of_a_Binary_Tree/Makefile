CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR)
LIB_DIR:=../../shared_libraries/binary_tree_utils
LDFLAGS:=-L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -Wall -lbinary_tree_utils
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=236_Lowest_Common_Ancestor_of_a_Binary_Tree.o test_236.o
EXE:=test_236

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)