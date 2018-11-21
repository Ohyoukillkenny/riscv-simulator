#### RISC-V Simulator

##### Configuration:

Install cmake and gtest on windows: https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Windows

on linux: https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Linux

on mac: https://github.com/iat-cener/tonatiuh/wiki/Installing-Google-Test-For-Mac



Install Clion: https://www.jetbrains.com/clion/



##### Workflow

add x10, x5, x6  			// x10 is rd, x5 is rs1, x6 is rs2, or you guys can set your own rules.

​						// However, if there is some universal rules for the riscv assembly

​						// code, just write the assembly code according to these rules.						

=>

00000000011000101000010100110011		// one assembly code -> one line of strings in txt file



Sample of exe.txt:

```
00011000010000000000000100010011
00000000000100000000001010010011
00000000001000101010100100100011
00000001001100000100001010000011
```

