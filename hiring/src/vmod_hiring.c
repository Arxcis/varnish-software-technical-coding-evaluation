#include "config.h"

#include <cache/cache.h>

#include "vcc_hiring_if.h"

VCL_STRING
vmod_hello(VRT_CTX)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	return ("vmod-hiring");
}
