/*
Author: Muhammad Hassan - BS Physics, BZU Multan
Project: Projectile Motion Simulation - C++ Version
Description: Projectile Motion With and Without Air Resistance
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
const double g = 9.8;       // Acceleration due to gravity (m/s^2)
const double PI = 3.14159265358979323846;
int main()
{
    // Initial conditions
    double v0 = 50.0;       // Initial velocity (m/s)
    double theta_deg = 45.0; // Launch angle (degrees)
    // Convert angle from degrees to radians
    double theta = theta_deg * PI / 180.0;
    // Air resistance parameters
    double drag_coeff = 0.05;
    double mass = 1.0;
    // Time step for Euler method
    double dt = 0.01;
    // =========================================================
    // 1. WITHOUT AIR RESISTANCE - ANALYTICAL SOLUTION
    // =========================================================
    double R = (v0 * v0 * sin(2.0 * theta)) / g;
    double H = (v0 * sin(theta) * v0 * sin(theta))
               / (2.0 * g);
    double T = (2.0 * v0 * sin(theta)) / g;
    cout << "============================================\n";
    cout << "      PROJECTILE MOTION SIMULATION\n";
    cout << "============================================\n\n";
    cout << "WITHOUT AIR RESISTANCE\n";
    cout << "Initial Velocity = " << v0 << " m/s\n";
    cout << "Launch Angle     = " << theta_deg << " degrees\n";
    cout << "Range            = " << R << " m\n";
    cout << "Maximum Height   = " << H << " m\n";
    cout << "Flight Time      = " << T << " s\n\n";
    // =========================================================
    // 2. WITH AIR RESISTANCE - EULER METHOD
    // =========================================================
    vector<double> x_list;
    vector<double> y_list;
    double x = 0.0;
    double y = 0.0;
    double vx = v0 * cos(theta);
    double vy = v0 * sin(theta);
    x_list.push_back(x);
    y_list.push_back(y);
    while (y >= 0.0)
    {
        // Magnitude of velocity
        double v = sqrt(vx * vx + vy * vy);
        // Acceleration due to air resistance
        double ax = -(drag_coeff / mass) * v * vx;
        double ay = -g - (drag_coeff / mass) * v * vy;
        // Euler method
        vx = vx + ax * dt;
        vy = vy + ay * dt;
        x = x + vx * dt;
        y = y + vy * dt;
        x_list.push_back(x);
        y_list.push_back(y);
        // Safety limit
        if (x_list.size() > 10000)
        {
            break;
        }
    }
    // =========================================================
    // SAVE DATA TO CSV FILE
    // =========================================================
    ofstream file("trajectory_cpp.csv");
    if (!file)
    {
        cout << "Error: Could not create CSV file.\n";
        return 1;
    }
    file << "x,y\n";
    for (size_t i = 0; i < x_list.size(); i++)
    {
        file << x_list[i] << "," << y_list[i] << "\n";
    }
    file.close();
    // =========================================================
    // OUTPUT RESULTS
    // =========================================================
    cout << "WITH AIR RESISTANCE\n";
    cout << "Drag Coefficient = " << drag_coeff << "\n";
    cout << "Mass             = " << mass << " kg\n";
    cout << "Range            = " << x_list.back() << " m\n\n";
    cout << "Trajectory data has been saved to:\n";
    cout << "trajectory_cpp.csv\n\n";
    cout << "Press Enter to exit...";
    cin.get();
    return 0;
}
