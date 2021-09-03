AM_CFLAGS = $(VARNISHAPI_CFLAGS)

# Modules

vmod_LTLIBRARIES = \
	libvmod_playground.la

libvmod_playground_la_LDFLAGS = $(VMOD_LDFLAGS)
libvmod_playground_la_SOURCES = vmod_playground.c
nodist_libvmod_playground_la_SOURCES = \
	vcc_playground_if.c \
	vcc_playground_if.h

@BUILD_VMOD_PLAYGROUND@

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
	vtc/vmod_playground.vtc

# Documentation

dist_doc_DATA = \
	vmod_playground.vcc \
	$(TESTS)

dist_man_MANS = \
	vmod_playground.3


.rst.1:
	$(AM_V_GEN) $(RST2MAN) $< $@
