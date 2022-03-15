#include "gtest/gtest.h"

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

extern struct Node *cloneGraph(struct Node *s);

TEST(cloneGraphTest, test1) {
    puts("TO DO : compare two Graphs");
    struct Node* s1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* s4 = (struct Node*)malloc(sizeof(struct Node));
    s1->val = 1;
    s1->numNeighbors = 2;
    s1->neighbors = (struct Node**)malloc(sizeof(struct Node)*2);
    s1->neighbors[0] = s2;
    s1->neighbors[1] = s4;
    s2->val = 2;
    s2->numNeighbors = 2;
    s2->neighbors = (struct Node**)malloc(sizeof(struct Node)*2);
    s2->neighbors[0] = s1;
    s2->neighbors[1] = s3;
    s3->val = 3;
    s3->numNeighbors = 2;
    s3->neighbors = (struct Node**)malloc(sizeof(struct Node)*2);
    s3->neighbors[0] = s2;
    s3->neighbors[1] = s4;
    s4->val = 4;
    s4->numNeighbors = 2;
    s4->neighbors = (struct Node**)malloc(sizeof(struct Node)*2);
    s4->neighbors[0] = s1;
    s4->neighbors[1] = s3;
    printf("s1=%p, val=%d, num=%d, n1=%p, n2=%p\n", s1, s1->val, s1->numNeighbors, s1->neighbors[0], s1->neighbors[1]);
    printf("s2=%p, val=%d, num=%d, n1=%p, n2=%p\n", s2, s2->val, s2->numNeighbors, s2->neighbors[0], s2->neighbors[1]);
    printf("s3=%p, val=%d, num=%d, n1=%p, n2=%p\n", s3, s3->val, s3->numNeighbors, s3->neighbors[0], s3->neighbors[1]);
    printf("s4=%p, val=%d, num=%d, n1=%p, n2=%p\n", s4, s4->val, s4->numNeighbors, s4->neighbors[0], s4->neighbors[1]);
    struct Node* out = cloneGraph(s1);
}

int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}