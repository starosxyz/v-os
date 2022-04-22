#if defined(__x86_64__)
#include "platform/amd64/counter.h"
#elif defined(__x86__)
#include "platform/x86/counter.h"
#elif defined(__ppc64__)
#include "platform/powerpc/counter.h"
#elif defined(__ppc__)
#include "platform/powerpc/counter.h"
#elif defined(__arm__)
#include "platform/arm/counter.h"
#elif defined(__aarch64__)
#include "platform/arm64/counter.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/counter.h"
#else
#error Your platform is unsupported
#endif
#endif