
/* autogenerated from E:\Work\OSSBuild\Main\GStreamer\Windows\.\..\Source\gst-plugins-good\gst\deinterlace\tvtime.orc */

#ifndef _E__WORK_OSSBUILD_MAIN_GSTREAMER_WINDOWS______WINDOWS_GENERATED_GST_PLUGINS_GOOD_GST_DEINTERLACE_TVTIME_H_
#define _E__WORK_OSSBUILD_MAIN_GSTREAMER_WINDOWS______WINDOWS_GENERATED_GST_PLUGINS_GOOD_GST_DEINTERLACE_TVTIME_H_

#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ORC_INTEGER_TYPEDEFS_
#define _ORC_INTEGER_TYPEDEFS_
#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
#include <stdint.h>
typedef int8_t orc_int8;
typedef int16_t orc_int16;
typedef int32_t orc_int32;
typedef int64_t orc_int64;
typedef uint8_t orc_uint8;
typedef uint16_t orc_uint16;
typedef uint32_t orc_uint32;
typedef uint64_t orc_uint64;
#elif defined(_MSC_VER)
typedef signed __int8 orc_int8;
typedef signed __int16 orc_int16;
typedef signed __int32 orc_int32;
typedef signed __int64 orc_int64;
typedef unsigned __int8 orc_uint8;
typedef unsigned __int16 orc_uint16;
typedef unsigned __int32 orc_uint32;
typedef unsigned __int64 orc_uint64;
#else
#include <limits.h>
typedef signed char orc_int8;
typedef short orc_int16;
typedef int orc_int32;
typedef unsigned char orc_uint8;
typedef unsigned short orc_uint16;
typedef unsigned int orc_uint32;
#if INT_MAX == LONG_MAX
typedef long long orc_int64;
typedef unsigned long long orc_uint64;
#else
typedef long orc_int64;
typedef unsigned long orc_uint64;
#endif
#endif
typedef union { orc_int32 i; float f; } orc_union32;
typedef union { orc_int64 i; double f; } orc_union64;
#endif

void deinterlace_line_vfir (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, const guint8 * s4, const guint8 * s5, int n);
void deinterlace_line_linear (guint8 * d1, const guint8 * s1, const guint8 * s2, int n);
void deinterlace_line_linear_blend (guint8 * d1, const guint8 * s1, const guint8 * s2, const guint8 * s3, int n);

#ifdef __cplusplus
}
#endif

#endif

