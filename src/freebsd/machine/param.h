#if defined(__x86_64__)
#include "platform/amd64/param.h"
#elif defined(__x86__)
#include "platform/x86/param.h"
#elif defined(__ppc64__)
#include "platform/powerpc/param.h"
#elif defined(__ppc__)
#include "platform/powerpc/param.h"
#elif defined(__arm__)
#include "platform/arm/param.h"
#elif defined(__aarch64__)
#include "platform/arm64/param.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/param.h"
#else
#error Your platform is unsupported
#endif
#endif