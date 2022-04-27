#include <stdio.h>

int main(){
    int option;

    printf("Memory Allocation\n"
            "-----------------\n"
            "1) Enter parameters\n"
            "2) Allocate memory for block using First-fit\n"
            "3) Allocate memory for block using Best-fi\n"
            "4) Deallocate memory for block\n"
            "5) Defragment memory\n"
            "6) Quit program\n");
    
    while (1)
    {
        printf("\nEnter Selection:");
        scanf("%d", &option);

        if (option == 1)
        {
            /* code */
        }
        else if (option == 2)
        {
            /* code */
        }
        else if (option == 3)
        {
            /* code */
        }
        else if (option == 4)
        {
            /* code */
        }
        else if (option == 5)
        {
            /* code */
        }
        else if (option == 6)
        {
            return 0;
        } 
    }
    
    return 0;
}