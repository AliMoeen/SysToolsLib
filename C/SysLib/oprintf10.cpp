/*****************************************************************************\
*                                                                             *
*   File name:	    oprintf10.cpp					      *
*                                                                             *
*   Description:    Generalized C++ object formatting - 10-argument option    *
*                                                                             *
*   Notes:                                                                    *
*                                                                             *
*   History:								      *
*    2021-11-05 JFL Created this module.				      *
*                                                                             *
\*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "oprintf.h"

#if defined(_MSC_VER)
#pragma warning(disable:4100) /* Avoid warnings "unreferenced formal parameter" */
#endif /* defined(_MSC_VER) */

/*---------------------------------------------------------------------------*\
*                                                                             *
|   Functions       printf family					      |
|									      |
|   Description     Print to standard output                                  |
|									      |
|   Parameters	    char *pszFormat	    Format string                     |
|		    OPFARG oa   	    Formattable object list           |
|		     ...						      |
|									      |
|   Returns	    The size of the resulting string. 			      |
|									      |
|   Notes	    							      |
|									      |
|   History								      |
|    2008/03/20 JFL Created this routine.				      |
*									      *
\*---------------------------------------------------------------------------*/

int CDECL oprintf(const char *pszForm, OPFA oa0, OPFA oa1, OPFA oa2, OPFA oa3, OPFA oa4, OPFA oa5, OPFA oa6, OPFA oa7, OPFA oa8, OPFA oa9)
    {
#if ARGS_ON_STACK
    const OPFARG **poaList;
    poaList = (const OPFARG **)((&pszForm)+1);
#else
    const OPFARG *poaList[10];
    poaList[0] = &oa0;
    poaList[1] = &oa1;
    poaList[2] = &oa2;
    poaList[3] = &oa3;
    poaList[4] = &oa4;
    poaList[5] = &oa5;
    poaList[6] = &oa6;
    poaList[7] = &oa7;
    poaList[8] = &oa8;
    poaList[9] = &oa9;
#endif
    return ovprintf(pszForm, poaList, 10);
    }

/*---------------------------------------------------------------------------*\
*                                                                             *
|   Functions       snprintf family					      |
|									      |
|   Description     Print to a string.					      |
|									      |
|   Parameters	    char *pszBuf	    Output string       	      |
|		    size_t iSize	    Output buffer size                |
|		    char *pszFormat	    Format string                     |
|		    OPFARG oa   	    Formattable object list           |
|		     ...						      |
|									      |
|   Returns	    The size of the resulting string. 			      |
|									      |
|   Notes	    							      |
|									      |
|   History								      |
|    2008/03/20 JFL Created this routine.				      |
*									      *
\*---------------------------------------------------------------------------*/

int CDECL osnprintf(char *pszBuf, size_t iSize, const char *pszForm, OPFA oa0, OPFA oa1, OPFA oa2, OPFA oa3, OPFA oa4, OPFA oa5, OPFA oa6, OPFA oa7, OPFA oa8, OPFA oa9)
    {
#if ARGS_ON_STACK
    const OPFARG **poaList;
    poaList = (const OPFARG **)((&pszForm)+1);
#else
    const OPFARG *poaList[10];
    poaList[0] = &oa0;
    poaList[1] = &oa1;
    poaList[2] = &oa2;
    poaList[3] = &oa3;
    poaList[4] = &oa4;
    poaList[5] = &oa5;
    poaList[6] = &oa6;
    poaList[7] = &oa7;
    poaList[8] = &oa8;
    poaList[9] = &oa9;
#endif
    return ovsnprintf(pszBuf, iSize, pszForm, poaList, 10);
    }

#if defined(_MSC_VER)
#pragma warning(default:4100)
#endif /* defined(_MSC_VER) */

