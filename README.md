# 42-ft_fractol
Fractol is a project that allows you to generate and visualize various fractal patterns using the MLX graphics library. This interactive program enables users to explore mesmerizing mathematical patterns such as the Mandelbrot set and the Julia set.

 <div id="header" align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/b/bb/Mandelbrot_Animation0.gif" height="300"/>
</div>

## Features

- Generate and visualize fractal patterns in real-time.
- Zoom in and out to explore fractals at different scales.
- Pan across the fractal space to navigate through the patterns.
- Interact with the Julia set by clicking on the screen.
- Adjust the color palette to customize the visualization.
- 
## Installation

1. Clone the repository to your local machine.
2. Navigate to the project directory.
3. Run the `make` command to compile the project.

## Usage
Once the project is compiled, you can run the program by executing the generated executable. The program will open a window displaying the fractal and provide various controls to interact with the visualization.

Use the following controls:
- Run the executable without args to get instructions.
- Zoom to desired direction (for Julia's set it will change the pattern of the fractal): `Click`.
- Zoom In: `Scroll up`.
- Zoom Out: `Scroll down`.
- Pan: Use the `arrow keys` to move in different directions.
- Change the parameter of the executable to change which set to explore.

## Fractal Algorithms

Fractals are complex geometric shapes that exhibit self-similarity at different scales. In this project, we focus on two popular types of fractals: the Mandelbrot set and the Julia set.

### Mandelbrot Set

The Mandelbrot set is a famous fractal that is generated based on the following iterative algorithm:

```c
int mandelbrot(t_complex z, t_complex c)
{
    long double square_x;
    long double square_y;
    int iter;

    square_x = z.x * z.x;
    square_y = z.y * z.y;
    iter = 0;
    // ...
    while ((square_x + square_y) <= 4 && iter < MAX_ITER)
    {
        // ...
        iter++;
    }
    return (coloring(iter));
}
```
In this algorithm, the complex number `z` is iterated upon, starting from (0, 0), and the result is compared against a threshold value. The iteration continues until the threshold is reached or the maximum number of iterations (`MAX_ITER`) is reached. The coloring function determines the color based on the number of iterations performed.

### Julia Set

The Julia set is another intriguing fractal that is generated using the following iterative algorithm:

```c
int julia(t_complex z, t_complex c)
{
    long double square_x;
    long double square_y;
    int iter = 0;
    
    square_x = z.x * z.x;
    square_y = z.y * z.y;
    
    while ((square_x + square_y) <= 4 && iter < MAX_ITER)
    {
        z.y = c.y + (z.x + z.x) * z.y;
        z.x = c.x + square_x - square_y;
        square_x = z.x * z.x;
        square_y = z.y * z.y;
        iter++;
    }
    
    return coloring(iter);
}
```
Similar to the Mandelbrot set algorithm, the Julia set algorithm iterates upon a complex number `z` and compares the result against a threshold value. The iteration continues until the threshold is reached or the maximum number of iterations is reached. The coloring function determines the color based on the number of iterations performed.
<br/>

In the case of the Julia set, the interesting aspect is that the fractal pattern changes based on the value of the complex number `c`. In this program, when you click on the screen while viewing the Julia set, the `c` value is updated based on the clicked coordinates, resulting in a new pattern being generated. This interactive feature allows you to explore different regions and variations of the Julia set.
<br/>
<br/>

For more detailed explanations and implementations of other fractal algorithms, you can explore the source code files included in this project.
