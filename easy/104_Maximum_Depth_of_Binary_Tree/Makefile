CC:=gcc
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR)
LIB_DIR:=../../shared_libraries/binary_tree_utils
LDFLAGS = -L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -Wall -lbinary_tree_utils -lm
OBJS:=104_Maximum_Depth_of_Binary_Tree.o 104_test.o
EXE:=test

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)