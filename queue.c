#include <stdio.h>
#include <assert.h>
#define QUEUE_MAX 5

typedef struct
{
    int inner[QUEUE_MAX];
    unsigned int head;
    unsigned int tail;
} Queue;

void init(Queue *q)
{
    q->head = 0;
    q->tail = 1;
}

unsigned int enque(Queue *q, int i)
{
    if ((q->tail + 1) % QUEUE_MAX < q->head)
    {
        return 0;
    }

    q->inner[q->tail] = i;
    if (q->tail < QUEUE_MAX)
    {
        ++q->tail;
    }
    else
    {
        q->tail = 0;
    }
    return 1;
}

unsigned int deque(Queue *q, int *a)
{
    if ((q->head + 1) % QUEUE_MAX == q->tail)
    {
        return 0;
    }

    *a = q->inner[(q->head + 1) % QUEUE_MAX];
    if (q->head < QUEUE_MAX)
    {
        ++q->head;
    }
    else
    {
        q->head = 0;
    }
    return 1;
}

int main(void)
{
    Queue q;
    init(&q);
    assert(enque(&q, 1));
    assert(enque(&q, 2));
    {
        int a, b;
        assert(deque(&q, &a));
        assert(deque(&q, &b));
        assert(a == 1);
        assert(b == 2);
    }

    {
        int b;
        assert(!deque(&q, &b));
    }

    assert(enque(&q, 1));
    assert(enque(&q, 1));
    assert(enque(&q, 1));
    //assert(enque(&q, 1));
    //assert(enque(&q, 1));
    //
    //assert(!enque(&q, 1));
}