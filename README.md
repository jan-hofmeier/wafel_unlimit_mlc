# Stroopwafel plugin to unlimte the MLC size

This plugin for [stroopwafel](https://github.com/shinyquagsire23/stroopwafel) packages IOSU patches from [GaryOrderNichts](https://github.com/GaryOderNichts) for easy usage.

- Removes predefined MLC sizes so IOSU sees the full size of the MLC media

- Disables SCFM (SLC cache for MLC)

If you unlimit the size of the MLC, you first need to format it and reinstall the system files. A second stroopwafel plugin will be provided to do the format and install.



## Details

Stock IOSU uses these rules to determinate the usable size of the MLC

```
if size < 8gb
  totalSize = size
else if size < 32gb
  totalSize = 8gb
else if size < 64gb
  totalSize = 32gb
else
  totalSize = 64gb
```

The largest size supported are 64gb. Everything above 64GB will be capped to 64GB. If you just want to upgrade to 64GB, you don't need this patch as it is already supported by stock IOSU. This patch will set the usable size always to the full size of the MLC media.

The SCFM needs to be disabled, as it doesn't work with more than 64GB. In my measurements disabeling SCFM did actually improve performance (espacially Installs) and I didn't find any performance degredation. Also it has the advantage that you can swap between multiple sdcards as MLC replacement.

## Hardware

One way to install a larger MLC media on your Wii U would be to replace the 8GB / 32GB eMMC with a micro SD card. To make the replacement more convieneint I recommend Voultars [Wii-U NAND-AID - eMMC Recovery and Replacement Interposer](https://gbatemp.net/threads/wii-u-nand-aid-emmc-recovery-and-replacement-interposer-public-test.630798/)

## How to use

Put the `wafel_unlimit_mlc.ipx` together with `wafel_core.ipx` from stroopwafel in `/wiiu/ios_plugins` on your sdcard

## Building

```bash
export STROOPWAFEL_ROOT=/path/too/stroopwafel-repo
make
```

## Thanks

- GaryOderNichts for the IOSU patches

- shinyquagsire23 for defuse, minute and stroopwafel
