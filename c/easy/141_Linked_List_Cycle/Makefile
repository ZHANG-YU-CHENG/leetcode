CC:=g++ #for unit test (gcc to g++)
INC_DIR:=../../includes
CFLAGS:=-I$(INC_DIR)
LIB_DIR:=../../shared_libraries/linked_list_utils
LDFLAGS:=-L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR) -Wall -llinked_list_utils
LDFLAGS+=-std=c++11 -lgtest -lpthread #for unit test
OBJS:=141_Linked_List_Cycle.o test_141.o
EXE:=test_141

all: $(OBJS)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm -rf $(OBJS) $(EXE)