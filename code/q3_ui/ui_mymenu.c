//THIS IS FOR THE PCLASS MENU
//CREATED BY TRENT GORDON FOR THE HAYFIELD SS QUAKE III ARENA MOD TEAM
//NOT COPYRIGHTED, SO BACK OF YOU DIRTY, DIRTY, wonderful person

//modified for use by RC KNP DN W.T. Woodson Quake III Arena Mod Team


/*
=============================================================================

START brawler MENU *****

=============================================================================
*/

#include "ui_local.h"

#define MYBRAWLERMAIN_FRAME	"menu/art/cut_frame"
#define MYBRAWLERBMAIN_FRAME	"menu/art/cut_frame"

//IDs to call object
#define ID_DYNAMIKER	200
#define ID_DYNAMIKEB	201

#define ID_ELPRIMOR		202
#define ID_ELPRIMOB		203

#define ID_SHELLYR		204
#define ID_SHELLYB		205

int teamFlag; //0-1 is Dynamike, 2-3 is El Primo, 4-5 is Shelly


typedef struct
{
	menuframework_s mybrawlermenu;
	menubitmap_s	myframe;
	menutext_s		header;
	menutext_s		joinDynamikeR;
	menutext_s		joinElPrimoR;
	menutext_s		joinShellyR;

}mybrawlermain_t;

typedef struct
{
	menuframework_s	mybrawlerbmenu;
	menubitmap_s	myframe;
	menutext_s		header;
	menutext_s		joinDynamikeB;
	menutext_s		joinElPrimoB;
	menutext_s		joinShellyB;

}mybrawlerbmain_t;

static mybrawlermain_t	s_mybrawlermain;

static mybrawlerbmain_t	s_mybrawlerbmain;



/*
===============
MyBrawlerMain_MenuEvent
===============
*/
static void MyBrawlerMain_MenuEvent( void* ptr, int event ) {
	if( event != QM_ACTIVATED ) {
		return;
	}

	switch( ((menucommon_s*)ptr)->id ) {

	case ID_DYNAMIKER:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team dynamiker\n" );
		UI_ForceMenuOff();
		break;


	case ID_ELPRIMOR:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team elprimor\n" );
		UI_ForceMenuOff();
		break;

	case ID_SHELLYR:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team shellyr\n");
		UI_ForceMenuOff();
		break;
	}
}

/*
===============
MyBrawlerMain_MenuInit
===============
*/
void MyBrawlerMain_MenuInit( void ) {
	int		y;
	int		gametype;
	char	info[MAX_INFO_STRING];

	memset( &s_mybrawlermain, 0, sizeof(s_mybrawlermain) );

	//MyMonsterMain_Cache();
	//TeamMain_Cache();

	y = 149;

	s_mybrawlermain.mybrawlermenu.wrapAround = qtrue;
	s_mybrawlermain.mybrawlermenu.fullscreen = qfalse;

	s_mybrawlermain.header.generic.type     = MTYPE_PTEXT;
	s_mybrawlermain.header.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	//s_mybrawlermain.header.generic.id       = ID_TNTYSON;
	//s_mybrawlermain.header.generic.callback = MyBrawlerMain_MenuEvent;
	s_mybrawlermain.header.generic.x        = 320;
	s_mybrawlermain.header.generic.y        = y;
	s_mybrawlermain.header.string           = "Select Brawler:";//TnTyson
	s_mybrawlermain.header.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlermain.header.color            = colorWhite;
	y += 30;
	
	s_mybrawlermain.joinDynamikeR.generic.type     = MTYPE_PTEXT;
	s_mybrawlermain.joinDynamikeR.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlermain.joinDynamikeR.generic.id       = ID_DYNAMIKER;
	s_mybrawlermain.joinDynamikeR.generic.callback = MyBrawlerMain_MenuEvent;
	s_mybrawlermain.joinDynamikeR.generic.x        = 320;
	s_mybrawlermain.joinDynamikeR.generic.y        = y;
	s_mybrawlermain.joinDynamikeR.string           = "Dynamike";//TnTyson
	s_mybrawlermain.joinDynamikeR.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlermain.joinDynamikeR.color            = colorWhite;
	y += 30;
	
	s_mybrawlermain.joinElPrimoR.generic.type     = MTYPE_PTEXT;
	s_mybrawlermain.joinElPrimoR.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlermain.joinElPrimoR.generic.id       = ID_ELPRIMOR;
	s_mybrawlermain.joinElPrimoR.generic.callback = MyBrawlerMain_MenuEvent;
	s_mybrawlermain.joinElPrimoR.generic.x        = 320;
	s_mybrawlermain.joinElPrimoR.generic.y        = y;
	s_mybrawlermain.joinElPrimoR.string           = "El Primo";//El Sobrino
	s_mybrawlermain.joinElPrimoR.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlermain.joinElPrimoR.color            = colorWhite;
	y += 30;

	s_mybrawlermain.joinShellyR.generic.type     = MTYPE_PTEXT;
	s_mybrawlermain.joinShellyR.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlermain.joinShellyR.generic.id       = ID_SHELLYR;
	s_mybrawlermain.joinShellyR.generic.callback = MyBrawlerMain_MenuEvent;
	s_mybrawlermain.joinShellyR.generic.x        = 320;
	s_mybrawlermain.joinShellyR.generic.y        = y;
	s_mybrawlermain.joinShellyR.string           = "Shelly";//Shelly
	s_mybrawlermain.joinShellyR.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlermain.joinShellyR.color            = colorWhite;
	y += 30;
	
	trap_GetConfigString(CS_SERVERINFO, info, MAX_INFO_STRING);   
	gametype = atoi( Info_ValueForKey( info,"g_gametype" ) );
		      

	Menu_AddItem( &s_mybrawlermain.mybrawlermenu, (void*) &s_mybrawlermain.header );
	Menu_AddItem( &s_mybrawlermain.mybrawlermenu, (void*) &s_mybrawlermain.joinDynamikeR );
	Menu_AddItem( &s_mybrawlermain.mybrawlermenu, (void*) &s_mybrawlermain.joinElPrimoR );
	Menu_AddItem( &s_mybrawlermain.mybrawlermenu, (void*) &s_mybrawlermain.joinShellyR );

}


/*
===============
MyBrawlerMain_Cache
===============
*/

void MyBrawlerMain_Cache( void ) {
	trap_R_RegisterShaderNoMip( MYBRAWLERMAIN_FRAME );
}

/*
===============
UI_MyBrawlerMainMenu
===============
*/
void UI_MyBrawlerMainMenu( void ) {
	MyBrawlerMain_MenuInit();
	UI_PushMenu ( &s_mybrawlermain.mybrawlermenu);
}

/*
===============
MyBrawlerBMain_MenuEvent
===============
*/
static void MyBrawlerBMain_MenuEvent( void* ptr, int event ) {
	if( event != QM_ACTIVATED ) {
		return;
	}

	switch( ((menucommon_s*)ptr)->id ) {

	case ID_DYNAMIKEB:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team dynamikeb\n" );
		UI_ForceMenuOff();
		break;


	case ID_ELPRIMOB:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team elprimob\n" );
		UI_ForceMenuOff();
		break;

	case ID_SHELLYB:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team shellyb\n");
		UI_ForceMenuOff();
		break;
	}
}

/*
===============
MyBrawlerBMain_MenuInit
===============
*/
void MyBrawlerBMain_MenuInit( void ) {
	int		y;
	int		gametype;
	char	info[MAX_INFO_STRING];

	memset( &s_mybrawlerbmain, 0, sizeof(s_mybrawlerbmain) );

	//MyMonsterMain_Cache();
	//TeamMain_Cache();

	y = 149;

	s_mybrawlerbmain.mybrawlerbmenu.wrapAround = qtrue;
	s_mybrawlerbmain.mybrawlerbmenu.fullscreen = qfalse;

	s_mybrawlerbmain.header.generic.type     = MTYPE_PTEXT;
	s_mybrawlerbmain.header.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	//s_mybrawlermain.header.generic.id       = ID_TNTYSON;
	//s_mybrawlermain.header.generic.callback = MyBrawlerMain_MenuEvent;
	s_mybrawlerbmain.header.generic.x        = 320;
	s_mybrawlerbmain.header.generic.y        = y;
	s_mybrawlerbmain.header.string           = "Select Brawler:";//TnTyson
	s_mybrawlerbmain.header.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlerbmain.header.color            = colorWhite;
	y += 30;
	
	s_mybrawlerbmain.joinDynamikeB.generic.type     = MTYPE_PTEXT;
	s_mybrawlerbmain.joinDynamikeB.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlerbmain.joinDynamikeB.generic.id       = ID_DYNAMIKEB;
	s_mybrawlerbmain.joinDynamikeB.generic.callback = MyBrawlerBMain_MenuEvent;
	s_mybrawlerbmain.joinDynamikeB.generic.x        = 320;
	s_mybrawlerbmain.joinDynamikeB.generic.y        = y;
	s_mybrawlerbmain.joinDynamikeB.string           = "Dynamike";//TnTyson
	s_mybrawlerbmain.joinDynamikeB.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlerbmain.joinDynamikeB.color            = colorWhite;
	y += 30;
	
	s_mybrawlerbmain.joinElPrimoB.generic.type     = MTYPE_PTEXT;
	s_mybrawlerbmain.joinElPrimoB.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlerbmain.joinElPrimoB.generic.id       = ID_ELPRIMOB;
	s_mybrawlerbmain.joinElPrimoB.generic.callback = MyBrawlerBMain_MenuEvent;
	s_mybrawlerbmain.joinElPrimoB.generic.x        = 320;
	s_mybrawlerbmain.joinElPrimoB.generic.y        = y;
	s_mybrawlerbmain.joinElPrimoB.string           = "El Primo";//El Sobrino
	s_mybrawlerbmain.joinElPrimoB.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlerbmain.joinElPrimoB.color            = colorWhite;
	y += 30;

	s_mybrawlerbmain.joinShellyB.generic.type     = MTYPE_PTEXT;
	s_mybrawlerbmain.joinShellyB.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlerbmain.joinShellyB.generic.id       = ID_SHELLYB;
	s_mybrawlerbmain.joinShellyB.generic.callback = MyBrawlerBMain_MenuEvent;
	s_mybrawlerbmain.joinShellyB.generic.x        = 320;
	s_mybrawlerbmain.joinShellyB.generic.y        = y;
	s_mybrawlerbmain.joinShellyB.string           = "Shelly";//Shelly
	s_mybrawlerbmain.joinShellyB.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlerbmain.joinShellyB.color            = colorWhite;
	y += 30;
	
	trap_GetConfigString(CS_SERVERINFO, info, MAX_INFO_STRING);   
	gametype = atoi( Info_ValueForKey( info,"g_gametype" ) );
		      

	Menu_AddItem( &s_mybrawlerbmain.mybrawlerbmenu, (void*) &s_mybrawlerbmain.header );
	Menu_AddItem( &s_mybrawlerbmain.mybrawlerbmenu, (void*) &s_mybrawlerbmain.joinDynamikeB );
	Menu_AddItem( &s_mybrawlerbmain.mybrawlerbmenu, (void*) &s_mybrawlerbmain.joinElPrimoB );
	Menu_AddItem( &s_mybrawlerbmain.mybrawlerbmenu, (void*) &s_mybrawlerbmain.joinShellyB );

}


/*
===============
MyBrawlerBMain_Cache
===============
*/

void MyBrawlerBMain_Cache( void ) {
	trap_R_RegisterShaderNoMip( MYBRAWLERBMAIN_FRAME );
}

/*
===============
UI_MyBrawlerBMainMenu
===============
*/
void UI_MyBrawlerBMainMenu( void ) {
	MyBrawlerBMain_MenuInit();
	UI_PushMenu ( &s_mybrawlerbmain.mybrawlerbmenu);
}


