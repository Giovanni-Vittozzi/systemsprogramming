#include <stdio.h>
#include<stdlib.h>

int squarer(int num1){
	return num1*num1;
}
int main(int argc, char *argv[]){
	//printf("arg num %d",argc);
	if(argc != 2){ //If there are more than two arguments (aka 1)
		printf("Please Enter Only One Number");
		exit(1);//exits program based on too many arguments
	}
	int numy = 0;
	numy=atoi(argv[1]); //converts argument to an integer
	int answer = squarer(numy); //argument passed to function; result returned to answer
	
      	printf("The Square of %d is %d\n",numy,answer);	//Prints ans
	
}


