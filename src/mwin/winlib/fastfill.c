#include "windows.h"
#include "wintools.h"
/*
 * WIN Draw Library
 *	Fast fill rectangle
 */


#define USE_COLORED_BACKGROUND 1  /* visualize text RECTs */

#if USE_COLORED_BACKGROUND
#include "nxcolors.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#endif


/*
 * fast fill background (works with non-dithered colors only)
 */
void WINAPI
FastFillRect(HDC hdc,LPRECT lprect,COLORREF cr)
{
	COLORREF	crOld;
	
#if USE_COLORED_BACKGROUND
#warning USE_COLORED_BACKGROUND in FastFillRect
    static int s_showFillRect = 0;  // 0: read cfg, 1: no, 2: yes
    if (!s_showFillRect) {  // read showFillRect - cfg from file:
		int fh = open("/mnt/sc1000/set/showfill", O_RDONLY);
		char bf[4] = {0};
		if (fh < 0) {
			s_showFillRect = 1;
		}
		else {
			lseek(fh, 0, SEEK_SET);
			read(fh, bf, 2);
			close(fh);
			if (bf[0] == '1')
				s_showFillRect = 2;
			else
				s_showFillRect = 1;
		}
	}
	if (s_showFillRect == 2) {  // use modified bg color:
		static int c = 0;
		unsigned int col;
		switch(++c % 11) {;
			case 0:		col = GR_COLOR_HOTPINK2;		break;
			case 1:		col = GR_COLOR_PALEVIOLETRED2;	break;
			case 2:		col = GR_COLOR_MAGENTA3;		break;
			case 3:		col = GR_COLOR_ORCHID2;			break;
			case 4:		col = GR_COLOR_PURPLE1;			break;
			case 5:		col = GR_COLOR_THISTLE1;		break;
			case 6:		col = GR_COLOR_INDIANRED1;		break;
			case 7:		col = GR_COLOR_GOLD2;			break;
			case 8:		col = GR_COLOR_PALEGREEN4;		break;
			case 9:		col = GR_COLOR_SPRINGGREEN2;	break;
			case 10:	col = GR_COLOR_TURQUOISE2;		break;
		}
		cr = col;
	}
#endif

	crOld = SetBkColor( hdc, cr);
	ExtTextOut( hdc, 0, 0, ETO_OPAQUE | ETO_CLIPPED, lprect, NULL, 0, NULL);
	SetBkColor( hdc, crOld);
}
