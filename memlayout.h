// Memory layout

#define PGSIZE		4096		// bytes mapped by a page
#define PGSHIFT		12		// log2(PGSIZE)

#define KSTKSIZE	(8*PGSIZE)   		// size of a kernel stack

#define IOSPACEB  0xA0000 // begin IO space
#define IOSPACEE  0x100000  // end IO space
#define PHYSTOP  0xE000000 // use phys mem up to here as free pool

#define KERNBASE 0xF0000000
#define USERTOP  (KERNBASE-PGSIZE)
#define KERNLINK 0xF0100000 

#ifndef __ASSEMBLER__

static inline uint v2p(void *a) { return (uint) a  - KERNBASE; }
static inline void *p2v(uint a) { return (void *) a + KERNBASE; }

#endif

#define V2P(a) ((uint) a - KERNBASE)
#define P2V(a) ((void *) a + KERNBASE)
