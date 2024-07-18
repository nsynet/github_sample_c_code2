def hexdump_to_addr_value(hexdump):
    lines = hexdump.strip().split('\n')
    hex_pairs = [line[2:].split() for line in lines if line.strip()]
    
    for line_num, hex_values in enumerate(hex_pairs):
        for idx, hex_value in enumerate(hex_values):
            addr = "{:02x}".format(line_num * 16 + idx)
            value = hex_value
            print(f"{addr}={value}")

# 示例hexdump字符串
hexdump = """
00 82 d4 1f 00 83 00 a0 84 00 02 00 8a 82 b6 06 3e
10 04 00 40 02 70 c3 1f 8e ff ff ff ff 00 00 41 01
20 07 06 05 04 03 02 01 00 08 09 0a 0b 0c 0d 0e 0f
30 17 16 15 14 13 12 11 10 18 19 1a 1b 1c 1d 1e 0e
40 0f 0d 5b 25 00 00 00 2d 37 a8 00 19 e8 c0 00 00
50 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
60 00 00 00 00 00 00 61 c4 19 0f 00 00 00 00 00 00
70 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
80 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
90 00 00 00 00 00 00 06 1f 4a 0d 10 00 00 00 00 00
a0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
b0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
c0 00 00 00 00 00 00 00 00 0a ff 00 00 00 00 00 00
d0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
e0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
f0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
"""

# 调用函数进行转换  
hexdump_to_addr_value(hexdump)
