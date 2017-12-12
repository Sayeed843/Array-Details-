#include<stdio.h>
#include<stdlib.h>

void oneDimensionArray();
void twoDimensionArray();
int * createArray();
void displayArray(int *num,int Size);

static int arraySize;

int main()
{
	printf("One Dimention Array\n");
    oneDimensionArray();
	printf("\n");
	printf("Two Dimention Array\n");
    twoDimensionArray();
	printf("\n");
	printf("Create a Dynamic Array\n");
	int *newArray;
	newArray = createArray();
	displayArray(newArray,arraySize);
    return 0;
}

void oneDimensionArray()
{
    int num[10];
    int i,j;
    for(i=0;i<10;i++)
    {
        num[i]=i+100;
    }

    for(j=0;j<10;j++)
    {
        printf("Element[%d] = %d\n",j,num[j]);
    }
}

void twoDimensionArray() 
{
    int matrix[10][10];

    // take the value for Two dimentional array
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("Enter the value: ");
            scanf("%d",&matrix[i][j]);
        }
    }

    // print the matrix	
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

//return a array from a function
int * createArray()
{	

	printf("Enter the Array Size: ");
	scanf("%d", &arraySize);
	
	/*Local variable address can not return by a fuction.
	 * So, we should make our variable 'static' 
	 * Mind it, num[arraySize] can not work. So, we will
	 * crate a point first then make it dynamic array.
	 * */

	static int *num;
	 /* 
	  *firstly *num is a pointer then it make int array by (int *) 
	  *malloc means 'Memory Location' and num array use arraySize location
	  * in RAM.
	  */
	num = (int *)malloc(arraySize*sizeof(int)); // dynamic array create
	
	for(int i=0;i<arraySize;i++)
	{
		printf("Enter the value: ");
		scanf("%d",&num[i]);
	}
	return num;
}

// passing a array from main function for print
void displayArray(int *num,int arraySize)
{
	for(int i=0; i<arraySize; i++)
	{
		printf("Value: %d\n", num[i]);
	}
}

