#include "includes/push_swap.h"

void print_stack(t_stack *stack, char name)
{
    t_lst_st *temp;

    printf("stack %c / menor: %d / mayor: %d size %d: ", name, stack->smaller, stack->bigger, stack->size);
    
    temp = stack->start;
    while (temp)
    {
        printf("%d,", temp->nbr);
        temp = temp->next;
    }
    printf("\n");
    /*
    printf("                                REVERSO: ");
    temp = stack->end;
    while (temp)
    {
        printf("%d,", temp->nbr);
        temp = temp->prev;
    }
    printf("\n");
    */
}

void print_reverse(t_stack *stack, char name)
{
    t_lst_st *temp;

    printf("stack %c %d: ", name, stack->size);
    temp = stack->end;
    while (temp)
    {
        printf("%d,", temp->nbr);
        temp = temp->prev;
    }
    printf("\n");
}

int main(void)
{
    t_data data;
    t_stack *stackA;
    t_stack *stackB;
    //int pila[] = {5, 1, 6, 10, 3, 4, 0};
    //int pila[] = {16, 17, 45, 27, 88, 49, 75, 2, 72, 59, 95, 37, 13, 51, 31, 10, 23, 50, 91, 25, 66, 7, 96, 56, 92, 68, 73, 33, 61, 15, 0};
    /*100*/int pila[] = {53, 167, 93, 32, 72, 114, 194, 60, 112, 46, 175, 24, 73, 59, 151, 197, 170, 139, 95, 186, 80, 148, 178, 145, 133, 153, 9, 200, 111, 160, 66, 78, 84, 70, 169, 183, 51, 37, 94, 74, 6, 75, 143, 52, 11, 116, 185, 149, 82, 156, 118, 165, 7, 36, 17, 192, 12, 137, 16, 57, 44, 138, 49, 98, 113, 187, 68, 10, 81, 21, 198, 48, 182, 45, 19, 108, 100, 164, 30, 177, 91, 67, 123, 33, 128, 15, 191, 104, 58, 135, 125, 23, 96, 199, 25, 69, 129, 105, 86, 161, 0};
    //int pila[] = {54, 23, 106, 94, 190, 119, 161, 72, 189, 137, 34, 114, 40, 53, 39, 103, 7, 26, 171, 51, 48, 163, 36, 46, 28, 124, 67, 185, 59, 162,0};
    /*500*///int pila[] = {585, 907, 448, 698, 139, 490, 849, 914, 35, 835, 319, 244, 492, 13, 135, 871, 659, 606, 788, 280, 316, 809, 88, 783, 644, 770, 778, 449, 899, 971, 95, 580, 329, 548, 202, 607, 811, 867, 285, 237, 953, 401, 154, 928, 567, 62, 726, 245, 638, 430, 852, 483, 72, 73, 691, 837, 501, 397, 713, 51, 599, 19, 333, 205, 11, 68, 980, 569, 240, 438, 243, 917, 93, 529, 131, 194, 789, 979, 55, 188, 40, 826, 714, 684, 370, 326, 253, 41, 436, 987, 204, 367, 121, 498, 260, 756, 724, 629, 683, 697, 168, 199, 147, 759, 998, 943, 307, 875, 417, 225, 730, 82, 682, 827, 777, 306, 321, 375, 570, 764, 464, 218, 262, 535, 458, 527, 383, 108, 539, 793, 122, 343, 675, 508, 384, 469, 372, 454, 944, 239, 945, 766, 327, 820, 291, 731, 510, 704, 314, 616, 371, 304, 507, 833, 500, 906, 708, 252, 972, 266, 23, 931, 556, 631, 988, 362, 694, 718, 351, 832, 517, 452, 107, 355, 47, 558, 495, 746, 138, 104, 48, 56, 186, 880, 963, 965, 312, 415, 261, 396, 476, 509, 814, 200, 703, 462, 431, 782, 976, 115, 428, 873, 29, 587, 666, 717, 949, 926, 956, 883, 175, 846, 649, 216, 566, 942, 650, 728, 711, 936, 286, 297, 908, 618, 654, 842, 77, 727, 347, 182, 60, 394, 710, 248, 470, 892, 911, 61, 981, 236, 940, 623, 511, 518, 45, 959, 231, 913, 732, 207, 762, 86, 475, 21, 467, 224, 642, 445, 198, 712, 447, 275, 563, 74, 144, 301, 571, 723, 687, 170, 493, 190, 359, 565, 669, 512, 27, 577, 673, 398, 217, 802, 281, 140, 364, 752, 504, 34, 450, 395, 935, 53, 853, 903, 515, 387, 923, 921, 652, 748, 591, 744, 249, 155, 970, 994, 855, 30, 150, 460, 288, 414, 622, 100, 22, 189, 503, 677, 733, 525, 303, 32, 715, 549, 635, 896, 143, 254, 54, 184, 90, 781, 806, 421, 617, 597, 117, 754, 915, 924, 300, 678, 836, 841, 840, 283, 954, 46, 425, 679, 834, 740, 259, 185, 328, 860, 203, 427, 595, 862, 897, 157, 784, 177, 471, 67, 267, 213, 289, 879, 613, 947, 771, 287, 962, 165, 938, 36, 156, 49, 961, 392, 247, 992, 132, 210, 709, 33, 901, 230, 119, 902, 583, 161, 891, 817, 774, 578, 163, 701, 124, 407, 543, 544, 426, 531, 496, 403, 547, 158, 278, 145, 453, 889, 634, 349, 24, 295, 722, 134, 499, 437, 608, 767, 620, 602, 164, 112, 768, 805, 707, 564, 604, 573, 123, 235, 380, 561, 133, 974, 63, 933, 162, 633, 643, 693, 640, 977, 966, 229, 39, 905, 823, 393, 861, 389, 545, 755, 885, 439, 865, 872, 171, 929, 594, 472, 310, 488, 627, 874, 516, 957, 201, 839, 605, 657, 554, 890, 451, 775, 636, 750, 109, 609, 358, 830, 463, 668, 572, 898, 305, 422, 78, 647, 780, 70, 729, 12, 922, 457, 0};
    int i;

    ft_bzero(&data, sizeof(t_data));
    stackA = &data.stack_a;
    stackB = &data.stack_b;
    printf("entrando en test\n");
    i = 0;
    while (pila[i] != 0)
    {
        printf("añadiendo %d\n", pila[i]);
        add_new_back(stackA, pila[i]);
        i++;
        printf("añadido %d\n", pila[i]);
    }
/*
    t_lst_st *temp;
    temp = data.stack_a.end;
    while (temp)
    {
        printf("%d, ", temp->nbr);
        temp = temp->prev;
    }
    printf("\n");
    */
    
     print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    //merge_short(&data);
    //selection_sort(&data);
    merge_select_short(&data);
    
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    print_stack(&data.operations, 'O');
    printf("Total movimientos: %d\n", data.operations.size);
    
/*
   while (stackA->start)
   {
       push_b(&data);
   }
   */
    /*
    while (stackA->start && stackA->start->next && stackA->start->next->next)
    {
        sort_top(&data);
        remove_element(stackA, stackA->start);
        print_stack(stackA, 'A');
    }
    rotate_a(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
*/
/*
    while (stackB->start && stackB->start->next && stackB->start->next->next)
    {
        sort_top(&data);
        remove_element(stackB, stackB->start);
        print_stack(stackB, 'B');
    }
    rotate_b(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    */
    

    /*
    i = 0;
    while (pila[i] != 0)
    {
        printf("añadiendo %d\n", pila[i]);
        add_new_back(stackB, pila[i]);
        i++;
        printf("añadido %d\n", pila[i]);
    }
    */
   /*
    i = 0;
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    sort_top(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    sort_top(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    sort_top(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    sort_top(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    sort_top(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
*/
    /*
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_b(&data);

    
    printf("**CAMBIO A PUSH A %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    printf("** %d **\n", i++);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    push_a(&data);
    */
  
    //short_array(&data);
    /*
    bubble_sort_a(&data);
    print_stack(stackA, 'A');
    bubble_sort_b(&data);    
    print_stack(stackB, 'B');
    */
    //selection_sort(&data);
    
    //insertion_sort(&data);
    /*
    merge_short(&data);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    print_stack(&data.operations, 'O');
    printf("%d operaciones\n", data.operations.size);
    */
    /*
    buble_sort(&data);
    print_stack(stackA, 'A');
    print_stack(&data.operations, 'O');
    printf("%d operaciones\n", data.operations.size);
    */
   /*
    printf("***** 1 ********\n");
    print_stack(stackA, 'A');
    move_of_stack(stackA, stackB);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    printf("***** 2 ********\n");
    move_of_stack(stackA, stackB);
    move_of_stack(stackA, stackB);
    print_stack(stackA, 'A');
    print_stack(stackB, 'B');
    printf("***** 3 ********\n");
    rotate_stack(stackB);
    print_stack(stackB, 'B');
    printf("***** 4 ********\n");
    rotate_reverse_stack(stackB);
    print_stack(stackB, 'B');
    printf("***** 3 ********\n");
    rotate_stack(stackB);
    print_stack(stackB, 'B');
    printf("***** 4 ********\n");
    rotate_reverse_stack(stackB);
    print_stack(stackB, 'B');
    printf("***** 5 ********\n");
    rotate_stack(stackA);
    print_stack(stackA, 'A');
    printf("***** 6 ********\n");
    rotate_reverse_stack(stackA);
    print_stack(stackA, 'A');
*/
    

}