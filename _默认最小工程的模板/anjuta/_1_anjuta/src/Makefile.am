## Process this file with automake to produce Makefile.in

## Created by Anjuta


uidir = $(pkgdatadir)/ui
ui_DATA = _1_.ui


AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(_1__CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

bin_PROGRAMS = _1_

_1__SOURCES = \
	main.c \
	_1_.h \
	_1_.c	


_1__LDFLAGS = \
	-Wl,--export-dynamic

_1__LDADD = $(_1__LIBS)




EXTRA_DIST = $(ui_DATA)

# Remove ui directory on uninstall
uninstall-local:
	-rm -r $(uidir)
	-rm -r $(pkgdatadir)

