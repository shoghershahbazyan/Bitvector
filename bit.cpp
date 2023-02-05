#include <iostream>

const int bitSize= 8 * sizeof(int);
int GetSize(){
	
	int size = 0;
	do{
		std :: cout << "How many elements do you need?"<< std :: endl;
		std :: cin >> size;
	}while( size < 0);
	return size ;
}

unsigned int * MakeArr(int size){
	 unsigned int * arr =  new unsigned int[size/bitSize + 1];
	return arr;
}
void SetReset (unsigned int * ptr, int const size){
	int index= 0;	
	char exit ;
	do{
	do {
	std :: cout << "Which index do you want to change: "<< std :: endl;
	std:: cin >> index;
	}while (index <0 || index >= size);
	int position = index/bitSize ;
	index = index % bitSize;
	std :: cout << "Pres s to set or r to reset: " << std :: endl ;
	char setReset;
	std :: cin>> setReset ;
	if(setReset == 's'){
		ptr[position]= ptr[position] | 1 << index ;
		}else if(setReset == 'r'){			
		ptr[position]= ptr[position] | 1 << index ;	
		ptr[position]= ptr[position] ^ 1 << index ;
		}
	std :: cout << ptr[position] << std :: endl; 
	std :: cout<< "Press x to exit, or any other button to continue: "<< std :: endl;
	std :: cin >> exit; 
	}while(exit != 'x');
}

int main(){

	int size = GetSize();
	unsigned int * arr = MakeArr(size);
	SetReset(arr, size);	
	for( int i =0 ; i<size/bitSize+1; i++){
		std :: cout << arr[i]<< std :: endl;
	}
	delete [] arr;
	return 0;
}
