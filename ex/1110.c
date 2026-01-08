#include <stdlib.h>
#include <stdio.h>

struct DequeNode {
    int Value;
    struct DequeNode *Prev, *Next;
};

struct Deque {
    int Size;
    struct DequeNode *Front, *Back;
};

void push_front(struct Deque* D, int Value){
    D->Size++;
    struct DequeNode* NewNode = (struct DequeNode*) malloc(sizeof(struct DequeNode));
    NewNode->Value = Value;
    NewNode->Prev = NULL;
    NewNode->Next = D->Front;

    if (D->Front != NULL)
        D->Front->Prev = NewNode;

    D->Front = NewNode;

    if (D->Back == NULL)
        D->Back = NewNode;
}

void push_back(struct Deque* D, int Value){
    D->Size++;
    struct DequeNode* NewNode = (struct DequeNode*) malloc(sizeof(struct DequeNode));
    NewNode->Value = Value;
    NewNode->Prev = D->Back;
    NewNode->Next = NULL;

    if (D->Back != NULL)
        D->Back->Next = NewNode;

    D->Back = NewNode;

    if (D->Front == NULL)
        D->Front = NewNode;
}

void pop_front(struct Deque* D){
    if (D->Size > 0){
        D->Size--;
        struct DequeNode* OldFront = D->Front;
        D->Front = OldFront->Next;
        free(OldFront);
    }
}

void pop_back(struct Deque* D){
    if (D->Size > 0){
        D->Size--;
        struct DequeNode* OldBack = D->Back;
        D->Back = OldBack->Prev;
        free(OldBack);
    }
}

int front(struct Deque* D){
    return D->Front->Value;
}

int back(struct Deque* D){
    return D->Back->Value;
}

int size(struct Deque* D){
    return D->Size;
}

int empty(struct Deque* D){
    return D->Size == 0;
}

void initialize(struct Deque* D){
    D->Size = 0;
    D->Front = NULL;
    D->Back = NULL;
}

void destroy(struct Deque* D){
    while (!empty(D))
        pop_front(D);   // rmv all
}

int main(){
    int N, First;
    struct Deque Cards;

    while (scanf("%d", &N)){
        if (!N) break;

        initializ
