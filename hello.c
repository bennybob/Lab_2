/* Hello World program */

#include<stdio.h>
void readPPMheader(char *filename, int *xres, int *yres);

int main()
{
    int xres, yres;
    readPPMheader("photo.ppm", &xres, &yres);
    
    int image [xres] [yres] [3]; //for each of the x and y coordinates, we need 3 numbers for red,blue & green intensity-hence number 3
    //printf("%d %d",xres, yres); for checking code
    
    //read image data
    FILE *input;
    input = fopen("photo.ppm","r");
    
    //read header into dummy variables to advance position indicator past header
    {
        int temp;
        fscanf(input, "P3\n%d %d\n%d", &temp, &temp, &temp);
        
    }
    
    int x, y;
    for( y = 0; y < yres ; y++ ){
        for( x = 0; x < xres; x++){//looping x & y pixels
            fscanf(input, "%d\n%d\n%d\n", &image[x][y][0], &image[x][y][1], &image[x][y][2]);
        }
    }
    
    //calculate mean value
    float rT = 0, gT = 0, bT = 0; // red/green/blue total 
    for( y = 0; y < yres ; y++ ){
        for( x = 0; x < xres; x++){//looping x & y pixels
            rT += image [x][y][0];
            gT += image [x][y][1];
            bT += image [x][y][2];
        }    

        
    }
    
    rT /= (xres*yres); //calculates mean
    gT /= (xres*yres);
    bT /= (xres*yres);
    
    printf("%f %f %f", rT, gT, bT);
}


void readPPMheader(char *filename, int *xres, int*yres) {
    FILE *input;
    
    input = fopen(filename, "r");
    
    fscanf(input,"P3\n%d %d", xres, yres); //this will pattern match and print the integers on the line below P3

    fclose(input);//to stop the file opening infinately
}


    
    