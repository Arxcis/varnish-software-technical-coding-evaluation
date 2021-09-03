AM_CFLAGS = $(VARNISHAPI_CFLAGS)

# Modules

vmod_LTLIBRARIES = \
	libvmod_hiring.la

libvmod_hiring_la_LDFLAGS = $(VMOD_LDFLAGS)
libvmod_hiring_la_SOURCES = vmod_hiring.c
nodist_libvmod_hiring_la_SOURCES = \
	vcc_hiring_if.c \
	vcc_hiring_if.h

@BUILD_VMOD_HIRING@

# Test suite

AM_TESTS_ENVIRONMENT = \
	PATH="$(abs_builddir):$(VARNISH_TEST_PATH):$(PATH)" \
	LD_LIBRARY_PATH="$(VARNISH_LIBRARY_PATH)"
TEST_EXTENSIONS = .vtc
VTC_LOG_COMPILER = varnishtest -v
AM_VTC_LOG_FLAGS = \
	-p vcl_path="$(abs_top_srcdir)/vcl:$(VARNISHAPI_VCLDIR)" \
	-p vmod_path="$(abs_builddir)/.libs:$(vmoddir):$(VARNISHAPI_VMODDIR)"

TESTS = \
	vtc/vmod_hiring.vtc

# Documentation

dist_doc_DATA = \
	vmod_hiring.vcc \
	$(TESTS)

dist_man_MANS = \
	vmod_hiring.3


.rst.1:
	$(AM_V_GEN) $(RST2MAN) $< $@
