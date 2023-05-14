CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR)
LIB_DIR:=../../shared_libraries/binary_tree_utils
LDFLAGS:=-L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -Wall -lbinary_tree_utils -lm
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=124_Binary_Tree_Maximum_Path_Sum.o test_124.o
EXE:=test_124

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)