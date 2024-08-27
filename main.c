#include<stdio.h>
#include<stdbool.h>

int main(){
	const char *filename = "source_code.c";
	const char *output_filename = "output.txt";
	FILE *fp = fopen(filename,"rb");
	FILE *out_fp = fopen(output_filename,"rb");
	
	// declaring the buffer
	const char opening_comments[2] = {'/','*'};
	const char closing_comments[2] = {'*','/'};
	
	char buffer[2];	
	bool isOpeningCommentsFound = false;

	// reading the file
	size_t bytesRead;
	while( (bytesRead = fread(buffer,2,1,fp)) != 0){
		if(!isOpeningCommentsFound){
			// here some codition arises 
			// 1) If we found '/' and '*'
			// 2) If we found some other char and '/'
			// 3) If both of them ar not matched 
		}
	}
	



	return 0;
}
