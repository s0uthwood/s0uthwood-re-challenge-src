for i in range(0x401080,0x40112B):
    patch_byte(i,get_wide_byte(i)^0x20)
