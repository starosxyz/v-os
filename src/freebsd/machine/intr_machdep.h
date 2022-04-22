#if defined(__x86_64__)
#include "platform/amd64/intr_machdep.h"
#elif defined(__x86__)
#include "platform/x86/intr_machdep.h"
#elif defined(__ppc64__)
#include "platform/powerpc/intr_machdep.h"
#elif defined(__ppc__)
#include "platform/powerpc/intr_machdep.h"
#elif defined(__arm__)
#include "platform/arm/intr_machdep.h"
#elif defined(__aarch64__)
#include "platform/arm64/intr_machdep.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/intr_machdep.h"
#else
#error Your platform is unsupported
#endif
#endif