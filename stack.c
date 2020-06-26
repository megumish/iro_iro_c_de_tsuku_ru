#include <stdio.h>
#include <assert.h>
#define STACK_MAX 5

typedef struct
{
    int inner[STACK_MAX];
    unsigned int top;
} Stack;

unsigned int push(Stack *s, int i)
{
    if (s->top + 1 > STACK_MAX)
    {
        return 0;
    }
    s->inner[s->top] = i;
    ++s->top;
    return 1;
}

unsigned int pop(Stack *s, int *a)
{
    if (s->top == 0)
    {
        return 0;
    }
    *a = s->inner[s->top - 1];
    --s->top;
    return 1;
}

int main(void)
{
    Stack s;
    assert(push(&s, 10));
    {
        int a;
        assert(pop(&s, &a));
        assert(a == 10);
    }

    {
        int b;
        assert(!pop(&s, &b));
    }

    assert(push(&s, 1));
    assert(push(&s, 1));
    assert(push(&s, 1));
    assert(push(&s, 1));
    assert(push(&s, 1));

    assert(!push(&s, 1));
}