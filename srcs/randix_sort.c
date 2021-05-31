#include "../includes/push_swap.h"

void print_binary(int n)
{

    while (n) {
    if (n & 1)
        printf("1");
    else
        printf("0");

    n >>= 1;
    }
    printf("\n");
}

void randix_sort(t_data *data)
{
    int max_num;
    int max_bits;
    int i;
    int count;
    int nbr;

    max_num = data->sorted->size - 1;
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        count = 0;
        while (count < data->sorted->size)
        {
            nbr = data->stack_a.start->nbr;
            if (((nbr >> i) & 1) == 1)
                rotate_a(data);
            else
                push_b(data);
            count++;
            
        }
        i++;
        while (data->stack_b.size > 0)
            push_a(data);      
    }   
    
}