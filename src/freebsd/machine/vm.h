#if defined(__x86_64__)
#include "platform/amd64/vm.h"
#elif defined(__x86__)
#include "platform/x86/vm.h"
#elif defined(__ppc64__)
#include "platform/powerpc/vm.h"
#elif defined(__ppc__)
#include "platform/powerpc/vm.h"
#elif defined(__arm__)
#include "platform/arm/vm.h"
#elif defined(__aarch64__)
#include "platform/arm64/vm.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/vm.h"
#else
#error Your platform is unsupported
#endif
#endif