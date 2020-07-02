#define MEMSIZE 4096
#define OFFSET  512


//For save/load states
typedef struct {
	unsigned char gfx[64*32];
	unsigned short pc;
	unsigned short opcode;
	unsigned short I;
	unsigned short sp;
	
	unsigned char V[16];
	unsigned short stack[16];
	unsigned char key[16];
	
	unsigned char dt;
	unsigned char st;
	char DrawFlag;
	
	char RomName[1000];
}Chip8State;
Chip8State State;
////////////////////////////////////////

//Main Chip8 struct
typedef struct  {
	unsigned char gfx[64*32]; //2048 video 
	unsigned char key[16];
	
	unsigned short pc; //program counter
	unsigned short opcode;
	unsigned short I; //index register
	unsigned short sp; //stack pointer
	
	unsigned char V[16]; //V-regs(V0-VF)
	unsigned short stack[16]; //Stack (16 levels)
	
	unsigned char *memory; // for alloc
	
	unsigned char delay_timer;
	unsigned char sound_timer;
	
	char DrawFlag;
	FILE *RomFile;
	char RomName[1000];
} Chip8Emulator;
 Chip8Emulator  Chip8Emu;


unsigned char Chip8Font[80] =
{ 
    0xF0, 0x90, 0x90, 0x90, 0xF0, //0
    0x20, 0x60, 0x20, 0x20, 0x70, //1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
    0x90, 0x90, 0xF0, 0x10, 0x10, //4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
    0xF0, 0x10, 0x20, 0x40, 0x40, //7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
    0xF0, 0x90, 0xF0, 0x90, 0x90, //A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
    0xF0, 0x80, 0x80, 0x80, 0xF0, //C
    0xE0, 0x90, 0x90, 0x90, 0xE0, //D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
    0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};


