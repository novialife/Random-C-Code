#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Your shopping assistant\n");
    float rate = 1.00;
    while(1){
      printf("");
      printf("1. Set exchange rate in SEK (current rate: %.2f)\n",rate);
      printf("2. Read prices in the foreign currency\n");
      printf("3. End\n");

      int choice = 0;
      printf("Give your choice (1 - 3):");
      scanf("%d", &choice);

      if(choice==1){
            printf("Give exchange rate: ");
            scanf("%f", &rate);
      }
      else if(choice==2){
            double* pricelist = malloc(1);
            int i = 0;
            while(1){
                    double price = 0;
                    printf("Give price (finish with < 0): ");
                    scanf("%lf", &price);

                    if(price < 0){
                        break;
                    }
                    pricelist[i] = price;
                    double* newpricelist = realloc(pricelist, 1+i);
                    pricelist = newpricelist;
                    i++;
            }
            double sumforeign = 0;
            for(int j = 0; j < i+1; j++) {
                sumforeign += pricelist[j];
            }
            double sumsek = sumforeign * rate;

            printf("Sum in foreign currency: %.2f\n", sumforeign);
            printf("Sum in SEK: %.2f\n", sumsek);

      }
      else if(choice==3){
            printf("End of program!");
            break;
      }
      else{
        printf("Not a valid choice!\n");
      }
    }


    return 0;
}
