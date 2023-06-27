#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SETS.h"

Set newSet(){
	int i;
	Set newSet;
	for(i=0;i<MAX;++i){
		newSet.elem[i] = false;
	}
	newSet.count = 0;
	return newSet;
}

bool addElement(Set *s, int item){

	if(s->elem[item]==false){
		s->elem[item] = true;
		s->count++;
		return true;
	}
	else{
		return false;
	}
	
}
bool removeElement(Set *s, int item){
	if(s->elem[item]){
		s->elem[item] = false;
		s->count--;
		return true;
	}
	else{
		return false;
	}
}
void displaySet(Set s){
	int i;
	printf("SET DATA\n{ ");
//	for(i=0;i<MAX;++i){
//		if(s.elem[i]){
//			printf("%d ", i);
//		}
//		else{
//			
//		}	
//	}

	for(i=0;i<MAX;++i){
		if(s.elem[i]==true){
			printf("1 ");
		}
		else{
			printf("0 ");
		}
	}
	printf("}\n");
}


Set unionSet(Set a, Set b){
	Set unSet = newSet();
	int i;
	for(i=0;i<MAX;++i){
		if(a.elem[i]|b.elem[i]){
			unSet.elem[i] = true;
			unSet.count++;
		}
	}
	return unSet;
}

Set intersectionSet(Set a, Set b){
	Set unSet = newSet();
	int i;
	for(i=0;i<MAX;++i){
		if(a.elem[i]&b.elem[i]){
			unSet.elem[i] = true;
			unSet.count++;
		}
	}	
	return unSet;
}

Set differenceSet(Set a, Set b){
	Set unSet = newSet();
	Set unSet1 = newSet();
	int i,j;
	for(i=0;i<MAX;++i){
		if(!b.elem[i]&a.elem[i]){
			unSet.elem[i] = true;
			unSet.count++;
		}
	}	
	for(j=0;j<MAX;++j){
		if(a.elem[i]&unSet.elem[i]){
			unSet1.elem[i] = true;
			unSet1.count++;
		}
	}
	return unSet;
}

Set symmetricDiffSet(Set a, Set b){
	Set unSet = newSet();
	int i;
	for(i=0;i<MAX;++i){
		if(!a.elem[i]&b.elem[i]){
			unSet.elem[i] = true;
			unSet.count++;
		}
	}	
	return unSet;
}

int cardinality(Set s){
	return s.count;
}
