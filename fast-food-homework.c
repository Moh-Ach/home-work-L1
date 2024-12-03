#include <stdio.h>
#include <string.h>

int main() {
    int order_num, ingredients_num;
    double Price = 0;
    double tax = 0.19;
    char order[6], ingredients[15], continue_order[10], size[3], student[4], senior[5], coupon[10];

    printf("Please choose an item from the MENU:\n");
    while (1) {
        printf("1 to choose Pizza\n2 to choose Tacos\n3 to choose Salad\n");
        printf("Enter your choice: ");
        scanf("%d", &order_num);
        
        switch (order_num) {
            case 1:
                printf("Pizza selected.\n");
                Price += 40;
                strcpy(order, "Pizza");
                break;
            case 2:
                printf("Tacos selected.\n");
                Price += 30;
                strcpy(order, "Tacos");
                break;
            case 3:
                printf("Salad selected.\n");
                Price += 15;
                strcpy(order, "Salad");
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
                continue;
        }

        printf("Choose ingredients:\n1 - 3 Cheese\n2 - Chicken\n3 - Beef\n4 - Tuna\n");
        printf("Enter your choice: ");
        scanf("%d", &ingredients_num);

        switch (ingredients_num) {
            case 1: strcpy(ingredients, "3 Cheese"); break;
            case 2: strcpy(ingredients, "Chicken"); break;
            case 3: strcpy(ingredients, "Beef"); break;
            case 4: strcpy(ingredients, "Tuna"); break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        printf("Choose size:\nM\nL\nXL\n");
        printf("Enter your choice: ");
        scanf("%s", size);

        if (strcmp(size, "M") == 0 || strcmp(size, "m") == 0) {
            printf("Order: %s %s (Size %s)\n", ingredients, order, size);
        } else if (strcmp(size, "L") == 0 || strcmp(size, "l") == 0) {
            Price += 5;
            printf("Order: %s %s (Size %s)\n", ingredients, order, size);
        } else if (strcmp(size, "XL") == 0 || strcmp(size, "xl") == 0) {
            Price += 7;
            printf("Order: %s %s (Size %s)\n", ingredients, order, size);
        } else {
            printf("Invalid size. Please try again.\n");
            continue;
        }

        printf("Would you like to order more? (Y/N): ");
        scanf("%s", continue_order);

        if (strcmp(continue_order, "Y") == 0 || strcmp(continue_order, "y") == 0) {
            continue;
        } else if (strcmp(continue_order, "N") == 0 || strcmp(continue_order, "n") == 0) {
            printf("Are you a student? (Y/N): ");
            scanf("%s", student);
            
            if (strcmp(student, "Y") == 0 || strcmp(student, "y") == 0) {
                printf("Congratulations! You get a 30%% discount.\n");
                Price *= 0.7;
            } else {
                printf("Are you a senior? (Y/N): ");
                scanf("%s", senior);
                
                if (strcmp(senior, "Y") == 0 || strcmp(senior, "y") == 0) {
                    printf("Congratulations! You get a 25%% discount.\n");
                    Price *= 0.75;
                } else {
                    printf("Do you have a coupon? (Y/N): ");
                    scanf("%s", coupon);
                    
                    if (strcmp(coupon, "Y") == 0 || strcmp(coupon, "y") == 0) {
                        printf("Congratulations! You get a 25%% discount.\n");
                        Price *= 0.75;
                    }
                }
            }

            printf("Final price: %.2f\n", Price * (1 + tax));
            printf("Thank you for your order! It will arrive in 20 minutes.\n");
            break;
        } else {
            printf("Invalid input.\n");
            continue;
        }
    }

    return 0;
}