#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter a valid integer.\n");
            while(getchar() != '\n'); // wait for the user to enter a valid integer
            continue;
        }

        if (score == 1) {
            break;
        }

        if (score < 0) {
            printf("Invalid input: Score cannot be negative.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        
        // Loop through all possibilities
        for (int td2 = 0; td2 * 8 <= score; td2++) {
            for (int td1 = 0; (td2 * 8) + (td1 * 7) <= score; td1++) {
                for (int td = 0; (td2 * 8) + (td1 * 7) + (td * 6) <= score; td++) {
                    for (int fg = 0; (td2 * 8) + (td1 * 7) + (td * 6) + (fg * 3) <= score; fg++) {
                        for (int safety = 0; (td2 * 8) + (td1 * 7) + (td * 6) + (fg * 3) + (safety * 2) <= score; safety++) {
                            if ((td2 * 8) + (td1 * 7) + (td * 6) + (fg * 3) + (safety * 2) == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", 
                                       td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}