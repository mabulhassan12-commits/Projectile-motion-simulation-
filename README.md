# Projectile Motion Simulation - C++

**Author:** Muhammad Hassan | BS Physics, BZU Multan
## Overview
C++ simulation of projectile motion with and without air resistance.
Compares analytical formulas vs numerical Euler method.
## Features
- Calculates Range, Max Height, Time of Flight
- Quadratic drag model: F = -k * v * v
- Exports trajectory to CSV for plotting
## Physics Formulas
- R = v0^2 * sin(2theta) / g
- H = v0^2 * sin^2(theta) / 2g
- With drag: ax = -(k/m)*v*vx , ay = -g -(k/m)*v*vy
## Parameters
v0=50 m/s, theta=45°, g=9.8, k=0.05, dt=0.01s
## How to Run
g++ projectile_motion.cpp -o projectile
./projectile
## Output
Generates trajectory_cpp.csv
