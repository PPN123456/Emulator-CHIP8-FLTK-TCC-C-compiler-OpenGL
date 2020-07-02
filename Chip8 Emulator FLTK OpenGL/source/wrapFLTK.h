#include <stdlib.h>



//-------TYPES--------------- 
typedef unsigned long int Fl_Window;
typedef unsigned long int Fl_Spinner;
typedef unsigned long int Fl_Box;
typedef unsigned long int Fl_Input;
typedef unsigned long int Fl_Button;
typedef unsigned long int Fl_Widget;
typedef unsigned long int Fl_Check_Button;
typedef unsigned long int Fl_Browser;
typedef unsigned long int Fl_Menu_Bar;
typedef unsigned long int Fl_Menu_Button;
typedef unsigned long int Fl_Menu;
typedef unsigned long int Fl_Tabs;
typedef unsigned long int Fl_Group;
typedef unsigned long int Fl_Double_Window;
typedef unsigned long int Fl_Native_File_Chooser;
typedef unsigned long int Fl_Event;
typedef unsigned long int Fl_Canvas;
typedef unsigned long int Fl_Glut_Window;
typedef unsigned long int Fl_Glut_WindowEx;
typedef unsigned long int Fl_Gl_WindowEx;
typedef unsigned long int Fl_Gl_Window;
typedef unsigned long int Fl_TableEx;
typedef unsigned long int Fl_Table;
typedef unsigned long int Fl_Text_Buffer;
typedef unsigned long int Fl_Text_Display;


typedef unsigned long int Fl_Color;
	//' The Fl_Color type holds an FLTK color value.
	//' Colors are either 8-bit indexes into a virtual colormap or 24-bit RGB color values.
	//' Color indices occupy the lower 8 bits of the value, 
	//' while RGB colors occupy the upper 24 bits. (RGBI)
	//' Fl_Color => &Hrrggbbii
	//'                | | | |
	//'                | | | +--- index between 0 and 255
	//'                | | +----- blue color component (8 bit)
	//'                | +------- green component (8 bit)
	//'                +--------- red component (8 bit)
	//' A color can have either an index or an rgb value.
	//' Colors with rgb set and an index >0 are reserved for special use.

	//'  Standard colors. These are used as default colors in widgets and altered as necessary
	const Fl_Color Fl_FOREGROUND_COLOR  =  0;  // the default foreground color (0) used for labels and text
	const Fl_Color Fl_BACKGROUND2_COLOR =  7; // the default background color for text, list, and valuator widgets
	const Fl_Color Fl_INACTIVE_COLOR    =  8; // the inactive foreground color
	const Fl_Color Fl_SELECTION_COLOR   = 15; // the default selection/highlight color

	#define Fl_FREE_COLOR     16
	#define Fl_NUM_FREE_COLOR 16

	//  boxtypes generally limit themselves to these colors so the whole ramp is not allocated:
	#define Fl_GRAY_RAMP                      32
	#define Fl_NUM_GRAY                       24
	const Fl_Color Fl_GRAY0             =  32 ;//  'A'
	const Fl_Color Fl_DARK3             =  39; //  'H'
	const Fl_Color Fl_DARK2             =  45; //  'N'
	const Fl_Color Fl_DARK1             =  47; //  'P'
	const Fl_Color Fl_BACKGROUND_COLOR  =  49; //  'R' default background color
	#define FL_GRAY FL_BACKGROUND_COLOR
	const Fl_Color Fl_LIGHT1            =  50; //  'S'
	const Fl_Color Fl_LIGHT2            =  52; //  'U'
	const Fl_Color Fl_LIGHT3            =  54; //  'W'

	// FLTK provides a 5x8x5 RGB color cube that is used with colormap visuals
	#define Fl_NUM_RED   5
	#define Fl_NUM_GREEN 8
	#define Fl_NUM_BLUE  5
	#define Fl_COLOR_CUBE_    56
	const Fl_Color Fl_BLACK             =  56; // Fl_COLOR_CUBE_ + r000 + g000 + b000 
	const Fl_Color Fl_DARK_GREEN        =  60; // Fl_COLOR_CUBE_ +        g004
	const Fl_Color Fl_GREEN             =  63; //Fl_COLOR_CUBE_ +        g007
	const Fl_Color Fl_DARK_RED          =  72; // Fl_COLOR_CUBE_ + r016
	const Fl_Color Fl_DARK_YELLOW       =  76;
	const Fl_Color Fl_RED               =  88; // Fl_COLOR_CUBE_ + r032
	const Fl_Color Fl_YELLOW            =  95;  
	const Fl_Color Fl_DARK_BLUE         = 136; // Fl_COLOR_CUBE_ +        r080
	const Fl_Color Fl_DARK_MAGENTA      = 152;
	const Fl_Color Fl_DARK_CYAN         = 140;
	const Fl_Color Fl_BLUE              = 216; // Fl_COLOR_CUBE_ +        b160
	const Fl_Color Fl_MAGENTA           = 248;
	const Fl_Color Fl_CYAN              = 223;
	const Fl_Color Fl_WHITE             = 255; 

	const Fl_Color FL_ICON_COLOR        = 0xffffffff;// icon color

typedef unsigned long int Fl_Event;

typedef unsigned long int Fl_Font;
	const Fl_Font Fl_HELVETICA              = 0 ;// Helvetica (or Arial) normal (0)
	const Fl_Font Fl_BOLD                   = 1 ;// bold
	const Fl_Font Fl_ITALIC                 = 2 ;// oblique
    const Fl_Font Fl_BOLD_ITALIC            = 3 ;// bold-oblique
	const Fl_Font Fl_HELVETICA_BOLD         = 0 | 1;
	const Fl_Font Fl_HELVETICA_ITALIC       = 0 | 2;
	const Fl_Font Fl_HELVETICA_BOLD_ITALIC  = 0 | 3;
	const Fl_Font Fl_COURIER                = 4 ;//Courier normal
	const Fl_Font Fl_COURIER_BOLD           = 4 | 1;
	const Fl_Font Fl_COURIER_ITALIC         = 4 | 2;   
	const Fl_Font Fl_COURIER_BOLD_ITALIC    = 4 | 3;
	const Fl_Font Fl_TIMES                  = 8 ;// Times roman
	const Fl_Font Fl_TIMES_BOLD             = 8 | 1;
	const Fl_Font Fl_TIMES_ITALIC           = 8 | 2;
	const Fl_Font Fl_TIMES_BOLD_ITALIC      = 8 | 3;
	const Fl_Font Fl_SYMBOL                 = 12 ;// Standard symbol font
	const Fl_Font Fl_SCREEN                 = 13 ;// Default monospaced screen font
	const Fl_Font Fl_SCREEN_BOLD            = 13 | 1;// Default monospaced bold screen font
	const Fl_Font Fl_ZAPF_DINGBATS          = 15 ;// Zapf-dingbats font
	const Fl_Font Fl_FREE_FONT              = 16 ;// first one to allocate
typedef unsigned long int Fl_FontSize;
	const Fl_FontSize FL_NORMAL_SIZE =14;
	
typedef unsigned long int Fl_Input_Type; // Fl_Input_SetInputType/Fl_Input_GetInputType
	const Fl_Input_Type FL_INPUT_NORMAL                = 0;
	const Fl_Input_Type FL_INPUT_FLOAT                 = 1;
	const Fl_Input_Type FL_INPUT_INT                   = 2;
	const Fl_Input_Type FL_INPUT_MULTILINE             = 4;
	const Fl_Input_Type FL_INPUT_SECRET                = 5;
	const Fl_Input_Type FL_INPUT_TYPE_                 = 7;
	const Fl_Input_Type FL_INPUT_READONLY              = 8;
	const Fl_Input_Type FL_INPUT_NORMAL_OUTPUT         = 0 | 8;
	const Fl_Input_Type FL_INPUT_MULTILINE_OUTPUT      = 4 | 8;
	const Fl_Input_Type FL_INPUT_WRAP                  = 16;
	const Fl_Input_Type FL_INPUT_MULTILINE_WRAP        = 4 | 16;
	const Fl_Input_Type FL_INPUT_MULTILINE_OUTPUT_WRAP = 4 | 8 | 16;

typedef  unsigned long int Fl_MenuButton_Popup_Type; //Values for Fl_WidgetSetType() used to indicate what mouse buttons pop up the menu.
	const Fl_MenuButton_Popup_Type POPUP1          = 1;// pops up with the mouse 1st button. 
	const Fl_MenuButton_Popup_Type POPUP2          = 2;// pops up with the mouse 2nd button. 
	const Fl_MenuButton_Popup_Type POPUP12         = 3;// pops up with the mouse 1st or 2nd buttons. 
	const Fl_MenuButton_Popup_Type POPUP3          = 4;// pops up with the mouse 3rd button. 
	const Fl_MenuButton_Popup_Type POPUP13         = 5;// pops up with the mouse 1st or 3rd buttons. 
	const Fl_MenuButton_Popup_Type POPUP23         = 6;// pops up with the mouse 2nd or 3rd buttons. 
	const Fl_MenuButton_Popup_Type POPUP123        = 7;// pops up with any mouse button. 	

typedef unsigned long int Fl_MenuItem_Flag;
	const Fl_MenuItem_Flag FL_MENU_INACTIVE        = 0x001 ;// Deactivate menu item (gray out)
	const Fl_MenuItem_Flag FL_MENU_TOGGLE          = 0x002 ;// Item is a checkbox toggle (shows checkbox for on/off state)
	const Fl_MenuItem_Flag FL_MENU_VALUE           = 0x004 ;// The on/off state for checkbox/radio buttons (if set, state is 'on')
	const Fl_MenuItem_Flag FL_MENU_RADIO           = 0x008 ;// Item is a radio button (one checkbox of many can be on)
	const Fl_MenuItem_Flag FL_MENU_INVISIBLE       = 0x010 ;// Item will not show up (shortcut will work)
	const Fl_MenuItem_Flag FL_SUBMENU_POINTER      = 0x020 ;// Indicates user_data() is a pointer to another menu array
	const Fl_MenuItem_Flag FL_SUBMENU              = 0x040 ;// This item is a submenu to other items
	const Fl_MenuItem_Flag FL_MENU_DIVIDER         = 0x080 ;// Creates divider line below this item. Also ends a group of radio buttons.
	const Fl_MenuItem_Flag FL_MENU_HORIZONTAL      = 0x100 ;// reserved


typedef unsigned long FL_NFC_OPTION;  //NFC = native file chooser 
	const   FL_NFC_OPTION NFC_NO_OPTIONS             = 0;
	const   FL_NFC_OPTION NFC_SAVEAS_CONFIRM         = 1;
	const   FL_NFC_OPTION NFC_NEW_FOLDER             = 2;
	const   FL_NFC_OPTION NFC_PREVIEW                = 4;
	const   FL_NFC_OPTION NFC_USE_FILTER_EXT         = 8;
 
typedef unsigned long  FL_NFC_TYPE;
	const  FL_NFC_TYPE NFC_BROWSE_FILE              = 0;
	const  FL_NFC_TYPE NFC_BROWSE_DIRECTORY         = 1;
	const  FL_NFC_TYPE NFC_BROWSE_MULTI_FILE        = 2;
	const  FL_NFC_TYPE NFC_BROWSE_MULTI_DIRECTORY   = 3;
	const  FL_NFC_TYPE NFC_BROWSE_SAVE_FILE         = 4;
	const  FL_NFC_TYPE NFC_BROWSE_SAVE_DIRECTORY    = 5;

const enum Fl_Event{
	FL_EVENT_PUSH                         =  1,
	FL_EVENT_RELEASE                      =  2,
	FL_EVENT_ENTER                        =  3,
	FL_EVENT_LEAVE                        =  4,
	FL_EVENT_DRAG                         =  5,
	FL_EVENT_FOCUS                        =  6,
	FL_EVENT_UNFOCUS                      =  7,
	FL_EVENT_KEYBOARD                     =  8,
	FL_EVENT_KEYDOWN                      =  8,
	FL_EVENT_KEYUP                        =  9,
	FL_EVENT_CLOSE                        = 10,
	FL_EVENT_MOVE                         = 11,
	FL_EVENT_SHORTCUT                     = 12,
	FL_EVENT_DEACTIVATE                   = 13,
	FL_EVENT_ACTIVATE                     = 14,

	FL_EVENT_HIDE                         = 15,
	FL_EVENT_SHOW                         = 16,

	FL_EVENT_PASTE                        = 17,

	FL_EVENT_SELECTIONCLEAR               = 18,

	FL_EVENT_MOUSEWHEEL                   = 19,

	FL_EVENT_DND_ENTER                    = 20,
	FL_EVENT_DND_DRAG                     = 21,
	FL_EVENT_DND_LEAVE                    = 22,
	FL_EVENT_DND_RELEASE                  = 23,

	FL_EVENT_SCREEN_CONFIGURATION_CHANGED = 24,
	FL_EVENT_FULLSCREEN                   = 25

};

typedef unsigned char Fl_Beep;
	const Fl_Beep FL_BEEP_DEFAULT        = 0;//' Default beep.
	const Fl_Beep	FL_BEEP_MESSAGE      = 1;//' Message beep.
	const Fl_Beep	FL_BEEP_ERROR        = 2;//' Error beep.
	const Fl_Beep	FL_BEEP_QUESTION     = 3;//' Question beep.
	const Fl_Beep	FL_BEEP_PASSWORD     = 4;//' Password beep.
	const Fl_Beep	FL_BEEP_NOTIFICATION = 5; //' Notification beep

typedef unsigned long  FL_Event_States;
//'  FIXME: it would be nice to have the modifiers in the upper 8 bit so that
//'         a unicode ke (24bit) can be sent as an unsigned with the modifiers.
	const  FL_Event_States FL_SHIFT                 = 0x00010000;// ' One of the shift keys is down
	const  FL_Event_States FL_CAPS_LOCK             = 0x00020000;// ' The caps lock is on
	const  FL_Event_States FL_CTRL                  = 0x00040000;// ' One of the ctrl keys is down
	const  FL_Event_States FL_ALT                   = 0x00080000;// ' One of the alt keys is down
	const  FL_Event_States FL_NUM_LOCK              = 0x00100000;// ' The num lock is on
	const  FL_Event_States FL_META                  = 0x00400000;// ' One of the meta/Windows keys is down
	const  FL_Event_States FL_SCROLL_LOCK           = 0x00800000;// ' The scroll lock is on
	const  FL_Event_States FL_BUTTON1               = 0x01000000;// ' Mouse button 1 is pushed
	const  FL_Event_States FL_BUTTON2               = 0x02000000;// ' Mouse button 2 is pushed
	const  FL_Event_States FL_BUTTON3               = 0x04000000;// ' Mouse button 3 is pushed
	const  FL_Event_States FL_BUTTONS               = 0x7f000000;// ' Any mouse button is pushed

	const  FL_Event_States FL_KEY_MASK              = 0x0000ffff;// ' All keys are 16 bit for now  FIXME: Unicode needs 24 bits!

	#define Fl_COMMAND Fl_CTRL // ' An alias for Fl_CTRL on WIN32 and X11, or Fl_META on MacOS X
	#define Fl_CONTROL Fl_META //' An alias for Fl_META on WIN32 and X11, or Fl_CTRL on MacOS X
	#define Fl_MOUSEBUTTON(n) (0x00800000 >> (n))  //' Mouse button n (n > 0) is pushed
 
 
typedef unsigned long FL_Keyboard_Events;
	const  FL_Keyboard_Events FL_Volume_Down  =0xEF11; //' Volume control down 
	const  FL_Keyboard_Events FL_Volume_Mute  =0xEF12; //' Mute sound from the system 
	const  FL_Keyboard_Events FL_Volume_Up    =0xEF13; //' Volume control up 
	const  FL_Keyboard_Events FL_Media_Play   =0xEF14; //' Start playing of audio 
	const  FL_Keyboard_Events FL_Media_Stop   =0xEF15; //' Stop playing audio 
	const  FL_Keyboard_Events FL_Media_Prev   =0xEF16; //' Previous track 
	const  FL_Keyboard_Events FL_Media_Next   =0xEF17; //' Next track 
	const  FL_Keyboard_Events FL_Home_Page    =0xEF18; //' Display user's home page 
	const  FL_Keyboard_Events FL_Mail         =0xEF19; //' Invoke user's mail program 
	const  FL_Keyboard_Events FL_Search       =0xEF1B; //' Search 
	const  FL_Keyboard_Events FL_Back         =0xEF26; //' Like back on a browser 
	const  FL_Keyboard_Events FL_Forward      =0xEF27; //' Like forward on a browser 
	const  FL_Keyboard_Events FL_Stop         =0xEF28; //' Stop current operation 
	const  FL_Keyboard_Events FL_Refresh      =0xEF29; //' Refresh the page 
	const  FL_Keyboard_Events FL_Sleep        =0xEF2F; //' Put system to sleep 
	const  FL_Keyboard_Events FL_Favorites    =0xEF30; //' Show favorite locations 
	
//'  FIXME: These codes collide with valid Unicode keys
	const  FL_Keyboard_Events FL_Mouse_Button =0xfee8; //' A mouse button; use FL_Button + n for mouse button n.
	const  FL_Keyboard_Events FL_BackSpace    =0xff08; //' The backspace key.
	const  FL_Keyboard_Events FL_Tab_KEY      =0xff09; //' The tab key. ( !!! FL_TAB is a widget)
                                                  
	const  FL_Keyboard_Events FL_Iso_Key      =0xff0c; //' The additional key of ISO keyboards.
	const  FL_Keyboard_Events FL_Enter_Key    =0xff0d; //' The enter key. 
                                                    
	const  FL_Keyboard_Events FL_Pause        =0xff13; //' The pause key.
	const  FL_Keyboard_Events FL_ScrollLock   =0xff14; //' The scroll lock key.
                                                     
	const  FL_Keyboard_Events FL_Escape       =0xff1b; //' The escape key.
	                                                 
	const  FL_Keyboard_Events FL_Home         =0xff50; //' The home key.
	const  FL_Keyboard_Events FL_Left         =0xff51; //' The left arrow key.
	const  FL_Keyboard_Events FL_Up           =0xff52; //' The up arrow key.
	const  FL_Keyboard_Events FL_Right        =0xff53; //' The right arrow key.
	const  FL_Keyboard_Events FL_Down         =0xff54; // ' The down arrow key.
	const  FL_Keyboard_Events FL_Page_Up      =0xff55; // ' The page-up key.
	const  FL_Keyboard_Events FL_Page_Down    =0xff56; // ' The page-down key.
	const  FL_Keyboard_Events FL_End          =0xff57; // ' The end key.
                                                     
	const  FL_Keyboard_Events FL_Print        =0xff61; // ' The print (or print-screen) key.
                                                     
	const  FL_Keyboard_Events FL_Insert       =0xff63; // ' The insert key. 
                                                  
	const  FL_Keyboard_Events FL_Menu         =0xff67; // ' The menu key.
	const  FL_Keyboard_Events FL_Help         =0xff68; // ' The 'help' key on Mac keyboards
                                                     
	const  FL_Keyboard_Events FL_NumLock      =0xff7f; //' The num lock key.
	const  FL_Keyboard_Events FL_KP           =0xff80; //' One of the keypad numbers; use FL_KP + n for number n.
												     
	const  FL_Keyboard_Events FL_KP_Enter     =0xff8d; //' The enter key on the keypad, same as FL_KP+'\\r'.
                                              
	const  FL_Keyboard_Events FL_KP_Last      =0xffbd;//' The last keypad key; use to range-check keypad.
                                                  
	const  FL_Keyboard_Events FL_F            =0xffbd;//' One of the function keys; use FL_F + n for function key n.
	const  FL_Keyboard_Events FL_F_Last       =0xffe0;//' The last function key; use to range-check function keys.
                                               
	const  FL_Keyboard_Events FL_Shift_L      =0xffe1;//' The lefthand shift key.
	const  FL_Keyboard_Events FL_Shift_R      =0xffe2;//' The righthand shift key.
	const  FL_Keyboard_Events FL_Control_L    =0xffe3;//' The lefthand control key.
	const  FL_Keyboard_Events FL_Control_R    =0xffe4;//' The righthand control key.
	const  FL_Keyboard_Events FL_CapsLock     =0xffe5;//' The caps lock key.
                                                     
	const  FL_Keyboard_Events FL_Meta_L       =0xffe7;//' The left meta/Windows key.
	const  FL_Keyboard_Events FL_Meta_R       =0xffe8;//' The right meta/Windows key.
	const  FL_Keyboard_Events FL_Alt_L        =0xffe9;//' The left alt key.
	const  FL_Keyboard_Events FL_Alt_R        =0xffea;//' The right alt key. 
	const  FL_Keyboard_Events FL_Delete       =0xffff;//' The delete key.
	
	
	
typedef void(*Fl_DrawcellEx)(void);
typedef void (*Fl_Callback)(Fl_Widget *wgt, void *data);
	//type Fl_Callback0        as sub      (byval widget as Fl_Widget ptr)
typedef void (*Fl_Callback0)(Fl_Widget *wgt);
	//type Fl_Timeout_Handler  as sub      (byval userdata as any ptr)
typedef void (*Fl_Timeout_Handler)(void *userdata);
	//' callback for the Fl_Canvas only
	//type Fl_CanvasDraw as sub (byval self as any ptr, byref dstX as long, byref dstY as long,  byref cpyW as long, byref cpyH as long, byref srcX as long, byref srcY as long)
typedef void (*Fl_CanvasDraw)(void *self, long dstX, long dstY, long cpyW, long cpyH, long srcX, long srcY);
	//' callback's for all extended FLTK classes
	//type Fl_DrawEx as function (byval self as any ptr) as long
typedef long Fl_DrawEx( void *self);


typedef struct {
	const char *text; //menu item text , returned by label()
	long shortcut_ ; //menu item shortcut;
	Fl_Callback cb_ ; //menu item callback
	void *userdata; //menu item user data for the menu's callback
	long flags; //menu item flags like FL_MENU_TOOGLE, FL_MENU_RADIO
	unsigned char labeltype_; //how the menu item text looks like( see FL_LABEL_TYPE)
	Fl_Font labelfont_; //which font for this menu item text 
	Fl_FontSize labelsize_; //size of menu item text
	Fl_Color labelcolor_; //menu item text color
}Fl_Menu_Item;

#define GLUT_RGB         FL_MODE_RGB
#define GLUT_RGBA        FL_MODE_RGB
#define GLUT_INDEX       FL_MODE_INDEX
#define GLUT_SINGLE      FL_MODE_SINGLE
#define GLUT_DOUBLE      FL_MODE_DOUBLE
#define GLUT_ACCUM       FL_MODE_ACCUM
#define GLUT_ALPHA       FL_MODE_ALPHA
#define GLUT_DEPTH       FL_MODE_DEPTH
#define GLUT_STENCIL     FL_MODE_STENCIL
#define GLUT_MULTISAMPLE FL_MODE_MULTISAMPLE
#define GLUT_STEREO      FL_MODE_STEREO

//' Fl_Gl_Window mode (values match Glut)
typedef unsigned long Fl_Mode;
	const Fl_Mode FL_MODE_RGB                      = 0x000;//' default
	const Fl_Mode FL_MODE_SINGLE                   = 0x000;
	const Fl_Mode FL_MODE_INDEX                    = 0x001;
	const Fl_Mode FL_MODE_DOUBLE                   = 0x002;//' default
	const Fl_Mode FL_MODE_ACCUM                    = 0x004;
	const Fl_Mode FL_MODE_ALPHA                    = 0x008;
	const Fl_Mode FL_MODE_DEPTH                    = 0x010;//' default
	const Fl_Mode FL_MODE_STENCIL                  = 0x020;
	const Fl_Mode FL_MODE_RGB8                     = 0x040;
	const Fl_Mode FL_MODE_MULTISAMPLE              = 0x080;
	const Fl_Mode FL_MODE_STEREO                   = 0x100;
	const Fl_Mode FL_MODE_FAKE_SINGLE 			   = 0x200;





//==========================================================
//==========================================================



	//' The Fl_Window constructors
	//declare function Fl_WindowNew(byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Window ptr
Fl_Window*   Fl_WindowNew(long w, long h, const char *title);

	//' #####################
	//' # FLTK Message Loop #
	//' #####################
//' Fl_Wait() waits until "something happens" and then returns.
//' Call this repeatedly to "run" your program.
//' You can also check what happened each time after this returns, 
//' which is quite useful for managing program state.
//' What Fl_Wait() really does is call all idle callbacks, 
//' all elapsed timeouts, call Fl_Flush() to get the screen to update, 
//' and then wait some time (zero if there are idle callbacks, the shortest of all pending timeouts, or infinity), 
//' for any events from the user or any Fl_Add_fd() callbacks.
//' It then handles the events and calls the callbacks and then returns.
	//declare function Fl_Wait() as long
long Fl_Wait(void);
//' Waits a maximum of time seconds.
//' It can return much sooner if something happens.
	//declare function Fl_Wait2(byval timeout as double) as double
double Fl_Wait2(double timeout);
//' Same as Fl_Wait2(0).
//declare function Fl_Check() as long
//' Fl_Ready is similar to Fl_Check() except this does not call Fl_Flush() or any callbacks, 
//' which is useful if your program is in a state where such callbacks are illegal. 
//declare function Fl_Ready() as long
	//As long as any windows are displayed Fl_Run() calls Fl_Wait() repeatedly. 
	//declare function Fl_Run() as long
long Fl_Run(void);


	//' Puts the window on the screen.
	//declare sub      Fl_WindowShow(byval win as Fl_Window ptr)
void Fl_WindowShow(Fl_Window* win);
	//'Gets or sets the current widget scheme. sheme can be "none","plastic", "gtk+" or "gleam" 
	//declare function Fl_SetScheme(byval scheme as const zstring ptr) as long
long Fl_SetScheme(const char *scheme_name);



	//'####################################
	//'# class Fl_Window extends Fl_Group #
	//'####################################
//' static member
//declare function Fl_WindowCurrent() as Fl_Window ptr
//' The Fl_Window constructors
//declare function Fl_WindowNew(byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Window ptr
//declare function Fl_WindowNew2(byval x as long, byval y as long, byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Window ptr
//' The Fl_Window destructor
//declare sub      Fl_WindowDelete(byref win as Fl_Window ptr)
//' Handles the specified event.
//declare function Fl_WindowHandle(byval win as Fl_Window ptr, byval event as FL_EVENT) as long
//' see: Fl_Group
	//declare sub      Fl_WindowBegin(byval win as Fl_Window ptr)
void Fl_WindowBegin(Fl_Window *win);
	//declare sub      Fl_WindowEnd(byval win as Fl_Window ptr)
void Fl_WindowEnd(Fl_Window *win);
//' Sets or gets whether or not the window manager border is around the window.
//declare sub      Fl_WindowSetBorder(byval win as Fl_Window ptr, byval b as long)
//declare function Fl_WindowGetBorder(byval win as Fl_Window ptr) as long
//' Fast inline function to turn the window manager border off
//declare sub      Fl_WindowClearBorder(byval win as Fl_Window ptr)
//' Sets the window titlebar label to a copy of a character string. 
//declare sub      Fl_WindowCopyLabel(byval win as Fl_Window ptr, byval label as const zstring ptr)
//' Sets things up so that the drawing functions will go into this window
	//declare sub      Fl_WindowMakeCurrent(byval win as Fl_Window ptr)
void Fl_WindowMakeCurrent(Fl_Window *win);
//' Changes the cursor for this window.
//declare sub      Fl_WindowCursor(byval win as Fl_Window ptr, byval c as FL_CURSOR, byval fg as Fl_COLOR = Fl_BLACK, byval bg as Fl_COLOR = Fl_WHITE)
//' Returns the window height including any window title bar and any frame added by the window manager. 
//declare function Fl_WindowDecorated_h(byval win as Fl_Window ptr) as long
//' Returns the window width including any frame added by the window manager.
//declare function Fl_WindowDecorated_w(byval win as Fl_Window ptr) as long
//' Undoes the effect of a previous Fl_WindowResize() or Fl_WindowShow() so that the next time Fl_WindowShow() is called the window manager is free to position the window.
//declare sub      Fl_WindowFreePosition(byval win as Fl_Window ptr)
//' Makes the window completely fill one or more screens, without any window manager border visible
//declare sub      Fl_WindowFullscreen(byval win as Fl_Window ptr)
//' Returns non zero if FULLSCREEN flag is set, 0 otherwise. 
//declare function Fl_WindowFullscreenActive(byval win as Fl_Window ptr) as long
//' Turns off any side effects of Fl_WindowFullscreen()
//declare sub      Fl_WindowFullscreenOff(byval win as Fl_Window ptr)
//' Turns off any side effects of Fl_WindowFullscreen() and does Fl_WindowResize(x,y,w,h). 
//declare sub      Fl_WindowFullscreenOffResize(byval win as Fl_Window ptr, byval x as long, byval y as long, byval w as long, byval h as long)
//' Positions the window so that the mouse is pointing at the given position, or at the center of the given widget, which may be the window itself.
//declare sub      Fl_WindowHotspot(byval win as Fl_Window ptr, byval x as long, byval y as long, byval offscreen as long=0)
//declare sub      Fl_WindowHotspotWidget(byval win as Fl_Window ptr, byval wgt as const Fl_Widget ptr, byval offscreen as long=0)
//' Iconifies the window.
//declare sub      Fl_WindowIconize(byval win as Fl_Window ptr)
//' Sets or gets the icon label. 
//declare sub      Fl_WindowSetIconLabel(byval win as Fl_Window ptr, byval label as const zstring ptr)
//declare function Fl_WindowGetIconLabel(byval win as Fl_Window ptr) as const zstring ptr
//' Sets or gets the window title bar label.
//declare sub      Fl_WindowSetLabel(byval win as Fl_Window ptr, byval label as const zstring ptr)
//declare function Fl_WindowGetLabel(byval win as Fl_Window ptr) as const zstring ptr
//' Sets the window title bar label and the icon label 
//declare sub      Fl_WindowSetLabels(byval win as Fl_Window ptr, byval winlabel as const zstring ptr, byval iconlabel as const zstring ptr)
//' Returns true if this window is a menu window. 
//declare function Fl_WindowGetMenuWindow(byval win as Fl_Window ptr) as long

//' A "modal" window, when shown(), will prevent any events from being delivered to other windows in the same program,
//' and will also remain on top of the other windows (if the X window manager supports the "transient for" property).
//declare sub      Fl_WindowSetModal(byval win as Fl_Window ptr)
//' Returns true if this window is modal. 
//declare function Fl_WindowGetModal(byval win as Fl_Window ptr) as long

//' A "non-modal" window (terminology borrowed from Microsoft Windows) acts like a modal() one 
//' in that it remains on top, but it has no effect on event delivery.
//declare sub      Fl_WindowSetNonModal(byval win as Fl_Window ptr)
//' Returns true if this window is modal or non-modal. 
//declare function Fl_WindowGetNonModal(byval win as Fl_Window ptr) as long

//' Activates the flags NOBORDER|FL_OVERRIDE. 
//declare sub      Fl_WindowSetOverride(byval win as Fl_Window ptr)
//' Returns non zero if FL_OVERRIDE flag is set, 0 otherwise
//declare function Fl_WindowGetOverride(byval win as Fl_Window ptr) as long

//' Changes the size and position of the window.
//declare sub      Fl_WindowResize(byval win as Fl_Window ptr, byval x as long, byval y as long, byval w as long, byval h as long)

//' Removes the window from the screen.
//declare sub      Fl_WindowHide(byval win as Fl_Window ptr)

//' Puts the window on the screen.
//declare sub      Fl_WindowShow(byval win as Fl_Window ptr)
//' Puts the window on the screen and parses command-line arguments
//declare sub      Fl_WindowShowArgs(byval win as Fl_Window ptr, byval argc as long, byval argv as zstring ptr ptr)
//' Returns non-zero if Fl_WindowShow() has been called (but not Fl_WindowHide())
//declare function Fl_WindowShown(byval win as Fl_Window ptr) as long




		//'##################################
		//'# class Fl_Box extends Fl_Widget #
		//'##################################
//DeclareEx(Fl_Box)
//' convert numeric boxtype 0-55 to FL_BOXTYPE
//declare function BoxType(byval nType as long) as FL_BOXTYPE
	//declare function Fl_BoxNew (byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Box ptr
Fl_Box* Fl_BoxNew(long x, long y, long w, long h, const char *label);
//declare function Fl_BoxNew2(byval bt as FL_BOXTYPE, byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Box ptr
//declare sub      Fl_BoxDelete(byref box as Fl_Box ptr)
//declare function Fl_BoxHandle(byval box as Fl_Box ptr, byval e as FL_EVENT) as long



	//'############################################
	//'# class Fl_Double_Window extends Fl_Window #
	//'############################################
	//declare function Fl_Double_WindowNew     (byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Double_Window ptr
Fl_Double_Window* Fl_Double_WindowNew(long w, long h, const char *title);
//declare function Fl_Double_WindowNew2    (byval x as long, byval y as long, byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Double_Window ptr
//declare sub      Fl_Double_WindowDelete  (byref win as Fl_Double_Window ptr)

//declare sub      Fl_Double_WindowFlush   (byval win as Fl_Double_Window ptr)

//declare sub      Fl_Double_WindowHide    (byval win as Fl_Double_Window ptr)

//declare sub      Fl_Double_WindowResize  (byval win as Fl_Double_Window ptr, byval x as long, byval y as long, byval w as long, byval h as long)

//declare sub      Fl_Double_WindowShow    (byval win as Fl_Double_Window ptr)

//declare sub      Fl_Double_WindowShowArgs(byval win as Fl_Double_Window ptr, byval argc as long, byval argv as zstring ptr ptr)


	//' ##########
	//' # widget #
	//' ##########
//' Adds a widget pointer to the widget watch list.
//declare sub      Fl_WatchWidgetPointer(byref widget as Fl_Widget ptr)
//' Clears a widget pointer in the watch list.(Internal use only !)
//declare sub      Fl_ClearWidgetPointer(byval wgt as const Fl_Widget ptr)
//' Releases a widget pointer from the watch list.
//declare sub      Fl_ReleaseWidgetPointer(byref widget as Fl_Widget ptr)
//' Schedules a widget for deletion at the next call to the event loop.
//' Use this method to delete a widget inside a callback function.
//declare sub      Fl_DeleteWidget(byval wgt as Fl_Widget ptr)
//' Deletes widgets previously scheduled for deletion. (This is for internal use only.)
//declare sub      Fl_DoWidgetDeletion
//' Sets/Gets the widget that is below the mouse.
//declare sub      Fl_SetBelowmouse(byval widget as Fl_Widget ptr)

//declare function Fl_GetBelowmouse() as Fl_Widget ptr
//' Sets the widget that will receive FL_KEYBOARD events.
	//declare sub      Fl_SetFocus(byval wgt as Fl_Widget ptr)
void Fl_SetFocus(Fl_Widget *wgt);
//' Gets the current widget with the focus.
//declare function Fl_GetFocus as Fl_Widget ptr
//' Gets/Sets the widget that is being pushed. 
//declare function Fl_GetPushed as Fl_Widget ptr

//declare sub      Fl_SetPushed(byval wgt as Fl_Widget ptr)
	//' Redraws all widgets.
	//declare sub      Fl_Redraw
void Fl_Redraw(void);
//' All Fl_Widgets that don't have a callback defined use a default callback that puts a pointer 
//' to the widget in this queue, and this method reads the oldest widget out of this queue. 
//declare function Fl_ReadQueue as Fl_Widget ptr




	//'#####################################
	//'# class Fl_Input_ extends Fl_Widget #
	//'#####################################
//' Changes the widget text.
//declare function Fl_Input_StaticValue(byval ip_ as Fl_Input_ ptr, byval text as const zstring ptr) as long
//declare function Fl_Input_StaticValue2(byval ip_ as Fl_Input_ ptr, byval text as const zstring ptr, byval nChars as long) as long

	//declare function Fl_Input_SetValue(byval ip_ as Fl_Input_ ptr, byval text as const zstring ptr) as long
long Fl_Input_SetValue(Fl_Input *inp, const char *txt);
//declare function Fl_Input_SetValue2(byval ip_ as Fl_Input_ ptr, byval text as const zstring ptr, byval nChars as long) as long
//' Returns the widget text.
	//declare function Fl_Input_GetValue(byval ip_ as Fl_Input_ ptr) as const zstring ptr
const char* Fl_Input_GetValue(Fl_Input *inp);
//' Inserts text at the cursor position.
//declare function Fl_Input_Insert(byval ip_ as Fl_Input_ ptr, byval text as const zstring ptr, byval cpos as long=0) as long
//' Deletes text from begin to end and inserts the new string text.
//declare function Fl_Input_Replace(byval ip_ as Fl_Input_ ptr, byval begin as long, byval end_ as long, byval text as const zstring ptr, byval nChars as long=0) as long
//' Returns the number of bytes in value
//declare function Fl_Input_GetSize(byval ip_ as Fl_Input_ ptr) as long
//' Returns the character at index i
//declare function Fl_Input_Index(byval ip_ as Fl_Input_ ptr, byval i as long) as Fl_Char
//' Put the current selection into the clipboard.
//declare function Fl_Input_Copy(byval ip_ as Fl_Input_ ptr, byval clipboard as long) as long
//' Copies the yank buffer to the clipboard.
//declare function Fl_Input_CopyCuts(byval ip_ as Fl_Input_ ptr) as long
//' Deletes the current selection.
//declare function Fl_Input_Cut(byval ip_ as Fl_Input_ ptr) as long
//' Deletes the next n bytes rounded to characters before or after the cursor.
//declare function Fl_Input_Cut1(byval ip_ as Fl_Input_ ptr, byval n as long) as long
//' Deletes all characters between index a and b.
//declare function Fl_Input_Cut2(byval ip_ as Fl_Input_ ptr, byval a as long, byval b as long) as long

//declare function Fl_Input_Undo(byval ip_ as Fl_Input_ ptr) as long
//' Sets/Gets the input field type.
	//declare sub      Fl_Input_SetInputType(byval ip_ as Fl_Input_ ptr, byval typ as FL_INPUT_TYPE)
void Fl_Input_SetInputType(Fl_Input *inp, Fl_Input_Type typ);
//declare function Fl_Input_GetInputType(byval ip_ as Fl_Input_ ptr) as FL_INPUT_TYPE
//' Sets/Gets the color of the cursor.
//declare sub      Fl_Input_SetCursorColor(byval ip_ as Fl_Input_ ptr, byval c as Fl_COLOR)
//declare function Fl_Input_GetCursorColor(byval ip_ as Fl_Input_ ptr) as Fl_COLOR
//' Sets/Gets the current selection mark.
//declare function Fl_Input_SetMark(byval ip_ as Fl_Input_ ptr, byval m as long) as long
//declare function Fl_Input_GetMark(byval ip_ as Fl_Input_ ptr) as long
//' Sets/Gets the maximum length of the input field in characters.
//declare sub      Fl_Input_SetMaximumSize(byval ip_ as Fl_Input_ ptr, byval maxsize as long)
//declare function Fl_Input_GetMaximumSize(byval ip_ as Fl_Input_ ptr) as long
//' Sets the cursor position and mark.
//declare function Fl_Input_SetPosition(byval ip_ as Fl_Input_ ptr, byval p as long) as long
//' Sets the index for the cursor and mark.
//declare function Fl_Input_SetPosition2(byval ip_ as Fl_Input_ ptr, byval p as long, byval m as long) as long
//' Gets the position of the text cursor. 
//declare function Fl_Input_GetPosition(byval ip_ as Fl_Input_ ptr) as long
//' Sets/Gets the read-only state of the input field. 
//declare sub      Fl_Input_SetReadonly(byval ip_ as Fl_Input_ ptr, byval readonly as long)
//declare function Fl_Input_GetReadonly(byval ip_ as Fl_Input_ ptr) as long
//' Sets/Gets the shortcut key associated with this widget.
//declare sub      Fl_Input_SetShortcut(byval ip_ as Fl_Input_ ptr, byval shortcut as long)
//declare function Fl_Input_GetShortcut(byval ip_ as Fl_Input_ ptr) as long
//' Changes the position and size of the widget.
//declare sub      Fl_Input_Resize(byval ip_ as Fl_Input_ ptr, byval x as long, byval y as long, byval w as long, byval h as long)
//' Changes the size of the widget.
//declare sub      Fl_Input_SetSize(byval ip_ as Fl_Input_ ptr, byval w as long, byval h as long)
//' Sets/Gets whether the Tab key causes focus navigation in multiline input fields or not.
//declare sub      Fl_Input_SetTabNav(byval ip_ as Fl_Input_ ptr, byval v as long)
//declare function Fl_Input_GetTabNav(byval ip_ as Fl_Input_ ptr) as long
//' Sets/Gets the color of the text in the input field. 
//declare sub      Fl_Input_SetTextColor(byval ip_ as Fl_Input_ ptr, byval c as Fl_COLOR)
//declare function Fl_Input_GetTextColor(byval ip_ as Fl_Input_ ptr) as Fl_COLOR
//' Sets/Gets the font of the text in the input field.
//declare sub      Fl_Input_SetTextFont(byval ip_ as Fl_Input_ ptr, byval f as FL_FONT)
//declare function Fl_Input_GetTextFont(byval ip_ as Fl_Input_ ptr) as FL_FONT
//' Sets/Gets the size of the text in the input field.
//declare sub      Fl_Input_SetTextSize(byval ip_ as Fl_Input_ ptr, byval s as FL_FONTSIZE)
//declare function Fl_Input_GetTextSize(byval ip_ as Fl_Input_ ptr) as FL_FONTSIZE
//' Sets/Gets the word wrapping state of the input field. 
//declare sub      Fl_Input_SetWrap(byval ip_ as Fl_Input_ ptr, byval wrap as long)
//declare function Fl_Input_GetWrap(byval ip_ as Fl_Input_ ptr) as long
	//' Creates a new Fl_Input widget using the given position, size, and label string.
	//declare function Fl_InputNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Input ptr
Fl_Input* Fl_InputNew(long x, long y, long w, long h, const char *label);
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

	//declare function Fl_ButtonNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Button ptr
Fl_Button* Fl_ButtonNew(long x, long y, long w, long h, const char *label);


	//' ####################
	//' # Widget Callbacks #
	//' ####################
	//declare sub      Fl_WidgetSetCallback    (byval wgt as Fl_Widget ptr, byval cb as Fl_Callback)
void Fl_WidgetSetCallback(Fl_Widget *wgt, Fl_Callback cb);
	//declare sub      Fl_WidgetSetCallbackArg (byval wgt as Fl_Widget ptr, byval cb as Fl_Callback, byval arg as any ptr)
void Fl_WidgetSetCallbackArg(Fl_Widget *wgt, Fl_Callback cb, void *arg);
	//declare sub      Fl_WidgetSetCallback0   (byval wgt as Fl_Widget ptr, byval cb as Fl_Callback0)
void Fl_WidgetSetCallback0(Fl_Widget *wgt, Fl_Callback0 cb);
//declare sub      Fl_WidgetSetCallback1Arg(byval wgt as Fl_Widget ptr, byval cb as Fl_Callback1, byval arg as long)
//declare function Fl_WidgetGetCallback    (byval wgt as Fl_Widget ptr) as Fl_Callback_p

//' Sets or gets the current user data (long) argument that is passed to the callback function. 
//declare sub      Fl_WidgetSetArgument(byval wgt as Fl_Widget ptr, byval lArg as long)
//declare function Fl_WidgetGetArgument(byval wgt as Fl_Widget ptr) as long
//' Checks if the widget value changed since the last callback.
//declare function Fl_WidgetChanged(byval wgt as Fl_Widget ptr) as ulong
//declare sub      Fl_WidgetSetChanged(byval wgt as Fl_Widget ptr)
//declare sub      Fl_WidgetClearChanged(byval wgt as Fl_Widget ptr)

//declare sub      Fl_WidgetSetOutput(byval wgt as Fl_Widget ptr)
//declare sub      Fl_WidgetClearOutput(byval wgt as Fl_Widget ptr)

//declare function Fl_WidgetOutput(byval wgt as Fl_Widget ptr) as ulong

//declare sub      Fl_WidgetSetVisible(byval wgt as Fl_Widget ptr)
//declare sub      Fl_WidgetClearVisible(byval wgt as Fl_Widget ptr)

	//declare sub      Fl_WidgetSetVisibleFocus(byval wgt as Fl_Widget ptr)
void Fl_WidgetSetVisibleFocus(Fl_Widget *wgt);
//declare sub      Fl_WidgetClearVisibleFocus(byval wgt as Fl_Widget ptr)


	//declare function Fl_Check_ButtonNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Check_Button ptr
Fl_Check_Button* Fl_Check_ButtonNew(long x, long y, long w, long h, const char *label);
	//declare function Fl_ButtonSetValue(byval btn as Fl_Button ptr, byval v as long) as long
long Fl_ButtonSetValue(Fl_Button *btn, long val);	
	//declare function Fl_ButtonGetValue(byval btn as Fl_Button ptr) as long
long Fl_ButtonGetValue(Fl_Button *btn);
	//Makes a widget in/visible. 
	//declare sub      Fl_WidgetHide(byval wgt as Fl_Widget ptr)
void Fl_WidgetHide(Fl_Widget *wgt);
	//declare sub      Fl_WidgetShow(byval wgt as Fl_Widget ptr)
void Fl_WidgetShow(Fl_Widget *wgt);
	//' Gets/Sets the label font. 
	//declare sub      Fl_WidgetSetLabelFont(byval wgt as Fl_Widget ptr, byval f as FL_FONT)
void Fl_WidgetSetLabelFont(Fl_Widget *wgt, Fl_Font fn);
	//declare function Fl_WidgetGetLabelFont(byval wgt as Fl_Widget ptr) as FL_FONT
Fl_Font Fl_WidgetGetLabelFont(Fl_Widget *wgt);
	//Gets/Sets the label fonstsize. 
	//declare sub      Fl_WidgetSetLabelSize(byval wgt as Fl_Widget ptr, byval fz as FL_FONTSIZE)
void Fl_WidgetSetLabelSize(Fl_Widget *wgt, Fl_FontSize fz);
	//declare function Fl_WidgetGetLabelSize(byval wgt as Fl_Widget ptr) as FL_FONTSIZE
Fl_FontSize Fl_WidgetGetLabelSize(Fl_Widget *wgt);
	//' De/Activates the widget. 
	//declare sub      Fl_WidgetActivate(byval wgt as Fl_Widget ptr)
void Fl_WidgetActivate(Fl_Widget *wgt);
	//declare sub      Fl_WidgetDeactivate(byval wgt as Fl_Widget ptr)
void Fl_WidgetDeactivate(Fl_Widget *wgt);


	//#####################################
	//# class Fl_Spinner extends Fl_Group #
	//#####################################
	//declare function Fl_SpinnerNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Spinner ptr
Fl_Spinner* Fl_SpinnerNew(long x, long y, long w, long h, const char *label);
	//declare sub      Fl_SpinnerDelete(byref spi as Fl_Spinner ptr)
void Fl_SpinnerDelete(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerSetColor(byval spi as Fl_Spinner ptr, byval c as Fl_COLOR)
void Fl_SpinnerSetColor(Fl_Spinner *spi, Fl_Color cl);
	//declare function Fl_SpinnerGetColor(byval spi as Fl_Spinner ptr) as Fl_COLOR
Fl_Color Fl_SpinnerGetColor(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerSetFormat(byval spi as Fl_Spinner ptr, byval f as const zstring ptr)
void Fl_SpinnerSetFormat(Fl_Spinner *spi, const char *frmt);
	//declare function Fl_SpinnerGetFormat(byval spi as Fl_Spinner ptr) as const zstring ptr
const char* Fl_SpinnerGetFormat(Fl_Spinner *spi);
	//declare function Fl_SpinnerHandle(byval spi as Fl_Spinner ptr, byval e as FL_EVENT) as long
long Fl_SpinnerHandle(Fl_Spinner *spi, Fl_Event ev);
	//declare sub      Fl_SpinnerSetMaximum(byval spi as Fl_Spinner ptr, byval m as double)
void Fl_SpinnerSetMaximum(Fl_Spinner *spi, double mx);
	//declare function Fl_SpinnerGetMaximum(byval spi as Fl_Spinner ptr) as double
double Fl_SpinnerGetMaximum(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerSetMinimum(byval spi as Fl_Spinner ptr, byval m as double)
void Fl_SpinnerSetMinimum(Fl_Spinner *spi, double mn);
	//declare function Fl_SpinnerGetMinimum(byval spi as Fl_Spinner ptr) as double
double Fl_SpinnerGetMinimum(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerRange(byval spi as Fl_Spinner ptr, byval a as double, byval b as double)
void Fl_SpinnerRange(Fl_Spinner *spi, double a, double b);
	//declare sub      Fl_SpinnerResize(byval spi as Fl_Spinner ptr, byval x as long, byval y as long, byval w as long, byval h as long)
void Fl_SpinnerResize(Fl_Spinner *spi, long x, long y, long w, long h );
	//declare sub      Fl_SpinnerSetStep(byval spi as Fl_Spinner ptr, byval s as double)
void Fl_SpinnerSetStep(Fl_Spinner *spi, double s);
	//declare function Fl_SpinnerGetStep(byval spi as Fl_Spinner ptr) as double
double Fl_SpinnerGetStep(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerSetTextColor(byval spi as Fl_Spinner ptr, byval c as Fl_COLOR)
void Fl_SpinnerSetTextColor(Fl_Spinner *spi, Fl_Color cl);
		//declare function Fl_SpinnerGetTextColor(byval spi as Fl_Spinner ptr) as Fl_COLOR
Fl_Color Fl_SpinnerGetTextColor(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerSetTextFont(byval spi as Fl_Spinner ptr, byval f as FL_FONT)
void Fl_SpinnerSetTextFont(Fl_Spinner *spi, Fl_Font fn);
	//declare function Fl_SpinnerGetTextFont(byval spi as Fl_Spinner ptr) as FL_FONT
Fl_Font Fl_SpinnerGetTextFont(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerSetTextSize(byval spi as Fl_Spinner ptr, byval s as FL_FONTSIZE)
void Fl_SpinnerSetTextSize(Fl_Spinner *spi, Fl_FontSize s);
	//declare function Fl_SpinnerGetTextSize(byval spi as Fl_Spinner ptr) as FL_FONTSIZE
Fl_FontSize Fl_SpinnerGetTextSize(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerSetType(byval spi as Fl_Spinner ptr, byval v as ubyte)
void Fl_SpinnerSetType(Fl_Spinner *spi, unsigned char v);
	//declare function Fl_SpinnerGetType(byval spi as Fl_Spinner ptr) as ubyte
unsigned char Fl_SpinnerGetType(Fl_Spinner *spi);
	//declare sub      Fl_SpinnerSetValue(byval spi as Fl_Spinner ptr, byval v as double)
void Fl_SpinnerSetValue(Fl_Spinner *spi, double v);
	//declare function Fl_SpinnerGetValue(byval spi as Fl_Spinner ptr) as double
double Fl_SpinnerGetValue(Fl_Spinner *spi);
///////////////////////////////////////////////////////////


//' ################
//' # Widget Label #
//' ################
	//' Gets or sets or copy the current label text.' 
	//declare function Fl_WidgetGetLabel(byval wgt as Fl_Widget ptr) as const zstring ptr
const char* Fl_WidgetGetLabel(Fl_Widget *wgt);
	//declare sub      Fl_WidgetSetLabel(byval wgt as Fl_Widget ptr, byval txt as const zstring ptr)
void Fl_WidgetSetLabel(Fl_Widget *wgt, const char *txt);
//declare sub      Fl_WidgetSetLabel2(byval wgt as Fl_Widget ptr, byval a as FL_LABEL_TYPE, byval txt as const zstring ptr)
	//declare sub      Fl_WidgetCopyLabel(byval wgt as Fl_Widget ptr, byval txt as const zstring ptr)
void Fl_WidgetCopyLabel(Fl_Widget *wgt, const char *txt);
//' Gets/Sets the label color. 
//declare sub      Fl_WidgetSetLabelColor(byval wgt as Fl_Widget ptr, byval c as Fl_COLOR)
//declare function Fl_WidgetGetLabelColor(byval wgt as Fl_Widget ptr) as Fl_COLOR
//' Gets/Sets the label font. 
//declare sub      Fl_WidgetSetLabelFont(byval wgt as Fl_Widget ptr, byval f as FL_FONT)
//declare function Fl_WidgetGetLabelFont(byval wgt as Fl_Widget ptr) as FL_FONT
//' Gets/Sets the label fonstsize. 
//declare sub      Fl_WidgetSetLabelSize(byval wgt as Fl_Widget ptr, byval fz as FL_FONTSIZE)
//declare function Fl_WidgetGetLabelSize(byval wgt as Fl_Widget ptr) as FL_FONTSIZE
//' Gets/Sets the label type.
//declare function Fl_WidgetGetLabelType(byval wgt as Fl_Widget ptr) as FL_LABEL_TYPE
//declare sub      Fl_WidgetSetLabelType(byval wgt as Fl_Widget ptr, byval lt as FL_LABEL_TYPE)
//' Returns w,h accordingly with the label size. 
//declare sub      Fl_WidgetMeasureLabel(byval wgt as Fl_Widget ptr, byref w as long, byref h as long)
//' Returns a pointer to the parent widget.
//declare function Fl_WidgetGetParent(byval wgt as Fl_Widget ptr) as Fl_Group ptr
//' Internal use only - "for hacks only"
//declare sub      Fl_WidgetSetParent(byval wgt as Fl_Widget ptr, byval p as Fl_Group ptr)
///////////////////////////////////////////////


	//' #####################
	//' # Widget re/drawing #
	//' #####################
//' Schedules the drawing of the widget.
//declare sub      Fl_WidgetRedraw(byval wgt as Fl_Widget ptr)
//' Schedules the drawing of the label.
//declare sub      Fl_WidgetRedrawLabel(byval wgt as Fl_Widget ptr)

//' Gives the widget the keyboard focus.
//declare function Fl_WidgetTakeFocus(byval wgt as Fl_Widget ptr) as long
//' Returns if the widget is able to take events.
//declare function Fl_WidgetTakesEvents(byval wgt as Fl_Widget ptr) as ulong
//' Returns true if the widget's label contains the entered '&x' shortcut.
//declare function Fl_WidgetTestShortcut(byval wgt as Fl_Widget ptr) as long

//' Gets or sets or copy the current tooltip text.
//declare function Fl_WidgetGetTooltip(byval wgt as Fl_Widget ptr) as const zstring ptr
//declare sub      Fl_WidgetSetTooltip(byval wgt as Fl_Widget ptr, byval tip as const zstring ptr)
//declare sub      Fl_WidgetCopyTooltip(byval wgt as Fl_Widget ptr, byval tip as const zstring ptr)
	//' Gets/Sets the widget type. 
	//declare function Fl_WidgetGetType(byval wgt as Fl_Widget ptr) as ubyte
unsigned char Fl_WidgetGetType(Fl_Widget *wgt);
	//declare sub      Fl_WidgetSetType(byval wgt as Fl_Widget ptr, byval t as ubyte)
void Fl_WidgetSetType(Fl_Widget *wgt, unsigned char t);
//' Gets/Sets the user data for this widget.
//declare function Fl_WidgetGetUserData(byval wgt as Fl_Widget ptr) as any ptr
//declare sub      Fl_WidgetSetUserData(byval wgt as Fl_Widget ptr, byval v as any ptr)
//' Returns whether a widget is visible. 
//declare function Fl_WidgetVisible(byval wgt as Fl_Widget ptr) as long
//' Returns whether a widget and all its parents are visible.
//declare function Fl_WidgetVisibleR(byval wgt as Fl_Widget ptr) as long
//' Checks whether this widget has a visible focus. 
//declare function Fl_WidgetGetVisibleFocus(byval wgt as Fl_Widget ptr) as long
//' Modifies keyboard focus navigation.
//declare sub      Fl_WidgetVisibleFocus(byval wgt as Fl_Widget ptr, byval v as long)

//' Set's Get's the flags used to decide when a callback is called. 
//declare sub      Fl_WidgetSetWhen(byval wgt as Fl_Widget ptr, byval w as FL_WHEN)
//declare function Fl_WidgetGetWhen(byval wgt as Fl_Widget ptr) as FL_WHEN

//' Returns a pointer to the nearest parent window up the widget hierarchy.
//declare function Fl_WidgetWindow(byval wgt as Fl_Widget ptr) as Fl_Window ptr

//declare function Fl_WidgetTopWindow(byval wgt as Fl_Widget ptr) as Fl_Window ptr

//declare function Fl_WidgetTopWindowOffset(byval wgt as Fl_Widget ptr, byref xoff as long, byref yoff as long) as Fl_Window ptr



//declare sub      Fl_WidgetDefaultCallback(byval cb as Fl_Widget ptr, byval pArg as any ptr)
//' static members
//declare function Fl_WidgetLabelShortcut(byval t as const zstring ptr) as long

//declare function Fl_WidgetTestShortcut2(byval t as const zstring ptr, byval require_alt as long=0) as long



	//########################################
	//# class Fl_Browser extends Fl_Browser_ #
	//########################################
//DeclareEx(Fl_Browser)
//' The constructor makes an empty browser. 
	//declare function Fl_BrowserNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Browser ptr
Fl_Browser* Fl_BrowserNew(long x, long y, long w, long h, const char *label);
	//declare sub      Fl_BrowserDelete(byref br as Fl_Browser ptr)
void Fl_BrowserDelete(Fl_Browser *br);
	//' Shows the entire Fl_Browser widget -- opposite of Fl_BrowserHide().
	//declare sub      Fl_BrowserShow(byval br as Fl_Browser ptr)
void Fl_BrowserShow(Fl_Browser *br);
	//' Hides the entire Fl_Browser widget -- opposite of Fl_BrowserShow().
	//declare sub      Fl_BrowserHide(byval br as Fl_Browser ptr)
void Fl_BrowserHide(Fl_Browser *br);
//' Makes line visible, and available for selection by user. 
//declare sub      Fl_BrowserShow2(byval br as Fl_Browser ptr, byval line_ as long)
//' Makes line invisible, preventing selection by the user. 
//declare sub      Fl_BrowserHide2(byval br as Fl_Browser ptr, byval line_ as long)
//' Returns non-zero if the specified line is visible, 0 if hidden. 
//declare function Fl_BrowserVisible(byval br as Fl_Browser ptr, byval line_ as long) as long
//' Removes all the lines in the browser.
	//declare sub      Fl_BrowserClear(byval br as Fl_Browser ptr)
void Fl_BrowserClear(Fl_Browser *br);
//' Clears the browser and reads the file, adding each line from the file to the browser. 
//declare function Fl_BrowserLoad(byval br as Fl_Browser ptr, byval filename as const zstring ptr) as long
	//' Adds a new line to the end of the browser. 
	//declare sub      Fl_BrowserAdd(byval br as Fl_Browser ptr, byval newtext as const zstring ptr, byval pData as any ptr=0)
void Fl_BrowserAdd(Fl_Browser *br, const char *newtext, void *pData);
//' Insert a new entry whose label is newtext above given line, optional data d.
//declare sub      Fl_BrowserInsert(byval br as Fl_Browser ptr, byval line_ as long, byval newtext as const zstring ptr, byval pDatat as any ptr=0)
//' Remove entry for given line number, making the browser one line shorter.
//declare sub      Fl_BrowserRemove(byval br as Fl_Browser ptr, byval line_ as long)
//' Removes the icon for line.
//declare sub      Fl_BrowserRemoveIcon(byval br as Fl_Browser ptr, byval line_ as long)
//' Returns the line that is currently visible at the top of the browser.
//declare function Fl_BrowserGetTopline(byval br as Fl_Browser ptr) as long
//' Scrolls the browser so the top item in the browser is showing the specified line.
//declare sub      Fl_BrowserSetTopline(byval br as Fl_Browser ptr, byval line_ as long)
//' Scrolls the browser so the middle item in the browser is showing the specified line.
//declare sub      Fl_BrowserMiddleLine(byval br as Fl_Browser ptr, byval line_ as long)
//' Scrolls the browser so the bottom item in the browser is showing the specified line.
//declare sub      Fl_BrowserBottomLine(byval br as Fl_Browser ptr, byval line_ as long)
//' Sets the column separator to c.
//declare sub      Fl_BrowserSetColumnChar(byval br as Fl_Browser ptr, byval c as ubyte)
//' Gets the current column separator character.
//declare function Fl_BrowserGetColumnChar(byval br as Fl_Browser ptr) as ubyte
//' Sets the current array to arr.
//declare sub      Fl_BrowserSetColumnWidths(byval br as Fl_Browser ptr, byval arr as const long ptr)
//' Gets the current column width array. 
//declare function Fl_BrowserGetColumnWidths(byval br as Fl_Browser ptr) as const long ptr
//' Sets the user data for specified line.
//declare sub      Fl_BrowserSetData(byval br as Fl_Browser ptr, byval line_ as long, byval pData as any ptr)
//' Returns the user data for specified line.
//declare function Fl_BrowserGetData(byval br as Fl_Browser ptr, byval line_ as long) as any ptr
//' For back compatibility.
//declare sub      Fl_BrowserDisplay(byval br as Fl_Browser ptr, byval line_ as long, byval v as long=1)
//' Returns non-zero if line has been scrolled to a position where it is being displayed.
//declare function Fl_BrowserDisplayed(byval br as Fl_Browser ptr, byval line_ as long) as long
//' Sets the current format code prefix character to c. 
//declare sub      Fl_BrowserSetFormatChar(byval br as Fl_Browser ptr, byval c as ubyte)
//' Gets the current format code prefix character, which by default is '@'.
//declare function Fl_BrowserGetFormatChar(byval br as Fl_Browser ptr) as ubyte
//' Set the image icon for line to the value icon.
//declare sub      Fl_BrowserSetIcon(byval br as Fl_Browser ptr, byval line_ as long, byval icon as Fl_Image ptr)
//' Returns the icon currently defined for line.
//declare function Fl_BrowserGetIcon(byval br as Fl_Browser ptr, byval line_ as long) as Fl_Image ptr
//' Updates the browser so that line is shown at position pos.
//declare sub      Fl_BrowserLinePosition(byval br as Fl_Browser ptr, byval line_ as long, byval p as FL_LINE_POSITION)
//' Make the item at the specified line visible.
//declare sub      Fl_BrowserMakeVisible(byval br as Fl_Browser ptr, byval line_ as long)
//' Line from is removed and reinserted at to.
//declare sub      Fl_BrowserMove(byval br as Fl_Browser ptr, byval to_ as long, byval from as long)
//' For back compatibility only.
//declare sub      Fl_BrowserReplace(byval br as Fl_Browser ptr, byval a as long, byval b as const zstring ptr)
//' Sets the selection state of the item at line to the value val.
//declare function Fl_BrowserSelect(byval br as Fl_Browser ptr, byval line_ as long, byval v as long=1) as long
//' Returns 1 if specified line is selected, 0 if not.
//declare function Fl_BrowserSelected(byval br as Fl_Browser ptr, byval line_ as long) as long
//' Changes the size of the widget.
//declare sub      Fl_BrowserSetSize(byval br as Fl_Browser ptr, byval w as long, byval h as long)
//' Returns how many lines are in the browser. 
//declare function Fl_BrowserGetSize(byval br as Fl_Browser ptr) as long
//' Swaps two browser lines a and b.
//declare sub      Fl_BrowserSwap(byval br as Fl_Browser ptr, byval a as long, byval b as long)
//' Sets the text for the specified line to newtext.
//declare sub      Fl_BrowserSetText(byval br as Fl_Browser ptr, byval line_ as long, byval newtext as const zstring ptr)
//' Returns the label text for the specified line.
//declare function Fl_BrowserGetText(byval br as Fl_Browser ptr, byval line_ as long) as const zstring ptr
//' Sets the browser's value, which selects the specified line. 
//declare sub      Fl_BrowserSetValue(byval br as Fl_Browser ptr, byval line_ as long)
//' Returns the line number of the currently selected line, or 0 if none.
//declare function Fl_BrowserGetValue(byval br as Fl_Browser ptr) as long
//#define Fl_BrowserEnd Fl_GroupEnd


	//' ###############
	//' # Widget Size #
	//' ###############
//declare sub      Fl_WidgetSize(byval wgt as Fl_Widget ptr, byval w as long, byval h as long)
//declare sub      Fl_WidgetResize(byval wgt as Fl_Widget ptr, byval x as long, byval y as long, byval w as long, byval h as long)
	//declare function Fl_WidgetGetW(byval wgt as Fl_Widget ptr) as long
long Fl_WidgetGetW(Fl_Widget *wgt);
	//declare function Fl_WidgetGetH(byval wgt as Fl_Widget ptr) as long
long Fl_WidgetGetH(Fl_Widget *wgt);



		//'######################
		//'# class Fl_Menu_Item #
		//'######################
//' Allows a menu item to be picked.
//declare sub      Fl_Menu_ItemActivate(byval it as Fl_Menu_Item ptr)
//declare sub      Fl_Menu_ItemDeactivate(byval it as Fl_Menu_Item ptr)
//' Gets whether or not the item can be picked.
//declare function Fl_Menu_ItemActive(byval it as Fl_Menu_Item ptr) as long
//' Returns non 0 if FL_INACTIVE and FL_INVISIBLE are cleared, 0 otherwise.
//declare function Fl_Menu_ItemActiveVisible(byval it as Fl_Menu_Item ptr) as long
//' Adds an item. 
//declare function Fl_Menu_ItemAdd (byval it as Fl_Menu_Item ptr, byval label as const zstring ptr, byval shortcut as long=0, byval cb as Fl_Callback=0, byval userdata as any ptr=0, byval flag as FL_MENUITEM_FLAG=0) as long
//declare function Fl_Menu_ItemAdd2(byval it as Fl_Menu_Item ptr, byval label as const zstring ptr, byval shortcut as const zstring ptr, byval cb as Fl_Callback=0, byval userdata as any ptr=0, byval flag as FL_MENUITEM_FLAG=0) as long
//' Inserts an item at position index. 
//declare function Fl_Menu_ItemInsert(byval it as Fl_Menu_Item ptr, byval index as long, byval label as const zstring ptr, byval shortcut as long, byval cb as Fl_Callback, byval userdata as any ptr=0, byval flag as FL_MENUITEM_FLAG=0) as long
//' Sets/Gets the user data argument that is sent to the callback function. 
//declare sub      Fl_Menu_ItemSetArgument(byval it as Fl_Menu_Item ptr, byval v as long)
//declare function Fl_Menu_ItemGetArgument(byval it as Fl_Menu_Item ptr) as long 

//' Sets the menu item's callback functions and optional the userdata argument. 
//declare sub      Fl_Menu_ItemCallback (byval it as Fl_Menu_Item ptr, byval cb as Fl_Callback)
//declare sub      Fl_Menu_ItemCallbackArg alias "Fl_Menu_ItemCallback2" (byval it as Fl_Menu_Item ptr, byval cb as Fl_Callback, byval pData as any ptr)
//declare sub      Fl_Menu_ItemCallback0(byval it as Fl_Menu_Item ptr, byval cb as Fl_Callback0)
//declare sub      Fl_Menu_ItemCallback1(byval it as Fl_Menu_Item ptr, byval cb as Fl_Callback1, byval lData as long=0)
//' Returns the callback function that is set for the menu item.
//declare function Fl_Menu_ItemGetCallback_p(byval it as Fl_Menu_Item ptr) as Fl_Callback_p
//' Returns true if a checkbox will be drawn next to this item. 
//declare function Fl_Menu_ItemCheckBox(byval it as Fl_Menu_Item ptr) as long
//' Returns true if this item is a radio item.
//declare function Fl_Menu_ItemRadio(byval it as Fl_Menu_Item ptr) as long
//' next 3 declares for backward compatibility only
//declare sub      Fl_Menu_ItemCheck(byval it as Fl_Menu_Item ptr)
//declare function Fl_Menu_ItemChecked(byval it as Fl_Menu_Item ptr) as long
//declare sub      Fl_Menu_ItemUncheck(byval it as Fl_Menu_Item ptr)
//' Turns the check or radio item "off" for the menu item.
//declare sub      Fl_Menu_ItemClear(byval it as Fl_Menu_Item ptr)
//' Calls the Fl_Menu_Item item's callback, and provides the Fl_Widget argument.
//declare sub      Fl_Menu_ItemDoCallback                                     (byval it as Fl_Menu_Item ptr, byval wgt as Fl_Widget ptr, byval pData as any ptr=0)
//declare sub      Fl_Menu_ItemDoCallbackArg  alias "Fl_Menu_ItemDoCallback"  (byval it as Fl_Menu_Item ptr, byval wgt as Fl_Widget ptr, byval pData as any ptr)
//declare sub      Fl_Menu_ItemDoCallback0    alias "Fl_Menu_ItemDoCallback3" (byval it as Fl_Menu_Item ptr, byval wgt as Fl_Widget ptr)
//declare sub      Fl_Menu_ItemDoCallback1Arg alias "Fl_Menu_ItemDoCallback2" (byval it as Fl_Menu_Item ptr, byval wgt as Fl_Widget ptr, byval lData as long)
//' Draws the menu item in bounding box x,y,w,h, optionally selects the item.
//declare sub      Fl_Menu_ItemDraw(byval it as Fl_Menu_Item ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval m as const Fl_Menu_ ptr, byval t as long=0)
//' Search only the top level menu for a shortcut.
//declare function Fl_Menu_ItemFindShortcut(byval it as Fl_Menu_Item ptr, byval ip as long ptr=0, byval require_alt as const long=0) as Fl_Menu_Item ptr
//' Returns the first menu item, same as next(0)
//declare function Fl_Menu_ItemFirst(byval it as Fl_Menu_Item ptr) as Fl_Menu_Item ptr
//declare function Fl_Menu_ItemFirst2(byval it as Fl_Menu_Item ptr) as const Fl_Menu_Item ptr
//' Advance a pointer by n items through a menu array, skipping the contents of submenus and invisible items.
//declare function Fl_Menu_ItemNext(byval it as Fl_Menu_Item ptr, byval index as long=1) as Fl_Menu_Item ptr
//declare function Fl_Menu_ItemNext2(byval it as Fl_Menu_Item ptr, byval index as long=1) as const Fl_Menu_Item ptr
//' Hides an item in the menu.
//declare sub      Fl_Menu_ItemHide(byval it as Fl_Menu_Item ptr)
//' Makes an item visible in the menu.
//declare sub      Fl_Menu_ItemShow(byval it as Fl_Menu_Item ptr)

//declare sub      Fl_Menu_ItemImage(byval it as const Fl_Menu_Item ptr, byval img as Fl_Image ptr)
	//' Sets or Returns the title of the item.
	//declare sub      Fl_Menu_ItemSetLabel(byval it as Fl_Menu_Item ptr, byval label as const zstring ptr)
void Fl_Menu_ItemSetLabel(Fl_Menu_Item *itm, const char* label);
//declare sub      Fl_Menu_ItemSetLabel2(byval it as Fl_Menu_Item ptr, byval lt as FL_LABEL_TYPE, byval label as const zstring ptr)
//declare function Fl_Menu_ItemGetLabel(byval it as Fl_Menu_Item ptr) as const zstring ptr

//declare sub      Fl_Menu_ItemSetLabelColor(byval it as Fl_Menu_Item ptr, byval c as Fl_COLOR)
//declare function Fl_Menu_ItemGetLabelColor(byval it as Fl_Menu_Item ptr) as Fl_COLOR

//declare sub      Fl_Menu_ItemSetLabelFont(byval it as Fl_Menu_Item ptr, byval f as FL_FONT)
//declare function Fl_Menu_ItemGetLabelFont(byval it as Fl_Menu_Item ptr) as FL_FONT

//declare sub      Fl_Menu_ItemSetLabelSize(byval it as Fl_Menu_Item ptr, byval fs as FL_FONTSIZE)
//declare function Fl_Menu_ItemGetLabelSize(byval it as Fl_Menu_Item ptr) as FL_FONTSIZE

//declare sub      Fl_Menu_ItemSetLabelType(byval it as Fl_Menu_Item ptr, byval lt as Fl_LABEL_TYPE)
//declare function Fl_Menu_ItemGetLabelType(byval it as Fl_Menu_Item ptr) as Fl_LABEL_TYPE

//' Measures width of label, including effect of & characters.
//declare function Fl_Menu_ItemMeasure(byval it as Fl_Menu_Item ptr, byval h as long ptr, byval m as const Fl_Menu_ ptr) as long

//' This method is called by widgets that want to display menus.
//declare function Fl_Menu_ItemPopup   (byval it as Fl_Menu_Item ptr, byval x as long, byval y as long, byval title as const zstring ptr=0, byval picked as Fl_Menu_Item ptr=0, byval m as const Fl_Menu_ ptr=0) as Fl_Menu_Item ptr

//' Pulldown() is similar to popup(), but a rectangle is provided to position the menu.
//declare function Fl_Menu_ItemPulldown(byval it as Fl_Menu_Item ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval picked as Fl_Menu_Item ptr=0, byval m as const Fl_Menu_ ptr=0, byval title as Fl_Menu_Item ptr=0, byval menubar as long=0) as Fl_Menu_Item ptr

//' Turns the check or radio item "on" for the menu item.
//declare sub      Fl_Menu_ItemSet(byval it as Fl_Menu_Item ptr)

//' Turns the radio item "on" for the menu item and turns off adjacent radio items set.
//declare sub      Fl_Menu_ItemSetonly(byval it as Fl_Menu_Item ptr)

//' Sets/Gets exactly what key combination will trigger the menu item.
//declare sub      Fl_Menu_ItemSetShortcut(byval it as Fl_Menu_Item ptr, byval s as long)
//declare function Fl_Menu_ItemGetShortcut(byval it as Fl_Menu_Item ptr) as long
//' This is designed to be called by a widgets handle() method in response to a FL_SHORTCUT event.
//declare function Fl_Menu_ItemTestShortcut(byval it as Fl_Menu_Item ptr) as Fl_Menu_Item ptr
//' Size of the menu starting from this menu item.
//declare function Fl_Menu_ItemSize(byval it as Fl_Menu_Item ptr) as long
//' Returns true if either FL_SUBMENU or FL_SUBMENU_POINTER is on in the flags.
//declare function Fl_Menu_ItemSubmenu(byval it as Fl_Menu_Item ptr) as long
//' Sets/Gets the user data argument that is sent to the callback function. 
//declare sub      Fl_Menu_ItemSetUserData(byval it as Fl_Menu_Item ptr, byval userdata as any ptr)
//declare function Fl_Menu_ItemGetUserData(byval it as Fl_Menu_Item ptr) as any ptr
//' Returns the current value of the check or radio item. 
//declare function Fl_Menu_ItemValue(byval it as Fl_Menu_Item ptr) as long
//' Gets the visibility of an item.
//declare function Fl_Menu_ItemVisible(byval it as Fl_Menu_Item ptr) as long



	//'######################################
	//'# class Fl_Menu_Bar extends Fl_Menu_ #
	//'######################################
	//DeclareEx(Fl_Menu_Bar)
	//declare function Fl_Menu_BarNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Menu_Bar ptr
Fl_Menu_Bar* Fl_Menu_BarNew(long x, long y, long w, long h, const char *label);
//declare sub      Fl_Menu_BarDelete(byref mb as Fl_Menu_Bar ptr)

//declare function Fl_Menu_BarHandle(byval mb as Fl_Menu_Bar ptr, byval event as FL_EVENT) as long



	//'####################################
	//'# class Fl_Menu_ extends Fl_Widget #
	//'####################################
	//' see also: https://www.fltk.org/doc-1.3/classFl__Menu__.html
	//' Adds a new menu item. 
	//declare function Fl_Menu_Add (byval m_ as Fl_Menu_ ptr, byval label as const zstring ptr, byval shortcut as long=0, byval cb as Fl_Callback=0, byval userdata as any ptr=0, byval flag as long=0) as long
long Fl_Menu_Add(Fl_Menu *mn, const char *label, long shortcut, Fl_Callback cb, void *userdata, long flag);

//declare function Fl_Menu_Add2(byval m_ as Fl_Menu_ ptr, byval label as const zstring ptr, byval shortcut as const zstring ptr=0, byval cb as Fl_Callback=0, byval userdata as any ptr=0, byval flag as long=0) as long
//declare function Fl_Menu_Add3(byval m_ as Fl_Menu_ ptr, byval label as const zstring ptr) as long
//' This returns the number of Fl_Menu_Item structures 
//' that make up the menu, correctly counting submenus.
//declare function Fl_Menu_GetSize(byval m_ as Fl_Menu_ ptr) as long
//' Set the array pointer to null, indicating a zero-length menu.
//declare sub      Fl_Menu_Clear(byval m_ as Fl_Menu_ ptr)
//' Clears the specified submenu pointed to by index of all menu items.
//declare function Fl_Menu_ClearSubmenu(byval m_ as Fl_Menu_ ptr, byval index as long) as long
//' Sets the menu array pointer with a copy of m_ that will be automatically deleted.
//declare sub      Fl_Menu_Copy(byval m_ as Fl_Menu_ ptr, byval mi as Fl_Menu_Item ptr, byval userdata as any ptr=0)
//' This box type is used to surround the currently-selected items in the menus.
//declare sub      Fl_Menu_SetDownBox(byval m_ as Fl_Menu_ ptr, byval bt as FL_BOXTYPE)
//declare function Fl_Menu_GetDownBox(byval m_ as Fl_Menu_ ptr) as FL_BOXTYPE
//' Seletion color
//declare sub      Fl_Menu_SetDownColor(byval m_ as Fl_Menu_ ptr, byval c as Fl_COLOR)
//declare function Fl_Menu_GetDownColor(byval m_ as Fl_Menu_ ptr) as Fl_COLOR
//' Find the menu item index for a given menu pathname, such as "Edit/Copy".
//declare function Fl_Menu_FindIndexByName(byval m_ as Fl_Menu_ ptr, byval name_ as const zstring ptr) as long
//' Find the index into the menu array for a given item.
//declare function Fl_Menu_FindIndexByItem(byval m_ as Fl_Menu_ ptr, byval item as Fl_Menu_Item ptr) as long
//' Find the index into the menu array for a given callback cb.
//declare function Fl_Menu_FindIndexByCallback(byval m_ as Fl_Menu_ ptr, byval cb as Fl_Callback) as long
//' Find the menu item for a given menu pathname, such as "Edit/Copy". 
//declare function Fl_Menu_FindItemByName(byval m_ as Fl_Menu_ ptr, byval name_ as const zstring ptr) as Fl_Menu_Item ptr
//' Find the menu item for the given callback cb
//declare function Fl_Menu_FindItemByCallback(byval m_ as Fl_Menu_ ptr, byval cb as Fl_Callback) as Fl_Menu_Item ptr
//' Make the shortcuts for this menu work no matter what window has the focus when you type it.
//declare sub      Fl_Menu_Global(byval m_ as Fl_Menu_ ptr)
//' Inserts a new menu item at the specified index position.
//' see at: https://www.fltk.org/doc-1.3/classFl__Menu__.html#a4a6d21b279e679a93b13eee2534f9f64
//declare function Fl_Menu_Insert (byval m_ as Fl_Menu_ ptr, byval index as long, byval label as const zstring ptr, byval shortcut as const zstring ptr=0, byval cb as Fl_Callback=0, byval userdata as any ptr=0, byval flag as long=0) as long
//declare function Fl_Menu_Insert2(byval m_ as Fl_Menu_ ptr, byval index as long, byval label as const zstring ptr, byval shortcut as long          =0, byval cb as Fl_Callback=0, byval userdata as any ptr=0, byval flag as long=0) as long
//' Get the menu 'pathname' for the specified menuitem.
//declare function Fl_Menu_ItemPathName(byval m_ as Fl_Menu_ ptr, byval name_ as zstring ptr, byval namelen as long, byval item as Fl_Menu_Item ptr=0) as long
	//' Set/Get a pointer to the array of Fl_Menu_Items.
	//declare sub      Fl_Menu_SetMenu(byval m_ as Fl_Menu_ ptr, byval item as Fl_Menu_Item ptr)
void Fl_Menu_SetMenu( Fl_Menu  *menu_, Fl_Menu_Item *item);
	//declare function Fl_Menu_GetMenu(byval m_ as Fl_Menu_ ptr) as Fl_Menu_Item ptr
Fl_Menu_Item * Fl_Menu_GetMenu(Fl_Menu *menu_);
//' Set/Get the flags of item index.
	//declare sub      Fl_Menu_SetMode(byval m_ as Fl_Menu_ ptr, byval index as long, byval flag as long)
void Fl_Menu_SetMode(Fl_Menu *menu_, long _index, long _flag);
//declare function Fl_Menu_GetMode(byval m_ as Fl_Menu_ ptr, byval index as long) as long
//' Returns a pointer to the last menu item that was picked.
//declare function Fl_Menu_MValue(byval m_ as Fl_Menu_ ptr) as Fl_Menu_Item ptr
//' When user picks a menu item, call this.
//declare function Fl_Menu_Picked(byval m_ as Fl_Menu_ ptr, byval item as Fl_Menu_Item ptr) as Fl_Menu_Item ptr
//' Deletes item from the menu. 
//declare sub      Fl_Menu_Remove(byval m_ as Fl_Menu_ ptr, byval index as long)
//' Changes the text of item. 
//declare sub      Fl_Menu_Replace(byval m_ as Fl_Menu_ ptr, byval index as long, byval label as const zstring ptr)
//' Changes the shortcut of item 
//declare sub      Fl_Menu_Shortcut(byval m_ as Fl_Menu_ ptr, byval index as long, byval shortcut as long)

//declare sub      Fl_Menu_SetSize(byval m_ as Fl_Menu_ ptr, byval w as long, byval h as long)

//' Returns the menu item with the entered shortcut (key value).
//declare function Fl_Menu_TestShortcut(byval m_ as Fl_Menu_ ptr) as Fl_Menu_Item ptr
//' Returns the title of the last item chosen.
//declare function Fl_Menu_Text(byval m_ as Fl_Menu_ ptr) as const zstring ptr
	//' Returns the title of item by index.
	//declare function Fl_Menu_TextByIndex(byval m_ as Fl_Menu_ ptr, byval index as long) as const zstring ptr
const char * Fl_Menu_TextByIndex(Fl_Menu *menu_, long index);
//' Set/Get the current color of menu item labels
//declare sub      Fl_Menu_SetTextColor(byval m_ as Fl_Menu_ ptr, byval c as Fl_COLOR)
//declare function Fl_Menu_GetTextColor(byval m_ as Fl_Menu_ ptr) as Fl_COLOR
//' Set/Get the current font of menu item labels. 
//declare sub      Fl_Menu_SetTextFont(byval m_ as Fl_Menu_ ptr, byval f as FL_FONT)
//declare function Fl_Menu_GetTextFont(byval m_ as Fl_Menu_ ptr) as FL_FONT
//' Set/Get the font size of menu item labels.
//declare sub      Fl_Menu_SetTextSize(byval m_ as Fl_Menu_ ptr, byval fs as FL_FONTSIZE)
//declare function Fl_Menu_GetTextSize(byval m_ as Fl_Menu_ ptr) as FL_FONTSIZE
//' Returns the index into menu() of the last item chosen by the user. 
//declare function Fl_Menu_GetValue        alias "Fl_Menu_Value"        (byval m_ as Fl_Menu_ ptr) as long
//' The value is the index into menu() of the last item chosen by the user.
//declare function Fl_Menu_GetValueByItem  alias "Fl_Menu_ValueByItem"  (byval m_ as Fl_Menu_ ptr, byval m as Fl_Menu_Item ptr) as long
//' The value is the index into menu() of the last item chosen by the user.
//declare function Fl_Menu_GetValueByIndex alias "Fl_Menu_ValueByIndex" (byval m_ as Fl_Menu_ ptr, byval index as long) as long

	//'##################################
	//'# class Fl_Tabs extends Fl_Group #
	//'##################################
	//DeclareEx(Fl_Tabs)
	//' Creates a new Fl_Tabs widget using the given position, size, and label string.
	//declare function Fl_TabsNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Tabs ptr
Fl_Tabs* Fl_TabsNew(long x, long y, long w, long h, const char *label);
//declare sub      Fl_TabsdDelete(byref tbs as Fl_Tabs ptr)
//declare function Fl_TabsHandle(byval tbs as Fl_Tabs ptr, byval event as FL_EVENT) as long
//' Returns the position and size available to be used by its children.
//declare sub      Fl_TabsClientArea(byval tbs as Fl_Tabs ptr, byref rx as long, byref ry as long, byref rw as long, byref rh as long, byval tabh as long=0)
//' This is called by the tab widget's handle() method to set the tab group widget the user last FL_PUSH'ed on.
//declare function Fl_TabsSetPush(byval tbs as Fl_Tabs ptr, byval wgt as Fl_Widget ptr) as long
//' Returns the tab group for the tab the user has currently down-clicked on and remains over until FL_RELEASE.
//declare function Fl_TabsGetPush(byval tbs as Fl_Tabs ptr) as Fl_Widget ptr
//' Sets the widget to become the current visible widget/tab.
//declare function Fl_TabsSetValue(byval tbs as Fl_Tabs ptr, byval wgt as Fl_Widget ptr) as long
//' Gets the currently visible widget/tab.
//declare function Fl_TabsGetValue(byval tbs as Fl_Tabs ptr) as Fl_Widget ptr
//' Return the widget of the tab the user clicked on at event_x / event_y.
//declare function Fl_TabsWhich(byval tbs as Fl_Tabs ptr, byval event_x as long, byval event_y as long) as Fl_Widget ptr
#define Fl_TabsEnd  Fl_GroupEnd
#define Fl_TabNew   Fl_GroupNew
#define Fl_TabBegin Fl_GroupBegin
#define Fl_TabEnd   Fl_GroupEnd

	//'####################################
	//'# class Fl_Group extends Fl_Widget #
	//'####################################
	//DeclareEx(Fl_Group)
	//' Creates a new Fl_Group widget using the given position, size, and label string.
	//declare function Fl_GroupNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Group ptr
Fl_Group* Fl_GroupNew(long x, long y, long w, long h, const char *label);
//declare sub      Fl_GroupDelete(byref grp as Fl_Group ptr)
//' Handles the specified event
//declare function Fl_GroupHandle(byval grp as Fl_Group ptr, byval ev as FL_EVENT) as long
//' The widget is removed from its current group (if any) and then added to the end of this group. 
//declare sub      Fl_GroupAdd(byval grp as Fl_Group ptr, byval wgt as Fl_Widget ptr)
//' Returns an Fl_Group pointer if this widget is an Fl_Group
//declare function Fl_GroupAsGroup(byval grp as Fl_Widget ptr) as Fl_Group ptr
//' Sets the current group so you can build the widget tree by just constructing the widgets.
//declare sub      Fl_GroupBegin(byval grp as Fl_Group ptr)
	//declare sub      Fl_GroupEnd(byval grp as Fl_Group ptr)
void Fl_GroupEnd( Fl_Group *grp);
//' Returns how many child widgets the group has. 
//declare function Fl_GroupChildren(byval grp as Fl_Group ptr) as long
//' Returns a pointer to the children.
//declare function Fl_GroupChild(byval grp as Fl_Group ptr, byval childIndex as long) as Fl_Widget ptr
//' Returns a pointer to the array of all children. 
//declare function Fl_GroupArray(byval grp as Fl_Group ptr) as Fl_Widget ptr ptr
//declare function Fl_GroupConstArray alias "Fl_GroupArray2" (byval grp as Fl_Group ptr) as const Fl_Widget ptr ptr
//declare function Fl_GroupArray2(byval grp as Fl_Group ptr) as const Fl_Widget ptr ptr
//' Deletes all child widgets from memory recursively.
//declare sub      Fl_GroupClear(byval grp as Fl_Group ptr)
//' Controls whether the group widget clips the drawing of child widgets to its bounding box
//declare sub      Fl_GroupSetClipChildren(byval grp as Fl_Group ptr, byval clip as long)
//' Returns the current clipping mode
//declare function Fl_GroupGetClipChildren(byval grp as Fl_Group ptr) as long
//' Searches the child array for the widget and returns the index
//declare function Fl_GroupFind(byval grp as Fl_Group ptr, byval wgt as const Fl_Widget ptr) as long
//' Resets the internal array of widget sizes and positions.
//declare sub      Fl_GroupInitSizes(byval grp as Fl_Group ptr)
//' Resizes the Fl_Group widget and all of its children
//declare sub      Fl_GroupResize(byval grp as Fl_Group ptr, byval x as long, byval y as long, byval w as long, byval h as long)
//' The widget is removed from its current group (if any) and then inserted into this group.
//declare sub      Fl_GroupInsert(byval grp as Fl_Group ptr, byref widget as Fl_Widget ptr, byval before as Fl_Widget ptr)
//declare sub      Fl_GroupInsert2(byval grp as Fl_Group ptr, byref widget as Fl_Widget ptr, byval childIndex as long)
//' Removes the widget at index from the group but does not delete it.
//declare sub      Fl_GroupRemove (byval grp as Fl_Group ptr, byval childIndex as long)
//declare sub      Fl_GroupRemove2(byval grp as Fl_Group ptr, byval childWgt as Fl_Widget ptr)
	//' The resizable widget defines the resizing box for the group.
	//declare sub      Fl_GroupSetResizable(byval grp as Fl_Group ptr, byval wgt as Fl_Widget ptr)
void Fl_GroupSetResizable(Fl_Group *grp, Fl_Widget *wgt);
//declare function Fl_GroupGetResizable(byval grp as Fl_Group ptr) as Fl_Widget ptr
//' Aaternative form
//#define Fl_GroupResizeable Fl_GroupSetResizable

	//'#########################################
	//'# class Fl_Menu_Button extends Fl_Menu_ #
	//'#########################################
	//DeclareEx(Fl_Menu_Button)
	//declare function Fl_Menu_ButtonNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Menu_Button ptr
Fl_Menu_Button* Fl_Menu_ButtonNew(long x, long y, long w, long h, const char *label);
	//declare sub      Fl_Menu_ButtonDelete(byref mb as Fl_Menu_Button ptr)
void Fl_Menu_ButtonDelete(Fl_Menu_Button *mb);
//declare function Fl_Menu_ButtonHandle(byval mb as Fl_Menu_Button ptr, byval event as FL_EVENT) as long

//declare function Fl_Menu_ButtonPopup(byval mb as Fl_Menu_Button ptr) as Fl_Menu_Item ptr


	//'################
	//'# FLTK Drawing #
	//'################
//' Checks whether platform supports true alpha blending for RGBA images. 
//declare function DrawCanDoAlphaBlending as long

	//declare sub      DrawSetColor(byval c as Fl_COLOR)
void DrawSetColor(Fl_Color clr);

//declare sub      DrawSetRGBColor(byval r as ubyte, byval g as ubyte, byval b as ubyte)

//declare function DrawGetColor() as Fl_COLOR
//' Pushes an empty clip region onto the stack so nothing will be clipped. 
//declare sub      DrawPushNoClip()
//' Intersects the current clip region with a rectangle and pushes this new region onto the stack. 
	//declare sub      DrawPushClip(byval x as long, byval y as long, byval w as long, byval h as long)
void DrawPushClip(long x, long y, long w, long h);
	//' Restores the previous clip region.
	//' !!! You must call DrawPopClip() once for every time you call DrawPushClip(), DrawPushNoClip(). !!!
	//declare sub      DrawPopClip()
void DrawPopClip();
//' Undoes any clobbering of clip done by your program. 
//declare sub      DrawRestoreClip()
//' Does the rectangle intersect the current clip region? 
//declare function DrawNotClipped(byval x as long, byval y as long, byval w as long, byval h as long) as long
//' Intersects the rectangle with the current clip region ? 
//' and returns the bounding box of the result. 
//declare function DrawClipBox(byval   x as long, byval   y as long, byval   w as long, byval   h as long, _
                             //byref bbx as long, byref bby as long, byref bbw as long, byref bbh as long) as long

//' dashes: A pointer to an array of dash lengths, measured in pixels. 
//' The first location is how long to draw a solid portion, the next is how long to draw the gap, then the solid, etc. 
//' It is terminated with a zero-length entry. A NULL pointer or a zero-length array results in a solid line. 
//' !!! Odd array sizes are not supported and result in undefined behavior. !!!
//declare sub      DrawSetLineStyle(byval style as Fl_LINE_STYLE, byval w as long=0, byval dashes as zstring ptr=0)

		//' ########################
		//' # fast integer drawing #
		//' ########################
		//' see: fltk-tools.bi also
//' Draw a single pixel at the given coordinates with current color.
//declare sub      DrawPoint(byval x as long, byval y as long)
//' Draw a 1-pixel border inside this bounding box.
//declare sub      DrawRect(byval x as long, byval y as long, byval w as long, byval h as long)

//declare sub      DrawRectColor(byval x as long, byval y as long, byval w as long, byval h as long, byval c as Fl_COLOR)
//' Color a rectangle that exactly fills the given bounding box.
	//declare sub      DrawRectFill        (byval x as long, byval y as long, byval w as long, byval h as long)
void DrawRectFill(long x, long y, long w, long h);
	//declare sub      DrawRectFillColor   (byval x as long, byval y as long, byval w as long, byval h as long, byval c as Fl_COLOR)
void DrawRectFillColor(long x, long y, long w, long h, Fl_Color cl);

//declare sub      DrawRectFillRGBColor(byval x as long, byval y as long, byval w as long, byval h as long, byval r as ubyte, byval g as ubyte, byval b as ubyte)

//declare sub      DrawOverlayClear

//declare sub      DrawOverlayRect(byval x as long, byval y as long, byval w as long, byval h as long)
//' Draws a series of line segments around the given box.
//' The string s must contain groups of 4 letters which specify one of 24 standard grayscale values, where 'A' is black and 'X' is white. 
//' The order of each set of 4 characters is: top, left, bottom, right. 
//' The result of calling fl_frame() with a string that is not a multiple of 4 characters in length is undefined. 
//' The only difference between this function and fl_frame2() is the order of the line segments. 
//declare sub      DrawFrame (byval s as const zstring ptr, byval x as long, byval y as long, byval w as long, byval h as long)
//' The order of each set of 4 characters is: bottom, right, top, left.
//declare sub      DrawFrame2(byval s as const zstring ptr, byval x as long, byval y as long, byval w as long, byval h as long)
//' Draws a box using given type, position, size and color. 
//declare sub      DrawBox(byval bt as FL_BOXTYPE, byval x as long, byval y as long, byval w as long, byval h as long, byval c as Fl_COLOR)
//' Draw one or two lines between the given points.
//declare sub      DrawLine (byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long)

//declare sub      DrawLine2(byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long, byval x3 as long, byval y3 as long)
//' Outline a 3 or 4-sided polygon with lines.
//declare sub      DrawLoop (byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long, byval x3 as long, byval y3 as long)

//declare sub      DrawLoop2(byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long, byval x3 as long, byval y3 as long, byval x4 as long, byval y4 as long)
//' Fill a 3 or 4-sided filled polygon. The polygon must be convex.
//declare sub      DrawPolygon (byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long, byval x3 as long, byval y3 as long)

//declare sub      DrawPolygon2(byval x1 as long, byval y1 as long, byval x2 as long, byval y2 as long, byval x3 as long, byval y3 as long, byval x4 as long, byval y4 as long)
//' Draw horizontal and vertical lines. A horizontal line is drawn first, then a vertical, then a horizontal.
//declare sub      DrawXYLine(byval x as long, byval y as long, byval x1 as long)

//declare sub      DrawXYLine2(byval x as long, byval y as long, byval x1 as long, byval y1 as long)

//declare sub      DrawXYLine3(byval x as long, byval y as long, byval x1 as long, byval y1 as long, byval x2 as long)
//' Draw vertical and horizontal lines. A vertical line is drawn first, then a horizontal, then a vertical.
//declare sub      DrawYXLine(byval x as long, byval y as long, byval y1 as long)

//declare sub      DrawYXLine2(byval x as long, byval y as long, byval y1 as long, byval x2 as long)

//declare sub      DrawYXLine3(byval x as long, byval y as long, byval y1 as long, byval x2 as long, byval y2 as long)
//' DrawArc() draws a series of lines to approximate the arc.
//declare sub      DrawArc(byval x as long, byval y as long, byval w as long, byval h as long, byval a1 as double, byval a2 as double)
//' Draw filled ellipse sections using long coordinates.
//' Like DrawArc(), but DrawPie() draws a filled-in pie slice. 
//' This slice may extend outside the line drawn by DrawArc() to avoid this use w - 1 and h - 1. 
//declare sub      DrawPie(byval x as long, byval y as long, byval w as long, byval h as long, byval a1 as double, byval a2 as double)

		//' ###########################
		//' # complex precise drawing #
		//' ###########################
//' Saves the current transformation matrix on the stack.
//' (The maximum depth of the stack is 32)
//declare sub      DrawPushMatrix()
//' Restores the current transformation matrix from the stack. 
//declare sub      DrawPopMatrix()
//' Concatenates another transformation onto the current [m]atrix one. 
//' matrix new
//'  new.a = a*current.a + b*current.c;
//'  new.b = a*current.b + b*current.d;
//'  new.c = c*current.a + d*current.c;
//'  new.d = c*current.b + d*current.d;
//'  new.x = x*current.a + y*current.c + current.x;
//'  new.y = x*current.b + y*current.d + current.y;
//'  cuurent = new;
//declare sub      DrawMultMatrix(byval a as double, byval b as double, byval c as double, byval d as double, byval x as double, byval y as double)
//' Concatenates scaling transformation onto the current matrix.
//' internal mult_matrix(s,0,0,s,0,0)
//declare sub      DrawScale(byval s as double)
//' internal mult_matrix(x,0,0,y,0,0)
//declare sub      DrawScaleXY(byval sx as double, byval sy as double)
//' Concatenates rotation transformation onto the current matrix. 
//' internal mult_matrix(c,-s,s,c,0,0);
//declare sub      DrawRotate(byval r as double)
//' Concatenates translation transformation onto the current one
//' internal  mult_matrix(1,0,0,1,tx,ty)
//declare sub      DrawTranslate(byval tx as double, byval ty as double)

//declare sub      DrawArc2(byval x as double, byval y as double, byval r as double, byval start as double, byval end_ as double)
//' DrawCircle() is equivalent to DrawArc2(0,360) but may be faster
//declare sub      DrawCircle(byval x as double, byval y as double, byval r as double)

//' Add a series of points on a Bezier curve to the path.
//declare sub      DrawCurve(byval x0 as double, byval y0 as double, byval x1 as double, byval y1 as double, byval x2 as double, byval y2 as double, byval x3 as double, byval y3 as double)

//' drawing a list of points. 
//declare sub      DrawBeginPoints()
//declare sub      DrawEndPoints()
//' drawing a list of lines. 
//declare sub      DrawBeginLine()
//declare sub      DrawEndLine()
//' drawing a closed sequence of lines. 
//declare sub      DrawBeginLoop()
//declare sub      DrawEndLoop()
//' drawing a convex filled polygon. 
//declare sub      DrawBeginPolygon()
//declare sub      DrawEndPolygon()
//' drawing a complex filled polygon. (can be concave)
//declare sub      DrawBeginComplexPolygon()
//declare sub      DrawEndComplexPolygon()
//' Adds a single vertex to the current path. 
//' xfinal=x* cos(zrot) + y*sin(zrot) + xPos
//' yfinal=x*-sin(zrot) + y*cos(zrot) + yPos
//declare sub      DrawVertex(byval x as double, byval y as double)
//' Adds a single vertex to the current path without further transformations. 
//declare sub      DrawTransformedVertex(byval xf as double, byval yf as double)
//' Transforms coordinate using the current transformation matrix. (x* cos(zrot) + y*sin(zrot) + xPos)
//declare function DrawTransformX(byval x as double, byval y as double) as double
//' Transforms coordinate using the current transformation matrix. (x*-sin(zrot) + y*cos(zrot) + yPos)
//declare function DrawTransformY(byval x as double, byval y as double) as double
//' Transforms distance using current transformation matrix.  (x* cos(zrot) + y*sin(zrot))
//declare function DrawTransformDX(byval x as double, byval y as double) as double
//' Transforms distance using current transformation matrix.  (x*-sin(zrot)+ y*cos(zrot))
//declare function DrawTransformDY(byval x as double, byval y as double) as double

		//' ################
		//' # text drawing #
		//' ################
//declare sub      DrawSetFont(byval font as FL_FONT, byval size as FL_FONTSIZE)
//declare function DrawGetFont() as FL_FONT

//declare function DrawHeight(byval font as FL_FONT, byval size as FL_FONTSIZE) as long

//declare function DrawGetFontSize() as FL_FONTSIZE

//declare function DrawGetFontHeight() as long

//declare function DrawGetFontDescent() as long

//declare function DrawGetStrWidth(byval txt as const zstring ptr) as long

//declare function DrawGetStrWidth2(byval txt as const zstring ptr, byval nChars as long) as long

//declare function DrawGetCharWidth(byval char as ulong) as long

//declare sub      DrawStrExtents (byval txt as const zstring ptr, byref dx as long, byref dy as long, byref w as long, byref h as long)

//declare sub      DrawStrExtents2(byval txt as const zstring ptr, byval nChars as long, byref dx as long, byref dy as long, byref w as long, byref h as long)

//declare sub      DrawStrMeasure (byval txt as const zstring ptr, byref x as long, byref y as long, byval draw_symbols as long = 1)

//declare sub      DrawStr        (byval txt as const zstring ptr, byval x as long, byval y as long)

//declare sub      DrawStr2       (byval txt as const zstring ptr, byval nChars as long, byval x as long, byval y as long)

//declare sub      DrawStrRightToLeft(byval txt as const zstring ptr, byval nChars as long, byval x as long, byval y as long)

//declare sub      DrawStrRot        (byval angle as long, byval txt as const zstring ptr, byval x as long, byval y as long)

//declare sub      DrawStrRot2       (byval angle as long, byval txt as const zstring ptr, byval nChars as long, byval x as long, byval y as long)

//declare sub      DrawStrBox        (byval txt as const zstring ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval aligh as FL_ALIGN=0, byval img as Fl_Image ptr=0, byval draw_symbols as long = 1)

//declare function DrawLatin1ToLocal(byval txt as const zstring ptr, byval nChars as long=-1) as const zstring ptr

//declare function DrawLocalToLatin1(byval txt as const zstring ptr, byval nChars as long=-1) as const zstring ptr

		//' #################
		//' # image drawing #
		//' #################
//' Draws an 8-bit per color RGB or luminance image. 
//declare sub      DrawImage    (byval buf as const any ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval BytesPerPixel as long=3, byval pitch as long=0)
//' Draws a gray-scale (1 channel) image. 
//declare sub      DrawImageMono(byval buf as const any ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval BytesPerPixel as long=1, byval pitch as long=0)

//' Draws an image using a callback function to generate image data.
//declare sub      DrawImageCallback    (byval cb as Fl_Draw_Image_Cb, byval pUserData as any ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval BytesPerPixel as long)
//' Draws a gray-scale image using a callback function to generate image data. 
//declare sub      DrawImageMonoCallback(byval cb as Fl_Draw_Image_Cb, byval pUserData as any ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval BytesPerPixel as long)

//' Reads an RGB(A) image from the current window
//' p    pixel buffer, or NULL to allocate one
//' X,Y  position of top-left of image to read
//' W,H  width and height of image to read
//' alphavalue value for image (0 for none)
//' Returns:  pointer to pixel buffer, or NULL if allocation failed.. 
//declare function DrawReadImage(byval p as any ptr=0, _
                               //byval x as long, byval y as long, _
                               //byval w as long, byval h as long, _
                               //byval alphavalue as long=0) as any ptr
//' Draw XPM image data, with the top-left corner at the given position. 
//declare function DrawPixmap(byval pdata as ubyte ptr const ptr, byval x as long, byval y as long, byval c as Fl_COLOR=FL_GRAY) as long

//declare function DrawConstPixmap alias "DrawPixmap2" (byval pdata as ubyte ptr const ptr, byval x as long, byval y as long, byval c as Fl_COLOR=FL_GRAY) as long

//declare function DrawPixmap2(byval cdata as const zstring ptr const ptr, byval x as long, byval y as long, byval c as Fl_COLOR=FL_GRAY) as long
//' Get the dimensions of a pixmap.
//declare function DrawMeasurePixmap(byval pdata as zstring ptr const ptr, byref w as long, byref h as long) as long

//declare function DrawMeasureConstPixmap alias "DrawMeasurePixmap2" (byval cdata as const zstring ptr const ptr, byref w as long, byref h as long) as long

//declare function DrawMeasurePixmap2(byval cdata as const zstring ptr const ptr, byref w as long, byref h as long) as long


//' I don't know why but it's defined in "Fl_Draw.H"
//declare function Fl_GetShortcutLabel(byval shortcut as long) as const zstring ptr

//declare function Fl_GetDrawShortcutFlag as ubyte

//declare sub      Fl_SetDrawShortcutFlag(byval flag as ubyte)


		//' ############
		//' # Fl Color #
		//' ############
//' Makes FLTK use its own colormap.
//declare sub      Fl_OwnColormap()

//declare sub      Fl_GetSystemColors()
//' Changes Fl_COLOR(FL_FOREGROUND_COLOR).
//declare sub      Fl_Foreground(byval r as ubyte, byval g as ubyte, byval b as ubyte)
//' Frees the specified color from the colormap, if applicable.
//declare sub      Fl_FreeColor (byval i as Fl_COLOR, byval overlay as long=0)

//' Returns the RGB values for the given FLTK color. 
//declare sub      Fl_GetColor(byval i as Fl_COLOR, byref r as ubyte, byref g as ubyte, byref b as ubyte)
//declare function Fl_GetColor2(byval i as Fl_COLOR) as ulong
//' Sets an entry in the Fl_COLOR index table.
//declare sub      Fl_SetColor (byval n as Fl_COLOR, byval c as ulong)
//declare sub      Fl_SetColor2(byval n as Fl_COLOR, byval r as ubyte, byval g as ubyte, byval b as ubyte)

//' Returns Fl_COLOR value from rgb triples
	//declare function Fl_RGB_Color(byval r as ubyte, byval g as ubyte, byval b as ubyte) as Fl_COLOR
Fl_Color Fl_RGB_Color(unsigned char R, unsigned char G, unsigned char B);
//' Returns a gray Fl_COLOR value
//declare function Fl_Gray_Color(byval gray as ubyte) as Fl_COLOR
//' Returns Fl_COLOR cube value from rgb triples
//declare function Fl_Color_Cube(byval r as long, byval g as long, byval b as long) as Fl_COLOR
//' Returns the inactive, dimmed version of the given color. 
//declare function Fl_Inactive(byval c as Fl_COLOR) as Fl_COLOR
//' Returns a color that contrasts with the background color.
//declare function Fl_Contrast(byval fg as Fl_COLOR, byval bg as Fl_COLOR) as Fl_COLOR
//' Returns the weighted average color between the two given colors.
//declare function Fl_Color_Average(byval c1 as Fl_COLOR, byval c2 as Fl_COLOR, byval weight as single) as Fl_COLOR
//' Changes Fl_COLOR(FL_BACKGROUND_COLOR) to the given color, and changes the gray ramp from 32 to 56 to black to white. 
//declare sub      Fl_Background(byval r as ubyte, byval g as ubyte, byval b as ubyte)
//' Changes the alternative background color. 
//declare sub      Fl_Background2(byval r as ubyte, byval g as ubyte, byval b as ubyte)




		//'################################ 
		//'# class Fl_Native_File_Chooser #
		//'################################
		//declare function Fl_Native_File_ChooserNew(byval typ as FL_NFC_TYPE=NFC_BROWSE_FILE) as Fl_Native_File_Chooser ptr
Fl_Native_File_Chooser * Fl_Native_File_ChooserNew(FL_NFC_TYPE _type_);
	//declare sub      Fl_Native_File_ChooserDelete(byref nfc as Fl_Native_File_Chooser ptr)
void Fl_Native_File_ChooserDelete(Fl_Native_File_Chooser *nfc);

//declare function Fl_Native_File_ChooserCount(byval nfc as Fl_Native_File_Chooser ptr) as long

	//declare sub      Fl_Native_File_ChooserSetDirectory(byval nfc as Fl_Native_File_Chooser ptr, byval d as const zstring ptr)
void Fl_Native_File_ChooserSetDirectory(Fl_Native_File_Chooser *nfc, const char *d);
	//declare function Fl_Native_File_ChooserGetDirectory(byval nfc as Fl_Native_File_Chooser ptr) as zstring ptr
const char* Fl_Native_File_ChooserGetDirectory(Fl_Native_File_Chooser *nfc);

//declare function Fl_Native_File_ChooserErrorMsg(byval nfc as Fl_Native_File_Chooser ptr) as const zstring ptr

	//declare sub      Fl_Native_File_ChooserSetFilter(byval nfc as Fl_Native_File_Chooser ptr, byval f as const zstring ptr)
void Fl_Native_File_ChooserSetFilter(Fl_Native_File_Chooser *nfc, const char *f);
//declare function Fl_Native_File_ChooserGetFilter(byval nfc as Fl_Native_File_Chooser ptr) as const zstring ptr

	//declare function Fl_Native_File_ChooserFilename(byval nfc as Fl_Native_File_Chooser ptr) as const zstring ptr
const char* Fl_Native_File_ChooserFilename(Fl_Native_File_Chooser *nfc);

//declare function Fl_Native_File_ChooserGetFilename(byval nfc as Fl_Native_File_Chooser ptr, byval fileIndex as long) as const zstring ptr

//declare sub      Fl_Native_File_ChooserSetFilterValue(byval nfc as Fl_Native_File_Chooser ptr, byval value as long)

//declare function Fl_Native_File_ChooserGetFilterValue(byval nfc as Fl_Native_File_Chooser ptr) as long
	//declare sub      Fl_Native_File_ChooserSetOptions(byval nfc as Fl_Native_File_Chooser ptr, byval opt as FL_NFC_OPTION)
void Fl_Native_File_ChooserSetOptions(Fl_Native_File_Chooser *nfc, FL_NFC_OPTION opt);

//declare function Fl_Native_File_ChooserGetOptions(byval nfc as Fl_Native_File_Chooser ptr) as FL_NFC_OPTION

	//declare sub      Fl_Native_File_ChooserSetPresetFile(byval nfc as Fl_Native_File_Chooser ptr, byval file as const zstring ptr)
void Fl_Native_File_ChooserSetPresetFile(Fl_Native_File_Chooser *nfc, const char *fname);
//declare function Fl_Native_File_ChooserGetPresetFile(byval nfc as Fl_Native_File_Chooser ptr) as const zstring ptr

	//declare function Fl_Native_File_ChooserShow(byval nfc as Fl_Native_File_Chooser ptr) as long
long Fl_Native_File_ChooserShow(Fl_Native_File_Chooser *nfc);

	//declare sub      Fl_Native_File_ChooserSetTitle(byval nfc as Fl_Native_File_Chooser ptr, byval title as const zstring ptr)
void Fl_Native_File_ChooserSetTitle(Fl_Native_File_Chooser *nfc, const char *title);
//declare function Fl_Native_File_ChooserGetTitle(byval nfc as Fl_Native_File_Chooser ptr) as const zstring ptr

//declare sub      Fl_Native_File_ChooserSetType(byval nfc as Fl_Native_File_Chooser ptr, byval typ as FL_NFC_TYPE)
//declare function Fl_Native_File_ChooserGetType(byval nfc as Fl_Native_File_Chooser ptr) as FL_NFC_TYPE


		//'##################
		//'# common dialogs #
		//'##################
		//' see also: http://www.fltk.org/doc-1.3/group__group__comdlg.html
	//declare sub      flAlert(byval msg as const zstring ptr)
void flAlert(const char *msg);
//declare function flChoice(byval msg as const zstring ptr, byval btn1 as const zstring ptr, byval btn2 as const zstring ptr=0, byval btn3 as const zstring ptr=0) as long

	//declare sub      flBeep(byval t as FL_BEEP=FL_BEEP_DEFAULT)
void flBeep(Fl_Beep t);
//declare function flColorChooser(byval name_ as const zstring ptr, byref r as ubyte, byref g as ubyte, byref b as ubyte, byval cmode as FL_ColorChooserModes) as long
//declare function flColorChooser2(byval name_ as const zstring ptr, byref r as double, byref g as double, byref b as double, byval cmode as FL_ColorChooserModes) as long

//declare function flDirChooser(byval message as const zstring ptr, byval filename as const zstring ptr, byval relative_ as long) as zstring ptr

//declare function flFileChooser(byval message as const zstring ptr, byval path as const zstring ptr, byval filename as const zstring ptr, byval relative_ as long) as zstring ptr
//declare sub      flFileChooserCallback(byval cb as sub cdecl(byval file as const zstring ptr))
//declare sub      flFileChooserOkLabel(byval label as const zstring ptr)

//declare function flInput(byval fmt as const zstring ptr, byval defaultString as const zstring ptr) as const zstring ptr

	//declare sub      flMessage(byval txt as const zstring ptr)
void flMessage(const char *txt);
//declare sub      flMessageSetHotspot(byval enable as long)
//declare function flMessageGetHotspot() as long
//declare function flMessageIcon() as Fl_Widget ptr
	//declare sub      flMessageTitle(byval title as const zstring ptr)
void flMessageTitle(const char *title);
//declare sub      flMessageTitleDefault(byval title as const zstring ptr)

//declare function flPassword(byval fmt as const zstring ptr, byval defaultPassword as const zstring ptr) as const zstring ptr


		 //#########
		//' # event #
		//' #########
	//' Returns the last event that was processed. 
	//declare function Fl_EventNumber() as long
long Fl_EventNumber(void);
	//' Gets which particular mouse button caused the current event.
	//declare function Fl_EventButton() as long
long Fl_EventButton(void);
//' Returns non-zero if mouse button 1,2 or 3 is currently held down.
//declare function Fl_EventButton1() as long
//declare function Fl_EventButton2() as long
//declare function Fl_EventButton3() as long
//' Returns the mouse buttons state bits if non-zero, then at least one button is pressed now.
//declare function Fl_EventButtons() as long
//' Returns non zero if we had a double click event.
//declare function Fl_GetEventClicks() as long
//' Manually sets the number returned by Fl_GetEventClicks(). 
//declare sub      Fl_SetEventClicks(byval i as long)
//' Set a new event dispatch function.
//declare sub      Fl_SetEventDispatch(byval d as Fl_Event_Dispatch)
//' Return the current event dispatch function.
//declare function Fl_GetEventDispatch() as Fl_Event_Dispatch
//' Returns whether or not the mouse event is inside a given child widget.
//declare function Fl_EventInside(byval wgt as const Fl_Widget ptr) as long
//' Returns whether or not the mouse event is inside the given rectangle.
//declare function Fl_EventInside2(byval x as long, byval y as long, byval w as long, byval h as long) as long
//' Returns non-zero if the mouse has not moved far enough and not enough time has passed since 
	//' the last FL_PUSH or FL_KEYBOARD event for it to be considered a "drag" rather than a "click". 
	//declare function Fl_GetEventIsClick() as long
long Fl_GetEventIsClick(void);
//' Clears the value returned by Fl_GetEventIsClick(). 
//declare sub      Fl_SetEventIsClick(byval i as long)
	//' Gets which key on the keyboard was last pushed.
	//declare function Fl_EventKey() as long
long Fl_EventKey(void);
	//' Returns true if the given key was held down (or pressed) during the last event.
	//declare function Fl_EventKey2(byval key as long) as long
long Fl_EventKey2(long key);
	//' Returns the keycode of the last key event, regardless of the NumLock state.
	//declare function Fl_EventOriginalKey() as long
long Fl_EventOriginalKey(void);
	//' Returns non-zero if the Alt,Ctrl,Shift or Command key is pressed. 
	//declare function Fl_EventAlt() as long
long Fl_EventAlt(void);
	//declare function Fl_EventCtrl() as long
long Fl_EventCtrl(void);
	//declare function Fl_EventShift() as long
long Fl_EventShift(void);
	//declare function Fl_EventCommand() as long ' ctrl or metha on Mac
long Fl_EventCommand(void);
	//' This is a bitfield of what shift states were on and what mouse buttons 
	//' were held down during the most recent event. 
	//declare function Fl_EventState() as long
long Fl_EventState(void);
	//declare function Fl_EventState2(byval i as long) as long
long Fl_EventState2(long i);
//' Returns the length of the text in Fl_EventText(). 
//declare function Fl_EventLength() as long
//' Returns the text associated with the current event, including FL_EVENT_PASTE or FL_EVENT_DND_RELEASE events. 
//declare function Fl_EventText() as const zstring ptr
//' Returns the mouse position of the event relative to the Fl_Window it was passed to.
//declare function Fl_EventX() as long
//declare function Fl_EventY() as long
//' Returns the mouse position on the screen of the event.
//declare function Fl_EventXRoot() as long
//declare function Fl_EventYRoot() as long
//' Returns the current horizontal / vertical mouse scrolling associated with the FL_MOUSEWHEEL event. 
//declare function Fl_EventDX() as long
//declare function Fl_EventDY() as long
//' new
//' During an FL_PASTE event of non-textual data, returns a pointer to the pasted data.
//declare function Fl_EventClipboardData() as any ptr
//' Returns the type of the pasted data during an FL_PASTE event.
//' Fl_clipboard_plain_text ("text/plain") or Fl_clipboard_image ("image")
//declare function Fl_EventClipboardType() as const zstring ptr


	//' Returns true if the given key is held down now.
	//declare function Fl_GetKey(byval key as long) as long
long Fl_GetKey(long key);
//' Return where the mouse is on the screen by doing a round-trip query to the server. 
//declare sub      Fl_GetMouse(byref x as long, byref y as long)


		//' ##########
		//' # window #
		//' ##########
	//' Causes all the windows that need it to be redrawn and graphics forced out through the pipes. 
	//declare sub      Fl_Flush()
void Fl_Flush(void);
	//' Handle events from the window system. 
	//declare function Fl_Handle(byval event as FL_EVENT, byval win as Fl_Window ptr) as long
long Fl_Handle(Fl_Event ev, Fl_Window *win);
	//declare function Fl_Handle_(byval event as FL_EVENT, byval win as Fl_Window ptr) as long
long Fl_Handle_(Fl_Event ev, Fl_Window *win);
//' Returns the top-most modal() window currently shown. 
//declare function Fl_Modal as Fl_Window ptr
//' Returns the first top-level window in the list of shown() windows. 
//declare function Fl_GetFirstWindow as Fl_Window ptr
//' Sets the window that is returned by Fl_GetFirstWindow(). 
//declare sub      Fl_SetFirstWindow(byval win as Fl_Window ptr)
//' Returns the next top-level window in the list of shown() windows.
//declare function Fl_NextWindow(byval win as const Fl_Window ptr) as Fl_Window ptr
//' Returns the window that currently receives all events. 
//declare function Fl_GetGrab as Fl_Window ptr
//' Selects the window to grab.
//declare sub      Fl_SetGrab(byval win as Fl_Window ptr)
//' Releases the current grabbed window, equals Fl_SetGrab(0).
//declare sub      Fl_Release



		//'###################
		//'# static class Fl #
		//'###################
	//declare sub      Fl_Free(byref By_FLTK_Allocated_Pointer as any ptr)
void Fl_Free( void *By_FLTK_Allocated_Pointer);
#ifdef _WIN32
	//declare function Fl_Find(byval xid as any ptr) as Fl_Window ptr
Fl_Window * Fl_Find(void *xid);
	//declare function Fl_XID(byval win as const Fl_Window ptr) as any ptr
void * Fl_XID(  const Fl_Window *win);
#else
	//declare function Fl_Find(byval xid as ulong) as Fl_Window ptr
Fl_Window * Fl_Find(unsigned long xid);
	//declare function Fl_XID(byval win as const Fl_Window ptr) as ulong
unsigned long Fl_XID(const  Fl_Window *win);
#endif


		//' ######################
		//' # Fl_Timeout_Handler #
		//' ######################
//' Adds a one-shot timeout callback.
	//declare sub      Fl_AddTimeout   (byval t as double, byval h as Fl_Timeout_Handler, byval pArg as any ptr = 0)
void Fl_AddTimeout( double t, Fl_Timeout_Handler h, void *pArg);
//declare sub      Fl_RemoveTimeout(byval h as Fl_Timeout_Handler, byval pArg as any ptr = 0)
//declare function Fl_HasTimeout   (byval h as Fl_Timeout_Handler, byval pArg as any ptr = 0) as long
	//declare sub      Fl_RepeatTimeout(byval t as double, byval h as Fl_Timeout_Handler, byval pArg as any ptr = 0)
void Fl_RepeatTimeout(double t, Fl_Timeout_Handler h, void *pArg);

//' Default callback for window widgets.
//declare sub      Fl_DefaultAtclose(byval win as Fl_Window ptr, byval pArg as any ptr = 0)
//' For back compatibility, sets the void Fl_Fatal handler callback. 
//declare sub      Fl_SetAbort(byval h as Fl_Abort_Handler)
//' For back compatibility, sets the Fl_Atclose handler callback. 
//declare sub      Fl_SetAtclose(byval h as Fl_Atclose_Handler)


		//'##################################
		//'# class Fl_Canvas extends Fl_Box #
		//'##################################
	//declare function Fl_CanvasNew(byval x as long, byval y as long, byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Canvas ptr
Fl_Canvas * Fl_CanvasNew(long x, long y, long w, long h, const char *title);	
//declare sub      Fl_CanvasDelete         (byref can as Fl_Canvas ptr)
//declare function Fl_CanvasHandleBase     (byval can as Fl_Canvas ptr, byval event as FL_EVENT) as long
//declare sub      Fl_CanvasSetDestructorCB(byval can as Fl_Canvas ptr, byval cb as Fl_DestructorEx)
	//declare sub      Fl_CanvasSetDrawCB      (byval can as Fl_Canvas ptr, byval cb as Fl_CanvasDraw)
void Fl_CanvasSetDrawCB( Fl_Canvas *can, Fl_CanvasDraw cb);
//declare sub      Fl_CanvasSetHandleCB    (byval can as Fl_Canvas ptr, byval cb as Fl_HandleEx)
//declare sub      Fl_CanvasSetResizeCB    (byval can as Fl_Canvas ptr, byval cb as Fl_ResizeEx)



		//' ################
		//' # Widget Color #
		//' ################
//declare sub      Fl_WidgetSetColor(byval wgt as Fl_Widget ptr, byval bg as Fl_COLOR)
//declare function Fl_WidgetGetColor(byval wgt as Fl_Widget ptr) as Fl_COLOR

//declare sub      Fl_WidgetSetColorSel(byval wgt as Fl_Widget ptr, byval bg as Fl_COLOR, byval sel as Fl_COLOR)
//declare sub      Fl_WidgetSetSelectionColor(byval wgt as Fl_Widget ptr, byval c as Fl_COLOR)
//declare function Fl_WidgetGetSelectionColor(byval wgt as Fl_Widget ptr) as Fl_COLOR
//' will be removed use Set/GetSelectionColor in new apps.
//declare sub      Fl_WidgetSetColor2(byval wgt as Fl_Widget ptr, byval c as Fl_COLOR)
//declare function Fl_WidgetGetColor2(byval wgt as Fl_Widget ptr) as Fl_COLOR
 
//declare function Fl_WidgetContains(byval wgt as Fl_Widget ptr, byval other as const Fl_Widget ptr) as long
//' Sets the damage bits for the widget.
//declare sub      Fl_WidgetSetDamage(byval wgt as Fl_Widget ptr, byval c as ubyte)
//' Sets the damage bits for an area inside the widget.
//declare sub      Fl_WidgetSetDamage2(byval wgt as Fl_Widget ptr, byval c as ubyte, byval x as long, byval y as long, byval w as long, byval h as long)
//' Returns non-zero if draw() needs to be called. 
//declare function Fl_WidgetGetDamage(byval wgt as Fl_Widget ptr) as ubyte
//' Clears or sets the damage flags.
//declare sub      Fl_WidgetClearDamage(byval wgt as Fl_Widget ptr, byval c as ubyte=0)
//' Internal use only.
//declare function Fl_WidgetDamageResize(byval wgt as Fl_Widget ptr, byval x as long, byval y as long, byval w as long, byval h as long) as long
//' Gets/Sets the image that is used as part of the widget label.
//declare function Fl_WidgetGetDeimage(byval wgt as Fl_Widget ptr) as Fl_Image ptr
//declare sub      Fl_WidgetSetDeimage(byval wgt as Fl_Widget ptr, byval img as Fl_Image ptr)

//' Calls the widget callback.
//declare sub      Fl_WidgetDoCallback(byval wgt as Fl_Widget ptr)
//#define Fl_WidgetDoCallback0 Fl_WidgetDoCallback
//declare sub      Fl_WidgetDoCallback2(byval wgt as Fl_Widget ptr, byval other as Fl_Widget ptr, byval pArg as any ptr=0)
//#define Fl_WidgetDoCallbackArg Fl_WidgetDoCallback2
//declare sub      Fl_WidgetDoCallback3(byval wgt as Fl_Widget ptr, byval other as Fl_Widget ptr, byval lArg as long)
//#define Fl_WidgetDoCallbacklArg Fl_WidgetDoCallback3
	//' Draws the widget. 
	//declare sub      Fl_WidgetDraw(byval wgt as Fl_Widget ptr)
void Fl_WidgetDraw(Fl_Widget *wgt);
//' Draws the label in an arbitrary bounding box with an arbitrary alignment.
//declare sub      Fl_WidgetDrawLabel(byval wgt as Fl_Widget ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval align as FL_ALIGN)
//' Handles the specified event.
//declare function Fl_WidgetHandle(byval wgt as Fl_Widget ptr, byval event as FL_EVENT) as long

//' Makes a widget in/visible. 
//declare sub      Fl_WidgetHide(byval wgt as Fl_Widget ptr)
//declare sub      Fl_WidgetShow(byval wgt as Fl_Widget ptr)

//' Gets/Sets the image that is used as part of the widget label. 
//declare sub      Fl_WidgetSetImage(byval wgt as Fl_Widget ptr, byval img as Fl_Image ptr)
//declare function Fl_WidgetGetImage(byval wgt as Fl_Widget ptr) as Fl_Image ptr
//' same as Fl_WidgetGetImage but read only (const)
//declare function Fl_WidgetGetImage2(byval wgt as Fl_Widget ptr) as const Fl_Image ptr

//' Checks if this widget is a child of the other widget.
//declare function Fl_WidgetInside(byval wgt as Fl_Widget ptr, byval other as const Fl_Widget ptr) as long





//////////////////////// 			 ////////////////////////////////
/////////////////////////  FLTK GLUT ////////////////////////////////
//////////////////////// 			 ////////////////////////////////

		 //' #######################################
		//' # Fl_Glut_Window extends Fl_Gl_Window #
		//' #######################################
	//declare function Fl_Glut_WindowNew(byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Glut_Window ptr
Fl_Glut_Window * Fl_Glut_WindowNew( long w, long h, const char *title);
//declare function Fl_Glut_WindowNew2(byval x as long, byval y as long, byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Glut_Window ptr
Fl_Glut_Window * Fl_Glut_WindowNew2( long x, long y, long w, long h, const char * title);
//declare sub      Fl_Glut_WindowDelete(byref win as Fl_Glut_Window ptr)

//declare sub      Fl_Glut_WindowMakeCurrent(byval win as Fl_Glut_Window ptr)

	//' #################################################
		//' # class Fl_Glut_WindowEx extends Fl_Glut_Window #
		//' #################################################
	//declare function Fl_Glut_WindowExNew(byval w as long,byval h as long,byval title as const zstring ptr=0) as Fl_Glut_WindowEx ptr
Fl_Glut_WindowEx * Fl_Glut_WindowExNew( long w, long h, const char *title);

	//declare function Fl_Glut_WindowExNew2(byval x as long,byval y as long,byval w as long,byval h as long,byval title as const zstring ptr=0) as Fl_Glut_WindowEx ptr
Fl_Glut_WindowEx * Fl_Glut_WindowExNew2( long x, long y, long w, long h, const char *title);
//declare sub      Fl_Glut_WindowExDelete(byref win as Fl_Glut_WindowEx ptr)

//declare function Fl_Glut_WindowExHandleBase      (byval win as Fl_Glut_WindowEx ptr,byval event as Fl_Event) as long

//declare sub      Fl_Glut_WindowExSetDestructorCB (byval win as Fl_Glut_WindowEx ptr,byval cb as Fl_DestructorEx)

	//declare sub      Fl_Glut_WindowExSetDrawCB       (byval win as Fl_Glut_WindowEx ptr,byval cb as Fl_DrawEx)
void Fl_Glut_WindowExSetDrawCB( Fl_Glut_WindowEx *win, Fl_DrawEx cb);
//declare sub      Fl_Glut_WindowExSetDrawOverlayCB(byval win as Fl_Glut_WindowEx ptr,byval cb as Fl_Draw_OverlayEx)

//declare sub      Fl_Glut_WindowExSetHandleCB     (byval win as Fl_Glut_WindowEx ptr,byval cb as Fl_HandleEx)

//declare sub      Fl_Glut_WindowExSetResizeCB     (byval win as Fl_Glut_WindowEx ptr,byval cb as Fl_ResizeEx)

//' opengl proc
//declare function GlutGetProcAddress(byval procName as const zstring ptr) as any ptr

//declare function GlutExtensionSupported(byval extensionName as const zstring ptr) as long
	//' glut lib
	//declare sub      GlutInit(byval argcp as long ptr,byval argv as zstring ptr ptr)
void GlutInit(int *argcp,   char **argv);
	//declare sub      GlutInitDisplayMode(byval mode as ulong)
void GlutInitDisplayMode(unsigned long mode);
	//declare sub      GlutSwapBuffers
void GlutSwapBuffers(void);
//' current active window or NULL
	//declare function Glut_window() as Fl_Glut_Window ptr
Fl_Glut_Window * Glut_Window(void);
//' current active menu or 0
//declare function Glut_menu() as long

	//declare sub      GlutMainLoop
void GlutMainLoop(void);


	//' callback's
	//declare sub      GlutDisplayFunc(byval f as sub())
void GlutDisplayFunc( void (*func)() );
	//declare sub      GlutReshapeFunc(byval f as sub(byval w as long,byval h as long))
void GlutReshapeFunc( void (*func)(long w, long h) );

	//declare sub      GlutKeyboardFunc(byval f as sub(byval key as ubyte,byval x as long,byval y as long))
void GlutKeyboardFunc( void(*func)(unsigned char key, long x, long y) );
//declare sub      GlutMouseFunc(byval f as sub(byval b as long,byval state as long,byval x as long,byval y as long))
//declare sub      GlutMotionFunc(byval f as sub(byval x as long,byval y as long))
//declare sub      GlutPassiveMotionFunc(byval f as sub(byval x as long,byval y as long))

//declare sub      GlutEntryFunc(byval f as sub(byval s as long))

//declare sub      GlutVisibilityFunc(byval f as sub(byval s as long))

	//declare sub      GlutIdleFunc(byval f as sub())
void GlutIdleFunc(void (*func)());
//declare sub      GlutTimerFunc(byval msec as ulong,byval f as sub(byval value as long),byval value as long)

//declare sub      GlutMenuStateFunc(byval f as sub(byval state as long))
//declare sub      GlutMenuStatusFunc(byval f as sub(byval status as long,byval x as long,byval y as long))

//declare sub      GlutSpecialFunc(byval f as sub(byval key as long,byval x as long,byval y as long))

//declare sub      GlutOverlayDisplayFunc(byval f as sub())

//declare function GlutGet(byval typ as ulong) as long

//declare function GlutDeviceGet(byval typ as ulong) as long

//declare function GlutGetModifiers() as long


//' window
//declare sub      GlutInitWindowPosition(byval x as long,byval y as long)
	//declare sub      GlutInitWindowSize(byval w as long,byval h as long)
void GlutInitWindowSize( long w, long h);
	//declare function GlutCreateWindow(byval title as zstring ptr) as long
long GlutCreateWindow( const char *title);
//declare function GlutCreateSubWindow(byval win as long,byval x as long,byval y as long,byval w as long,byval h as long) as long
//declare sub      GlutDestroyWindow(byval win as long)

//declare sub      GlutPostRedisplay
//declare sub      GlutPostWindowRedisplay(byval win as long)

//declare function GlutGetWindow() as long
	//declare sub      GlutSetWindow(byval win as long)
void GlutSetWindow( long win );
//declare sub      GlutSetWindowTitle(byval title as zstring ptr)

//declare sub      GlutSetIconTitle(byval title as zstring ptr)

	//declare sub      GlutPositionWindow(byval x as long,byval y as long)
void GlutPositionWindow( long x, long y);
//declare sub      GlutReshapeWindow(byval w as long,byval h as long)

//declare sub      GlutPopWindow()
//declare sub      GlutPushWindow()

//declare sub      GlutIconifyWindow()

	//declare sub      GlutShowWindow()
void GlutShowWindow(void);
//declare sub      GlutHideWindow()

//declare sub      GlutFullScreen()

//declare sub      GlutSetCursor(byval c as Fl_Cursor)
//declare sub      GlutWarpPointer(byval x as long,byval y as long)

//declare sub      GlutEstablishOverlay()
//declare sub      GlutRemoveOverlay()
//declare sub      GlutPostOverlayRedisplay()

//declare sub      GlutShowOverlay()
//declare sub      GlutHideOverlay()

//declare sub      GlutUseLayer(byval layer as ulong)


//sub Fl_GlutInit
  //dim as long argc=0
  //dim as zstring ptr argv=0
  //GlutInit @argc,@argv
//end sub
void Fl_GlutInit(void){
	int argc=0;
	char **argv=NULL;
	GlutInit(&argc, &argv);
}
	

////////////////////////		     ///////////////////////////////// 
////////////////////////  OPENGL  GL /////////////////////////////////
////////////////////////             /////////////////////////////////

		//'########################################
		//'# class Fl_Gl_Window extends Fl_Window #
		//'########################################
	//declare function Fl_Gl_WindowNew(byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Gl_Window ptr
Fl_Gl_Window * Fl_Gl_WindowNew( long w, long h, const char *title);
	//declare function Fl_Gl_WindowNew2(byval x as long, byval y as long, byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Gl_Window ptr
Fl_Gl_Window * Fl_Gl_WindowNew2( long x, long y, long w, long h, const char *title);

//declare sub      Fl_Gl_WindowDelete(byref win as Fl_Gl_Window ptr)

//declare function Fl_Gl_WindowHandle(byval win as Fl_Gl_Window ptr, byval ev as FL_EVENT) as long

//declare function Fl_Gl_WindowCanDo(byval win as Fl_Gl_Window ptr) as long
//declare function Fl_Gl_WindowCanDoOverlay(byval win as Fl_Gl_Window ptr) as long

	//declare sub      Fl_Gl_WindowSetContext(byval win as Fl_Gl_Window ptr, byval ctx as any ptr, byval destroy_flag as long=0)
void Fl_Gl_WindowSetContext( Fl_Gl_Window *win, void *context, long destroy_flag);
//declare function Fl_Gl_WindowGetContext(byval win as Fl_Gl_Window ptr) as any ptr

//declare sub      Fl_Gl_WindowSetContextValid(byval win as Fl_Gl_Window ptr, byval v as long)
//declare function Fl_Gl_WindowGetContextValid(byval win as Fl_Gl_Window ptr) as long

//declare sub      Fl_Gl_WindowSetValid(byval win as Fl_Gl_Window ptr, byval v as long)
	//declare function Fl_Gl_WindowGetValid(byval win as Fl_Gl_Window ptr) as long
long Fl_Gl_WindowGetValid(Fl_Gl_Window *win);
//declare sub      Fl_Gl_WindowFlush(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowInvalidate(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowMakeCurrent(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowHideOverlay(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowMakeOverlayCurrent(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowRedrawOverlay(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowSetMode(byval win as Fl_Gl_Window ptr, byval m as FL_MODE)
//declare function Fl_Gl_WindowGetMode(byval win as Fl_Gl_Window ptr) as FL_MODE

//declare sub      Fl_Gl_WindowOrtho(byval win as Fl_Gl_Window ptr)
void Fl_Gl_WindowOrtho(Fl_Gl_Window *win);
//declare sub      Fl_Gl_WindowResize(byval win as Fl_Gl_Window ptr, byval x as long, byval y as long, byval w as long, byval h as long)

//declare sub      Fl_Gl_WindowSwapBuffers(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowHide(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowShow(byval win as Fl_Gl_Window ptr)

//declare sub      Fl_Gl_WindowShowArgs(byval win as Fl_Gl_Window ptr, byval argc as long, byval argv as zstring ptr ptr)

		//'#############################################
		//'# class Fl_Gl_WindowEx extends Fl_GL_Window #
		//'#############################################
	//declare function Fl_Gl_WindowExNew(byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Gl_WindowEx ptr
Fl_Gl_WindowEx * Fl_Gl_WindowExNew( long w, long h, const char *title);
	//declare function Fl_Gl_WindowExNew2(byval x as long, byval y as long, byval w as long, byval h as long, byval title as const zstring ptr=0) as Fl_Gl_WindowEx ptr
Fl_Gl_WindowEx * Fl_Gl_WindowExNew2( long x, long y, long w, long h, const char *title);
//declare sub      Fl_Gl_WindowExDelete          (byref win as Fl_Gl_WindowEx ptr)

//declare function Fl_Gl_WindowExHandleBase      (byval win as Fl_Gl_WindowEx ptr, byval event as FL_EVENT) as long

//declare sub      Fl_Gl_WindowExSetDestructorCB (byval win as Fl_Gl_WindowEx ptr, byval cb as Fl_DestructorEx)
	//declare sub      Fl_Gl_WindowExSetDrawCB       (byval win as Fl_Gl_WindowEx ptr, byval cb as Fl_DrawEx)
void Fl_Gl_WindowExSetDrawCB( Fl_Gl_WindowEx *win, Fl_DrawEx  cb ); 
//declare sub      Fl_Gl_WindowExSetDrawOverlayCB(byval win as Fl_Gl_WindowEx ptr, byval cb as Fl_Draw_OverlayEx)

//declare sub      Fl_Gl_WindowExSetHandleCB     (byval win as Fl_Gl_WindowEx ptr, byval cb as Fl_HandleEx)

//declare sub      Fl_Gl_WindowExSetResizeCB     (byval win as Fl_Gl_WindowEx ptr, byval cb as Fl_ResizeEx)


		//' ###################
		//' # FLTK GL drawing #
		//' ###################
	//declare sub      glDrawSetColor(byval c as Fl_COLOR)
void glDrawSetColor(Fl_Color clr);
//declare sub      glDrawRect(byval x as long, byval y as long, byval w as long, byval h as long)

//declare sub      glDrawRectFill(byval x as long, byval y as long, byval w as long, byval h as long)

//declare sub      glDrawSetFont(byval font as FL_FONT, byval size as FL_FONTSIZE)

//declare function glDrawGetFontHeight() as long

//declare function glDrawGetFontDescent() as long

//declare function glDrawGetStrWidth (byval txt as const zstring ptr) as double

//declare function glDrawGetStrWidth2(byval txt as const zstring ptr, byval nChars as long) as double

//declare function glDrawGetCharWidth(byval c as ubyte) as double

//declare sub      glDrawStrMeasure  (byval txt as const zstring ptr, byref x as long, byref y as long)

//declare sub      glDrawStr         (byval txt as const zstring ptr)

//declare sub      glDrawStr2        (byval txt as const zstring ptr, byval nChars as long)

	//declare sub      glDrawStrAti      (byval txt as const zstring ptr, byval x as long, byval y as long)
void glDrawStrAti(const char *txt, long x, long y);
//declare sub      glDrawStrAti2     (byval txt as const zstring ptr, byval nChars as long, byval x as long, byval y as long)

//declare sub      glDrawStrAtf      (byval txt as const zstring ptr, byval x as single, byval y as single)

//declare sub      glDrawStrAtf2     (byval txt as const zstring ptr, byval nChars as long, byval x as single, byval y as single)

//declare sub      glDrawStrBox      (byval txt as const zstring ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval align as FL_ALIGN)

//declare sub      glDrawImage       (byval buffer as const ubyte ptr, byval x as long, byval y as long, byval w as long, byval h as long, byval BytesPerPixel as long=3, byval pitch as long=0)





		//'###################################
		//'# class Fl_Table extends Fl_Group #
		//'###################################
//declare function Fl_TableNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Table ptr
//declare sub      Fl_TableDelete(byref t as Fl_Table ptr)
//' Sets the current group so you can build the widget tree by just constructing the widgets. 
	//declare sub      Fl_TableBegin(byval t as Fl_Table ptr)
void Fl_TableBegin( Fl_Table *t);
	//declare sub      Fl_TableEnd(byval t as Fl_Table ptr)
void Fl_TableEnd(Fl_Table *t);
//' The widget is removed from its current group (if any) and then added to the end of this group. 
//declare sub      Fl_TableAdd(byval t as Fl_Table ptr, byval wgt as Fl_Widget ptr)

//declare function Fl_TableArray(byval t as Fl_Table ptr) as Fl_Widget ptr const ptr
//' Returns the current column and row inside the callback.
//declare function Fl_TableCallbackCol(byval t as Fl_Table ptr) as long

//declare function Fl_TableCallbackRow(byval t as Fl_Table ptr) as long
//' Returns the current 'table context' inside the callback.
//declare function Fl_TableCallbackContext(byval t as Fl_Table ptr) as FL_TABLECONTEXT
//' Returns the number of children in the table. 
//declare function Fl_TableChildren(byval t as Fl_Table ptr) as long
//' Returns the child widget by an index. 
//declare function Fl_TableChild(byval t as Fl_Table ptr, byval nChildIndex as long) as Fl_Widget ptr
//' Clears the table to zero rows,columns and clears any widgets that were added with Fl_TableBegin()/Fl_TableEnd(). 
//declare sub      Fl_TableClear(byval t as Fl_Table ptr)
//' Enable or disable column headers.
	//declare sub      Fl_TableSetColHeader(byval t as Fl_Table ptr, byval bFlag as long)
void Fl_TableSetColHeader(Fl_Table *t, long bFlag);
//' Returns if column headers are enabled or not.
//declare function Fl_TableGetColHeader(byval t as Fl_Table ptr) as long
//' Sets the color for column headers and redraws the table.
//declare sub      Fl_TableSetColHeaderColor(byval t as Fl_Table ptr, byval c as Fl_COLOR)
//' Gets the color for column headers.
//declare function Fl_TableGetColHeaderColor(byval t as Fl_Table ptr) as Fl_COLOR
//' Sets the height in pixels for column headers and redraws the table.
//declare sub      Fl_TableSetColHeaderHeight(byval t as Fl_Table ptr, byval h as long)
//' Gets the height in pixels for column headers
//declare function Fl_TableGetColHeaderHeight(byval t as Fl_Table ptr) as long
//' Sets the column scroll position to column 'col', and causes the screen to redraw. 
//declare sub      Fl_TableSetColPosition(byval t as Fl_Table ptr, byval col as long)
//' Gets the column scroll position.
//declare function Fl_TableGetColPosition(byval t as Fl_Table ptr) as long
//' Enable / disable column resizing by the user. 
	//declare sub      Fl_TableSetColResize(byval t as Fl_Table ptr, byval bFlag as long)
void Fl_TableSetColResize(Fl_Table *t, long bFlag);
//' Returns if column resizing by the user is enabled or not.
//declare function Fl_TableGetColResize(byval t as Fl_Table ptr) as long
//' Sets/Returns the current column minimum resize value.
//declare sub      Fl_TableSetColResizeMin(byval t as Fl_Table ptr, byval m as long)
//declare function Fl_TableGetColResizeMin(byval t as Fl_Table ptr) as long
//' Sets the width of the specified column in pixels, and the table is redrawn. 
//declare sub      Fl_TableSetColWidth(byval t as Fl_Table ptr, byval col as long, byval w as long)
//' Returns the current width of the specified column in pixels.
//declare function Fl_TableGetColWidth(byval t as Fl_Table ptr, byval col as long) as long
//' Convenience method to set the width of all columns to the same value, in pixels. 
	//declare sub      Fl_TableColWidthAll(byval t as Fl_Table ptr, byval w as long)
void Fl_TableColWidthAll(Fl_Table *t, long w);
//' Set the number of columns in the table and redraw. 
	//declare sub      Fl_TableSetCols(byval t as Fl_Table ptr, byval nColumns as long)
void Fl_TableSetCols(Fl_Table *t, long nColumns);
//' Get the number of columns in the table. 
//declare function Fl_TableGetCols(byval t as Fl_Table ptr) as long
//' Trigger as table callback.
//declare sub      Fl_TableDoCallback(byval t as Fl_Table ptr, byval context as FL_TABLECONTEXT, byval r as long, byval c as long)

//declare sub      Fl_TableDraw(byval t as Fl_Table ptr)
//' Searches the child array for the widget and returns the index.
//declare function Fl_TableFind(byval t as Fl_Table ptr, byval wgt as const Fl_Widget ptr) as long
//' Sets or gets the region of cells selected (highlighted).
//declare sub      Fl_TableSetSelection(byval t as Fl_Table ptr, byval row_top as long, byval col_left as long, byval row_bot as long, byval col_right as long)
//declare sub      Fl_TableGetSelection(byval t as Fl_Table ptr, byref row_top as long, byref col_left as long, byref row_bot as long, byref col_right as long)
//' Resets the internal array of widget sizes and positions.
//declare sub      Fl_TableInitSizes(byval t as Fl_Table ptr)
//' The widget is removed from its current group (if any) and then inserted into this group.
//declare sub      Fl_TableInsert(byval t as Fl_Table ptr, byval wgt as Fl_Widget ptr, byval n as long)
//' This does Fl_TableInsert(w2, Fl_TbleFind(w1)) before.
//declare sub      Fl_TableInsert2(byval t as Fl_Table ptr, byval w1 as Fl_Widget ptr, byval w2 as Fl_Widget ptr)
//' Returns 1 if someone is interactively resizing a row or column.
//declare function Fl_TableIsInteractiveResize(byval t as Fl_Table ptr) as long
//' See if the cell at row and column is selected. 
//declare function Fl_TableIsSelected(byval t as Fl_Table ptr, byval row as long, byval col as long) as long
//' 
//declare function Fl_TableMoveCursor(byval t as Fl_Table ptr, byval ror as long, byval col as long) as long
//' Removes a widget from the group but does not delete it.
//declare sub      Fl_TableRemove(byval t as Fl_Table ptr, byval wgt as Fl_Widget ptr)
//' Changes the size of the Fl_Table, causing it to redraw. 
//declare sub      Fl_TableResize(byval t as Fl_Table ptr, byval x as long, byval y as long, byval w as long, byval h as long)
//' Sets/Returns enables/disables showing the row headers. 
	//declare sub      Fl_TableSetRowHeader(byval t as Fl_Table ptr, byval flag as long)
void Fl_TableSetRowHeader(Fl_Table *t, long flag);
//declare function Fl_TableGetRowHeader(byval t as Fl_Table ptr) as long
//' Sets the row header color and causes the screen to redraw.
//declare sub      Fl_TableSetRowHeaderColor(byval t as Fl_Table ptr, byval c as Fl_COLOR)
//' Returns the current row header color.
//declare function Fl_TableGetRowHeaderColor(byval t as Fl_Table ptr) as Fl_COLOR
//' Sets width in pixels for row headers and redraws the table.
//declare sub      Fl_TableSetRowHeaderWidth(byval t as Fl_Table ptr, byval w as long)
//' Returns the current row header width (in pixels).
//declare function Fl_TableGetRowHeaderWidth(byval t as Fl_Table ptr) as long
//' Sets the height of the specified row in pixels, and the table is redrawn.
//declare sub      Fl_TableSetRowHeight(byval t as Fl_Table ptr, byval row as long, byval h as long)
//' Returns the current height of the specified row in pixels.
//declare function Fl_TableGetRowHeight(byval t as Fl_Table ptr, byval row as long) as long
//' Convenience method to set the height of all rows to the same value, in pixels. 
	//declare sub      Fl_TableRowHeightAll(byval t as Fl_Table ptr, byval h as long)
void Fl_TableRowHeightAll(Fl_Table *t, long h);
//' Sets the row scroll position to 'row' and causes the screen to redraw. 
//declare sub      Fl_TableSetRowPosition(byval t as Fl_Table ptr, byval row as long)
//' Returns the current row scroll position as a row number. 
//declare function Fl_TableGetRowPosition(byval t as Fl_Table ptr) as long
//' Sets/Returns allows/disallows row resizing by the user. 
	//declare sub      Fl_TableSetRowResize(byval t as Fl_Table ptr, byval bFlag as long)
void Fl_TableSetRowResize(Fl_Table *t, long bFlag);
//declare function Fl_TableGetRowResize(byval t as Fl_Table ptr) as long
//' Sets or gets the current row minimum resize value. 
//declare sub      Fl_TableSetRowResizeMin(byval t as Fl_Table ptr, byval m as long)
//declare function Fl_TableGetRowResizeMin(byval t as Fl_Table ptr) as long
//' Sets the number of rows in the table, and the table is redrawn.
	//declare sub      Fl_TableSetRows(byval t as Fl_Table ptr, byval r as long)
void Fl_TableSetRows(Fl_Table *ptr, long r);
//declare function Fl_TableGetRows(byval t as Fl_Table ptr) as long
//' Sets or gets the kind of box drawn around the data table, the default being FL_NO_BOX. 
//declare sub      Fl_TableSetTableBox(byval t as Fl_Table ptr, byval bt as FL_BOXTYPE)
//declare function Fl_TableGetTableBox(byval t as Fl_Table ptr) as FL_BOXTYPE
//' Sets which row should be at the top of the table, scrolling as necessary, and the table is redrawn. 
//declare sub      Fl_TableSetTopRow(byval t as Fl_Table ptr, byval row as long)
//' Returns the current top row shown in the table.
//declare function Fl_TableGetTopRow(byval t as Fl_Table ptr) as long
//' Returns the range of row and column numbers for all visible and partially visible cells in the table.
//declare sub      Fl_TableVisibleCells(byval t as Fl_Table ptr, byref r1 as long, byref r2 as long, byref c1 as long, byref c2 as long)

//declare sub      Fl_TableWhen(byval t as Fl_Table ptr, byval flags as FL_WHEN)

		//'#####################################
		//'# class Fl_TableEx extends Fl_Table #
		//'#####################################
	//declare function Fl_TableExNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_TableEx ptr
Fl_TableEx* Fl_TableExNew(long x, long y, long w, long h, const char *lable);
//declare function Fl_TableExHandleBase   (byval tex as Fl_TableEx ptr, byval event as FL_EVENT) as long
//declare function Fl_TableExFindCell     (byval tex as Fl_TableEx ptr, byval ctx as FL_TABLECONTEXT, byval r as long, byval c as long, byref x as long, byref y as long, byref w as long, byref h as long) as long
//declare sub      Fl_TableExSetDrawCB    (byval tex as Fl_TableEx ptr, byval cb as Fl_DrawEx)
	//declare sub      Fl_TableExSetDrawCellCB(byval tex as Fl_TableEx ptr, byval cb as Fl_DrawcellEx)
void Fl_TableExSetDrawCellCB(Fl_TableEx *t, Fl_DrawcellEx cb);
//declare sub      Fl_TableExSetHandleCB  (byval tex as Fl_TableEx ptr, byval cb as Fl_HandleEx)
//declare sub      Fl_TableExSetResizeCB  (byval tex as Fl_TableEx ptr, byval cb as Fl_ResizeEx)

		//'#######################################
		//'# class Fl_Table_Row extends Fl_Table #
		//'#######################################
//declare function Fl_Table_RowNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Table_Row ptr

//declare sub      Fl_Table_RowClear(byval tr as Fl_Table_Row ptr)
//' Checks to see if 'row' is selected. 
//declare function Fl_Table_RowRowSelected(byval tr as Fl_Table_Row ptr, byval r as long) as long
//' Sets the number of rows in the table, and the table is redrawn. 
//declare sub      Fl_Table_RowSetRows(byval tr as Fl_Table_Row ptr, byval nRows as long)
//' Returns the number of rows in the table. 
//declare function Fl_Table_RowGetRows(byval tr as Fl_Table_Row ptr) as long
//' This convenience function changes the selection state for all rows based on 'flag'
//declare sub      Fl_Table_RowSelectAllRows(byval tr as Fl_Table_Row ptr, byval flag as long=1)
//' Changes the selection state for 'row', depending on the value of 'flag'.
//declare function Fl_Table_RowSelectRow(byval tr as Fl_Table_Row ptr, byval row as long, byval  flag as long=1) as long
//' Sets or gets the table selection mode. 
//declare sub      Fl_Table_RowSetType(byval tr as Fl_Table_Row ptr, byval m as Fl_TableRowSelectMode)

//declare function Fl_Table_RowGetType(byval tr as Fl_Table_Row ptr) as Fl_TableRowSelectMode

//'#############################################
//'# class Fl_Table_RowEx extends Fl_Table_Row #
//'#############################################
//declare function Fl_Table_RowExNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Table_RowEx ptr
//declare function Fl_Table_RowExHandleBase   (byval tex as Fl_Table_RowEx ptr, byval event as FL_EVENT) as long
//declare function Fl_Table_RowExFindCell     (byval tex as Fl_Table_RowEx ptr, byval ctx as FL_TABLECONTEXT, byval r as long, byval c as long, byref x as long, byref y as long, byref w as long, byref h as long) as long
//declare sub      Fl_Table_RowExSetDrawCB    (byval tex as Fl_Table_RowEx ptr, byval cb as Fl_DrawEx)
//declare sub      Fl_Table_RowExSetDrawCellCB(byval tex as Fl_Table_RowEx ptr, byval cb as Fl_DrawcellEx)
//declare sub      Fl_Table_RowExSetHandleCB  (byval tex as Fl_Table_RowEx ptr, byval cb as Fl_HandleEx)
//declare sub      Fl_Table_RowExSetResizeCB  (byval tex as Fl_Table_RowEx ptr, byval cb as Fl_ResizeEx)

//'##################################
//'# class Fl_Tabs extends Fl_Group #
//'##################################
//DeclareEx(Fl_Tabs)
//' Creates a new Fl_Tabs widget using the given position, size, and label string.
//declare function Fl_TabsNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Tabs ptr
//declare sub      Fl_TabsdDelete(byref tbs as Fl_Tabs ptr)

//declare function Fl_TabsHandle(byval tbs as Fl_Tabs ptr, byval event as FL_EVENT) as long
//' Returns the position and size available to be used by its children.
//declare sub      Fl_TabsClientArea(byval tbs as Fl_Tabs ptr, byref rx as long, byref ry as long, byref rw as long, byref rh as long, byval tabh as long=0)
//' This is called by the tab widget's handle() method to set the tab group widget the user last FL_PUSH'ed on.
//declare function Fl_TabsSetPush(byval tbs as Fl_Tabs ptr, byval wgt as Fl_Widget ptr) as long
//' Returns the tab group for the tab the user has currently down-clicked on and remains over until FL_RELEASE.
//declare function Fl_TabsGetPush(byval tbs as Fl_Tabs ptr) as Fl_Widget ptr
//' Sets the widget to become the current visible widget/tab.
//declare function Fl_TabsSetValue(byval tbs as Fl_Tabs ptr, byval wgt as Fl_Widget ptr) as long
//' Gets the currently visible widget/tab.
//declare function Fl_TabsGetValue(byval tbs as Fl_Tabs ptr) as Fl_Widget ptr
//' Return the widget of the tab the user clicked on at event_x / event_y.
//declare function Fl_TabsWhich(byval tbs as Fl_Tabs ptr, byval event_x as long, byval event_y as long) as Fl_Widget ptr
//#define Fl_TabsEnd  Fl_GroupEnd
//#define Fl_TabNew   Fl_GroupNew
//#define Fl_TabBegin Fl_GroupBegin
//#define Fl_TabEnd   Fl_GroupEnd


		//'################################################
		//'# class Fl_Text_Buffer used by Fl_Text_Display #
		//'################################################
	//' Create an empty text buffer.
	//declare function Fl_Text_BufferNew(byval requestedSize as long=0, byval preferredGapSize as long=1024) as Fl_Text_buffer ptr
Fl_Text_Buffer * Fl_Text_BufferNew(long RequestedSize, long PreferredGapSizes );
//' Frees a text buffer.
//declare sub      Fl_Text_BufferDelete(byref tb as Fl_Text_Buffer ptr)
//' Adds a callback function that is called whenever the text buffer is modified. 
//declare sub      Fl_Text_BufferAddModifyCallback(byval tb as Fl_Text_Buffer ptr, byval cb as Fl_Text_Modify_Cb, byval cbArg as any ptr)

//declare sub      Fl_Text_BufferRemoveModifyCallback(byval tb as Fl_Text_Buffer ptr, byval cb as Fl_Text_Modify_Cb, byval cbArg as any ptr)
//' Calls all modify callbacks that have been registered using the add_modify_callback() method. 
//declare sub      Fl_Text_BufferCallModifyCallbacks(byval tb as Fl_Text_Buffer ptr)
//' Adds a callback routine to be called before text is deleted from the buffer. 
//declare sub      Fl_Text_BufferAddPredeleteCallback(byval tb as Fl_Text_Buffer ptr, byval cb as Fl_Text_Predelete_Cb, byval cbArg as any ptr)

//declare sub      Fl_Text_BufferRemovePredeleteCallback(byval tb as Fl_Text_Buffer ptr, byval cb as Fl_Text_Predelete_Cb, byval cbArg as any ptr)
//' Calls the stored pre-delete callback procedure(s) for this buffer to update the changed area(s) on the screen and any other listeners. 
//declare sub      Fl_Text_BufferCallPredeleteCallbacks(byval tb as Fl_Text_Buffer ptr)
	//' Loads a text file into the buffer.
	//declare function Fl_Text_BufferLoadFile  (byval tb as Fl_Text_Buffer ptr, byval file as const zstring ptr, byval buflen as long = 128*1024) as long
long Fl_Text_BufferLoadFile(Fl_Text_Buffer *tb, const char *filename, unsigned long buflen );
//' Saves a text file from the current buffer.
//declare function Fl_Text_BufferSaveFile  (byval tb as Fl_Text_Buffer ptr, byval file as const zstring ptr, byval buflen as long = 128*1024) as long
//' 
//declare function Fl_Text_BufferOutputFile(byval tb as Fl_Text_Buffer ptr, byval file as const zstring ptr, byval start as long, byval end_ as long, byval buflen as long = 128*1024) as long
	//' Appends the named file to the end of the buffer.
	//declare function Fl_Text_BufferAppendFile(byval tb as Fl_Text_Buffer ptr, byval file as const zstring ptr, byval buflen as long = 128*1024) as long
long Fl_TextBufferAppendFile(Fl_Text_Buffer *tb, const char *filename, unsigned long buflen);
//' Inserts a file at the specified position.
//declare function Fl_Text_BufferInsertFile(byval tb as Fl_Text_Buffer ptr, byval file as const zstring ptr, byval p as long, byval buflen as long = 128*1024) as long
	//' Appends the text string to the end of the buffer. 
	//declare sub      Fl_Text_BufferAppend(byval tb as Fl_Text_Buffer ptr, byval text as const zstring ptr)
void Fl_Text_BufferAppend(Fl_Text_Buffer *tb, const char *text);
	//' Inserts null-terminated string text at position pos. 
	//declare sub      Fl_Text_BufferInsert(byval tb as Fl_Text_Buffer ptr, byval pos_ as long, byval text as const zstring ptr)
void Fl_Text_BufferInsert(Fl_Text_Buffer *tb, unsigned long pos_, const char *text);
//' Returns the number of bytes in the buffer.
//declare function Fl_Text_BufferLength(byval tb as Fl_Text_Buffer ptr) as long
//' Convert a byte offset in buffer into a memory address. 
//declare function Fl_Text_BufferAddress (byval tb as Fl_Text_Buffer ptr, byval p as long) as zstring ptr
//declare function Fl_Text_BufferAddress2(byval tb as Fl_Text_Buffer ptr, byval p as long) as const zstring ptr

//' Returns the raw byte at the specified position pos in the buffer. 
//declare function Fl_Text_BufferByteAt(byval tb as Fl_Text_Buffer ptr, byval p as long) as ubyte
//' Returns the character at the specified position pos in the buffer. 
//declare function Fl_Text_BufferCharAt(byval tb as Fl_Text_Buffer ptr, byval p as long) as ulong
//' Lets the undo system know if we can undo changes.
//declare sub      Fl_Text_BufferCanUndo(byval tb as Fl_Text_Buffer ptr, byval flag as byte=1)
//' Copies text from one buffer to this one. 
//declare sub      Fl_Text_BufferCopy(byval tb as Fl_Text_Buffer ptr, byval from as Fl_Text_Buffer ptr, byval fromStart as long, byval fromEnd as long, byval toPos as long)
//' Count the number of displayed characters between buffer position lineStartPos and targetPos. 
//declare function Fl_Text_BufferCountDisplayedCharacters(byval tb as Fl_Text_Buffer ptr, byval lineStartPos as long, byval targetPos as long) as long
//' Counts the number of newlines between startPos and endPos in buffer. 
//declare function Fl_Text_BufferCountLines(byval tb as Fl_Text_Buffer ptr, byval startPos as long, byval endPos as long) as long
//' Search backwards in buffer buf for character searchChar, starting with the character BEFORE startPos, returning the result in foundPos returns 1 if found, 0 if not. 
//declare function Fl_Text_BufferFindCharBackward(byval tb as Fl_Text_Buffer ptr, byval startPos as long, byval searchChar as ulong, byval pFoundPos as long ptr) as long
//' Finds the next occurrence of the specified character. 
//declare function Fl_Text_BufferFindCharForward(byval tb as Fl_Text_Buffer ptr, byval startPos as long, byval searchChar as ulong, byval pFoundPos as long ptr) as long
//' Highlights the specified text within the buffer. 
//declare sub      Fl_Text_BufferSetHighlight(byval tb as Fl_Text_Buffer ptr, byval start as long, byval end_ as long)
//' Returns the highlighted text. 
//declare function Fl_Text_BufferGetHighlight(byval tb as Fl_Text_Buffer ptr) as long
//' Highlights the specified text between start and end within the buffer. 
//declare function Fl_Text_BufferHighlightPosition(byval tb as Fl_Text_Buffer ptr, byval pStart as long ptr, byval pEnd as long ptr) as long
//' Returns the current highlight selection. 
//declare function Fl_Text_BufferHighlightSelection(byval tb as Fl_Text_Buffer ptr) as const Fl_Text_Selection ptr
//' Returns the highlighted text. 
//declare function Fl_Text_BufferHighlightText(byval tb as Fl_Text_Buffer ptr) as zstring ptr
//' Finds and returns the position of the end of the line containing position pos
//' (which is either a pointer to the newline character ending the line, or a pointer to one character beyond the end of the buffer) 
//declare function Fl_Text_BufferLineEnd(byval tb as Fl_Text_Buffer ptr, byval p as long) as long
//' Returns the position of the start of the line containing position pos.
//declare function Fl_Text_BufferLineStart(byval tb as Fl_Text_Buffer ptr, byval p as long) as long
//' Returns the text from the entire line containing the specified character position. 
//declare function Fl_Text_BufferLineText(byval tb as Fl_Text_Buffer ptr, byval p as long) as zstring ptr
//' Returns the index of the next character. 
//declare function Fl_Text_BufferNextChar(byval tb as Fl_Text_Buffer ptr, byval ix as long) as long

//declare function Fl_Text_BufferNextCharClipped(byval tb as Fl_Text_Buffer ptr, byval ix as long) as long
//' Returns the index of the previous character. 
//declare function Fl_Text_BufferPrevChar(byval tb as Fl_Text_Buffer ptr, byval ix as long) as long

//declare function Fl_Text_BufferPrevCharClipped(byval tb as Fl_Text_Buffer ptr, byval ix as long) as long
//' Deletes a range of characters in the buffer. 
//declare sub      Fl_Text_BufferRemove(byval tb as Fl_Text_Buffer ptr, byval start as long, byval end_ as long)
//' Deletes the characters between start and end, and inserts the null-terminated string text in their place in the buffer. 
//declare sub      Fl_Text_BufferReplace(byval tb as Fl_Text_Buffer ptr, byval start as long, byval end_ as long, byval text as const zstring ptr)
//' Removes the text in the primary selection. 
//declare sub      Fl_Text_BufferRemoveSelection(byval tb as Fl_Text_Buffer ptr)
//' Removes the text from the buffer corresponding to the secondary text selection object. 
//declare sub      Fl_Text_BufferRemoveSecondarySelection(byval tb as Fl_Text_Buffer ptr)
//' Replaces the text in the primary selection. 
//declare sub      Fl_Text_BufferReplaceSelection(byval tb as Fl_Text_Buffer ptr, byval text as const zstring ptr)
//' Replaces the text from the buffer corresponding to the secondary text selection object with the new string text.
//declare sub      Fl_Text_BufferReplaceSecondarySelection(byval tb as Fl_Text_Buffer ptr, byval text as const zstring ptr)
//' Finds and returns the position of the first character of the line nLines backwards from startPos
//' (not counting the character pointed to by startpos if that is a newline) in the buffer. 
//declare function Fl_Text_BufferRewindLines(byval tb as Fl_Text_Buffer ptr, byval startPos as long, byval nLines as long) as long
//' Search backwards in buffer for string searchCharssearchString, starting with the character BEFORE startPos, returning the result in foundPos returns 1 if found, 0 if not. 
//declare function Fl_Text_BufferSearchBackward(byval tb as Fl_Text_Buffer ptr, byval startPos as long, byval searchString as const zstring ptr, byval pFoundPos as long ptr, byval matchCase as long=0) as long
//' Search forwards in buffer for string searchString, starting with the character startPos, and returning the result in foundPos returns 1 if found, 0 if not. 
//declare function Fl_Text_BufferSearchForward(byval tb as Fl_Text_Buffer ptr, byval startPos as long, byval searchString as const zstring ptr, byval pFoundPos as long ptr, byval matchCase as long=0) as long
//' Returns the primary selection. 
//declare function Fl_Text_BufferPrimarySelection(byval tb as Fl_Text_Buffer ptr) as Fl_Text_Selection ptr

//declare function Fl_Text_BufferPrimarySelection2(byval tb as Fl_Text_Buffer ptr) as const Fl_Text_Selection ptr
//' Selects a range of characters in the buffer.
//declare sub      Fl_Text_BufferSelect(byval tb as Fl_Text_Buffer ptr, byval start as long, byval end_ as long)
//' Returns a non 0 value if text has been selected, 0 otherwise.
//declare function Fl_Text_BufferSelected(byval tb as Fl_Text_Buffer ptr) as long
//' Gets the selection position.
//declare function Fl_Text_BufferSelectionPosition(byval tb as Fl_Text_Buffer ptr, byval start as long ptr, byval end_ as long ptr) as long
//' Returns the currently selected text.
//declare function Fl_Text_BufferSelectionText(byval tb as Fl_Text_Buffer ptr) as zstring ptr
//' Returns the secondary selection. 
//declare function Fl_Text_BufferSecondarySelection(byval tb as Fl_Text_Buffer ptr) as const Fl_Text_Selection ptr
//' Selects a range of characters in the secondary selection. 
//declare sub      Fl_Text_BufferSecondarySelect(byval tb as Fl_Text_Buffer ptr, byval start as long, byval end_ as long)
//' Returns a non 0 value if text has been selected in the secondary text selection, 0 otherwise. 
//declare function Fl_Text_BufferSecondarySelected(byval tb as Fl_Text_Buffer ptr) as long
//' Returns the current selection in the secondary text selection object.
//declare function Fl_Text_BufferSecondarySelectionPosition(byval tb as Fl_Text_Buffer ptr, byval start as long ptr, byval end_ as long ptr) as long
//' Returns the text in the secondary selection. 
//declare function Fl_Text_BufferSecondarySelectionText(byval tb as Fl_Text_Buffer ptr) as zstring ptr
//' Clears any selection in the secondary text selection object.
//declare sub      Fl_Text_BufferSecondaryUnselect(byval tb as Fl_Text_Buffer ptr)
//' Count forward from buffer position startPos in displayed characters 
//' (displayed characters are the characters shown on the screen to represent characters in the buffer, where tabs and control characters are expanded) 
//declare function Fl_Text_BufferSkipDisplayedCharacters(byval tb as Fl_Text_Buffer ptr, byval lineStartPos as long, byval nChars as long) as long
//' Finds the first character of the line nLines forward from startPos in the buffer and returns its position.
//declare function Fl_Text_BufferSkipLines(byval tb as Fl_Text_Buffer ptr, byval startPos as long, byval nLines as long) as long
//' Set the hardware tab distance (width) used by all displays for this buffer, and used in computing offsets for rectangular selection operations. 
//declare sub      Fl_Text_BufferSetTabDistance(byval tb as Fl_Text_Buffer ptr, byval tabDist as long)
//' Gets the tab width.
//declare function Fl_Text_BufferGetTabDistance(byval tb as Fl_Text_Buffer ptr) as long
	//' Replaces the entire contents of the text buffer.
	//declare sub      Fl_Text_BufferSetText(byval tb as Fl_Text_Buffer ptr, byval text as const zstring ptr=0)
void Fl_Text_BufferSetText(Fl_Text_Buffer *tb, const char *text);
//' Get a copy of the entire contents of the text buffer.
//declare function Fl_Text_BufferGetText(byval tb as Fl_Text_Buffer ptr) as zstring ptr
//' Get a copy of a part of the text buffer.
//declare function Fl_Text_BufferTextRange(byval tb as Fl_Text_Buffer ptr, byval start as long, byval end_ as long) as zstring ptr
//' Undo text modification according to the undo variables or insert text from the undo buffer. 
//declare function Fl_Text_BufferUndo(byval tb as Fl_Text_Buffer ptr, byval cp as long ptr=0) as long
//' Unhighlights text in the buffer.
//declare sub      Fl_Text_BufferUnhighlight(byval tb as Fl_Text_Buffer ptr)
//' Cancels any previous selection on the primary text selection object.
//declare sub      Fl_Text_BufferUnselect(byval tb as Fl_Text_Buffer ptr)
//' Align an index into the buffer to the current or previous utf8 boundary. 
//declare function Fl_Text_BufferUtf8Align(byval tb as Fl_Text_Buffer ptr, byval a as long) as long
//' Returns the position corresponding to the end of the word.
//declare function Fl_Text_BufferWordEnd(byval tb as Fl_Text_Buffer ptr, byval p as long) as long
//' Returns the position corresponding to the start of the word.
//declare function Fl_Text_BufferWordStart(byval tb as Fl_Text_Buffer ptr, byval p as long) as long

		//'##########################################
		//'# class Fl_Text_Display extends Fl_Group #
		//'##########################################
//DeclareEx(Fl_Text_Display)
	//declare function Fl_Text_DisplayNew(byval x as long, byval y as long, byval w as long, byval h as long, byval label as const zstring ptr=0) as Fl_Text_Display ptr
Fl_Text_Display * Fl_Text_DisplayNew(long x, long y, long w, long h, const char *label);
//declare sub      Fl_Text_DisplayDelete(byref td as Fl_Text_Display ptr)

//declare function Fl_Text_DisplayHandle(byval td as Fl_Text_Display ptr, byval event as FL_EVENT) as long
	//' Attach a text buffer to display, replacing the current buffer (if any) 
	//declare sub      Fl_Text_DisplaySetBuffer(byval td as Fl_Text_Display ptr, byval pTextbuf as Fl_Text_Buffer ptr)
void Fl_Text_DisplaySetBuffer(Fl_Text_Display *td, Fl_Text_Buffer *tb);
//' Gets the current text buffer associated with the text widget. 
//declare function Fl_Text_DisplayGetBuffer(byval td as Fl_Text_Display ptr) as Fl_Text_Buffer ptr
//' Attach (or remove) highlight information in text display and redisplay. 
//declare sub      Fl_Text_DisplayHighlightData(byval td as Fl_Text_Display ptr, byval pStylebuf as Fl_Text_Buffer ptr, byval pStyles as Style_Table_Entry ptr, byval nStyles as long, _
                                              //byval unfinishedStyle as byte=0, byval cb as Unfinished_Style_Cb=0, byval cbArg as any ptr=0)
//' Count the number of lines between two positions. 
//declare function Fl_Text_DisplayCountLines(byval td as Fl_Text_Display ptr, byval start as long, byval end_ as long, byval start_pos_is_line_start as byte) as long
//' Sets or gets the text cursor color. 
//declare sub      Fl_Text_DisplaySetCursorColor(byval td as Fl_Text_Display ptr, byval c as Fl_COLOR)
//declare function Fl_Text_DisplayGetCursorColor(byval td as Fl_Text_Display ptr) as Fl_COLOR
//' Sets the text cursor style. 
//declare sub      Fl_Text_DisplayCursorStyle(byval td as Fl_Text_Display ptr, byval style as FL_TEXT_DISPLAY_CURSOR_SHAPE)
//' Hides the text cursor. 
//declare sub      Fl_Text_DisplayHideCursor(byval td as Fl_Text_Display ptr)
//' Shows the text cursor. (This function may trigger a redraw.)
//declare sub      Fl_Text_DisplayShowCursor(byval td as Fl_Text_Display ptr, byval b as long=1)
//' Check if a pixel position is within the primary selection.
//declare function Fl_Text_DisplayInSelection(byval td as Fl_Text_Display ptr, byval x as long, byval y as long) as long
//' Inserts "text" at the current cursor location. 
//declare sub      Fl_Text_DisplayInsert(byval td as Fl_Text_Display ptr, byval text as const zstring ptr)
//' Sets or gets the position of the text insertion cursor for text display. 
//declare sub      Fl_Text_DisplaySetInsertPosition(byval td as Fl_Text_Display ptr, byval newPos as long)
//declare function Fl_Text_DisplayGetInsertPosition(byval td as Fl_Text_Display ptr) as long
//' Returns the end of a line.
//declare function Fl_Text_DisplayLineEnd(byval td as Fl_Text_Display ptr, byval startPos as long, byval startPosIsLineStart as byte) as long
//' Return the beginning of a line.
//declare function Fl_Text_DisplayLineStart(byval td as Fl_Text_Display ptr, byval p as long) as long
//' Moves the current insert position down / up one line. 
//declare function Fl_Text_DisplayMoveDown(byval td as Fl_Text_Display ptr) as long

//declare function Fl_Text_DisplayMoveUp(byval td as Fl_Text_Display ptr) as long
//' Moves the current insert position left / right one character. 
//declare function Fl_Text_DisplayMoveLeft(byval td as Fl_Text_Display ptr) as long

//declare function Fl_Text_DisplayMoveRight(byval td as Fl_Text_Display ptr) as long
//' Moves the current insert position right / left one word. 
//declare sub      Fl_Text_DisplayNextWord(byval td as Fl_Text_Display ptr)

//declare sub      Fl_Text_DisplayPreviousWord(byval td as Fl_Text_Display ptr)
//' Replaces text at the current insert position.
//declare sub      Fl_Text_DisplayOverStrike(byval td as Fl_Text_Display ptr, byval text as const zstring ptr)
//' Find the correct style for a character. 
//declare function Fl_Text_DisplayPositionStyle(byval td as Fl_Text_Display ptr, byval lineStartPos as long, byval lineLen as long, byval lineIndex as long) as long
//' Convert a character index into a pixel position. 
//declare function Fl_Text_DisplayPositionToXY(byval td as Fl_Text_Display ptr, byval p as long, byval x as long ptr, byval y as long ptr) as long
//' Marks text from start to end as needing a redraw. 
//declare sub      Fl_Text_DisplayRedisplayRange(byval td as Fl_Text_Display ptr, byval start as long, byval end_ as long)
//' Change the size of the displayed text area.
//declare sub      Fl_Text_DisplayResize(byval td as Fl_Text_Display ptr, byval x as long, byval y as long, byval w as long, byval h as long)
//' Skip a number of lines back.
//declare function Fl_Text_DisplayRewindLines(byval td as Fl_Text_Display ptr, byval startPos as long, byval nLines as long) as long
//' Scrolls the current buffer to start at the specified line and column.
//declare sub      Fl_Text_DisplayScroll(byval td as Fl_Text_Display ptr, byval topLineNum as long, byval horizOffset as long)
//' Sets / gets the scrollbar alignment type. 
//declare sub      Fl_Text_DisplaySetScrollbarAlign(byval td as Fl_Text_Display ptr, byval a as FL_ALIGN)
//declare function Fl_Text_DisplayGetScrollbarAlign(byval td as Fl_Text_Display ptr) as FL_ALIGN
//' Sets / gets the width/height of the scrollbars. 
//declare sub      Fl_Text_DisplaySetScrollbarWidth(byval td as Fl_Text_Display ptr, byval w as long)
//declare function Fl_Text_DisplayGetScrollbarWidth(byval td as Fl_Text_Display ptr) as long
//' Sets / gets the new shortcut key.
//declare sub      Fl_Text_DisplaySetShortcut(byval td as Fl_Text_Display ptr, byval s as long)
//declare function Fl_Text_DisplayGetShortcut(byval td as Fl_Text_Display ptr) as long
//' Scrolls the text buffer to show the current insert position.
//declare sub      Fl_Text_DisplayShowInsertPosition(byval td as Fl_Text_Display ptr)
//' Skip a number of lines forward.
//declare function Fl_Text_DisplaySkipLines(byval td as Fl_Text_Display ptr, byval startPos as long, byval nLines as long, byval startPosIsLineStart as byte) as long
//' Sets / gets the default color of text in the widget. 
//declare sub      Fl_Text_DisplaySetTextColor(byval td as Fl_Text_Display ptr, byval c as Fl_COLOR)
//declare function Fl_Text_DisplayGetTextColor(byval td as Fl_Text_Display ptr) as Fl_COLOR
//' Sets / gets the default font used when drawing text in the widget. 
//declare sub      Fl_Text_DisplaySetTextFont(byval td as Fl_Text_Display ptr, byval f as FL_FONT)
//declare function Fl_Text_DisplayGetTextFont(byval td as Fl_Text_Display ptr) as FL_FONT
//' Sets / gets the default size of text in the widget. 
//declare sub      Fl_Text_DisplaySetTextSize(byval td as Fl_Text_Display ptr, byval s as FL_FONTSIZE)
//declare function Fl_Text_DisplayGetTextSize(byval td as Fl_Text_Display ptr) as FL_FONTSIZE
//' Moves the insert position to the beginning / end of the current word. 
//declare function Fl_Text_DisplayWordStart(byval td as Fl_Text_Display ptr, byval pos_ as long) as long

//declare function Fl_Text_DisplayWordEnd(byval td as Fl_Text_Display ptr, byval pos_ as long) as long
//' Set the new text wrap mode.
//declare sub      Fl_Text_DisplayWrapMode(byval td as Fl_Text_Display ptr, byval wrap as FL_TEXT_DISPLAY_WRAP_MODE, byval wrap_margin as long)
//' Nobody knows what this function does. 
//declare function Fl_Text_DisplayWrappedColumn(byval td as Fl_Text_Display ptr, byval row as long, byval column as long) as long

//declare function Fl_Text_DisplayWrappedRow(byval td as Fl_Text_Display ptr, byval row as long) as long
//' Convert an x pixel position into a column number and vice versa.
//declare function Fl_Text_DisplayXToCol(byval td as Fl_Text_Display ptr, byval x as double) as double

//declare function Fl_Text_DisplayColToX(byval td as Fl_Text_Display ptr, byval col as double) as double

//declare sub      Fl_Text_DisplaySetLinenumberAlign(byval td as Fl_Text_Display ptr, byval aligm as FL_ALIGN)
//declare function Fl_Text_DisplayGetLinenumberAlign(byval td as Fl_Text_Display ptr) as FL_ALIGN

//declare sub      Fl_Text_DisplaySetLinenumberBGColor(byval td as Fl_Text_Display ptr, byval c as Fl_COLOR)
//declare function Fl_Text_DisplayGetLinenumberBGColor(byval td as Fl_Text_Display ptr) as Fl_COLOR

//declare sub      Fl_Text_DisplaySetLinenumberFGColor(byval td as Fl_Text_Display ptr, byval c as Fl_COLOR)
//declare function Fl_Text_DisplayGetLinenumberFGColor(byval td as Fl_Text_Display ptr) as Fl_COLOR

//declare sub      Fl_Text_DisplaySetLinenumberFont(byval td as Fl_Text_Display ptr, byval f as FL_FONT)
//declare function Fl_Text_DisplayGetLinenumberFont(byval td as Fl_Text_Display ptr) as FL_FONT

//declare sub      Fl_Text_DisplaySetLinenumberFormat(byval td as Fl_Text_Display ptr, byval fmt as const zstring ptr)
//declare function Fl_Text_DisplayGetLinenumberFormat(byval td as Fl_Text_Display ptr) as const zstring ptr

//declare sub      Fl_Text_DisplaySetLinenumberSize(byval td as Fl_Text_Display ptr, byval s as Fl_Fontsize)
//declare function Fl_Text_DisplayGetLinenumberSize(byval td as Fl_Text_Display ptr) as Fl_Fontsize

//declare sub      Fl_Text_DisplaySetLinenumberWidth(byval td as Fl_Text_Display ptr, byval w as long)
//declare function Fl_Text_DisplayGetLinenumberWidth(byval td as Fl_Text_Display ptr) as long
