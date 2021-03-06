MODULES = forbid_truncate
EXTENSION = forbid_truncate
DATA = forbid_truncate--1.0.sql

REGRESS = forbid_truncate

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/forbid_truncate
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
