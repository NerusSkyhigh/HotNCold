# [HotNCold](https://www.youtube.com/watch?v=kTHNpusq654)

Heat Equation solver with a CUDA engine and Raylib for visualization.

An indepth review of the heat equation can be found here:

[https://ntrs.nasa.gov/api/citations/20200006182/downloads/Introduction%20to%20Numerical%20Methods%20in%20Heat%20Transfer.pdf](https://ntrs.nasa.gov/api/citations/20200006182/downloads/Introduction%20to%20Numerical%20Methods%20in%20Heat%20Transfer.pdf)

but the gist of it is that the heat equation is
$$\dot{q}_{gen} + k \nabla^2T = \rho C_p \frac{\partial T}{\partial t}$$
with:

- $\dot{q}_{gen}$ is the energy per unit of time and volume
  generated $\frac{ \text{[energy]} }{ \text{[time] [length]}^3l }$
- $k$: is the thermal conductivity $\frac{ \text{[energy]} }{ \text{[time] [temperature]  [length]} }$
- $\nabla^2$ is the laplacian $\frac{ 1 }{\text{[length]}^2}$
- $T$ is the temperature at point $\vec{x}$ and time $t$
- $\rho$ is the density of the material, $\frac{ \text{[mass]} }{ \text{[length]}^3 }$
- $C_p$ is the specific heat $\frac{ \text{[energy]} }{ \text{[mass] [temperature]} }$

This differential equation can be discretized in the following way:
$$\frac{\partial T(x, t)}{\partial t} = \frac{T(x, t+\Delta t)-T(x, t)}{\Delta t}$$
$$\frac{\partial^2 T(x, t)}{\partial x^2} = \frac{T(x+\Delta x, t)-2T(x, t)+T(x-\Delta x, t)}{(\Delta x)^2}$$

which leads to:
$$\frac{T(x, y, t+\Delta t)-T(x, y, t)}{\Delta t} = \frac{1}{\rho C_p} \dot{q}_{gen}(x, y, t) + \frac{k}{\rho C_p} \left( \frac{T(x+\Delta x, y, t)-2T(x, y, t)+T(x-\Delta x, y, t)}{(\Delta x)^2} + \frac{T(x, y+\Delta y, t)-2T(x, y, t)+T(x, y-\Delta y, t)}{(\Delta y)^2}\right)$$

by setting $\delta x = \delta y$ and defining $\alpha = \frac{k}{\rho C_p} \frac{\Delta t}{\Delta x^2}$
and $T(x, y, t) = T_{t}^{x, y}$, the heat equations becomes

$$T^{x, y}_{t+\Delta t} = \frac{\delta t}{\rho C_p} \dot{q}_{gen}(x, y, t) + T^{x, y}_{t} + \alpha \left( T^{x+\Delta x, y}_{t} + T^{x, y+\Delta y}_{t} -4T^{x, y}_{t} + T^{x-\Delta x, y}_{t}+T^{x, y-\Delta y}_{t}\right)$$

It can be
proved ([Section 10.1 - Morten Hjorth-Jensen Computational Physics, Lecture notes](https://www.hlevkin.com/hlevkin/60numalgs/C/Hjorth-Jensen%20Computational%20Physics.pdf))
that this equation is stable if and only if
$$\frac{k}{\rho C_p} \frac{\Delta t}{\Delta x^2} < \frac{1}{4}$$
in every point. I choose to make the timestep dependent on the other parameters as 1-fifth of the minimum value.
The program will then compute
$$\Delta t = 0.05 \min \limits_{\rho, C_p, k, \Delta x} \left\{ \frac{\rho C_p}{k}\Delta x^2 \right\}$$
