/*  
******************************************************************************
*
*   Copyright (C) 2001, International Business Machines
*   Corporation and others.  All Rights Reserved.
*
******************************************************************************
*   file name:  cwchar.c
*   encoding:   US-ASCII
*   tab size:   8 (not used)
*   indentation:4
*
*   created on: 2001may25
*   created by: Markus W. Scherer
*/

#include "unicode/utypes.h"

#if !U_HAVE_WCSCPY

#include "cwchar.h"

U_CAPI wchar_t *uprv_wcscat(wchar_t *dst, const wchar_t *src) {
    wchar_t *start=dst;
    while(*dst!=0) {
        ++dst;
    }
    while((*dst=*src)!=0) {
        ++dst;
        ++src;
    }
    return start;
}

U_CAPI wchar_t *uprv_wcscpy(wchar_t *dst, const wchar_t *src) {
    wchar_t *start=dst;
    while((*dst=*src)!=0) {
        ++dst;
        ++src;
    }
    return start;
}

U_CAPI size_t uprv_wcslen(const wchar_t *src) {
    const wchar_t *start=src;
    while(*src!=0) {
        ++src;
    }
    return src-start;
}

#endif

size_t uprv_impl_mbstowcs(wchar_t *pwcs, const char *s, size_t n) {
   if (pwcs == NULL)
       return strlen(s);

    return mbsrtowcs(pwcs, &s, n, NULL);
}

size_t uprv_impl_wcstombs(char *s, const wchar_t *pwcs, size_t n) {
    return wcsrtombs(s, &pwcs, n, NULL);
}

