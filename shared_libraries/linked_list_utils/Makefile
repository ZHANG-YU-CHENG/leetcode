CC:=g++
OBJS:=linked_list_utils.o
LIB:=liblinked_list_utils.so
INC_DIR:=../../includes
CFLAGS:=-fPIC -I$(INC_DIR) 
LDFLAGS:=-shared


all: $(OBJS)
	$(CC) -o $(LIB) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(LIB)