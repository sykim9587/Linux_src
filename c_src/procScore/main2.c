#include <stdio.h>
#include <string.h>

typedef struct {
	char name[20];
	int kor;
	int eng;
	int mat;
	int sum;
	double average;
	int rank;
} Student;

int main(void)
{
	Student students[10];
	for (int i =0; i<10; ++i){
		scanf("%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].mat);	
		students[i].sum = students[i].kor + students[i].eng + students[i].mat;
		students[i].average = (double)students[i].sum / 3;
		students[i].rank = 1;
	}
	
	//rank
	for (int j = 0; j<10; j++){
		for(int k = 0; k<10; k++){
			if(/*i != k && */students[j].sum < students[k].sum)
				students[j].rank ++ ;
		}
	}
	
	
	printf("-----------------------------------------\n");
	printf("	name	kor eng mat sum  avg  rank\n");
	printf("-----------------------------------------\n");
	for(int i =0; i<10; ++i){
		printf("%-15s %3d %3d %3d %3d %6.2f %2d\n", 
			students[i].name, students[i].kor, students[i].eng, students[i].mat, students[i].sum, students[i].average, students[i].rank);
	}
	

	//sorting
	for(int i = 0; i< 10-1; ++i){
		for (int j = i+1; j<10; ++j){
			if (students[i].sum < students[j].sum){
				Student tmp = students[i];
				students[i] = students[j];
				students[j] = tmp;

			}
		}
	}

printf("-----------------------------------------\n");
	printf("	name	kor eng mat sum  avg  rank\n");
	printf("-----------------------------------------\n");
	for(int i =0; i<10; ++i){
		printf("%-15s %3d %3d %3d %3d %6.2f %2d\n", 
			students[i].name, students[i].kor, students[i].eng, students[i].mat, students[i].sum, students[i].average, students[i].rank);
	}
	
	return 0;
}
