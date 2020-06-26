#include <stdio.h>
#include <assert.h>
#define STACK_MAX 5

typedef struct
{
    int inner[STACK_MAX];
    unsigned int top;
} Stack;

void init(Stack *s)
{
    s->top = 0;
}

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
    init(&s);
    assert(push(&s, 1));
    assert(push(&s, 2));
    {
        int a, b;
        assert(pop(&s, &a));
        assert(pop(&s, &b));
        assert(a == 2);
        assert(b == 1);
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