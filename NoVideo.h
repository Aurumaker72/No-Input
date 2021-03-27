
#ifndef _NOVIDEO_H_INCLUDED__
#define _NOVIDEO_H_INCLUDED__

#if defined(__cplusplus)
extern "C" {
#endif


#define PLUGIN_NAME "No Video"

#define PLUGIN_TYPE_RSP 1
#define PLUGIN_TYPE_GFX 2
#define PLUGIN_TYPE_AUDIO 3
#define PLUGIN_TYPE_CONTROLLER 4

#define PLUGIN_NONE					1
#define PLUGIN_MEMPAK				2
#define PLUGIN_RUMBLE_PAK			3
#define PLUGIN_TANSFER_PAK			4
#define PLUGIN_RAW					5


#define EXPORT						__declspec(dllexport)
#define CALL						_cdecl

	typedef struct {
		WORD Version;  
		WORD Type;     
		char Name[100];
		BOOL Reserved1;
		BOOL Reserved2;
	} PLUGIN_INFO;

	typedef struct {
		HWND hWnd;			/* Render window */
		HWND hStatusBar;    /* if render window does not have a status bar then this is NULL */

		BOOL MemoryBswaped;    // If this is set to TRUE, then the memory has been pre
							   //   bswap on a dword (32 bits) boundry 
							   //	eg. the first 8 bytes are stored like this:
							   //        4 3 2 1   8 7 6 5

		BYTE* HEADER;	// This is the rom header (first 40h bytes of the rom
						// This will be in the same memory format as the rest of the memory.
		BYTE* RDRAM;
		BYTE* DMEM;
		BYTE* IMEM;

		DWORD* MI_INTR_REG;

		DWORD* DPC_START_REG;
		DWORD* DPC_END_REG;
		DWORD* DPC_CURRENT_REG;
		DWORD* DPC_STATUS_REG;
		DWORD* DPC_CLOCK_REG;
		DWORD* DPC_BUFBUSY_REG;
		DWORD* DPC_PIPEBUSY_REG;
		DWORD* DPC_TMEM_REG;

		DWORD* VI_STATUS_REG;
		DWORD* VI_ORIGIN_REG;
		DWORD* VI_WIDTH_REG;
		DWORD* VI_INTR_REG;
		DWORD* VI_V_CURRENT_LINE_REG;
		DWORD* VI_TIMING_REG;
		DWORD* VI_V_SYNC_REG;
		DWORD* VI_H_SYNC_REG;
		DWORD* VI_LEAP_REG;
		DWORD* VI_H_START_REG;
		DWORD* VI_V_START_REG;
		DWORD* VI_V_BURST_REG;
		DWORD* VI_X_SCALE_REG;
		DWORD* VI_Y_SCALE_REG;

		void (*CheckInterrupts)(void);
	} GFX_INFO;

	EXPORT void CALL CaptureScreen(char* Directory);
	EXPORT void CALL ChangeWindow(void);
	EXPORT void CALL CloseDLL(void);
	EXPORT void CALL DllAbout(HWND hParent);
	EXPORT void CALL DllConfig(HWND hParent);
	EXPORT void CALL DllTest(HWND hParent);
	EXPORT void CALL DrawScreen(void);
	EXPORT void CALL GetDllInfo(PLUGIN_INFO* PluginInfo);
	EXPORT BOOL CALL InitiateGFX(GFX_INFO Gfx_Info);
	EXPORT void CALL MoveScreen(int xpos, int ypos);
	EXPORT void CALL ProcessDList(void);
	EXPORT void CALL ProcessRDPList(void);
	EXPORT void CALL RomClosed(void);
	EXPORT void CALL RomOpen(void);
	EXPORT void CALL ShowCFB(void);
	EXPORT void CALL UpdateScreen(void);
	EXPORT void CALL ViStatusChanged(void);
	EXPORT void CALL ViWidthChanged(void);


#if defined(__cplusplus)
}
#endif
#endif