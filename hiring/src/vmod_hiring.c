#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <cache/cache.h>
#include "config.h"
#include "vtim.h"

#include "vcc_hiring_if.h"


VCL_STRING
vmod_hello(VRT_CTX)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	return ("vmod-hiring");
}

const size_t infosz = 64;
char	     *info;


/*
 * handle vmod internal state, vmod init/fini and/or varnish callback
 * (un)registration here.
 *
 * malloc'ing the info buffer is only indended as a demonstration, for any
 * real-world vmod, a fixed-sized buffer should be a global variable
 */

int v_matchproto_(vmod_event_f)
vmod_event_function(VRT_CTX, struct vmod_priv *priv, enum vcl_event_e e)
{
	char	   ts[VTIM_FORMAT_SIZE];
	const char *event = NULL;

	(void) ctx;
	(void) priv;

	switch (e) {
	case VCL_EVENT_LOAD:
		info = malloc(infosz);
		if (! info)
			return (-1);
		event = "loaded";
		break;
	case VCL_EVENT_WARM:
		event = "warmed";
		break;
	case VCL_EVENT_COLD:
		event = "cooled";
		break;
	case VCL_EVENT_DISCARD:
		free(info);
		return (0);
		break;
	default:
		return (0);
	}
	AN(event);
	VTIM_format(VTIM_real(), ts);
	snprintf(info, infosz, "vmod_hiring %s at %s", event, ts);

	return (0);
}

VCL_STRING
vmod_info(VRT_CTX)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	return (info);
}

VCL_INT
vmod_count(VRT_CTX, VCL_STRING haystack, VCL_STRING needle)
{
	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);

	int needle_length = strlen(needle);
	int haystack_length = strlen(haystack);

	if (needle_length == 0 || haystack_length == 0) {
		return 0;
	}

	if (needle_length > haystack_length) {
		return 0;
	}
	
	VCL_STRING cursor = haystack;
	VCL_INT count = 0;

	while (cursor = strstr(cursor, needle)) {
		count += 1;	
		cursor += needle_length;
	}

	return count;
}	