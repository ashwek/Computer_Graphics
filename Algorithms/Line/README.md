# Line Drawing Algorithms

## [DDA (Digital Differential Analyzer)](./Line/DDA.c)

A Digital Differential Analyzer (DDA) is hardware or software used for interpolation of variables over an interval between start and end point. DDAs are used for rasterization of lines, triangles and polygons. They can be extended to non linear functions, such as perspective correct texture mapping, quadratic curves, and traversing voxels. The DDA method can be implemented using floating-point or integer arithmetic. The native floating-point implementation requires one addition and one rounding operation per interpolated value (e.g. coordinate x, y, depth, color component etc.) and output result. [more on Wikipedia](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
