#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t);
void my_free(void *);

void *__wrap_malloc(size_t n)
{
    return my_malloc(n);
}

void *__wrap_free(void *ptr)
{
    my_free(ptr);
}

int main()
{
    printf("Hello world!\n\r");

    int *int_ptr = (int *)malloc(sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        (*int_ptr)++;
    }

    printf("val: %i\n\r", *int_ptr);

    free(int_ptr);

    return EXIT_SUCCESS;
}

void *my_malloc(size_t n)
{
    static int counter = 0;
    counter++;
    printf("malloc %lu called: %i\n\r", n, counter);

    static int buffer_pool[1024];
    return &buffer_pool[0];
}

void my_free(void *ptr)
{
    printf("free called\n\r");
}
