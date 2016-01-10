#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//========================================================================================
#define boolean int
#define true 1
#define false 0

//========================================================================================
struct test_struct
{
    int val;
    float x1;
    float x2;
    float x3;
    struct test_struct *next;
};

struct test_struct *head = NULL;
struct test_struct *curr = NULL;



//========================================================================================
struct test_struct* create_list(int val)
{
    printf("\n creating list with headnode as [%d]\n",val);
    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = val;
    ptr->next = NULL;

    head = curr = ptr;
    return ptr;
}

//========================================================================================
struct test_struct* add_to_list(int val, bool add_to_end)
{
	float xval;
    if(NULL == head)
    {
        return (create_list(val));
    }

    if(add_to_end)
        printf("\n Adding node to end of list with value [%d]\n",val);
    else
        printf("\n Adding node to beginning of list with value [%d]\n",val);

    struct test_struct *ptr = (struct test_struct*)malloc(sizeof(struct test_struct));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }

    printf("Enter x1 value: \n");
    scanf("%f", &xval);
    ptr->x1 = xval;
    printf("Enter x2 value: \n");
    scanf("%f", &xval);
    ptr->x2 = xval;
    printf("Enter x3 value: \n");
    scanf("%f", &xval);
    ptr->x3 = xval;

    ptr->val = val;
    ptr->next = NULL;

    if(add_to_end)
    {
        curr->next = ptr;
        curr = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return ptr;
}

//========================================================================================
struct test_struct* search_in_list(int val, struct test_struct **prev)
{
    struct test_struct *ptr = head;
    struct test_struct *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n",val);

    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

//========================================================================================
int delete_from_list(int val)
{
    struct test_struct *prev = NULL;
    struct test_struct *del = NULL;

    printf("\n Deleting value [%d] from list\n",val);

    del = search_in_list(val,&prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == curr)
        {
            curr = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}

//========================================================================================
void print_list(void)
{

    struct test_struct *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("\n [%d] \n",ptr->val);
        printf("(%f,%f,%f) \n", ptr->x1,ptr->x2,ptr->x3);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}



//========================================================================================
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);

	int choice = 0, ret = 0, count = 0, select = 0;
	boolean menu1 = true;
	boolean menu2 = true;

    struct test_struct *ptr = NULL;

    add_to_list(count,true);
    count++;

	while(menu1){
		menu2 = true;

		printf("--------------- Main Menu --------------- \n");
		printf("Please select a menu item: \n \n");
		printf("[1] Edit coordinates \n");
		printf("[2] Run through coordinate sequence \n");
		printf("[0] Exit \n");
		scanf("%d", &choice);

		if(choice == 1){
			printf("\n");
			printf("------------ Add Coordinate ------------- \n");
			printf("Please select a menu item: \n \n");
			printf("[1] Add new coordinate at end\n");
			printf("[2] Add new coordinate in middle \n");
			printf("[3] Edit coordinate value \n");
			printf("[4] Delete coordinate \n");
			printf("[0] Exit \n");
			scanf("%d", &choice);

			while(menu2){
				if(choice == 1){
					printf("------- Add New Coordinate At End ------- \n");
					add_to_list(count,true);
					count++;
					menu2 = false;
				} else if(choice == 2) {
					printf("----- Add New Coordinate In Middle ------ \n");
					printf("Select a coordinate in sequence that this \n");
					printf("new coordinate will be placed after. \n");
					print_list();
					scanf("%d", &select);
					add_to_list(select,false);
					count++;
					menu2 = false;
				} else if(choice == 3){
					printf("--------- Edit Coordinate Value --------- \n");
					printf("Select a coordinate in sequence that will \n");
					printf("be replaced. \n");
					print_list();
					scanf("%d", &select);
					delete_from_list(select);
					add_to_list(select,false);
					menu2 = false;
				} else if(choice == 4){
					printf("----------- Delete Coordinate ----------- \n");
					printf("Select a coordinate in sequence that will \n");
					printf("be deleted. \n");
					print_list();
					scanf("%d", &select);
					delete_from_list(select);
					count--;
					menu2 = false;
				} else if(choice == 0){
					menu2 = false;
				} else {
					printf("--------------- Invalid ----------------- \n");
					menu2 = false;
				}
			}
		} else if(choice == 2){
			printf("\n");
			printf("---- Run Through Coordinate Sequence ---- \n");
			printf("Please select a menu item: \n \n");
			printf("[1] Next Coordinate \n");
			printf("[2] Previous Coordinate \n");
			printf("[3] Print Coordinate Sequence \n");
			printf("[0] Exit \n");
			scanf("%d", &choice);

			while(menu2){
				if(choice == 1){
					printf("------------ Next Coordinate ------------ \n");
					menu2 = false;
				} else if(choice == 2) {
					printf("---------- Previous Coordinate ---------- \n");
					menu2 = false;
				} else if(choice == 3) {
					printf("------- Print Coordinate Sequence ------- \n");
					print_list();
					menu2 = false;
				} else if(choice == 0){
					menu2 = false;
				} else {
					printf("--------------- Invalid ----------------- \n");
					menu2 = false;
				}
			}

		} else if(choice == 0){
			printf("----------------- Exit ------------------ \n");
			menu1 = false;
		} else {
			printf("--------------- Invalid ----------------- \n");
		}

	}
	return 0;
}
