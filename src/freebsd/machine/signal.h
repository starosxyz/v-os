#if defined(__x86_64__)
#include "platform/amd64/signal.h"
#elif defined(__x86__)
#include "platform/x86/signal.h"
#elif defined(__ppc64__)
#include "platform/powerpc/signal.h"
#elif defined(__ppc__)
#include "platform/powerpc/signal.h"
#elif defined(__arm__)
#include "platform/arm/signal.h"
#elif defined(__aarch64__)
#include "platform/arm64/signal.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/signal.h"
#else
#error Your platform is unsupported
#endif
#endif