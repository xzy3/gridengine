#ifndef __SGE_GROUPS_H__
#define __SGE_GROUPS_H__
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

#include "sge_hostgroupL.h"

extern lList *Master_Host_Group_List;

bool sge_is_hostgrp_reference(const char *string);

lListElem *hostgroup_list_locate(const lList *this_list, const char *group);

lListElem *hostgroup_create(lList **answer_list, const char *name,
                            lList *hostref_or_groupref);

bool hostgroup_add_used(lListElem *this_elem, lList **answer_list,
                        const lList *hostref_or_groupref);

/* old implementation */

lListElem* sge_get_group_elem(lList *groupList, const char *groupName);

bool 
sge_is_group(lList *groupList, const char *groupName);

bool sge_is_member_in_group(lList *groupList, const char *groupName, 
                            const char *memberName, lList *rec_list);

bool 
sge_is_group_supergroup(lListElem *groupElem, const char *groupName);

bool 
sge_is_group_subgroup(lList *groupList, lListElem *groupElem, 
                      const char *groupName, lList *rec_list);

bool 
sge_add_group_elem(lList *groupList, const char *groupName, 
                   const char *subGroupName, const char *superGroupName);

bool 
sge_add_member2group(lListElem *groupElem, const char *memberName);   

bool sge_add_subgroup2group(lList **alpp, lList *groupList, 
                            lListElem *groupElem, 
                            const char *subGroupName, 
                            bool makeChanges);

bool 
sge_add_supergroup2group(lList *groupList, lListElem *groupElem, 
                         const char *superGroupName);

bool 
sge_del_subgroup_from_group(lList *groupList, lListElem *groupElem, 
                            const char *subGroupName);

bool 
sge_verify_host_group_entry(lList **alpp, lList *hostGroupList, 
                            lListElem *hostGroupElem, const char *filename);


#endif /* __SGE_GROUPS_H__ */


