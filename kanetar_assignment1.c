#include <stdio.h>
#include <math.h>

/* gcc --std=gnu99 -o ./a.out kanetar_assignment1.c -lm*/

int main(void) {
    /* n: number of spherical segments */
    /* count: number of valid segments calculated */
    /* R: radius*/
    /* ha: height of the top cutting plane from the center */
    /* hb: height of the bottom cutting plane from the center */
    int n;
    int count = 0;
    double R;
    double ha;
    double hb;
    double pi = 3.14159265359;

    /*for calculations */
    double topArea;
    double bottomArea;
    double lateralArea;
    double totalArea;
    double volume;

    double sumArea = 0.0;
    double sumVolume = 0.0;
    /*for average*/
    double avgArea;
    double avgVolume;

    /* Ask how many segments to evaluate */
    do {
        printf("How many spherical segments you want to evaluate [2-10]? \n");
        scanf("%d", &n);
    } while (n < 2 || n > 10);

    /* Get data for each valid segment */
    while (count < n) {
        int valid = 1;

        printf ("Obtaining data for spherical segment number %d\n", count + 1);

         printf("What is the radius of the sphere (R)? \n");
        scanf("%lf", &R);

        printf ("What is the height of the top area of the spherical segment (ha)? \n");
        scanf( "%lf", &ha);

        printf("What is the height of the bottom area of the spherical segment (hb)? \n");
        scanf("%lf", &hb) ;

        /* Display the entered values */
        printf ("Entered data: R = %.2f ha = %.2f hb = %.2f.\n",R, ha, hb);

        /*  Check if the input values are valid */
        if (R <= 0 || ha <= 0 ||  hb <= 0 ||ha > R || hb > R || hb > ha) {
            printf("Invalid Input.\n");
            valid = 0;
        }

        /* Calculate when the input is valid */
        if (valid == 1) {
            topArea = pi * (R * R - ha * ha);
            bottomArea = pi * (R * R - hb * hb);
            lateralArea = 2 * pi * R * (ha - hb);

            totalArea = topArea + bottomArea + lateralArea;

            volume = (pi / 3.0) * (ha - hb) *
                     (3 * R * R - ha * ha - ha * hb - hb * hb);

            printf("Total Surface Area = %.2f Volume = %.2f.\n",  totalArea, volume);

             sumArea = sumArea + totalArea;
            sumVolume = sumVolume + volume;

            count++;
        }
    }

    /* Calculate the averages */
    avgArea = sumArea / n;
    avgVolume = sumVolume / n;

    printf ("Total average results:\n");
    printf( "Average Surface Area = %.2f Average Volume = %.2f.\n", avgArea, avgVolume);

    return 0;
}