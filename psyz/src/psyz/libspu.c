#include <psyz.h>
#include <libspu.h>
#include <psyz/log.h>
#include "../../decomp/src/libspu/libspu_private.h"

#ifdef PSYZ_SPU_HOT_SRAM // the mixer reads these for every voice of every sample
static SPU_RXX spu_RXX __attribute__((section(".bss_sram.psyz_spu_regs")));
#else
static SPU_RXX spu_RXX;
#endif
static unsigned _dma_dpcr;
union SpuUnion* _spu_RXX = (union SpuUnion*)&spu_RXX;
unsigned* dma_dpcr = &_dma_dpcr; // TODO this must be removed
volatile u16 _spu_RQ[10] = {0};

void SpuNGetVoiceAttr(int vNum, SpuVoiceAttr* arg) { NOT_IMPLEMENTED; }
