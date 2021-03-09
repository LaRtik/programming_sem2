#ifndef MAIN_H
#define MAIN_H
int positiveFloatInput(char buffer[]);
float sphereArea(float sphereRadius);
float sphereVolume(float sphereRadius); /* V = 4/3 * pi * R^3 */
float edgeLength(float sphereRadius); /*  R = a(sqrt6) / 4  */
float crossArea(float sphereRadius, float k); /* R^2 = r^2 - k^2 */


#endif