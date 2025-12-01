// Primary Author: Samuel Lamore
// Helper for hsv_to_rgb
float my_floor(float x) {
    int i = (int)x;
    return (x < 0 && x != (float)i) ? (float)(i - 1) : (float)i;
}

// Primary Author: Samuel Lamore
// Converts hsv values into 0-5 r, g, and b values that can be used to color the curses output
void hsv_to_rgb(int hue, float s, float v, short *red, short *green, short *blue) {
    float C = s*v;
    float h2 = (float)hue / 60.0f;
    float X = C * (1 - fabs(h2 - 2.0f * my_floor(h2 / 2.0f) - 1));
    float r,g,b;
    if (hue < 60)       { r = C; g = X; b = 0; } 
    else if (hue < 120) { r = X; g = C; b = 0; } 
    else if (hue < 180) { r = 0; g = C; b = X; } 
    else if (hue < 240) { r = 0; g = X; b = C; } 
    else if (hue < 300) { r = X; g = 0; b = C; } 
    else                { r = C; g = 0; b = X; }
    *red =   (r * 5.0f);
    *green = (g * 5.0f);
    *blue =  (b * 5.0f);
}