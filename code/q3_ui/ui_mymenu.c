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
//#define MYEARTHMAIN_FRAME	"menu/art/cut_frame"

//IDs to call object
#define ID_TNTYSON		200
#define ID_ELSOBRINO	201
#define ID_SHELLY		202

int teamFlag; //0 is TNTyson, 1 is El Sobrino, 2 is Shelly


typedef struct
{
	menuframework_s mybrawlermenu;
	menubitmap_s	myframe;
	menutext_s		header;
	menutext_s		joinTntyson;
	menutext_s		joinElsobrino;
	menutext_s		joinShelly;

}mybrawlermain_t;

static mybrawlermain_t	s_mybrawlermain;



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

	case ID_TNTYSON:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team tntyson\n" );
		UI_ForceMenuOff();
		break;

	case ID_ELSOBRINO:
		trap_Cmd_ExecuteText( EXEC_APPEND, "cmd team elsobrino\n" );
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
	
	s_mybrawlermain.joinTntyson.generic.type     = MTYPE_PTEXT;
	s_mybrawlermain.joinTntyson.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlermain.joinTntyson.generic.id       = ID_TNTYSON;
	s_mybrawlermain.joinTntyson.generic.callback = MyBrawlerMain_MenuEvent;
	s_mybrawlermain.joinTntyson.generic.x        = 320;
	s_mybrawlermain.joinTntyson.generic.y        = y;
	s_mybrawlermain.joinTntyson.string           = "Dynamike";//TnTyson
	s_mybrawlermain.joinTntyson.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlermain.joinTntyson.color            = colorWhite;
	y += 30;
	
	s_mybrawlermain.joinElsobrino.generic.type     = MTYPE_PTEXT;
	s_mybrawlermain.joinElsobrino.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlermain.joinElsobrino.generic.id       = ID_ELSOBRINO;
	s_mybrawlermain.joinElsobrino.generic.callback = MyBrawlerMain_MenuEvent;
	s_mybrawlermain.joinElsobrino.generic.x        = 320;
	s_mybrawlermain.joinElsobrino.generic.y        = y;
	s_mybrawlermain.joinElsobrino.string           = "El Primo";//El Sobrino
	s_mybrawlermain.joinElsobrino.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlermain.joinElsobrino.color            = colorWhite;
	y += 30;

	s_mybrawlermain.joinShelly.generic.type     = MTYPE_PTEXT;
	s_mybrawlermain.joinShelly.generic.flags    = QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS;
	s_mybrawlermain.joinShelly.generic.id       = ID_SHELLY;
	s_mybrawlermain.joinShelly.generic.callback = MyBrawlerMain_MenuEvent;
	s_mybrawlermain.joinShelly.generic.x        = 320;
	s_mybrawlermain.joinShelly.generic.y        = y;
	s_mybrawlermain.joinShelly.string           = "Shelly";//Shelly
	s_mybrawlermain.joinShelly.style            = UI_CENTER|UI_BIGFONT|UI_DROPSHADOW;
	s_mybrawlermain.joinShelly.color            = colorWhite;
	y += 30;
	
	trap_GetConfigString(CS_SERVERINFO, info, MAX_INFO_STRING);   
	gametype = atoi( Info_ValueForKey( info,"g_gametype" ) );
		      

	Menu_AddItem( &s_mybrawlermain.mybrawlermenu, (void*) &s_mybrawlermain.header );
	Menu_AddItem( &s_mybrawlermain.mybrawlermenu, (void*) &s_mybrawlermain.joinTntyson );
	Menu_AddItem( &s_mybrawlermain.mybrawlermenu, (void*) &s_mybrawlermain.joinElsobrino );
	Menu_AddItem( &s_mybrawlermain.mybrawlermenu, (void*) &s_mybrawlermain.joinShelly );

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


