#include <stdio.h>
#include <stdlib.h>

typedef struct MEM_BLOC_STRUCT MEM_BLOC;

struct MEM_BLOC_STRUCT
{
    int id;
    int start_addr;
    int end_addr;
    MEM_BLOC* next;

};

void init_mem(MEM_BLOC **list, int *rem_mem);

void print(MEM_BLOC **list);

void ff_alloc(MEM_BLOC **list, int* mem_depth);

void dealloc(MEM_BLOC **list, int *mem_depth);

int main(){
    int option;

    int rem_mem = 0;
    MEM_BLOC* list = NULL;

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
        printf("\nEnter Selection: ");
        scanf("%d", &option);

        if (option == 1)
        {
            init_mem(&list, &rem_mem);
        }
        else if (option == 2)
        {
            ff_alloc(&list, &rem_mem);
            print(&list);
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

void init_mem(MEM_BLOC **list, int *rem_mem){
    MEM_BLOC *dummy;

    printf("Enter size of physical memory: ");
    scanf("%d", rem_mem);
    
    dummy = (MEM_BLOC*) malloc( sizeof(MEM_BLOC) );

    dummy->id = -1;
    dummy->start_addr = 0;
    dummy->end_addr = 0;
    dummy->next = NULL;

    *list = dummy;
}

void print(MEM_BLOC **list){

    printf("\nID\tStart   End\n"
            "-------------------\n");
    
    MEM_BLOC *ptr = (*list)->next;
        printf("%2d\t%4d  %4d\n", 
            ptr->id, 
            ptr->start_addr, 
            ptr->end_addr);
        ptr = (*list)->next;
}

void ff_alloc(MEM_BLOC **list, int *rem_mem){
    MEM_BLOC *bloc;
    MEM_BLOC *curr;
    int id;
    int size;

    printf("Enter block id: ");
    scanf("%d", &(id));
    
    printf("Enter block size:");
    scanf("%d", &size);

    if (size > *rem_mem) {
        printf("Not Enough Memory\n");
        return;
    }

    bloc  = (MEM_BLOC*) malloc(sizeof(MEM_BLOC));

    if ((*list)->next == NULL) {
        bloc->id = id;
        bloc->start_addr = 0;
        bloc->end_addr = bloc->start_addr + (size-1);
        bloc->next = NULL;
        *rem_mem -= size;
        (*list)->next = bloc;
        return;
    }

    curr = (*list)->next;

    while (curr != NULL)
    {
        if ( (*list)->id == bloc->id){
            printf("Duplicate id found\n");
            return;
        }

        if ( ((curr->next)->start_addr - curr->end_addr) >= size){
            bloc->id = id;
            bloc->start_addr = curr->end_addr + 1;
            bloc->start_addr = (curr->next->start_addr) - 1;
            bloc->next = NULL;
            *rem_mem -= size;
            return;
        }        

        curr = curr->next;
    }
    

}