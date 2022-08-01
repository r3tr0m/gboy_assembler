//GLOBAL VARIABLES

char *numbers   = "%$0123456789abcdef";

//DATA STRUTURES

typedef struct asm_code{

        char *file_code;
        uint32_t size;

}asm_t;

typedef struct inst{

	char 	 *filecode;
	char 	 *cnum;

	uint16_t number;
	uint8_t ibyte;
	uint32_t hash;

}inst_t;

typedef struct bin{

	char *code;
	uint32_t size;

}bin_t;


//ERROR HANDLING

void log_program(char *session,void *code,uint32_t error_code){

        int32_t session_code = *(uint32_t*) &code;

        if(session_code == error_code){

		fprintf(stderr,"[ %s ] Failure\n",session);
                exit(-1);
        }

	fprintf(stdout,"[ %s ] Success\n",session);

}

//LOAD CODE

asm_t* load_code(char *target){

        int32_t fd = open(target,O_RDONLY);

        struct stat fileInfo;
        fstat(fd,&fileInfo);

        char  *fileCode = (char*)  malloc(fileInfo.st_size);
        asm_t *program  = (asm_t*) malloc(sizeof(asm_t));

        read(fd,fileCode,fileInfo.st_size);

        program->file_code      = fileCode;
        program->size           = fileInfo.st_size;

        return program;

}

//CHECKSUM

int32_t hash(char *code){

        uint32_t hash   = 0;
        uint8_t size    = strlen(code);

        uint16_t r1 = 0;
        uint16_t r2 = 0;
        uint16_t r3 = 0;

        uint16_t ts;

        for(uint8_t byte=0; byte < size; byte++){

                if( (code[byte] != '\x00') && (code[byte] != '\x0a') && (code[byte] != '\x20') ){

                        ts = (code[byte]<<8) * (code[byte+1]<<8);

                        r1 ^= (code[byte]) ^ (ts ^ byte);
                        r2 ^= (code[byte]) ^ (ts ^ byte);
                        r3 ^= (code[byte]) ^ (ts ^ byte);

                        hash += r1 + r2 + r3 + (code[byte]);

                }

        }

	return hash;

}

//BIN OUT

int8_t _bin_out_(bin_t *binary){

	int fd = open("code.bin",O_WRONLY | O_CREAT,0766);

	if(fd == -1){
		printf("[!]Error in creating code.bin\n");
		return -1;
	}

	for(uint32_t byte=0; byte < binary->size; byte++){

		write(fd,&binary->code[byte],sizeof(char));

	}

	return 0;

}
