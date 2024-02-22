#include <iostream>

enum SortingStrategy {
	BUBBLE_SORT,
	SELECTION_SORT
};

struct SortingOption {
	SortingStrategy value;
    void (*fptr) (int*, int);
};

void bubble (int* arr, int size);
void selection (int* arr, int size);

int main()
{	
	srand(time(0));
	int size;
	std::cout << "enter array size" << std::endl;
	std::cin >> size;
	int* arr = new int [size];
	std::cout << "An initial array" << std::endl;
	for (int i = 0; i < size; ++i) {
		arr[i] = 1 + rand() % 100;
	}
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	SortingOption sortingArr [] = {
		{BUBBLE_SORT, bubble},
		{SELECTION_SORT, selection}
	};
	int choice = 0;
	std::cout << "enter 0 for bubble sort and 1 for selection sort" << std::endl;
	std::cin >> choice;
	if (choice < 0 || choice > 1) {
		std::cout << "Bad choice, buy" << std::endl;
		return 0;
	}
		
	SortingOption selected = sortingArr[choice];
	selected.fptr (arr, size);
	std::cout << "sorted array" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}

	delete [] arr;
}

void bubble (int* arr, int size)
{
	bool swapped = false;
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap (arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}

}

void selection (int* arr, int size)
{
	int min_index = 0;
	for (int i = 0; i < size - 1; ++i) {
		min_index = i;
		for (int j = i + 1; j < size; ++j) {
			if (arr[j] < arr[min_index]) 
				min_index = j;
			}

			if (i != min_index) 
				std::swap(arr[i], arr[min_index]);
		}
}


