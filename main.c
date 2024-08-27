#include<stdio.h>
#include<stdbool.h>

int main(int argc,unsigned char *argv[]){
	const char *filename = argv[1];
	FILE *fp = fopen(filename,"rb");
	if(!fp){
		printf("File could not be loaded!\n");
		return 0;
	}
	
	// declaring the buffer	
	char buffer[2];	
	int openingCommentCount = 0;

	while( fread(buffer,2,1,fp) != 0 ){
		// | '/' | '*' |
		if(buffer[0] == '/' && buffer[1] == '*'){
			openingCommentCount +=1;
			continue;
		}

		if(openingCommentCount == 0){
			if(buffer[0]!= '/' && buffer[1] == '/'){
				fseek(fp,-1,SEEK_CUR);
			}
		}

		if(openingCommentCount > 0){
			//  | '*' | '/' |
			if(buffer[0] == '*' && buffer[1] == '/'){
				openingCommentCount -= 1;
				if(openingCommentCount == 0)
					printf("\n");
				continue;
			}

			// | 'x' | '/' or '*' | 
			if(buffer[0] != '/' && buffer[0] != '*' && (buffer[1] == '/' || buffer[1] == '*')){
				printf("%c",buffer[0]);
				fseek(fp,-1,SEEK_CUR);
				continue;
			}

			// | 'x' | 'y' |
			if( (buffer[0] != '*' && buffer[0] != '/') && (buffer[1] != '*' && buffer[1] != '/') ){
				printf("%c%c",buffer[0],buffer[1]);
			}
		}
	}

	return 0;
}
