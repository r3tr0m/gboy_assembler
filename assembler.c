#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "ultis.c"
#include "optable.c"

inst_t* lexar(char *line){

	//CODE OUT

	inst_t  *inst		= (inst_t*) malloc(sizeof(inst_t));
	char 	*code 		= (char*)   malloc(sizeof(char)*20);
	char 	*cnumber 	= (char*)   malloc(sizeof(char)*5);

	// INCREMENTS

	uint8_t inc	= 0;
	uint8_t cinc	= 0;

	//BOOL STATMENTS

	bool	num	= false;
	bool	sims	= false;
	bool	out	= true;

	//AUTOMATA

	while( (line[inc] != '\x0a') || (line[inc] == ';') )
	{


		for(uint8_t byte=0; byte < 18; byte++)
		{

			if( (line[inc] == '%') || (line[inc] == '$') || (line[inc] == '@') ){
				
				sims = true;
				out  = false;
				break;

			}else if( (line[inc] == ',') || (line[inc] == ')') ){
				
				sims = false;
				out  = true;

				break;

			}else if( (numbers[byte] == line[inc]) && (sims == true) ){

				out = false;
				break;

			}else{
				
				out = true;
				
			}

		}

		if(out == true)
		{
			code[inc] = line[inc];

		}else if( (out == false) && (sims == true) )
		{
	
			cnumber[cinc] = line[inc];
			cinc++;

		}

	inc++;

	}

	//INST OUT

	inst->filecode	= code;
	inst->cnum	= cnumber;
	inst->ibyte	= inc;

	return inst;

}

int16_t convert(char *cnumber){

	int32_t base;

	switch(cnumber[0]){

		case '$':
			base = 16;
			break;

		case '@':
			base = 10;
			break;

		case '%':
			base = 2;
			break;
		default:
			break;
	}

	long n = strtol(&cnumber[1],NULL,base);

	return (int16_t) n;
}


bin_t* assembler(asm_t *program){

	//PROGRAM TEMP MEMORY

	bin_t 	*bin_c		= (bin_t*) malloc(sizeof(bin_t));
	char 	*binary		= (char*)  malloc(program->size);

	uint32_t inc		= 0;
	uint32_t ibyte		= 0;

	while(ibyte < program->size){

		//AUTOMATA

		inst_t	*inst 		= lexar(&program->file_code[ibyte]);

		if(inst->cnum[0] != 0x00)
		{
			int16_t num 	= convert(inst->cnum);
			inst->number	= num;
		}

		uint32_t hcode		= hash(inst->filecode);
		inst->hash		= hcode;

		//PUT IN MEMORY


		inc += opcode(&binary[inc],inst);
		ibyte += inst->ibyte +1;

		free(inst);

	}

	bin_c->code = binary;
	bin_c->size = inc;

	return bin_c;

}

int main(uint8_t argc,char **argv){

	//MAIN ENTRY

	if(argc < 2)
	{
		printf("%s <program.asm>\n",argv[0]);
		return -1;
	}

	char *target = argv[1];

	//MAIN PROGRAM CONTROL

	asm_t *code 	 = load_code(target);
	bin_t *bin_code  = assembler(code);
	_bin_out_(bin_code);

}
