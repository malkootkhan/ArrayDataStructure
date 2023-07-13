
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* More in-depth implementation of Array DTS in c: almost all common operations are performed the array in this code, it is the updated version of main branch it */
/*
In-depth Implementation of various functions of array DST in C
File: Main.c
Author: Malkoot Khan
Date: 13/07/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

struct Array {
	int capacity;
	int lastIndex;
	int* item;
};

inline bool isFull(struct Array* arr) {
	if (arr->lastIndex == arr->capacity - 1)
		return true;
	return false;
}
inline bool isEmpty(struct Array* arr) {
	if (arr->lastIndex == -1)
		return true;
	return false;
}
inline bool isValid(struct Array* arr, int index) {
	if (index >= 0 && index < arr->capacity)
		return true;
	return false;
}
inline int getCapacity(struct Array* arr) 
{
	return arr->capacity;
}
inline int getSize(struct Array* arr) 
{
	if (!isEmpty(arr))
		return arr->lastIndex + 1;
	printf("The array is empty");
	return 0;
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
void deleteData(struct Array* arr, int data) {
	if (!isEmpty(arr)) {
		for (int i = 0; i <= arr->lastIndex; i++) {
			if (data == arr->item[i]) {
				if (i == arr->lastIndex) {
					arr->item[arr->lastIndex] = 0;
					arr->lastIndex--;
					return;
				}
				for (int j = i; j < arr->lastIndex; j++) {
					arr->item[j] = arr->item[j + 1];
					arr->item[arr->lastIndex] = 0;
					arr->lastIndex--;
					return;
				}
			}
		}
	}
	printf("The array is empty!\n");
	return;
}
int findLargest(struct Array *arr) {
	if (isEmpty(arr))
	{
		printf("The array is empty!\n");
		return -1;
	}
	int max = arr->item[0];
	for (int i = 0; i <= arr->lastIndex; i++) {
		if (max < arr->item[i])
			max = arr->item[i];
	}
	return max;
}
int findSmallest(struct Array* arr) {
	if (!isEmpty(arr)) {
		int min = arr->item[0];
		for (int i = 0; i <= arr->lastIndex; i++) {
			if (min > arr->item[i])
				min = arr->item[i];
		}
		return min;
	}
	printf("The array is empty!\n");
	return -1;
}
int search(struct Array* arr, int element) {
	if (!isEmpty(arr)) {
		for (int i = 0; i <= arr->lastIndex; i++) {
			if (element == arr->item[i])
				return i;
		}
		printf("Element not found!\n");
		return -1;
	}
	printf("The array is empty!\n");
	return -1;
}
int getSum(struct Array* arr) {
	if (!isEmpty(arr)) {
		int sum = 0;
		for (int i = 0; i <= arr->lastIndex; i++) 
			sum += arr->item[i];
		return sum;
		
	}
	else
		printf("\nThe array is empty!\n");
	return -1;
}
float getAverage(struct Array* arr) {
	return (float)getSum(arr) / (arr->lastIndex + 1);
}
void rotateRightByOnePos(struct Array *arr) {
	if (!isEmpty(arr)) {
		int temp = arr->item[arr->lastIndex];
		for (int i = arr->lastIndex; i > 0; i--) 
			arr->item[i] = arr->item[i - 1];
		arr->item[0] = temp;
		return;
	}
	printf("The array is empty!\n");
	return;
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sort(struct Array* arr) {
	if (!isEmpty(arr)) {
		bool flag; 
		for (int i = 0; i <= arr->lastIndex; i++) {
			flag = true;
			for (int j = 1; j <= arr->lastIndex - i; j++) {
				if (arr->item[j - 1] > arr->item[j])
				{
					swap(&arr->item[j - 1], &arr->item[j]);
					flag = false;
				}
			}
			if (flag)
				return;
		}
		
	}
	printf("The array is empty!\n");
	return;
}
void removeDuplicate(struct Array* arr) {
	if (isEmpty(arr)) {
		printf("The array is empty!\n");
		return;
	}
	for (int i = 1; i <= arr->lastIndex; i++) {
		if (arr->item[i - 1] == arr->item[i])
		{
			for (int j = i; j < arr->lastIndex; j++)
				arr->item[j] = arr->item[j + 1];
			arr->item[arr->lastIndex] = 0;
			arr->lastIndex--;
		}
	}
}

int secondLargest(struct Array* arr) {
	if (!isEmpty(arr)) {
		struct Array* tempArr = arr;
		deleteData(tempArr, findLargest(arr));
		int secLargest =  findLargest(tempArr);
		return secLargest;

	}
	printf("The array is empty!\n;");
	return -1;
}
int main() {
	/*Random implementation of the above functions to test the working*/ 
	/*you can invoke these function in your code as you like*/
	int capacity;
	struct Array* arr = NULL;
	capacity = 10;
	arr = initialize(capacity);
	insert(arr, 10);
	insert(arr,20);
	insert(arr, 30);
	insert(arr, 30);
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

	printf("Largest element in the array: %d\n", findLargest(arr));

	insert(arr, 500);
	display(arr);
	printf("Largest element in the array: %d\n", findLargest(arr));
	printf("The smallest element: %d", findSmallest(arr)); printf("\n");

	int element = 40;
	printf("index of %d: %d\n", element, search(arr, element));
	printf("The sum of elements: %d\n",getSum(arr));
	printf("The average: %.2f\n", getAverage(arr));

	rotateRightByOnePos(arr);
	display(arr);
	sort(arr);
	display(arr);
	insertAtPos(arr, 50,4);
	insertAtPos(arr, 50,5);
	display(arr);
	removeDuplicate(arr);
	display(arr);
	printf("second largest: %d\n", secondLargest(arr));
	releaseMemory(arr);

	return 0;
}

