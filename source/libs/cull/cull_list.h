#ifndef __CULL_LIST_H
#define __CULL_LIST_H
/*___INFO__MARK_BEGIN__*/
/*************************************************************************
 * 
 *  The Contents of this file are made available subject to the terms of
 *  the Sun Industry Standards Source License Version 1.2
 * 
 *  Sun Microsystems Inc., March, 2001
 * 
 * 
 *  Sun Industry Standards Source License Version 1.2
 *  =================================================
 *  The contents of this file are subject to the Sun Industry Standards
 *  Source License Version 1.2 (the "License"); You may not use this file
 *  except in compliance with the License. You may obtain a copy of the
 *  License at http://gridengine.sunsource.net/Gridengine_SISSL_license.html
 * 
 *  Software provided under this License is provided on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
 *  WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
 *  MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
 *  See the License for the specific provisions governing your rights and
 *  obligations concerning the Software.
 * 
 *   The Initial Developer of the Original Code is: Sun Microsystems, Inc.
 * 
 *   Copyright: 2001 by Sun Microsystems, Inc.
 * 
 *   All Rights Reserved.
 * 
 ************************************************************************/
/*___INFO__MARK_END__*/

#include <stdio.h> 

#include "basis_types.h"

#ifdef  __cplusplus
extern "C" {
#endif

#define NoName -1

typedef float lFloat;
typedef double lDouble;
typedef u_long32 lUlong;
typedef long lLong;
typedef char lChar;
typedef int lInt;
typedef char *lString;
typedef char *lHost;      /* CR - hostname change */
typedef void*  lRef;
typedef struct _lDescr lDescr;
typedef struct _lNameSpace lNameSpace;
typedef struct _lList lList;
typedef struct _lListElem lListElem;
typedef struct _lCondition lCondition;
typedef struct _lEnumeration lEnumeration;
typedef union _lMultiType lMultiType;
typedef struct _lSortOrder lSortOrder;
typedef struct _WhereArg WhereArg, *WhereArgList;
typedef struct _lHash lHash;

/* IF YOU CHANGE THIS ENUM, CHANGE cull_multitype.c/multitypes[] */
enum _enum_lMultiType {
   lEndT,                       /* This is the end of the descriptor */
   lFloatT,
   lDoubleT,
   lUlongT,
   lLongT,
   lCharT,
   lIntT,
   lStringT,
   lListT,
   lRefT,
   lHostT             /* CR - hostname change */
};

#ifdef __SGE_GDI_LIBRARY_HOME_OBJECT_FILE__

#define LISTDEF( name ) lDescr name[] = {
#define XLISTDEF( name, idlname ) lDescr name[] = {
#define ILISTDEF( name, idlname, listname ) lDescr name[] = {
#define SLISTDEF( name, idlname ) lDescr name[] = {
#define LISTEND {NoName, lEndT, NULL}};

#define SGE_INT(name) { name, lIntT, NULL },
#define SGE_RINT(name) { name, lIntT, NULL },
#define SGE_IINT(name)
#define SGE_IRINT(name)
#define SGE_XINT(name) { name, lIntT, NULL },
#define SGE_HOST(name) { name, lHostT, NULL },                    /* CR - hostname change */
#ifdef CULL_NO_HASH
#define SGE_HOSTH(name) { name, lHostT, NULL },                   /* CR - hostname change */
#define SGE_HOSTHU(name) { name, lHostT, NULL },                  /* CR - hostname change */
#else
#define SGE_HOSTH(name) { name, lHostT, &template_hash },         /* CR - hostname change */
#define SGE_HOSTHU(name) { name, lHostT, &template_hash_unique }, /* CR - hostname change */
#endif
#define SGE_STRING(name) { name, lStringT, NULL },
#ifdef CULL_NO_HASH
#define SGE_STRINGH(name) { name, lStringT, NULL },
#define SGE_STRINGHU(name) { name, lStringT, NULL },
#else
#define SGE_STRINGH(name) { name, lStringT, &template_hash },
#define SGE_STRINGHU(name) { name, lStringT, &template_hash_unique },
#endif
#define SGE_KSTRING(name) { name, lStringT, NULL },
#ifdef CULL_NO_HASH
#define SGE_KSTRINGH(name) { name, lStringT, NULL },
#define SGE_KSTRINGHU(name) { name, lStringT, NULL },
#else
#define SGE_KSTRINGH(name) { name, lStringT, &template_hash },
#define SGE_KSTRINGHU(name) { name, lStringT, &template_hash_unique },
#endif
#define SGE_RSTRING(name) { name, lStringT, NULL },
#ifdef CULL_NO_HASH
#define SGE_RSTRINGH(name) { name, lStringT, NULL },
#define SGE_RSTRINGHU(name) { name, lStringT, NULL },
#else
#define SGE_RSTRINGH(name) { name, lStringT, &template_hash },
#define SGE_RSTRINGHU(name) { name, lStringT, &template_hash_unique },
#endif
#define SGE_ISTRING(name)
#define SGE_IRSTRING(name)
#define SGE_XSTRING(name) { name, lStringT, NULL },
#ifdef CULL_NO_HASH
#define SGE_XSTRINGH(name) { name, lStringT, NULL },
#define SGE_XSTRINGHU(name) { name, lStringT, NULL },
#else
#define SGE_XSTRINGH(name) { name, lStringT, &template_hash },
#define SGE_XSTRINGHU(name) { name, lStringT, &template_hash_unique },
#endif
#define SGE_FLOAT(name) { name, lFloatT, NULL },
#define SGE_IFLOAT(name)
#define SGE_RFLOAT(name) { name, lFloatT, NULL },
#define SGE_IRFLOAT(name)
#define SGE_XFLOAT(name) { name, lFloatT, NULL },
#define SGE_DOUBLE(name) { name, lDoubleT, NULL },
#define SGE_IDOUBLE(name)
#define SGE_RDOUBLE(name) { name, lDoubleT, NULL },
#define SGE_IRDOUBLE(name)
#define SGE_XDOUBLE(name) { name, lDoubleT, NULL },
#define SGE_CHAR(name) { name, lCharT, NULL },
#define SGE_ICHAR(name)
#define SGE_RCHAR(name) { name, lCharT, NULL },
#define SGE_IRCHAR(name)
#define SGE_XCHAR(name) { name, lCharT, NULL },
#define SGE_LONG(name) { name, lLongT, NULL },
#define SGE_ILONG(name)
#define SGE_RLONG(name) { name, lLongT, NULL },
#define SGE_IRLONG(name)
#define SGE_XLONG(name) { name, lLongT, NULL },
#define SGE_ULONG(name) { name, lUlongT, NULL },
#ifdef CULL_NO_HASH
#define SGE_ULONGH(name) { name, lUlongT, NULL },
#define SGE_ULONGHU(name) { name, lUlongT, NULL },
#else
#define SGE_ULONGH(name) { name, lUlongT, &template_hash },
#define SGE_ULONGHU(name) { name, lUlongT, &template_hash_unique },
#endif
#define SGE_KULONG(name) { name, lUlongT, NULL },
#ifdef CULL_NO_HASH
#define SGE_KULONGH(name) { name, lUlongT, NULL },
#define SGE_KULONGHU(name) { name, lUlongT, NULL },
#else
#define SGE_KULONGH(name) { name, lUlongT, &template_hash },
#define SGE_KULONGHU(name) { name, lUlongT, &template_hash_unique },
#endif
#define SGE_IULONG(name)
#define SGE_RULONG(name) { name, lUlongT, NULL },
#define SGE_IRULONG(name)
#define SGE_XULONG(name) { name, lUlongT, NULL },
#ifdef CULL_NO_HASH
#define SGE_XULONGH(name) { name, lUlongT, NULL },
#define SGE_XULONGHU(name) { name, lUlongT, NULL },
#else
#define SGE_XULONGH(name) { name, lUlongT, &template_hash },
#define SGE_XULONGHU(name) { name, lUlongT, &template_hash_unique },
#endif
#define SGE_BOOL(name) { name, lUlongT, NULL },
#define SGE_IBOOL(name)
#define SGE_RBOOL(name) { name, lUlongT, NULL },
#define SGE_IRBOOL(name)
#define SGE_XBOOL(name) { name, lUlongT, NULL },

#define SGE_LIST(name) { name, lListT, NULL },
#define SGE_TLIST(name, type) { name, lListT, NULL },
#define SGE_ILIST(name, type)
#define SGE_RLIST(name, type) { name, lListT, NULL },
#define SGE_IRLIST(name, type)
#define SGE_XLIST(name, type) { name, lListT, NULL },
#define SGE_OBJECT(name, type) { name, lListT, NULL },
#define SGE_IOBJECT(name, type)
#define SGE_ROBJECT(name, type) { name, lListT, NULL },
#define SGE_IROBJECT(name, type)
#define SGE_XOBJECT(name, type) { name, lListT, NULL },

#define SGE_REF(name) { name, lRefT, NULL },

#define NAMEDEF( name ) char *name[] = {
#define NAME( name ) name ,
#define NAMEEND    };

#else

#define LISTDEF( name ) extern lDescr name[];
#define XLISTDEF( name, idlname ) extern lDescr name[];
#define ILISTDEF( name, idlname, listname ) extern lDescr name[];
#define SLISTDEF( name, idlname ) extern lDescr name[];
#define LISTEND

#define SGE_INT(name)
#define SGE_IINT(name)
#define SGE_RINT(name)
#define SGE_IRINT(name)
#define SGE_XINT(name)
#define SGE_HOST(name)
#define SGE_HOSTH(name)
#define SGE_HOSTHU(name)
#define SGE_STRING(name)
#define SGE_STRINGH(name)
#define SGE_STRINGHU(name)
#define SGE_KSTRING(name)
#define SGE_KSTRINGH(name)
#define SGE_KSTRINGHU(name)
#define SGE_ISTRING(name)
#define SGE_RSTRING(name)
#define SGE_RSTRINGH(name)
#define SGE_RSTRINGHU(name)
#define SGE_IRSTRING(name)
#define SGE_XSTRING(name)
#define SGE_XSTRINGH(name)
#define SGE_XSTRINGHU(name)
#define SGE_FLOAT(name)
#define SGE_IFLOAT(name)
#define SGE_RFLOAT(name)
#define SGE_IRFLOAT(name)
#define SGE_XFLOAT(name)
#define SGE_DOUBLE(name)
#define SGE_IDOUBLE(name)
#define SGE_RDOUBLE(name)
#define SGE_IRDOUBLE(name)
#define SGE_XDOUBLE(name)
#define SGE_CHAR(name)
#define SGE_ICHAR(name)
#define SGE_RCHAR(name)
#define SGE_IRCHAR(name)
#define SGE_XCHAR(name)
#define SGE_LONG(name)
#define SGE_ILONG(name)
#define SGE_RLONG(name)
#define SGE_IRLONG(name)
#define SGE_XLONG(name)
#define SGE_ULONG(name)
#define SGE_ULONGH(name)
#define SGE_ULONGHU(name)
#define SGE_KULONG(name)
#define SGE_KULONGH(name)
#define SGE_KULONGHU(name)
#define SGE_IULONG(name)
#define SGE_RULONG(name)
#define SGE_IRULONG(name)
#define SGE_XULONG(name)
#define SGE_XULONGH(name)
#define SGE_XULONGHU(name)
#define SGE_BOOL(name)
#define SGE_IBOOL(name)
#define SGE_RBOOL(name)
#define SGE_IRBOOL(name)
#define SGE_XBOOL(name)

#define SGE_LIST(name)
#define SGE_TLIST(name, type)
#define SGE_ILIST(name, type)
#define SGE_RLIST(name, type)
#define SGE_IRLIST(name, type)
#define SGE_XLIST(name, type)
#define SGE_OBJECT(name, type)
#define SGE_IOBJECT(name, type)
#define SGE_ROBJECT(name, type)
#define SGE_IROBJECT(name, type)
#define SGE_XOBJECT(name, type)

#define SGE_REF(name)

#define NAMEDEF( name ) extern char *name[];
#define NAME( name )
#define NAMEEND

#endif

struct _lNameSpace {
   int lower;
   int size;
   char **namev;
};

struct _lDescr {
   int nm;                             /* name */
   int mt;                             /* multitype information */
   lHash *hash;
};

/* LIST SPECIFIC FUNCTIONS */
const char *lGetListName(const lList *lp);
const lDescr *lGetListDescr(const lList *lp);
int lGetNumberOfElem(const lList *lp);
int lGetNumberOfRemainingElem(const lListElem *ep);
int lGetElemIndex(const lListElem *ep, const lList *lp);

const lDescr *lGetElemDescr(const lListElem *ep);

void lWriteElem(const lListElem *ep);
void lWriteElemTo(const lListElem *ep, FILE *fp);
void lWriteList(const lList *lp);
void lWriteListTo(const lList *lp, FILE *fp);

lListElem *lCreateElem(const lDescr *dp);
lList *lCreateList(const char *listname, const lDescr *descr);
lList *lCreateElemList(const char *listname, const lDescr *descr, int nr_elem);

lListElem *lFreeElem(lListElem *ep);
lList *lFreeList(lList *lp);

int lAddList(lList *lp0, lList *lp1);
int lCompListDescr(const lDescr *dp0, const lDescr *dp1);
lList *lCopyList(const char *name, const lList *src);
lListElem *lCopyElem(const lListElem *src);
int lModifyWhat(lListElem *dst, const lListElem *src, const lEnumeration *enp);

int lCopyElemPartial(lListElem *dst, int *jp, const lListElem *src, const lEnumeration *ep);
int lCopySwitch(const lListElem *sep, lListElem *dep, int src_idx, int dst_idx);

int lAppendElem(lList *lp, lListElem *ep);
lListElem *lDechainElem(lList *lp, lListElem *ep);
int lRemoveElem(lList *lp, lListElem *ep);
int lInsertElem(lList *lp, lListElem *ep, lListElem *new_elem);

int lPSortList(lList *lp, const char *fmt, ...);
int lSortList(lList *lp, const lSortOrder *sp);
int lSortList2(lList *lp, const char *fmt, ...);
int lUniqStr(lList *lp, int keyfield);
int lUniqHost(lList *lp, int keyfield);



lListElem *lFirst(const lList *lp);
lListElem *lLast(const lList *lp);
lListElem *lNext(const lListElem *ep);
lListElem *lPrev(const lListElem *ep);

lListElem *lFindNext(const lListElem *ep, const lCondition *cp);
lListElem *lFindPrev(const lListElem *ep, const lCondition *cp);
lListElem *lFindFirst(const lList *lp, const lCondition *cp);
lListElem *lFindLast(const lList *lp, const lCondition *cp);


/* #define for_each(ep,lp) for (ep=lFirst(lp);ep;ep=lNext(ep)) */
/* #define for_each_rev(ep,lp) for (ep=lLast(lp);ep;ep=lPrev(ep)) */

#ifndef __cplusplus
#define for_each(ep,lp) for (ep = ((lp) ? (lp)->first : (lListElem *) NULL); ep; ep = ep->next)
#else
#define for_each_cpp(ep,lp) for (ep = ((lp) ? (lp)->first : (lListElem *) NULL); ep; ep = ep->next)
#endif
#define for_each_rev(ep,lp) for (ep = ((lp) ? (lp)->last : (lListElem *) NULL); ep; ep = ep->prev)

#define for_each_where(ep,lp,cp) \
   for (ep=lFindFirst(lp,cp);ep;ep=lFindNext(ep,cp))
#define for_each_where_rev(ep,lp,cp) \
   for (ep=lFindLast(lp,cp);ep;ep=lFindPrev(ep,cp))

#ifdef  __cplusplus
}
#endif

#endif /* #ifndef __CULL_LIST_H */

