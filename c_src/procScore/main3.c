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
	FILE *fin, *fout;
	fin = fopen("score.dat", "r");
	fout = fopen("score.out", "w");
	

	Student students[10];
	for (int i =0; i<10; ++i){
		fscanf(fin,"%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].mat);	
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
	
	
	fprintf(fout,"-----------------------------------------\n");
	fprintf(fout,"	name	kor eng mat sum  avg  rank\n");
	fprintf(fout,"-----------------------------------------\n");
	for(int i =0; i<10; ++i){
		fprintf(fout,"%-15s %3d %3d %3d %3d %6.2f %2d\n", 
			students[i].name, students[i].kor, students[i].eng, students[i].mat, students[i].sum, students[i].average, students[i].rank);
	}
	

	//sorting
	Student* table[10];
	for(int i=0; i<10; ++i)
		table[i] = &students[i];
		
	for(int i = 0; i< 10-1; ++i){
		for (int j = i+1; j<10; ++j){
			if (table[i]->sum < table[j]->sum){
				Student *tmp = table[i];
				table[i] = table[j];
				table[j] = tmp;

			}
		}
	}

	fprintf(fout,"-----------------------------------------\n");
	fprintf(fout,"	name	kor eng mat sum  avg  rank\n");
	fprintf(fout,"-----------------------------------------\n");
	for(int i =0; i<10; ++i){
		fprintf(fout,"%-15s %3d %3d %3d %3d %6.2f %2d\n", 
			table[i]->name, table[i]->kor, table[i]->eng, table[i]->mat, table[i]->sum, table[i]->average, table[i]->rank);
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}
