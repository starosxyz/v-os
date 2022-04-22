#if defined(__x86_64__)
#include "platform/amd64/bus_dma.h"
#elif defined(__x86__)
#include "platform/x86/bus_dma.h"
#elif defined(__ppc64__)
#include "platform/powerpc/bus_dma.h"
#elif defined(__ppc__)
#include "platform/powerpc/bus_dma.h"
#elif defined(__arm__)
#include "platform/arm/bus_dma.h"
#elif defined(__aarch64__)
#include "platform/arm64/bus_dma.h"
#elif !defined(__GNUC__)
#ifdef _WIN32
#include "platform/windows/bus_dma.h"
#else
#error Your platform is unsupported
#endif
#endif