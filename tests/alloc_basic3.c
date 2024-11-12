#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "vmlib.h"
#include "vm.h"

int main()
{
    vmload("img/many_free.img");

    void *ptr = vmalloc(16); 
    struct block_header *hdr = (struct block_header *)
                               ((char *)ptr - sizeof(struct block_header));
    
    assert(ptr != NULL);
    assert((uint64_t)ptr % 16 == 0);
    assert((char *)ptr - (char *)heapstart == 184);
    assert(hdr->size_status == 35);

    vmdestroy();
    return 0;
}