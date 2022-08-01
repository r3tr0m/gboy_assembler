enum instructions{

	//SET 1

	nop 	 	= 1005,
	ld_bc 	 	= 1271,
	ld_$bc_a	= 1776,
	inc_bc	 	= 1465,
	inc_b	 	= 1057,
	dec_b	 	= 1010,
	ld_b	 	= 1205,
	rlca 	 	= 1215,
	ld_$_sp		= 1529,
	add_hl_bc	= 2250,
	ld_a		= 1222,
	dec_bc		= 1400,
	inc_c		= 1055,
	dec_c		= 1008,
	ld_c		= 1212,
	rrca		= 1063,

	//SET 2

	stop		= 1210,
	ld_de		= 1293,
	ld_$de_a	= 1774,
	inc_de		= 1487,
	inc_d		= 1077,
	dec_d		= 994,
	ld_d		= 1243,
	rla		= 1126,
	jr_i8		= 613,
	add_hl_de	= 2272,
	ld_a_$de	= 2437,
	dec_de		= 1386,
	inc_e		= 1075,
	dec_e		= 992,
	ld_e		= 1250,
	rra		= 964,

	//SET 3

	jr_nz_i8	= 1372+1,
	ld_hl_u16	= 1244,
	ld_$hl_a	= 1797,
	inc_hl		= 1495,
	inc_h		= 1093,
	dec_h		= 1034,
	ld_h_u8		= 1223+1,
	dda		= 894,
	jr_z_i8		= 1283,
	add_hl_hl	= 2256,
	ld_a_$hl	= 2388,
	dec_hl		= 1442,
	inc_l		= 1109,
	dec_l		= 1026,
	ld_l_u8		= 1251,
	cpl		= 1042,

	//SET 4

	jr_nc_i8	= 1445,
	ld_sp_u16	= 1340,
	ld_$hl__a	= 1977,
	inc_sp		= 1534,
	inc_$hl		= 2110,
	dec_$hl		= 2033,
	ld_$hl_u8	= 1550,
	scf		= 1063+1,
	jr_c_i8		= 1372,
	add_hl_sp	= 2375,
	ld_a_$hl_	= 2775,
	dec_sp		= 1481,
	inc_a		= 1059,
	dec_a		= 1000,
	ld_a_u8		= 1222+1,
	ccf		= 903,

};

int32_t opcode(char *memory,inst_t *inst){

	uint8_t *data 	= (uint8_t*) &inst->number;
	uint8_t  byte 	= 1;
	bool 	 data1	= false;
	bool	 data2	= false;

	switch(inst->hash){

			//SET 1

			case nop:
				*memory = 0x00;
				break;

			case ld_bc:
				memory[0] = 0x01;
				data2	  = true;
				break;

			case ld_$bc_a:
				memory[0] = 0x02;
				data2	  = true;
				break;

			case inc_bc:
				memory[0] = 0x03;
				break;

			case inc_b:
				memory[0] = 0x04;
				break;

			case dec_b:
				memory[0] = 0x05;
				break;

			case ld_b:
				memory[0] = 0x06;
				data1     = true;
				break;

			case rlca:
				memory[0] = 0x07;
				break;

			case ld_$_sp:
				memory[0] = 0x08;
				data2     = true;
				break;

			case add_hl_bc:
				memory[0] = 0x09;
				break;

			case ld_a:
				memory[0] = 0x0a;
				data1     = true;
				break;

			case dec_bc:
				memory[0] = 0x0b;
				break;

			case inc_c:
				memory[0] = 0x0c;
				break;

			case dec_c:
				memory[0] = 0x0d;
				break;

			case ld_c:
				memory[0] = 0x0e;
				data1     = true;
				break;

			case rrca:
				memory[0] = 0x0f;
				break;

			//SET 2

			case stop:
				memory[0] = 0x10;
				break;

			case ld_de:
				memory[0] = 0x11;
				data2     = true;
				break;

			case ld_$de_a:
				memory[0] = 0x12;
				data2     = true;
				break;

			case inc_de:
				memory[0] = 0x13;
				break;

			case inc_d:
				memory[0] = 0x14;
				break;

			case dec_d:
				memory[0] = 0x15;
				break;

			case ld_d:
				memory[0] = 0x16;
				data1     = true;
				break;

			case rla:
				memory[0] = 0x17;
				break;

			case jr_i8:
				memory[0] = 0x18;
				data1     = true;
				break;

			case add_hl_de:
				memory[0] = 0x19;
				break;

			case ld_a_$de:
				memory[0] = 0x1a;
				break;

			case dec_de:
				memory[0] = 0x1b;
				break;

			case inc_e:
				memory[0] = 0x1c;
				break;

			case ld_e:
				memory[0] = 0x1e;
				data1 = true;
				break;

			case rra:
				memory[0] = 0x1f;
				break;

			//SET 3

			case jr_nz_i8:
				memory[0] = 0x20;
				data1	  = true;
				break;

			case ld_hl_u16:
				memory[0] = 0x21;
				data2     = true;
				break;

			case ld_$hl_a:
				memory[0] = 0x22;
				break;

			case inc_hl:
				memory[0] = 0x23;
				break;

			case inc_h:
				memory[0] = 0x24;
				break;

			case dec_h:
				memory[0] = 0x25;
				break;

			case ld_h_u8:
				memory[0] = 0x26;
				break;

			case dda:
				memory[0] = 0x27;
				break;

			case jr_z_i8:
				memory[0] = 0x28;
				break;

			case add_hl_hl:
				memory[0] = 0x29;
				break;

			case ld_a_$hl:
				memory[0] = 0x2a;
				break;

			case dec_hl:
				memory[0] = 0x2b;
				break;

			case inc_l:
				memory[0] = 0x2c;
				break;

			case dec_l:
				memory[0] = 0x2d;
				break;

			case ld_l_u8:
				memory[0] = 0x2e;
				data1     = true;
				break;

			case cpl:
				memory[0] = 0x2f;
				break;

			//SET 4

			case jr_nc_i8:
				memory[0] = 0x30;
				data1     = true;
				break;

			case ld_sp_u16:
				memory[0] = 0x31;
				data2     = true;
				break;

			case ld_$hl__a:
				memory[0] = 0x32;
				break;

			case inc_sp:
				memory[0] = 0x33;
				break;

			case inc_$hl:
				memory[0] = 0x34;
				break;

			case dec_$hl:
				memory[0] = 0x35;
				break;

			case ld_$hl_u8:
				memory[0] = 0x36;
				data1     = true;
				break;

			case scf:
				memory[0] = 0x37;
				break;

			case jr_c_i8:
				memory[0] = 0x38;
				data1     = true;
				break;

			case add_hl_sp:
				memory[0] = 0x39;
				break;

			case ld_a_$hl_:
				memory[0] = 0x3a;
				break;

			case dec_sp:
				memory[0] = 0x3b;
				break;

			case dec_a:
				memory[0] = 0x3d;
				break;

			case ld_a_u8:
				memory[0] = 0x3e;
				data1     = true;
				break;

			case ccf:
				memory[0] = 0x3f;
				break;

			//SET 5


			default:
				break;

	}

	if(data2 == true){

                 memory[1] = data[1];
                 memory[2] = data[0];
                 byte+=2;

	}else if(data1 == true){

                 memory[1] = data[1];
                 byte+=1;

	}

	return byte;
}
