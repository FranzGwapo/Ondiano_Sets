#include <stdio.h>
#include <stdlib.h>
#include "SETS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int choice, num, cardinal;
	char setchoice;
	bool state;
	Set a = newSet();
	Set b = newSet();
	Set c;
	do{
		printf("MAIN MENU\n");
		printf("Choose \n1. Add Element\n2. Remove Element\n3. Display Set\n4. Union Set\n5. Intersect Element\n6. Difference Element\n7. Symmetric Diff Element\n8. Cardinality\n0. Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
			
				printf("\nADD ELEMENT\n");
				printf("Enter a number: ");
				scanf("%d", &num);
				printf("What set? ");
				scanf(" %c", &setchoice);
				if(setchoice == 'a'){
					state = addElement(&a, num);
					displaySet(a);
				}
				else if(setchoice == 'b'){
					state = addElement(&b, num);
					displaySet(b);
				}
				else{
					printf("Invalid choice");
				}
				
				if(state){
					printf("Element added SUCCESSFULLY\n\n");
				}
				else{
					printf("Element added has DUPLICATE\n\n");
				}
				break;
			case 2:
	
				printf("\nREMOVE ELEMENT\n");
				printf("Enter a number: ");
				scanf("%d", &num);
				printf("What set?");
				scanf(" %c", &setchoice);
				if(setchoice == 'a'){
					state = removeElement(&a, num);
					displaySet(a);
				}
				else if(setchoice == 'b'){
					state = removeElement(&b, num);
					displaySet(b);
				}
				else{
					printf("Invalid choice\n\n");
				}
				if(state){
					printf("Element removed SUCCESSFULLY!\n\n");
				}
				else{
					printf("ELEMENT is not found in the set\n\n");
				}
				break;
			case 3:
				printf("\nDISPLAY SET\n");
				printf("What set?");
				scanf(" %c", &setchoice);
				if(setchoice == 'a'){
					displaySet(a);
				}
				else if(setchoice == 'b'){
					displaySet(b);
				}
				else{
					printf("Invalid choice\n\n");
				}
				break;
			case 4:
				printf("UNION SET\n");
				c = newSet();
				c = unionSet(a, b);
				displaySet(c);
				break;
				
			case 5:
				printf("INTERSECT SET\n");
				c = newSet();
				c = intersectionSet(a, b);
				displaySet(c);
				break;

			case 6:
				printf("DIFFERENCE SET\n");
				c = newSet();
				c = differenceSet(a, b);
				displaySet(c);
				break;
			
			case 7:
				printf("SYMMETRIC DIFFERENCE SET\n");
				c = newSet();
				c = symmetricDiffSet(a, b);	
				displaySet(c);
				break;
				
			case 8:
				printf("CARDINALITY SET\n");
				printf("What set? ");
				scanf(" %c", &setchoice);
				if(setchoice == 'a'){
					cardinal = cardinality(a);
					printf("Cardinality of set %c: %d\n\n", setchoice, cardinal);
				}
				else if(setchoice == 'b'){
					cardinal = cardinality(b);
					printf("Cardinality of set %c: %d\n\n", setchoice, cardinal);
				}
				else if(setchoice == 'c'){
					cardinal = cardinality(c);
					printf("Cardinality of set %c: %d\n\n", setchoice, cardinal);
				}
				else{
					printf("Invalid");
				}
				break;	
			default:
				break;
			}
	}while(choice!=0);
	return 0;
}
