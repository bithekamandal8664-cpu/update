#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[100];
    char KDE[200];
    char GNOME[200];
    char NIRI[200];
    char HYPRLAND[200];
    char EXTRA_PKGS[300];
    
    // Changed variables to single characters for proper switch handling
    char selection;
    char confirmation;
    char command;

    printf("type your password first: ");
    fgets(password, sizeof(password), stdin);
    // FIX: Changed 'selection' to 'password' to prevent memory corruption
    password[strcspn(password, "\n")] = '\0';
    
    printf("\nChoose your Desktop environment first\n");
    printf("1. KDE-plasma\n");
    printf("2. GNOME\n");
    printf("3. Niri (Note: this is window manager rather than a traditional desktop environment, but ill manage it for you :3 )\n");
    printf("4. Hyprland (Note: this is a window manager rather than a traditional desktop environment, but ill manage it for you :3)\n");
    printf("choose a number please:- ");
    // FIX: Added a leading space to " %c" to clear input buffer whitespace
    scanf(" %c", &selection);

    snprintf(KDE, sizeof(KDE), "echo '%s' | sudo -S pacman -S --noconfirm plasma", password);
    snprintf(GNOME, sizeof(GNOME), "echo '%s' | sudo -S pacman -S --noconfirm gnome", password);
    snprintf(NIRI, sizeof(NIRI), "echo '%s' | sudo -S pacman -S --noconfirm niri", password);
    snprintf(HYPRLAND, sizeof(HYPRLAND), "echo '%s' | sudo -S pacman -S --noconfirm hyprland", password);

    // FIX: Switching on character literals now
    switch (selection) {
        case '1':
            system(KDE);
            break;
        case '2':
            system(GNOME);
            break;
        case '3':
            printf("installing niri......\n");
            system(NIRI);

            printf("\nChoose your shell!\n");
            printf("1. Noctalia\n");
            printf("2. Caelestia\n");
            printf("Type your number!:- ");
            scanf(" %c", &confirmation);

            switch (confirmation) {
                case '1':
                    system("yay -S --noconfirm noctalia");
                    system("echo 'spawn-sh-at-startup \"qs -c noctalia-shell\"' >> ~/.config/niri/cfg/autostart.kdl");
                    printf("\nAdded Noctalia to autostart!\n");
                    break;
                case '2':
                    system("yay -S --noconfirm caelestia-shell");
                    system("echo 'spawn-sh-at-startup \"caelestia shell\"' >> ~/.config/niri/cfg/autostart.kdl");
                    printf("\nAdded caelestia shell to autostart!\n");
                    break;
            }
            break;  
        case '4':
            printf("installing hyprland....\n");
            system(HYPRLAND);

            printf("\nChoose your shell\n");
            printf("1. Noctalia\n");
            printf("2. Caelestia\n");
            printf("Type your number!:- ");
            scanf(" %c", &confirmation);

            switch (confirmation) {
                case '1':
                    system("yay -S --noconfirm noctalia");
                    system("echo '\nhl.on(\"hyprland.start\", function() hl.exec_cmd(\"qs -c noctalia-shell\") end)' >> ~/.config/hypr/hyprland.lua");
                    printf("\nAdded Noctalia to autostart!\n");
                    break;
                case '2':
                    system("yay -S --noconfirm caelestia-shell");
                    system("echo '\nhl.on(\"hyprland.start\", function() hl.exec_cmd(\"caelestia shell\") end)' >> ~/.config/hypr/hyprland.lua");
                    printf("\nAdded Caelestia to autostart!\n");
                    break;
            }
            break;
    }

    printf("\nadding additional packages including firefox, Dolphin, and kitty\n");
    printf("want to add?:\n");
    printf("1. yes\n");
    printf("2. no\n");
    printf("choose a number please:- ");
    scanf(" %c", &command);

    switch (command) {
        case '1':
            // FIX: Formatted string execution to inject user password correctly
            snprintf(EXTRA_PKGS, sizeof(EXTRA_PKGS), "echo '%s' | sudo -S pacman -S --noconfirm firefox dolphin kitty", password);
            system(EXTRA_PKGS);
            break;
        case '2':
            break;
    }

    printf("\nDone!\n");
    return 0;
}

