
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* Basic Array implementation in c */
/*
Priority Queue Implementation in C
File: Main.c
Author: Malkoot Khan
Date: 12/07/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

struct Array {
	int capacity;
	int lastIndex;
	int* item;
};
bool isFull(struct Array* arr) {
	if (arr->lastIndex == arr->capacity - 1)
		return true;
	return false;
}
bool isEmpty(struct Array* arr) {
	if (arr->lastIndex == -1)
		return true;
	return false;
}
bool isValid(struct Array* arr, int index) {
	if (index >= 0 && index < arr->capacity)
		return true;
	return false;
}
struct Array* initialize(int cap) {
	struct Array* arr = (struct Array*)malloc(sizeof(struct Array));
	arr->capacity = cap;
	arr->lastIndex = -1;
	arr->item = (int*)malloc(sizeof(int) * cap);
	return arr;
}
void insert(struct Array* arr, int data) {
	if (arr->lastIndex == arr->capacity - 1)
		printf("The array is full!\n");
	else
	{
		arr->lastIndex++;
		arr->item[arr->lastIndex] = data;
	}
	return;
}
void insertAtPos(struct Array* arr,int data, int index) {
	if (index >= 0 && index < arr->capacity) {
		if (!isFull(arr)) {
			for (int i = arr->lastIndex; i >= index; i--) 
				arr->item[i + 1] = arr->item[i];
			arr->lastIndex++;
			arr->item[index] = data;

		}
		else
			printf("Array is already Full!\n");
	}
	else
		printf("Invalid index!\n");
}
void display(struct Array* arr) {
	if (isEmpty(arr))
	{
		printf("The array is already empty!\n");
		return;
	}
	else {
		for (int i = 0; i <= arr->lastIndex; i++)
			printf("%d ", arr->item[i]);
	}
	printf("\n");
}
void deleteLastItem(struct Array* arr) {
	if (isEmpty(arr)) {
		printf("The array is empty!\n");
		return;
	}
	else
	{
		arr->item[arr->lastIndex] = 0;
		arr->lastIndex--;
	}

}
void deleteAtPos(struct Array* arr, int index) {
	if (isValid(arr, index)) {
		for (int i = index; i < arr->lastIndex; i++)
			arr->item[i] = arr->item[i + 1];
		arr->item[arr->lastIndex] = 0;
		arr->lastIndex--;
	}
	else
		printf("Invalid index!\n");
}
void releaseMemory(struct Array *arr) {
	free(arr->item);
	free(arr);
}
int getCapacity(struct Array* arr) { return arr->capacity; }
int getSize(struct Array* arr) { return arr->lastIndex + 1; }
int main() {
	int data, index,capacity;
	struct Array* arr = NULL;
	printf("Enter capacity for array ");
	scanf("%d", &capacity);
	arr = initialize(capacity);
	insert(arr, 10);
	insert(arr,20);
	insert(arr, 30);
	insert(arr, 40);
	insert(arr, 50);
	insert(arr, 60);

	printf("\nSize: %d", getSize(arr)); printf("\n");
	display(arr);

	insertAtPos(arr, 111, 3);

	printf("\nSize: %d", getSize(arr)); printf("\n");
	display(arr);

	insertAtPos(arr, 111, 7);

	printf("\nSize: %d", getSize(arr)); printf("\n");
	display(arr);
	
	deleteLastItem(arr);

	printf("\nSize: %d", getSize(arr)); printf("\n");
	display(arr);

	deleteAtPos(arr, 5);

	printf("\nSize: %d", getSize(arr)); printf("\n");
	display(arr);

	printf("\nCapacity: %d", getCapacity(arr)); printf("\n");

	releaseMemory(arr);
;

	return 0;
}

