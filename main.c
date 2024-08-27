#include<stdio.h>
#include<stdbool.h>

int main(){
	const char *filename = "source_code2.c";
	const char *output_filename = "output.txt";
	FILE *fp = fopen(filename,"rb");
	FILE *out_fp = fopen(output_filename,"rb");
	if(!fp) { 
		printf("File %s not loaded\n",filename);
		return 0;
	}
	if(!out_fp){
		printf("File %s not loaded\n",output_filename);
		return 0;
	}
	
	// declaring the buffer
	const char opening_comments[2] = {'/','*'};
	const char closing_comments[2] = {'*','/'};
	
	char buffer[2];	
	bool isOpeningCommentsFound = false;
	bool isClosingCommentsFound = false;
	// reading the file
	size_t bytesRead;
	while( (bytesRead = fread(buffer,2,1,fp)) != 0){
		if(!isOpeningCommentsFound){
			// here some codition arises 
			// 1) If we found '/' and '*'
			// 2) If we found some other char and '/'
			// 3) If both of them ar not matched
		
			if(buffer[0] == opening_comments[0] && buffer[1] == opening_comments[1]){
				isOpeningCommentsFound = true;
				printf("\n");
				continue;
			}
			else if(buffer[0] != opening_comments[0] && buffer[1] == opening_comments[0]){
				fseek(fp,-1,SEEK_CUR);
				continue;
			} 
		}
		else {
			if(buffer[0] == closing_comments[0] && buffer[1] == closing_comments[1]){
				isOpeningCommentsFound = false;
				continue;
			}
			
			else if(buffer[0] != closing_comments[0] && buffer[1] == closing_comments[0]){
				printf("%c",buffer[0]);
				fseek(fp,-1,SEEK_CUR);
			}

			else{
				printf("%c%c",buffer[0],buffer[1]);
			}	
		}
	}
	
	return 0;
}
