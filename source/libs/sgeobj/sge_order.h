#ifndef __SGE_ORDER_H
#define __SGE_ORDER_H
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


/* struct containing the cull pos for fields in the ticket order */
typedef struct {
   int JAT_status_pos;
   int JAT_tix_pos;

   int JAT_oticket_pos;
   int JAT_fticket_pos;
   int JAT_sticket_pos;
   int JAT_share_pos;
   int JAT_prio_pos;
   int JAT_ntix_pos;   
} ja_task_pos_t;


/* struct containing the cull pos for fields in the ticket order */
typedef struct {
   int JB_version_pos;
   int JB_nppri_pos;
   int JB_nurg_pos;
   int JB_urg_pos;
   int JB_rrcontr_pos;
   int JB_dlcontr_pos;
   int JB_wtcontr_pos;
} job_pos_t;


/* struct containing the cull field position of the job target structures
   and the reduced order elements */
typedef struct {
   ja_task_pos_t ja_task;
   ja_task_pos_t order_ja_task;   
   job_pos_t   job;
   job_pos_t   order_job;
} order_pos_t;

void 
sge_free_cull_order_pos(order_pos_t **cull_order_pos);

void 
sge_create_cull_order_pos(order_pos_t **cull_order_pos, lListElem *jep, lListElem *jatp,
                          lListElem *joker, lListElem *joker_task); 
#endif /* __SGE_ORDER_H */