CC:=gcc
OBJS:=binary_tree_utils.o
LIB:=libbinary_tree_utils.so
INC_DIR:=../../includes
CFLAGS:=-fPIC -I$(INC_DIR) 
LDFLAGS:=-shared


all: $(OBJS)
	$(CC) -o $(LIB) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(LIB)