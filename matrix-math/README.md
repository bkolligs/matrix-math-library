# Matrix Math

This is my custom implementation of various matrix operations using compiler intrinsics.

## Vectors
* Dot product
* Cross product
* Scalar multiplication
* Addition

## Implementation Notes

So it seems like using a vector 3 with floats, the compiler optimizes out my SIMD, which makes sense, it probably knows best. 

I will try to use AVX2 instructions (256 bit registers instead of SSE's 128 bit) by changing the data type of vector 3 to floats.

I can force the compiler to use AVX2 instructions by adding the `-mavx2` flag<sup>2</sup> to the target's compile definitions. 


### Endianness 
The CPU has a particular ordering of bits that is described with it's _Endianness_<sup>5</sup>. If I have the 32 bit integer `0x0A0B0C0D`, (168496141 in decimal) then the layout of the bits are as follows:

| Memory Offset | a    | a+1  | a+2  | a+3  |
|---------------|------|------|------|------|
| Little Endian | 0x0D | 0x0C | 0x0B | 0x0A |
| Big Endian    | 0x0A | 0x0B | 0x0C | 0x0D |

I need to pay attention to this, because it seems like the vectors I am creating are organized in Little Endian which means the following: 

```c++
/**
 * This will layout the vector in the following way:
 * [0.0, one.z, one.y, one.x]
 */
_one = _mm256_set_pd(one.x, one.y, one.z, 0.0);
```

### Compiling
So to compile things properly it's also worth using the `RelWithDebInfo` mode in CMake. This gives the following assembly [output](../logs/matrix-math-disassembly.txt).

# References
1. Oracle, _x86 Assembly Language Reference Manual_, https://docs.oracle.com/cd/E36784_01/html/E36859/epmoa.html#scrolltoc
2. GNU, _x86 Options (Using the GNU Compiler Collection (GCC))_, https://gcc.gnu.org/onlinedocs/gcc/x86-Options.html
3. Tables Generator Project, _Markdown Tables generator - TablesGenerator.com_, https://www.tablesgenerator.com/markdown_tables
4. Intel, _Intel Intrinsics Guide_, https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html#techs=AVX&ig_expand=3847,6134,4936&cats=Arithmetic,Set
5. Wikipedia, _Endianness_, https://en.wikipedia.org/wiki/Endianness