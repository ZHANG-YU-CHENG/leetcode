#include "gtest/gtest.h"

/*for unit test*/
extern "C" {
#include "linked_list_utils.h"
}

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

extern struct Node* copyRandomList(struct Node* head);

extern struct Node* createRandomList(int* valArr, int* randomArr, int len);

void printRandomList(struct Node* head)
{
    struct Node* cur = head;
    while(cur)
    {
        printf("[%p] val=%d, next=%p, random=%p\n", cur, cur->val, cur->next, cur->random);
        cur = cur->next;
    }
}

TEST(copyRandomListTest, test1) {
    int len = 5;
    int valArr[] = {7, 13, 11, 10, 1};
    int randomArr[] = {-1, 0, 4, 2, 0};
    struct Node* head = createRandomList(valArr, randomArr, len);
    printRandomList(head);

    puts("");
    struct Node* out = copyRandomList(head);
    printRandomList(out);

    EXPECT_TRUE(true); //TO DO : compare RandomList

    if(head) free(head);
    head = NULL;
    if(out) free(out);
    out = NULL;
}

TEST(copyRandomListTest, test2) {
    int len = 2;
    int valArr[] = {1, 2};
    int randomArr[] = {1, 1};
    struct Node* head = createRandomList(valArr, randomArr, len);
    printRandomList(head);

    puts("");
    struct Node* out = copyRandomList(head);
    printRandomList(out);

    EXPECT_TRUE(true); //TO DO : compare RandomList

    if(head) free(head);
    head = NULL;
    if(out) free(out);
    out = NULL;
}

TEST(copyRandomListTest, test3) {
    int len = 3;
    int valArr[] = {3, 3, 3};
    int randomArr[] = {-1, 0, -1};
    struct Node* head = createRandomList(valArr, randomArr, len);
    printRandomList(head);

    puts("");
    struct Node* out = copyRandomList(head);
    printRandomList(out);

    EXPECT_TRUE(true); //TO DO : compare RandomList

    if(head) free(head);
    head = NULL;
    if(out) free(out);
    out = NULL;
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}