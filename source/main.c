#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <wafel/dynamic.h>
#include <wafel/ios_dynamic.h>
#include <wafel/utils.h>
#include <wafel/patch.h>

// This fn runs before everything else in kernel mode.
// It should be used to do extremely early patches
// (ie to BSP and kernel, which launches before MCP)
// It jumps to the real IOS kernel entry on exit.
__attribute__((target("arm")))
void kern_main()
{
    // Make sure relocs worked fine and mappings are good
    debug_printf("we in here unlimit mlc plugin kern %p\n", kern_main);

    debug_printf("init_linking symbol at: %08x\n", wafel_find_symbol("init_linking"));

    // Unlimit MLC
    ASM_PATCH_K(0x107bdb14, "nop\n");

    //Disable SCFM
    ASM_PATCH_K(0x107d1f28, "nop\n");
    ASM_PATCH_K(0x107d1e08,"nop\n");
    ASM_PATCH_K(0x107e7628,"mov r3, #0x0\nstr r3, [r10]\n");

    debug_printf("unlimit mlc done\n");
}

// This fn runs before MCP's main thread, and can be used
// to perform late patches and spawn threads under MCP.
// It must return.
void mcp_main()
{
    // Make sure relocs worked fine and mappings are good
	debug_printf("we in here plugin MCP %p\n", mcp_main);

    debug_printf("done\n");
}
