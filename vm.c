#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void wishme() {
    time_t now = time(0);
    struct tm *time = localtime(&now);

    if (time->tm_hour < 12) {
        printf("Good Morning Sir\n");
        system("espeak \"Good Morning Sir\"");
    }
    else if (time->tm_hour >= 12 && time->tm_hour <= 16) {
        printf("Good Afternoon sir\n");
        system("espeak \"Good Afternoon sir\"");
    }
    else if (time->tm_hour > 16 && time->tm_hour < 24) {
        printf("Good Evening sir\n");
        system("espeak \"Good Evening sir\"");
    }
}

void datetime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    printf("The date and time is \n%s\n", dt);
    system("espeak \"Current date and time\"");
}

void greetings() {
    printf("Hello! I'm here to help you. How are you doing today?\n");
    system("espeak \"Hello! I'm here to help you. How are you doing today?\"");
}

void calculator () {
    float num1, num2, result;
    char operator;

    printf("\n====Calculator====\n");
    printf("Enter first number: ");
    scanf("%f", &num1);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter second number: ");
    scanf("%f", &num2);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
        break;
    case '/':
        if (num2 != 0) {
        result = num1 / num2;
        printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
        } else {
        printf("Error: Division by zero!\n");
        }
        break;
    default:
    printf("Error: Invalid operator!\n");
    }
    system("espeak \"Calculator\"");
}

void tell_joke() {
    int joke_number = rand() % 5;
    
    switch(joke_number) {
        case 0:
            printf("Why do programmers prefer dark mode? Because light attracts bugs!\n");
            system("espeak \"Why do programmers prefer dark mode? Because light attracts bugs!\"");
            break;
        case 1:
            printf("Why did the computer go to the doctor? Because it had a virus!\n");
            system("espeak \"Why did the computer go to the doctor? Because it had a virus!\"");
            break;
        case 2:
            printf("What do you call a programmer from Finland? Nerdic!\n");
            system("espeak \"What do you call a programmer from Finland? Nerdic!\"");
            break;
        case 3:
            printf("Why do Java developers wear glasses? Because they can't C#!\n");
            system("espeak \"Why do Java developers wear glasses? Because they can't C sharp!\"");
            break;
        case 4:
            printf("I told my wife she was drawing her eyebrows too high. She looked surprised!\n");
            system("espeak \"I told my wife she was drawing her eyebrows too high. She looked surprised!\"");
            break;
    }
}

void note_taker() {
    char note[500];
    FILE *file;
    
    printf("\n===== NOTE TAKER =====\n");
    printf("Enter your note (max 500 characters): ");
    
    // Clear input buffer
    getchar();
    
    fgets(note, sizeof(note), stdin);
    
    // Open file in append mode
    file = fopen("waan_notes.txt", "a");
    
    if (file != NULL) {
        fprintf(file, "%s", note);
        fclose(file);
        
        printf("Note saved successfully!\n");
        system("espeak \"Note saved\"");
    } else {
        printf("Error: Could not save the note.\n");
        system("espeak \"Error saving note\"");
    }
}

void about_assistant() {
    printf("Hello! I'm WAAN AI, a virtual assistant created to make your life easier.\n");
    printf("I can help you with various tasks like checking time, opening websites, and more.\n");
    system("espeak \"I'm WAAN AI, a virtual assistant created to make your life easier\"");
}

void check_weather() {
    printf("\n===== WEATHER INFORMATION =====\n");
    system("curl -s 'wttr.in/YourCity?format=3'");
    system("espeak \"Checking weather information\"");
}

void system_monitor() {
    printf("\n===== SYSTEM RESOURCES =====\n");
    printf("Checking system resources...\n");
    system("top -bn1 | head -n 5");
    system("df -h | head -n 2");
    system("free -h");
    system("espeak \"System resources information\"");
}

// Password Generator
void generate_password() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    char password[21];
    int length = 16;
    
    srand(time(NULL));
    
    printf("\n===== PASSWORD GENERATOR =====\n");
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[length] = '\0';
    
    printf("Generated Password: %s\n", password);
    system("espeak \"Generated password\"");
}

// Pomodoro Timer

void detailed_countdown(int total_seconds, const char* session_name) {
    int remaining_time = total_seconds;
    int minutes, seconds;
    float progress;
    int progress_width = 50;
    
    printf("\n🍅 %s Session Started\n", session_name);
    system("espeak \"Starting session\"");
    
    while (remaining_time > 0) {
        // Calculate progress
        minutes = remaining_time / 60;
        seconds = remaining_time % 60;
        progress = (float)(total_seconds - remaining_time) / total_seconds;
        
        // Progress bar
        printf("\r[");
        int pos = progress_width * progress;
        for (int i = 0; i < progress_width; ++i) {
            if (i < pos) 
                printf("=");
            else if (i == pos)
                printf(">");
            else 
                printf(" ");
        }
        
        // Time and percentage display
        printf("] %02d:%02d  %.0f%%  ", 
            minutes, 
            seconds, 
               progress * 100);
        
        fflush(stdout);
        sleep(1);
        remaining_time--;
    }
    
    printf("\n🔔 %s Session Complete!\n", session_name);
    system("espeak \"Session complete\"");
}

void pomodoro_timer() {
    int work_minutes = 25;
    int break_minutes = 5;
    
    // Work Session
    detailed_countdown(work_minutes * 60, "Work");
    
    // Break Session
    detailed_countdown(break_minutes * 60, "Break");
}

// Unit Converter
void unit_converter() {
    float value;
    int choice;
    printf("\n===== UNIT CONVERTER =====\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Kilograms to Pounds\n");
    printf("4. Meters to Feet\n");
    printf("5. Centimeters to Inches\n");
    printf("6. Liters to Gallons\n");
    printf("7. Square Meters to Square Feet\n");
    printf("8. Hours to Minutes\n");
    printf("9. Minutes to Seconds\n");
    printf("10. Hectares to Acres\n");
    printf("Enter your choice (1-10): ");
    scanf("%d", &choice);
    printf("Enter the value to convert: ");
    scanf("%f", &value);

    switch(choice) {
        case 1:
            printf("%.2f°C = %.2f°F\n", value, (value * 9/5) + 32);
            system("espeak \"Celsius to Fahrenheit conversion\"");
            break;
        case 2:
            printf("%.2f km = %.2f miles\n", value, value * 0.621371);
            system("espeak \"Kilometers to miles conversion\"");
            break;
        case 3:
            printf("%.2f kg = %.2f pounds\n", value, value * 2.20462);
            system("espeak \"Kilograms to pounds conversion\"");
            break;
        case 4:
            printf("%.2f meters = %.2f feet\n", value, value * 3.28084);
            system("espeak \"Meters to feet conversion\"");
            break;
        case 5:
            printf("%.2f centimeters = %.2f inches\n", value, value * 0.393701);
            system("espeak \"Centimeters to inches conversion\"");
            break;
        case 6:
            printf("%.2f liters = %.2f gallons\n", value, value * 0.264172);
            system("espeak \"Liters to gallons conversion\"");
            break;
        case 7:
            printf("%.2f square meters = %.2f square feet\n", value, value * 10.7639);
            system("espeak \"Square meters to square feet conversion\"");
            break;
        case 8:
            printf("%.2f hours = %.2f minutes\n", value, value * 60);
            system("espeak \"Hours to minutes conversion\"");
            break;
        case 9:
            printf("%.2f minutes = %.2f seconds\n", value, value * 60);
            system("espeak \"Minutes to seconds conversion\"");
            break;
        case 10:
            printf("%.2f hectares = %.2f acres\n", value, value * 2.47105);
            system("espeak \"Hectares to acres conversion\"");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// To-Do List Manager
void todo_list() {
    FILE *file;
    char task[200];
    char temp[200];
    int choice, priority, task_number, line_count;
    char status;
    
    do {
        printf("\n===== TO-DO LIST =====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Complete\n");
        printf("4. Delete Task\n");
        printf("5. Clear All Tasks\n");
        printf("6. Sort by Priority\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear input buffer

        switch(choice) {
            case 1:
                printf("Enter task: ");
                fgets(task, sizeof(task), stdin);
                printf("Enter priority (1-High, 2-Medium, 3-Low): ");
                scanf("%d", &priority);
                getchar();

                file = fopen("todo_list.txt", "a");
                if (file != NULL) {
                    fprintf(file, "[%d] [ ] %s", priority, task);
                    fclose(file);
                    printf("Task added successfully!\n");
                    system("espeak \"Task added\"");
                }
                break;

            case 2:
                file = fopen("todo_list.txt", "r");
                if (file != NULL) {
                    printf("\nCurrent Tasks:\n");
                    line_count = 1;
                    while (fgets(task, sizeof(task), file)) {
                        printf("%d. %s", line_count++, task);
                    }
                    fclose(file);
                    system("espeak \"Displaying tasks\"");
                }
                break;

            case 3:
                printf("Enter task number to mark as complete: ");
                scanf("%d", &task_number);
                
                file = fopen("todo_list.txt", "r");
                FILE *temp_file = fopen("temp.txt", "w");
                
                if (file != NULL && temp_file != NULL) {
                    line_count = 1;
                    while (fgets(task, sizeof(task), file)) {
                        if (line_count == task_number) {
                            // Replace "[ ]" with "[x]"
                            task[4] = 'x';
                        }
                        fprintf(temp_file, "%s", task);
                        line_count++;
                    }
                    fclose(file);
                    fclose(temp_file);
                    remove("todo_list.txt");
                    rename("temp.txt", "todo_list.txt");
                    printf("Task marked as complete!\n");
                    system("espeak \"Task completed\"");
                }
                break;

            case 4:
                printf("Enter task number to delete: ");
                scanf("%d", &task_number);
                
                file = fopen("todo_list.txt", "r");
                temp_file = fopen("temp.txt", "w");
                
                if (file != NULL && temp_file != NULL) {
                    line_count = 1;
                    while (fgets(task, sizeof(task), file)) {
                        if (line_count != task_number) {
                            fprintf(temp_file, "%s", task);
                        }
                        line_count++;
                    }
                    fclose(file);
                    fclose(temp_file);
                    remove("todo_list.txt");
                    rename("temp.txt", "todo_list.txt");
                    printf("Task deleted successfully!\n");
                    system("espeak \"Task deleted\"");
                }
                break;

            case 5:
                file = fopen("todo_list.txt", "w");
                if (file != NULL) {
                    fclose(file);
                    printf("All tasks cleared!\n");
                    system("espeak \"All tasks cleared\"");
                }
                break;

        case 6:
    {
        // Read all tasks into an array
        struct Task {
            int priority;
            char content[200];
        } tasks[100];
        int task_count = 0;

        file = fopen("todo_list.txt", "r");
        if (file == NULL) {
            printf("Error: Could not open todo list file!\n");
            system("espeak \"Error opening file\"");
            break;
        }

        // Read and validate tasks
        while (fgets(task, sizeof(task), file) && task_count < 100) {
            // Validate minimum length and format
            if (strlen(task) < 3 || task[0] != '[' || task[2] != ']') {
                printf("Warning: Skipping invalid task format\n");
                continue;
            }
            
            // Extract and validate priority
            int priority = task[1] - '0';
            if (priority < 1 || priority > 3) {
                printf("Warning: Invalid priority found (%d), setting to lowest priority\n", priority);
                priority = 3;
            }
            
            tasks[task_count].priority = priority;
            
            // Safe string copy
            strncpy(tasks[task_count].content, task, sizeof(tasks[task_count].content) - 1);
            tasks[task_count].content[sizeof(tasks[task_count].content) - 1] = '\0';
            
            task_count++;
        }
        fclose(file);

        if (task_count == 0) {
            printf("No tasks found to sort!\n");
            system("espeak \"No tasks to sort\"");
            break;
        }

        if (task_count >= 100) {
            printf("Warning: Only first 100 tasks will be sorted\n");
            system("espeak \"Warning: Task limit reached\"");
        }

        // Bubble sort by priority
        for (int i = 0; i < task_count - 1; i++) {
            for (int j = 0; j < task_count - i - 1; j++) {
                if (tasks[j].priority > tasks[j + 1].priority) {
                    struct Task temp = tasks[j];
                    tasks[j] = tasks[j + 1];
                    tasks[j + 1] = temp;
                }
            }
        }

        // Write sorted tasks back to file
        file = fopen("todo_list.txt", "w");
        if (file == NULL) {
            printf("Error: Could not open file for writing!\n");
            system("espeak \"Error saving sorted tasks\"");
            break;
        }

        for (int i = 0; i < task_count; i++) {
            fprintf(file, "%s", tasks[i].content);
        }
        fclose(file);
        printf("Tasks sorted by priority!\n");
        system("espeak \"Tasks sorted successfully\"");
    }
    break;

            case 7:
                system("espeak \"Goodbye\"");
                return;
        }
    } while (1);
}

// Random Motivational Quote Generator
void motivational_quote() {
    int quote_number = rand() % 5;
    
    switch(quote_number) {
        case 0:
            printf("\"Believe you can and you're halfway there.\" - Theodore Roosevelt\n");
            break;
        case 1:
            printf("\"Success is not final, failure is not fatal: it is the courage to continue that counts.\" - Winston Churchill\n");
            break;
        case 2:
            printf("\"The only way to do great work is to love what you do.\" - Steve Jobs\n");
            break;
        case 3:
            printf("\"Don't watch the clock; do what it does. Keep going.\" - Sam Levenson\n");
            break;
        case 4:
            printf("\"Your attitude, not your aptitude, will determine your altitude.\" - Zig Ziglar\n");
            break;
    }
    system("espeak \"Here is your motivational quote\"");
}

// Simple Rock Paper Scissors Game
void rock_paper_scissors() {
    int player_choice, computer_choice;
    srand(time(NULL));
    
    printf("\n===== ROCK PAPER SCISSORS =====\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &player_choice);
    
    computer_choice = rand() % 3 + 1;
    
    printf("Computer chose: %d\n", computer_choice);
    
    if (player_choice == computer_choice) {
        printf("It's a tie!\n");
    } else if (
        (player_choice == 1 && computer_choice == 3) ||
        (player_choice == 2 && computer_choice == 1) ||
        (player_choice == 3 && computer_choice == 2)
    ) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
    system("espeak \"Rock paper scissors game\"");
}

// Quick Tip Calculator
void tip_calculator() {
    float bill_amount, tip_percentage;
    
    printf("\n===== TIP CALCULATOR =====\n");
    printf("Enter bill amount: ");
    scanf("%f", &bill_amount);
    
    printf("Enter tip percentage: ");
    scanf("%f", &tip_percentage);
    
    float tip_amount = bill_amount * (tip_percentage / 100);
    float total_bill = bill_amount + tip_amount;
    
    printf("Tip Amount: %.2f\n", tip_amount);
    printf("Total Bill: %.2f\n", total_bill);
    system("espeak \"Tip calculation complete\"");
}


void print_menu() {
    printf("\n============= WAAN AI MENU =============\n");
    printf("1. Greetings\n");
    printf("2. About Assistant\n");
    printf("3. Check Time and Date\n");
    printf("4. Open Websites\n");
    printf("5. Calculator\n");
    printf("6. Take a Note\n");
    printf("7. Tell a Joke\n");
    printf("8. Weather Information\n");
    printf("9. System Monitor\n");
    printf("10. Password Generator\n");
    printf("11. Pomodoro Timer\n");
    printf("12. Unit Converter\n");
    printf("13. To-Do List\n");
    printf("14. Motivational Quote\n");
    printf("15. Rock Paper Scissors\n");
    printf("16. Tip Calculator\n");
    printf("17. Exit\n");
    printf("========================================\n");
    printf("Enter your choice (1-17): ");
}

void open_website_menu() {
    int site_choice;
    printf("\n===== WEBSITE MENU =====\n");
    printf("1. Open Google\n");
    printf("2. Open YouTube\n");
    printf("3. Open Instagram\n");
    printf("4. Open Discord\n");
    printf("5. Exit\n");
    scanf("%d", &site_choice);
    getchar(); // Clear input buffer

    switch(site_choice) {
        case 1:
            printf("Opening Google.....\n");
            system("espeak \"opening google\"");
            system("open https://www.google.com");
            break;
        case 2:
            printf("Opening YouTube.....\n");
            system("espeak \"opening youtube\"");
            system("open https://www.youtube.com");
            break;
        case 3:
            printf("Opening Instagram.....\n");
            system("espeak \"opening instagram\"");
            system("open https://www.instagram.com");
            break;
        case 4:
            printf("Opening Discord.....\n");
            system("espeak \"opening discord\"");
            system("open https://discord.com/");
            break;
        case 5:
            printf("Opening Personal Biodata.....\n");
            system("espeak \"opening biodata\"");
            system("open https://irawan.it.student.pens.ac.id/");
            break;
        case 6:
            return;
        default:
            printf("Invalid choice. Returning to main menu.\n");
            system("espeak \"Invalid choice\"");
    }
}

int main() {
    system("clear");

    printf("\t\t\t<============================================= W E L C O M E ==========================================>\n");
    printf("\t\t\t<============================================= I'M A VIRTUAL ASSISTANT ==========================================>\n");
    printf("\t\t\t<============================================= MY NAME IS WAAN AI ==========================================>\n");
    printf("\t\t\t<============================================= I'M HERE TO HELP YOU ==========================================>\n\n");

    char password[20];
    char input[100];
    int menu_choice;

    do {
        printf("=======================\n");
        printf("| ENTER YOUR PASSWORD |\n");
        printf("=======================\n\n");
        system("espeak \"enter your password\"");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Remove trailing newline
        strncpy(password, input, sizeof(password) - 1);
        password[sizeof(password) - 1] = '\0';

        if (strcmp(password, "irawan") == 0) {
            printf("\n<==================================================================================================>\n\n");
            wishme();

            do {
                print_menu();
                scanf("%d", &menu_choice);
                getchar(); // Clear input buffer

                switch(menu_choice) {
                    case 1:
                        greetings();
                        break;
                    
                    case 2:
                        about_assistant();
                        break;
                    
                    case 3:
                        datetime();
                        break;
                    
                    case 4:
                        open_website_menu();
                        break;

                    case 5:
                        calculator();
                        break;

                    case 6:
                        note_taker();
                        break;

                    case 7:
                        tell_joke();
                        break;

                    case 8:
        check_weather();
        break;
    case 9:
        system_monitor();
        break;
    case 10:
        generate_password();
        break;
    case 11:
        pomodoro_timer();
        break;
    case 12:
        unit_converter();
        break;
    case 13:
        todo_list();
        break;
    case 14:
        motivational_quote();
        break;
    case 15:
        rock_paper_scissors();
        break;
    case 16:
        tip_calculator();
        break;
    case 17:
        printf("Good Bye sir, have a nice day!!!!\n");
        system("espeak \"Good Bye sir, have a nice day\"");
        exit(0);
                    
                    default:
                        printf("Invalid choice. Please try again.\n");
                        system("espeak \"Invalid choice, please try again\"");
                }
            } while (1);
        }
        else {
            system("clear");

            printf("\t\t\t<============================= W E L C O M E=============================>\n");
            printf("\t\t\t<============================= I'M VIRTUAL ASSISTANT =============================>\n");
            printf("\t\t\t<============================= MY NAME IS WAAN AI =============================>\n");
            printf("\t\t\t<============================= I'M HERE TO HELP YOU AND MAKE YOUR LIFE EASY =============================>\n\n");

            printf("======================\n");
            printf("X Incorrect Password X\n");
            printf("======================\n\n");
            system("espeak \"Incorrect Password, Please enter correct password\"");
        }
    } while (1);

    return 0;
}