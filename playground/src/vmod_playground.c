#include "config.h"

#include <cache/cache.h>

#include "vcc_playground_if.h"

VCL_STRING
vmod_hello(VRT_CTX)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	return ("vmod-playground");
}