#include <stdlib.h>
#include <direct.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <sys/stat.h>
#include <GL/freeglut.h>

#define TRUE 1
#define FALSE 0

//======= CONTROL KEYS==========
//const enum ChipState{
	//_DebugShow,
	//_Pause,
	//_Step,
	//_Reset,
	//_LoadState,
	//_SaveState,
	//_RomIsLoad,
	//_IsRamFile
//};

//typedef struct {
	////char _DebugShow;
	////char _Pause;
	////char _Step;
	////char_Reset;
	////char _LoadState;
	////char _SaveState;
	////char _RomIsLoad;
	////char _IsRamFile;
//}Chip8Stae;

unsigned long StepCnt=0;
char _DebugShow =FALSE;
char _Pause =FALSE;
char _Step  =FALSE; 
char _Reset =FALSE;
char _LoadState =FALSE;
char _RomIsLoad=FALSE;
char _IsRamFile=FALSE;
 //=============================

typedef struct {
	long WinW, WinH;
	char WinTitle[100], FLTKScheme[50];
}AppConfig ;
AppConfig Config;

#include "wrapFLTK.h"
#include "InChip8.h"
#include "Chip8Emulate.h"

 
#define CONFIGFILE "config.txt"
#define SFILE "States/StateMenu.txt"

#define SCREEN_WIDTH 64
#define SCREEN_HEIGHT 32
#define MODIFIER 10
#define modifier MODIFIER
#define MENUH 18
#define SCROFFSET MENUH //Gl screen offset on Fltk window

#define CTRL(key) FL_CTRL +  key 
#define FKEY(key) FL_F  + key

struct _stat s; //file info


 
// Window size
int display_width = MODIFIER * SCREEN_WIDTH;
int display_height = MODIFIER* SCREEN_HEIGHT;

typedef unsigned __int8 u8;
u8 screenData[SCREEN_HEIGHT][SCREEN_WIDTH][3];
 
//============
Fl_Double_Window *MainWin =NULL, *DebugWin =NULL;
Fl_Text_Buffer *DebugBuf =NULL;
Fl_Text_Display *DebugTextDisplay =NULL;
Fl_Glut_Window *GlutWin = NULL;
Fl_Menu_Bar *MenuBar =NULL;
Fl_Menu_Item *Mitem =NULL;
Fl_Native_File_Chooser *FChooser=NULL;
long SaveState[5]={}, LoadState[5]={};
char *MenuItemLabel[5]={}; //for alloc  strdup() 
const char *StateMenu[5][100]={};
//=============================================

int LoadFileToMemory(void);
int Display(void);
void SetupTexture(void);
void ReshapeWin(void);
void FltkKeyboardDown(long key);
void FltkKeyboardUp(long key);
void CheckKeyPressed(void);
void DebugShowState(void);
void LoadStateMenuFile(char *sbuf[][100]);

//==========EMULATION==============================
int InitChip8(void){	
	//Clear
	Chip8Emu.pc =0x200; //512
	Chip8Emu.opcode =0;
	Chip8Emu.I =0;
	Chip8Emu.sp =0;
	//Clear
	memset(Chip8Emu.memory, 0, MEMSIZE); 
	
	memset(Chip8Emu.gfx, 0, 64*32);
	memset(Chip8Emu.stack, 0, 16);
	memset(Chip8Emu.V, 0, 16);
	memset(Chip8Emu.key, 0,16);
	
	//Reset timers
	Chip8Emu.delay_timer =0;
	Chip8Emu.sound_timer =0;
	
	//Load Font
	memcpy(Chip8Emu.memory, Chip8Font, 80);
	//Clear screen once
	Chip8Emu.DrawFlag = TRUE;
	srand(time(NULL));
	return 0;
}

int  CheckChipFile(const char *FileName){

	Chip8Emu.RomFile = fopen(FileName, "rb");
	if(Chip8Emu.RomFile ==NULL){
		fputs("File read error", stderr);
		return 0;
	}
	fstat(fileno(Chip8Emu.RomFile), &s); //get file info
	sprintf(Chip8Emu.RomName, "%s", FileName);
	printf("\nCurrent file:'%s'\n", FileName);
	printf("FileSize: %d bytes\n", s.st_size);
	
	if(s.st_size > (MEMSIZE - OFFSET) ){
		printf("Wrong file,too big for memory!\n");
		return 0;
	}
	return 1;
}

int CheckRamFile(const char *FileName){
	
	Chip8Emu.RomFile = fopen(FileName, "rb");
	if(Chip8Emu.RomFile ==NULL){
		fputs("File read error", stderr);
		return 0;
	}
	fstat(fileno(Chip8Emu.RomFile), &s);
	printf("\nCurrent file:'%s'\n", FileName);
	printf("FileSize: %d bytes\n", s.st_size);
	
	if(s.st_size > MEMSIZE){
		printf("Wrong Ram file,too big (>4096)!\n");
		return 0;
	}
	
	return 1;
}

void InitGlutEmulator(){
	SetupTexture();
	ReshapeWin(); //one time  resize window
	
	GlutDisplayFunc(&Display);
	GlutIdleFunc(&Display);
	
	//GlutKeyboardFunc(  );
	//Fltk no GlutKeyboardUpFunc ???
	//see CheckKeyPressed() , call from Display() func
}
 
void CheckKeyPressed(void){
	switch(Fl_EventNumber()){
		case FL_EVENT_SHORTCUT: FltkKeyboardDown( Fl_EventKey());break; // not FL_EVENT_KEYDOWN ??
		case FL_EVENT_KEYUP :   FltkKeyboardUp( Fl_EventKey() );break;
	} 
 
}

void FltkKeyboardDown(long key ){	
	
	// _KEY  file Chip8Emulator.h
	switch(key){
		case '1': _KEY[0x1]=1;break;
		case '2': _KEY[0x2]=1;break;
		case '3': _KEY[0x3]=1;break;
		case '4': _KEY[0xC]=1;break;
		
		case 'q': _KEY[0x4]=1;break;
		case 'w': _KEY[0x5]=1;break;
		case 'e': _KEY[0x6]=1;break;
		case 'r': _KEY[0xD]=1;break;
		
		case 'a': _KEY[0x7]=1;break;
		case 's': _KEY[0x8]=1;break;
		case 'd': _KEY[0x9]=1;break;
		case 'f': _KEY[0xE]=1;break;
		
		case 'z': _KEY[0xA]=1;break;
		case 'x': _KEY[0x0]=1;break;
		case 'c': _KEY[0xB]=1;break;
		case 'v': _KEY[0xF]=1;break;
	}
	
}

void FltkKeyboardUp( long key ){
	// _KEY  file Chip8Emulator.h
	switch(key){
		case '1': _KEY[0x1]=0;break;
		case '2': _KEY[0x2]=0;break;
		case '3': _KEY[0x3]=0;break;
		case '4': _KEY[0xC]=0;break;
		
		case 'q': _KEY[0x4]=0;break;
		case 'w': _KEY[0x5]=0;break;
		case 'e': _KEY[0x6]=0;break;
		case 'r': _KEY[0xD]=0;break;
		
		case 'a': _KEY[0x7]=0;break;
		case 's': _KEY[0x8]=0;break;
		case 'd': _KEY[0x9]=0;break;
		case 'f': _KEY[0xE]=0;break;
		
		case 'z': _KEY[0xA]=0;break;
		case 'x': _KEY[0x0]=0;break;
		case 'c': _KEY[0xB]=0;break;
		case 'v': _KEY[0xF]=0;break;
	}
	
}
 
int LoadFileToMemory(void){
	if(_RomIsLoad){//not first file(rom)
		if( ! _Reset ){  //clear if not from menu 'Reset'
			_Pause=FALSE;
			_Step=FALSE;
			StepCnt =0;
		}
		free(Chip8Emu.memory);
	}
	Chip8Emu.memory = (char*)malloc(sizeof(char)* MEMSIZE);
	if(Chip8Emu.memory==NULL){
		printf("Cannot allocate memory for Chip8Emu\n");
		getchar();
		exit(1);
	}
	
	//load file to memory
	if( ! _IsRamFile){
		InitChip8();
		fread(Chip8Emu.memory + OFFSET , 1, s.st_size, Chip8Emu.RomFile);
	}else{
		_IsRamFile=FALSE;
		InitChip8();
		fread(Chip8Emu.memory, 1, s.st_size, Chip8Emu.RomFile);
	}		
	_RomIsLoad=TRUE;
	fclose(Chip8Emu.RomFile);
	return 0;
}


//================MENU CALLBACKS======================
void UpdateDebugInfo(void  ){
	char Buf[1000];
	
	sprintf(Buf, "Step :%lu\n\n"
				 "Opcode : 0x%X\n\n"
				 "PC:\t0x%X\n"
				 "I:\t0x%X\n"
				 "SP:\t0x%X\n\n"
				 "ST:\t0x%X\n"
				 "DT:\t0x%X\n\n"
				 "[Registers]\n"
				 "V0:\t0x%X\n"
				 "V1:\t0x%X\n"
				 "V2:\t0x%X\n"
				 "V3:\t0x%X\n"
				 "V4:\t0x%X\n"
				 "V5:\t0x%X\n"
				 "V6:\t0x%X\n"
				 "V7:\t0x%X\n"
				 "V8:\t0x%X\n"
				 "V9:\t0x%X\n"
				 "VA:\t0x%X\n"
				 "VB:\t0x%X\n"
				 "VC:\t0x%X\n"
				 "VD:\t0x%X\n"
				 "VE:\t0x%X\n"
				 "VF:\t0x%X\n\n"
				 "[Stack]\n"
				 "S0:\t0x%X\n"
				 "S1:\t0x%X\n"
				 "S2:\t0x%X\n"
				 "S3:\t0x%X\n"
				 "S4:\t0x%X\n"
				 "S5:\t0x%X\n"
				 "S6:\t0x%X\n"
				 "S7:\t0x%X\n"
				 "S8:\t0x%X\n"
				 "S9:\t0x%X\n"
				 "SA:\t0x%X\n"
				 "SB:\t0x%X\n"
				 "SC:\t0x%X\n"
				 "SD:\t0x%X\n"
				 "SE:\t0x%X\n"
				 "SF:\t0x%X\n",   StepCnt,Chip8Emu.opcode, Chip8Emu.pc,  Chip8Emu.I, Chip8Emu.sp, Chip8Emu.sound_timer, Chip8Emu.delay_timer, Chip8Emu.V[0],
								  Chip8Emu.V[1],Chip8Emu.V[2],Chip8Emu.V[3],Chip8Emu.V[4],Chip8Emu.V[5],Chip8Emu.V[6],Chip8Emu.V[7],Chip8Emu.V[8],Chip8Emu.V[9],
								  Chip8Emu.V[10],Chip8Emu.V[11],Chip8Emu.V[12],Chip8Emu.V[13],Chip8Emu.V[14],Chip8Emu.V[15],Chip8Emu.stack[0],Chip8Emu.stack[1],Chip8Emu.stack[2],Chip8Emu.stack[3],Chip8Emu.stack[4],Chip8Emu.stack[5],
								  Chip8Emu.stack[6],Chip8Emu.stack[7],Chip8Emu.stack[8],Chip8Emu.stack[9],Chip8Emu.stack[10],Chip8Emu.stack[11],Chip8Emu.stack[12],Chip8Emu.stack[13],
								  Chip8Emu.stack[14],Chip8Emu.stack[15]);
	Fl_Text_BufferSetText(DebugBuf, Buf);
	 
}

void MenuDebugger(Fl_Widget *wg){
	_DebugShow =TRUE;
	DebugWin = Fl_Double_WindowNew(400,500, "Debugger");
	DebugBuf = Fl_Text_BufferNew(0,1024);
	DebugTextDisplay = Fl_Text_DisplayNew( 10,10, 380, 480, "");
	Fl_Text_DisplaySetBuffer(DebugTextDisplay, DebugBuf);
	Fl_GroupSetResizable(DebugWin, DebugWin);
	UpdateDebugInfo();
	Fl_WindowShow(DebugWin);	
}

void MenuPause(Fl_Widget *wg){
	if(_RomIsLoad){
			_Pause =  _Pause==FALSE ? TRUE: FALSE ; // change if 0=1   if 1=0
			_Step=FALSE;
			StepCnt =0;
	}
	printf("Pause: %d\n", _Pause);	 
}

void MenuStep(Fl_Widget *wg){
	if(_Pause){
		_Pause=FALSE;
		_Step=TRUE;
		StepCnt++;	
	}
	printf("Step: %d\n", _Step);
}

int MenuReset(Fl_Widget *wg){
	if(!_RomIsLoad)return;
	Chip8Emu.RomFile = fopen(Chip8Emu.RomName, "rb");
	if(Chip8Emu.RomFile ==NULL){
		fputs("File read error", stderr);
		return 0;
	}
	StepCnt =1;
	_Reset =TRUE;
	if(_Pause){
		_Pause=FALSE;
		_Step=TRUE;		
	}

	LoadFileToMemory();
	
}

int MenuResetRun(Fl_Widget *wg){
	if(!_RomIsLoad)return;
	Chip8Emu.RomFile = fopen(Chip8Emu.RomName, "rb");
	if(Chip8Emu.RomFile ==NULL){
		fputs("File read error", stderr);
		return 0;
	}
	if(_Pause){
		_Pause=FALSE;
		_Step=FALSE;		
	}
	LoadFileToMemory();
}

void MenuExitCB(Fl_Widget *wg){
	printf("Exit\n");
	exit(0);
}

 
int  MenuRamToFile(Fl_Widget *wg){
	if(_RomIsLoad==0){
		flMessageTitle("Attention");
		flMessage("Chip8 file not open yet");
		return 0;
	}
	//Fl_Native_File_Chooser *FChooser=NULL;
	
		 
	#define RF "ramfile.bin"
	//create file to save ram
	 
	FChooser = Fl_Native_File_ChooserNew(NFC_BROWSE_SAVE_FILE );
	Fl_Native_File_ChooserSetOptions(FChooser, NFC_SAVEAS_CONFIRM);
	Fl_Native_File_ChooserSetTitle(FChooser, "Save Chip8 Ram to file");
	Fl_Native_File_ChooserSetFilter(FChooser, "*.{bin}");
	Fl_Native_File_ChooserSetPresetFile(FChooser, RF);
	#undef RF
	
	if(Fl_Native_File_ChooserShow(FChooser)==NULL){//
		char *FN = (char*)Fl_Native_File_ChooserFilename(FChooser); //save file name
		FILE *CurRamFile;
		CurRamFile = fopen( FN, "wb");
		if(CurRamFile ==NULL){
			printf("Cannot save Ram to file: '%s'", FN);
			return 0;
		}
	
		//write Ram to file
		fwrite(Chip8Emu.memory, MEMSIZE, 1, CurRamFile);
		fclose(CurRamFile);
	}else{
		printf("No file selected!\n");
	}
 
	//Fl_Native_File_ChooserDelete(FChooser);
	return 0;
}


int MenuOpenFile(Fl_Widget *wg){
	
	char PathBuf[1000]={}; //clear
	 
	FChooser = Fl_Native_File_ChooserNew(NFC_BROWSE_FILE);
	Fl_Native_File_ChooserSetTitle(FChooser, "Load Chip8 rom file");
	Fl_Native_File_ChooserSetFilter(FChooser, "*.{c,c8}");
	Fl_Native_File_ChooserSetDirectory(FChooser, getcwd(PathBuf, 1000)); //current app path
	
	
	if(Fl_Native_File_ChooserShow(FChooser)==NULL){
		if( CheckChipFile(   Fl_Native_File_ChooserFilename(FChooser))){
			_Reset=FALSE;
			LoadFileToMemory();
			InitGlutEmulator();
		}
	}else{
		printf("No file selected!\n");
	}
	
	//Fl_Native_File_ChooserDelete(FChooser);
	return 0;	
}
 
 void MenuAbout(Fl_Widget *wg){
	 flMessageTitle("About");
	 flMessage("Chip8  Emulator.Version 0.1\n"
			   "fltk-c-1.3.3\n"
			   "Date:27.06.2020");
 }

void MenuLoadState(Fl_Widget *wg,int st){
	
	//Make states name
	char fname[40];
	sprintf(fname, "%s_%d", "States/State",st);
		
	FILE *stfile;
	if(  !(stfile = fopen( fname, "rb"))){
		flMessage("Cannot open state");
		return;
	}
	
	//read data state struct from file
	fread( &State, sizeof(State), 1, stfile);
	fclose(stfile);
	
	//copy data from state file to chip8 
	sprintf( Chip8Emu.RomName,"%s", State.RomName );
	Chip8Emu.RomFile = fopen(Chip8Emu.RomName, "rb");
	if(Chip8Emu.RomFile ==NULL){
		fputs("File read error", stderr);
		return ;
	}
	fstat(fileno(Chip8Emu.RomFile), &s);
	LoadFileToMemory();
	//Restore data from state file
	memcpy( Chip8Emu.gfx, State.gfx, 64*32);
	Chip8Emu.pc = State.pc;
	Chip8Emu.opcode = State.opcode;
	Chip8Emu.I = State.I;
	Chip8Emu.sp = State.sp;
	Chip8Emu.delay_timer = State.dt;
	Chip8Emu.sound_timer = State.st;
	//Chip8Emu.DrawFlag = State.DrawFlag;
	memcpy( Chip8Emu.V, State.V, 16);
	memcpy( Chip8Emu.stack, State.stack, 16);
	memcpy( Chip8Emu.key, State.key, 16);
	
	InitGlutEmulator();//start emulation
	 
	//DebugShowState();
}

//For MenuSaveState()
void ChangeMenuLabel(int st){
	//st  -state index in menu
	//get file name + file extansion
	char fName[100], fExt[10];
	_splitpath(State.RomName ,NULL,NULL, (char*)fName, (char*)fExt);
	//get current data
	char bufname[100], bufdate[100];
	time_t t =time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(bufdate, "%d-%02d-%02d %02d:%02d:%02d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	//create new menu item name
	sprintf(bufname, "%d %s%s_%s",   st, fName,  fExt, bufdate);
	
	free(MenuItemLabel[st]); //free previous alloc if any
	MenuItemLabel[st] = strdup(bufname); //alloc string

	//change menu item label
	//Mitem  Fl_Menu_Item ptr
	Fl_Menu_ItemSetLabel(Mitem + SaveState[st],  MenuItemLabel[st]) ;
	Fl_Menu_ItemSetLabel(Mitem + LoadState[st],  MenuItemLabel[st]) ;
}


void UpdateStateMenuFile(int st){
	//st  -state index in menu
	//save current data from file StateMenu.txt
	LoadStateMenuFile(&StateMenu);
	//clear old 'state name'
	memset((char*)StateMenu[st], 0, strlen( (char*)StateMenu[st]));
	//save new  'state name'
	sprintf( (char*)StateMenu[st], (char*)MenuItemLabel[st]);
	
	//save new version of StateMenu.txt file 
	FILE *sfile = fopen( SFILE, "w");
	if( sfile ==NULL){
		char mes[100];
		sprintf(mes, "Cannot write to state file '%s'" , SFILE);
		flMessageTitle("Attention");
		flMessage(mes);
		exit(1);
	}
	
	for(int i=0; i<5; i++){
		fprintf(sfile, "%s", StateMenu[i]);
		fputc('\n', sfile);
	}
	fclose(sfile);
}

//Update menu Save/Load state from file StateMenu.txt after program load
void UpdateStateMenu(const char *StateMenu[][100]){
	for(int i=0; i<5; i++){
		free(MenuItemLabel[i]); //free previous alloc if any
		MenuItemLabel[i] = strdup((char*)StateMenu[i]);
		Fl_Menu_ItemSetLabel(Mitem + SaveState[i],  MenuItemLabel[i]) ;
		Fl_Menu_ItemSetLabel(Mitem + LoadState[i],  MenuItemLabel[i]) ;
	}
		 
}

void MenuSaveState(Fl_Widget *wg, int st){

	if(!_RomIsLoad){
		flMessage("Chip8 file not open yet");
		return;
	}
	//Make states path/name
	char fname[40];
	sprintf(fname, "%s_%d", "States/State",st);
	
	FILE *stfile;
	if(  !(stfile = fopen( fname, "wb"))){
		flMessage("Cannot save state");
		return;
	}
	
	//save current rom data
	memcpy( State.gfx, Chip8Emu.gfx, 64*32); 
	State.pc = Chip8Emu.pc;
	State.opcode = Chip8Emu.opcode;
	State.I = Chip8Emu.I;
	State.sp = Chip8Emu.sp;
	memcpy( State.V, Chip8Emu.V, 16);
	memcpy( State.stack, Chip8Emu.stack, 16);
	memcpy( State.key, Chip8Emu.key, 16);
	State.dt = Chip8Emu.delay_timer;
	State.st = Chip8Emu.sound_timer;
	State.DrawFlag = Chip8Emu.DrawFlag;
	sprintf(State.RomName,"%s", Chip8Emu.RomName);
	
	fwrite( &State, sizeof(State), 1, stfile);
	fclose(stfile);
	
	
	ChangeMenuLabel(st);
	UpdateStateMenuFile(st);
	//printf("Save file: '%s'\n", fname);
}


//================= GLUT DRAW ==============================
// Setup Texture
void SetupTexture(void)
{
	// Clear screen
	for(int y = 0; y < SCREEN_HEIGHT; ++y)		
		for(int x = 0; x < SCREEN_WIDTH; ++x)
			screenData[y][x][0] = screenData[y][x][1] = screenData[y][x][2] = 0;

	// Create a texture 
	glTexImage2D(GL_TEXTURE_2D, 0, 3, SCREEN_WIDTH, SCREEN_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)screenData);

	// Set up the texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); 

	// Enable textures
	glEnable(GL_TEXTURE_2D);
}

void DrawGlPixel(long x, long y){
	glBegin(GL_QUADS);
		glVertex3f((x * modifier) + 0.0f,     (y * modifier) + 0.0f,	 0.0f);
		glVertex3f((x * modifier) + 0.0f,     (y * modifier) + modifier, 0.0f);
		glVertex3f((x * modifier) + modifier, (y * modifier) + modifier, 0.0f);
		glVertex3f((x * modifier) + modifier, (y * modifier) + 0.0f,	 0.0f);
	glEnd();
}

void UpdateScreen(){
		// Draw
	for(int y = 0; y < 32; ++y)		
		for(int x = 0; x < 64; ++x)
		{
			if( (_GFX[(y*64) + x]) == 0) 
				glColor3f(0.0f,0.0f,0.0f);			
			else 
				glColor3f(1.0f,1.0f,1.0f);

			DrawGlPixel(x, y);
		}
}

void UpdateTexture(void)
{	
	// Update pixels
	for(int y = 0; y < 32; ++y)		
		for(int x = 0; x < 64; ++x)
			if( _GFX[(y * 64) + x] == 0)
				screenData[y][x][0] = screenData[y][x][1] = screenData[y][x][2] = 0;	// Disabled
			else 
				screenData[y][x][0] = screenData[y][x][1] = screenData[y][x][2] = 255;  // Enabled
		
	// Update Texture
	glTexSubImage2D(GL_TEXTURE_2D, 0 ,0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid*)screenData);

	glBegin( GL_QUADS );
		glTexCoord2d(0.0, 0.0);		glVertex2d(0.0,			  0.0);
		glTexCoord2d(1.0, 0.0); 	glVertex2d(display_width, 0.0);
		glTexCoord2d(1.0, 1.0); 	glVertex2d(display_width, display_height);
		glTexCoord2d(0.0, 1.0); 	glVertex2d(0.0,			  display_height);
	glEnd();
	 
}

int  Display(void){
	sleep(3); //Main program delay
	
	if(_Pause)return; // Menu 'Pause'
	 //Menu 'Debugger'
	Chip8Emulate();
	CheckKeyPressed();	

	if(_DFLAG){
			glClear(GL_COLOR_BUFFER_BIT);
			 
			UpdateTexture();
			glFlush();
			GlutSwapBuffers();
			_DFLAG = FALSE;
		}
	if(_DebugShow)UpdateDebugInfo();
	if(_Step)_Pause=TRUE; // Menu 'Step'
}

void ReshapeWin(void){
	long w = Fl_WidgetGetW(MainWin);
	long h = Fl_WidgetGetH(MainWin) -SCROFFSET;
	glClearColor(0.0f, 0.0f, 0.5f, 0.0f);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);        
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, w, h);

	// Resize quad
	display_width = w;
	display_height = h;
}


//=======================================================
//=======================================================

//load "config.txt"
void LoadConfig(void){
	
	FILE *config = fopen(CONFIGFILE, "r");
	if(config ==NULL){
		char mes[100];
		sprintf(mes, "Cannot load config file '%s'" , CONFIGFILE);
		flMessageTitle("Attention");
		flMessage(mes);
		exit(1);
	}
	
	fscanf(config,
		"W= %d\n"
		"H= %d\n"
		"Title= %99[^\n]%*c" 
		"FLTKScheme= %99[^\n]%*c", &Config.WinW, &Config.WinH, &Config.WinTitle, &Config.FLTKScheme);
	fclose(config);
}

void DebugShowConfig(void){
	printf("WinW : '%d'\nWinH : '%d'\nWinTitle : '%s'\nFLTKScheme : '%s'\n", Config.WinW, Config.WinH, Config.WinTitle, Config.FLTKScheme);
	
}
void DebugShowStateMenuFile(char *sbuf[][100]){
	printf("State File:\n");
	for(int i=0; i<5; i++) printf("%s\n", &sbuf[i]);
			 	
}
void DebugShowState(void){
	char buf[1000];
	sprintf(buf, "pc: 0x%X\n"
				 "opcode: 0x%X\n"
				 "I: 0x%X\n"
				 "SP: 0x%X\n"
				 "ST:\t0x%X\n"
				 "DT:\t0x%X\n\n"
				 "[Registers]\n"
				 "V0:\t0x%X\n"
				 "V1:\t0x%X\n"
				 "V2:\t0x%X\n"
				 "V3:\t0x%X\n"
				 "V4:\t0x%X\n"
				 "V5:\t0x%X\n"
				 "V6:\t0x%X\n"
				 "V7:\t0x%X\n"
				 "V8:\t0x%X\n"
				 "V9:\t0x%X\n"
				 "VA:\t0x%X\n"
				 "VB:\t0x%X\n"
				 "VC:\t0x%X\n"
				 "VD:\t0x%X\n"
				 "VE:\t0x%X\n"
				 "VF:\t0x%X\n\n"
				 "[Stack]\n"
				 "S0:\t0x%X\n"
				 "S1:\t0x%X\n"
				 "S2:\t0x%X\n"
				 "S3:\t0x%X\n"
				 "S4:\t0x%X\n"
				 "S5:\t0x%X\n"
				 "S6:\t0x%X\n"
				 "S7:\t0x%X\n"
				 "S8:\t0x%X\n"
				 "S9:\t0x%X\n"
				 "SA:\t0x%X\n"
				 "SB:\t0x%X\n"
				 "SC:\t0x%X\n"
				 "SD:\t0x%X\n"
				 "SE:\t0x%X\n"
				 "SF:\t0x%X\n", State.pc, State.opcode, State.I, State.sp, State.st, State.dt, State.V[0],State.V[1],State.V[2],State.V[3],State.V[4],
							    State.V[5],State.V[6],State.V[7],State.V[8],State.V[9],State.V[10],State.V[11],State.V[12],State.V[13],State.V[14],State.V[15],
							    State.stack[0],State.stack[1],State.stack[2],State.stack[3],State.stack[4],State.stack[5],State.stack[6],State.stack[7],State.stack[8],State.stack[9],
							    State.stack[10],State.stack[11],State.stack[12],State.stack[13],State.stack[14],State.stack[15]);
				flMessageTitle("Debug State");
				flMessage(buf);
}
//load "StateMenu.txt"
void LoadStateMenuFile(char *sbuf[][100]){
	 
	FILE *sfile = fopen( SFILE, "r");
	if( sfile ==NULL){
		char mes[100];
		sprintf(mes, "Cannot load state file '%s'" , SFILE);
		flMessageTitle("Attention");
		flMessage(mes);
		exit(1);
	}
	 
	fscanf(sfile,
		"%99[^\n]%*c"
		"%99[^\n]%*c"
		"%99[^\n]%*c"
		"%99[^\n]%*c"
		"%99[^\n]%*c", &sbuf[0] , &sbuf[1], &sbuf[2], &sbuf[3], &sbuf[4]);
	fclose(sfile);
}



void SetupMenu(void){
	
	#define ST(n) (int*)n  //  state to load/save

	Fl_Menu_Add(MenuBar,"File/Open...",CTRL('o'), &MenuOpenFile, 0,0);
	
	LoadState[0] =Fl_Menu_Add(MenuBar, "File/Load state/0 -------", 0, &MenuLoadState, ST(0), 0);
	LoadState[1] =Fl_Menu_Add(MenuBar, "File/Load state/1 -------", 0, &MenuLoadState, ST(1),0);
	LoadState[2] =Fl_Menu_Add(MenuBar,"File/Load state/2 -------",  0, &MenuLoadState, ST(2),0);
	LoadState[3] =Fl_Menu_Add(MenuBar,"File/Load state/3 -------",  0, &MenuLoadState, ST(3),0);
	LoadState[4] =Fl_Menu_Add(MenuBar,"File/Load state/4 -------",  0, &MenuLoadState, ST(4),0);
	
	SaveState[0] =Fl_Menu_Add(MenuBar, "File/Save state/0 -------" , 0, &MenuSaveState, ST(0),0);
	SaveState[1] =Fl_Menu_Add(MenuBar, "File/Save state/1 -------" , 0, &MenuSaveState, ST(1),0);
	SaveState[2] =Fl_Menu_Add(MenuBar,"File/Save state/2 -------", 0, &MenuSaveState, ST(2),0);
	SaveState[3] =Fl_Menu_Add(MenuBar,"File/Save state/3 -------", 0, &MenuSaveState, ST(3),0);
	SaveState[4] =Fl_Menu_Add(MenuBar,"File/Save state/4 -------", 0, &MenuSaveState, ST(4),0);
	Fl_Menu_Add(MenuBar,"File/Load from file...", 0, NULL, 0,0);
	Fl_Menu_Add(MenuBar,"File/Save state as...", 0, NULL, 0,0);
	Fl_Menu_Add(MenuBar,"File/-------", 0, NULL, 0,0);
	Fl_Menu_Add(MenuBar,"File/Exit", 0, &MenuExitCB, 0,0);
	
	Fl_Menu_Add(MenuBar,"Run/Pause_Run", FKEY(5), &MenuPause, 0,0);
	Fl_Menu_Add(MenuBar,"Run/Reset", FKEY(6), &MenuReset, 0,0);
	Fl_Menu_Add(MenuBar,"Run/Reset+Run", FKEY(7), &MenuResetRun, 0,0);
	Fl_Menu_Add(MenuBar,"Run/Step", FKEY(8), &MenuStep, 0,0);
	
	
	Fl_Menu_Add(MenuBar,"Options/Pixel color", 0,NULL, 0,0);
	Fl_Menu_Add(MenuBar,"Options/Background color", 0,NULL, 0,0);	
	
	Fl_Menu_Add(MenuBar,"Tools/Debugger", CTRL('d'), &MenuDebugger, 0,0); 
	Fl_Menu_Add(MenuBar,"Tools/Ram view", CTRL('r'), NULL, 0,0);
	Fl_Menu_Add(MenuBar,"Tools/Ram to file", 0, &MenuRamToFile, 0,0); 
	
	Fl_Menu_Add(MenuBar,"Help/About", 0, &MenuAbout, 0,0);
	
	#undef ST(n)
}



//===========================================================
//======================== MAIN  ============================
int main(int argc, char * argv[]){
	LoadConfig( );
	Fl_SetScheme(Config.FLTKScheme);	
	
	//DebugShowConfig();
	
	MainWin =  Fl_Double_WindowNew( Config.WinW, Config.WinH, Config.WinTitle);
	MenuBar = Fl_Menu_BarNew(0,0,Config.WinW,MENUH,"");
	SetupMenu();
	
	Mitem = Fl_Menu_GetMenu(MenuBar);//get menu item pointer
	LoadStateMenuFile(&StateMenu);//from StateMenu.txt 
	UpdateStateMenu(&StateMenu); // if any in StateMenu.txt file
	DebugShowStateMenuFile(&StateMenu);
	
	//Fl_Glut_  after Fl_Double_Window New()   else error;	
	GlutWin = Fl_Glut_WindowNew2(0,SCROFFSET,Fl_WidgetGetW(MainWin), Fl_WidgetGetH(MainWin) - SCROFFSET,"");  
		
	Fl_WindowShow(MainWin);
	Fl_Run();
	free(Chip8Emu.memory); // comment? 
	return 0;
}
