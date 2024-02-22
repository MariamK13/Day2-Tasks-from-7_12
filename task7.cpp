#include <iostream>

void bubble (int* arr, int size);
void selection (int* arr, int size);
void (*fptr) (int*, int);

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
	char choose;
	std::cout << "enter 'b' for bubble sort and 's' for selection sort" << std::endl;
	std::cin >> choose;
	switch (choose) {
		case 'b': 
			fptr = bubble;
			break;
		case 's':
			fptr = selection;
			break;
		default:
			std::cout << "invalid option";
			break;
	}
	fptr (arr, size);
	std::cout << "here is a sorted array" << std::endl;
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


