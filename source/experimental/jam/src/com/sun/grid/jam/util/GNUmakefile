#___INFO__MARK_BEGIN__
#########################################################################
# 
#  The Contents of this file are made available subject to the terms of
#  the Sun Industry Standards Source License Version 1.2
# 
#  Sun Microsystems Inc., March, 2001
# 
# 
#  Sun Industry Standards Source License Version 1.2
#  =================================================
#  The contents of this file are subject to the Sun Industry Standards
#  Source License Version 1.2 (the "License"); You may not use this file
#  except in compliance with the License. You may obtain a copy of the
#  License at http://gridengine.sunsource.net/Gridengine_SISSL_license.html
# 
#  Software provided under this License is provided on an "AS IS" basis,
#  WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING,
#  WITHOUT LIMITATION, WARRANTIES THAT THE SOFTWARE IS FREE OF DEFECTS,
#  MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE, OR NON-INFRINGING.
#  See the License for the specific provisions governing your rights and
#  obligations concerning the Software.
# 
#   The Initial Developer of the Original Code is: Sun Microsystems, Inc.
#   and/or Swiss Center for Scientific Computing
# 
#   Copyright: 2002 by Sun Microsystems, Inc.
#   Copyright: 2002 by Swiss Center for Scientific Computing
# 
#   All Rights Reserved.
# 
########################################################################
#___INFO__MARK_END__
include $(TOPDIR)/GNUmakefileConstants.gmk
include $(TOPDIR)/GNUmakefileRules.gmk

SRC = JAMAdmin JAMAdminProxy JAMProxy JAMServiceRegistrar \
	RemoteInputStreamInterface RemoteInputStream

STUB = JAMServiceRegistrar RemoteInputStream

JPACKAGE = com.sun.grid.jam.util.
PACKAGE = com/sun/grid/jam/util

vpath %.class $(CODEBASE)/$(PACKAGE)

.PHONY: all lib stub doc clean

all: lib

lib: $(addsuffix .class, $(SRC))

stub: $(addsuffix _Stub.class, $(STUB))

clean:
