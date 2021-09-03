#include "config.h"
#include <string.h>

#include <cache/cache.h>

#include "vcc_hiring_if.h"

VCL_STRING
vmod_hello(VRT_CTX)
{

	CHECK_OBJ_NOTNULL(ctx, VRT_CTX_MAGIC);
	return ("vmod-hiring");
}

const size_t infosz = 64;
char	     *info;

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