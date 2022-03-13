CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR)
LIB_DIR:=../../shared_libraries/binary_tree_utils
LDFLAGS:=-L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -Wall -lbinary_tree_utils
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=94_Binary_Tree_Inorder_Traversal.o test_94.o
EXE:=test_94

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)