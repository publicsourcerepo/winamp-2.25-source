#ifndef NULLOSFT_LOCALMEDIA_PLUGIN_MENU_HEADER
#define NULLOSFT_LOCALMEDIA_PLUGIN_MENU_HEADER


#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#include <wtypes.h>

BOOL Menu_SetRatingValue(HMENU ratingMenu, INT ratingValue);
INT Menu_TrackPopup(HMENU hMenu, UINT fuFlags, INT x, INT y,  HWND hwnd, LPTPMPARAMS lptpm);

#endif //NULLOSFT_LOCALMEDIA_PLUGIN_MENU_HEADER