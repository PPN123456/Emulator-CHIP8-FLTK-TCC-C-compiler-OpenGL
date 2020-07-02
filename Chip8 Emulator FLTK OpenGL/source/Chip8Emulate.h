

void DrawPixels(void);


#define _PC Chip8Emu.pc
#define _OPCODE Chip8Emu.opcode
#define _MEM Chip8Emu.memory
#define _GFX Chip8Emu.gfx
#define _DFLAG Chip8Emu.DrawFlag
#define _SP Chip8Emu.sp
#define _STACK Chip8Emu.stack
#define _V Chip8Emu.V
#define _I Chip8Emu.I
#define _KEY Chip8Emu.key
#define _DT Chip8Emu.delay_timer
#define _ST Chip8Emu.sound_timer

#define NNNN (_MEM[ _PC] << 8 | _MEM[_PC+1])
#define xNNN (_OPCODE & 0x0FFF)
#define xxNN (_OPCODE & 0x00FF)
#define Nxxx (_OPCODE & 0xF000)
#define xNxx (_OPCODE & 0x0F00)  
#define xxNx (_OPCODE & 0x00F0)
#define xxxN (_OPCODE & 0x000F)

//e.g 0x5XY0 
#define VX  _V[ (xNxx) >> 8]
#define VY  _V[ (xxNx) >> 4]
#define VF  _V[0xF]
#define V0  _V[0]

#define RANDFF (rand() % 0xFF)

char mesbuf[200];
long ccnum=0;

//for opcode 0xD000 
unsigned short dX=0,dY=0;
unsigned short dH=0; //Height
unsigned short dPixel=0;
int yline=0, xline=0;
//============

void Out(const char *mes  ){
	printf("%s", mes);
}


 
int Chip8Emulate(){ 
	
		_OPCODE = NNNN;
		
		switch(Nxxx){
			//==================
			case 0x0000:
				switch( xxxN){
						case 0x0000: //Clear the screen
							memset( _GFX, 0, 64*32);
							//for(int i=0; i<2048; ++i) _GFX[i]=0x0;
							_DFLAG = TRUE;
							_PC +=2;
							break;
						case 0x000E: // 0x00EE returns from subroutine
							--_SP;
							_PC = _STACK[_SP];
							_PC +=2;
							break;
							
						default:
						sprintf(mesbuf, "Unknown opcode [0x0000]: 0x%X", _OPCODE);
						Out(mesbuf);
				}break;
			//==================
			case 0x1000: //0x1NNN jumps to address NNN
				_PC = xNNN;
			break;
			//==================
			case 0x2000: //0x2NNN Call subroutine at NNN
				_STACK[_SP] = _PC;
				++_SP;
				_PC =  xNNN;
			break;
			//==================
			case 0x3000: //0x3XNN skips the next instruction if VX equals NN
				if(  VX  ==  (xxNN))
					_PC +=4;
				else
					_PC +=2;
			break;
			//==================
			case 0x4000: //0x4XNN skips the next instruction if VX doesn't equal NN
				if( (VX) != (xxNN))
					_PC +=4;
				else
					_PC +=2;
			break;
			//=================
			case 0x5000: //0x5XY  skips the next instruction if VX equal VY
				if( VX == VY )
					_PC +=4;
				else
					_PC +=2;
			break;
			//=================
			case 0x6000: //0x6XNN sets VX to NN
				VX = xxNN;
				_PC +=2;
			break;
			//=================
			case 0x7000: //0x7XNN add NN to VX
				VX += xxNN;
				_PC +=2;
			break;
			//=================
			case 0x8000:
				switch(xxxN){
					case 0x0000: //0x8XY0 sets VX to the value of VY
						VX = VY;
						_PC +=2;
					break;
					
					case 0x0001: //0x8XY1 sets VX to "VX OR VY"
						VX |= VY;
						_PC +=2;
					break;
					
					case 0x0002: //0x8XY2 set VX to "VX AND VY"
						VX &= VY;
						_PC +=2;
					break;
					
					case 0x0003: //0x8XY3 set VX to "VX XOR VY"
						VX ^= VY;
						_PC +=2;
					break;
					
					case 0x0004: //0x8XY4 add VY to VX.  VF is set to 1 when there's carry and to 0 when there isn't
						if( VY  > (0xFF - VX))
							VF =1; //carry
						else 
							VF =0;
						VX += VY;
						_PC +=2;
					break;
					
					case 0x0005: //0x8XY5 VY is subrracted from VX. VF is set to 0 when there's a borrow and 1 when ther isn't
						if( VY > VX)
							VF =0;
						else 
							VF =1;
						VX -= VY;
						_PC +=2;
					break;
					
					case 0x0006: //0x8XY6 shift VX right by one VF is set to value of the least significant bit of VX before the shift
						VF = VX & 0x1;
						VX >>=1;
						_PC +=2;
					break;
					
					case 0x0007: //0x8XY7 sets VX to VY minus VX . VF to 0 it borrow , no set to 1
						if( VX > VY )
							VF =0; //there is a borrow
						else
							VF =1;
						VX = VY - VX;
						_PC +=2;
					break;
							
					case 0x000E: //0x8XY shifts VX left by one VF = value of most significant bit of VX before the shift
						VF = VX >> 7;
						VX <<=1;
						_PC +=2;
						
					break;
					
					default:
						sprintf(mesbuf, "Unknown opcode [0x8000]: 0x%X\n", _OPCODE);
				}
				break;
				
			//=================
			case 0x9000: //0x9XY0 skip the next instruction if VX doesn't equal VY
				if( VX != VY )
					_PC +=4;
				else
					_PC +=2;
			break;
			//=================
			case 0xA000: //ANNN: sets I to the address NNN
				_I = xNNN;
				_PC +=2;
			break;
			//=================
			case 0xB000: //BNNN jump to the address NNN plus V0
				_PC = xNNN + V0;
			break;
			//=================
			case 0xC000: //CXNN sets VX to a random number and NN
				VX = RANDFF & xxNN;
				_PC +=2;
			break;
			//=================
			case 0xD000: // DXYN draw a sprite at coordinate (VX, VY)  width 8 pixels , N height of pixels
						 //Each row  of 8 pixels is read as bit-codded starting from memory location I
						 //I value doesn't change after the execution of this instruction
						 //VF is set to 1 if any screen pixels are flipped from set to unset when the sprite is drawn
						 // and to 0 if that doesn't happen
			{
				dX = VX;
				dY = VY;
				dH = xxxN;
				
				VF =0;
				dPixel=0;
				for(yline=0; yline < dH; yline++){
					dPixel = _MEM[ _I + yline];
					for( xline =0; xline <8; xline++){
						if( (dPixel & (0x80 >> xline)) !=0){
							if( _GFX[(dX + xline + (( dY + yline) *64)) ] ==1){
								VF =1;
							}
							_GFX[ dX + xline + ((dY + yline) *64)] ^=1;
						}
					}
				}
			_DFLAG = TRUE;
			_PC +=2;
			}
			break;
			//==================
			case 0xE000:
				switch( xxNN){
					case 0x009E: //EX9E skips the next instruction if the key stored in VX is pressed
						if( _KEY[ VX ] !=0)
							_PC +=4;
						else
							_PC +=2;
					break;
					
					case 0x00A1: //EXA1 skipt the next instruction if the key stored in VX isn't pressed
						if( _KEY[ VX ] ==0)
							_PC +=4;
						else
							_PC +=2;
					break;
					
					default:
						sprintf(mesbuf, "Unknown opcode [0xE000]: 0x%X\n", _OPCODE);
						Out(mesbuf);
				}
			break;
			//=====================
			case 0xF000:
				switch(xxNN){
					case 0x0007: //FX07 sets VX to the value of delay timer
						VX = _DT;
						_PC +=2;
					break;
					
					case 0x000A: //FX0A A key press is awaited and then stored in VX
					{	
						char KeyPress=0;
						for(int i=0; i<16; ++i){
							if( _KEY[i] !=0){
								VX =i;
								KeyPress=1;
							}
						}
						//if we didn't received a keypress skip this cycle and tyr again
						if(!KeyPress)return;
						_PC +=2;			
					}
					break;
					
					case 0x0015: //FX15 sets the delay timer to VX
						_DT = VX;
						_PC +=2;
					break;
					
					case 0x0018: //FX18 sets the sound timer to VX
						_ST = VX;
						_PC +=2;
					break;
					
					case 0x001E: //FX1E add VX to I
						if( _I + VX > 0xFFF) //VF is set to 1 when range overflow and 0 when there isn't
							VF =1;
						else
							VF =0;
						_I += VX;
						_PC +=2;
					break;
					
					case 0x0029: // FX29 sets I to the location of the sprite for character in VX. Characters 0-F(in Hexadecimal) are represented by a 4x5 font
						_I = VX * 0x5;
						_PC +=2;
					break;
					
					case 0x0033: //FX33 stores the binary-coded decimal representation of VX at the addresses I, I+1, I+2
						_MEM[ _I ] = VX /100;
						_MEM[ _I +1] = (VX /10)  %10;
						_MEM[ _I +2] = (VX %100) %10;
						_PC +=2;
					break;
					
					case 0x0055: //FX55 stores V0 to VX in memory starting at address I
						for( int i=0; i<=  xNxx >> 8 ; ++i)
							_MEM[ _I +i] = _V[i];
						
						
						//on the original interpreter, when the operation is done , I= I+X+1
						_I +=  xNxx >>8   +1;
						_PC +=2;
					break;
					
					case 0x0065: //FX65 fills V0 to VX with values from memory starting at address I
						for(int i=0; i<= xNxx >> 8; ++i)  
							_V[i] = _MEM[ _I + i];
						
						//(( _OPCODE & 0x0F00)>>8)
						//on the original interpreter, when the operation is done, I=I+X+1
						_I += xNxx >> 8 +1;
						_PC +=2;
					break;
					
					default:
						sprintf(mesbuf, "Unknown opcode [0xF000]: 0x%X\n", _OPCODE);
						Out(mesbuf);
				}
			break;
			
			default:
				sprintf(mesbuf, "Unknown opcode: 0x%X\n", _OPCODE);
				Out(mesbuf);
		}
		
		
		//updates timers
		if( _DT >0) --_DT;
		if( _ST >0){
			if( _ST==1) printf("BEEP\n");
				--_ST;
		}
	return 0;
}



