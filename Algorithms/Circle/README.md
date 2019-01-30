# Circle Drawing Algorithms

## [Midpoint Circle algorithm](./Midpoint%20circle%20algorithm.c)

The midpoint circle algorithm is an algorithm used to determine the points needed for rasterizing a circle. Bresenham's circle algorithm is derived from the midpoint circle algorithm. This algorithm draws all eight octants simultaneously, starting from each cardinal direction (0°, 90°, 180°, 270°) and extends both ways to reach the nearest multiple of 45° (45°, 135°, 225°, 315°). It can determine where to stop because when y = x, it has reached 45°. [more on Wikipedia](https://en.wikipedia.org/wiki/Midpoint_circle_algorithm)
