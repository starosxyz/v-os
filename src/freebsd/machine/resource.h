#if defined(__x86_64__)
#include "platform/amd64/resource.h"
#elif defined(__x86__)
#include "platform/x86/resource.h"
#elif defined(__ppc64__)
#include "platform/powerpc/resource.h"
#elif defined(__ppc__)
#include "platform/powerpc/resource.h"
#elif defined(__arm__)
#include "platform/arm/resource.h"
#elif defined(__aarch64__)
#include "platform/arm64/resource.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/resource.h"
#else
#error Your platform is unsupported
#endif
#endif