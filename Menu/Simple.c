#include <stdio.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);

	int choice;
	bool menu1 = true;
	bool menu2 = true;


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
					menu2 = false;
				} else if(choice == 2) {
					printf("----- Add New Coordinate In Middle ------ \n");
					menu2 = false;
				} else if(choice == 3){
					printf("--------- Edit Coordinate Value --------- \n");
					menu2 = false;
				} else if(choice == 4){
					printf("----------- Delete Coordinate ----------- \n");
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
			printf("[0] Exit \n");
			scanf("%d", &choice);

			while(menu2){
				if(choice == 1){
					printf("------------ Next Coordinate ------------ \n");
					menu2 = false;
				} else if(choice == 2) {
					printf("---------- Previous Coordinate ---------- \n");
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
