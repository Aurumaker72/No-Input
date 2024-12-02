
#ifndef _NOINPUT_H_INCLUDED__
#define _NOINPUT_H_INCLUDED__

#if defined(__cplusplus)
#include <cstdint>
extern "C" {
#endif


#define PLUGIN_NAME "No Sound"

#define PLUGIN_TYPE_CONTROLLER		4
#define PLUGIN_TYPE_SOUND 3

#define PLUGIN_NONE					1
#define PLUGIN_MEMPAK				2
#define PLUGIN_RUMBLE_PAK			3
#define PLUGIN_TANSFER_PAK			4
#define PLUGIN_RAW					5


#define EXPORT						__declspec(dllexport)
#define CALL						_cdecl

	typedef struct
	{
		uint16_t Version;
		uint16_t Type;
		char Name[100];

		/* If DLL supports memory these memory options then set them to TRUE or FALSE
		   if it does not support it */
		int32_t NormalMemory; /* a normal uint8_t array */
		int32_t MemoryBswaped; /* a normal uint8_t array where the memory has been pre
								 bswap on a dword (32 bits) boundry */
	} PLUGIN_INFO;

	typedef struct
	{
		void* hInst;
		// Whether the memory has been pre-byteswapped on a uint32_t boundary
		int32_t MemoryBswaped;
		uint8_t* RDRAM;
		uint8_t* DMEM;
		uint8_t* IMEM;

		uint32_t* MI_INTR_REG;

		uint32_t* SP_MEM_ADDR_REG;
		uint32_t* SP_DRAM_ADDR_REG;
		uint32_t* SP_RD_LEN_REG;
		uint32_t* SP_WR_LEN_REG;
		uint32_t* SP_STATUS_REG;
		uint32_t* SP_DMA_FULL_REG;
		uint32_t* SP_DMA_BUSY_REG;
		uint32_t* SP_PC_REG;
		uint32_t* SP_SEMAPHORE_REG;

		uint32_t* DPC_START_REG;
		uint32_t* DPC_END_REG;
		uint32_t* DPC_CURRENT_REG;
		uint32_t* DPC_STATUS_REG;
		uint32_t* DPC_CLOCK_REG;
		uint32_t* DPC_BUFBUSY_REG;
		uint32_t* DPC_PIPEBUSY_REG;
		uint32_t* DPC_TMEM_REG;

		void(__cdecl* CheckInterrupts)(void);
		void(__cdecl* ProcessDlistList)(void);
		void(__cdecl* ProcessAlistList)(void);
		void(__cdecl* ProcessRdpList)(void);
		void(__cdecl* ShowCFB)(void);
	} RSP_INFO;

	typedef struct
	{
		void* hWnd; /* Render window */
		void* hStatusBar;
		/* if render window does not have a status bar then this is NULL */

		int32_t MemoryBswaped; // If this is set to TRUE, then the memory has been pre
		//   bswap on a dword (32 bits) boundry
		//	eg. the first 8 bytes are stored like this:
		//        4 3 2 1   8 7 6 5

		uint8_t* HEADER; // This is the rom header (first 40h bytes of the rom
		// This will be in the same memory format as the rest of the memory.
		uint8_t* RDRAM;
		uint8_t* DMEM;
		uint8_t* IMEM;

		uint32_t* MI_INTR_REG;

		uint32_t* DPC_START_REG;
		uint32_t* DPC_END_REG;
		uint32_t* DPC_CURRENT_REG;
		uint32_t* DPC_STATUS_REG;
		uint32_t* DPC_CLOCK_REG;
		uint32_t* DPC_BUFBUSY_REG;
		uint32_t* DPC_PIPEBUSY_REG;
		uint32_t* DPC_TMEM_REG;

		uint32_t* VI_STATUS_REG;
		uint32_t* VI_ORIGIN_REG;
		uint32_t* VI_WIDTH_REG;
		uint32_t* VI_INTR_REG;
		uint32_t* VI_V_CURRENT_LINE_REG;
		uint32_t* VI_TIMING_REG;
		uint32_t* VI_V_SYNC_REG;
		uint32_t* VI_H_SYNC_REG;
		uint32_t* VI_LEAP_REG;
		uint32_t* VI_H_START_REG;
		uint32_t* VI_V_START_REG;
		uint32_t* VI_V_BURST_REG;
		uint32_t* VI_X_SCALE_REG;
		uint32_t* VI_Y_SCALE_REG;

		void(__cdecl* CheckInterrupts)(void);
	} GFX_INFO;

	typedef struct
	{
		void* hwnd;
		void* hinst;

		int32_t MemoryBswaped; // If this is set to TRUE, then the memory has been pre
		//   bswap on a dword (32 bits) boundry
		//	eg. the first 8 bytes are stored like this:
		//        4 3 2 1   8 7 6 5
		uint8_t* HEADER; // This is the rom header (first 40h bytes of the rom
		// This will be in the same memory format as the rest of the memory.
		uint8_t* RDRAM;
		uint8_t* DMEM;
		uint8_t* IMEM;

		uint32_t* MI_INTR_REG;

		uint32_t* AI_DRAM_ADDR_REG;
		uint32_t* AI_LEN_REG;
		uint32_t* AI_CONTROL_REG;
		uint32_t* AI_STATUS_REG;
		uint32_t* AI_DACRATE_REG;
		uint32_t* AI_BITRATE_REG;

		void(__cdecl* CheckInterrupts)(void);
	} AUDIO_INFO;

	typedef struct
	{
		int32_t Present;
		int32_t RawData;
		int32_t Plugin;
	} CONTROL;

	typedef union
	{
		uint32_t Value;

		struct
		{
			unsigned R_DPAD : 1;
			unsigned L_DPAD : 1;
			unsigned D_DPAD : 1;
			unsigned U_DPAD : 1;
			unsigned START_BUTTON : 1;
			unsigned Z_TRIG : 1;
			unsigned B_BUTTON : 1;
			unsigned A_BUTTON : 1;

			unsigned R_CBUTTON : 1;
			unsigned L_CBUTTON : 1;
			unsigned D_CBUTTON : 1;
			unsigned U_CBUTTON : 1;
			unsigned R_TRIG : 1;
			unsigned L_TRIG : 1;
			unsigned Reserved1 : 1;
			unsigned Reserved2 : 1;

			signed Y_AXIS : 8;

			signed X_AXIS : 8;
		};
	} BUTTONS;

	typedef struct
	{
		void* hMainWindow;
		void* hinst;

		int32_t MemoryBswaped; // If this is set to TRUE, then the memory has been pre
		//   bswap on a dword (32 bits) boundry, only effects header.
		//	eg. the first 8 bytes are stored like this:
		//        4 3 2 1   8 7 6 5
		uint8_t* HEADER; // This is the rom header (first 40h bytes of the rom)
		CONTROL* Controls; // A pointer to an array of 4 controllers .. eg:
		// CONTROL Controls[4];
	} CONTROL_INFO;

	EXPORT void CALL DllAbout(HWND hParent);
	EXPORT void CALL GetDllInfo(PLUGIN_INFO* PluginInfo);


#if defined(__cplusplus)
}
#endif
#endif